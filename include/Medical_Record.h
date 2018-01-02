#ifndef MEDICAL_RECORD_H
#define MEDICAL_RECORD_H
#include "Tooth.h"
#include <string>
#include <iostream>

class Medical_Record
{
    public:
        Medical_Record();
        virtual ~Medical_Record();
        void setPrice(double price);
        void setDescription(std::string description);
        void setTooth(Tooth* t);
        void print();
        std::string getDescription();



    protected:

    private:
        double _price;
        Tooth* _t;
        std::string _description;

};

#endif // MEDICAL_RECORD_H
