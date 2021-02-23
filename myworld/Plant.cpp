#include"Plant.h"
#include<iostream>
#include<cmath>

using namespace std;

Plant::Plant() {
	age = 0;
	healthCondition = 0;
	ifPregnant = false;
	ifSick = false;
	environmentalAdaptation = 0;
	effectExtendOfDisaster = 0;
}

Plant::Plant(int age, bool ifSick, double effectExtendOfDisaster) {
	this->age = age;
	this->ifSick = ifSick;
	this->effectExtendOfDisaster = effectExtendOfDisaster;
	calIfPregant();
	calHeaCond();
	calEnvironmentalAdaptation();
}

Plant &Plant::operator=(Plant &c) {
	this->age = c.age;
	this->healthCondition = c.healthCondition;
	this->ifPregnant = c.ifPregnant;
	this->ifSick = c.ifSick;
	this->environmentalAdaptation = c.environmentalAdaptation;
	this->effectExtendOfDisaster = c.effectExtendOfDisaster;
	return *this;
}

double Plant::getAge() {
	return age;
}

void Plant::setAge(double age) {
	this->age = age;
}

double Plant::getHealthCondition() {
	return healthCondition;
}

void Plant::setHealthCondition(double healthCondition) {
	this->healthCondition = healthCondition;
	//this->healthCondition = age @ healthCondition @ ifSick;
}

bool Plant::getIfPregnant() {
	return ifPregnant;
}

void Plant::setIfPregnant(bool ifPregnant) {
	this->ifPregnant = ifPregnant;
}

bool Plant::getIfSick() {
	return ifSick;
}

void Plant::setIfSick(bool ifSick) {
	this->ifSick = ifSick;
}

double Plant::getEnvironmentalAdaptation() {
	return environmentalAdaptation;
}

void Plant::setEnvironmentalAdaptation(double environmentalAdaptation) {
	this->environmentalAdaptation = environmentalAdaptation;
}

double Plant::getEffectExtendOfDisaster() {
	return effectExtendOfDisaster;
}

void Plant::setEffectExtendOfDisaster(double effectExtendOfDisaster) {
	this->effectExtendOfDisaster = effectExtendOfDisaster;
}

void Plant::calHeaCond() {
	//计算健康状况
	double mid = 0.000003*pow((age - 1), 3) - 0.0006*pow((age - 1), 2) + 0.0317*(age - 1) + 0.5421 - healthCondition;
	//double mid = sin((age - 1)*1.0*3.14 / max_age) - healthCondition;
	healthCondition = 0.000003*pow(age, 3) - 0.0006*pow(age, 2) + 0.0317*age + 0.5421 - mid;
	double heaCon = healthCondition;
	if (ifSick)
		healthCondition -= heaCon*plant_sickAffectHealthCondition;
	healthCondition -= heaCon*effectExtendOfDisaster;
	if (healthCondition < 0)
		healthCondition = 0;
	//age @ ifSick @ effectExtendOfDisaster
}

void Plant::calEnvironmentalAdaptation() {
	//计算环境适应性
	environmentalAdaptation = sin(age*1.0*3.14 / plant_max_age);
	environmentalAdaptation *= healthCondition;
	if (ifPregnant)
		environmentalAdaptation -= environmentalAdaptation * pregantAffectEnvironmentalAdaptation;
	if (environmentalAdaptation < 0)
		environmentalAdaptation = 0;
	//age @ ifPregant @ healthCondition
}

void Plant::calIfPregant() {
	//计算是否在繁殖期
	if (age >= 15 && age <= 60)
		ifPregnant = true;
	else
		ifPregnant = false;
}


