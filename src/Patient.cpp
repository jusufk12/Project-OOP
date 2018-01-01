#include "Patient.h"


Patient::Patient(std::string name, std::string surname,std::string mail, int phoneNum)
:Person(name, surname, mail, phoneNum)
{
}

Patient::~Patient()
{
    //dtor
}



