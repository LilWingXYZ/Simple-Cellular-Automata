#include"World.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
	//��ʼ�����������
	srand((unsigned int)time(NULL));
	//����������Ķ���
	World *myWorld = new World();
	//��ʼ
	myWorld->startWorld();

	delete myWorld;

	return 0;
}
