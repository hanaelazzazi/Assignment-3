//Created by Hana Elazzazi 900222935
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "person.h"
#include "appointment.h"

class customer : public Person
{
private:
    int mechanicID;
    Appointment appt;
public:
    customer();
    customer(string n, int i, int a, int m, Appointment app);
    void setMechanicID(int m);
    void setAppointment(Appointment app);
    int getMechanicID();
    Appointment getAppointment() const;
    bool operator<(const customer& c) const;
    bool operator>(const customer& c) const;
    bool operator==(const customer& c) const;
};


#endif 

