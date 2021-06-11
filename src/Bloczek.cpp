
#include "Bloczek.hh"

Bloczek::Bloczek(int id, PzG::LaczeDoGNUPlota &Lacze, Wektor3D pozycja) : Lacze(Lacze)
{
    kat=0;
    this->id = id;
    orginal.set_nazwa("dat/korpus" + std::to_string(id) + ".dat");

    Lacze.DodajNazwePliku(orginal.get_nazwa().c_str(), PzG::RR_Ciagly, 2);
  
    kopia = orginal;

    kopia.przesun(pozycja);
    

   

    this->droga = this->droga + pozycja;
}

void Bloczek::przesun(double droga)
{
    Wektor3D droga_o;
    droga_o[0] = droga * cos(kat * M_PI / 180);
    droga_o[1] = droga * sin(kat * M_PI / 180);
    this->droga = this->droga + droga_o;
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}

void Bloczek::obrot_z(double kat)
{
    this->kat += kat;
    Macierz3x3 nowa;
    obr = nowa * mac_obr_z(this->kat);
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}
void Bloczek::obrot_x(double kat)
{
    this->kat += kat;
    Macierz3x3 nowa;
    obr = nowa * mac_obr_x(this->kat);
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}
void Bloczek::obrot_y(double kat)
{
    this->kat += kat;
    Macierz3x3 nowa;
    obr = nowa * mac_obr_y(this->kat);
    kopia.translacja(obr);
    kopia.przesun(this->droga);
}

void Bloczek::zapisz()
{
    kopia.zapisz();

}

void Bloczek::sterowanie()
{
    
    double droga;
    double kat;
    char opcja;

    do
    {
    zapisz();
    cout << "Menu sterowania: \np - przesuniecie,\no - obrot o kat w stopniach\nm - wyswietl menu\n";
    cin >> opcja;
    /* o - obrot bryly o zadana sekwencje katow \n
       t- powtorzenie poprzedniego obrotu \n
       r - wyswietlanie macierzy rotacji \n
       p - przesuniecie prostokata o zadany wektor \n
       w - wyswietlenie wspolrzednych wierzcholkow \n 
       s - sprawdzanie dlugosci przeciwleglych bokow \n
       m - wyswietl menu \n
       k - koniec dzialania programu \n
    */   
    std::string strumien;
   
    
        
    
        switch (opcja)
        {
        case 'p':
            cout << "Podaj droge :";
            cin >> droga;
            okresl_droge(droga);
            Lacze.DodajNazwePliku("dat/droga.dat", PzG::RR_Ciagly, 2);
            for (int i = 0; i < droga; i++)
            {
                kopia = orginal;
                przesun(1);
                zapisz();
                Lacze.Rysuj();
            }
        
        Lacze.UsunOstatniaNazwe();
            break;
        case 'o':
        {
            cout << "Twoj wybor to o - obrot bryly w zadanej sekwencji katow, \nPodaj sekwencje oznaczen osi i katy w stopniach:\n";
            double tablica_obrotow[100];
            char os;
            std::string strumien;
            long int powtorzenia = 0;
            do
            {
                cin >> os;
                if(os == '.')
                {
                    break;
                }
                cin >> tablica_obrotow[powtorzenia];
                if(os != 'x' && os != 'y' && os != 'z')
                {
                    cout << "Zle oznaczenie osi, wprowadz jeszcze raz";
                    cin >> os;
                    cin >> tablica_obrotow[powtorzenia];
                }
                powtorzenia++;
                strumien += os;
            }
            while(os != '.');
           
            
            cout << "Ile razy sekwencja ma zostac powtorzona ?\n";
            int ilosc_powtorzen;
            cin >> ilosc_powtorzen;
            for (int i = 0; i < ilosc_powtorzen; i++)
            {
                for(long unsigned int j = 0; j < strumien.length(); ++j)
                {   
                    os = strumien[j];
                    kat = tablica_obrotow[j];
                
                    
                    if (kat > 0 && os =='x')
                    {   
                        kopia = orginal;
                        for (int k = 0; k < kat; k++)
                        {
                            obrot_x(1);
                            zapisz();
                            Lacze.Rysuj();
                            usleep(CZAS);
                        }
                        
                        
                    }   
                    else if (kat > 0 && os == 'y')
                    {
                        kopia = orginal;
                        for (int k = 0; k < kat; k++)
                        {
                            obrot_y(1);
                            zapisz();
                            Lacze.Rysuj();
                            usleep(CZAS);
                        }
                    }

                    else if (kat > 0 && os == 'z')
                    {
                        kopia = orginal;
                        for (int k = 0; k < kat; k++)
                        {
                            obrot_z(1);
                            zapisz();
                            Lacze.Rysuj();
                            usleep(CZAS);
                        }
                    }

                    else if (kat < 0 && os == 'x')
                    {
                        for (int k = 0; k > kat; k--)
                        {
                            kopia = orginal;
                            obrot_y(-kat);
                            zapisz();
                            Lacze.Rysuj();
                        }
                    }
                    else if (kat < 0 && os == 'y')
                    {
                        for (int k = 0; k > kat; k--)
                        {
                            kopia = orginal;
                            obrot_y(-kat);
                            zapisz();
                            Lacze.Rysuj();
                        }
                    }
                    else if (kat < 0 && os == 'z')
                    {
                        for (int k = 0; k > kat; k--)
                        {
                            kopia = orginal;
                            obrot_y(-kat);
                            zapisz();
                            Lacze.Rysuj();
                        }
                    }
                }
            
            }
                

            }
            break;
           
        }
    }while (opcja != 'm');
        
  
}


void Bloczek::okresl_droge(double droga)
{
    Wektor3D nastepny = kopia.get_srodek();
    nastepny[2] = 0;
    droga_drona.push_back(nastepny);
    nastepny[2] = 100;
    droga_drona.push_back(nastepny);
    nastepny[0] += droga * cos(kat * M_PI / 180);
    nastepny[1] += droga * sin(kat * M_PI / 180);
    droga_drona.push_back(nastepny);
    nastepny[2] = 0;
    droga_drona.push_back(nastepny);

    std::fstream plik;

    plik.open("dat/droga.dat", std::ios::out);
    for (int i = 0; i < (int)droga_drona.size(); i++)
    {

        plik << droga_drona[i] << std::endl;
    }
    plik.close();
}