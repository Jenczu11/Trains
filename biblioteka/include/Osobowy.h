//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#ifndef PROJECTTRAINS_OSOBOWY_H
#define PROJECTTRAINS_OSOBOWY_H


#include "Pociag.h"

class Osobowy : public Pociag {
private:
    unsigned int miejsceNaRowery;
public:
    Osobowy(unsigned int iloscWagonow, unsigned int iloscOsobNaWagon, unsigned int miejsceNaRowery);
    std::string toString();
    virtual ~Osobowy(){}
    unsigned int getLiczbaMiejscNaRowery();
};
typedef std::shared_ptr <Osobowy> Osobowy_ptr;


#endif //PROJECTTRAINS_OSOBOWY_H
