#include <cstdio>
#include <iostream>

int main()
{

	FILE* file = nullptr;

	auto result = fopen_s(&file, "Test.txt", "wb");

	if (!file)
	{
		std::cout << "파일 열기 실패.\n";
		return 1;
	}

	// 파일 열기 성공.
	std::cout << "파일 열기 성공.\n";

	// 파일 닫기.
	fclose(file);
	file = nullptr;
}