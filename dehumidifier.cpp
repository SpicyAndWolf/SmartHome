#include"dehumidifier.h"

Dehumidifier::Dehumidifier()
	:Humidifier()
{
	Symbol = (LPTSTR)_T("◙");
}
Dehumidifier::Dehumidifier(const TCHAR* a, const TCHAR* b, int d,  int f, int g, int qq, const TCHAR* i, int j, const TCHAR* k)
	:Humidifier(a, b,d,  f, g, qq, i, j, k)
{
	Symbol = (LPTSTR)_T("◙");
}
Dehumidifier::~Dehumidifier()
{}

void::Dehumidifier::F_run()
{
	if ((map_info[x][y].humidity > Humidity_request)&&(map_info[x][y].humidity>15))//判断要不要除湿
	{
		if (Gear != AUTOGEAR)//判断是不是自动挡
		{
				for (int i = 0; i < map_h; i++)
				{
					for (int j = 0; j < map_l; j++)
					{
						if(map_info[i][j].humidity>15)
						map_info[i][j].humidity -= (Humidity_power_now + rand() % 2);//除湿
					}
				}
		}
		else
		{
			if (map_info[x][y].humidity >( Humidity_request + 20))
			{
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							if (map_info[i][j].humidity > 15)
							map_info[i][j].humidity -= (Humidity_power * 3 + rand() % 2);
						}
					}
				noise_now = noise * 3;
				Humidity_power_now = Humidity_power * 3;
				p_now = p;
			}
			else if (map_info[x][y].humidity > (Humidity_request + 10))
			{
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							if (map_info[i][j].humidity > 15)
							map_info[i][j].humidity -= (Humidity_power * 2 + rand() % 2);
						}
					}
				noise_now = noise * 2;
				Humidity_power_now = Humidity_power * 2;
				p_now = p - 50;
			}

			else if (map_info[x][y].humidity > Humidity_request)
			{
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							if (map_info[i][j].humidity > 15)
							map_info[i][j].humidity -= (Humidity_power + rand() % 2);
						}
					}
				noise_now = noise;
				Humidity_power_now = Humidity_power;
				p_now = p - 80;
			}

		}

	}
	else
	{
		noise_now = 0;
		Humidity_power_now = 0;
		p_now = 0;
	}
}

void Dehumidifier::setGear(int a)
{
	Gear = a;
	if (Gear != AUTOGEAR)
	{
		noise_now = noise * a;
		bacteria_power_now = bacteria_power * a;
		Humidity_power_now = Humidity_power * a;
		switch (Gear)
		{
		case 3:
			p_now = p;
			break;
		case 2:
			p_now = p - 100;
			break;
		case 1:
			p_now = p - 180;
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