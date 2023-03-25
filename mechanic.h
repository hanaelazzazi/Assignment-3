//Created by Hana Elazzazi 900222935
#ifndef MECHANIC_H
#define MECHANIC_H
#include <iostream>
#include "person.h"
#include "appointment.h"
using namespace std;

class mechanic : public Person
{
private:
    int counter;
    Appointment appts[10];
public:
    mechanic();
    mechanic(string n, int i, int a, int c);
    void addAppointment(Appointment app);
    bool isAvailable(int h, int m);
    int getCounter();
    Appointment getAppointment(int i);
};

#endif

