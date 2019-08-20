//
// Created by Szymi on 11.01.2019.
//
#include <boost/test/unit_test.hpp>
#include "Pociag.h"
#include "Pospieszny.h"
#include "Osobowy.h"
#include "Pasazer.h"
#include "Bilet.h"


BOOST_AUTO_TEST_SUITE(PociagiTest)

BOOST_AUTO_TEST_CASE(TworzeniePociagow){
    Pospieszny_ptr p1=std::make_shared<Pospieszny>(3,50,40);


    BOOST_CHECK_EQUAL(p1->getIloscOsobNaWagon(),50);
    BOOST_CHECK_EQUAL(p1->getIloscWagonow(),3);
    BOOST_CHECK_EQUAL(p1->getPojemnosc(),150);
    BOOST_CHECK_EQUAL(p1->getLiczbaPrzedzialowZLozkami(),40);
    BOOST_CHECK_EQUAL(p1->przyPeronie(),0);
    BOOST_TEST_MESSAGE(p1->toString());
        Osobowy_ptr o1=std::make_shared<Osobowy>(2,50,25);
    BOOST_CHECK_EQUAL(o1->przyPeronie(),0);
    BOOST_CHECK_EQUAL(o1->getIloscWagonow(),2);
    BOOST_CHECK_EQUAL(o1->getPojemnosc(),100);
    BOOST_CHECK_EQUAL(o1->przyPeronie(),0);
    BOOST_CHECK_EQUAL(o1->getLiczbaMiejscNaRowery(),25);
    BOOST_TEST_MESSAGE(o1->toString());
}
BOOST_AUTO_TEST_CASE(DodaniePasazerowDoPociagu)
    {
        Pospieszny_ptr p1=std::make_shared<Pospieszny>(3,50,40);
        Bilet_ptr bilet1 = std::make_shared<Bilet>("Pospieszny", "11.01.2019", 120, Klasa1());
        Pasazer_ptr pas1 = std::make_shared<Pasazer>("Jan", "Kowalski", "7932418");
        pas1->dodajBilet(bilet1);
        BOOST_CHECK_EQUAL(p1->pasazerWsiada(pas1),1);
        BOOST_CHECK_EQUAL(p1->getIloscOsobWPociagu(),1);
        Bilet_ptr bilet2 = std::make_shared<Bilet>("Osobowy", "11.01.2019", 120, Klasa1());
        Pasazer_ptr pas2 = std::make_shared<Pasazer>("Jan", "Nowak", "1234567");
        BOOST_CHECK_EQUAL(p1->pasazerWsiada(pas2),0);
    }
    BOOST_AUTO_TEST_CASE(UsuwaniePasazerowZPociagu)
    {
        Pospieszny_ptr p1=std::make_shared<Pospieszny>(3,50,40);
        Bilet_ptr bilet1 = std::make_shared<Bilet>("Pospieszny", "11.01.2019", 120, Klasa1());
        Pasazer_ptr pas1 = std::make_shared<Pasazer>("Jan", "Kowalski", "7932418");
        Pasazer_ptr pas2 = std::make_shared<Pasazer>("Adam", "Nowak", "123456");
        Pasazer_ptr pas3 = std::make_shared<Pasazer>("Emil", "Nowak", "1123456");
        pas1->dodajBilet(bilet1);
        pas2->dodajBilet(bilet1);
        pas3->dodajBilet(bilet1);
        BOOST_CHECK_EQUAL(p1->pasazerWsiada(pas1),1);
        BOOST_CHECK_EQUAL(p1->pasazerWsiada(pas2),1);
        BOOST_CHECK_EQUAL(p1->pasazerWsiada(pas3),1);
        BOOST_CHECK_EQUAL(p1->getIloscOsobWPociagu(),3);
        BOOST_TEST_MESSAGE(p1->toString());
        BOOST_CHECK_EQUAL(p1->pasazerWysiada(pas2),1);
        BOOST_CHECK_EQUAL(p1->getIloscOsobWPociagu(),2);
        BOOST_TEST_MESSAGE(p1->toString());
    }

BOOST_AUTO_TEST_SUITE_END()