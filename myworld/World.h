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

	void startWorld();//开始
	void showWorld();//显示地图
	void changeWorld();//世界演变
    void humanCopy();
	void humanNeiborhood();            //计算邻居数目
    void animalCopy();
	void animalNeiborhood();            //计算邻居数目
    void plantCopy();
	void plantNeiborhood();            //计算邻居数目
	void humanBreed();//人类繁殖
	void animalBreed();//动物繁殖
	void plantBreed();//植物繁殖
	void humanChangeEnvironment();//人类对环境的影响
	void animalChangeEnvironment();//动物对环境的影响
	void plantChangeEnvironment();//植物对环境的影响
    void environmentChange();//环境的变化
	void disaster();//自然灾害发生
    void humanCases(int i,int j,int m);                  //情况判断
	void animalCases(int i,int j,int m);                  //情况判断
	void plantCases(int i,int j,int m);                  //情况判断
    int getRandomNum();//获取随机数
	double getRandomNum(int min, int max, double precision);//获取随机数
    bool probabilityEvent(double probability);//判断概率事件是否发生
	int randomProbabilityEvent(double probability[], int length);//判断哪个随机事件发生
	bool mapRangeCheck(int x, int y);//地图边界检查
	int input(int min, int max);//输入
    void deleteHuman(int x, int y);//删除人类
	void addHuman(Human &hu, Environment &envir);//添加人类
	void addHuman(Human &hu, int x, int y);//添加人类
	void deleteAnimal(int x, int y);//删除动物
	void addAnimal(Animal &ani, Environment &envir);//添加动物
	void addAnimal(Animal &ani, int x, int y);//添加动物
    void deletePlant(int x, int y);//删除植物
	void addPlant(Plant &pl, Environment &envir);//添加植物
	void addPlant(Plant &pl, int x, int y);//添加植物
	void showHumanNum();//显示人类的数量
    void showAnimalNum();//显示动物的数量
    void showPlantNum();//显示植物的数量
    void showEnvironment(Environment &envir);//显示环境信息






    void statusSave();//状态保存
    void statusRefresh();//状态刷新


	void humanChange();//人类的变化

	void humanMove();//人类迁移

    void animalChange();//动物的变化

	void animalMove();//动物迁移

    void plantChange();//植物的变化

	void plantMove();//植物迁移








	bool save();//保存数据到文件
	bool read();//从文件中读取数据




	void humanSelectBreed(int i, int j);
	void animalSelectBreed(int i, int j);
	void plantSelectBreed(int i, int j);

	~World();

private:
	bool exitFlag;//退出标志
	int position_x[8];//位置变换
	int position_y[8];//位置变换
	Environment environment[M][N];//方格
	Environment environment_new[M][N];//方格备份
	int humanNum;//世界中实际的人类数量
    int animalNum;//世界中实际的动物数量
    int plantNum;//世界中实际的植物数量
	int period;//每周期时长
	double resourceGrowthRate;//资源自然增长率
	double disasterLevel;//自然灾害发生条件
	double addFactor_HealthCondition;//健康状况对繁殖的影响
	double addFactor_EnvironCondition;//环境状况对繁殖的影响
	double addFactor_Resource;//资源对繁殖的影响
	double moveFactor_HealthCondition;//健康状况对迁移的影响
	double moveFactor_Ability;//能力对迁移的影响
	double moveFactor_EnvironCondition;//环境状况对迁移的影响
	double moveFactor_Resource;//资源对迁移的影响
	double humanToEnvironmentFactor_Ability;//人类对环境的影响（和能力相关）
    double animalToEnvironmentFactor_Ability;//动物对环境的影响（和能力相关）
    double plantToEnvironmentFactor_Ability;//植物对环境的影响（和能力相关）
	double recoverFactor_percent;//自然灾害后，每周期自动恢复百分比
	double disasterFactor;//发生自然灾害的影响因素
	double disasterFactor_Level;//发生自然灾害的判断标准
	double disasterFactor_EffectPercent;//自然灾害的影响程度
};

