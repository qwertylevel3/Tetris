#include"stdafx.h"


void shape::paint(HDC hdc,POINT paint_size,POINT offset)
{
	for(int i=0;i<4;i++)
	{
		container[i].paint_cube(hdc,paint_size,offset);
	}
}
void shape::offset(POINT p)
{
	for(int i=0;i<4;i++)
	{
		container[i].set_position(container[i].get_position().x+p.x,container[i].get_position().y+p.y);
	}
}
shape::shape(COLORREF col)
{
	color=col;
	for(int i=0;i<4;i++)
	{
		container[i].set_color(color);
	}
}

POINT shape::get_single_position(int index)
{
	return container[index].get_position();
}

void i_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	for(int i=0;i<4;i++)
	{
		container[i].set_position(x+i,y);
	}
}
i_shape::i_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
i_shape::i_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
void i_shape::change()
{
	if(mod==1)//Êú±äºá
	{
		container[0].set_position(container[0].get_position().x-1,container[0].get_position().y-1);
		container[1].set_position(container[1].get_position().x,container[1].get_position().y);
		container[2].set_position(container[2].get_position().x+1,container[2].get_position().y+1);
		container[3].set_position(container[3].get_position().x+2,container[3].get_position().y+2);
	}
	else if(mod==0)//ºá±äÊú
	{
		container[0].set_position(container[0].get_position().x+1,container[0].get_position().y+1);
		container[1].set_position(container[1].get_position().x,container[1].get_position().y);
		container[2].set_position(container[2].get_position().x-1,container[2].get_position().y-1);
		container[3].set_position(container[3].get_position().x-2,container[3].get_position().y-2);
	}
	mod=1-mod;
}

void b_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	container[0].set_position(x,y);
	container[1].set_position(x+1,y);
	container[2].set_position(x,y-1);
	container[3].set_position(x+1,y-1);
}
b_shape::b_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
b_shape::b_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
void b_shape::change()
{

}

void z1_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	container[0].set_position(x,y);
	container[1].set_position(x+1,y);
	container[2].set_position(x+1,y-1);
	container[3].set_position(x+2,y-1);
}
z1_shape::z1_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
z1_shape::z1_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
void z1_shape::change()
{
	if(mod==0)
	{
		container[0].set_position(container[0].get_position().x+1,container[0].get_position().y);
		container[1].set_position(container[1].get_position().x,container[1].get_position().y-1);
		container[2].set_position(container[2].get_position().x-1,container[2].get_position().y);
		container[3].set_position(container[3].get_position().x-2,container[3].get_position().y-1);
	}
	else if(mod==1)
	{
		container[0].set_position(container[0].get_position().x-1,container[0].get_position().y);
		container[1].set_position(container[1].get_position().x,container[1].get_position().y+1);
		container[2].set_position(container[2].get_position().x+1,container[2].get_position().y);
		container[3].set_position(container[3].get_position().x+2,container[3].get_position().y+1);
	}
	mod=1-mod;
}


void z2_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	container[0].set_position(x,y);
	container[1].set_position(x,y-1);
	container[2].set_position(x+1,y-1);
	container[3].set_position(x+1,y-2);
}
z2_shape::z2_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
z2_shape::z2_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
void z2_shape::change()
{
	if(mod==0)
	{
		container[0].set_position(container[0].get_position().x,container[0].get_position().y-1);
		container[1].set_position(container[1].get_position().x+1,container[1].get_position().y);
		container[2].set_position(container[2].get_position().x,container[2].get_position().y+1);
		container[3].set_position(container[3].get_position().x+1,container[3].get_position().y+2);
	}
	else if(mod==1)
	{
		container[0].set_position(container[0].get_position().x,container[0].get_position().y+1);
		container[1].set_position(container[1].get_position().x-1,container[1].get_position().y);
		container[2].set_position(container[2].get_position().x,container[2].get_position().y-1);
		container[3].set_position(container[3].get_position().x-1,container[3].get_position().y-2);
	}
	mod=1-mod;
}

