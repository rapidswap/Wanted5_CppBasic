#include <cstdio>
#include <iostream>
#include <cassert>

int main()
{
	// 문자열 쓰기.
	float framerate = 120.0f;
	int width = 30;
	int height = 20;

	// 위의 변수를 포맷 지정해서 문자열로 만들기.
	// 포맷: 키 = 값.
	const int length = 256;
	char string[length] = {};

	sprintf_s(
		string, length,
		"framerate = %f\nwidth = %d\nheight = %d",
		framerate,width,height
	);

	FILE* configFile = nullptr;
	fopen_s(&configFile, "Setting.txt","wt");

	if (!configFile)
	{
		return 1;
	}

	fwrite(string, sizeof(char), strlen(string) + 1, configFile);

	fclose(configFile);
	configFile = nullptr;

	FILE* file = nullptr;

	auto result = fopen_s(&file, "Test.txt", "rt");

	if (!file)
	{
		std::cout << "파일 열기 실패.\n";
		return 1;
	}

	// 기록할 값.
	const char* message = "C 라이브러리로 기록한 텍스트.\n";
	
	// 파일에 쓰기.
	//if (fputs(message, file) == EOF)
	//{
	//	std::cout << "파일에 쓰기 실패\n";
	//	fclose(file);
	//	return 1;
	//}

	// 파일에서 읽기.
	// 읽어온 데이터를 저장할 버퍼.
	const int size = 256;
	char buffer[size] = {};
	size_t readSize = fread(buffer, sizeof(char), size, file);
	

	// 복사할 파일 생성(쓰기 모드로 열기.)
	FILE* copyFile = nullptr;
	errno_t errorCode = fopen_s(&copyFile, "Test2.txt", "wb");
	if (!copyFile)
	{
		return 1;
	}

	// 쓰기
	size_t writtenSize = fwrite(buffer, sizeof(char), readSize, copyFile);
	
	assert(readSize == writtenSize);

	
	
	// 파일 열기 성공.
	//std::cout << "파일 열기 성공.\n";

	// 파일 닫기.
	fclose(file);
	file = nullptr;

	fclose(copyFile);
	copyFile = nullptr;
}