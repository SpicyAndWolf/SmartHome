#include"humidifier.h"


Humidifier::Humidifier()
	:Furniture()
{
	Humidity_request = 50;
	Humidity_power = 0;
	Humidity_power_now = 0;
	bacteria_power = 0;
	bacteria_power_now = 0;
	Symbol = (LPTSTR)_T("֎");
}

Humidifier::Humidifier(const TCHAR* a, const TCHAR* b, int d, int f, int g, int qq, const TCHAR* i, int j, const TCHAR* k)
	:Furniture(a,b,d,f,g,qq,i,j,k),
	Humidity_request(50)
{
	Humidity_power = 0;
	Humidity_power_now = 0;
	bacteria_power = 0;
	bacteria_power_now = 0;
	Symbol = (LPTSTR)_T("֎");
}

Humidifier::~Humidifier()
{}

void Humidifier::setHumidity_request(int a)
{
	Humidity_request = a;
}

void Humidifier::setHumidity(int a)
{
	Humidity_power = a;
}

void Humidifier::setBacteria_power(int a)
{
	bacteria_power = a;
}

int Humidifier::getHumidity_power()
{
	return Humidity_power;
}

int Humidifier::getHumidity_power_now()
{
	return Humidity_power_now;
}

int Humidifier::getBacteria_power()const
{
	return bacteria_power;
}

int Humidifier::getBacteria_power_now()const
{
	return bacteria_power;
}

int Humidifier::getHumidity_request()
{
	return Humidity_request;
}

void Humidifier::setGear(int a)
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
			p_now = p - 10;
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

void Humidifier::F_run() //运行函数，增湿、除菌
{
	if (map_info[x][y].humidity < Humidity_request)//判断要不要增湿
	{
		if (Gear != AUTOGEAR)//判断是不是自动挡
		{
			if(map_info[x][y].bacteria>20)//判断要不要除菌
				for (int i = 0; i < map_h; i++)
				{
					for (int j = 0; j < map_l; j++)
					{
						map_info[i][j].humidity += (Humidity_power_now + rand() % 2);//增湿
						if (map_info[i][j].bacteria > 15)
						map_info[i][j].bacteria -= bacteria_power_now;//除菌
					}
				}
			else
				for (int i = 0; i < map_h; i++)
				{
					for (int j = 0; j < map_l; j++)
					{
						map_info[i][j].humidity += (Humidity_power_now + rand() % 2);//仅增湿
					}
				}
		}
		else
		{
			if (map_info[x][y].humidity < Humidity_request - 20)
			{
				if(map_info[x][y].bacteria > 15)//判断要不要除菌
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							map_info[i][j].humidity += (Humidity_power*3 + rand() % 2);//增湿
							if (map_info[i][j].bacteria > 15)
							map_info[i][j].bacteria -= bacteria_power*3;//除菌
						}
					}
				else
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							map_info[i][j].humidity += (Humidity_power*3 + rand() % 2);//仅增湿
						}
					}
				noise_now = noise * 3;
				Humidity_power_now = Humidity_power * 3;
				bacteria_power_now = bacteria_power * 3;
				p_now = p;
			}
			else if (map_info[x][y].humidity < Humidity_request - 10)
			{
				if (map_info[x][y].bacteria > 10)//判断要不要除菌
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							map_info[i][j].humidity += (Humidity_power * 2 + rand() % 2);//增湿
							if (map_info[i][j].bacteria > 15)
							map_info[i][j].bacteria -= bacteria_power * 2;//除菌
						}
					}
				else
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							map_info[i][j].humidity += (Humidity_power * 2 + rand() % 2);//仅增湿
						}
					}
				noise_now = noise * 2;
				Humidity_power_now = Humidity_power * 2;
				bacteria_power_now = bacteria_power * 2;
				p_now = p - 10;
			}

			else if (map_info[x][y].humidity < Humidity_request)
			{
				if (map_info[x][y].bacteria > 10)//判断要不要除菌
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							map_info[i][j].humidity += (Humidity_power + rand() % 2);//增湿
							if (map_info[i][j].bacteria > 15)
							map_info[i][j].bacteria -= bacteria_power;//除菌
						}
					}
				else
					for (int i = 0; i < map_h; i++)
					{
						for (int j = 0; j < map_l; j++)
						{
							map_info[i][j].humidity += (Humidity_power + rand() % 2);//仅增湿
						}
					}
				noise_now = noise;
				Humidity_power_now = Humidity_power;
				bacteria_power_now = bacteria_power;
				p_now = p - 30;
			}

		}

	}
	else
	{
		noise_now =0;
		Humidity_power_now = 0;
		bacteria_power_now = 0;
		p_now = 0;
	}
}