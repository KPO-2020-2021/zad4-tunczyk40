#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"

class Prostopadloscian : public Bryla
{

public:

Prostopadloscian(Wektor3D srodek=Wektor3D(), double x=100,double y=100, double z=100,std::string nazwa="dat/prostopadloscian.dat");
Prostopadloscian( Prostopadloscian& pr );
~Prostopadloscian(){delete wymiary;}
};







#endif 