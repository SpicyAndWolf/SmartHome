#include"fileCreater.h"
#include"wall.h"

FileCreater::FileCreater()
{}

FileCreater::~FileCreater()
{}

void FileCreater::Create_file()
{
	//�����յ��ļ�
	{
		std::ofstream file_Aircondition("E:\\Aircondition.dat", std::ios::out | std::ios::binary);//��������յ���Ϣ�Ķ������ļ�
		if (!file_Aircondition)
		{
			MessageBox(NULL, _T("�����ļ�Aircondition.datʧ��"), _T("Tip:"), MB_OK);
		}
		//�յ�1
		const TCHAR* type_Aircondition = _T("�յ�");
		const TCHAR* air1_name = _T("����KFR-35GW/05EDS83");
		const TCHAR* air_material = _T("ABS����");
		const TCHAR* air1_feature = _T("�����������");
		Air_condition air1(type_Aircondition, air1_name, 1162, 865, 190, 300, air_material, 41, air1_feature, 100);//�յ�1
		air1.setBacteria_power(3);
		file_Aircondition.write(reinterpret_cast<const char*>(&air1), sizeof(Air_condition));
		//�յ�2
		const TCHAR* air2_name = _T("����KFR-35GW/10AFA81U1");
		const TCHAR* air2_feature = _T("˫�������·�");
		Air_condition air2(type_Aircondition, air2_name, 1000, 965, 205, 305, air_material, 41, air2_feature, 90);//�յ�2
		air2.setBacteria_power(1);
		file_Aircondition.write(reinterpret_cast<const char*>(&air2), sizeof(Air_condition));
		//�յ�3
		const TCHAR* air3_name = _T("����KFR-72LW/81@U1-Ub");
		const TCHAR* air3_feature = _T("3D������");
		Air_condition air3(type_Aircondition, air3_name, 2000, 416, 433, 1820, air_material, 47, air3_feature, 110);//�յ�3
		air3.setBacteria_power(0);
		file_Aircondition.write(reinterpret_cast<const char*>(&air3), sizeof(Air_condition));
		//�յ�4
		const TCHAR* air4_name = _T("����KFR-35GW/N8XHB1 ");
		const TCHAR* air4_feature = _T("ȫֱ����Ƶϵͳ");
		Air_condition air4(type_Aircondition, air4_name, 950, 880, 295, 195, air_material, 42, air4_feature, 105);//�յ�4
		air4.setBacteria_power(2);
		file_Aircondition.write(reinterpret_cast<const char*>(&air4), sizeof(Air_condition));

		file_Aircondition.close();//�ر��ļ�
		
	}//�յ��ļ��������

	//�����·��ļ�
	{
		std::ofstream file_AirFresh("E:\\AirFresh.dat", std::ios::out | std::ios::binary);//���������·���Ϣ�Ķ������ļ�
		if (!file_AirFresh)
		{
			MessageBox(NULL, _T("�����ļ�AirFresh.datʧ��"), _T("Tip:"), MB_OK);
		}
		//�·�1
		const TCHAR* type_AirFresh = _T("�·�ϵͳ");
		const TCHAR* AirFresh1_name = _T("С���·�ϵͳ�·��");
		const TCHAR* AirFresh_material = _T("PE��");
		const TCHAR* AirFresh1_feature = _T("�����ٿ�");
		Air_fresh airFresh1(type_AirFresh, AirFresh1_name, 42, 970, 365, 230, AirFresh_material, 39, AirFresh1_feature, 300);
		airFresh1.setBacteria_power(2);
		file_AirFresh.write(reinterpret_cast<const char*>(&airFresh1), sizeof(Air_fresh));
		//�·�2
		const TCHAR* AirFresh2_name = _T("����KJ400F-N860CU1 ");
		const TCHAR* AirFresh2_feature = _T("ֱ����ˢ���");
		Air_fresh airFresh2(type_AirFresh, AirFresh2_name, 42, 250, 250, 510, AirFresh_material, 37, AirFresh2_feature, 350);
		airFresh2.setBacteria_power(3);
		file_AirFresh.write(reinterpret_cast<const char*>(&airFresh2), sizeof(Air_fresh));
		//�·�3
		const TCHAR* AirFresh3_name = _T("����FHGKD-B3DA ");
		const TCHAR* AirFresh3_feature = _T("����");
		Air_fresh airFresh3(type_AirFresh, AirFresh3_name, 35, 390, 220, 930, AirFresh_material, 22, AirFresh3_feature, 300);
		airFresh3.setBacteria_power(2);
		file_AirFresh.write(reinterpret_cast<const char*>(&airFresh3), sizeof(Air_fresh));

		file_AirFresh.close();
	}//�·��ļ��������

	//������ʪ���ļ�
	{
		std::ofstream file_Humidifier("E:\\Humidifier.dat", std::ios::out | std::ios::binary);//���������ʪ����Ϣ�Ķ������ļ�
		if (!file_Humidifier)
		{
			MessageBox(NULL, _T("�����ļ�Humidity.datʧ��"), _T("Tip:"), MB_OK);
		}

		const TCHAR* type_Humidifier = _T("��ʪ��");
		const TCHAR* Humidifier1_name = _T("AirWater A3S");
		const TCHAR* Humidifier1_material = _T("PP����");
		const TCHAR* Humidifier1_feature = _T("���������ȫ�ݺ�ʪ����");
		Humidifier humidifier1(type_Humidifier, Humidifier1_name, 37, 250, 250, 603, Humidifier1_material, 18, Humidifier1_feature);
		humidifier1.setBacteria_power(4);
		humidifier1.setHumidity(4);
		file_Humidifier.write(reinterpret_cast<const char*>(&humidifier1), sizeof(Humidifier));

		const TCHAR* Humidifier2_name = _T("С��MJJSQ04DY");
		const TCHAR* Humidifier2_material = _T("ABS����");
		const TCHAR* Humidifier2_feature = _T("С������ϵͳ");
		Humidifier humidifier2(type_Humidifier, Humidifier2_name, 43, 190, 190, 324, Humidifier2_material, 32, Humidifier2_feature);
		humidifier2.setBacteria_power(2);
		humidifier2.setHumidity(3);
		file_Humidifier.write(reinterpret_cast<const char*>(&humidifier2), sizeof(Humidifier));

		const TCHAR* Humidifier3_name = _T("����3G40A");
		const TCHAR* Humidifier3_material = _T("PVC����");
		const TCHAR* Humidifier3_feature = _T("����");
		Humidifier humidifier3(type_Humidifier, Humidifier3_name, 45, 170, 170, 150, Humidifier3_material, 38, Humidifier3_feature);
		humidifier3.setBacteria_power(1);
		humidifier3.setHumidity(2);
		file_Humidifier.write(reinterpret_cast<const char*>(&humidifier3), sizeof(Humidifier));

		file_Humidifier.close();
	}//��ʪ���ļ��������

	//������ʪ���ļ�
	{
		std::ofstream file_Dehumidifier("E:\\Dehumidifier.dat", std::ios::out | std::ios::binary);//���������ʪ����Ϣ�Ķ������ļ�
		if (!file_Dehumidifier)
		{
			MessageBox(NULL, _T("�����ļ�Dehumidity.datʧ��"), _T("Tip:"), MB_OK);
		}

		const TCHAR* type_Dehumidifier = _T("��ʪ��");
		const TCHAR* Dehumidifier1_name = _T("��ҵDYD-D50A3 ");
		const TCHAR* Dehumidifier1_material = _T("PP����");
		const TCHAR* Dehumidifier1_feature = _T("���ٳ�ʪ");
		Dehumidifier dehumidifier1(type_Dehumidifier, Dehumidifier1_name, 860, 396, 341, 637, Dehumidifier1_material, 45, Dehumidifier1_feature);
		dehumidifier1.setBacteria_power(4);
		dehumidifier1.setHumidity(5);
		file_Dehumidifier.write(reinterpret_cast<const char*>(&dehumidifier1), sizeof(Dehumidifier));

		const TCHAR* Dehumidifier2_name = _T("����DH12EN");
		const TCHAR* Dehumidifier2_material = _T("PP����");
		const TCHAR* Dehumidifier2_feature = _T("����");
		Dehumidifier dehumidifier2(type_Dehumidifier, Dehumidifier2_name, 210, 350, 206, 400, Dehumidifier2_material,39, Dehumidifier2_feature);
		dehumidifier2.setBacteria_power(3);
		dehumidifier2.setHumidity(3);
		file_Dehumidifier.write(reinterpret_cast<const char*>(&dehumidifier2), sizeof(Dehumidifier));

		const TCHAR* Dehumidifier3_name = _T("������MJ-E140AF-C");
		const TCHAR* Dehumidifier3_material = _T("���Ͻ�");
		const TCHAR* Dehumidifier3_feature = _T("�����ʪ");
		Dehumidifier dehumidifier3(type_Dehumidifier, Dehumidifier3_name, 405, 372, 281, 594, Dehumidifier3_material, 39, Dehumidifier3_feature);
		dehumidifier3.setBacteria_power(3);
		dehumidifier3.setHumidity(4);
		file_Dehumidifier.write(reinterpret_cast<const char*>(&dehumidifier3), sizeof(Dehumidifier));

		file_Dehumidifier.close();
	}//��ʪ���ļ��������

	//������ů�ļ�
	{
		std::ofstream file_FloorHeat("E:\\FloorHeat.dat", std::ios::out | std::ios::binary);
		if (!file_FloorHeat)
		{
			MessageBox(NULL, _T("�����ļ�FloorHeat.datʧ��"), _T("Tip:"), MB_OK);

		}

		const TCHAR* type_floorHeat = _T("��ů");
		const TCHAR* floorHeat_name = _T("��ů");
		const TCHAR* floorHeat_material = _T("��ש");
		const TCHAR* floorHeat_Feature = _T("���ܲٿ�");
		FloorHeat floorheat(type_floorHeat, floorHeat_name, 150, 100, 100, 100, floorHeat_material, 0, floorHeat_Feature);
		floorheat.setHumidity(3);
		file_FloorHeat.write(reinterpret_cast<const char*>(&floorheat), sizeof(FloorHeat));

		file_FloorHeat.close();
	}//������ů�ļ��ɹ�

	//����ǽ���ļ�
	{
		std::ofstream file_Wall("E:\\Wall.dat", std::ios::out | std::ios::binary);
		if (!file_Wall)
		{
			MessageBox(NULL, _T("�����ļ�Wall.datʧ��"), _T("Tip:"), MB_OK);

		}

		//ǽ1
		const TCHAR* type_Wall = _T("ǽ");
		const TCHAR* Wall_name = _T("����ǽ");
		const TCHAR* Wall_material = _T("������");
		const TCHAR* Wall_Feature = _T("�������ܺ�");
		Wall wall1(1, type_Wall, Wall_name, 0, 0, 24, 300, Wall_material, 2, Wall_Feature);
		file_Wall.write(reinterpret_cast<const char*>(&wall1), sizeof(Wall));

		//ǽ2
		const TCHAR* type_Wall2 = _T("ǽ");
		const TCHAR* Wall2_name = _T("����ǽ");
		const TCHAR* Wall2_material = _T("ʯ���");
		const TCHAR* Wall2_Feature = _T("����Ч����");
		Wall wall2(2, type_Wall2, Wall2_name, 0, 0, 26, 310, Wall2_material, 0, Wall2_Feature);
		file_Wall.write(reinterpret_cast<const char*>(&wall2), sizeof(Wall));

		file_Wall.close();
	}
}

