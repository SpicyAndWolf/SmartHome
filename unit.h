#pragma once
#ifndef UNIT_H
#define UNIT_H


#include"framework.h"
//这个头文件用于定义新的单位

class P//单位：W
{
private:
	int power;
public:
	P(int);//构造函数、析构函数
	P();
	~P();
	P operator+(P);//重载运算符
	P operator-(P);//重载运算符
	P operator/(int);//重载运算符
	P operator/(P);//重载运算符
	void decrease(int);
	void increase(int);
	void division(int);
	int getPower();
};

class L//单位：mm
{
private:
	int length;
public:
	L(int);//构造函数、析构函数
	L();
	~L();
	L operator+(L);//重载运算符
	L operator-(L);//重载运算符
	void decrease(int);
	void increase(int);
	int getLength();
};

class Noise//单位：Db
{
private:
	int Db;
public:
	Noise(int);//构造函数、析构函数
	Noise();
	~Noise();
	Noise operator+(Noise);//重载运算符
	Noise operator-(Noise);//重载运算符
	Noise operator*(int);//重载运算符
	void decrease(int);
	void increase(int);
	void multiplication(int);
	int getDb();
};


#endif // !UNIT_H