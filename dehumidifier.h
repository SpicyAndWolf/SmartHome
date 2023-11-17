#pragma once
#ifndef DEHUMIDIFIER_H
#define DEHUMIDIFIER_H

#include"humidifier.h"

class Dehumidifier:public Humidifier
{
public:
	Dehumidifier();
	Dehumidifier(const TCHAR*, const TCHAR*, int,  int, int, int, const TCHAR*, int, const TCHAR*);
	~Dehumidifier();
	void F_run() override;
	void setGear(int) override;
};







#endif // DEHUMIDIFIER_H
