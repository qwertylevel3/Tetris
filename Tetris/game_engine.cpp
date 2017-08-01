#include"stdafx.h"
#include"Tetris.h"
#include<string>
#include<fstream>
game_engine::game_engine()
{
	offset.x=50;
	offset.y=20;
	paint_size.x=20;
	paint_size.y=20;
	pause=false;
	game_over=false;
	speed_level=0;
	memset(frame,0,sizeof(frame));
	score=0;
	hi_score=0;
	now_shape=NULL;
	next_shape=NULL;
	
}
void game_engine::get_shape()
{
	delete now_shape;
	now_shape=next_shape;
	int num=rand()%7+1;
	switch (num)
	{
	case 1:next_shape=new i_shape(frame_width/2,4,RGB(255,0,0));break;
	case 2:next_shape=new b_shape(frame_width/2,4,RGB(0,255,0));break;
	case 3:next_shape=new z1_shape(frame_width/2,4,RGB(0,0,255));break;
	case 4:next_shape=new z2_shape(frame_width/2,4,RGB(255,255,0));break;
	case 5:next_shape=new t_shape(frame_width/2,4,RGB(0,255,255));break;
	case 6:next_shape=new l1_shape(frame_width/2,4,RGB(255,0,255));break;
	case 7:next_shape=new l2_shape(frame_width/2,4,RGB(100,255,0));break;
	}
}
void game_engine::init()
{
	change_speed=false;
	hi_score=read_score();
	score=0;
	memset(frame,0,sizeof(frame));
	srand(time(0));
	get_shape();
	get_shape();
	speed_level=800;
	game_over=false;
	pause=false;
	hOffscreenDC = CreateCompatibleDC(GetDC(hWnd));
	hBitmap=CreateCompatibleBitmap(GetDC(hWnd),win_width,win_height);
	SelectObject(hOffscreenDC,hBitmap);
	read_score();
}
void game_engine::write_score()
{
	using namespace std;
	if(score>hi_score)
	{
		fstream fout("hi_score.dat",ios::out);
		if(fout)
		{

			fout<<score<<endl;
		}
		fout.close();
	}
	
}

