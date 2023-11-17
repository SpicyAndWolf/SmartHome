#include"Airfresh.h"

Air_fresh::Air_fresh()
	:Furniture()
{
	Wind_power = 0;
	Wind_power_now = 0;
	bacteria_power = 0;
	bacteria_power_now = 0;
	Symbol = (LPTSTR)_T("▼");
}

Air_fresh::Air_fresh(const TCHAR* a, const TCHAR* b, int d,  int f, int g, int qq, const TCHAR* i, int j, const TCHAR* k,int l)
	:Furniture(a,b,d,f,g,qq,i,j,k)
{
	Wind_power = l;
	Wind_power_now = 0;
	bacteria_power = 0;
	bacteria_power_now = 0;
	Symbol = (LPTSTR)_T("▼");
}

Air_fresh::~Air_fresh()
{}

void Air_fresh::F_run()//减少细菌
{
	if (Gear != AUTOGEAR)//判断是不是自动挡
	{
		if(map_info[0][0].bacteria>=20)
		for (int i = 0; i < map_h; i++)
		{
			for (int j = 0; j < map_l; j++)
			{
				map_info[i][j].bacteria -= bacteria_power_now;
			}
		}
	}
	else//以下为自动挡
	{
		if (map_info[x][y].bacteria > 80)
		{
			bacteria_power_now = 3*bacteria_power;
			Wind_power_now = 3*Wind_power;
			noise_now = noise * 3;
			p_now = p;
			for (int i = 0; i < map_h; i++)
			{
				for (int j = 0; j < map_l; j++)
				{
					if(map_info[i][j].bacteria>15)
					map_info[i][j].bacteria -= bacteria_power * 3;
				}
			}
		}
		else if (map_info[x][y].bacteria > 40)
		{
			bacteria_power_now = 2 * bacteria_power;
			Wind_power_now = 2 * Wind_power;
			noise_now = noise * 2;
			p_now = p - 20;
			for (int i = 0; i < map_h; i++)
			{
				for (int j = 0; j < map_l; j++)
				{
					if (map_info[i][j].bacteria > 15)
					map_info[i][j].bacteria -= bacteria_power * 2;
				}
			}
		}
		else if (map_info[x][y].bacteria > 20)
		{
			bacteria_power_now = bacteria_power;
			Wind_power_now = Wind_power;
			noise_now = noise;
			p_now = p - 30;
			for (int i = 0; i < map_h; i++)
			{
				for (int j = 0; j < map_l; j++)
				{
					if (map_info[i][j].bacteria > 15)
					map_info[i][j].bacteria -= bacteria_power;
				}
			}
		}
		else
		{
			bacteria_power_now = 0;
			Wind_power_now = 0;
			noise_now = 0;
			p_now = 0;
		}
	}

}

void Air_fresh::setGear(int a)
{
	Gear = a;
	if (Gear != AUTOGEAR)
	{		
		bacteria_power_now = a * bacteria_power;
		Wind_power_now = a * Wind_power;
		noise_now = noise * a;

		switch (Gear)
		{
		case 3:
			p_now = p;
			break;
		case 2:
			p_now = p - 20;
			break;
		case 1:
			p_now = p - 30;
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

void Air_fresh::setBacteria_power(int a)
{
	bacteria_power = a;
}

int Air_fresh::getBacteria_power_now()const
{
	return bacteria_power_now;
}

int Air_fresh::getWind_power_now()const
{
	return Wind_power_now;
}

int Air_fresh::getBacteria_power() const
{
	return bacteria_power;
}