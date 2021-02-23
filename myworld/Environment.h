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
	int x;//λ��
	int y;//λ��
	double environCondition;//����״��
	double resource;//��Դ
	double effectExtendOfDisaster;//��Ȼ�ֺ������Ӱ��̶�
	bool humanAlive;//�õص����Ƿ��������
	bool animalAlive;//�õص����Ƿ���ڶ���
	bool plantAlive;//�õص����Ƿ����ֲ��
	Human human;//����
	Animal animal;
	Plant plant;//ֲ��
};


