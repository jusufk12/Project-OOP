#include <iostream>
#include <Ordination.h>
#include <Dentist.h>
#include <Patient.h>

using namespace std;

int main()
{

    Ordination ord;
    Dentist dentist1("jsdv", "sss", "ddd", 1234);
    ord.addDentist(&dentist1);
    ord.showDentists();
    Patient p("jsdv", "sss", "ddd", 1234);




    return 0;
}
