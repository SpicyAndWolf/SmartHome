#include"fileCreater.h"
#include"wall.h"

FileCreater::FileCreater()
{}

FileCreater::~FileCreater()
{}

void FileCreater::Create_file()
{
	//创建空调文件
	{
		std::ofstream file_Aircondition("E:\\Aircondition.dat", std::ios::out | std::ios::binary);//创建储存空调信息的二进制文件
		if (!file_Aircondition)
		{
			MessageBox(NULL, _T("创建文件Aircondition.dat失败"), _T("Tip:"), MB_OK);
		}
		//空调1
		const TCHAR* type_Aircondition = _T("空调");
		const TCHAR* air1_name = _T("海尔KFR-35GW/05EDS83");
		const TCHAR* air_material = _T("ABS塑料");
		const TCHAR* air1_feature = _T("蒸发器自清洁");
		Air_condition air1(type_Aircondition, air1_name, 1162, 865, 190, 300, air_material, 41, air1_feature, 100);//空调1
		air1.setBacteria_power(3);
		file_Aircondition.write(reinterpret_cast<const char*>(&air1), sizeof(Air_condition));
		//空调2
		const TCHAR* air2_name = _T("海尔KFR-35GW/10AFA81U1");
		const TCHAR* air2_feature = _T("双动力换新风");
		Air_condition air2(type_Aircondition, air2_name, 1000, 965, 205, 305, air_material, 41, air2_feature, 90);//空调2
		air2.setBacteria_power(1);
		file_Aircondition.write(reinterpret_cast<const char*>(&air2), sizeof(Air_condition));
		//空调3
		const TCHAR* air3_name = _T("海尔KFR-72LW/81@U1-Ub");
		const TCHAR* air3_feature = _T("3D除菌仓");
		Air_condition air3(type_Aircondition, air3_name, 2000, 416, 433, 1820, air_material, 47, air3_feature, 110);//空调3
		air3.setBacteria_power(0);
		file_Aircondition.write(reinterpret_cast<const char*>(&air3), sizeof(Air_condition));
		//空调4
		const TCHAR* air4_name = _T("美的KFR-35GW/N8XHB1 ");
		const TCHAR* air4_feature = _T("全直流变频系统");
		Air_condition air4(type_Aircondition, air4_name, 950, 880, 295, 195, air_material, 42, air4_feature, 105);//空调4
		air4.setBacteria_power(2);
		file_Aircondition.write(reinterpret_cast<const char*>(&air4), sizeof(Air_condition));

		file_Aircondition.close();//关闭文件
		
	}//空调文件创建完毕

	//创建新风文件
	{
		std::ofstream file_AirFresh("E:\\AirFresh.dat", std::ios::out | std::ios::binary);//创建储存新风信息的二进制文件
		if (!file_AirFresh)
		{
			MessageBox(NULL, _T("创建文件AirFresh.dat失败"), _T("Tip:"), MB_OK);
		}
		//新风1
		const TCHAR* type_AirFresh = _T("新风系统");
		const TCHAR* AirFresh1_name = _T("小米新风系统新风机");
		const TCHAR* AirFresh_material = _T("PE管");
		const TCHAR* AirFresh1_feature = _T("语音操控");
		Air_fresh airFresh1(type_AirFresh, AirFresh1_name, 42, 970, 365, 230, AirFresh_material, 39, AirFresh1_feature, 300);
		airFresh1.setBacteria_power(2);
		file_AirFresh.write(reinterpret_cast<const char*>(&airFresh1), sizeof(Air_fresh));
		//新风2
		const TCHAR* AirFresh2_name = _T("海尔KJ400F-N860CU1 ");
		const TCHAR* AirFresh2_feature = _T("直流无刷电机");
		Air_fresh airFresh2(type_AirFresh, AirFresh2_name, 42, 250, 250, 510, AirFresh_material, 37, AirFresh2_feature, 350);
		airFresh2.setBacteria_power(3);
		file_AirFresh.write(reinterpret_cast<const char*>(&airFresh2), sizeof(Air_fresh));
		//新风3
		const TCHAR* AirFresh3_name = _T("格力FHGKD-B3DA ");
		const TCHAR* AirFresh3_feature = _T("安静");
		Air_fresh airFresh3(type_AirFresh, AirFresh3_name, 35, 390, 220, 930, AirFresh_material, 22, AirFresh3_feature, 300);
		airFresh3.setBacteria_power(2);
		file_AirFresh.write(reinterpret_cast<const char*>(&airFresh3), sizeof(Air_fresh));

		file_AirFresh.close();
	}//新风文件创建完毕

	//创建加湿器文件
	{
		std::ofstream file_Humidifier("E:\\Humidifier.dat", std::ios::out | std::ios::binary);//创建储存加湿器信息的二进制文件
		if (!file_Humidifier)
		{
			MessageBox(NULL, _T("创建文件Humidity.dat失败"), _T("Tip:"), MB_OK);
		}

		const TCHAR* type_Humidifier = _T("加湿器");
		const TCHAR* Humidifier1_name = _T("AirWater A3S");
		const TCHAR* Humidifier1_material = _T("PP塑料");
		const TCHAR* Humidifier1_feature = _T("无雾除菌，全屋恒湿，贵");
		Humidifier humidifier1(type_Humidifier, Humidifier1_name, 37, 250, 250, 603, Humidifier1_material, 18, Humidifier1_feature);
		humidifier1.setBacteria_power(4);
		humidifier1.setHumidity(4);
		file_Humidifier.write(reinterpret_cast<const char*>(&humidifier1), sizeof(Humidifier));

		const TCHAR* Humidifier2_name = _T("小米MJJSQ04DY");
		const TCHAR* Humidifier2_material = _T("ABS塑料");
		const TCHAR* Humidifier2_feature = _T("小米物联系统");
		Humidifier humidifier2(type_Humidifier, Humidifier2_name, 43, 190, 190, 324, Humidifier2_material, 32, Humidifier2_feature);
		humidifier2.setBacteria_power(2);
		humidifier2.setHumidity(3);
		file_Humidifier.write(reinterpret_cast<const char*>(&humidifier2), sizeof(Humidifier));

		const TCHAR* Humidifier3_name = _T("美的3G40A");
		const TCHAR* Humidifier3_material = _T("PVC塑料");
		const TCHAR* Humidifier3_feature = _T("便宜");
		Humidifier humidifier3(type_Humidifier, Humidifier3_name, 45, 170, 170, 150, Humidifier3_material, 38, Humidifier3_feature);
		humidifier3.setBacteria_power(1);
		humidifier3.setHumidity(2);
		file_Humidifier.write(reinterpret_cast<const char*>(&humidifier3), sizeof(Humidifier));

		file_Humidifier.close();
	}//加湿器文件创建完毕

	//创建除湿器文件
	{
		std::ofstream file_Dehumidifier("E:\\Dehumidifier.dat", std::ios::out | std::ios::binary);//创建储存除湿器信息的二进制文件
		if (!file_Dehumidifier)
		{
			MessageBox(NULL, _T("创建文件Dehumidity.dat失败"), _T("Tip:"), MB_OK);
		}

		const TCHAR* type_Dehumidifier = _T("除湿器");
		const TCHAR* Dehumidifier1_name = _T("德业DYD-D50A3 ");
		const TCHAR* Dehumidifier1_material = _T("PP塑料");
		const TCHAR* Dehumidifier1_feature = _T("快速除湿");
		Dehumidifier dehumidifier1(type_Dehumidifier, Dehumidifier1_name, 860, 396, 341, 637, Dehumidifier1_material, 45, Dehumidifier1_feature);
		dehumidifier1.setBacteria_power(4);
		dehumidifier1.setHumidity(5);
		file_Dehumidifier.write(reinterpret_cast<const char*>(&dehumidifier1), sizeof(Dehumidifier));

		const TCHAR* Dehumidifier2_name = _T("格力DH12EN");
		const TCHAR* Dehumidifier2_material = _T("PP塑料");
		const TCHAR* Dehumidifier2_feature = _T("安静");
		Dehumidifier dehumidifier2(type_Dehumidifier, Dehumidifier2_name, 210, 350, 206, 400, Dehumidifier2_material,39, Dehumidifier2_feature);
		dehumidifier2.setBacteria_power(3);
		dehumidifier2.setHumidity(3);
		file_Dehumidifier.write(reinterpret_cast<const char*>(&dehumidifier2), sizeof(Dehumidifier));

		const TCHAR* Dehumidifier3_name = _T("三菱电机MJ-E140AF-C");
		const TCHAR* Dehumidifier3_material = _T("铝合金");
		const TCHAR* Dehumidifier3_feature = _T("地面除湿");
		Dehumidifier dehumidifier3(type_Dehumidifier, Dehumidifier3_name, 405, 372, 281, 594, Dehumidifier3_material, 39, Dehumidifier3_feature);
		dehumidifier3.setBacteria_power(3);
		dehumidifier3.setHumidity(4);
		file_Dehumidifier.write(reinterpret_cast<const char*>(&dehumidifier3), sizeof(Dehumidifier));

		file_Dehumidifier.close();
	}//除湿器文件创建完毕

	//创建地暖文件
	{
		std::ofstream file_FloorHeat("E:\\FloorHeat.dat", std::ios::out | std::ios::binary);
		if (!file_FloorHeat)
		{
			MessageBox(NULL, _T("创建文件FloorHeat.dat失败"), _T("Tip:"), MB_OK);

		}

		const TCHAR* type_floorHeat = _T("地暖");
		const TCHAR* floorHeat_name = _T("地暖");
		const TCHAR* floorHeat_material = _T("瓷砖");
		const TCHAR* floorHeat_Feature = _T("智能操控");
		FloorHeat floorheat(type_floorHeat, floorHeat_name, 150, 100, 100, 100, floorHeat_material, 0, floorHeat_Feature);
		floorheat.setHumidity(3);
		file_FloorHeat.write(reinterpret_cast<const char*>(&floorheat), sizeof(FloorHeat));

		file_FloorHeat.close();
	}//创建地暖文件成功

	//创建墙壁文件
	{
		std::ofstream file_Wall("E:\\Wall.dat", std::ios::out | std::ios::binary);
		if (!file_Wall)
		{
			MessageBox(NULL, _T("创建文件Wall.dat失败"), _T("Tip:"), MB_OK);

		}

		//墙1
		const TCHAR* type_Wall = _T("墙");
		const TCHAR* Wall_name = _T("保温墙");
		const TCHAR* Wall_material = _T("硅酸铝");
		const TCHAR* Wall_Feature = _T("保温性能好");
		Wall wall1(1, type_Wall, Wall_name, 0, 0, 24, 300, Wall_material, 2, Wall_Feature);
		file_Wall.write(reinterpret_cast<const char*>(&wall1), sizeof(Wall));

		//墙2
		const TCHAR* type_Wall2 = _T("墙");
		const TCHAR* Wall2_name = _T("隔音墙");
		const TCHAR* Wall2_material = _T("石膏板");
		const TCHAR* Wall2_Feature = _T("隔音效果好");
		Wall wall2(2, type_Wall2, Wall2_name, 0, 0, 26, 310, Wall2_material, 0, Wall2_Feature);
		file_Wall.write(reinterpret_cast<const char*>(&wall2), sizeof(Wall));

		file_Wall.close();
	}
}

