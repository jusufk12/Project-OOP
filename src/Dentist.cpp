#include "Dentist.h"
#include<limits>


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

Patient Dentist::createNewPatient()
{
    std::cout<<"Enter name of your new patient. "<<std::endl;
    std::string name;
    std::cin>>name;
    std::cout<<"Surname: "<<std::endl;
    std::string surname;
    std::cin>>surname;
    std::cout<<"E-mail address: "<<std::endl;
    std::string mail;
    std::cin>>mail;
    std::cout<<"Phone number: "<<std::endl;
    int phone;
    std::cin>>phone;
    Patient p(name, surname, mail, phone);
    //addPatient(&p);
    return p;



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
    std::string name;
    std::string surname;


    if (_patients.size()>0)
    {
       showPatients();
       std::cout<<"\n";
       bool patientFound=true;
       int patientIndex;

       while(patientFound)
       {
       std::cout<<"Enter the name of patient."<<std::endl;
       std::cin>>name;
       std::cout<<"Enter the surname of patient."<<std::endl;
       std::cin>>surname;


       for (int i=0; i<_patients.size(); i++)
       {
           if ((name ==_patients[i]->getName())&&(surname ==_patients[i]->getSurname()))
               {
                 patientFound=false;
                 patientIndex=i;
               }
       }
       if (patientFound == true)
       {
           std::cout<<"You don't have that patient. If you want to enter again press 1, if you want to create new patient press 2"<<std::endl;
           int choice;
           std::cin>>choice;
           if (choice==2)
           {
               Patient p;
               p = createNewPatient();
               addPatient(&p);
                //showPatients();

               patientFound=false;
               patientIndex=_patients.size()-1;
               break;

           }
       }
       }
        //patientIndex=0;


      std::cout<<"You are going to write medical record for "<<_patients[patientIndex]->getName()<<" "<<_patients[patientIndex]->getSurname()<<std::endl;
      std::cout<<"Enter 'upper' or 'lower' for jaw"<<std::endl;
      std::string _jaw;
      _jaw = checkParameters("upper", "lower");

      std::cout<<"Enter 'right' or 'left' for tooth side"<<std::endl;
      std::string _side;
      _side = checkParameters("right", "left");

      std::cout<<"Enter position of the tooth (from 1 to 8)"<<std::endl;
      int _position = 0;
      bool c = true;

      while(!((_position > 0) && (_position < 9)))
      {

            std::cin >> _position;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            if (!((_position > 0) && (_position < 9)))
                std::cout<<"Invalid input.  Try again:"<<std::endl;
      }


      std::cout<<"Enter price of your service"<<std::endl;
      int _price = 0;
      while((!(std::cin >> _price)))
      {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            std::cout << "Invalid input.  Try again: "<<std::endl;

      }

      std::cout<<"Enter description of your service"<<std::endl;
      char _description[100];
      std::cin.getline(_description, 100);


      _patients[patientIndex]->AddMedicalRecord(_jaw, _side, _position, _price, _description);

    }
    else
    {
        std::cout<<"You don't have any patients."<<std::endl;
    }

}

std::string Dentist::checkParameters(std::string first, std::string second)
{
          std::string temp;
          bool correct = true;
          while(correct)
          {
              std::cin>>temp;
              if (temp==first||temp==second)
               {
                  correct=false;
               }
               else
               {
                   std::cout<<"You entered parameter wrongly. Enter again."<<std::endl;
               }
          }
          return temp;
}

void Dentist::savePatientReport()
{
    std::cout<<"Enter name of the patient whose report you want to save"<<std::endl;
    std::string name;
    std::cin>>name;
    std::cout<<"Enter surname of the patient"<<std::endl;
    std::string surname;
    std::cin>>surname;

    for (int i=0; i<_patients.size(); i++)
       {
           if ((name ==_patients[i]->getName())&&(surname ==_patients[i]->getSurname()))
           {
              _patients[i]->saveMedRecords();
           }
       }

}
