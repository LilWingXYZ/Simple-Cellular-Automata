#pragma once

#include"Environment.h"
#include"Human.h"
#include"Animal.h"
#include"Plant.h"

const int M = 30;
const int N = 30;
const int INITIAL_HUMAN_NUM = 50;
const int INITIAL_ANIMAL_NUM = 100;
const int INITIAL_PLANT_NUM = 10;


class World {
public:
	World();

	void startWorld();//��ʼ
	void showWorld();//��ʾ��ͼ
	void changeWorld();//�����ݱ�
    void humanCopy();
	void humanNeiborhood();            //�����ھ���Ŀ
    void animalCopy();
	void animalNeiborhood();            //�����ھ���Ŀ
    void plantCopy();
	void plantNeiborhood();            //�����ھ���Ŀ
	void humanBreed();//���෱ֳ
	void animalBreed();//���ﷱֳ
	void plantBreed();//ֲ�ﷱֳ
	void humanChangeEnvironment();//����Ի�����Ӱ��
	void animalChangeEnvironment();//����Ի�����Ӱ��
	void plantChangeEnvironment();//ֲ��Ի�����Ӱ��
    void environmentChange();//�����ı仯
	void disaster();//��Ȼ�ֺ�����
    void humanCases(int i,int j,int m);                  //����ж�
	void animalCases(int i,int j,int m);                  //����ж�
	void plantCases(int i,int j,int m);                  //����ж�
    int getRandomNum();//��ȡ�����
	double getRandomNum(int min, int max, double precision);//��ȡ�����
    bool probabilityEvent(double probability);//�жϸ����¼��Ƿ���
	int randomProbabilityEvent(double probability[], int length);//�ж��ĸ�����¼�����
	bool mapRangeCheck(int x, int y);//��ͼ�߽���
	int input(int min, int max);//����
    void deleteHuman(int x, int y);//ɾ������
	void addHuman(Human &hu, Environment &envir);//��������
	void addHuman(Human &hu, int x, int y);//��������
	void deleteAnimal(int x, int y);//ɾ������
	void addAnimal(Animal &ani, Environment &envir);//���Ӷ���
	void addAnimal(Animal &ani, int x, int y);//���Ӷ���
    void deletePlant(int x, int y);//ɾ��ֲ��
	void addPlant(Plant &pl, Environment &envir);//����ֲ��
	void addPlant(Plant &pl, int x, int y);//����ֲ��
	void showHumanNum();//��ʾ���������
    void showAnimalNum();//��ʾ���������
    void showPlantNum();//��ʾֲ�������
    void showEnvironment(Environment &envir);//��ʾ������Ϣ






    void statusSave();//״̬����
    void statusRefresh();//״̬ˢ��


	void humanChange();//����ı仯

	void humanMove();//����Ǩ��

    void animalChange();//����ı仯

	void animalMove();//����Ǩ��

    void plantChange();//ֲ��ı仯

	void plantMove();//ֲ��Ǩ��








	bool save();//�������ݵ��ļ�
	bool read();//���ļ��ж�ȡ����




	void humanSelectBreed(int i, int j);
	void animalSelectBreed(int i, int j);
	void plantSelectBreed(int i, int j);

	~World();

private:
	bool exitFlag;//�˳���־
	int position_x[8];//λ�ñ任
	int position_y[8];//λ�ñ任
	Environment environment[M][N];//����
	Environment environment_new[M][N];//���񱸷�
	int humanNum;//������ʵ�ʵ���������
    int animalNum;//������ʵ�ʵĶ�������
    int plantNum;//������ʵ�ʵ�ֲ������
	int period;//ÿ����ʱ��
	double resourceGrowthRate;//��Դ��Ȼ������
	double disasterLevel;//��Ȼ�ֺ���������
	double addFactor_HealthCondition;//����״���Է�ֳ��Ӱ��
	double addFactor_EnvironCondition;//����״���Է�ֳ��Ӱ��
	double addFactor_Resource;//��Դ�Է�ֳ��Ӱ��
	double moveFactor_HealthCondition;//����״����Ǩ�Ƶ�Ӱ��
	double moveFactor_Ability;//������Ǩ�Ƶ�Ӱ��
	double moveFactor_EnvironCondition;//����״����Ǩ�Ƶ�Ӱ��
	double moveFactor_Resource;//��Դ��Ǩ�Ƶ�Ӱ��
	double humanToEnvironmentFactor_Ability;//����Ի�����Ӱ�죨��������أ�
    double animalToEnvironmentFactor_Ability;//����Ի�����Ӱ�죨��������أ�
    double plantToEnvironmentFactor_Ability;//ֲ��Ի�����Ӱ�죨��������أ�
	double recoverFactor_percent;//��Ȼ�ֺ���ÿ�����Զ��ָ��ٷֱ�
	double disasterFactor;//������Ȼ�ֺ���Ӱ������
	double disasterFactor_Level;//������Ȼ�ֺ����жϱ�׼
	double disasterFactor_EffectPercent;//��Ȼ�ֺ���Ӱ��̶�
};
