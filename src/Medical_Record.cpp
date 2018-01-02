#include "Medical_Record.h"

Medical_Record::Medical_Record()
{

}

Medical_Record::Medical_Record(int price, std::string description, Tooth* t)
{
    _price=price;
    description=description;
    _t=t;
}
Medical_Record::~Medical_Record()
{
}

void Medical_Record::setPrice(double price)
{
    _price=price;
}
void Medical_Record::setDescription(char description[])
{
     for (int i=0; i < sizeof(description); i++)
     {
         _description[i] = description[i];
     }
}
void Medical_Record::setTooth(Tooth* t)
{
    _t=t;
}

void Medical_Record:: print()
{
    std::cout<<_description<<std::endl;
}

char* Medical_Record::getDescription()
{
    return _description;
}

std::string Medical_Record::getToothJaw()
{
    return _t->getJaw();
}
std::string Medical_Record::getToothSide()
{
    return _t->getSide();
}
int Medical_Record::getToothPosition()
{
    return _t->getPosition();
}
int Medical_Record::getPrice()
{
    return _price;
}




