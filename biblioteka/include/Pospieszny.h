//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#ifndef PROJECTTRAINS_POSPIESZNY_H
#define PROJECTTRAINS_POSPIESZNY_H

#include "Pociag.h"
class Pospieszny: public Pociag {
private:
    unsigned int przedzialZLozkami;
public:
    Pospieszny(unsigned int iloscWagonow, unsigned int iloscOsobNaWagon, unsigned int przedzialZLozkami);
    virtual ~Pospieszny(){}
    std::string toString();
    unsigned int getLiczbaPrzedzialowZLozkami();


};

typedef std::shared_ptr<Pospieszny> Pospieszny_ptr;

#endif //PROJECTTRAINS_POSPIESZNY_H
