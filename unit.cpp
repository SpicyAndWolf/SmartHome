#include"unit.h"
////////////////
/////功率
////////////////
P::P(int a)//构造函数
	:power(a)
{}

P::~P()//析构函数
{}

P::P()//默认构造函数
{
	power = 0;
}

void P::increase(int a)
{
	power += a;
}

void P::decrease(int a)
{
	power -= a;
}

void P::division(int a)
{
	power /= a;
}

int P::getPower()
{
	return power;
}

P P::operator+(P a)
{
	P b(power);
	b.increase(a.getPower());
	return b;
}
P P::operator-(P a)
{
	P b(power);
	b.decrease(a.getPower());
	return b;
}

P P::operator/(int a)
{
	P b(power);
	b.division(a);
	return b;
}
P P::operator/(P a)
{
	P b(power);
	b.division(a.getPower());
	return b;
}


////////////////
//////长度
////////////////
L::L(int a)//构造函数
	:length(a)
{}

L::~L()//析构函数
{}

L::L()//默认构造函数
{
	length = 0;
}

void L::increase(int a)
{
	length += a;
}

void L::decrease(int a)
{
	length -= a;
}

int L::getLength()
{
	return length;
}

L L::operator+(L a)
{
	L b(length);
	b.increase(a.getLength());
	return b;
}
L L::operator-(L a)
{
	L b(length);
	b.decrease(a.getLength());
	return b;
}

////////////////
//////噪声值
////////////////
Noise::Noise(int a)//构造函数
	:Db(a)
{}

Noise::~Noise()//析构函数
{}

Noise::Noise()//默认构造函数
{
	Db = 0;
}

void Noise::increase(int a)
{
	Db += a;
}

void Noise::decrease(int a)
{
	Db -= a;
}

int Noise::getDb()
{
	return Db;
}

Noise Noise::operator+(Noise a)
{
	Noise b(Db);
	b.increase(a.getDb());
	return b;
}
Noise Noise::operator-(Noise a)
{
	Noise b(Db);
	b.decrease(a.getDb());
	return b;
}

Noise Noise::operator*(int a)
{
	Noise b(Db);
	b.multiplication(a);
	return b;
}

void Noise::multiplication(int a)
{
	Db=Db* a;
}