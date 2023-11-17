#pragma once
#ifndef WALL_H
#define WALL_H

#include"furniture.h"

class Wall:public Furniture
{
public:
	Wall();
	Wall(int, const TCHAR*, const TCHAR*, int, int, int, int, const TCHAR*, int, const TCHAR*);
	~Wall();
	void F_run() override;//墙传热，如果window_if为真，则还有光传热。如果gate_if为真，则传热加倍

	void setWindow_if(bool);
	void setGate_if(bool);
	bool getGate_if()const;
	bool getWindow_if()const;
	int getHeat_transfer_speed()const;
	bool judge_brick() override;

private:
	int heat_transfer_speed;
	bool window_if;//显示这个位置是否有窗户
	bool gate_if;//显示这个位置是否有门
	
};


#endif // !WALL_H