#pragma once
#ifndef FILECREATER_H
#define FILECREATER_H

#include<fstream>
#include"Airfresh.h"
#include"Aircondition.h"
#include"humidifier.h"
#include"floorHeat.h"
#include"dehumidifier.h"

class FileCreater
{
public:
	FileCreater();
	~FileCreater();
	void Create_file();

};

#endif