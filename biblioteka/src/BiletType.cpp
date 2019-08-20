//
// Created by Bartłomiej Jencz on 14.01.2019.
//

#include <BiletType.h>

#include "BiletType.h"

void BiletType::setBiletType(std::string biletType) {
    this -> biletType = biletType;
}

std::string BiletType::getBiletType() {
    return this -> biletType;
}

double BiletType::getDiscount() {
    return this -> discount;
}

void BiletType::setDiscount(double discount) {
    this -> discount = discount;
}
