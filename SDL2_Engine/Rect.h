#pragma once
#include "SDL_rect.h"
#include "Point.h"

class Rect : public SDL_Rect
{
public:
	// construtor
	Rect();

	// constructor with with and height
	Rect(int _w, int _h);
	Rect(Point* _b);

	// constructor with with, height, x and y pos
	Rect(Point* _p, Point* _b);
	Rect(Point* _p, int _w, int _h);
	Rect(int _x, int _y, Point* _b);
	Rect(int _x, int _y, int _w, int _h);
};