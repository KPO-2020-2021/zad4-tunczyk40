#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>
using namespace std;

template <int Wymiar>
class Wektor
{
    static int wszystkie;
    static int aktualne;
    double _wsp[Wymiar];

public:
    Wektor();
    Wektor(const Wektor& wek){  
        for(int i=0; i<Wymiar;i++)
        _wsp[i]=wek._wsp[i];
        
        aktualne++;}
    ~Wektor();
    Wektor(double _wsp[Wymiar]);
    double operator[](int index) const;
    double &operator[](int index);
    Wektor<Wymiar> operator+(Wektor<Wymiar> &arg);
    Wektor<Wymiar> operator-(Wektor<Wymiar> &arg);
    void informacje();
};

template <int Wymiar>
 int Wektor<Wymiar>::wszystkie = 0;

template <int Wymiar>
 int Wektor<Wymiar>::aktualne = 0;

template <int Wymiar>
void Wektor<Wymiar>::informacje()
{
    cout << "Aktualne obiekty: " << aktualne << endl;
    cout << "Wszystkie obiekty: " << wszystkie << endl;
}

template <int Wymiar>
Wektor<Wymiar>::Wektor()
{
    for (int i = 0; i < Wymiar; i++)
        _wsp[i] = 0;
    aktualne++;
    wszystkie++;
}

template <int Wymiar>
Wektor<Wymiar>::Wektor(double _wsp[Wymiar])
{
    for (int i = 0; i < Wymiar; i++)
        this->_wsp[i] = _wsp[i];
    aktualne++;
    wszystkie++;
}

template <int Wymiar>
Wektor<Wymiar>::~Wektor()
{
    aktualne--;
}

template <int Wymiar>
double Wektor<Wymiar>::operator[](int index) const
{
    if (index > Wymiar || index < 0)
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return _wsp[index];
}

template <int Wymiar>
double &Wektor<Wymiar>::operator[](int index)
{
    if (index > Wymiar || index < 0)
    {
        std::cerr << "Indeks poza skala" << std::endl;
        exit(1);
    }
    return _wsp[index];
}

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator+(Wektor<Wymiar> &arg)
{
    Wektor<Wymiar> Wynik;
    for (int i = 0; i < Wymiar; i++)
    {
        Wynik[i] = _wsp[i] + arg[i];
    }
    return Wynik;
}

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator-(Wektor<Wymiar> &arg)
{
    Wektor<Wymiar> Wynik;
    for (int i = 0; i < Wymiar; i++)
    {
        Wynik[i] = _wsp[i] - arg[i];
    }
    return Wynik;
}

template <int Wymiar>
std::istream &operator>>(std::istream &Strm, Wektor<Wymiar> &Wek)
{
    for (int i = 0; i < Wymiar; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
    return Strm;
}

template <int Wymiar>
inline std::ostream &operator<<(std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
    for (int i = 0; i < Wymiar; i++)
    {
        Strm << Wek[i] << " ";
    }
    return Strm;
}

#endif
