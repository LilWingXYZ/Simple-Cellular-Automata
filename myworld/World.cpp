#include"World.h"
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<ctime>
#include<math.h>
#include<string>
#include <windows.h>
#include <cstdlib>
#include<stdio.h>

using namespace std;
#define setcolor(c) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c)

#define DEAD 0
#define ALIVE 1

World::World() {
	//��ʼ��ȫ�ֱ���
	exitFlag = false;
	position_x[0] = -1;
	position_x[1] = -1;
	position_x[2] = -1;
	position_x[3] = 0;
	position_x[4] = 1;
	position_x[5] = 1;
	position_x[6] = 1;
	position_x[7] = 0;
	position_y[0] = -1;
	position_y[1] = 0;
	position_y[2] = 1;
	position_y[3] = 1;
	position_y[4] = 1;
	position_y[5] = 0;
	position_y[6] = -1;
	position_y[7] = -1;
	//Ϊ�������ó�ֵ
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			environment[i][j].setX(i);
			environment[i][j].setY(j);
			environment[i][j].setHumanAlive(false);
			environment[i][j].setAnimalAlive(false);
			environment[i][j].setPlantAlive(false);
			environment[i][j].setEnvironCondition(0.7);
			environment[i][j].setResource(0.7);
			environment[i][j].setEffectExtendOfDisaster(0);
		}
	}
	//�������һ������������
	humanNum = INITIAL_HUMAN_NUM;
	int randomX = -1;
	int randomY = -1;
	bool flag = true;
	int i = 0;
	while (i < humanNum) {
		flag = true;
		while (flag) {
			randomX = int(getRandomNum(0, M - 1, 1));
			randomY = int(getRandomNum(0, N - 1, 1));
			if (!environment[randomX][randomY].getHumanAlive()) {
				environment[randomX][randomY].setHumanAlive(true);
				if (i < 15) {
					environment[randomX][randomY].getHuman().setAge(i + 1);
					if (i % 5 == 0)
						environment[randomX][randomY].getHuman().setIfSick(true);
					else
						environment[randomX][randomY].getHuman().setIfSick(false);
					environment[randomX][randomY].getHuman().calIfPregant();
					environment[randomX][randomY].getHuman().setHealthCondition(0.000003*pow((i + 1), 3) - 0.0006*pow((i + 1), 2) + 0.0317*(i + 1) + 0.5421);
					environment[randomX][randomY].getHuman().calEnvironmentalAdaptation();
					environment[randomX][randomY].getHuman().setEffectExtendOfDisaster(1 - environment[randomX][randomY].getHuman().getEnvironmentalAdaptation());
				}
				else if (i < 115) {
					environment[randomX][randomY].getHuman().setAge((i + 1) / 2);
					if (i % 5 == 0)
						environment[randomX][randomY].getHuman().setIfSick(true);
					else
						environment[randomX][randomY].getHuman().setIfSick(false);
					environment[randomX][randomY].getHuman().calIfPregant();
					environment[randomX][randomY].getHuman().setHealthCondition(0.000003*pow(((i + 1) / 2), 3) - 0.0006*pow(((i + 1) / 2), 2) + 0.0317*((i + 1) / 2) + 0.5421);
					environment[randomX][randomY].getHuman().calEnvironmentalAdaptation();
					environment[randomX][randomY].getHuman().setEffectExtendOfDisaster(1 - environment[randomX][randomY].getHuman().getEnvironmentalAdaptation());
				}
				else {
					environment[randomX][randomY].getHuman().setAge(i - 49);
					if (i % 5 == 0)
						environment[randomX][randomY].getHuman().setIfSick(true);
					else
						environment[randomX][randomY].getHuman().setIfSick(false);
					environment[randomX][randomY].getHuman().calIfPregant();
					environment[randomX][randomY].getHuman().setHealthCondition(0.000003*pow((i - 49), 3) - 0.0006*pow((i - 49), 2) + 0.0317*(i - 49) + 0.5421);
					environment[randomX][randomY].getHuman().calEnvironmentalAdaptation();
					environment[randomX][randomY].getHuman().setEffectExtendOfDisaster(1 - environment[randomX][randomY].getHuman().getEnvironmentalAdaptation());
				}
				flag = false;
			}
		}
		i++;
	}

	//�������һ�������Ķ���
    animalNum = INITIAL_ANIMAL_NUM;
	int randomXX = -1;
	int randomYY = -1;
	bool fflag = true;
	int ii = 0;
	while (ii < animalNum) {
		fflag = true;
		while (fflag) {
			randomXX = int(getRandomNum(0, M - 1, 1));
			randomYY = int(getRandomNum(0, N - 1, 1));
			if (!environment[randomXX][randomYY].getAnimalAlive()) {
				environment[randomXX][randomYY].setAnimalAlive(true);
				if (ii < 15) {
					environment[randomXX][randomYY].getAnimal().setAge(ii + 1);
					if (ii % 5 == 0)
						environment[randomXX][randomYY].getAnimal().setIfSick(true);
					else
						environment[randomXX][randomYY].getAnimal().setIfSick(false);
					environment[randomXX][randomYY].getAnimal().calIfPregant();
					environment[randomXX][randomYY].getAnimal().setHealthCondition(0.000003*pow((ii + 1), 3) - 0.0006*pow((ii + 1), 2) + 0.0317*(ii + 1) + 0.5421);
					environment[randomXX][randomYY].getAnimal().calEnvironmentalAdaptation();
					environment[randomXX][randomYY].getAnimal().setEffectExtendOfDisaster(1 - environment[randomXX][randomYY].getAnimal().getEnvironmentalAdaptation());
				}
				else if (ii < 115) {
					environment[randomXX][randomYY].getAnimal().setAge((ii + 1) / 2);
					if (ii % 5 == 0)
						environment[randomXX][randomYY].getAnimal().setIfSick(true);
					else
						environment[randomXX][randomYY].getAnimal().setIfSick(false);
					environment[randomXX][randomYY].getAnimal().calIfPregant();
					environment[randomXX][randomYY].getAnimal().setHealthCondition(0.000003*pow(((ii + 1) / 2), 3) - 0.0006*pow(((ii + 1) / 2), 2) + 0.0317*((ii + 1) / 2) + 0.5421);
					environment[randomXX][randomYY].getAnimal().calEnvironmentalAdaptation();
					environment[randomXX][randomYY].getAnimal().setEffectExtendOfDisaster(1 - environment[randomXX][randomYY].getAnimal().getEnvironmentalAdaptation());
				}
				else {
					environment[randomXX][randomYY].getAnimal().setAge(ii - 49);
					if (ii % 5 == 0)
						environment[randomXX][randomYY].getAnimal().setIfSick(true);
					else
						environment[randomXX][randomYY].getAnimal().setIfSick(false);
					environment[randomXX][randomYY].getAnimal().calIfPregant();
					environment[randomXX][randomYY].getAnimal().setHealthCondition(0.000003*pow((ii - 49), 3) - 0.0006*pow((ii - 49), 2) + 0.0317*(ii - 49) + 0.5421);
					environment[randomXX][randomYY].getAnimal().calEnvironmentalAdaptation();
					environment[randomXX][randomYY].getAnimal().setEffectExtendOfDisaster(1 - environment[randomX][randomY].getAnimal().getEnvironmentalAdaptation());
				}
				fflag = false;
			}
		}
		ii++;
	}


	//�������һ��������ֲ��
    plantNum = INITIAL_PLANT_NUM;
	int randomXXX = -1;
	int randomYYY = -1;
	bool ffflag = true;
	int iii = 0;
	while (iii < plantNum) {
		ffflag = true;
		while (ffflag) {
			randomXXX = int(getRandomNum(0, M - 1, 1));
			randomYYY = int(getRandomNum(0, N - 1, 1));
			if (!environment[randomXXX][randomYYY].getPlantAlive()) {
				environment[randomXXX][randomYYY].setPlantAlive(true);
				if (iii < 15) {
					environment[randomXXX][randomYYY].getPlant().setAge(iii + 1);
					if (iii % 5 == 0)
						environment[randomXXX][randomYYY].getPlant().setIfSick(true);
					else
						environment[randomXXX][randomYYY].getPlant().setIfSick(false);
					environment[randomXXX][randomYYY].getPlant().calIfPregant();
					environment[randomXXX][randomYYY].getPlant().setHealthCondition(0.000003*pow((iii + 1), 3) - 0.0006*pow((iii + 1), 2) + 0.0317*(iii + 1) + 0.5421);
					environment[randomXXX][randomYYY].getPlant().calEnvironmentalAdaptation();
					environment[randomXXX][randomYYY].getPlant().setEffectExtendOfDisaster(1 - environment[randomXXX][randomYYY].getPlant().getEnvironmentalAdaptation());
				}
				else if (iii < 115) {
					environment[randomXXX][randomYYY].getPlant().setAge((iii + 1) / 2);
					if (iii % 5 == 0)
						environment[randomXXX][randomYYY].getPlant().setIfSick(true);
					else
						environment[randomXXX][randomYYY].getPlant().setIfSick(false);
					environment[randomXXX][randomYYY].getPlant().calIfPregant();
					environment[randomXXX][randomYYY].getPlant().setHealthCondition(0.000003*pow(((iii + 1) / 2), 3) - 0.0006*pow(((iii + 1) / 2), 2) + 0.0317*((iii + 1) / 2) + 0.5421);
					environment[randomXXX][randomYYY].getPlant().calEnvironmentalAdaptation();
					environment[randomXXX][randomYYY].getPlant().setEffectExtendOfDisaster(1 - environment[randomXXX][randomYYY].getPlant().getEnvironmentalAdaptation());
				}
				else {
					environment[randomXXX][randomYYY].getPlant().setAge(iii - 49);
					if (iii % 5 == 0)
						environment[randomXXX][randomYYY].getPlant().setIfSick(true);
					else
						environment[randomXXX][randomYYY].getPlant().setIfSick(false);
					environment[randomXXX][randomYYY].getPlant().calIfPregant();
					environment[randomXXX][randomYYY].getPlant().setHealthCondition(0.000003*pow((iii - 49), 3) - 0.0006*pow((iii - 49), 2) + 0.0317*(iii - 49) + 0.5421);
					environment[randomXXX][randomYYY].getPlant().calEnvironmentalAdaptation();
					environment[randomXXX][randomYYY].getPlant().setEffectExtendOfDisaster(1 - environment[randomX][randomY].getPlant().getEnvironmentalAdaptation());
				}
				ffflag = false;
			}
		}
		iii++;
	}


	//Ӱ���������ó�ֵ
	period = 1;
	resourceGrowthRate = 0.1;
	disasterLevel = 0.5;
	addFactor_HealthCondition = 0.5;
	addFactor_EnvironCondition = 0.5;
	addFactor_Resource = 0.5;
	moveFactor_HealthCondition = 0.5;
	moveFactor_Ability = 0.5;
	moveFactor_EnvironCondition = 0.5;
	moveFactor_Resource = 0.5;
	humanToEnvironmentFactor_Ability = 0.5;
	animalToEnvironmentFactor_Ability = 0.5;
	plantToEnvironmentFactor_Ability = 0.5;
	recoverFactor_percent = 0.5;
	disasterFactor = 0.5;
	disasterFactor_Level = 0.5;
	disasterFactor_EffectPercent = 0.5;
}

