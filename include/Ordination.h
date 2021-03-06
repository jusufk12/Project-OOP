#ifndef ORDINATION_H
#define ORDINATION_H
#include <vector>
#include "Dentist.h"
#include <iostream>
#include <fstream>

class Ordination
{
    public:
        Ordination();
        virtual ~Ordination();
        void addDentist(Dentist* d);
        void showDentists();
        bool hasDentist(Dentist* d);
        void menu();
        void saveDentists(std::string name, std::string surname, std::string email, int phone);
        void ReadDentists();
        void savePatients(std::string name,std::string  surname, std::string  email,  int phone, std::string dentistName, std::string dentistSurname);
        void ReadPatients();



    protected:

    private:
        std::vector <Dentist*> _dentists;

};

#endif // ORDINATION_H
