#include <iostream>
#include <Ordination.h>
#include <Dentist.h>

using namespace std;

int main()
{

    Ordination ord;
    Dentist dentist1("jsdv", "sss", "ddd", 1234);
    ord.addDentist(&dentist1);
    //ord.addDentist(&dentist2);
    ord.showDentists();




    return 0;
}
