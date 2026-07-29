#include<iostream>

void Release(int** t)
{
	if (t != nullptr)
	{
		delete *t;
		*t = nullptr;
	}
}

// 두 변수의 값을 서로 교환하는 함수.
void swap(int* const a, int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	// 두 수를 교환.
	int numberA = 10;
	int numberB = 20;
	swap(&numberA, &numberB);

	int var = 8;
	int* ptr = &var;

	int *testPtr = new int;
	Release(&testPtr);
	//delete testPtr;
	//testPtr = nullptr;

	// 동적 할당.
	const int length = 100;
	int* buffer = new int[length];
	int** bufferPtr = &buffer;
	//int*** bufferPtrPtr = &bufferPtr;

	memset(buffer, 0, sizeof(int));
	
	delete[] buffer;

	std::cin.get();
}