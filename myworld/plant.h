#pragma once

#include <iostream>
#include"Human.h"

using namespace std;

const int plant_max_age = 500;
const double plant_sickAffectHealthCondition = 0.01;
//const double pregantAffectEnvironmentalAdaptation = 0.2;

class Plant {
public:
	Plant();
	Plant(int age, bool ifSick, double effectExtendOfDisaster);
	Plant &operator=(Plant &c);
	double getAge();
	void setAge(double age);
	double getHealthCondition();
	void setHealthCondition(double healthCondition);
	bool getIfPregnant();
	void setIfPregnant(bool ifPregnant);
	bool getIfSick();
	void setIfSick(bool ifSick);
	double getEnvironmentalAdaptation();
	void setEnvironmentalAdaptation(double environmentalAdaptation);
	double getEffectExtendOfDisaster();
	void setEffectExtendOfDisaster(double effectExtendOfDisaster);
	void calHeaCond();//���㽡��״��
	void calEnvironmentalAdaptation();//���㻷����Ӧ��
	void calIfPregant();//�����Ƿ��ڷ�ֳ��
private:
	double age;//����
	double healthCondition;//����״��
	bool ifPregnant;//�Ƿ��ڷ�ֳ��
	bool ifSick;//�Ƿ񻼲�
	double environmentalAdaptation;//������Ӧ��
	double effectExtendOfDisaster;//��Ȼ�ֺ������Ӱ��̶�
};