void World::startWorld() {
	//��ʼ
	int select;
	int day;
	int x,y;
   /* setcolor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    char s[420]={"  ���ܣ�����"};

      for(int k=0;k<8;k+=2)
      {
        cout<<s[k]<<s[k+1]<<flush;

        if(k%40==0)
        cout<<endl;

        Sleep(80);
      }
      cout<<endl;
      */

	showWorld();//��ʾ��ͼ
	//�˵�ѡ��
	while (!exitFlag) {
	    //cout <<endl<< "1. �����ݱ����    2. ��ѯ������Ϣ    3. ����" << endl;
	    cout <<endl<< "1. �����ݱ�    2. ������Ϣ    3. ��������    4. ��ȡ����    5. �˳�" << endl;
		cin >> select;
		switch (select) {
		case 1 :
			cout << "�ݱ�����(��): " ;
			cin >> day;
			if(day==0) showWorld();
            for (int i = 0; i < day; i += period) {
					changeWorld();
					system("cls");
					showWorld();
				}
            //showWorld();
            break;

        case 2:
            cout << "������Ҫ��ѯ�Ļ������꣬�磨0 0��" << endl;
            cin >> x >> y;
            showEnvironment(environment[x][y]);
            break;

        case 3:
		//case saveAction:
			save();
			break;
        case 4:
		//case readAction:
			read();
			break;
        case 5:
		//case exitAction:
			exitFlag = true;
			break;
		default:
			break;
		}
	}
}

int World::getRandomNum() {
	//��ȡ�����
	return rand();
}

double World::getRandomNum(int min, int max, double precision) {
	//��ȡ�����
	return (min + rand() % (max - min + 1)) * precision;
}

bool World::probabilityEvent(double probability) {
	//�жϸ����¼��Ƿ���
	if (probability >= 1)
		return true;
	else if (probability <= 0)
		return false;
	else {
		double r = getRandomNum(0, 100, 0.01);
		if (r < probability)
			return true;
		else
			return false;
	}
}

int World::randomProbabilityEvent(double probability[], int length) {
	//�ж��ĸ�����¼�����
	double sum = 0;
	for (int i = 0; i < length; i++)
		sum += probability[i];
	double num[M*N];
	num[0] = 0;
	for (int i = 1; i < length; i++)
		num[i] = num[i - 1] + probability[i - 1] / sum;
	double r = getRandomNum(0, 100, float(0.01));
	for (int i = 0; i < length - 1; i++)
		if (num[i] <= r && r < num[i + 1])
			return i + 1;
	return -1;
}

bool World::mapRangeCheck(int x, int y) {
	//��ͼ�߽���
	if (x < 0 || x > N)
		return false;
	if (y < 0 || y > M)
		return false;
	return true;
}

int World::input(int min, int max) {
	//���뺯�������ڱ�֤������ȷ
	bool flag = false;
	string str;
	char c;
	int i = -1;
	while (!flag) {
		cin >> str;
		if (str.length() == 1) {
			c = str[0];
			if (c >= '0' && c <= '9') {
				i = c - '0';
				if (i >= min && i <= max)
					flag = true;
				else
					cout << "�������,����������" << endl;
			}
			else
				cout << "�������,����������" << endl;
		}
		else
			cout << "�������,����������" << endl;
	}
	return i;
}

void World::changeWorld() {
	//statusSave();//״̬����
	humanCopy();
	humanNeiborhood();
	humanCopy();
    animalCopy();
	animalNeiborhood();
	animalCopy();
    plantCopy();
	plantNeiborhood();
	plantCopy();
	humanBreed();//���෱ֳ
	animalBreed();//���ﷱֳ
	//plantBreed();//ֲ�ﷱֳ
	humanChangeEnvironment();//����Ի�����Ӱ��
	animalChangeEnvironment();//����Ի�����Ӱ��
	plantChangeEnvironment();//ֲ��Ի�����Ӱ��
	/*
	humanChange();//����ı仯
	humanBreed();//���෱ֳ
	humanMove();//����Ǩ��
	humanChangeEnvironment();//����Ի�����Ӱ��
    animalChange();//����ı仯
	animalBreed();//���ﷱֳ
	animalMove();//����Ǩ��
	animalChangeEnvironment();//����Ի�����Ӱ��
    plantChange();//ֲ��ı仯
	plantBreed();//ֲ�ﷱֳ
	plantMove();//ֲ��Ǩ��
	plantChangeEnvironment();//ֲ��Ի�����Ӱ��
	*/
	environmentChange();//�����ı仯
	disaster();//��Ȼ�ֺ�����
	//statusRefresh();//״̬ˢ��
}

void World::statusSave() {
	//״̬����
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			environment_new[i][j] = environment[i][j];
}

