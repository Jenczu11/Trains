//
// Created by Szymi on 11.01.2019.
//

#include <boost/test/unit_test.hpp>
#include "Pasazer.h"
#include "Bilet.h"
#include <iostream>
using namespace std;



BOOST_AUTO_TEST_SUITE(PasazerTesty)

    BOOST_AUTO_TEST_CASE(TworzeniePasazera){
        Pasazer_ptr pas1=std::make_shared<Pasazer>("Jan","Kowalski","7932418");
        BOOST_CHECK_EQUAL(pas1->getImie(),"Jan");
        BOOST_CHECK_EQUAL(pas1->getNazwisko(),"Kowalski");
        BOOST_CHECK_EQUAL(pas1->getPesel(),"7932418");
    }

    BOOST_AUTO_TEST_CASE(BiletTest) {
        Bilet_ptr bil1 = std::make_shared<Bilet>("Pospieszny", "11.01.2019", 120);
        BOOST_CHECK_EQUAL(bil1->getRodzajPociagu(), "Pospieszny");
        BOOST_CHECK_EQUAL(bil1->getDataWaznosci(), "11.01.2019");
        BOOST_CHECK_EQUAL(bil1->getDlugoscTrasy(), 120);
        BOOST_CHECK_EQUAL(bil1->getBiletType(),"Klasa3");
        Pasazer_ptr pas1 = std::make_shared<Pasazer>("Jan", "Kowalski", "7932418");
        BOOST_CHECK_EQUAL(pas1->getLiczbaBiletow(), 0);
        pas1->dodajBilet(bil1);
        BOOST_CHECK_EQUAL(pas1->getLiczbaBiletow(), 1);
        BOOST_REQUIRE_EQUAL(bil1->cena(),72);
        BOOST_TEST_MESSAGE(pas1->getInfo());
        cout<<pas1->getInfo();
        pas1->usunBilet(bil1);
        BOOST_CHECK_EQUAL(pas1->getLiczbaBiletow(), 0);
        cout<<pas1->getInfo();
    }

    BOOST_AUTO_TEST_CASE(BiletTestZKonstruktoremBiletType) {
        Bilet_ptr bil1 = std::make_shared<Bilet>("Pospieszny", "11.01.2019", 120, Klasa1());
        BOOST_CHECK_EQUAL(bil1->getRodzajPociagu(), "Pospieszny");
        BOOST_CHECK_EQUAL(bil1->getDataWaznosci(), "11.01.2019");
        BOOST_CHECK_EQUAL(bil1->getDlugoscTrasy(), 120);
        BOOST_CHECK_EQUAL(bil1->getBiletType(),"Klasa1");
        Pasazer_ptr pas1 = std::make_shared<Pasazer>("Jan", "Kowalski", "7932418");
        BOOST_CHECK_EQUAL(pas1->getLiczbaBiletow(), 0);
        pas1->dodajBilet(bil1);
        BOOST_CHECK_EQUAL(pas1->getLiczbaBiletow(), 1);
        BOOST_REQUIRE_EQUAL(bil1->cena(),57.6);
        BOOST_TEST_MESSAGE(pas1->getInfo());
        pas1->usunBilet(bil1);
        BOOST_CHECK_EQUAL(pas1->getLiczbaBiletow(), 0);
        cout<<pas1->getInfo();
    }
    BOOST_AUTO_TEST_CASE(BiletTestZmianaTypuBiletu)
    {   Bilet_ptr bil1 = std::make_shared<Bilet>("Pospieszny", "11.01.2019", 120, Klasa1());
        BOOST_CHECK_EQUAL(bil1->getBiletType(),"Klasa1");
        Pasazer_ptr pas1 = std::make_shared<Pasazer>("Jan", "Kowalski", "7932418");
        pas1->dodajBilet(bil1);
        BOOST_REQUIRE_EQUAL(bil1->cena(),57.6);
        BOOST_TEST_MESSAGE(pas1->getInfo());
        bil1->setBiletType(Klasa3());
        BOOST_REQUIRE_EQUAL(bil1->cena(),72);
    }



BOOST_AUTO_TEST_SUITE_END()