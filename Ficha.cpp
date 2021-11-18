#include "Ficha.h"
#include <string>

Ficha::Ficha(char simbolo){
    this->validar(simbolo);
    this->simbolo = simbolo;
}


char Ficha::getSimbolo() {
    return this->simbolo;
}


void Ficha::validar(char simbolo){
    if ((simbolo == '\0') || 
        (simbolo == ' ')) {
        std::string error = "Simbolo ingresado invalido. '" +  simbolo ;
        throw  error + "' " ;
    }    
}


bool Ficha::sonIguales(Ficha * ficha1, Ficha * ficha2){
    try {
        return (ficha1->getSimbolo() == ficha2->getSimbolo());
    } catch (...) {
        //si los punteros son nulos salta la excepcion
        return false;
    }
}


bool Ficha::estaBloqueada() {

    return (this->estado == bloqueada)
}


void Ficha::bloquear() {

    this->estado = bloqueada;
}


void Ficha::desbloquear() {

    this->estado = desbloqueada;
}