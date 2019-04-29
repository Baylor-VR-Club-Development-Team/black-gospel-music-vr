// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"
#include "TextureManipulation.h"
#include "ImageUtils.h"
#include "AssetRegistryModule.h"

#include "HammUErSettings.h"

UTexture2D* TextureManipulation::GetTextureForChain(UMaterial* inMaterial, EMaterialProperty inProperty)
{
	if (inMaterial != NULL)
	{
		TArray<UTexture*> chainTextures;
		TArray<UTexture*> parentTextures;
		TArray<FName> parameterNames;
		TArray<FName>parentparameterNames;
		UTexture2D* testTexture;

		if (inMaterial->GetTexturesInPropertyChain(inProperty, chainTextures, &parameterNames, NULL, ERHIFeatureLevel::Num, EMaterialQualityLevel::Num))
		{
			UMaterialInterface* myParent = ((UMaterialInstance*)inMaterial)->Parent;
			if (myParent != NULL)
			{

				// this is an instance
				myParent->GetTexturesInPropertyChain(inProperty, parentTextures, &parentparameterNames, NULL, ERHIFeatureLevel::Num, EMaterialQualityLevel::Num);
				for (int i = 0; i < parentTextures.Num(); i++)
					chainTextures.Remove(parentTextures[i]);
			}
			testTexture = NULL;

			if (chainTextures.Num() > 0)
			{
				if (chainTextures.Num() == 1)
					testTexture = (UTexture2D*)chainTextures[0];
				else
				{
					for (int i = 0; i < chainTextures.Num(); i++)
					{
						if (chainTextures[i]->GetName().EndsWith("_D"))
						{
							testTexture = (UTexture2D*)chainTextures[i];
							break;
						}
					}
					if (testTexture == NULL) // okay, so we've got nothing
					{
						for (int i = 0; i < chainTextures.Num(); i++)
						{
							bool filterOK = true;
							FString testTextureName = chainTextures[i]->GetName();
							for (int j = 0; j < HammUErSettings::textureBeginsWith.Num(); j++)
							{
								if (testTextureName.StartsWith(HammUErSettings::textureBeginsWith[j]))
								{
									filterOK = false;
									break;
								}
							}
							if (!filterOK)
								break;
							for (int j = 0; j < HammUErSettings::textureContains.Num(); j++)
							{
								if (testTextureName.Contains(HammUErSettings::textureContains[j]))
								{
									filterOK = false;
									break;
								}
							}
							if (!filterOK)
								break;
							for (int j = 0; j < HammUErSettings::textureEndsWith.Num(); j++)
							{
								if (testTextureName.EndsWith(HammUErSettings::textureEndsWith[j]))
								{
									filterOK = false;
									break;
								}
							}
							if (filterOK)
							{
								testTexture = (UTexture2D*)chainTextures[i];
								break;
								// yeah, sure, whatever, it passed the test, let's go with this one
							}
						}
					}
					if (testTexture == NULL) // no texture to use?
					{
						return NULL;
					}
				}

				return testTexture;
			}

		}
		else
		{
			return NULL;
		}
	}
	return NULL;
}

void TextureManipulation::CreateTexture(int32 width, int32 height, TArray<FColor>& colorArray, FString ObjectName, FString importDirectory, bool hasAlpha)
{
	// last minute sanitizing, just in case we missed one
	ObjectName = ObjectName.Replace(TEXT("*"), TEXT("X"));
	ObjectName = ObjectName.Replace(TEXT("?"), TEXT("Q"));
	ObjectName = ObjectName.Replace(TEXT("!"), TEXT("I"));
	ObjectName = ObjectName.Replace(TEXT("."), TEXT("-"));
	ObjectName = ObjectName.Replace(TEXT("&"), TEXT("_"));
	ObjectName = ObjectName.Replace(TEXT(" "), TEXT("_"));


	FString NewPackageName = TEXT("/Game/") + (importDirectory == "" ? "Textures/" : importDirectory + "/Textures/") + ObjectName;
	UPackage* Package = CreatePackage(NULL, *NewPackageName);
	Package->FullyLoad();
	Package->Modify();

	FCreateTexture2DParameters FCT;
	FCT.bUseAlpha = hasAlpha;
	/*if (HammUErSettings::useTextureAlpha)
		FCT.bUseAlpha = false;*/

	FString TextureName = ObjectName;
	if (TextureName.Contains("/"))
		TextureName = TextureName.Mid(TextureName.Find("/", ESearchCase::IgnoreCase, ESearchDir::FromEnd) + 1);

	UTexture2D* basetexture = FImageUtils::CreateTexture2D(width, height, colorArray, Package, *TextureName, RF_Public | RF_Standalone, FCT);
	FAssetRegistryModule::AssetCreated(basetexture);
	basetexture->PostEditChange();
	colorArray.Empty();

	FString PackageFileName = FPackageName::LongPackageNameToFilename(NewPackageName, FPackageName::GetAssetPackageExtension());
	try
	{
#if ENGINE_MINOR_VERSION>=11
		if (HammUErSettings::generateThumbs)
			ThumbnailTools::GenerateThumbnailForObjectToSaveToDisk(basetexture);
#endif
		if (GEditor->SavePackage(Package, basetexture, RF_Public | RF_Standalone, *PackageFileName, GError, nullptr, false, true, SAVE_None))
		{
			Package->PostEditChange();
			FAssetRegistryModule::AssetCreated(basetexture);
		}
		else
			UE_LOG(LogTemp, Error, TEXT("Could not save package %s"), *PackageFileName);
	}
	catch (...)
	{
		UE_LOG(LogTemp, Error, TEXT("Something went catastrophically wrong trying to save an unreal package for %s. In unreal code."), *ObjectName);
	}
}



