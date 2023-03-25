//Created by Hana Elazzazi 900222935
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int id;
    int age;
public:
    Person();
    Person(string n, int i, int a);
    void setName(string n);
    void setID(int i);
    void setAge(int a);
    string getName();
    int getID();
    int getAge();
    void printInfo();
};

#endif

