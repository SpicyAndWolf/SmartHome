#pragma once
#ifndef UNIT_H
#define UNIT_H


#include"framework.h"
//���ͷ�ļ����ڶ����µĵ�λ

class P//��λ��W
{
private:
	int power;
public:
	P(int);//���캯������������
	P();
	~P();
	P operator+(P);//���������
	P operator-(P);//���������
	P operator/(int);//���������
	P operator/(P);//���������
	void decrease(int);
	void increase(int);
	void division(int);
	int getPower();
};

class L//��λ��mm
{
private:
	int length;
public:
	L(int);//���캯������������
	L();
	~L();
	L operator+(L);//���������
	L operator-(L);//���������
	void decrease(int);
	void increase(int);
	int getLength();
};

class Noise//��λ��Db
{
private:
	int Db;
public:
	Noise(int);//���캯������������
	Noise();
	~Noise();
	Noise operator+(Noise);//���������
	Noise operator-(Noise);//���������
	Noise operator*(int);//���������
	void decrease(int);
	void increase(int);
	void multiplication(int);
	int getDb();
};


#endif // !UNIT_H