#pragma once
#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H

#include"furniture.h"

class Humidifier:public Furniture
{
public:
	Humidifier();
	Humidifier(const TCHAR*, const TCHAR*,  int, int, int, int, const TCHAR*, int, const TCHAR*);
	virtual ~Humidifier();

	void setHumidity(int)override;
	void setBacteria_power(int)override;
	void setHumidity_request(int)override;
	int getHumidity_power()override;
	int getBacteria_power()const override;
	int getHumidity_power_now()override;
	int getBacteria_power_now()const override;
	int getHumidity_request()override;

	virtual void F_run() override;//���к�������ʪ����
	virtual void setGear(int) override;

protected:
	int Humidity_request;//Ҫ���ʪ������,60����
	int Humidity_power;//��ʪ����,1����
	int Humidity_power_now;
	int bacteria_power;//ɱ������
	int bacteria_power_now;

};







#endif // !HUMIDIFIER_H
