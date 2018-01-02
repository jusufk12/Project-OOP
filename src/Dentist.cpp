#include "Dentist.h"
Dentist::Dentist(std::string name, std::string surname,std::string mail, int phoneNum)
:Person(name, surname, mail, phoneNum)
{

}

Dentist::~Dentist()
{
}

bool Dentist::hasPatient(Patient* p)
{
    if(std::find(_patients.begin(), _patients.end(), p) != _patients.end()){
		return true;
	}
	return false;
}

void Dentist::addPatient (Patient* p)
{
    if(!hasPatient(p))
    {
         _patients.push_back(p);
    }
   else{
    std::cout<<"Doraditi ovu funksciju za else"<<std::endl;
   }
}

void Dentist::showPatients()
{
    for (int i=0; i<_patients.size(); i++)
    {
        std::cout<<_patients[i]->getName()<<std::endl;
    }
}

void Dentist::addRequest (Patient* p)
{
    if(!(std::find(_requests.begin(), _requests.end(), p) != _requests.end()))
        {
            _requests.push_back(p);
        }
   else{
    std::cout<<"Doraditi ovu funksciju za else"<<std::endl;
   }
}

void Dentist::writeMedicalRecord()
{
    showPatients();

    _patients[0]->AddMedicalRecord("g", "d", 5, 20, "novi opis");
    _patients[1]->AddMedicalRecord("g", "d", 5, 20, "novi dva");

}




