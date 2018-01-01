#include "Dentist.h"

Dentist::Dentist(std::string _n)
{
  name = _n;
}

Dentist::~Dentist()
{
    //dtor
}

std::string Dentist::getName()
{
    return name;
}
