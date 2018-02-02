#pragma once
#include "Macros.h"

struct Point
{
public:
	// constructor
	Point();
	Point(int _xy);
	Point(int _x, int _y);

	// destructor
	~Point();

	// return a point at 0, 0
	inline static Point* Zero() { return new Point(); };

	// return a point with standard units positions
	inline static Point* Unit() { return new Point(UNIT, UNIT); };

	// x position
	int x;

	// y position
	int y;
};