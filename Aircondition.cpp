#include"Aircondition.h"


Air_condition::Air_condition() //默认构造函数
	:Furniture()
{
	Temperature = 26.0;
	Wind_power = 0;
	Wind_power_now = 0;
	bacteria_power = 0;
	bacteria_power_now = 0;
	Symbol = (LPTSTR)_T("♫");
}
Air_condition::Air_condition(const TCHAR* a, const TCHAR* b,  int d, int f, int g
	, int qq, const TCHAR* i, int j, const TCHAR* k, int m)
	:Furniture(a,b,d,f,g,qq,i,j,k),
	Wind_power(m)
{
	Temperature = 26;
	bacteria_power = 0;
	Wind_power_now = 0;
	bacteria_power_now = 0;
	Symbol = (LPTSTR)_T("♫");
}

Air_condition::~Air_condition()
{}
double Air_condition::getTemperature()const
{
	return Temperature;
}
void Air_condition::setTemperature(int a)
{
	Temperature = a;
}
int Air_condition::getWind_power()const
{
	return Wind_power;
}

void Air_condition::insideFunction(int num)
{
	for (int i = -1; i < 2; i++)
	{
		if ((x + i >= 0) && (x + i < map_h))
			for (int j = -1; j < 2; j++)
			{
				if ((y + j > 0) && (y + j < map_l))
				{
					double a = (rand() % 5) / 40.0;
					if (map_info[x + i][y + j].temperature > Temperature)
						map_info[x + i][y + j].temperature -= a * num;//降温
					int b = (rand() % 3) * bacteria_power * num;//增生细菌
					map_info[x + i][y + j].bacteria += b;
				}
			}
	}
	Wind_power_now = Wind_power * num;
	noise_now = noise * num;
	bacteria_power_now = bacteria_power * num;
}

void Air_condition::setGear(int a)
{
	Gear = a;
	if (a != AUTOGEAR)
	{
		Wind_power_now = Wind_power * a;
		noise_now = noise * a;
		bacteria_power_now = bacteria_power * a;
		switch (Gear)
		{
		case 3:
			p_now = p;
			break;
		case 2:
			p_now = p -20;
			break;
		case 1:
			p_now = p - 60;
			break;
		case 0:
			p_now = 0;
			break;
		default:
			p_now = 0;
			break;
		}
	}

}

void Air_condition::F_run()//空调的运行函数，降温加增生细菌
{
	if (map_info[x][y].temperature > Temperature)//判断是否降温
	{
		if (Gear != AUTOGEAR) //我定义的宏，值为10.意思是自动挡
		{
			for (int i = -1; i < 2; i++)
			{
				if ((x + i >= 0) && (x + i < map_h))
					for (int j = -1; j < 2; j++)
					{

						double a = (rand() % 5) / 40.0;
						if (map_info[x + i][y + j].temperature > Temperature)
							map_info[x + i][y + j].temperature -= a * Gear;//降温
						int b = (rand() % 3) * bacteria_power * Gear;//增生细菌
						map_info[x + i][y + j].bacteria += b;
					}
			}

		}

		else//这是自动挡的工作逻辑
		{
			if (map_info[x][y].temperature > (Temperature + 4.0))//如果温度大于设置的温度4度以上
			{
				insideFunction(3);
				p_now = p;
			}

			else if (map_info[x][y].temperature > (Temperature + 2.0))//如果温度大于设置的温度2度以上
			{
				insideFunction(2);
				p_now = p - 20;

			}
			else if (map_info[x][y].temperature > (Temperature))//如果温度大于设置的温度
			{
				insideFunction(1);
				p_now = p - 60;
			}
		}
	}
	else//如果温度不大于设定的温度
	{
	Wind_power_now = 0;
	noise_now = 0;
	bacteria_power_now = 0;
	p_now = 0;
	}
}

void Air_condition::setBacteria_power(int a)
{
	bacteria_power = a;//2左右
}

int Air_condition::getWind_power_now()const
{
	return Wind_power_now;
}

int Air_condition::getBacteria_power_now()const
{
	return bacteria_power_now;
}

int Air_condition::getBacteria_power() const
{
	return bacteria_power;
}