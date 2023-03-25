//Created by Hana Elazzazi 900222935
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include "appointment.h"
#include "my_queue.h"
using namespace std;

int main()
{
    // Open mechanics file and read in the number of mechanics
    ifstream mechanics_file("/Users/hanaelazzazi/Desktop/Spring 2023/CS 2/Assignments /Assignment 3/Assignment3/Assignment3/mechanics.txt");
    
    int num_mechanics;
    mechanics_file >> num_mechanics;
    
    // Allocate memory for mechanics array
    mechanic* mechanics = new mechanic[num_mechanics];
    
    // Loop through mechanics file and add mechanics to array
    for (int i = 0; i < num_mechanics; i++)
    {
        // Read in mechanic data from file
        string name;
        int age, id, num_appointments;
        mechanics_file >> name >> id >> age >> num_appointments;
        
        // Create new mechanic and add to array
        mechanics[i] = mechanic(name, id, age, 0);
        
        // Loop through appointments for this mechanic and add to mechanic's schedule
        for (int j = 0; j < num_appointments; j++)
        {
            int hours, mins;
            mechanics_file >> hours >> mins;
            mechanics[i].addAppointment({ hours, mins });
        }
    }
    
    // Close mechanics file
    mechanics_file.close();
    
    // Open customers file and read in the number of customers
    ifstream customers_file("/Users/hanaelazzazi/Desktop/Spring 2023/CS 2/Assignments /Assignment 3/Assignment3/Assignment3/customers.txt");
    
    int num_customers;
    customers_file >> num_customers;
    
    // Allocate memory for customers array
    customer* customers = new customer[num_customers];
    
    // Loop through customers file and add customers to array
    for (int i = 0; i < num_customers; i++)
    {
        // Read in customer data from file
        string name;
        int age, id, mechanic_id, hours, mins;
        customers_file >> name >> age >> id >> mechanic_id >> hours >> mins;
        
        // Create new customer and add to array
        customers[i] = customer(name, id, age, mechanic_id, Appointment(hours, mins));
    }
    
    // Close customers file
    customers_file.close();

    // Create a queue to hold customers
    Q<customer> q;
    // Add customers to the queue
    for (int i = 0; i < num_customers; i++)
    {
        q.push(customers[i]);
    }

    // Process the queue of customers
    while (!q.empty())
    {
        // Get the next customer from the queue
        customer c = q.pop();

        // Find an available mechanic for the customer
        mechanic* m = nullptr;
        if (c.getMechanicID() == 1)
        {
            if (mechanics[0].isAvailable(c.getAppointment().hours, c.getAppointment().mins))
            {
                m = &mechanics[0];
            }
            else if (mechanics[1].isAvailable(c.getAppointment().hours, c.getAppointment().mins))
            {
                m = &mechanics[1];
            }
        }
        else if (c.getMechanicID() == 2)
        {
            if (mechanics[1].isAvailable(c.getAppointment().hours, c.getAppointment().mins))
            {
                m = &mechanics[1];
            }
        }
        else if (c.getMechanicID() == 3) {
            if (mechanics[2].isAvailable(c.getAppointment().hours, c.getAppointment().mins))
            {
                m = &mechanics[2];
            }
        }
        // If a mechanic is available, assign the customer to the mechanic and print the appointment

        if (m != nullptr)
        {
            m->addAppointment({ c.getAppointment().hours, c.getAppointment().mins });
            cout << "Mr./Mrs. " << c.getName() <<  " has an appointment at " << c.getAppointment().hours << ":" << c.getAppointment().mins <<"0 with "<< m->getName() << endl;
        }
        // If the mechanic isn't available at this time print this statement
        else
        {
            cout << "Mr./Mrs. " << c.getName() << " cannot be assigned to a mechanic at this time." << endl;
        }
    }
    
    // Deallocating memory for mechanics and customer arrays
    delete[] mechanics;
    delete[] customers;

    return 0;
}