void World::statusRefresh() {
	//״̬ˢ��
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			environment[i][j] = environment_new[i][j];
}

void World::deleteHuman(int x, int y) {
	//ɾ������
	environment_new[x][y].setHumanAlive(false);//�ڶ�Ӧ�ص���Ϊ��������
	humanNum--;//������������
}

void World::deleteAnimal(int x, int y) {
	//ɾ������
	environment_new[x][y].setAnimalAlive(false);//�ڶ�Ӧ�ص���Ϊ��������
	animalNum--;//������������
}

void World::deletePlant(int x, int y) {
	//ɾ��ֲ��
	environment_new[x][y].setPlantAlive(false);//�ڶ�Ӧ�ص���Ϊֲ������
	plantNum--;//ֲ����������
}

void World::addHuman(Human &hu, Environment &envir) {
	//�������
	envir.setHumanAlive(true);//�ڶ�Ӧ�ص���Ϊ������
	envir.setHuman(hu);//��������
	humanNum++;//������������
}

void World::addAnimal(Animal &ani, Environment &envir) {
	//��Ӷ���
	envir.setAnimalAlive(true);//�ڶ�Ӧ�ص���Ϊ������
	envir.setAnimal(ani);//���ö���
	animalNum++;//������������
}

void World::addPlant(Plant &pl, Environment &envir) {
	//���ֲ��
	envir.setPlantAlive(true);//�ڶ�Ӧ�ص���Ϊֲ����
	envir.setPlant(pl);//����ֲ��
	plantNum++;//ֲ����������
}

void World::addHuman(Human &hu, int x, int y) {
	//�������
	environment_new[x][y].setHumanAlive(true);//�ڶ�Ӧ�ص���Ϊ������
	//�������������
	environment_new[x][y].getHuman().setAge(hu.getAge());
	environment_new[x][y].getHuman().setHealthCondition(hu.getHealthCondition());
	environment_new[x][y].getHuman().setIfPregnant(hu.getIfPregnant());
	environment_new[x][y].getHuman().setEnvironmentalAdaptation(hu.getEnvironmentalAdaptation());
	environment_new[x][y].getHuman().setIfSick(hu.getIfSick());
	environment_new[x][y].getHuman().setEffectExtendOfDisaster(hu.getEffectExtendOfDisaster());
	environment_new[x][y].getHuman().calEnvironmentalAdaptation();
	environment_new[x][y].getHuman().calHeaCond();
	humanNum++;//������������
}

void World::addAnimal(Animal &ani, int x, int y) {
	//��Ӷ���
	environment_new[x][y].setAnimalAlive(true);//�ڶ�Ӧ�ص���Ϊ������
	//���ö��������
	environment_new[x][y].getAnimal().setAge(ani.getAge());
	environment_new[x][y].getAnimal().setHealthCondition(ani.getHealthCondition());
	environment_new[x][y].getAnimal().setIfPregnant(ani.getIfPregnant());
	environment_new[x][y].getAnimal().setEnvironmentalAdaptation(ani.getEnvironmentalAdaptation());
	environment_new[x][y].getAnimal().setIfSick(ani.getIfSick());
	environment_new[x][y].getAnimal().setEffectExtendOfDisaster(ani.getEffectExtendOfDisaster());
	environment_new[x][y].getAnimal().calEnvironmentalAdaptation();
	environment_new[x][y].getAnimal().calHeaCond();
	animalNum++;//������������
}

void World::addPlant(Plant &pl, int x, int y) {
	//���ֲ��
	environment_new[x][y].setPlantAlive(true);//�ڶ�Ӧ�ص���Ϊֲ����
	//����ֲ�������
	environment_new[x][y].getPlant().setAge(pl.getAge());
	environment_new[x][y].getPlant().setHealthCondition(pl.getHealthCondition());
	environment_new[x][y].getPlant().setIfPregnant(pl.getIfPregnant());
	environment_new[x][y].getPlant().setEnvironmentalAdaptation(pl.getEnvironmentalAdaptation());
	environment_new[x][y].getPlant().setIfSick(pl.getIfSick());
	environment_new[x][y].getPlant().setEffectExtendOfDisaster(pl.getEffectExtendOfDisaster());
	environment_new[x][y].getPlant().calEnvironmentalAdaptation();
	environment_new[x][y].getPlant().calHeaCond();
	plantNum++;//ֲ����������
}


void World::humanBreed() {
	//��ֳ
	int humanCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//�жϸõص��Ƿ��д�������
				continue;
			humanCount = 0;//��Χ8��
			positionSum = 0;
			positionX = -1;
			positionY = -1;
			if (!environment[i][j].getHuman().getIfPregnant())//�жϸ������Ƿ��ڷ�ֳ��
				continue;
			for (int k = 0; k < 8; k++) {//ͳ����Χ�˸��������������
				if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
					continue;
				if (!environment_new[i + position_x[k]][j + position_y[k]].getHumanAlive())
					humanCount++;
			}
			//�ж��Ƿ�ֳ������
			if (humanCount > addFactor_HealthCondition*environment[i][j].getHuman().getHealthCondition()) {//��
				for (int k = 0; k < 8; k++) {//����Χ�˸�������ѡ����õĵص㷱ֳ
					if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
						continue;
					if (environment_new[i + position_x[k]][j + position_y[k]].getHumanAlive())
						continue;
					if (positionSum < addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource()) {
						positionSum = addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource();
						positionX = i + position_x[k];
						positionY = j + position_y[k];
					}
				}
				if (positionX == -1)//ѡ��ʧ��
					continue;
				//��ֳ�ľ������
				Human *c = new Human();
				c->setAge(0);
				c->setIfSick(false);
				c->calIfPregant();
				c->setHealthCondition(0.5);
				c->calEnvironmentalAdaptation();
				c->setEffectExtendOfDisaster(1 - c->getEnvironmentalAdaptation());
				addHuman(*c, positionX, positionY);
				delete c;
			}
		}
	}
}

void World::animalBreed() {
	//���ﷱֳ
	int animalCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//�жϸõص��Ƿ��д�������
				continue;
			animalCount = 0;//��Χ8��
			positionSum = 0;
			positionX = -1;
			positionY = -1;
			if (!environment[i][j].getAnimal().getIfPregnant())//�жϸö����Ƿ��ڷ�ֳ��
				continue;
			for (int k = 0; k < 8; k++) {//ͳ����Χ�˸������������
				if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
					continue;
				if (!environment_new[i + position_x[k]][j + position_y[k]].getAnimalAlive())
					animalCount++;
			}
			//�ж��Ƿ�ֳ������
			if (animalCount > addFactor_HealthCondition*environment[i][j].getAnimal().getHealthCondition()) {//��
				for (int k = 0; k < 8; k++) {//����Χ�˸�������ѡ����õĵص㷱ֳ
					if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
						continue;
					if (environment_new[i + position_x[k]][j + position_y[k]].getAnimalAlive())
						continue;
					if (positionSum < addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource()) {
						positionSum = addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource();
						positionX = i + position_x[k];
						positionY = j + position_y[k];
					}
				}
				if (positionX == -1)//ѡ��ʧ��
					continue;
				//��ֳ�ľ������
				Animal *a = new Animal();
				a->setAge(0);
				a->setIfSick(false);
				a->calIfPregant();
				a->setHealthCondition(0.5);
				a->calEnvironmentalAdaptation();
				a->setEffectExtendOfDisaster(1 - a->getEnvironmentalAdaptation());
				addAnimal(*a, positionX, positionY);
				delete a;
			}
		}
	}
}


