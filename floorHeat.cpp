#include"floorHeat.h"

FloorHeat::FloorHeat()
	:Furniture()
{
	Temperature = 26;
	humidity_power = 0;
	humidity_power_now = 0;
	Symbol = (LPTSTR)_T("ⱷ");
}

FloorHeat::FloorHeat(const TCHAR* a, const TCHAR* b,int d,  int f, int g, int qq, const TCHAR* i, int j, const TCHAR* k)
	:Furniture(a,b,d,f,g,qq,i,j,k)
{
	Temperature = 26;
	humidity_power = 0;
	humidity_power_now = 0;
	Symbol = (LPTSTR)_T("ⱷ");
}

FloorHeat::~FloorHeat()
{}

void FloorHeat::setTemperature(int a)
{
	Temperature = a;
}

void FloorHeat::setHumidity(int a)
{
	humidity_power = a;
}

double FloorHeat::getTemperature()const
{
	return Temperature;
}
int FloorHeat::getHumidity_power()
{
	return humidity_power;
}

int FloorHeat::getHumidity_power_now()
{
	return humidity_power_now;
}

void FloorHeat::setGear(int a)
{
	Gear = a;
	if (Gear != AUTOGEAR)
	{
		switch (Gear)
		{
		case 3:
			p_now = p;
			break;
		case 2:
			p_now = p - 30;
			break;
		case 1:
			p_now = p - 80;
			break;
		case 0:
			p_now = 0;
			break;
		default:
			p_now = 0;
			break;
		}
		humidity_power_now = Gear * humidity_power;
	}

}

void FloorHeat::F_run() //干燥加升温
{
	if (map_info[x][y].temperature < Temperature)
	{
		if (Gear != AUTOGEAR)//判断是不是自动挡
		{
			for (int i = 0; i < map_h; i++)
			{
				for (int j = 0; j < map_l; j++)
				{
					double a = (rand() % 5) / 40.0;
					map_info[i][j].temperature += a * Gear;//加热
					if(map_info[i][j].humidity>15)
					map_info[i][j].humidity -= humidity_power_now;//干燥
				}
			}
		}
		else
		{
			if (map_info[x][y].temperature < (Temperature - 4.0))
			{
				humidity_power_now = 3 * humidity_power;
				p_now = p;
				for (int i = 0; i < map_h; i++)
				{
					for (int j = 0; j < map_l; j++)
					{
						double a = (rand() % 5) / 40.0;
						map_info[i][j].temperature += a * 3;//加热
						if (map_info[i][j].humidity > 15)//判断会不会干燥
					    map_info[i][j].humidity -= humidity_power*3;//干燥
					}
				}

			}
			else if (map_info[x][y].temperature < (Temperature - 2.0))
			{
				humidity_power_now = 2 * humidity_power;
				p_now = p-30;
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							double a = (rand() % 5) / 40.0;
							map_info[i][j].temperature += a * 2;//加热
							if (map_info[i][j].humidity > 15)//判断会不会干燥
							map_info[i][j].humidity -= humidity_power * 2;//干燥
						}
					}

			}
			else if (map_info[x][y].temperature < Temperature)
			{
				humidity_power_now = humidity_power;
				p_now = p-80;
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							double a = (rand() % 5) / 40.0;
							map_info[i][j].temperature += a;//加热
							if (map_info[i][j].humidity > 15)//判断会不会干燥
							map_info[i][j].humidity -= humidity_power;//干燥
						}
					}
			}

		}



	}
	else
	{

		if (Gear == AUTOGEAR)
		{
			p_now = 0;
			humidity_power_now = 0;
		}
	}
}