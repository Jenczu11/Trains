//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#include <Pospieszny.h>

#include "Pospieszny.h"
#include<sstream>
#include <boost/uuid/uuid_io.hpp>

using namespace std;


Pospieszny::Pospieszny(unsigned int iloscWagonow, unsigned int iloscOsobNaWagon, unsigned int przedzialZLozkami)
        : Pociag(iloscWagonow, iloscOsobNaWagon), przedzialZLozkami(przedzialZLozkami) {
    this->rodzajPociagu="Pospieszny";

}


std::string Pospieszny::toString() {
    stringstream ss;
    ss << "Pociag pospieszny " << to_string(UUID) << ", wagony - " << this->getIloscWagonow() << " Osoby/Wagon - "
       << this->getIloscOsobNaWagon() << " ilosc Lozek " << przedzialZLozkami<<"\n";
    for (auto pasazer : pasazerowie) {
        ss << pasazer->getInfo() << "\n";
    }
    return ss.str();
}

unsigned int Pospieszny::getLiczbaPrzedzialowZLozkami() {
    return przedzialZLozkami;
}
