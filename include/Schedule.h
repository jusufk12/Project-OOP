#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <string>
#include <vector>
#include <iostream>


class Schedule
{
    public:
        Schedule();
        virtual ~Schedule();
        bool addAppointment(std::string patient, unsigned day, unsigned timeslot);
        bool appointmentFree();
        void showSchedule();

    protected:

    private:
        unsigned int _tableDimX;
        unsigned int _tableDimY;
        std::vector<std::vector<std::string>> _table;
};

#endif // SCHEDULE_H
