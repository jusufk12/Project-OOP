#ifndef DENTIST_H
#define DENTIST_H
#include <vector>
#include "Patient.h"
#include <string>
#include "Person.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include "Schedule.h"
#include "Medical_Record.h"
#include "Tooth.h"

class Dentist: public Person
{
    public:
        Dentist(std::string name, std::string surname, std::string mail, int phoneNum, Schedule* schedule);
        Dentist(std::string name, std::string surname, std::string mail, int phoneNum);
        Dentist();
        virtual ~Dentist();
        bool hasPatient(Patient* p);
        void addPatient(Patient* p);
        Patient* createNewPatient();
        void showPatients();
        void writeMedicalRecord();
        std::string checkParameters(std::string first, std::string second);
        void showPatientReport();
        void makeAppointment();
        void cancelAppointment();
        bool hasAnyPatients();
        void showDentistSchedule();
        void saveMedicalRecord(std::string jaw, std::string side, int position, int price, std::string patientName, std::string patientSurname);
        void readMedicalRecords();
        void saveSchedule();
        void ReloadSchedule();

    protected:

    private:

        std::vector <Patient*> _patients;
        Schedule* _schedule;
};

#endif // DENTIST_H
