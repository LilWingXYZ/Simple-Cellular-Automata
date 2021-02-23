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
	//初始化全局变量
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
	//为环境设置初值
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
	//随机放置一定数量的人类
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

	//随机放置一定数量的动物
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


	//随机放置一定数量的植物
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


	//影响因素设置初值
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
	//开始
	int select;
	int day;
	int x,y;
   /* setcolor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    char s[420]={"  介绍：待定"};

      for(int k=0;k<8;k+=2)
      {
        cout<<s[k]<<s[k+1]<<flush;

        if(k%40==0)
        cout<<endl;

        Sleep(80);
      }
      cout<<endl;
      */

	showWorld();//显示地图
	//菜单选择
	while (!exitFlag) {
	    //cout <<endl<< "1. 生命演变过程    2. 查询环境信息    3. 结束" << endl;
	    cout <<endl<< "1. 生命演变    2. 环境信息    3. 保存世界    4. 读取世界    5. 退出" << endl;
		cin >> select;
		switch (select) {
		case 1 :
			cout << "演变周期(代): " ;
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
            cout << "请输入要查询的环境坐标，如（0 0）" << endl;
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
	//获取随机数
	return rand();
}

double World::getRandomNum(int min, int max, double precision) {
	//获取随机数
	return (min + rand() % (max - min + 1)) * precision;
}

bool World::probabilityEvent(double probability) {
	//判断概率事件是否发生
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
	//判断哪个随机事件发生
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
	//地图边界检查
	if (x < 0 || x > N)
		return false;
	if (y < 0 || y > M)
		return false;
	return true;
}

int World::input(int min, int max) {
	//输入函数，用于保证输入正确
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
					cout << "输入错误,请重新输入" << endl;
			}
			else
				cout << "输入错误,请重新输入" << endl;
		}
		else
			cout << "输入错误,请重新输入" << endl;
	}
	return i;
}

void World::changeWorld() {
	//statusSave();//状态保存
	humanCopy();
	humanNeiborhood();
	humanCopy();
    animalCopy();
	animalNeiborhood();
	animalCopy();
    plantCopy();
	plantNeiborhood();
	plantCopy();
	humanBreed();//人类繁殖
	animalBreed();//动物繁殖
	//plantBreed();//植物繁殖
	humanChangeEnvironment();//人类对环境的影响
	animalChangeEnvironment();//动物对环境的影响
	plantChangeEnvironment();//植物对环境的影响
	/*
	humanChange();//人类的变化
	humanBreed();//人类繁殖
	humanMove();//人类迁移
	humanChangeEnvironment();//人类对环境的影响
    animalChange();//动物的变化
	animalBreed();//动物繁殖
	animalMove();//动物迁移
	animalChangeEnvironment();//动物对环境的影响
    plantChange();//植物的变化
	plantBreed();//植物繁殖
	plantMove();//植物迁移
	plantChangeEnvironment();//植物对环境的影响
	*/
	environmentChange();//环境的变化
	disaster();//自然灾害发生
	//statusRefresh();//状态刷新
}

void World::statusSave() {
	//状态保存
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			environment_new[i][j] = environment[i][j];
}

void World::statusRefresh() {
	//状态刷新
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			environment[i][j] = environment_new[i][j];
}

void World::deleteHuman(int x, int y) {
	//删除人类
	environment_new[x][y].setHumanAlive(false);//在对应地点标记为人类死亡
	humanNum--;//人类数量减少
}

void World::deleteAnimal(int x, int y) {
	//删除动物
	environment_new[x][y].setAnimalAlive(false);//在对应地点标记为动物死亡
	animalNum--;//动物数量减少
}

void World::deletePlant(int x, int y) {
	//删除植物
	environment_new[x][y].setPlantAlive(false);//在对应地点标记为植物死亡
	plantNum--;//植物数量减少
}

void World::addHuman(Human &hu, Environment &envir) {
	//添加人类
	envir.setHumanAlive(true);//在对应地点标记为人类存活
	envir.setHuman(hu);//设置人类
	humanNum++;//人类数量增加
}

void World::addAnimal(Animal &ani, Environment &envir) {
	//添加动物
	envir.setAnimalAlive(true);//在对应地点标记为动物存活
	envir.setAnimal(ani);//设置动物
	animalNum++;//动物数量增加
}

