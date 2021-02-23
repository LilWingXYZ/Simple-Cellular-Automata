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
	void calHeaCond();//计算健康状况
	void calEnvironmentalAdaptation();//计算环境适应性
	void calIfPregant();//计算是否在繁殖期
private:
	double age;//年龄
	double healthCondition;//健康状况
	bool ifPregnant;//是否在繁殖期
	bool ifSick;//是否患病
	double environmentalAdaptation;//环境适应性
	double effectExtendOfDisaster;//自然灾害后的受影响程度
};

