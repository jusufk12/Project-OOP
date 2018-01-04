#ifndef MEDICAL_RECORD_H
#define MEDICAL_RECORD_H
#include "Tooth.h"
#include <string>
#include <iostream>

class Medical_Record
{
    public:
        Medical_Record();
        Medical_Record(int price, Tooth* t);
        virtual ~Medical_Record();
        void setPrice(double price);

        void setTooth(Tooth* t);
        void print();
        std::string getToothJaw();
        std::string getToothSide();
        int getToothPosition();
        int getPrice();


    protected:

    private:
        int _price;
        Tooth* _t;


};

#endif // MEDICAL_RECORD_H
