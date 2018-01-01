#ifndef DENTIST_H
#define DENTIST_H
#include <vector>
#include "Patient.h"
#include <string>
#include "Person.h"

class Dentist: public Person
{
    public:
        Dentist(std::string name, std::string surname, std::string mail, int phoneNum);
        virtual ~Dentist();



    protected:

    private:

        std::vector <Patient*> _patients;
};

#endif // DENTIST_H
