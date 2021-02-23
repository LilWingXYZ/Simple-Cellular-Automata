#include"World.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
	//初始化随机数种子
	srand((unsigned int)time(NULL));
	//创建世界类的对象
	World *myWorld = new World();
	//开始
	myWorld->startWorld();

	delete myWorld;

	return 0;
}
