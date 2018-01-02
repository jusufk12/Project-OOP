#include "Person.h"


Person::Person(std::string name, std::string surname, std::string mail, int phone)
{
    _name=name;
    _surname=surname;
    _mail=mail;
    _phoneNum=phone;
}
Person::Person()
{

}

Person::~Person()
{
}

void Person::setName(std::string name)
{
    _name=name;
}

void Person::setSurname(std::string surname)
{
    _surname=surname;
}

std::string Person::getName()
{
    return _name;
}

std::string Person::getSurname()
{
    return _surname;
}
