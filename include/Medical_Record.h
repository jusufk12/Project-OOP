#ifndef MEDICAL_RECORD_H
#define MEDICAL_RECORD_H
#include "Tooth.h"
#include <string>
#include <iostream>

class Medical_Record
{
    public:
        Medical_Record();
        Medical_Record(int price, std::string description, Tooth* t);
        virtual ~Medical_Record();
        void setPrice(double price);
        void setDescription(char description[]);
        void setTooth(Tooth* t);
        void print();
        char* getDescription();
        std::string getToothJaw();
        std::string getToothSide();
        int getToothPosition();
        int getPrice();





    protected:

    private:
        int _price;
        Tooth* _t;
        char _description[100];

};

#endif // MEDICAL_RECORD_H
