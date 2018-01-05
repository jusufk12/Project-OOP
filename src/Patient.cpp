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
    for (int i=0; i<_medicalRecords.size(); i++)
    {
        delete [] _medicalRecords[i];
        _medicalRecords[i]=nullptr;
    }
}

void Patient::showMedRecords()
{
    if(_medicalRecords.size()==0)
    {
        std::cout<<"Patient has no medical records."<<std::endl;
        std::cout<<"\n";
    }
    else
    {
        std::cout<<"\n";
        std::cout<<"Medical record "<<" for patient "<<getName()<<" "<<getSurname()<<":"<<std::endl;
        for (int i=0; i<_medicalRecords.size(); i++)
    {

        std::cout<<"\t"<<i+1<<". The service is done on tooth: "<<_medicalRecords[i]->getToothJaw()<<" "<<_medicalRecords[i]->getToothSide()<<" "<<_medicalRecords[i]->getToothPosition()<<";  Price: "<<_medicalRecords[i]->getPrice()<<std::endl;

    }
    std::cout<<"\n";
    }
}

void Patient::CreateMedRecord(std::string _jaw, std::string _side, int _position, int _price)
{
    Tooth* t=new Tooth(_jaw, _side, _position);
    Medical_Record* med=new Medical_Record(_price, t);
    _medicalRecords.push_back(med);
    showMedRecords();
    //std::cout<<"\tMedical record for patient "<<getName()<<" "<<getSurname()<<":\n"<<"\tService is done on tooth: "<<jaw<<" "<<side<<" "<<position<<"\n"<<
    //"\tThe price for the service is: "<<price<<"\n";

}

void Patient::RealoadMedicalRecord(std::string jaw, std::string side, int position, int price)
{
    Tooth* t=new Tooth(jaw, side, position);
    Medical_Record* med=new Medical_Record(price, t);
    _medicalRecords.push_back(med);
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




