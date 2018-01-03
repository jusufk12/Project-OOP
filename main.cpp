#include <iostream>
#include <Ordination.h>
#include <Dentist.h>
#include <Patient.h>
#include <vector>

using namespace std;

int main()
{

    Ordination ord;
    Dentist dentist1("Ensar", "sss", "ddd", 1234);
    Dentist dentist2("Jusuf", "sss", "ddd", 1234);

    ord.addDentist(&dentist1);
    ord.addDentist(&dentist2);

    //ord.showDentists();
    std::vector <Dentist*> all_dentists= ord.getDentists();


    Patient p("Kanita", "Koric", "ddd", 1234);
    dentist1.addPatient(&p);
    //dentist1.showPatients();
    //dentist1.addPatient(&p);
    Patient p2("Jusuf", "Koric", "ddd", 1234);
    dentist1.addPatient(&p2);
    p2.saveMedRecords();
    //dentist1.writeMedicalRecord();
    Tooth t("upper", "right", 6);
    Medical_Record med1(260, "betmen", &t);
    p2.addMedRecordInVector(&med1);

    Tooth t1("down", "left", 1);
    Medical_Record med2(263, "betmen", &t);
    p2.addMedRecordInVector(&med2);

    p2.saveMedRecords();

    dentist1.makeAppointment();



    return 0;
}
