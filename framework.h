// header.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件
//

#pragma once
#ifndef FRAMEWORK_H
#define FRAMEWORK_H



#include "targetver.h"
#define WIN32_LEAN_AND_MEAN   // 从 Windows 头文件中排除极少使用的内容
#define AUTOGEAR 10    //用于判断电器是不是自动挡的值
#define WALLROOM 100 //用于判断是不是窗户的值
// Windows 头文件
#include <windows.h>
// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include<iostream>
#include<vector>
#include<tchar.h>
#include<fstream>
#include "mmsystem.h"//导入声音头文件
#pragma comment(lib,"winmm.lib")//导入声音头文件库


struct brick//这是地图里面每个单元格的数据类型,已在头文件里定义
{
    double temperature;
    int judge;
    int bacteria; 
    int noise;
    int humidity;
};

extern std::vector<std::vector<brick>> map_info; //声明地图
extern int map_l;//地图的长
extern int map_h;//地图的宽
extern double temperature_outdoor;//室外温度
extern int Sun_x;//太阳的横纵坐标
extern int Sun_y;
extern bool Sun_if;//判断有没有太阳

#endif // FRAMEWORK_H