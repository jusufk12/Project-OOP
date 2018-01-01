#include <iostream>
#include <Ordination.h>
#include <Dentist.h>
#include <Patient.h>

using namespace std;

int main()
{

    Ordination ord;
    Dentist dentist1("jsdv", "sss", "ddd", 1234);
    Dentist dentist2("Jusuf je dentist", "sss", "ddd", 1234);

    ord.addDentist(&dentist1);
    ord.addDentist(&dentist2);

    ord.showDentists();
    Patient p("Kanita je pacijent", "Koric", "ddd", 1234);
    dentist1.addPatient(&p);
    dentist1.showPatients();
    dentist1.addPatient(&p);






    return 0;
}
