#include"stdafx.h"

void cube::paint_cube(HDC hdc,POINT paint_size,POINT offset) const
{
	HBRUSH hbrush=CreateSolidBrush(color);
	SelectObject(hdc,hbrush);
	POINT pos;
	pos.x=offset.x+position.x*paint_size.x;
	pos.y=offset.y+position.y*paint_size.y;
	Rectangle(hdc,pos.x,pos.y,length+pos.x,length+pos.y);
	DeleteObject(hbrush);
}

cube::cube()
{
	length=20;
	color=RGB(0,0,0);
	position.x=0;
	position.y=0;
}