void Decompress16x3bitIndices(uint8* packed, uint8* unpacked)
{
	int32 tmp, block, i;
	for (block = 0; block < 2; ++block)
	{
		tmp = 0;
		for (i = 0; i < 3; i++)
			tmp |= ((uint32)packed[i]) << (i * 8);

		for (i = 0; i < 8; i++)
			unpacked[i] = (tmp >> (i * 3)) & 0x7;

		packed += 3;
		unpacked += 8;
	}
}

void DecompressBlockDXT1Internal(uint8* block, TArray<FColor> &image, int32 x, int32 y, int32 stride, TArray<uint8_t> alphaValues)
{
	uint32_t temp, code;

	uint16_t color0, color1;
	uint8_t r0, g0, b0, r1, g1, b1;

	color0 = *(const uint16_t*)(block);
	color1 = *(const uint16_t*)(block + 2);

	temp = (color0 >> 11) * 255 + 16;
	r0 = (uint8_t)((temp / 32 + temp) / 32);
	temp = ((color0 & 0x07E0) >> 5) * 255 + 32;
	g0 = (uint8_t)((temp / 64 + temp) / 64);
	temp = (color0 & 0x001F) * 255 + 16;
	b0 = (uint8_t)((temp / 32 + temp) / 32);

	temp = (color1 >> 11) * 255 + 16;
	r1 = (uint8_t)((temp / 32 + temp) / 32);
	temp = ((color1 & 0x07E0) >> 5) * 255 + 32;
	g1 = (uint8_t)((temp / 64 + temp) / 64);
	temp = (color1 & 0x001F) * 255 + 16;
	b1 = (uint8_t)((temp / 32 + temp) / 32);

	code = *(const uint32_t*)(block + 4);

	uint32_t positionCode;
	uint8_t alpha;
	FColor finalColor;

	for (int32 j = 0; j < 4; j++)
	{
		for (int32 i = 0; i < 4; i++)
		{
			alpha = alphaValues[j * 4 + i];
			finalColor = FColor::White;
			positionCode = (code >> 2 * (4 * j + i)) & 0x03;

			if (color0 > color1)
			{
				switch (positionCode)
				{
				case 0:
					finalColor = FColor(r0, g0, b0, alpha);
					break;
				case 1:
					finalColor = FColor(r1, g1, b1, alpha);
					break;
				case 2:
					finalColor = FColor((2 * r0 + r1) / 3, (2 * g0 + g1) / 3, (2 * b0 + b1) / 3, alpha);
					break;
				case 3:
					finalColor = FColor((r0 + 2 * r1) / 3, (g0 + 2 * g1) / 3, (b0 + 2 * b1) / 3, alpha);
					break;
				}
			}
			else
			{
				switch (positionCode)
				{
				case 0:
					finalColor = FColor(r0, g0, b0, alpha);
					break;
				case 1:
					finalColor = FColor(r1, g1, b1, alpha);
					break;
				case 2:
					finalColor = FColor((r0 + r1) / 2, (g0 + g1) / 2, (b0 + b1) / 2, alpha);
					break;
				case 3:
					finalColor = FColor(0, 0, 0, alpha);
					break;
				}
			}
			image[i + x + (stride*(y + j))] = finalColor;
		}
	}
}

