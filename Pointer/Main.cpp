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
void Swap(int* const a, int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 레퍼런스를 활용한 swap 함수.
void SwapRef(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	// 두 수를 교환.
	int numberA = 10;
	int numberB = 20;
	//Swap(&numberA, &numberB);
	SwapRef(numberA, numberB);

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

//함수 매개변수 int* a 일때 const int* a(읽기만 가능하게 즉, 값이 변하면 안될떄) 
//int* const a일떄(주소를 변경하고 싶지 않을때) 사용
//참조는 int& const a(이미 값의 주소를 바꾸지 못하기 떄문에 써도 의미없음)