void World::addPlant(Plant &pl, Environment &envir) {
	//添加植物
	envir.setPlantAlive(true);//在对应地点标记为植物存活
	envir.setPlant(pl);//设置植物
	plantNum++;//植物数量增加
}

void World::addHuman(Human &hu, int x, int y) {
	//添加人类
	environment_new[x][y].setHumanAlive(true);//在对应地点标记为人类存活
	//设置人类的属性
	environment_new[x][y].getHuman().setAge(hu.getAge());
	environment_new[x][y].getHuman().setHealthCondition(hu.getHealthCondition());
	environment_new[x][y].getHuman().setIfPregnant(hu.getIfPregnant());
	environment_new[x][y].getHuman().setEnvironmentalAdaptation(hu.getEnvironmentalAdaptation());
	environment_new[x][y].getHuman().setIfSick(hu.getIfSick());
	environment_new[x][y].getHuman().setEffectExtendOfDisaster(hu.getEffectExtendOfDisaster());
	environment_new[x][y].getHuman().calEnvironmentalAdaptation();
	environment_new[x][y].getHuman().calHeaCond();
	humanNum++;//人类数量增加
}

void World::addAnimal(Animal &ani, int x, int y) {
	//添加动物
	environment_new[x][y].setAnimalAlive(true);//在对应地点标记为动物存活
	//设置动物的属性
	environment_new[x][y].getAnimal().setAge(ani.getAge());
	environment_new[x][y].getAnimal().setHealthCondition(ani.getHealthCondition());
	environment_new[x][y].getAnimal().setIfPregnant(ani.getIfPregnant());
	environment_new[x][y].getAnimal().setEnvironmentalAdaptation(ani.getEnvironmentalAdaptation());
	environment_new[x][y].getAnimal().setIfSick(ani.getIfSick());
	environment_new[x][y].getAnimal().setEffectExtendOfDisaster(ani.getEffectExtendOfDisaster());
	environment_new[x][y].getAnimal().calEnvironmentalAdaptation();
	environment_new[x][y].getAnimal().calHeaCond();
	animalNum++;//动物数量增加
}

void World::addPlant(Plant &pl, int x, int y) {
	//添加植物
	environment_new[x][y].setPlantAlive(true);//在对应地点标记为植物存活
	//设置植物的属性
	environment_new[x][y].getPlant().setAge(pl.getAge());
	environment_new[x][y].getPlant().setHealthCondition(pl.getHealthCondition());
	environment_new[x][y].getPlant().setIfPregnant(pl.getIfPregnant());
	environment_new[x][y].getPlant().setEnvironmentalAdaptation(pl.getEnvironmentalAdaptation());
	environment_new[x][y].getPlant().setIfSick(pl.getIfSick());
	environment_new[x][y].getPlant().setEffectExtendOfDisaster(pl.getEffectExtendOfDisaster());
	environment_new[x][y].getPlant().calEnvironmentalAdaptation();
	environment_new[x][y].getPlant().calHeaCond();
	plantNum++;//植物数量增加
}