void DecompressBlockDXT3(int32 x, int32 y, int32 stride, uint8* source, TArray<FColor> &image)
{
	TArray<uint8_t> alphaValues;
	alphaValues.AddZeroed(16);

	for (int i = 0; i < 4; ++i)
	{
		uint16* alphaData = (uint16*)source;
		alphaValues[i * 4 + 0] = (((*alphaData) >> 0) & 0xF) * 17;
		alphaValues[i * 4 + 1] = (((*alphaData) >> 4) & 0xF) * 17;
		alphaValues[i * 4 + 2] = (((*alphaData) >> 8) & 0xF) * 17;
		alphaValues[i * 4 + 3] = (((*alphaData) >> 12) & 0xF) * 17;

		source += 2;
	}
	DecompressBlockDXT1Internal(source, image, x, y, stride, alphaValues);

}
void DecompressBlockDXT5(int32 x, int32 y, int32 stride, uint8* source, TArray<FColor> &image)
{
	uint8 alpha0, alpha1;
	uint8 alphaIndices[16];

	int16 color0, color1;
	uint8 r0, g0, b0, r1, g1, b1;

	int32 i, j;
	int32 temp, code;

	alpha0 = *(source);
	alpha1 = *(source + 1);

	Decompress16x3bitIndices(source + 2, alphaIndices);

	color0 = *(int16*)(source + 8);
	color1 = *(int16*)(source + 10);

	temp = (color0 >> 11) * 255 + 16;
	r0 = (uint8)((temp / 32 + temp) / 32);
	temp = ((color0 & 0x07E0) >> 5) * 255 + 32;
	g0 = (uint8)((temp / 64 + temp) / 64);
	temp = (color0 & 0x001F) * 255 + 16;
	b0 = (uint8)((temp / 32 + temp) / 32);

	temp = (color1 >> 11) * 255 + 16;
	r1 = (uint8)((temp / 32 + temp) / 32);
	temp = ((color1 & 0x07E0) >> 5) * 255 + 32;
	g1 = (uint8)((temp / 64 + temp) / 64);
	temp = (color1 & 0x001F) * 255 + 16;
	b1 = (uint8)((temp / 32 + temp) / 32);

	code = *(int32*)(source + 12);
	for (j = 0; j < 4; j++)
		for (i = 0; i < 4; i++)
		{
			uint8 finalAlpha;
			int alphaCode;
			uint8 colorCode;
			FColor finalColor;

			alphaCode = alphaIndices[4 * j + i];

			if (alphaCode == 0) {
				finalAlpha = alpha0;
			}
			else if (alphaCode == 1) {
				finalAlpha = alpha1;
			}
			else {
				if (alpha0 > alpha1) {
					finalAlpha = (uint8)(((8 - alphaCode)*alpha0 + (alphaCode - 1)*alpha1) / 7);
				}
				else {
					if (alphaCode == 6) {
						finalAlpha = 0;
					}
					else if (alphaCode == 7) {
						finalAlpha = 255;
					}
					else {
						finalAlpha = (uint8)(((6 - alphaCode)*alpha0 + (alphaCode - 1)*alpha1) / 5);
					}
				}
			}

			colorCode = (code >> 2 * (4 * j + i)) & 0x03;
			switch (colorCode)
			{
			case 0:
				finalColor = FColor(r0, g0, b0, finalAlpha);
				break;
			case 1:
				finalColor = FColor(r1, g1, b1, finalAlpha);
				break;
			case 2:
				finalColor = FColor((2 * r0 + r1) / 3, (2 * g0 + g1) / 3, (2 * b0 + b1) / 3, finalAlpha);
				break;
			case 3:
				finalColor = FColor((r0 + 2 * r1) / 3, (g0 + 2 * g1) / 3, (b0 + 2 * b1) / 3, finalAlpha);
				break;
			}

			image[i + x + (stride*(y + j))] = finalColor;
		}

}
/*
void DecompressDXT1Image(int32 width, int32 height, uint8* data, TArray<FColor>& image)
{
	int blockCountX = (width + 3) / 4;
	int blockCountY = (height + 3) / 4;
	int blockWidth = (width < 4) ? width : 4;
	int blockHeight = (height < 4) ? height : 4;

	TArray<FColor> colors;
	colors.Add(FColor::White);
	colors.Add(FColor::White);
	colors.Add(FColor::White);
	colors.Add(FColor::White);

	uint16 color0, color1;
	unsigned long temp; 
	uint8 r0, r1, g0, g1, b0, b1;


	for (int j = 0; j < blockCountY; j++)
	{
		for (int i = 0; i < blockCountX; i++)
		{
			decompress the block 
			// x = i*4
			// y = j*4, width, data+i*8, data = blockCountX * 8;
			color0 = (*data) | *(data + 1) << 8;
			color1 = (*data + 2) | *(data + 3) << 8;

			temp = (color0 >> 11) * 255 + 16;
			r0 = ((temp / 32 + temp) / 32);
			temp = ((color0 & 0x07E0) >> 5) * 255 + 32;
			g0 = ((temp / 64 + temp) / 64);
			temp = (color0 & 0x001F) * 255 + 16;
			b0 = ((temp / 32 + temp) / 32);

			temp = (color1 >> 11) * 255 + 16;
			r1 = ((temp / 32 + temp) / 32);
			temp = ((color1 & 0x07E0) >> 5) * 255 + 32;
			g1 = ((temp / 64 + temp) / 64);
			temp = (color1 & 0x001F) * 255 + 16;
			b1 = ((temp / 32 + temp) / 32);

			bool c0c1 = color0 > color1;

			colors[0] = FColor(r0, g0, b0, 255);
			colors[1] = FColor(r1, g1, b1, 255);
			colors[2] = (c0c1) ? FColor((2 * r0 + r1) / 3, (2 * g0 + g1) / 3, (2 * b0 + b1) / 3, 255) :
				FColor((r1 + r0) / 2, (g1 + g0) / 2, (b1 + b0) / 2, 255);
			colors[3] = (!c0c1) ? FColor((2 * r0 + r1) / 3, (2 * g0 + g1) / 3, (2 * b0 + b1) / 3, 255) :
				FColor((2 * r1 + r0) / 3, (2 * g1 + g0) / 3, (2 * b1 + b0) / 3, 255);

			unsigned long code = *reinterpret_cast<const unsigned long*>(data + 4);

			for (int x = 0; x < 4; x++)
				for (int y = 0; y < 4; y++)
				{
					int position = (code >> (8 * y + 2 * x)) & 0x03;
					image[i * 4 + x + (j * 4 + y) * width] = colors[position];
				}

			data += 8;
		}
		//data += blockCountX * 8;
	}
}*/

