#pragma once
#ifndef FURNITURE_H
#define FURNITURE_H


#include"framework.h"
#include"unit.h"


//���������bacteriaֵΪ40���ң����ʱ�����80���ɾ�Ϊ20

class Furniture
{
protected:
	const TCHAR* Type;//�Ҿߵ����࣬������䡢�ذ�.....
	const TCHAR* Model;//�Ҿߵ��ͺţ���S-123���ֵ�
	int Gear;//�Ҿߵĵ�λ������3����ǿ��,0��Ϊ�ر�
	P p;//�����,����PΪ�Խ����࣬���ڱ�ʾ���ʣ���λΪW
	P p_now;
	double P_E;//�����һ��Ķ��ٵ�
	L length;//x��y��h�ֱ�Ϊ����ߣ�����LΪ�Խ����࣬���ڱ�ʾ���ȣ���λΪmm
	L width;
	L h;
	int x;//�Ҿߵ�ǰ��x��y����
	int y;//
	const TCHAR* Material;//�ҾߵĲ���
	Noise noise;//��ʾ�Ҿ�1��ʱ������ֵ������NoiseΪ�Խ����࣬���ڱ�ʾ��������λΪDb  һ���豸����������Ϊ20
	Noise noise_now;//��ǰ�������������ֵ
	const TCHAR* Feature;//��ʾһ����Ʒ����ɫ
	TCHAR* Symbol;

public:
	Furniture();
	Furniture(const TCHAR*, const TCHAR*, int, int, int, int, const TCHAR*, int, const TCHAR*);
	virtual ~Furniture();//����������virtual
	//����get����
	LPCTSTR getType();
	LPCTSTR getModel();
	int getGear();
	P getP();
	P getP_now();
	double getP_E();
	L getLength();
	L getWidth();
	L getH();
	int getX();
	int getY();
	LPCTSTR getMaterial();
	Noise getNoise();
	Noise getNoise_now();
	LPCTSTR getFeature();
	//һ��set���������ڵ��ص�ǰ�ҾߵĹ���
	void setP_now(P);
	void setX(int);
	void setY(int);
	void Noise_make();//���������ĺ���

	virtual void setGear(int);//���õ�ǰ��λ
	virtual void F_run();//ÿ���Ҿߵ����к����Ļ�����

	virtual double getTemperature() const;//һЩ�麯��
	virtual void setTemperature(int);
	virtual int getWind_power()const;
	virtual int getWind_power_now()const ;
	virtual void setBacteria_power(int);
	virtual int getBacteria_power_now()const;
	virtual int getBacteria_power()const ;
	virtual void setHumidity(int);
	virtual void setHumidity_request(int);
	virtual int getHumidity_power();
	virtual int getHumidity_power_now();
	virtual int getHumidity_request();

	virtual void setWindow_if(bool);
	virtual void setGate_if(bool);
	virtual void setMaterial(LPCTSTR);
	virtual bool getGate_if()const;
	virtual bool getWindow_if()const;
	virtual int getHeat_transfer_speed()const;
	virtual TCHAR* getSymbol();
	virtual bool judge_brick();
};


#endif // !FURNITURE_H