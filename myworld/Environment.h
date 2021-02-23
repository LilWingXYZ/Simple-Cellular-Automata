#pragma once

#include"Human.h"
#include"Animal.h"
#include"Plant.h"
#include<iostream>

using namespace std;

class Environment {
public:
	Environment();
	Environment(int x, int y, double resource, double environCondition, double effectExtendOfDisaster, bool humanAlive, bool animalAlive, bool plantAlive);
	Environment &operator=(Environment &e);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	double getEnvironCondition();
	void setEnvironCondition(double environCondition);
	double getResource();
	void setResource(double resource);
	double getEffectExtendOfDisaster();
	void setEffectExtendOfDisaster(double effectExtendOfDisaster);
	bool getHumanAlive();
	bool getAnimalAlive();
	bool getPlantAlive();
	void setHumanAlive(bool humanAlive);
	void setAnimalAlive(bool animalAlive);
	void setPlantAlive(bool plantAlive);
	Human &getHuman();
	Animal &getAnimal();
	Plant &getPlant();
	void setHuman(Human &human);
	void setAnimal(Animal &animal);
	void setPlant(Plant &plant);
private:
	int x;//位置
	int y;//位置
	double environCondition;//环境状况
	double resource;//资源
	double effectExtendOfDisaster;//自然灾害后的受影响程度
	bool humanAlive;//该地点内是否存在生物
	bool animalAlive;//该地点内是否存在动物
	bool plantAlive;//该地点内是否存在植物
	Human human;//生物
	Animal animal;
	Plant plant;//植物
};


