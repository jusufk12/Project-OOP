#include "Medical_Record.h"

Medical_Record::Medical_Record()
{

}

Medical_Record::Medical_Record(int price)
{
    _price=price;
}

Medical_Record::Medical_Record(int price, Tooth* t)
{
    _price=price;
    _t=t;
}
Medical_Record::~Medical_Record()
{
}

void Medical_Record::setPrice(double price)
{
    _price=price;
}

void Medical_Record::setTooth(Tooth* t)
{
    _t=t;
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




