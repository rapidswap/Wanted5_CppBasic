#include "Player.h"
#include <iostream>

int main()
{
	//Player *player1=new Player();
	//Player *player2=new Player("HJ");
	//Player *player3=new Player(*player2);

	//delete player1;
	//delete player2;
	//delete player3;

	Player player1;
	Player player2("HJ");
	Player player3(player2);
	Player player4 = player3;

	std::cin.get();
}