void World::plantBreed() {
	//ֲ�ﷱֳ
	int plantCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//�жϸõص��Ƿ��д�������
				continue;
			plantCount = 0;//��Χ8��
			positionSum = 0;
			positionX = -1;
			positionY = -1;
			if (!environment[i][j].getPlant().getIfPregnant())//�жϸö����Ƿ��ڷ�ֳ��
				continue;
			for (int k = 0; k < 8; k++) {//ͳ����Χ�˸������������
				if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
					continue;
				if (!environment_new[i + position_x[k]][j + position_y[k]].getPlantAlive())
					plantCount++;
			}
			//�ж��Ƿ�ֳ������
			if (plantCount > addFactor_HealthCondition*environment[i][j].getPlant().getHealthCondition()) {//��
				for (int k = 0; k < 8; k++) {//����Χ�˸�������ѡ����õĵص㷱ֳ
					if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
						continue;
					if (environment_new[i + position_x[k]][j + position_y[k]].getPlantAlive())
						continue;
					if (positionSum < addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource()) {
						positionSum = addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource();
						positionX = i + position_x[k];
						positionY = j + position_y[k];
					}
				}
				if (positionX == -1)//ѡ��ʧ��
					continue;
				//��ֳ�ľ������
				Plant *a = new Plant();
				a->setAge(0);
				a->setIfSick(false);
				a->calIfPregant();
				a->setHealthCondition(0.5);
				a->calEnvironmentalAdaptation();
				a->setEffectExtendOfDisaster(1 - a->getEnvironmentalAdaptation());
				addPlant(*a, positionX, positionY);
				delete a;
			}
		}
	}
}


void World::humanMove() {
	//Ǩ��
	int humanCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//�жϸõص��Ƿ��д�������
				continue;
			if (moveFactor_HealthCondition*environment[i][j].getHuman().getHealthCondition() + moveFactor_Ability*environment[i][j].getHuman().getEnvironmentalAdaptation() - moveFactor_EnvironCondition*environment[i][j].getEnvironCondition() - moveFactor_Resource*environment[i][j].getResource() > 0) {
				humanCount = 0;
				positionSum = 0;
				positionX = -1;
				positionY = -1;
				for (int k = 0; k < M; k++) {
					for (int l = 0; l < N; l++) {
						if (k == i && l == j)
							continue;
						if ((k - i)*(k - i) + (l - j)*(l - j) > 25)//��֤��һ����Χ��Ǩ��
							continue;
						if (environment_new[k][l].getHumanAlive())//�жϸõص��Ƿ��д�������
							continue;
						//��һ����Χ��ѡ����õĵص�Ǩ��
						if (positionSum < addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource()) {
							positionSum = addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource();
							positionX = k;
							positionY = l;
						}
					}
				}
				if (positionX == -1)//ѡ��ʧ��
					continue;
				//Ǩ�Ƶľ������
				addHuman(environment[i][j].getHuman(), positionX, positionY);
				deleteHuman(i, j);
			}
		}
	}
}


void World::animalMove() {
	//����Ǩ��
	int animalCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//�жϸõص��Ƿ��д��Ķ���
				continue;
			if (moveFactor_HealthCondition*environment[i][j].getAnimal().getHealthCondition() + moveFactor_Ability*environment[i][j].getAnimal().getEnvironmentalAdaptation() - moveFactor_EnvironCondition*environment[i][j].getEnvironCondition() - moveFactor_Resource*environment[i][j].getResource() > 0) {
				animalCount = 0;
				positionSum = 0;
				positionX = -1;
				positionY = -1;
				for (int k = 0; k < M; k++) {
					for (int l = 0; l < N; l++) {
						if (k == i && l == j)
							continue;
						if ((k - i)*(k - i) + (l - j)*(l - j) > 25)//��֤��һ����Χ��Ǩ��
							continue;
						if (environment_new[k][l].getAnimalAlive())//�жϸõص��Ƿ��д��Ķ���
							continue;
						//��һ����Χ��ѡ����õĵص�Ǩ��
						if (positionSum < addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource()) {
							positionSum = addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource();
							positionX = k;
							positionY = l;
						}
					}
				}
				if (positionX == -1)//ѡ��ʧ��
					continue;
				//Ǩ�Ƶľ������
				addAnimal(environment[i][j].getAnimal(), positionX, positionY);
				deleteAnimal(i, j);
			}
		}
	}
}

void World::plantMove() {
	//ֲ��Ǩ��
	int plantCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//�жϸõص��Ƿ��д��Ķ���
				continue;
			if (moveFactor_HealthCondition*environment[i][j].getPlant().getHealthCondition() + moveFactor_Ability*environment[i][j].getPlant().getEnvironmentalAdaptation() - moveFactor_EnvironCondition*environment[i][j].getEnvironCondition() - moveFactor_Resource*environment[i][j].getResource() > 0) {
				plantCount = 0;
				positionSum = 0;
				positionX = -1;
				positionY = -1;
				for (int k = 0; k < M; k++) {
					for (int l = 0; l < N; l++) {
						if (k == i && l == j)
							continue;
						if ((k - i)*(k - i) + (l - j)*(l - j) > 25)//��֤��һ����Χ��Ǩ��
							continue;
						if (environment_new[k][l].getPlantAlive())//�жϸõص��Ƿ��д��Ķ���
							continue;
						//��һ����Χ��ѡ����õĵص�Ǩ��
						if (positionSum < addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource()) {
							positionSum = addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource();
							positionX = k;
							positionY = l;
						}
					}
				}
				if (positionX == -1)//ѡ��ʧ��
					continue;
				//Ǩ�Ƶľ������
				addPlant(environment[i][j].getPlant(), positionX, positionY);
				deletePlant(i, j);
			}
		}
	}
}

void World::humanChangeEnvironment() {
	//�������Դ��Ӱ��
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//�жϸõص��Ƿ��д�������
				continue;
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + humanToEnvironmentFactor_Ability*environment[i][j].getHuman().getEnvironmentalAdaptation()));
		}
	}
}

void World::animalChangeEnvironment() {
	//�������Դ��Ӱ��
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//�жϸõص��Ƿ��д�������
				continue;
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + animalToEnvironmentFactor_Ability*environment[i][j].getAnimal().getEnvironmentalAdaptation()));
		}
	}
}

void World::plantChangeEnvironment() {
	//�������Դ��Ӱ��
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//�жϸõص��Ƿ��д�������
				continue;
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + plantToEnvironmentFactor_Ability*environment[i][j].getPlant().getEnvironmentalAdaptation()));
		}
	}
}

void World::humanChange() {
	//����ı仯
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//�жϸõص��Ƿ��д�������
				continue;
			//�����������Ӱ��

			//ÿ���ڼ������������
			environment_new[i][j].getHuman().setAge(environment_new[i][j].getHuman().getAge() + 1);
			environment_new[i][j].getHuman().calHeaCond();
			environment_new[i][j].getHuman().calEnvironmentalAdaptation();
			environment_new[i][j].getHuman().calIfPregant();
			//��������
			if (environment[i][j].getHuman().getHealthCondition() <= 0)
				deleteHuman(i, j);
		}
	}
}

void World::animalChange() {
	//����ı仯
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//�жϸõص��Ƿ��д�������
				continue;
			//�����������Ӱ��

			//ÿ���ڼ������������
			environment_new[i][j].getAnimal().setAge(environment_new[i][j].getAnimal().getAge() + 1);
			environment_new[i][j].getAnimal().calHeaCond();
			environment_new[i][j].getAnimal().calEnvironmentalAdaptation();
			environment_new[i][j].getAnimal().calIfPregant();
			//��������
			if (environment[i][j].getAnimal().getHealthCondition() <= 0)
				deleteAnimal(i, j);
		}
	}
}

void World::plantChange() {
	//ֲ��ı仯
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//�жϸõص��Ƿ��д���ֲ��
				continue;
			//������ֲ���Ӱ��

			//ÿ���ڼ���ֲ�������
			environment_new[i][j].getPlant().setAge(environment_new[i][j].getPlant().getAge() + 1);
			environment_new[i][j].getPlant().calHeaCond();
			environment_new[i][j].getPlant().calEnvironmentalAdaptation();
			environment_new[i][j].getPlant().calIfPregant();
			//ֲ������
			if (environment[i][j].getPlant().getHealthCondition() <= 0)
				deletePlant(i, j);
		}
	}
}

