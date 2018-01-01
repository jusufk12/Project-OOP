#ifndef DENTIST_H
#define DENTIST_H
#include <vector>
#include "Patient.h"
#include <string>
#include "Person.h"
#include <algorithm>
#include <iostream>

class Dentist: public Person
{
    public:
        Dentist(std::string name, std::string surname, std::string mail, int phoneNum);
        virtual ~Dentist();
        bool hasPatient(Patient* p);
        void addPatient(Patient* p);
        void showPatients();




    protected:

    private:

        std::vector <Patient*> _patients;
};

#endif // DENTIST_H
