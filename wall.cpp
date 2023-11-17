#include"wall.h"

Wall::Wall()
	:Furniture()
{
	heat_transfer_speed = 0;
	width = 0;
	h = 0;
	window_if = 0;
	gate_if = 0;
	Symbol = (LPTSTR)_T("▒");
}

Wall::Wall(int a, const TCHAR* c, const TCHAR* d, int e, int  f, int g, int qq, const TCHAR* i, int j, const TCHAR* k)
	:Furniture(c, d, e, f, g, qq, i, j, k),
	heat_transfer_speed(a)
{
	gate_if = 0;
	window_if = 0;
	Symbol = (LPTSTR)_T("▒");
}

Wall::~Wall()
{}


void Wall::setWindow_if(bool a)
{
	window_if = a;
	if (a == 1)
	{
		Type = _T("窗户");
		Model = NULL;
		heat_transfer_speed+=2;
		noise=noise+1;
		Symbol = (LPTSTR)_T("♥");
	}
	
}

void Wall::setGate_if(bool a)
{
	gate_if = a;
	{
		{
			Type = _T("门");
			Model = NULL;
			heat_transfer_speed+=1;
			noise = noise + 1;
			Symbol = (LPTSTR)_T("℗");
		}
	}
}



bool Wall::getWindow_if()const
{
	return window_if;
}

bool Wall::getGate_if()const
{
	return gate_if;
}

int Wall::getHeat_transfer_speed()const
{
	return heat_transfer_speed;
}


void Wall::F_run()
{
	//两部分，一部分是墙、门、窗的正常传热，一部分是窗的光线照射传热（这个得等到外部环境创建好了再说了)
	//外界温度和内部温度的差值将会影响传热速率
	//墙的传热速率也是因素之一
	double a = temperature_outdoor - map_info[x][y].temperature;//这一部分是正常传热
		for (int i = -1; i < 2; i++)
		{
			if ((x + i >= 0) && (x + i < map_h))
				for (int j = -1; j < 2; j++)
				{
					if ((y + j >= 0) && (y + j < map_l))
						map_info[x+i][j+y].temperature += heat_transfer_speed * a / 1000.0;
				}
		}


	//下面是光线传热
	if (window_if&&Sun_if)//判断它是不是窗户，且当前有没有太阳
	{
		bool temp = 1;//判断阳光能不能照进来的值
		bool temp_2 = 1;
		if (Sun_y > y)//判断是不是上面的墙壁且太阳在上方
			for (int j = y; j < map_l; j++)
			{
				if (map_info[x][j].judge == WALLROOM)
				{
					temp = 0;
					break;
				}
			}
		else if(Sun_y<y)//判断是不是下面的墙壁且太阳在下方
			for (int j = y; j >= 0; j--)
			{
				if (map_info[x][j].judge == WALLROOM)
					temp = 0;
			}

		if (!temp)//如果不是上下方的窗户，则判断是不是左右两边的窗户
		{
			if (Sun_x > x)
			{
				for (int i = x; i < map_h; i++)
				{
					if (map_info[i][y].judge == WALLROOM)
					{
						temp_2 = 0;
						break;
					}
				}
			}
			else if (Sun_x < x)
			{
				for (int i = x; i >= 0; i--)
				{
					if (map_info[i][y].judge == WALLROOM)
					{
						temp_2 = 0;
						break;
					}
				}
			}
		}
		
		if (temp)//窗户是竖直方向的
		{
			for (int i = 0; i < map_h; i++)
				map_info[i][y].temperature += (rand() % 3 / 500.0);
		}
		else if (temp_2)//窗户是水平方向的
		{
			for (int j = 0; j < map_l; j++)
				map_info[x][j].temperature += (rand() % 3 / 500.0);
		}


	}
	
}

bool Wall::judge_brick()
{
	return 1;
}