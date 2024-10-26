#include <iostream>
#include "joc.h"

Joc::Joc(const std::string& nume1, const std::string& nume2, int pozitie1, int pozitie2, int puncte1, int puncte2)
    : p1(nume1, pozitie1, puncte1), p2(nume2, pozitie2, puncte2),
       suprafata(p1, p2), scor(p1, p2), moment(p1, p2, suprafata) {}

void Joc::start(){
    std::cout<<"\n";
    std::cout<<"Incepe jocul! Mult succes ambilor jucatori!\n\n";
    suprafata.suprafata_noua();
    suprafata.afisare_suprafata_actuala();
    continua();  
}

void Joc::continua(){
    std::cout<<"Jucatorul p1: ";
    p1.alegere_mutare();
    std::cout<<"Jucatorul p2: ";
    p2.alegere_mutare();
    suprafata.suprafata_noua();
    suprafata.afisare_suprafata_actuala();
    if(verificare_moment_lupta(p1.pozitie_actuala(), p2.pozitie_actuala())){
        int verif=moment.moment_al_jocului();
        if(verif==0){
            operator<<(std::cout, scor);
            suprafata.resetare_suprafata();
            suprafata.suprafata_noua();
            suprafata.afisare_suprafata_actuala();
        }else{
            continua();
        }
    }else continua();
    
    if(verificare_meci_incheiat(p1.scor_actual(), p2.scor_actual())){
    }else{
        continua();
    }
    
}

bool Joc::verificare_moment_lupta(int poz1, int poz2){
    if(poz2-poz1==1){
        return true;
    }else return false;
}

bool Joc::verificare_meci_incheiat(int puncte1, int puncte2){
    if(puncte1==5 || puncte2==5){
        if(puncte1==5){
        std::cout<<"Felicitari! Jucatorul 1 castiga Aurul!\n";
        }else{
            std::cout<<"Felicitari! Jucatorul 2 castiga Aurul!\n";
        }
        return true;
    }else return false;
}