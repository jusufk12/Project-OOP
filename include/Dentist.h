#ifndef DENTIST_H
#define DENTIST_H
#include <vector>
#include "Patient.h"
#include <string>

class Dentist
{
    public:
        Dentist(std::string name);
        virtual ~Dentist();
        std::string getName();


    protected:

    private:
        std::string name;
        std::vector <Patient*> _patients;
};

#endif // DENTIST_H