void World::humanBreed() {
	//繁殖
	int humanCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//判断该地点是否有存活的人类
				continue;
			humanCount = 0;//周围8个
			positionSum = 0;
			positionX = -1;
			positionY = -1;
			if (!environment[i][j].getHuman().getIfPregnant())//判断该人类是否在繁殖期
				continue;
			for (int k = 0; k < 8; k++) {//统计周围八个方格人类的数量
				if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
					continue;
				if (!environment_new[i + position_x[k]][j + position_y[k]].getHumanAlive())
					humanCount++;
			}
			//判断是否繁殖的条件
			if (humanCount > addFactor_HealthCondition*environment[i][j].getHuman().getHealthCondition()) {//？
				for (int k = 0; k < 8; k++) {//在周围八个方格内选择最好的地点繁殖
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
				if (positionX == -1)//选择失败
					continue;
				//繁殖的具体操作
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
	//动物繁殖
	int animalCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//判断该地点是否有存活的人类
				continue;
			animalCount = 0;//周围8个
			positionSum = 0;
			positionX = -1;
			positionY = -1;
			if (!environment[i][j].getAnimal().getIfPregnant())//判断该动物是否在繁殖期
				continue;
			for (int k = 0; k < 8; k++) {//统计周围八个方格动物的数量
				if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
					continue;
				if (!environment_new[i + position_x[k]][j + position_y[k]].getAnimalAlive())
					animalCount++;
			}
			//判断是否繁殖的条件
			if (animalCount > addFactor_HealthCondition*environment[i][j].getAnimal().getHealthCondition()) {//？
				for (int k = 0; k < 8; k++) {//在周围八个方格内选择最好的地点繁殖
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
				if (positionX == -1)//选择失败
					continue;
				//繁殖的具体操作
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
	//植物繁殖
	int plantCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//判断该地点是否有存活的人类
				continue;
			plantCount = 0;//周围8个
			positionSum = 0;
			positionX = -1;
			positionY = -1;
			if (!environment[i][j].getPlant().getIfPregnant())//判断该动物是否在繁殖期
				continue;
			for (int k = 0; k < 8; k++) {//统计周围八个方格动物的数量
				if (!mapRangeCheck(i + position_x[k], j + position_y[k]))
					continue;
				if (!environment_new[i + position_x[k]][j + position_y[k]].getPlantAlive())
					plantCount++;
			}
			//判断是否繁殖的条件
			if (plantCount > addFactor_HealthCondition*environment[i][j].getPlant().getHealthCondition()) {//？
				for (int k = 0; k < 8; k++) {//在周围八个方格内选择最好的地点繁殖
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
				if (positionX == -1)//选择失败
					continue;
				//繁殖的具体操作
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
	//迁移
	int humanCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//判断该地点是否有存活的人类
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
						if ((k - i)*(k - i) + (l - j)*(l - j) > 25)//保证在一定范围内迁移
							continue;
						if (environment_new[k][l].getHumanAlive())//判断该地点是否有存活的人类
							continue;
						//在一定范围内选择最好的地点迁移
						if (positionSum < addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource()) {
							positionSum = addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource();
							positionX = k;
							positionY = l;
						}
					}
				}
				if (positionX == -1)//选择失败
					continue;
				//迁移的具体操作
				addHuman(environment[i][j].getHuman(), positionX, positionY);
				deleteHuman(i, j);
			}
		}
	}
}


void World::animalMove() {
	//动物迁移
	int animalCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//判断该地点是否有存活的动物
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
						if ((k - i)*(k - i) + (l - j)*(l - j) > 25)//保证在一定范围内迁移
							continue;
						if (environment_new[k][l].getAnimalAlive())//判断该地点是否有存活的动物
							continue;
						//在一定范围内选择最好的地点迁移
						if (positionSum < addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource()) {
							positionSum = addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource();
							positionX = k;
							positionY = l;
						}
					}
				}
				if (positionX == -1)//选择失败
					continue;
				//迁移的具体操作
				addAnimal(environment[i][j].getAnimal(), positionX, positionY);
				deleteAnimal(i, j);
			}
		}
	}
}

void World::plantMove() {
	//植物迁移
	int plantCount = 0;
	double positionSum = 0;
	int positionX = -1;
	int positionY = -1;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//判断该地点是否有存活的动物
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
						if ((k - i)*(k - i) + (l - j)*(l - j) > 25)//保证在一定范围内迁移
							continue;
						if (environment_new[k][l].getPlantAlive())//判断该地点是否有存活的动物
							continue;
						//在一定范围内选择最好的地点迁移
						if (positionSum < addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource()) {
							positionSum = addFactor_EnvironCondition*environment[k][l].getEnvironCondition() + addFactor_Resource*environment[k][l].getResource();
							positionX = k;
							positionY = l;
						}
					}
				}
				if (positionX == -1)//选择失败
					continue;
				//迁移的具体操作
				addPlant(environment[i][j].getPlant(), positionX, positionY);
				deletePlant(i, j);
			}
		}
	}
}

void World::humanChangeEnvironment() {
	//人类对资源的影响
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//判断该地点是否有存活的人类
				continue;
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + humanToEnvironmentFactor_Ability*environment[i][j].getHuman().getEnvironmentalAdaptation()));
		}
	}
}

void World::animalChangeEnvironment() {
	//动物对资源的影响
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//判断该地点是否有存活的人类
				continue;
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + animalToEnvironmentFactor_Ability*environment[i][j].getAnimal().getEnvironmentalAdaptation()));
		}
	}
}

void World::plantChangeEnvironment() {
	//动物对资源的影响
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//判断该地点是否有存活的人类
				continue;
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + plantToEnvironmentFactor_Ability*environment[i][j].getPlant().getEnvironmentalAdaptation()));
		}
	}
}

