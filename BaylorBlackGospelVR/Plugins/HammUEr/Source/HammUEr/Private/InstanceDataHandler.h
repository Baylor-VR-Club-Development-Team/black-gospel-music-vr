// HammUEr
// Copyright 2015-2016 Turfster / NT Entertainment
// All Rights Reserved.


// This code is held together with kitten whiskers and toothpicks.
// There's nothing to see or learn here.
// Seriously.
// Turn back.

#pragma once
#include <HammUEr.h>
#include <vector>
#include <string>

class InstanceDataHandler
{
	std::vector<uint8_t> instanceArray;
	int instanceIndex;

public:
	
	InstanceDataHandler()
	{
		instanceArray.empty();
		int header = 0x11554400;
		instanceAdd(header);
		instanceIndex = 0;
	}

	template <typename T>
	inline void instanceAdd(T& data)
	{
		uint8_t* castdata = (uint8_t*)(&data);
		for (int i = 0; i < sizeof(T); i++) // this isn't fast, but should at least be sort of safe?
			instanceArray.push_back(*(castdata++));
	}

	template <typename T>
	inline void instanceGet(T& data)
	{
		memcpy(&data, &instanceArray[instanceIndex], sizeof(T));
		instanceIndex += sizeof(T);
	}

	void instanceAddString(FString inputString)
	{
		int length = inputString.Len();
		instanceAdd(length);
		for (int i = 0; i < inputString.Len(); i++)
			instanceArray.push_back(inputString[i]);
	}

	void WriteTo(FString InstanceFileName)
	{
		FILE* fp;
		fopen_s(&fp, TCHAR_TO_ANSI(*InstanceFileName), "wb");
		if (!fp)
			return;
		fseek(fp, 0, 0);
		fwrite((uint8_t*)&instanceArray[0], sizeof(uint8_t), instanceArray.size(), fp);
		fclose(fp);
	}
};