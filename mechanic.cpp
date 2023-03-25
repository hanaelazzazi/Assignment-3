//Created by Hana Elazzazi 900222935
#include "mechanic.h"
#include "appointment.h"
#include <string>

mechanic::mechanic() {
    counter = 0;
}

mechanic::mechanic(std::string n, int i, int a, int c) : Person(n, i, a) {
    counter = c;
}

void mechanic::addAppointment(Appointment app) {
    appts[counter] = app;
    counter++;
}

bool mechanic::isAvailable(int h, int m) {
    for (int i = 0; i < counter; i++) {
        if (h == appts[i].hours && m == appts[i].mins) {
            return false;
        }
    }
    return true;
}

int mechanic::getCounter() {
    return counter;
}

Appointment mechanic::getAppointment(int i) {
    return appts[i];
}

