#ifndef TOOTH_H
#define TOOTH_H
#include <string>
class Tooth
{
    public:
        Tooth(std::string jaw, std::string side, int position);
        Tooth();
        virtual ~Tooth();

        void setJaw(std::string jaw);
        void setPosition(int position);
        void setSide(std::string side);

    protected:

    private:
    std::string _jaw;
    std::string _side;
    int _position;
};

#endif // TOOTH_H
