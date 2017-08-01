#pragma once

#include"stdafx.h"

class cube
{
public:
	cube();
	cube(COLORREF col,POINT p,int len):color(col),position(p),length(len){}
	cube(COLORREF col,int x,int y,int len):color(col){position.x=x;position.y=y;length=len;}

	void paint_cube(HDC hdc,POINT paint_size,POINT offset) const;

	void set_color(COLORREF col){ color=col;}
	void set_position(POINT p){ position.x=p.x; position.y=p.y;}
	void set_position(int x,int y) { position.x=x;position.y=y;}
	void set_length(int len){ length=len;}

	COLORREF get_color(){ return color;}
	int get_length(){ return length;}
	POINT get_position() { return position;}
protected:
	int length;
	COLORREF color;
	POINT position;
};