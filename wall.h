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
	void F_run() override;//ǽ���ȣ����window_ifΪ�棬���й⴫�ȡ����gate_ifΪ�棬���ȼӱ�

	void setWindow_if(bool);
	void setGate_if(bool);
	bool getGate_if()const;
	bool getWindow_if()const;
	int getHeat_transfer_speed()const;
	bool judge_brick() override;

private:
	int heat_transfer_speed;
	bool window_if;//��ʾ���λ���Ƿ��д���
	bool gate_if;//��ʾ���λ���Ƿ�����
	
};


#endif // !WALL_H