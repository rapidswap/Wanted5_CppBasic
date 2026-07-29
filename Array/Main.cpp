#include <iostream>
#include <array>

//https://learn.microsoft.com/ko-kr/cpp/c-runtime-library/find-memory-leaks-using-the-crt-library?view=msvc-170
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) // DBG_NEW -> new 통제 가능하기 때문에 상관 없지만,
														// 프로젝트가 커지면 문제. 바꾸지 않는 것을 권장.
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 배열을 전달 받아서 원소를 출력하는 함수.
void PrintArray(int* array,int count)
{
	for (int ix = 0;ix < count; ++ix)
	{
		std::cout << array[ix] << ' ';
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//std::array<int, 5> stdArr;
	//stdArr.size();
	
	// 배열.
	const int length = 5;
	int array[length] = {};
	//memset(array, 0, sizeof(int) * length);

	// 동적배열.
	int* dArray = new int[length];

	//dArray[0] = 10;

	// 메모리 해제.
	delete[] dArray;

	int* ptr = array;
	*(ptr + 2) = 30;


	for (int ix = 0;ix < length;++ix)
	{
		array[ix] = ix + 1;
	}

	// Range-Based Loop
	//for (const int value : array)
	//{
	//	std::cout << value << ' ';
	//}

	PrintArray(array, length);

	std::cout << "\n";

	std::cin.get();
}