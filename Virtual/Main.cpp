#include <iostream>

class Entity
{
public:
	Entity() { std::cout << "Entity() called.\n"; };
	// 부모 클래스 포인터로 자식 객체를 delete할 때,
	// virtual이 없으면 부모 클래스의 소멸자만 호출됩니다.
	// 자식 클래스에서 관리하던 자원(동적 메모리, 파일 핸들 등)이 해제되지 않아
	// 메모리 누수가 발생합니다.

	virtual ~Entity() { std::cout << "~Entity() called.\n"; };

	virtual const char* GetName(){ return "Entity";}
};

class Player : public Entity
{
public:
	Player(const char* inName)
	{
		std::cout << "Player() called.\n";
		size_t length = strlen(inName)+1;
		strcpy_s(name, length, inName);
	}

	~Player() { std::cout << "~Player() called.\n"; };

	// override가 상위 객체에 함수가 있고 없고를 알려줌. 함수 명 오타나면 빨간줄.
	virtual const char* GetName() override{ return name; } 

private:
	// 이름 값 저장 변수.
	char name[15] = {};
};

int main()
{
	Entity* e1 = new Entity();
	Entity* e2 = new Player("KHJ");

	//std::cout << e1->GetName() << "\n";
	//std::cout << sizeof(Entity) << "\n";
	//
	//std::cout << e2->GetName() << "\n";
	//std::cout << sizeof(Player) << "\n";

	delete e1;
	e1 = nullptr;

	delete e2;
	e2 = nullptr;
}
