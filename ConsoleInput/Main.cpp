#include <iostream>

int main()
{
	int value = 0;
	//검증용 문자 버퍼
	char buffer[50] = {};

	while (true)
	{
		std::cout << "0이 아닌 숫자를 입력하세요.(첫 번째): ";

		std::cin >> buffer;

		//검증
		if ((value = atoi(buffer)) == 0)
		{
			std::cout << "숫자를 입력하세요.\n";
		}
		else
		{
			break;
		}
	}
	


	int value2 = 0;
	std::cout << "0이 아닌 숫자를 입력하세요.(두 번째): ";

	std::cin >> value2;

	std::cout << "입력한 두 수의 합은 " << (value + value2) << "입니다.\n";
	//std::cout << "입력하신 숫자는 " << value << "입니다.\n";

	std::cin.get();
}