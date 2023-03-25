//Created by Hana Elazzazi 900222935
#include "appointment.h"
#include "customer.h"
#include <iostream>
using namespace std;

// Default constructor
  customer::customer()
  {
      
  }
  // Constructor with parameters
    customer::customer(string n, int i, int a, int m, Appointment app) : Person(n, i, a)
  {
      mechanicID = m;
      appt = app;
  }
  // Setter for the mechanic's ID
  void customer::setMechanicID(int m)
  {
      mechanicID = m;
  }
  // Setter for the customer's appointment
void customer::setAppointment(Appointment app)
  {
      appt = app;
  }
  // Getter for the mechanic's ID
  int customer::getMechanicID()
  {
      return mechanicID;
  }
// Getter for the customer's appointment
Appointment customer::getAppointment() const
   {
       return appt;
   }
   // Overload the less than operator to compare appointments
   bool customer::operator<(const customer& c) const
   {
       if (appt.hours == c.getAppointment().hours)
       {
           return appt.mins < c.getAppointment().mins;
       }
       else
       {
           return appt.hours < c.getAppointment().hours;
       }
   }
   // Overload the greater than operator to compare appointments
   bool customer::operator>(const customer& c) const
   {
       if (appt.hours == c.getAppointment().hours)
       {
           return appt.mins > c.getAppointment().mins;
       }
       else
       {
           return appt.hours > c.getAppointment().hours;
       }
   }
   // Overload the equal to operator to compare appointments
   bool customer::operator==(const customer& c) const
   {
       return appt.hours == c.getAppointment().hours && appt.mins == c.getAppointment().mins;
   }


