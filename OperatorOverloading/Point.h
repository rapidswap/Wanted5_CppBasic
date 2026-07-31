#pragma once		// 인클루드 가드
#include<iostream>


class Point
{
public:
	Point(int x, int y);

	// 덧셈 연산자 오버로딩.
	Point operator+(const Point& other) const;

	// friend로 연산자 오버로딩
	friend Point operator-(const Point& left, const Point& right);

	friend std::ostream& operator<<(std::ostream& os, const Point& point);

	
	void Print() const;

private:
	int x = 0;
	int y = 0;
};

