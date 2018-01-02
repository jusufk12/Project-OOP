#include "Medical_Record.h"

Medical_Record::Medical_Record()
{

}

Medical_Record::~Medical_Record()
{
}

void Medical_Record::setPrice(double price)
{
    _price=price;
}
void Medical_Record::setDescription(std::string description)
{
    _description=description;
}
void Medical_Record::setTooth(Tooth* t)
{
    _t=t;
}

void Medical_Record:: print()
{
    std::cout<<_description<<std::endl;
}

std::string Medical_Record::getDescription()
{
    return _description;
}




