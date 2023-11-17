#include"unit.h"
////////////////
/////����
////////////////
P::P(int a)//���캯��
	:power(a)
{}

P::~P()//��������
{}

P::P()//Ĭ�Ϲ��캯��
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
//////����
////////////////
L::L(int a)//���캯��
	:length(a)
{}

L::~L()//��������
{}

L::L()//Ĭ�Ϲ��캯��
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
//////����ֵ
////////////////
Noise::Noise(int a)//���캯��
	:Db(a)
{}

Noise::~Noise()//��������
{}

Noise::Noise()//Ĭ�Ϲ��캯��
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