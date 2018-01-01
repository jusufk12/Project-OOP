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

    protected:

    private:
        std::vector <Dentist*> _dentists;

};

#endif // ORDINATION_H
