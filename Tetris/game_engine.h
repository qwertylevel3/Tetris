#pragma once

#include"stdafx.h"

class game_engine
{
public:
	enum { frame_height=24,frame_width=10};
	game_engine();
	void get_hwnd(HWND hwnd){hWnd=hwnd;}; 
	void paint(HDC hdc);
	void init();
	void write_score();
	int read_score();
	bool check_change();
	void change_shape();
	void get_shape();
	void game_end();
	void game_cycle();
	bool check(int line);
	void clear_line(int line);
	bool check_gameover();
	void game_paint(HDC hdc);
	void go_down();
	int get_speed_level() { return speed_level;}
	void move_shape(POINT shape_offset);
	void switch_pause() { pause=(pause==true?false:true);}
	void switch_game_over() { game_over=(game_over==true?false:true);}
	void switch_change_speed() { change_speed=(change_speed==true?false:true);}
	bool get_change_speed() { return change_speed;}
	bool get_game_over() { return game_over;}
	void add_score(int sc){ score+=sc;}
protected:
	HWND hWnd;
	POINT offset;
	POINT paint_size;
	int speed_level;
	int frame[frame_width][frame_height];//¿ò¼Ü
	int score;
	int hi_score;
	bool pause;
	bool game_over;
	shape* now_shape;
	shape* next_shape;
	HDC hOffscreenDC;
	HBITMAP hBitmap;
	bool change_speed;
};
