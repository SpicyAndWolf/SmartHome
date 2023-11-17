#pragma once
#ifndef  FLOORHEAT_H
#define  FLOORHEAT_H


#include"furniture.h"

//这个类是地暖
//具有加热功能，在加热的同时会让室内更干燥
//没有噪音
class FloorHeat:public Furniture
{
public:
	FloorHeat();
	FloorHeat(const TCHAR*, const TCHAR*, int,  int, int, int, const TCHAR*, int, const TCHAR*);
	~FloorHeat();
	virtual void F_run() override;//干燥加升温
	virtual void setGear(int) override;

	void setTemperature(int)override;
	void setHumidity(int)override;
	double getTemperature()const override;
	int getHumidity_power()override;
	int getHumidity_power_now()override;

private:
	double Temperature;//限定的最高温度
	int humidity_power;//干燥能力,1为正常
	int humidity_power_now;
};




#endif // ! FLOORHEAT_H