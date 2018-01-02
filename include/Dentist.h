#ifndef DENTIST_H
#define DENTIST_H
#include <vector>
#include "Patient.h"
#include <string>
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <limits>

class Dentist: public Person
{
    public:
        Dentist(std::string name, std::string surname, std::string mail, int phoneNum);
        virtual ~Dentist();
        bool hasPatient(Patient* p);
        void addPatient(Patient* p);
        Patient createNewPatient();
        void showPatients();
        void addRequest(Patient* p);
        void writeMedicalRecord();
        std::string checkParameters(std::string first, std::string second);
        void savePatientReport();



    protected:

    private:

        std::vector <Patient*> _patients;
        std::vector <Patient*> _requests;
};

#endif // DENTIST_H
