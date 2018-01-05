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
        void CreateMedRecord(std::string jaw, std::string side, int position, int price);
        void showMedRecords();
        void saveMedRecords(std::string file_name);
        void addMedRecordInVector(Medical_Record* mr);
        void RealoadMedicalRecord(std::string jaw, std::string side, int position, int price);


    protected:

    private:

        std::vector <Medical_Record*> _medicalRecords;
};

#endif // PATIENT_H
