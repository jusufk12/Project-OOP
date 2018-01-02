#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "Person.h"
#include <vector>
#include <iostream>

class Ordination;

class Patient: public Person
{
    public:
        Patient(std::string name, std::string surname, std::string mail, int phoneNum);
        virtual ~Patient();
        void AddMedicalRecord(std::string vilica, std::string side, int position, double price, std::string description );
        void showMedRecords();

    protected:

    private:

        std::vector <Medical_Record*> _medicalRecords;
};

#endif // PATIENT_H
