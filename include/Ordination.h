#ifndef ORDINATION_H
#define ORDINATION_H
#include <vector>
#include "Dentist.h"
#include <iostream>

class Ordination
{
    public:
        Ordination();
        virtual ~Ordination();
        void addDentist(Dentist* d);
        void showDentists();
        bool hasDentist(Dentist* d);

    protected:

    private:
        std::vector <Dentist*> _dentists;

};

#endif // ORDINATION_H
