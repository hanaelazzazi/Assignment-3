//Created by Hana Elazzazi 900222935
#include "person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {}

Person::Person(string n, int i, int a) {
    name = n;
    id = i;
    age = a;
}

void Person::setName(string n) {
    name = n;
}

void Person::setID(int i) {
    id = i;
}

void Person::setAge(int a) {
    age = a;
}

string Person::getName()
{
    return name;
}

int Person::getID() {
    return id;
}

int Person::getAge() {
    return age;
}

void Person::printInfo() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Age: " << age << endl;
}


