#include <iostream>


// 클래스.
class Player
{
public:
	// 생성자.
	Player(const char* name)
	{
		size_t length = strlen(name)+1;
		this->name = new char[length];

		// 문자열 값 복사.
		strcpy_s(this->name, length, name);

		// 값 저장.
		//for (size_t ix = 0;ix < length - 1;++ix)
		//{
		//	this->name[ix] = name[ix];
		//}
		//this->name[length - 1] = '\0';
	}

	~Player()
	{
		// name 값이 null인지 확인.
		//if(name)
		//if(name != nullptr)
		if (nullptr != name)
		{
			delete[] name;
		}
	}

	// 이름 출력.
	void PrintName() const
	{
		std::cout << name << '\n';
	}

private:
	// 이름을 저장할 변수.
	char* name = nullptr;

};


int main()
{
	Player player("KHJ");
	player.PrintName();


	// 문자열. 
	const char* name = "hj";
	//const wchar_t* wName;

	//char nameArray[4];
	//nameArray[0] = 'R';
	//nameArray[1] = 'o';
	//nameArray[2] = 'n';
	//nameArray[3] = '\0'; // 문자열 종료 문자.


	size_t length=strlen(name);
	std::cout << "string length: " << length << "\n";

	std::cin.get();
}