void World::environmentChange() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//�������һָ�
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + resourceGrowthRate));
			//�ֺ�ָ�
			if (environment[i][j].getEffectExtendOfDisaster() > 0)
				environment_new[i][j].setResource(environment[i][j].getResource() + recoverFactor_percent);
		}
	}
}

void World::disaster() {
	//������Ȼ�ֺ�
	int positionX = -1;
	int positionY = -1;
	double probability[M*N];
	int probability_x[M*N];
	int probability_y[M*N];
	int k = 0;
	//ɸѡ���������ĵص�
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (disasterFactor*environment[i][j].getEnvironCondition() < disasterFactor_Level) {
				probability[k] = disasterFactor*environment[i][j].getEnvironCondition();
				probability_x[k] = i;
				probability_y[k] = j;
				k++;
			}
		}
	}
	int p = randomProbabilityEvent(probability, k);//���������������ĵص������ѡ��һ��
	if (p == -1)//ѡ��ʧ��
		return;
	positionX = probability_x[p];
	positionY = probability_y[p];
	//������Ȼ�ֺ��Ӱ��
	environment_new[positionX][positionY].setEnvironCondition(environment[positionX][positionY].getEnvironCondition()*(1 - disasterFactor_EffectPercent));
	environment_new[positionX][positionY].setResource(environment[positionX][positionY].getResource()*(1 - disasterFactor_EffectPercent));
	//����
	if (environment[positionX][positionY].getHumanAlive()) {
		environment_new[positionX][positionY].getHuman().setHealthCondition(environment[positionX][positionY].getHuman().getHealthCondition() - 0.4);
		if (environment_new[positionX][positionY].getHuman().getHealthCondition() <= 0) {
			deleteHuman(positionX, positionY);
		}
		else {
			environment_new[positionX][positionY].getHuman().calEnvironmentalAdaptation();
			environment_new[positionX][positionY].getHuman().calHeaCond();
			if (environment_new[positionX][positionY].getHuman().getHealthCondition() <= 0) {
				deleteHuman(positionX, positionY);
			}
		}
	}
	//����
	if (environment[positionX][positionY].getAnimalAlive()) {
		environment_new[positionX][positionY].getAnimal().setHealthCondition(environment[positionX][positionY].getAnimal().getHealthCondition() - 0.4);
		if (environment_new[positionX][positionY].getAnimal().getHealthCondition() <= 0) {
			deleteAnimal(positionX, positionY);
		}
		else {
			environment_new[positionX][positionY].getAnimal().calEnvironmentalAdaptation();
			environment_new[positionX][positionY].getAnimal().calHeaCond();
			if (environment_new[positionX][positionY].getAnimal().getHealthCondition() <= 0) {
				deleteAnimal(positionX, positionY);
			}
		}
	}
		//ֲ��
	if (environment[positionX][positionY].getPlantAlive()) {
		environment_new[positionX][positionY].getPlant().setHealthCondition(environment[positionX][positionY].getPlant().getHealthCondition() - 0.4);
		if (environment_new[positionX][positionY].getPlant().getHealthCondition() <= 0) {
			deleteAnimal(positionX, positionY);
		}
		else {
			environment_new[positionX][positionY].getPlant().calEnvironmentalAdaptation();
			environment_new[positionX][positionY].getPlant().calHeaCond();
			if (environment_new[positionX][positionY].getPlant().getHealthCondition() <= 0) {
				deletePlant(positionX, positionY);
			}
		}
	}
}

void World::showHumanNum() {
	//��ʾ���������
	cout << "�����й���" << humanNum << "������" << endl;
}

void World::showAnimalNum() {
	//��ʾ���������
	cout << "�����й���" << animalNum << "ֻ����" << endl;
}

void World::showPlantNum() {
	//��ʾֲ�������
	cout << "�����й���" << plantNum << "��ֲ��" << endl;
}

void World::showEnvironment(Environment &envir) {
	//��ʾ������Ϣ
	cout << "��ǰ��ѯ����Ϊ(" << envir.getX() << "," << envir.getY() << ")��"<<"�˴�������״��Ϊ�� "<<endl;
	//cout << "��Դ��Ϊ" << envir.getResource() << "��";
	//cout << "����״��Ϊ" << envir.getEnvironCondition() << endl;
	//����
	if (!envir.getHumanAlive())
		cout << "û������" << endl;
	else {
		cout << "��һ������" << endl;
	/*
		cout << "����Ϊ" << envir.getHuman().getAge() << "��";
		cout << "����״��Ϊ" << envir.getHuman().getHealthCondition() << "��";
		if (envir.getHuman().getIfPregnant())
			cout << "���ڷ�ֳ��" << "��";
		else
			cout << "���ڷ�ֳ��" << "��";
		if (envir.getHuman().getIfSick())
			cout << "�ѻ���" << "��";
		else
			cout << "δ����" << "��";
		cout << "����Ϊ" << envir.getHuman().getEnvironmentalAdaptation() << endl;
		*/
	}


    //����
		if (!envir.getAnimalAlive())
		cout << "û�ж���" << endl;
	else {
		cout << "��һֻ����" << endl;
		/*
		cout << "����Ϊ" << envir.getAnimal().getAge() << "��";
		cout << "����״��Ϊ" << envir.getAnimal().getHealthCondition() << "��";
		if (envir.getAnimal().getIfPregnant())
			cout << "���ڷ�ֳ��" << "��";
		else
			cout << "���ڷ�ֳ��" << "��";
		if (envir.getAnimal().getIfSick())
			cout << "�ѻ���" << "��";
		else
			cout << "δ����" << "��";
		cout << "����Ϊ" << envir.getAnimal().getEnvironmentalAdaptation() << endl;
		*/
	}

	    //ֲ��
		if (!envir.getPlantAlive())
		cout << "û��ֲ��" << endl;
	else {
		cout << "��һ��ֲ��" << endl;
		/*
		cout << "����Ϊ" << envir.getPlant().getAge() << "��";
		cout << "����״��Ϊ" << envir.getPlant().getHealthCondition() << "��";
		if (envir.getPlant().getIfPregnant())
			cout << "���ڷ�ֳ��" << "��";
		else
			cout << "���ڷ�ֳ��" << "��";
		if (envir.getPlant().getIfSick())
			cout << "�ѻ���" << "��";
		else
			cout << "δ����" << "��";
		cout << "����Ϊ" << envir.getPlant().getEnvironmentalAdaptation() << endl;
		*/
	}
}

   void gotoxy(const int y,const int x)
 {
   COORD point;
   point.X=2*x;
   point.Y=y;  //���α�
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
 }


void World::showWorld() {

	//��ʾ��ͼ

	for (int i = 0; i < M; i++) {
		cout << " ";
		for (int j = 0; j < N; j++) {
            if (environment[i][j].getHumanAlive() && environment[i][j].getAnimalAlive() && environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                gotoxy(i,j);
                cout << "& ";}
            else if (!environment[i][j].getHumanAlive() && environment[i][j].getAnimalAlive() && environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                gotoxy(i,j);
                cout << "@ ";}
            else if (environment[i][j].getHumanAlive() && !environment[i][j].getAnimalAlive() && environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                gotoxy(i,j);
                cout << "# ";}
            else if (environment[i][j].getHumanAlive() && environment[i][j].getAnimalAlive() && !environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                gotoxy(i,j);
                cout << "$ ";}
			else if (environment[i][j].getHumanAlive() && !environment[i][j].getAnimalAlive() &&!environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                gotoxy(i,j);
				cout << "O ";}
            else if (!environment[i][j].getHumanAlive() && environment[i][j].getAnimalAlive() &&!environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_RED | FOREGROUND_INTENSITY);
                gotoxy(i,j);
                cout << "X ";}
            else if (!environment[i][j].getHumanAlive() && !environment[i][j].getAnimalAlive() &&environment[i][j].getPlantAlive())
                {setcolor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                gotoxy(i,j);
                cout << "I ";}

            else
       {
            gotoxy(i,j);
            cout<<" ";
       }

			//else
				//cout << " ";
		}
		cout << endl;
	}
	setcolor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout <<endl<<"*******************************��ӭ�����ҵ�����!********************************"<<endl;
    cout <<"O-�������࣬X���������I-����ֲ�$-���붯��,"<<endl<<
           "#-����ֲ�@-������ֲ�&-���У��հ�-�ĵ�"<<endl<<endl;
	//cout <<endl<< "��ǰ���������"<<endl;
    //cout<<"�����"<<N<<"*"<<M<<"ƽ����  "<<"���ࣺ"<< humanNum << "�� " <<"���"<< animalNum << "ֻ "<<"ֲ�"<< plantNum << "��" <<endl;
}