void DecompressDXT1Image(int32 width, int32 height, uint8* data, TArray<FColor> &image)
{
	TArray<uint8> raw;
	raw.AddZeroed(8);

	TArray<FColor> colors;
	colors.Add(FColor::White);
	colors.Add(FColor::White);
	colors.Add(FColor::White);
	colors.Add(FColor::White);

	uint16 color0, color1;
	uint8 r0, r1, g0, g1, b0, b1;

	for (int j = 0; j < height / 4; j++)
		for (int i = 0; i < width / 4; i++)
		{
			raw[0] = (uint8)*(data + j*width * 2 + i * 8);
			raw[1] = (uint8)*(data + j*width * 2 + i * 8 + 1);
			raw[2] = (uint8)*(data + j*width * 2 + i * 8 + 2);
			raw[3] = (uint8)*(data + j*width * 2 + i * 8 + 3);
			raw[4] = (uint8)*(data + j*width * 2 + i * 8 + 4);
			raw[5] = (uint8)*(data + j*width * 2 + i * 8 + 5);
			raw[6] = (uint8)*(data + j*width * 2 + i * 8 + 6);
			raw[7] = (uint8)*(data + j*width * 2 + i * 8 + 7);

			color0 = (uint16)(raw[0] | raw[1] << 8);
			color1 = (uint16)(raw[2] | raw[3] << 8);

			// color0 RGB
			r0 = (uint8)(((color0 >> 11) << 3) | 0x04);
			g0 = (uint8)(((color0 & 0x07E0) >> 3) | 0x02);
			b0 = (uint8)(((color0 & 0x001F) << 3) | 0x04);

			r1 = (uint8)((color1 >> 11) << 3);
			g1 = (uint8)((color1 & 0x07E0) >> 3);
			b1 = (uint8)((color1 & 0x001F) << 3);

			bool c0c1 = color0 > color1;

			colors[0] = FColor(r0, g0, b0, 255);
			colors[1] = FColor(r1, g1, b1, 255);
			colors[2] = (c0c1) ? FColor((2 * r0 + r1) / 3, (2 * g0 + g1) / 3, (2 * b0 + b1) / 3, 255) :
				FColor((r0 + r1) / 2, (g0 + g1) / 2, (b0 + b1) / 2, 255);
			colors[3] = (c0c1) ? FColor((2 * r1 + r0) / 3, (2 * g1 + g0) / 3, (2 * b1 + b0) / 3, 255):
				FColor(0,0,0, 255);

			// lookup table two bits per color index
			int32 location = raw[4] | (raw[5] << 8) | (raw[6] << 16) | (raw[7] << 24);  // little endian swap

			for (int x = 0; x < 4; x++)
				for (int y = 0; y < 4; y++)
				{
					int code = (location >> (8 * y + 2 * x)) & 0x03;
					image[i * 4 + x + (j * 4 + y) * width] = colors[code];
				}

		}
}
