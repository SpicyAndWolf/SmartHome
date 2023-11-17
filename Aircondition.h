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

	virtual void setGear(int) override;//���õ�λ
	virtual void F_run() override;//�յ������к��������¼�����ϸ��

private:
	double Temperature;//�趨���¶�
	int Wind_power;//����//�Ұ�100����Ϊ1���ķ���
	int Wind_power_now;
	int bacteria_power;//����ϸ����������3����
	int bacteria_power_now;
	void insideFunction(int);
};



#endif // !FURNITURE_DERIVE_H
