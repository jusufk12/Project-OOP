#include "Schedule.h"

Schedule::Schedule()
	: _tableDimX(9)
	, _tableDimY(6)

{
	for (int x = 0; x < 10; ++x)
	{
		std::vector<std::string> newClmn;
		_table.push_back(newClmn);
		for (int y = 0; y < 7; ++y)
		{
			_table[x].push_back("-\t");
		}
	}
	_table[0][0] = "\t";
    _table[0][1] = "Mon\t";
	_table[0][2] = "Tue\t";
    _table[0][3] = "Wed\t";
    _table[0][4] = "Thu\t";
    _table[0][5] = "Fri\t";

    _table[1][0] = "9:00\t";
    _table[2][0] = "10:00\t";
    _table[3][0] = "11:00\t";
    _table[4][0] = "12:00\t";
    _table[5][0] = "13:00\t";
    _table[6][0] = "14:00\t";
    _table[7][0] = "15:00\t";
    _table[8][0] = "16:00\t";
}

Schedule::~Schedule()
{
    //dtor
}

bool Schedule::AppointmentFree(unsigned timeslot, unsigned day)
{
    if(_table[timeslot][day] == "-\t")
        return true;
    return false;
}

bool Schedule::addAppointment(std::string patient, unsigned timeslot, unsigned day)
{

    if (!AppointmentFree(timeslot,day))
        {
            return false;
        }
    else
    {
        _table[timeslot][day]=patient+"\t";
        showSchedule();
        return true;
    }
}
void Schedule::showSchedule()
{
	for (int x = 0; x < _tableDimX; ++x)
	{
		for (int y = 0; y < _tableDimY; ++y)
		{
			std::cout << _table[x][y];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Schedule::removeAppointment (unsigned timeslot, unsigned day)
{
    if (AppointmentFree(timeslot, day))
    {
        return false;
    }
    else
    {
        _table[timeslot][day]="-\t";
        showSchedule();
        return true;
    }
}

void Schedule::saveChangesInSchedule(std::string denName, std::string denSurname)
{
    std::ofstream myfile (denName+"_"+denSurname+"_schedule.txt");
    if (myfile.is_open())
    {
        for (int x = 1; x <9 ; ++x)
        {
            for (int y = 1; y < 6; ++y)
            {
                if (_table[x][y]!="-\t")
                {
                    myfile<<x<<" "<<y<<" "<<_table[x][y];
                }
            }
        }

    }
    else std::cout<<"unable, ne radi";
    myfile.close();
}

