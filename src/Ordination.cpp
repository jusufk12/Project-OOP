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

                    bool quit=false;
                    while (!quit)
                    {

                    std::cout<<"Main menu:  Press number for the option you want to choose"<<std::endl;
                    std::cout<<"\n";
                    std::cout<<"1. List patients\n 2. Add patient\n 3. Write Medical Record\n 4. Make appointment\n 5. Cancel Appointment"<<std::endl;
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
                        else
                        {
                            std::cout<<"Invalid input. Select one of five options."<<std::endl;
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
            }

    }


   /* Dentist dentist1("Amina", "sss", "ddd", 1234, &s);
    Dentist dentist2("Jusuf", "sss", "ddd", 1234, &s);

    addDentist(&dentist1);
    addDentist(&dentist2);

    Patient p("Kanita", "Koric", "ddd", 1234);
    dentist1.addPatient(&p);
    //dentist1.showPatients();
    //dentist1.addPatient(&p);
    Patient p2("Amira", "Koric", "ddd", 1234);
    dentist1.addPatient(&p2);
    //p2.saveMedRecords();

    Tooth t("upper", "right", 6);
    Medical_Record med1(260, &t);
    p2.addMedRecordInVector(&med1);

    Tooth t1("down", "left", 1);
    Medical_Record med2(263, &t1);
    //p2.addMedRecordInVector(&med2);

    Patient* p3;
    p3 = dentist1.getPatient();
    std::cout<<"Prije"<<std::endl;
    p3->addMedRecordInVector(&med2);
    std::cout<<"Prije 2"<<std::endl;
    p3->showMedRecords();
    std::cout<<"Pslije"<<std::endl;

    //dentist1.makeAppointment();
    //dentist1.makeAppointment();
    Medical_Record* med3;
    med3 = dentist1.writeMedicalRecord();
    p2.AddMedicalRecord(med3);
    p2.showMedRecords();
    dentist1.savePatientReport();
    */
}





