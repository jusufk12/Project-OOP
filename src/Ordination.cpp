#include "Ordination.h"
#include <algorithm>
#include <iostream>

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
    if(!hasDentist(d))
    {
         _dentists.push_back(d);
    }
   else{
    std::cout<<"Doraditi ovu funksciju za else"<<std::endl;
   }
}

void Ordination::showDentists()
{
    for (int i=0; i<_dentists.size(); i++)
    {
        std::cout<<_dentists[i]->getName()<<std::endl;
    }
}

bool Ordination::hasDentist(Dentist* d)
{
    if(std::find(_dentists.begin(), _dentists.end(), d) != _dentists.end()){
		return true;
	}
	return false;
}
