#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <Medical_Record.h>


class Person
{
    public:
        Person(std::string name, std::string surname, std::string mail, int phone);
        virtual ~Person();
        void setName(std::string name);
        void setSurname(std::string surname);
        std::string getName();
        std::string getSurname();


    protected:

    private:
        std::string _name;
        std::string _surname;
        std::string _mail;
        int _phoneNum;



};

#endif // PERSON_H
