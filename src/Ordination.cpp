#include "Ordination.h"

Ordination::Ordination()
{
    //ctor
}

Ordination::~Ordination()
{
    //dtor
}

void Ordination::addDentist(Dentist* d)
{

    _dentists.push_back(d);
}
void Ordination::showDentists()
{
    for (int i=0; i<_dentists.size(); i++)
    {
        std::cout<<_dentists[i]->getName()<<std::endl;
    }
}
