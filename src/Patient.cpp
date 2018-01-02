#include "Patient.h"
#include "Medical_Record.h"
#include "Tooth.h"

Patient::Patient(std::string name, std::string surname,std::string mail, int phoneNum)
:Person(name, surname, mail, phoneNum)
{

}

Patient::~Patient()
{
    //dtor
}

void Patient::showMedRecords()
{
    for (int i=0; i<_medicalRecords.size(); i++)
    {
        std::cout<<_medicalRecords[i]->getDescription()<<std::endl;
    }
}

void Patient::AddMedicalRecord(std::string jaw, std::string side, int position, double price, std::string description)
{

    Medical_Record med;
    Tooth t;
    t.setJaw(jaw);
    t.setSide(side);
    t.setPosition(position);
    med.setPrice(price);
    med.setDescription(description);
    med.setTooth(&t);
   // med.print();

    _medicalRecords.push_back(&med);

    showMedRecords();

}


