#include <iostream>
#include <Ordination.h>
#include <Dentist.h>
#include <Patient.h>
#include <vector>

using namespace std;

int main()
{

    Ordination ord;
    Dentist dentist1("jsdv", "sss", "ddd", 1234);
    Dentist dentist2("Jusuf je dentist", "sss", "ddd", 1234);

    ord.addDentist(&dentist1);
    ord.addDentist(&dentist2);

    ord.showDentists();
    std::vector <Dentist*> all_dentists= ord.getDentists();


    Patient p("Kanita je pacijent", "Koric", "ddd", 1234);
    dentist1.addPatient(&p);
    dentist1.showPatients();
    //dentist1.addPatient(&p);
    Patient p2("Kanita", "Koric", "ddd", 1234);
    dentist1.addPatient(&p2);

    dentist1.writeMedicalRecord();




    return 0;
}
