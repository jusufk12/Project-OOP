#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "Person.h"


class Patient: public Person
{
    public:
        Patient(std::string name, std::string surname, std::string mail, int phoneNum);
        virtual ~Patient();

    protected:

    private:
        int a;
};

#endif // PATIENT_H