bool World::save() {
	//���ļ�
	ofstream saveFile;
	try {
		saveFile.open("data.txt");
		if (!saveFile)
			throw "error";
	}
	catch (char *) {
		cout << "�޷������ļ�" << endl;
	}
	//����ȫ�ֱ���
	saveFile << humanNum << " ";
	saveFile << animalNum << " ";
	saveFile << plantNum << " ";
	saveFile << period << " ";
	saveFile << resourceGrowthRate << " ";
	saveFile << disasterLevel << " ";
	saveFile << addFactor_HealthCondition << " ";
	saveFile << addFactor_EnvironCondition << " ";
	saveFile << addFactor_Resource << " ";
	saveFile << moveFactor_HealthCondition << " ";
	saveFile << moveFactor_Ability << " ";
	saveFile << moveFactor_EnvironCondition << " ";
	saveFile << moveFactor_Resource << " ";
	saveFile << humanToEnvironmentFactor_Ability << " ";
	saveFile << animalToEnvironmentFactor_Ability << " ";
	saveFile << plantToEnvironmentFactor_Ability << " ";
	saveFile << recoverFactor_percent << " ";
	saveFile << disasterFactor << " ";
	saveFile << disasterFactor_Level << " ";
	saveFile << disasterFactor_EffectPercent << " ";
	//���滷������
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			saveFile << environment[i][j].getX() << " ";
			saveFile << environment[i][j].getY() << " ";
			saveFile << environment[i][j].getResource() << " ";
			saveFile << environment[i][j].getEnvironCondition() << " ";
			saveFile << environment[i][j].getEffectExtendOfDisaster() << " ";

			if (environment[i][j].getHumanAlive() || environment[i][j].getAnimalAlive() || environment[i][j].getPlantAlive())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			//������������
			saveFile << environment[i][j].getHuman().getAge() << " ";
			saveFile << environment[i][j].getHuman().getHealthCondition() << " ";
			if (environment[i][j].getHuman().getIfPregnant())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			saveFile << environment[i][j].getHuman().getEnvironmentalAdaptation() << " ";
			if (environment[i][j].getHuman().getIfSick())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			saveFile << environment[i][j].getHuman().getEffectExtendOfDisaster() << " ";

                //���涯������
			saveFile << environment[i][j].getAnimal().getAge() << " ";
			saveFile << environment[i][j].getAnimal().getHealthCondition() << " ";
			if (environment[i][j].getAnimal().getIfPregnant())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			saveFile << environment[i][j].getAnimal().getEnvironmentalAdaptation() << " ";
			if (environment[i][j].getAnimal().getIfSick())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			saveFile << environment[i][j].getAnimal().getEffectExtendOfDisaster() << " ";

                //����ֲ������
			saveFile << environment[i][j].getPlant().getAge() << " ";
			saveFile << environment[i][j].getPlant().getHealthCondition() << " ";
			if (environment[i][j].getPlant().getIfPregnant())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			saveFile << environment[i][j].getPlant().getEnvironmentalAdaptation() << " ";
			if (environment[i][j].getPlant().getIfSick())
				saveFile << "1 ";
			else
				saveFile << "0 ";
			saveFile << environment[i][j].getPlant().getEffectExtendOfDisaster() << " ";
		}
	}
	//�������
	cout << "����ɹ�" << endl;
	saveFile.close();
	return true;
}

bool World::read() {
	//���ļ�
	ifstream readFile;
	try {
		readFile.open("data.txt");
		if (!readFile)
			throw "error";
	}
	catch (char *) {
		cout << "�޷���ȡ�ļ�" << endl;
	}
	//��ȡȫ�ֱ���
	readFile >> humanNum;
	readFile >> animalNum;
	readFile >> plantNum;
	readFile >> period;
	readFile >> resourceGrowthRate;
	readFile >> disasterLevel;
	readFile >> addFactor_HealthCondition;
	readFile >> addFactor_EnvironCondition;
	readFile >> addFactor_Resource;
	readFile >> moveFactor_HealthCondition;
	readFile >> moveFactor_Ability;
	readFile >> moveFactor_EnvironCondition;
	readFile >> moveFactor_Resource;
	readFile >> humanToEnvironmentFactor_Ability;
	readFile >> animalToEnvironmentFactor_Ability;
	readFile >> plantToEnvironmentFactor_Ability;
	readFile >> recoverFactor_percent;
	readFile >> disasterFactor;
	readFile >> disasterFactor_Level;
	readFile >> disasterFactor_EffectPercent;
	//������Ҫ��ȡ�ı���
	int readX;
	int readY;
	double readResource;
	double readEnvironCondition;
	double readEnvEffectExtendOfDisaster;
	int readHumanAlive;
	int readAnimalAlive;
	int readPlantAlive;
	int readAge;
	double readHealthCondition;
	int readIfPregnant;
	int readIfSick;
	double readEnvironmentalAdaptation;
	double readCreEffectExtendOfDisaster;
	//��ȡ��������
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			readFile >> readX;
			readFile >> readY;
			readFile >> readResource;
			readFile >> readEnvironCondition;
			readFile >> readEnvEffectExtendOfDisaster;
			readFile >> readHumanAlive;
			readFile >> readAnimalAlive;
			readFile >> readPlantAlive;
			environment[i][j].setX(readX);
			environment[i][j].setY(readY);
			environment[i][j].setResource(readResource);
			environment[i][j].setEnvironCondition(readEnvironCondition);
			environment[i][j].setEffectExtendOfDisaster(readEnvEffectExtendOfDisaster);
			//����
			if (readHumanAlive == 1)
				environment[i][j].setHumanAlive(true);
			else
				environment[i][j].setHumanAlive(false);
            //����
            if (readAnimalAlive == 1)
				environment[i][j].setAnimalAlive(true);
			else
				environment[i][j].setAnimalAlive(false);
            //ֲ��
            if (readPlantAlive == 1)
				environment[i][j].setPlantAlive(true);
			else
				environment[i][j].setPlantAlive(false);
			//��ȡ��������
			readFile >> readAge;
			readFile >> readHealthCondition;
			readFile >> readIfPregnant;
			readFile >> readEnvironmentalAdaptation;
			readFile >> readIfSick;
			readFile >> readCreEffectExtendOfDisaster;

			//����
			if (!environment[i][j].getHumanAlive())
				continue;
			environment[i][j].getHuman().setAge(readAge);
			environment[i][j].getHuman().setHealthCondition(readHealthCondition);
			if (readIfPregnant == 1)
				environment[i][j].getHuman().setIfPregnant(true);
			else
				environment[i][j].getHuman().setIfPregnant(false);
			environment[i][j].getHuman().setEnvironmentalAdaptation(readEnvironmentalAdaptation);
			if (readIfSick == 1)
				environment[i][j].getHuman().setIfSick(true);
			else
				environment[i][j].getHuman().setIfSick(false);
			environment[i][j].getHuman().setEffectExtendOfDisaster(readCreEffectExtendOfDisaster);

			//����
			if (!environment[i][j].getAnimalAlive())
				continue;
			environment[i][j].getAnimal().setAge(readAge);
			environment[i][j].getAnimal().setHealthCondition(readHealthCondition);
			if (readIfPregnant == 1)
				environment[i][j].getAnimal().setIfPregnant(true);
			else
				environment[i][j].getAnimal().setIfPregnant(false);
			environment[i][j].getAnimal().setEnvironmentalAdaptation(readEnvironmentalAdaptation);
			if (readIfSick == 1)
				environment[i][j].getAnimal().setIfSick(true);
			else
				environment[i][j].getAnimal().setIfSick(false);
			environment[i][j].getAnimal().setEffectExtendOfDisaster(readCreEffectExtendOfDisaster);

            //ֲ��
			if (!environment[i][j].getPlantAlive())
				continue;
			environment[i][j].getPlant().setAge(readAge);
			environment[i][j].getPlant().setHealthCondition(readHealthCondition);
			if (readIfPregnant == 1)
				environment[i][j].getPlant().setIfPregnant(true);
			else
				environment[i][j].getPlant().setIfPregnant(false);
			environment[i][j].getPlant().setEnvironmentalAdaptation(readEnvironmentalAdaptation);
			if (readIfSick == 1)
				environment[i][j].getPlant().setIfSick(true);
			else
				environment[i][j].getPlant().setIfSick(false);
			environment[i][j].getPlant().setEffectExtendOfDisaster(readCreEffectExtendOfDisaster);
		}
	}
	//�������
	cout << "��ȡ�ɹ�" << endl;
	readFile.close();
	return true;
}