void t_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	container[0].set_position(x-1,y);
	container[1].set_position(x,y-1);
	container[2].set_position(x,y);
	container[3].set_position(x+1,y);
}
t_shape::t_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
t_shape::t_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
void t_shape::change()
{
	if(mod==0)
	{
		POINT position=container[2].get_position();
		container[0].set_position(position.x,position.y-1);
		container[1].set_position(position.x,position.y);
		container[2].set_position(position.x+1,position.y);
		container[3].set_position(position.x,position.y+1);
		mod=1;
	}
	else if(mod==1)
	{
		POINT position=container[1].get_position();
		container[0].set_position(position.x-1,position.y);
		container[1].set_position(position.x,position.y);
		container[2].set_position(position.x+1,position.y);
		container[3].set_position(position.x,position.y+1);
		mod=2;
	}
	else if(mod==2)
	{
		POINT position=container[1].get_position();
		container[0].set_position(position.x-1,position.y);
		container[1].set_position(position.x,position.y);
		container[2].set_position(position.x,position.y+1);
		container[3].set_position(position.x,position.y-1);
		mod=3;
	}
	else if(mod==3)
	{
		POINT position=container[1].get_position();
		container[0].set_position(position.x-1,position.y);
		container[1].set_position(position.x,position.y);
		container[2].set_position(position.x,position.y-1);
		container[3].set_position(position.x+1,position.y);
		mod=0;
	}
}

void l1_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	container[0].set_position(x,y);
	container[1].set_position(x+1,y);
	container[2].set_position(x-1,y);
	container[3].set_position(x-1,y+1);
}
l1_shape::l1_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
l1_shape::l1_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
void l1_shape::change()
{
	if(mod==0)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x,position.y-1);
		container[2].set_position(position.x,position.y+1);
		container[3].set_position(position.x+1,position.y+1);
		mod=1;
	}
	else if(mod==1)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x-1,position.y);
		container[2].set_position(position.x+1,position.y);
		container[3].set_position(position.x+1,position.y-1);
		mod=2;
	}
	else if(mod==2)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x,position.y+1);
		container[2].set_position(position.x,position.y-1);
		container[3].set_position(position.x-1,position.y-1);
		mod=3;
	}
	else if(mod==3)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x+1,position.y);
		container[2].set_position(position.x-1,position.y);
		container[3].set_position(position.x-1,position.y+1);
		mod=0;
	}
}


void l2_shape::initialize(int x,int y,COLORREF col)
{
	mod=0;
	container[0].set_position(x,y);
	container[1].set_position(x+1,y);
	container[2].set_position(x-1,y);
	container[3].set_position(x+1,y+1);
}
l2_shape::l2_shape(int x,int y,COLORREF col):shape(col)
{
	initialize(x,y,col);
}
l2_shape::l2_shape(POINT po,COLORREF col):shape(col)
{
	initialize(po.x,po.y,col);
}
void l2_shape::change()
{
	if(mod==0)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x,position.y-1);
		container[2].set_position(position.x,position.y+1);
		container[3].set_position(position.x-1,position.y+1);
		mod=1;
	}
	else if(mod==1)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x-1,position.y);
		container[2].set_position(position.x+1,position.y);
		container[3].set_position(position.x-1,position.y-1);
		mod=2;
	}
	else if(mod==2)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x,position.y+1);
		container[2].set_position(position.x,position.y-1);
		container[3].set_position(position.x+1,position.y-1);
		mod=3;
	}
	else if(mod==3)
	{
		POINT position=container[0].get_position();
		container[0].set_position(position.x,position.y);
		container[1].set_position(position.x+1,position.y);
		container[2].set_position(position.x-1,position.y);
		container[3].set_position(position.x+1,position.y+1);
		mod=0;
	}
}
