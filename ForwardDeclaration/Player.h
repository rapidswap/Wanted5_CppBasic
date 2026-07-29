#pragma once

//#include "Weapon.h"
// Ctrl + K + O 헤더 -> cpp.

// 전방선언.
// 1. 컴파일 시간 단축.
// 2. 헤더 순환 참조 방지.
class Weapon;

class Player
{
public:
	Player();
	~Player();

private:
	// Weapon 변수.
	// 전방 선언 한것으로는 타입의 크기를 모름.
	// 전방 선언은 포인터없이 사용 불가능.
	// 함수는 레퍼런스(멤버 변수 없이) 가능.
	Weapon* weapon = nullptr;
};

