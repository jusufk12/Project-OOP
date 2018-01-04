#include "Patient.h"
#include "Medical_Record.h"
#include "Tooth.h"

Patient::Patient(std::string name, std::string surname,std::string mail, int phoneNum)
:Person(name, surname, mail, phoneNum)
{

}
Patient::Patient():Person()
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
        std::cout<<"Medical record"<<i+1<<std::endl;
        std::cout<<_medicalRecords[i]->getPrice()<<std::endl;
    }
}

void Patient::CreateMedRecord(std::string _jaw, std::string _side, int _position, int _price)
{
    Tooth t(_jaw, _side, _position);
    Medical_Record med(_price);


    _medicalRecords.push_back(&med);
    showMedRecords();
    //std::cout<<"\tMedical record for patient "<<getName()<<" "<<getSurname()<<":\n"<<"\tService is done on tooth: "<<jaw<<" "<<side<<" "<<position<<"\n"<<
    //"\tThe price for the service is: "<<price<<"\n";

}

void Patient::saveMedRecords(std::string file_name)
{
    std::ofstream myfile (file_name);
    if (myfile.is_open())
    {
        myfile<<"Medical record for patient: "<<getName()<<" "<<getSurname()<<"\n";
        myfile<<"\n";
        for (int i=0; i<_medicalRecords.size(); i++)
        {
            myfile<<"Medical record "<<i+1<<"\n";
            myfile<<"\tTooth: "<<_medicalRecords[i]->getToothJaw()<<" "<<_medicalRecords[i]->getToothSide()<<" "<<_medicalRecords[i]->getToothPosition()<<"\n";
            //myfile<<"\tDescription about service done: "<<_medicalRecords[i]->getDescription<<"\n";
            myfile<<"\tPrice: "<<_medicalRecords[i]->getPrice()<<"\n";
            myfile<<"\n";
        }
        myfile.close();
    }
    else std::cout<<"unable, ne radi";
}

void Patient::addMedRecordInVector (Medical_Record* mr)
{
    _medicalRecords.push_back(mr);
}




