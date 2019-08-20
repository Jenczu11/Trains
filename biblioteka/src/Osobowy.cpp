//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#include <Osobowy.h>
#include <sstream>
#include "Osobowy.h"
using namespace std;

Osobowy::Osobowy(unsigned int IloscWagonow, unsigned int IloscOsobNaWagon, unsigned int miejsceNaRowery)
:
Pociag(IloscWagonow, IloscOsobNaWagon),
miejsceNaRowery(miejsceNaRowery) {

    this->rodzajPociagu="Osobowy";
}




std::string Osobowy::toString() {
    stringstream ss;
    ss << "Pociag Osobowy, wagony - " <<this->getIloscWagonow()<<" Osoby/Wagon - "<<this->getIloscOsobNaWagon()<<" ilosc miejsc na rowery "<<miejsceNaRowery<<"\n";
    for (auto pasazer : pasazerowie) {
        ss << pasazer->getInfo() << "\n";
    }
    return ss.str();
}

unsigned int Osobowy::getLiczbaMiejscNaRowery() {
    return miejsceNaRowery;
}
