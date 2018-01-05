#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


class Schedule
{
    public:
        Schedule();
        virtual ~Schedule();
        bool addAppointment(std::string patient, unsigned timeslot, unsigned day);
        bool removeAppointment (unsigned timeslot, unsigned day);
        bool AppointmentFree(unsigned timeslot, unsigned day);
        void showSchedule();
        void saveChangesInSchedule(std::string denName, std::string denSurname);


    protected:

    private:
        unsigned int _tableDimX;
        unsigned int _tableDimY;
        std::vector<std::vector<std::string>> _table;
};

#endif // SCHEDULE_H
