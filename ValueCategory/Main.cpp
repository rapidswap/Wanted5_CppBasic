#include <iostream>
#include <string>

class Actor
{
public:
	// const L-Value는 L-Value, R-Value 둘다 가능.
	Actor(const char* newName)
	{
		// 이름 값 설정.
		// 1. 공간 할당.
		size_t length = strlen(newName) + 1;
		name = new char[length] {};

		// 2. 값 복사.
		strcpy_s(name, length, newName);
	}

	~Actor()
	{
		if (name)
		{
			delete[] name;
			name = nullptr;
		}
	}

	// 복사 생성자.
	Actor(const Actor& other)
	{
		// 0. 기존 공간 해제.
		if (name)
		{
			delete[] name;
			name = nullptr;
		}

		// 1. 공간 할당.
		size_t length = strlen(other.name) + 1;
		name = new char[length] {};

		// 2. 값 복사.
		strcpy_s(name, length, other.name);
	}

	// 이동 생성자 - Move Constructor.
	Actor(Actor&& other) 
		//:name(other.name)
	{
		// 기존 메모리 해제.
		if (name)
		{
			delete[] name;
			name = nullptr;
		}

		// 주소 값 이전.
		name = other.name;

		// 주소값을 이전 시킨 후에 원본 주소를 null 대입.
		other.name = nullptr;
	}

private:
	char* name=nullptr;
};

// 함수 오버로딩 (같은 이름의 함수가 여러개 배치되는 형태).
void Use(int& value)
{
	std::cout << "void Use(int& value)\n";
}

void Use(int&& value)
{
	std::cout << "void Use(int&& value)\n";
}

class Item
{

};

void Test(Item& item)
{
	std::cout << "void Test(Item& item)\n";
}

void Test(Item&& item)
{
	std::cout << "void Test(Item&& item)\n";
}

template<typename T>
void Function(T&& value)
{ 
	Test(std::forward<T>(value));
}

int main() 
{
	int value = 10;
	Use(value);
	Use(std::move(value));

	Item item;
	Function(item);
	Function(Item());


	//std::string actor2Name = "name";
	//Actor actor1("Test");
	//Actor actor2(actor2Name);
	// count 는 L-Value.
	// L- value:
	// - 메모리를 차지하고,
	// - 이름이 있어 식별이 가능하면,
	// - 변경이 가능.
	// 10은 정수 리터럴로서 R-Value.
	// R-Value:
	// - 임시 값.
	int count = 10;

	// L-Value Reference(L-Value 참조).
	int& lRef = count;
	//int& lRef = 10; // 오류

	// R-Value Reference(R-Value 참조).
	int&& rRef = 10;
	rRef = 30;
	//int&& rRef = count; // 오류
	//int&& rRef2 = rRef; // 오류
}