void World::humanChange() {
	//人类的变化
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getHumanAlive())//判断该地点是否有存活的人类
				continue;
			//环境对人类的影响

			//每周期计算人类的属性
			environment_new[i][j].getHuman().setAge(environment_new[i][j].getHuman().getAge() + 1);
			environment_new[i][j].getHuman().calHeaCond();
			environment_new[i][j].getHuman().calEnvironmentalAdaptation();
			environment_new[i][j].getHuman().calIfPregant();
			//人类死亡
			if (environment[i][j].getHuman().getHealthCondition() <= 0)
				deleteHuman(i, j);
		}
	}
}

void World::animalChange() {
	//动物的变化
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getAnimalAlive())//判断该地点是否有存活的人类
				continue;
			//环境对人类的影响

			//每周期计算人类的属性
			environment_new[i][j].getAnimal().setAge(environment_new[i][j].getAnimal().getAge() + 1);
			environment_new[i][j].getAnimal().calHeaCond();
			environment_new[i][j].getAnimal().calEnvironmentalAdaptation();
			environment_new[i][j].getAnimal().calIfPregant();
			//人类死亡
			if (environment[i][j].getAnimal().getHealthCondition() <= 0)
				deleteAnimal(i, j);
		}
	}
}

void World::plantChange() {
	//植物的变化
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!environment[i][j].getPlantAlive())//判断该地点是否有存活的植物
				continue;
			//环境对植物的影响

			//每周期计算植物的属性
			environment_new[i][j].getPlant().setAge(environment_new[i][j].getPlant().getAge() + 1);
			environment_new[i][j].getPlant().calHeaCond();
			environment_new[i][j].getPlant().calEnvironmentalAdaptation();
			environment_new[i][j].getPlant().calIfPregant();
			//植物死亡
			if (environment[i][j].getPlant().getHealthCondition() <= 0)
				deletePlant(i, j);
		}
	}
}

void World::environmentChange() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//环境自我恢复
			environment_new[i][j].setResource(environment[i][j].getResource()*(1.0 + resourceGrowthRate));
			//灾后恢复
			if (environment[i][j].getEffectExtendOfDisaster() > 0)
				environment_new[i][j].setResource(environment[i][j].getResource() + recoverFactor_percent);
		}
	}
}

void World::disaster() {
	//发生自然灾害
	int positionX = -1;
	int positionY = -1;
	double probability[M*N];
	int probability_x[M*N];
	int probability_y[M*N];
	int k = 0;
	//筛选满足条件的地点
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
	int p = randomProbabilityEvent(probability, k);//在满足上述条件的地点中随机选择一个
	if (p == -1)//选择失败
		return;
	positionX = probability_x[p];
	positionY = probability_y[p];
	//发生自然灾后的影响
	environment_new[positionX][positionY].setEnvironCondition(environment[positionX][positionY].getEnvironCondition()*(1 - disasterFactor_EffectPercent));
	environment_new[positionX][positionY].setResource(environment[positionX][positionY].getResource()*(1 - disasterFactor_EffectPercent));
	//人类
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
	//动物
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
		//植物
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
	//显示人类的数量
	cout << "世界中共有" << humanNum << "个人类" << endl;
}

void World::showAnimalNum() {
	//显示动物的数量
	cout << "世界中共有" << animalNum << "只动物" << endl;
}

void World::showPlantNum() {
	//显示植物的数量
	cout << "世界中共有" << plantNum << "株植物" << endl;
}

