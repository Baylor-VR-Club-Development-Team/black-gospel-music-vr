// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#include "HammUErPrivatePCH.h"

#include "HammUErStyle.h"
#include "SlateGameResources.h"
#include "IPluginManager.h"

TSharedPtr< FSlateStyleSet > FHammUErStyle::StyleInstance = NULL;

void FHammUErStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FHammUErStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FHammUErStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("HammUErStyle"));
	return StyleSetName;
}

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);
const FVector2D Header400x40(400.0f, 40.0f);

TSharedRef< FSlateStyleSet > FHammUErStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("HammUErStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("HammUEr")->GetBaseDir() / TEXT("Resources"));

	Style->Set("HammUEr.OpenPluginWindow", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));
	Style->Set("HammUEr.OpenPluginWindow.Small", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon20x20));
	Style->Set("HammUEr.EdModeIcon", new IMAGE_BRUSH(TEXT("ButtonIcon_40x"), Icon40x40));
	Style->Set("HammUEr.Header", new IMAGE_BRUSH(TEXT("headertest"), Header400x40));

	return Style;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT

void FHammUErStyle::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

const ISlateStyle& FHammUErStyle::Get()
{
	return *StyleInstance;
}
