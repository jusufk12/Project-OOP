#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "Person.h"
#include <vector>
#include <iostream>
#include <fstream>

class Ordination;

class Patient: public Person
{
    public:
        Patient(std::string name, std::string surname, std::string mail, int phoneNum);
        Patient();
        virtual ~Patient();
        void AddMedicalRecord(std::string vilica, std::string side, int position, double price, char description[] );
        void showMedRecords();
        void saveMedRecords();
        void addMedRecordInVector(Medical_Record* mr);


    protected:

    private:

        std::vector <Medical_Record*> _medicalRecords;
};

#endif // PATIENT_H
