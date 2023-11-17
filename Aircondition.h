#pragma once
#ifndef FURNITURE_DERIVE_H
#define FURNITURE_DERIVE_H


#include"furniture.h"


class Air_condition:public Furniture
{
public:
	Air_condition();
	Air_condition(const TCHAR*, const TCHAR*, int,  int, int, int, const TCHAR*, int, const TCHAR*,int);
	~Air_condition();
	double getTemperature() const override;
	void setTemperature(int) override;
	int getWind_power()const override;
	int getWind_power_now()const override;
	void setBacteria_power(int) override;
	int getBacteria_power_now()const override;
	int getBacteria_power() const override;

	virtual void setGear(int) override;//设置档位
	virtual void F_run() override;//空调的运行函数，降温加增生细菌

private:
	double Temperature;//设定的温度
	int Wind_power;//风力//我按100左右为1挡的风力
	int Wind_power_now;
	int bacteria_power;//创造细菌的能力，3左右
	int bacteria_power_now;
	void insideFunction(int);
};



#endif // !FURNITURE_DERIVE_H