void World::showEnvironment(Environment &envir) {
	//显示方格信息
	cout << "当前查询坐标为(" << envir.getX() << "," << envir.getY() << ")，"<<"此处的生物状况为： "<<endl;
	//cout << "资源数为" << envir.getResource() << "，";
	//cout << "环境状况为" << envir.getEnvironCondition() << endl;
	//人类
	if (!envir.getHumanAlive())
		cout << "没有人类" << endl;
	else {
		cout << "有一个人类" << endl;
	/*
		cout << "年龄为" << envir.getHuman().getAge() << "，";
		cout << "健康状况为" << envir.getHuman().getHealthCondition() << "，";
		if (envir.getHuman().getIfPregnant())
			cout << "处在繁殖期" << "，";
		else
			cout << "不在繁殖期" << "，";
		if (envir.getHuman().getIfSick())
			cout << "已患病" << "，";
		else
			cout << "未患病" << "，";
		cout << "能力为" << envir.getHuman().getEnvironmentalAdaptation() << endl;
		*/
	}


    //动物
		if (!envir.getAnimalAlive())
		cout << "没有动物" << endl;
	else {
		cout << "有一只动物" << endl;
		/*
		cout << "年龄为" << envir.getAnimal().getAge() << "，";
		cout << "健康状况为" << envir.getAnimal().getHealthCondition() << "，";
		if (envir.getAnimal().getIfPregnant())
			cout << "处在繁殖期" << "，";
		else
			cout << "不在繁殖期" << "，";
		if (envir.getAnimal().getIfSick())
			cout << "已患病" << "，";
		else
			cout << "未患病" << "，";
		cout << "能力为" << envir.getAnimal().getEnvironmentalAdaptation() << endl;
		*/
	}

	    //植物
		if (!envir.getPlantAlive())
		cout << "没有植物" << endl;
	else {
		cout << "有一株植物" << endl;
		/*
		cout << "年龄为" << envir.getPlant().getAge() << "，";
		cout << "健康状况为" << envir.getPlant().getHealthCondition() << "，";
		if (envir.getPlant().getIfPregnant())
			cout << "处在繁殖期" << "，";
		else
			cout << "不在繁殖期" << "，";
		if (envir.getPlant().getIfSick())
			cout << "已患病" << "，";
		else
			cout << "未患病" << "，";
		cout << "能力为" << envir.getPlant().getEnvironmentalAdaptation() << endl;
		*/
	}
}

   void gotoxy(const int y,const int x)
 {
   COORD point;
   point.X=2*x;
   point.Y=y;  //设游标
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
 }


void World::showWorld() {

	//显示地图

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
    cout <<endl<<"*******************************欢迎来到我的世界!********************************"<<endl;
    cout <<"O-正常人类，X—正常动物，I-正常植物，$-人与动物,"<<endl<<
           "#-人与植物，@-动物与植物，&-都有，空白-荒地"<<endl<<endl;
	//cout <<endl<< "当前世界情况："<<endl;
    //cout<<"面积："<<N<<"*"<<M<<"平方格  "<<"人类："<< humanNum << "个 " <<"动物："<< animalNum << "只 "<<"植物："<< plantNum << "株" <<endl;
}

bool World::save() {
	//打开文件
	ofstream saveFile;
	try {
		saveFile.open("data.txt");
		if (!saveFile)
			throw "error";
	}
	catch (char *) {
		cout << "无法保存文件" << endl;
	}
	//保存全局变量
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
	//保存环境属性
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
			//保存人类属性
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

                //保存动物属性
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

                //保存植物属性
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
	//保存完成
	cout << "保存成功" << endl;
	saveFile.close();
	return true;
}

bool World::read() {
	//打开文件
	ifstream readFile;
	try {
		readFile.open("data.txt");
		if (!readFile)
			throw "error";
	}
	catch (char *) {
		cout << "无法读取文件" << endl;
	}
	//读取全局变量
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
	//定义需要读取的变量
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
	//读取环境属性
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
			//人类
			if (readHumanAlive == 1)
				environment[i][j].setHumanAlive(true);
			else
				environment[i][j].setHumanAlive(false);
            //动物
            if (readAnimalAlive == 1)
				environment[i][j].setAnimalAlive(true);
			else
				environment[i][j].setAnimalAlive(false);
            //植物
            if (readPlantAlive == 1)
				environment[i][j].setPlantAlive(true);
			else
				environment[i][j].setPlantAlive(false);
			//读取人类属性
			readFile >> readAge;
			readFile >> readHealthCondition;
			readFile >> readIfPregnant;
			readFile >> readEnvironmentalAdaptation;
			readFile >> readIfSick;
			readFile >> readCreEffectExtendOfDisaster;

			//人类
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

			//动物
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

            //植物
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
	//保存完成
	cout << "读取成功" << endl;
	readFile.close();
	return true;
}

//人类变化
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

//动物变化
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


//植物变化
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

				for (int k = 0; k < 8; k++) {//在周围八个方格内选择最好的地点繁殖
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
				//if (positionX == -1)//选择失败
					//continue;
				//繁殖的具体操作
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
				for (int k = 0; k < 8; k++) {//在周围八个方格内选择最好的地点繁殖
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
				//if (positionX == -1)//选择失败
					//continue;
				//繁殖的具体操作
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
				for (int k = 0; k < 8; k++) {//在周围八个方格内选择最好的地点繁殖
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
				//if (positionX == -1)//选择失败
					//continue;
				//繁殖的具体操作
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

