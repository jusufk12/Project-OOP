#include "Tooth.h"

Tooth::Tooth(std::string jaw, std::string side, int position)
{
  _jaw=jaw;
  _side=side;
  _position=position;
}
Tooth::Tooth()
{

}

Tooth::~Tooth()
{
    //dtor
}


void Tooth::setJaw(std::string jaw)
{
    _jaw = jaw;
}
void Tooth::setPosition(int position)
{
    _position = position;
}
void Tooth::setSide(std::string side)
{
    _side=side;
}
std::string Tooth::getJaw()
{
    return _jaw;
}
std::string Tooth::getSide()
{
    return _side;
}
int Tooth::getPosition()
{
    return _position;
}
