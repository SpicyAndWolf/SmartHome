#pragma once
#ifndef AIRFRESH_H
#define AIRFRESH_H
#include"furniture.h"

//��Ҫ�����bacteria_power��ֵ
//��λ��0��3��������AUTOGEARΪ�Զ���
class Air_fresh:public Furniture
{
public:
	Air_fresh();
	Air_fresh(const TCHAR*, const TCHAR*, int,  int, int, int, const TCHAR*, int, const TCHAR*,int);
	~Air_fresh();
	virtual void F_run() override;//����ϸ��
	virtual void setGear(int) override;//��д���麯��

	int getWind_power_now()const override;//��ȡ��ǰ�������
	int getBacteria_power()const override;
	int getBacteria_power_now()const override;
	void setBacteria_power(int)override;
	
private:
	int Wind_power;//1��ʱ�ķ���,
	int Wind_power_now;
	int bacteria_power;//1��ʱ�ĳ���ˮƽ,���Ϊ5
	int bacteria_power_now;
};

#endif