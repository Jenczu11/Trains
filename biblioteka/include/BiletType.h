//
// Created by Bartłomiej Jencz on 14.01.2019.
//

#ifndef PROJECTTRAINS_BILETTYPE_H
#define PROJECTTRAINS_BILETTYPE_H


#include <string>

class BiletType {
public:
    void  setBiletType(std::string biletType);
    std::string getBiletType();
    double  getDiscount();
    void setDiscount(double discount);
private:
    double discount;
    std::string biletType;

};


#endif //PROJECTTRAINS_BILETTYPE_H
