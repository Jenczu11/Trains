//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#include <Bilet.h>

#include "Bilet.h"
#include <sstream>
using namespace std;


Bilet::~Bilet() {

}

Bilet::Bilet(const std::string rodzajPociagu, const std::string &dataWaznosci,unsigned int dlugoscTrasy) :
rodzajPociagu(rodzajPociagu),
dataWaznosci(dataWaznosci),
dlugoscTrasy(dlugoscTrasy){
    this->biletType=Klasa3();
}
//TODO: DO PRZEMYSLENIA KOSZT ZNIZKI + MOZNA DODAC TYP 1KLASA 2 KLASA ETC.

double Bilet::cena() {
    //W zaleznosci od dlugosci trasy  i rodzaju  pociagu jest liczona cena
    // Ponadto w zaleznosci od biletu jest liczona znizka
    double koszt=0;
    if(rodzajPociagu=="Pospieszny")
    {
        koszt=(double)dlugoscTrasy*0.6;
    }
    else if(rodzajPociagu=="Osobowy")
    {
        koszt=(double)dlugoscTrasy*0.4;
    }
    if(getBiletType()=="Klasa1")
    {
        koszt=koszt*(1-(biletType.getDiscount()));
    }
    if(getBiletType()=="Klasa2")
    {
        koszt=koszt*(1-(biletType.getDiscount()));
    }

    return koszt;
}

 unsigned int Bilet::getDlugoscTrasy() {
    return dlugoscTrasy;
}

std::string Bilet::getRodzajPociagu() {
    return rodzajPociagu;
}

std::string Bilet::getDataWaznosci() {
    return dataWaznosci;
}

std::string Bilet::biletInfo() {
    stringstream ss ;
    ss<<"Bilet na pociag: "<<rodzajPociagu<<endl<<
    "Data Waznosci: "<<dataWaznosci<<endl<<
    "Ilosc Kilometrow: "<<dlugoscTrasy<<endl<<
    "Cena za bilet: "<<cena()<<" zl"<<endl;
    return ss.str();
}

Bilet::Bilet(const std::string rodzajPociagu, const std::string &dataWaznosci,unsigned int dlugoscTrasy, const BiletType &biletType) :
        rodzajPociagu(rodzajPociagu),
        dataWaznosci(dataWaznosci),
        dlugoscTrasy(dlugoscTrasy),
        biletType(biletType){}

std::string Bilet::getBiletType()  {
/*
 * Getter zwraca nam tym bilet w formie stringa.
 */
   return biletType.getBiletType();

}

void Bilet::setBiletType(const BiletType &biletType) {
    /*
     * Setter za wartosc parametru przyjmuje konstruktor odpowiedniej klasy tutaj moga to byc konstruktory:
     * "Klasa1()" , "Klasa2()", "Klasa3()"
     * Poprawne wywolanie funkcji to np.:
     * Bilet->setBiletType(Klasa3());
     */
    Bilet::biletType = biletType;
}