//����仯
void World::humanNeiborhood()
{
 int i,j;
 int num=0;
 for(i=0;i<M;i++)
	 for(j=0;j<M;j++)
	 {

			 if(i==0&&j==0)
			 {num=environment_new[0][1].getHumanAlive()+environment_new[1][0].getHumanAlive()+environment_new[1][1].getHumanAlive();humanCases(i,j,num);}
			 if(i==0&&j==M-1)
			 {num=environment_new[0][M-2].getHumanAlive()+environment_new[1][M-1].getHumanAlive()+environment_new[1][M-2].getHumanAlive();humanCases(i,j,num);}
			 if(i==M-1&&j==0)
			 {num=environment_new[M-1][1].getHumanAlive()+environment_new[M-2][0].getHumanAlive()+environment_new[M-2][1].getHumanAlive();humanCases(i,j,num);}
			 if(i==M-1&&j==M-1)
			 {num=environment_new[M-1][M-2].getHumanAlive()+environment_new[M-2][M-1].getHumanAlive()+environment_new[M-2][M-2].getHumanAlive();humanCases

(i,j,num);}


			 if(i==0&&j!=0&&j!=M-1)
			 {num=environment_new[0][j-1].getHumanAlive()+environment_new[0][j+1].getHumanAlive()+environment_new[1][j-1].getHumanAlive()+environment_new[1][j].getHumanAlive()+environment_new[1][j

+1].getHumanAlive();humanCases(i,j,num);}
			 if(i==M-1&&j!=0&&j!=M-1)
			 {num=environment_new[M-1][j-1].getHumanAlive()+environment_new[M-1][j+1].getHumanAlive()+environment_new[M-2][j-1].getHumanAlive()+environment_new[M-2][j].getHumanAlive()+environment_new

[M-2][j+1].getHumanAlive();humanCases(i,j,num);}
			 if(i!=0&&j==0&&i!=M-1)
             {num=environment_new[i+1][0].getHumanAlive()+environment_new[i-1][0].getHumanAlive()+environment_new[i+1][1].getHumanAlive()+environment_new[i][1].getHumanAlive()+environment_new[i-1][1].getHumanAlive();humanCases

(i,j,num);}
			 if(i!=0&&j==M-1&&i!=M-1)
             {num=environment_new[i+1][M-1].getHumanAlive()+environment_new[i-1][M-1].getHumanAlive()+environment_new[i+1][M-2].getHumanAlive()+environment_new[i][M-2].getHumanAlive()+environment_new[i-1][M-

2].getHumanAlive();humanCases(i,j,num);}

		     if(i!=0&&j!=0&&i!=M-1&&j!=M-1)
             {num=environment_new[i][j-1].getHumanAlive()+environment_new[i][j+1].getHumanAlive()+environment_new[i+1][j].getHumanAlive()+environment_new[i+1][j-1].getHumanAlive()+environment_new[i+1][j+1].getHumanAlive()+environment_new[i-1]

[j-1].getHumanAlive()+environment_new[i-1][j].getHumanAlive()+environment_new[i-1][j+1].getHumanAlive();humanCases(i,j,num);}

	 }
}

void World::humanCases(int i,int j,int m)
{
	switch(m)
	{
	case 0: environment[i][j].setHumanAlive(false);break;
	case 1: break;
	case 2: break;
	case 3: environment[i][j].setHumanAlive(true);break;
    case 4: environment[i][j].setHumanAlive(false);break;
 	case 5: environment[i][j].setHumanAlive(false);break;
	case 6: environment[i][j].setHumanAlive(false);break;
	case 7: environment[i][j].setHumanAlive(false);break;
	case 8: environment[i][j].setHumanAlive(false);break;
	}
}

void World::humanCopy()
{
	int i,j;
	for(i=0;i<M;i++)
	 for(j=0;j<M;j++)
	 {
	     if(environment[i][j].getHumanAlive())
            environment_new[i][j].setHumanAlive(true);
		 else
            environment_new[i][j].setHumanAlive(false);

	 }
}

//����仯
void World::animalNeiborhood()
{
 int i,j;
 int num=0;
 for(i=0;i<M;i++)
	 for(j=0;j<M;j++)
	 {

			 if(i==0&&j==0)
			 {num=environment_new[0][1].getAnimalAlive()+environment_new[1][0].getAnimalAlive()+environment_new[1][1].getAnimalAlive();animalCases(i,j,num);}
			 if(i==0&&j==M-1)
			 {num=environment_new[0][M-2].getAnimalAlive()+environment_new[1][M-1].getAnimalAlive()+environment_new[1][M-2].getAnimalAlive();animalCases(i,j,num);}
			 if(i==M-1&&j==0)
			 {num=environment_new[M-1][1].getAnimalAlive()+environment_new[M-2][0].getAnimalAlive()+environment_new[M-2][1].getAnimalAlive();animalCases(i,j,num);}
			 if(i==M-1&&j==M-1)
			 {num=environment_new[M-1][M-2].getAnimalAlive()+environment_new[M-2][M-1].getAnimalAlive()+environment_new[M-2][M-2].getAnimalAlive();animalCases

(i,j,num);}


			 if(i==0&&j!=0&&j!=M-1)
			 {num=environment_new[0][j-1].getAnimalAlive()+environment_new[0][j+1].getAnimalAlive()+environment_new[1][j-1].getAnimalAlive()+environment_new[1][j].getAnimalAlive()+environment_new[1][j

+1].getAnimalAlive();animalCases(i,j,num);}
			 if(i==M-1&&j!=0&&j!=M-1)
			 {num=environment_new[M-1][j-1].getAnimalAlive()+environment_new[M-1][j+1].getAnimalAlive()+environment_new[M-2][j-1].getAnimalAlive()+environment_new[M-2][j].getAnimalAlive()+environment_new

[M-2][j+1].getAnimalAlive();animalCases(i,j,num);}
			 if(i!=0&&j==0&&i!=M-1)
             {num=environment_new[i+1][0].getAnimalAlive()+environment_new[i-1][0].getAnimalAlive()+environment_new[i+1][1].getAnimalAlive()+environment_new[i][1].getAnimalAlive()+environment_new[i-1][1].getAnimalAlive();animalCases

(i,j,num);}
			 if(i!=0&&j==M-1&&i!=M-1)
             {num=environment_new[i+1][M-1].getAnimalAlive()+environment_new[i-1][M-1].getAnimalAlive()+environment_new[i+1][M-2].getAnimalAlive()+environment_new[i][M-2].getAnimalAlive()+environment_new[i-1][M-

2].getAnimalAlive();animalCases(i,j,num);}

		     if(i!=0&&j!=0&&i!=M-1&&j!=M-1)
             {num=environment_new[i][j-1].getAnimalAlive()+environment_new[i][j+1].getAnimalAlive()+environment_new[i+1][j].getAnimalAlive()+environment_new[i+1][j-1].getAnimalAlive()+environment_new[i+1][j+1].getAnimalAlive()+environment_new[i-1]

[j-1].getAnimalAlive()+environment_new[i-1][j].getAnimalAlive()+environment_new[i-1][j+1].getAnimalAlive();animalCases(i,j,num);}

	 }
}

