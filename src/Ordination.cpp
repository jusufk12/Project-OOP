#include "Ordination.h"
#include <algorithm>
#include <iostream>

Ordination::Ordination()
{
    //ctor
}

Ordination::~Ordination()
{
    //dtor
}

void Ordination::addDentist(Dentist* d)
{
    if(!hasDentist(d))
    {
         _dentists.push_back(d);
    }
   else{
    std::cout<<"Doraditi ovu funksciju za else"<<std::endl;
   }
}

void Ordination::showDentists()
{
    std::cout<<"registered are following dentists:"<<std::endl;
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

std::vector<Dentist*> Ordination::getDentists ()
{
    return _dentists;
}

void Ordination::menu()
{
    int input;
    while (input!=0)
    {
        //ReadDentists();
            if(_dentists.size() == 0)
            {
                std::cout<<"There are no dentists in system."<<std::endl;
                std::cout<<"Press 1 to register, press 0 to exit: ";
                std::cin>>input;
                if(input == 0)
                {
                    break;
                }
                else
                {
                    Schedule s;
                    std::string name, surname, mail;
                    int phone;
                    std::cout<<"Input your name: "<<std::endl;
                    std::cin>>name;
                    std::cout<<"Input your surname: "<<std::endl;
                    std::cin>>surname;
                    std::cout<<"Input your mail: "<<std::endl;
                    std::cin>>mail;
                    std::cout<<"Input your phone: "<<std::endl;
                    std::cin>>phone;
                    Dentist dentist1 (name, surname, mail, phone, &s);
                    addDentist(&dentist1);
                    showDentists();

                    saveDentists(name, surname, mail, phone);

                    bool quit=false;
                    while (!quit)
                    {

                    std::cout<<"Main menu:  Press number for the option you want to choose"<<std::endl;
                    std::cout<<"\n";
                    std::cout<<"1. List patients\n 2. Add patient\n 3. Write Medical Record\n 4. Make appointment\n 5. Cancel Appointment\n 6. Show Medical Report for patient"<<std::endl;
                    std::cin>>input;

                        if (input==0)
                        {
                            quit=true;
                        }
                        else if(input==1)
                        {
                            dentist1.showPatients();
                        }
                        else if(input==2)
                        {
                            std::cout<<"Enter the name of the patient you want to add."<<std::endl;
                            std::string n;
                            std::cin>>n;
                            std::cout<<"Enter surname"<<std::endl;
                            std::string s;
                            std::cin>>s;
                            std::cout<<"Enter mail"<<std::endl;
                            std::string m;
                            std::cin>>m;
                            std::cout<<"Enter phone number"<<std::endl;
                            int ph;
                            std::cin>>ph;
                            Patient patient1(n,s,m,ph);
                            dentist1.addPatient(&patient1);
                        }
                        else if(input==3)
                        {
                            dentist1.writeMedicalRecord();
                        }
                        else if(input==4)
                        {
                            dentist1.makeAppointment();
                        }
                        else if(input==5)
                        {
                            dentist1.cancelAppointment();
                        }
                        else if (input==6)
                        {
                            dentist1.savePatientReport();
                        }
                        else
                        {
                            std::cout<<"Invalid input. Select one ofCreateMedRecord five options."<<std::endl;
                        }
                     }
                }
            }
            else
            {
                showDentists();
                std::cout<<"Choose one of the dentists listed."<<std::endl;
                std::cout<<"Enter your name"<<std::endl;
                std::string name;
                std::cin>>name;
                std::cout<<"Enter your surname"<<std::endl;
                std::string surname;
                std::cin>>surname;

                for (int i=0; i<_dentists.size(); i++)
                {
                    if((_dentists[i]->getName()==name)&&(_dentists[i]->getSurname()==surname))
                    {
                                 bool quit=false;
                    while (!quit)
                    {
                    std::cout<<"Main menu:  Press number for the option you want to choose, press 0 to exit"<<std::endl;
                    std::cout<<"\n";
                    std::cout<<" 1. List patients\n 2. Add patient\n 3. Write Medical Record\n 4. Make appointment\n 5. Cancel Appointment\n 6. Show Medical Report for patient"<<std::endl;
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
                            std::string s;
                            std::cin>>s;
                            std::cout<<"Enter mail"<<std::endl;
                            std::string m;
                            std::cin>>m;
                            std::cout<<"Enter phone number"<<std::endl;
                            int ph;
                            std::cin>>ph;
                            Patient patient1(n,s,m,ph);
                            _dentists[i]->addPatient(&patient1);
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
                            _dentists[i]->savePatientReport();
                        }
                        else
                        {
                            std::cout<<"Invalid input. Select one ofCreateMedRecord five options."<<std::endl;
                        }
                     }
                    }
                }


            }

    }
}
    void Ordination::saveDentists(std::string name,std::string  surname, std::string  email,  int phone)
    {
        std::ofstream ofs;
        ofs.open("dentists.txt", std::ofstream::out | std::ofstream::app);
        ofs <<name<<" " <<surname<< " "<< email<<" "<<phone<<"\n";
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
    while (file >> dentistName >> dentistSurname >> dentistEmail >> dentistPhone)
    {
        Schedule s;
        Dentist dentist (dentistName, dentistSurname, dentistEmail, dentistPhone, &s);
        _dentists.push_back(&dentist);
    }
    }






