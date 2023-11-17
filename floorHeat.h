#pragma once
#ifndef  FLOORHEAT_H
#define  FLOORHEAT_H


#include"furniture.h"

//������ǵ�ů
//���м��ȹ��ܣ��ڼ��ȵ�ͬʱ�������ڸ�����
//û������
class FloorHeat:public Furniture
{
public:
	FloorHeat();
	FloorHeat(const TCHAR*, const TCHAR*, int,  int, int, int, const TCHAR*, int, const TCHAR*);
	~FloorHeat();
	virtual void F_run() override;//���������
	virtual void setGear(int) override;

	void setTemperature(int)override;
	void setHumidity(int)override;
	double getTemperature()const override;
	int getHumidity_power()override;
	int getHumidity_power_now()override;

private:
	double Temperature;//�޶�������¶�
	int humidity_power;//��������,1Ϊ����
	int humidity_power_now;
};




#endif // ! FLOORHEAT_H