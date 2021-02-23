#pragma once

#include <iostream>

using namespace std;

const int human_max_age = 100;
const double human_sickAffectHealthCondition = 0.05;
const double pregantAffectEnvironmentalAdaptation = 0.2;

class Human {
public:
	Human();
	Human(int age, bool ifSick, double effectExtendOfDisaster);
	Human &operator=(Human &c);
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




