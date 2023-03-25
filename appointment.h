//Created by Hana Elazzazi 900222935
#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include "person.h"

struct Appointment
{
    int hours;
    int mins;
    Appointment(int h, int m)
    {
        hours = h;
        mins = m;
    }
    
    Appointment()
    {
        hours = 0;
        mins = 0;
    }
};
#endif
