#pragma once
#ifndef AIRFRESH_H
#define AIRFRESH_H
#include"furniture.h"

//需要额外对bacteria_power赋值
//档位有0—3，另外有AUTOGEAR为自动挡
class Air_fresh:public Furniture
{
public:
	Air_fresh();
	Air_fresh(const TCHAR*, const TCHAR*, int,  int, int, int, const TCHAR*, int, const TCHAR*,int);
	~Air_fresh();
	virtual void F_run() override;//减少细菌
	virtual void setGear(int) override;//重写的虚函数

	int getWind_power_now()const override;//获取当前风力情况
	int getBacteria_power()const override;
	int getBacteria_power_now()const override;
	void setBacteria_power(int)override;
	
private:
	int Wind_power;//1挡时的风力,
	int Wind_power_now;
	int bacteria_power;//1挡时的除菌水平,大概为5
	int bacteria_power_now;
};

#endif