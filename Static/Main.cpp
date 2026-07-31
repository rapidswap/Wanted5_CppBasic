#include <iostream>
#include "File1.h"
#include "File2.h"
#include "Person.h"


void Increment()
{
	static int count = 0;
	++count;
	std::cout << "Count: " << count << "\n";
}

#pragma once

// 현재 존재하는 person 객체의 수.
//int personCount = 0;

class Person
{
public:
	Person()
	{
		++personCount;
		std::cout << personCount << "번째 Person 객체 생성\n";
	}

	~Person()
	{
		--personCount;
	}

private:
	static int personCount;
	//inline static int personCount;
};

// static 변수는 별도로 초기화 해야함.
int Person::personCount = 0;

int main()
{
	//FileOneFunction();
	//FileTwoFunction();
	// Increment();
	// Increment();
	// Increment();
	
	Person p1;
	Person p2;
	

	Person p3;

}