int game_engine::read_score()
{
	using namespace std;
	fstream fin("hi_score.dat");
	if(fin)
	{
		fin>>hi_score;
		fin.close();
	}
	else
	{
		hi_score=0;
	}
	return hi_score;
}
void game_engine::game_end()
{
	DeleteObject(hBitmap);
	DeleteDC(hOffscreenDC);
	delete now_shape;
	delete next_shape;
	write_score();
}
void game_engine::paint(HDC hdc)
{
	for(int i=0;i<frame_width;i++)
	{
		for(int j=4;j<frame_height;j++)
		{
			if(frame[i][j]==1)
			{
				COLORREF color = RGB(255,0,100);
				HBRUSH hbrush=CreateSolidBrush(color);
				SelectObject(hdc,hbrush);
				POINT pos;
				pos.x=offset.x+i*paint_size.x;
				pos.y=offset.y+j*paint_size.y;
				Rectangle(hdc,pos.x,pos.y,paint_size.x+pos.x,paint_size.y+pos.y);
				DeleteObject(hbrush);
			}
			else
			{
				COLORREF color = RGB(255,255,255);
				HBRUSH hbrush=CreateSolidBrush(color);
				SelectObject(hdc,hbrush);
				POINT pos;
				pos.x=offset.x+i*paint_size.x;
				pos.y=offset.y+j*paint_size.y;
				Rectangle(hdc,pos.x,pos.y,paint_size.x+pos.x,paint_size.y+pos.y);
				DeleteObject(hbrush);
			}
		}
	}
	POINT next_shape_offset;
	next_shape_offset.x=250;
	next_shape_offset.y=80;
	now_shape->paint(hdc,paint_size,offset);
	next_shape->paint(hdc,paint_size,next_shape_offset);

	int iLength;
	TCHAR szWordBuffer[40];
	iLength=wsprintf(szWordBuffer,TEXT("NEXT:"));
	TextOut(hdc,270,100,szWordBuffer,iLength);

	iLength=wsprintf(szWordBuffer,TEXT("HI_SCORE: %i"),hi_score);
	TextOut(hdc,270,300,szWordBuffer,iLength);

	iLength=wsprintf(szWordBuffer,TEXT("SCORE: %i"),score);
	TextOut(hdc,270,350,szWordBuffer,iLength);

	if(game_over)
	{
		int iLength;
		TCHAR szBuffer[40];
		iLength=wsprintf(szBuffer,TEXT("GAME OVER"));
		TextOut(hdc,200,200,szBuffer,iLength);
	}
	if(pause)
	{
		int iLength;
		TCHAR szBuffer[40];
		iLength=wsprintf(szBuffer,TEXT("PAUSE"));
		TextOut(hdc,200,200,szBuffer,iLength);
	}
}
void game_engine::game_paint(HDC hdc)
{
	SetBkColor(hOffscreenDC,RGB(255,255,255));
	// Paint the game to the offscreen device context
	COLORREF color = RGB(255,255,255);
	HBRUSH hbrush=CreateSolidBrush(color);
	SelectObject(hOffscreenDC,hbrush);
	Rectangle(hOffscreenDC,0,0,win_width,win_height);
	DeleteObject(hbrush);
	paint(hOffscreenDC);

	// Blit the offscreen bitmap to the game screen
	BitBlt(hdc, 0, 0, win_width, win_height,
		hOffscreenDC, 0, 0, SRCCOPY);
}
bool game_engine::check_gameover()
{
	int i=0;
	for(;i<frame_width;i++)
	{
		if(frame[i][4]==1)
			break;
	}
	if(i!=frame_width)
	{
		game_over=true;
	}
	return game_over;
}
bool game_engine::check(int line)
{
	int i=0;
	for(;i<frame_width;i++)
	{
		if(frame[i][line]==0)
			return false;
	}
	return true;
}
void game_engine::clear_line(int line)
{
	
	for(int j=0;j<frame_width;j++)
	{
		frame[j][line]=0;
	}
	for(int j=line;j>4;j--)
	{
		for(int k=0;k<frame_width;k++)
		{
			frame[k][j]=frame[k][j-1];
		}
	}
	add_score(200);
	switch(score)
	{
	case 1000:speed_level=700;change_speed=true;break;
	case 2000:speed_level=600;change_speed=true;break;
	case 3000:speed_level=500;change_speed=true;break;
	case 4000:speed_level=400;change_speed=true;break;
	case 5000:speed_level=300;change_speed=true;break;
	default:break;
	}
}
bool game_engine::check_change()
{
	for(int i=0;i<4;i++)//检验当前方块位置是否合法
	{
		POINT temp_position=now_shape->get_single_position(i);
		if(frame[temp_position.x][temp_position.y]==1 
			|| temp_position.y>=frame_height 
			|| temp_position.x>=frame_width 
			|| temp_position.x<0)
		{
			return false;
		}
	}
	return true;
}
void game_engine::change_shape()
{
	POINT offset_x;
	int now_mod;
	now_mod=now_shape->get_mod();
	now_shape->change();
	if(check_change())//检查变换是否可行
	{
		return;
	}
	else//若不行调整
	{
		offset_x.x=-1;
		offset_x.y=0;
		now_shape->offset(offset_x);
		if(check_change())
		{
			return;
		}
		offset_x.x=2;
		now_shape->offset(offset_x);
		if(check_change())
		{
			return;
		}
		offset_x.x=1;
		now_shape->offset(offset_x);
		if(check_change())
		{
			return;
		}
		offset_x.x=-4;
		now_shape->offset(offset_x);
		if(check_change())
		{
			return;
		}
	}
	offset_x.x=2;//若怎么调整都不行，则返回原来状态
	now_shape->offset(offset_x);
	while(now_shape->get_mod()!=now_mod)
	{
		now_shape->change();
	}

}
void game_engine::game_cycle()
{
	if(!game_over && !pause)
	{
		InvalidateRect(hWnd,NULL,false);
		for(int i=0;i<4;i++)//检查是否到底
		{
			POINT temp_position=now_shape->get_single_position(i);
			if(frame[temp_position.x][temp_position.y+1]==1 || temp_position.y+1==frame_height)//若方块已经到底
			{
				for(int j=0;j<4;j++)
				{
					POINT temp=now_shape->get_single_position(j);
					frame[temp.x][temp.y]=1;
				}
				for(int j=0;j<4;j++)
				{
					POINT temp=now_shape->get_single_position(j);
					while(check(temp.y))
					{
						clear_line(temp.y);
					}
					
				}
				get_shape();
				break;
			}
		}
		if(!check_gameover())
		{

			POINT offset_position;
			offset_position.x=0;
			offset_position.y=1;
			now_shape->offset(offset_position);
		}
		
		
	}
}
void game_engine::move_shape(POINT shape_offset)
{
	now_shape->offset(shape_offset);
	if(check_change())
	{
		return;
	}
	else
	{
		POINT ret_offset;
		ret_offset.x=-shape_offset.x;
		ret_offset.y=-shape_offset.y;
		now_shape->offset(ret_offset);
	}
}
void game_engine::go_down()
{
	POINT down_offset;
	down_offset.x=0;
	down_offset.y=1;
	while(check_change())
	{
		now_shape->offset(down_offset);
	}
	down_offset.y=-1;
	now_shape->offset(down_offset);
}