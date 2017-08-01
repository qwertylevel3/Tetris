#pragma once

#include"stdafx.h"


class shape
{
public:
	shape(COLORREF col);
	virtual void paint(HDC hdc,POINT paint_size,POINT offset);
	virtual void change()=0;
	void init(int x,int y,COLORREF col);
	void offset(POINT p);

	void set_color(COLORREF col){ color=col;}

	COLORREF get_color() { return color;}
	POINT get_single_position(int index);

	int get_mod(){ return mod;}
protected:
	COLORREF color;
	cube container[4];
	int mod;
};

class i_shape:public shape
{
public:
	i_shape(POINT po,COLORREF col);
	i_shape(int x,int y,COLORREF col);
	void change();
	~i_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};

class b_shape:public shape
{
public:
	b_shape(POINT po,COLORREF col);
	b_shape(int x,int y,COLORREF col);
	void change();
	~b_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};

class z1_shape:public shape
{
public:
	z1_shape(POINT po,COLORREF col);
	z1_shape(int x,int y,COLORREF col);
	void change();
	~z1_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};

class z2_shape:public shape
{
public:
	z2_shape(POINT po,COLORREF col);
	z2_shape(int x,int y,COLORREF col);
	void change();
	~z2_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};

class t_shape:public shape
{
public:
	t_shape(POINT po,COLORREF col);
	t_shape(int x,int y,COLORREF col);
	void change();
	~t_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};

class l1_shape:public shape
{
public:
	l1_shape(POINT po,COLORREF col);
	l1_shape(int x,int y,COLORREF col);
	void change();
	~l1_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};

class l2_shape:public shape
{
public:
	l2_shape(POINT po,COLORREF col);
	l2_shape(int x,int y,COLORREF col);
	void change();
	~l2_shape(){};
protected:
	void initialize(int x,int y,COLORREF col);
};