#include"Environment.h"
#include<iostream>

using namespace std;

Environment::Environment() {

}

Environment::Environment(int x, int y, double resource, double environCondition, double effectExtendOfDisaster, bool humanAlive,bool animalAlive,bool plantAlive) {
	this->x = x;
	this->y = y;
	this->resource = resource;
	this->environCondition = environCondition;
	this->effectExtendOfDisaster = effectExtendOfDisaster;
	this->humanAlive = humanAlive;
	this->animalAlive = animalAlive;
	this->plantAlive = plantAlive;
}

Environment &Environment::operator=(Environment &e) {
	this->x = e.x;
	this->y = e.y;
	this->resource = e.resource;
	this->environCondition = e.environCondition;
	this->effectExtendOfDisaster = e.effectExtendOfDisaster;
	this->humanAlive = e.humanAlive;
	this->human = e.human;
	this->animalAlive = e.animalAlive;
	this->animal = e.animal;
	this->plantAlive = e.plantAlive;
	this->plant = e.plant;
	return *this;
}

int Environment::getX() {
	return x;
}

void Environment::setX(int x) {
	this->x = x;
}

int Environment::getY() {
	return y;
}

void Environment::setY(int y) {
	this->y = y;
}

double Environment::getEnvironCondition() {
	return environCondition;
}

void Environment::setEnvironCondition(double environCondition) {
	this->environCondition = environCondition;
}

double Environment::getResource() {
	return resource;
}

void Environment::setResource(double resource) {
	this->resource = resource;
}

double Environment::getEffectExtendOfDisaster() {
	return effectExtendOfDisaster;
}

void Environment::setEffectExtendOfDisaster(double extendOfDisaster) {
	this->effectExtendOfDisaster = extendOfDisaster;
}

bool Environment::getHumanAlive() {
	return humanAlive;
}

void Environment::setHumanAlive(bool humanAlive) {
	this->humanAlive = humanAlive;
}

Human &Environment::getHuman() {
	return human;
}

void Environment::setHuman(Human &human) {
	this->human = human;
}

bool Environment::getAnimalAlive() {
	return animalAlive;
}

void Environment::setAnimalAlive(bool animalAlive) {
	this->animalAlive = animalAlive;
}

Animal &Environment::getAnimal() {
	return animal;
}

void Environment::setAnimal(Animal &animal) {
	this->animal = animal;
}

bool Environment::getPlantAlive() {
	return plantAlive;
}

void Environment::setPlantAlive(bool plantAlive) {
	this->plantAlive = plantAlive;
}

Plant &Environment::getPlant() {
	return plant;
}

void Environment::setPlant(Plant &plant) {
	this->plant = plant;
}

