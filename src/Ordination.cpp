#include "Ordination.h"
#include <algorithm>
#include <iostream>

Ordination::Ordination()
{
}

Ordination::~Ordination()
{
    for (int i=0; i<_dentists.size(); i++)
    {
        delete [] _dentists[i];
        _dentists[i]=nullptr;
    }
}

void Ordination::addDentist(Dentist* d)
{
    if(!hasDentist(d))
    {
         _dentists.push_back(d);
    }
   else{
    std::cout<<"You cannot add this dentist. He is already registered."<<std::endl;
   }
}

void Ordination::showDentists()
{
    std::cout<<"Registered are following dentists:"<<std::endl;
    for (int i=0; i<_dentists.size(); i++)
    {
        std::cout<<_dentists[i]->getName()<<" "<<_dentists[i]->getSurname()<<std::endl;
    }
    std::cout<<"\n";
}

bool Ordination::hasDentist(Dentist* d)
{
    if(std::find(_dentists.begin(), _dentists.end(), d) != _dentists.end()){
		return true;
	}
	return false;
}

void Ordination::menu()
{
    int input;
    Schedule s;
    ReadDentists();

    while (input!=0)
    {
        std::cout<<"Enter 1 to register new dentist, enter 2 to choose one of the listed dentists."<<std::endl;
        std::cout<<"Enter 0 to exit."<<std::endl;
        std::cin>>input;

        if(input==0)
        {
            break;
        }
        else if(input==1)
        {
            std::string name, surname, mail;
            int phone;
            std::cout<<"\n";
            std::cout<<"Input your name: "<<std::endl;
            std::cin>>name;
            std::cout<<"Input your surname: "<<std::endl;
            std::cin>>surname;
            std::cout<<"Input your mail: "<<std::endl;
            std::cin>>mail;
            std::cout<<"Input your phone: "<<std::endl;
            std::cin>>phone;
            Dentist* dentist1=new Dentist(name, surname, mail, phone, &s);
            addDentist(dentist1);

            saveDentists(name, surname, mail, phone);
            std::cout<<"You are successfully registered!"<<std::endl;
            std::cout<<"\n";
            showDentists();
        }
        else if(input==2)
        {
            if(_dentists.size()==0)
            {
                std::cout<<"There are no registered dentists."<<std::endl;
            }
            else
            {
                showDentists();
                std::cout<<"\n";
                std::cout<<"Choose one of the dentists listed. "<<std::endl;
                std::cout<<"Enter your name"<<std::endl;
                std::string name;
                std::cin>>name;
                std::cout<<"Enter your surname"<<std::endl;
                std::string surname;
                std::cin>>surname;
                bool DentistFound = false;
                for (int i=0; i<_dentists.size(); i++)
                {
                    if((_dentists[i]->getName()==name)&&(_dentists[i]->getSurname()==surname))
                    {
                        //dodati readAppointments void ReadAppointments(name, surname);
                        // je li ovdje ide readMedRecords
                        ReadPatients();
                        _dentists[i]->readMedicalRecords();
                        _dentists[i]->ReloadSchedule();
                        DentistFound=true;
                        bool quit=false;
                        while (!quit)
                        {
                        std::cout<<"Main menu:  Press number for the option you want to choose, press 0 to exit"<<std::endl;
                        std::cout<<"\n";
                        std::cout<<" 1. List patients\n 2. Add patient\n 3. Write Medical Record\n 4. Make appointment\n 5. Cancel Appointment\n 6. Show Medical Report for patient\n 7. Show schedule"<<std::endl;
                        std::cin>>input;

                            if (input==0)
                            {
                                quit=true;
                            }
                            else if(input==1)
                            {
                                _dentists[i]->showPatients();
                            }
                            else if(input==2)
                            {
                                std::cout<<"Enter the name of the patient you want to add."<<std::endl;
                                std::string n;
                                std::cin>>n;
                                std::cout<<"Enter surname"<<std::endl;
                                std::string su;
                                std::cin>>su;
                                std::cout<<"Enter mail"<<std::endl;
                                std::string m;
                                std::cin>>m;
                                std::cout<<"Enter phone number"<<std::endl;
                                int ph;
                                std::cin>>ph;

                                Patient* pat = new Patient(n,su,m,ph);
                                _dentists[i]->addPatient(pat);
                                std::cout<<"Patient successfully added!"<<std::endl;
                                std::cout<<"\n";
                                savePatients(n,su,m,ph,_dentists[i]->getName(),_dentists[i]->getSurname());
                            }
                            else if(input==3)
                            {
                                _dentists[i]->writeMedicalRecord();
                            }
                            else if(input==4)
                            {
                                _dentists[i]->makeAppointment();
                            }
                            else if(input==5)
                            {
                                _dentists[i]->cancelAppointment();
                            }
                            else if (input==6)
                            {
                                _dentists[i]->showPatientReport();
                            }
                            else if (input==7)
                            {
                                _dentists[i]->showDentistSchedule();
                            }
                            else
                            {
                                std::cout<<"Invalid input. Select one of five options."<<std::endl;
                            }
                         }
                    }
                }
                if(DentistFound == false)
                {
                     std::cout<<"Wrong inputs. Try again!"<<std::endl;
                        std::cout<<"\n";
                }
            }
        }
        else{
            std::cout<<"Invalid input. Select one of three options."<<std::endl;
        }
    }
}
    void Ordination::saveDentists(std::string name, std::string  surname, std::string  email,  int phone)
    {
        std::ofstream ofs;
        ofs.open("dentists.txt", std::ofstream::out | std::ofstream::app);
        ofs <<name<<" " <<surname<< " "<< email<<" "<<phone<<"\n";
        ofs.close();
    }

     void Ordination::savePatients(std::string name,std::string  surname, std::string  email,  int phone, std::string dentistName, std::string dentistSurname)
    {
        std::ofstream ofs;
        ofs.open("patients.txt", std::ofstream::out | std::ofstream::app);
        ofs <<name<<" " <<surname<< " "<< email<<" "<<phone<< " "<< dentistName<<" "<<dentistSurname<<"\n";
        ofs.close();
    }

    void Ordination::ReadDentists()
    {
        std::ifstream file;
        file.open("dentists.txt");
        if (!file.is_open())
            std::cout<<"Not opened!"<<std::endl;

        std::string dentistName;
        std::string dentistSurname;
        std::string dentistEmail;
        int dentistPhone;
        Schedule* s=new Schedule;
        while (file >> dentistName >> dentistSurname >> dentistEmail >> dentistPhone)
        {
            Dentist* d=new Dentist (dentistName, dentistSurname, dentistEmail, dentistPhone, s);
            _dentists.push_back(d);
        }
    }

    //void Ordination::ReadAppointments(name, surname)

    void Ordination::ReadPatients()
    {
        std::ifstream file;
        file.open("patients.txt");
        if (!file.is_open())
            std::cout<<"Didn't load any data for patients."<<std::endl;

        std::string dentistName;
        std::string dentistSurname;
        std::string patientName;
        std::string patientSurname;
        std::string patientEmail;
        int patientPhone;
        while (file >> patientName >> patientSurname >> patientEmail >> patientPhone >> dentistName >> dentistSurname)
        {
            Patient* p = new Patient (patientName, patientSurname, patientEmail, patientPhone);
            for (int i = 0; i < _dentists.size(); i++)
            {
                if ((_dentists[i]->getName() == dentistName) && (_dentists[i]->getSurname() == dentistSurname))
                {
                    _dentists[i]->addPatient(p);
                }
            }
        }
    }






