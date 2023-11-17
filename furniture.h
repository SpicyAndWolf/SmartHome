#pragma once
#ifndef FURNITURE_H
#define FURNITURE_H


#include"framework.h"
#include"unit.h"


//正常情况下bacteria值为40左右，脏的时候大于80，干净为20

class Furniture
{
protected:
	const TCHAR* Type;//家具的种类，比如冰箱、地板.....
	const TCHAR* Model;//家具的型号，如S-123这种的
	int Gear;//家具的档位，比如3挡是强风,0挡为关闭
	P p;//额定功率,其中P为自建的类，用于表示功率，单位为W
	P p_now;
	double P_E;//额定功率一天耗多少电
	L length;//x、y、h分别为长宽高，其中L为自建的类，用于表示长度，单位为mm
	L width;
	L h;
	int x;//家具当前的x、y坐标
	int y;//
	const TCHAR* Material;//家具的材质
	Noise noise;//表示家具1挡时的噪音值，其中Noise为自建的类，用于表示噪音，单位为Db  一个设备的正常噪音为20
	Noise noise_now;//当前运行情况的噪音值
	const TCHAR* Feature;//表示一个产品的特色
	TCHAR* Symbol;

public:
	Furniture();
	Furniture(const TCHAR*, const TCHAR*, int, int, int, int, const TCHAR*, int, const TCHAR*);
	virtual ~Furniture();//对析构函数virtual
	//各种get函数
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
	//一个set函数，用于调控当前家具的功率
	void setP_now(P);
	void setX(int);
	void setY(int);
	void Noise_make();//产生噪音的函数

	virtual void setGear(int);//设置当前档位
	virtual void F_run();//每个家具的运行函数的基函数

	virtual double getTemperature() const;//一些虚函数
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