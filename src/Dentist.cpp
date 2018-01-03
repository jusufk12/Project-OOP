#include "Dentist.h"
#include <limits>


Dentist::Dentist(std::string name, std::string surname,std::string mail, int phoneNum, Schedule* schedule)
:Person(name, surname, mail, phoneNum)
{
    _schedule = schedule;
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
         std::cout<<"Patient successfully added!"<<std::endl;
         std::cout<<"\n";
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
    addPatient(&p);
    showPatients();
    return p;



}

void Dentist::showPatients()
{
    for (int i=0; i<_patients.size(); i++)
    {
        std::cout<<_patients[i]->getName()<<" "<<_patients[i]->getSurname()<<std::endl;
    }
}


Patient* Dentist::getPatient()
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
           return _patients[patientIndex];
       }

}}}

Medical_Record* Dentist::writeMedicalRecord()
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

      Tooth t(_jaw, _side, _position);
      Medical_Record med(_price);

      return &med;
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
    showPatients();
    std::cout<<"Enter name of the patient whose report you want to save"<<std::endl;
    std::string name;
    std::cin>>name;
    std::cout<<"Enter surname of the patient"<<std::endl;
    std::string surname;
    std::cin>>surname;

    bool found = false;
    for (int i=0; i<_patients.size(); i++)
       {
           std::cout<< _patients[i]->getName();
           std::cout<< _patients[i]->getSurname();
           if ((name ==_patients[i]->getName())&&(surname ==_patients[i]->getSurname()))
           {
              _patients[i]->saveMedRecords("testing1.txt");
              found = true;
           }

       }
    if (found == true)
    {
        std::cout<<"Report successfully created!"<<std::endl;
    }
    else{
        std::cout<<"Patient was not found!"<<std::endl;
    }
}

void Dentist::makeAppointment()
{

        _schedule->showSchedule();
        std::cout<<"Enter name of your patient "<<std::endl;
        std::string name;
        std::cin>>name;
        std::cout<<"Enter day (Mon-Fri)"<<std::endl;
        std::string day;
        std::cin>>day;
        std::cout<<"Enter timeslot (9-16)"<<std::endl;
        int timeslot;
        std::cin>>timeslot;
        int _day;

        if (day == "Mon")
            _day = 1;
        else if (day == "Tue")
            _day=2;
        else if (day == "Wed")
            _day=3;
        else if (day == "Thu")
            _day=4;
        else if (day == "Fri")
            _day=5;
        else{
            std::cout<<"Invalid Input!"<<std::endl;
        }

       int _timeslot=timeslot-8;

        bool a = _schedule->addAppointment(name, _timeslot,_day);
        if(a == false)
        {
            std::cout<<"You did not make appointment."<<std::endl;
        }
        else
            {
                std::cout<<"radi";
        }
}

void Dentist::cancelAppointment()
{

        _schedule->showSchedule();
        std::cout<<"Enter day when you want to cancel appointment(Mon-Fri)"<<std::endl;
        std::string day;
        std::cin>>day;
        std::cout<<"Enter timeslot (9-16)"<<std::endl;
        int timeslot;
        std::cin>>timeslot;
        int _day;

        if (day == "Mon")
            _day = 1;
        else if (day == "Tue")
            _day=2;
        else if (day == "Wed")
            _day=3;
        else if (day == "Thu")
            _day=4;
        else if (day == "Fri")
            _day=5;
        else{
            std::cout<<"Invalid Input!"<<std::endl;
        }

       int _timeslot=timeslot-8;

        bool a = _schedule->removeAppointment(_timeslot,_day);
        if(a == false)
        {
            std::cout<<"You did not cancel appointment"<<std::endl;
        }
        else
            {
                std::cout<<"Appointment successfully canceled";
        }
}
