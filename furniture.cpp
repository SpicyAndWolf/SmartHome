#include"furniture.h"



Furniture::Furniture()//默认构造函数
	:Feature(_T("无")),Material(_T("砖头"))
{
	Type = _T("地板");
	Model = _T("AAA");
	Gear = 0;
	P_E = 0;
	length = 0;
	width = 0;
	h = 0;
	x = 0;
	y = 0;
	noise = 0;
	noise_now = 0;
	p_now = p;
	Symbol = (LPTSTR)_T("");
}

//非默认构造函数
Furniture::Furniture(const TCHAR* a, const TCHAR* b, int d, int f, int g, int qq, const TCHAR* i, int j , const TCHAR* k)
	:Type(a),Model(b),p(d),length(f),width(g),h(qq),Material(i),noise(j),Feature(k)
{
	Gear = AUTOGEAR;
	x = 0;
	y = 0;
	noise_now = 0;
	p_now = p;
	P_E = 0;
	Symbol = (LPTSTR)_T("");
}

Furniture::~Furniture()
{}



LPCTSTR Furniture:: getType()
{
	return Type;
}
LPCTSTR Furniture::getModel()
{
	return Model;
}
int Furniture::getGear()
{
	return Gear;
}
P Furniture::getP()
{
	return p;
}
P Furniture::getP_now()
{
	return p_now;
}

double Furniture::getP_E()
{
	P_E = (double)(p_now.getPower()) * 24/1000.0;
		return P_E;

}
L Furniture::getLength()
{
	return length;
}
L Furniture::getWidth()
{
	return width;
}
L Furniture::getH()
{
	return h;
}
LPCTSTR Furniture::getMaterial()
{
	return Material;
}
Noise Furniture::getNoise()
{
	return noise;
}

Noise Furniture::getNoise_now()
{
	return noise_now;
}

LPCTSTR Furniture::getFeature()
{
	return Feature;
}


int Furniture::getX()
{
	return x;
}

int Furniture::getY()
{
	return y;
}

void Furniture::setX(int a)
{
	x = a;
}
void Furniture::setY(int a)
{
	y = a;
}

void Furniture::setGear(int a)
{
	Gear = a;
}

void Furniture::F_run()
{

}

void Furniture::Noise_make()//注意，这个要紧贴着运行函数，因为自动挡的情况下运行函数的噪音值会发生改变
{
	for (int i = -1; i < 2; i++)
	{
		if ((x + i >= 0)&&(x+i<map_h))
		for (int j = -1; j < 2; j++)
		{
			if((y+j>=0)&&(y+j<map_l))
			map_info[x+i][y+j].noise =(noise_now+map_info[x+i][y+j].noise).getDb() ;
		}
	}
}


double Furniture::getTemperature() const//一些虚、纯虚函数
{
	return 0;
}
void Furniture::setTemperature(int a)
{}
int Furniture::getWind_power()const
{
	return 0;
}
int Furniture::getWind_power_now()const
{
	return 0;
}
void Furniture::setBacteria_power(int a)
{
}
int Furniture::getBacteria_power_now()const
{
	return 0;
}

void Furniture::setHumidity(int a)
{
}

void Furniture::setHumidity_request(int a)
{}

int Furniture::getHumidity_power()
{
	return 0;
}

int Furniture::getHumidity_power_now()
{
	return 0;
}

int Furniture::getHumidity_request()
{
	return 0;
}
int Furniture::getBacteria_power()const
{
	return 0;
}

void Furniture::setWindow_if(bool)
{

}
void Furniture::setGate_if(bool)
{

}
void Furniture::setMaterial(LPCTSTR)
{

}
bool Furniture::getGate_if()const
{
	return 0;
}
bool Furniture::getWindow_if()const
{
	return 0;
}
int Furniture::getHeat_transfer_speed()const
{
	return 0;
}

TCHAR* Furniture::getSymbol()
{
	return Symbol;
}

bool Furniture::judge_brick()
{
	return 0;
}