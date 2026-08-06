#include <iostream>
#include <memory>		// 스마트 포인터 사용을 위해 필요함.

class Actor
{
public:
	virtual ~Actor()=default;
};

class Player :public Actor
{
public:
	Player()
	{
		std::cout << "Player constructed\n";
	}

	~Player()
	{
		std::cout << "Player destroyed.\n";
	}

	void Attack()
	{
		std::cout << "Player attacks.\n";
	}
};

int main()
{
	//Player* player = new Player();
	//delete player;
	//player = nullptr;

	// 스마트 포인터.
	// STL - Standard Template Library.
	std::unique_ptr<Player> player = std::make_unique<Player>();
	
	// 스마트 포인터 객체의 사용은 일반 포인터의 사용 방법과 같다.
	// -> 연산자로 참조 가능.
	player->Attack();

	// 레퍼런스(역참조) 방법도 기존 포인터와 동일.
	Player& playerRef = *player;
}