void World::animalCases(int i,int j,int m)
{
	switch(m)
	{
	case 0: environment[i][j].setAnimalAlive(false);break;
	case 1: environment[i][j].setAnimalAlive(false);break;
	case 2: environment[i][j].setAnimalAlive(false);break;
	case 3: environment[i][j].setAnimalAlive(true);break;
    case 4: break;
 	case 5: environment[i][j].setAnimalAlive(true);break;
	case 6: environment[i][j].setAnimalAlive(false);break;
	case 7: environment[i][j].setAnimalAlive(false);break;
	case 8: environment[i][j].setAnimalAlive(false);break;
	}
}

void World::animalCopy()
{
	int i,j;
	for(i=0;i<M;i++)
	 for(j=0;j<M;j++)
	 {
	     if(environment[i][j].getAnimalAlive())
            environment_new[i][j].setAnimalAlive(true);
		 else
            environment_new[i][j].setAnimalAlive(false);

	 }
}


//ֲ��仯
void World::plantNeiborhood()
{
 int i,j;
 int num=0;
 for(i=0;i<M;i++)
	 for(j=0;j<M;j++)
	 {

			 if(i==0&&j==0)
			 {num=environment_new[0][1].getPlantAlive()+environment_new[1][0].getPlantAlive()+environment_new[1][1].getPlantAlive();plantCases(i,j,num);}
			 if(i==0&&j==M-1)
			 {num=environment_new[0][M-2].getPlantAlive()+environment_new[1][M-1].getPlantAlive()+environment_new[1][M-2].getPlantAlive();plantCases(i,j,num);}
			 if(i==M-1&&j==0)
			 {num=environment_new[M-1][1].getPlantAlive()+environment_new[M-2][0].getPlantAlive()+environment_new[M-2][1].getPlantAlive();plantCases(i,j,num);}
			 if(i==M-1&&j==M-1)
			 {num=environment_new[M-1][M-2].getPlantAlive()+environment_new[M-2][M-1].getPlantAlive()+environment_new[M-2][M-2].getPlantAlive();plantCases

(i,j,num);}


			 if(i==0&&j!=0&&j!=M-1)
			 {num=environment_new[0][j-1].getPlantAlive()+environment_new[0][j+1].getPlantAlive()+environment_new[1][j-1].getPlantAlive()+environment_new[1][j].getPlantAlive()+environment_new[1][j

+1].getPlantAlive();plantCases(i,j,num);}
			 if(i==M-1&&j!=0&&j!=M-1)
			 {num=environment_new[M-1][j-1].getPlantAlive()+environment_new[M-1][j+1].getPlantAlive()+environment_new[M-2][j-1].getPlantAlive()+environment_new[M-2][j].getPlantAlive()+environment_new

[M-2][j+1].getPlantAlive();plantCases(i,j,num);}
			 if(i!=0&&j==0&&i!=M-1)
             {num=environment_new[i+1][0].getPlantAlive()+environment_new[i-1][0].getPlantAlive()+environment_new[i+1][1].getPlantAlive()+environment_new[i][1].getPlantAlive()+environment_new[i-1][1].getPlantAlive();plantCases

(i,j,num);}
			 if(i!=0&&j==M-1&&i!=M-1)
             {num=environment_new[i+1][M-1].getPlantAlive()+environment_new[i-1][M-1].getPlantAlive()+environment_new[i+1][M-2].getPlantAlive()+environment_new[i][M-2].getPlantAlive()+environment_new[i-1][M-

2].getPlantAlive();plantCases(i,j,num);}

		     if(i!=0&&j!=0&&i!=M-1&&j!=M-1)
             {num=environment_new[i][j-1].getPlantAlive()+environment_new[i][j+1].getPlantAlive()+environment_new[i+1][j].getPlantAlive()+environment_new[i+1][j-1].getPlantAlive()+environment_new[i+1][j+1].getPlantAlive()+environment_new[i-1]

[j-1].getPlantAlive()+environment_new[i-1][j].getPlantAlive()+environment_new[i-1][j+1].getPlantAlive();plantCases(i,j,num);}

	 }
}

void World::plantCases(int i,int j,int m)
{
	switch(m)
	{
	case 0: environment[i][j].setPlantAlive(false);break;
	case 1: environment[i][j].setPlantAlive(false);break;
	case 2: environment[i][j].setPlantAlive(true);break;
	case 3:           break;
    case 4: environment[i][j].setPlantAlive(false);break;
 	case 5: environment[i][j].setPlantAlive(false);break;
	case 6: environment[i][j].setPlantAlive(false);break;
	case 7: environment[i][j].setPlantAlive(false);break;
	case 8: environment[i][j].setPlantAlive(false);break;
	}
}

void World::plantCopy()
{
	int i,j;
	for(i=0;i<M;i++)
	 for(j=0;j<M;j++)
	 {
	     if(environment[i][j].getPlantAlive())
            environment_new[i][j].setPlantAlive(true);
		 else
            environment_new[i][j].setPlantAlive(false);

	 }
}


void World::humanSelectBreed(int i, int j){
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;

				for (int k = 0; k < 8; k++) {//����Χ�˸�������ѡ����õĵص㷱ֳ
					if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
						continue;
					if (environment_new[i + position_x[k]][j + position_y[k]].getHumanAlive())
						continue;
					if (positionSum < addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource()) {
						positionSum = addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource();
						positionX = i + position_x[k];
						positionY = j + position_y[k];
					}
				}
				//if (positionX == -1)//ѡ��ʧ��
					//continue;
				//��ֳ�ľ������
				Human *c = new Human();
				c->setAge(0);
				c->setIfSick(false);
				c->calIfPregant();
				c->setHealthCondition(0.5);
				c->calEnvironmentalAdaptation();
				c->setEffectExtendOfDisaster(1 - c->getEnvironmentalAdaptation());
				addHuman(*c, positionX, positionY);
				delete c;
}

void World::animalSelectBreed(int i, int j){
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
				for (int k = 0; k < 8; k++) {//����Χ�˸�������ѡ����õĵص㷱ֳ
					if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
						continue;
					if (environment_new[i + position_x[k]][j + position_y[k]].getHumanAlive())
						continue;
					if (positionSum < addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource()) {
						positionSum = addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource();
						positionX = i + position_x[k];
						positionY = j + position_y[k];
					}
				}
				//if (positionX == -1)//ѡ��ʧ��
					//continue;
				//��ֳ�ľ������
				Animal *c = new Animal();
				c->setAge(0);
				c->setIfSick(false);
				c->calIfPregant();
				c->setHealthCondition(0.5);
				c->calEnvironmentalAdaptation();
				c->setEffectExtendOfDisaster(1 - c->getEnvironmentalAdaptation());
				addAnimal(*c, positionX, positionY);
				delete c;
}

void World::plantSelectBreed(int i, int j){
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
				for (int k = 0; k < 8; k++) {//����Χ�˸�������ѡ����õĵص㷱ֳ
					if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
						continue;
					if (environment_new[i + position_x[k]][j + position_y[k]].getHumanAlive())
						continue;
					if (positionSum < addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource()) {
						positionSum = addFactor_EnvironCondition*environment[i + position_x[k]][j + position_y[k]].getEnvironCondition() + addFactor_Resource*environment[i + position_x[k]][j + position_y[k]].getResource();
						positionX = i + position_x[k];
						positionY = j + position_y[k];
					}
				}
				//if (positionX == -1)//ѡ��ʧ��
					//continue;
				//��ֳ�ľ������
				Plant *c = new Plant();
				c->setAge(0);
				c->setIfSick(false);
				c->calIfPregant();
				c->setHealthCondition(0.5);
				c->calEnvironmentalAdaptation();
				c->setEffectExtendOfDisaster(1 - c->getEnvironmentalAdaptation());
				addPlant(*c, positionX, positionY);
				delete c;
}

World::~World() {

}

