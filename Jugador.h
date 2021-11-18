#ifndef _JUGADOR_H_INCLUDED_
#define _JUGADOR_H_INCLUDED_

#include <iostream>
#include "Ficha.h"
#include "Carta.h"
#include "Lista.h"


enum estadoJugador {
    desbloqueado;
    bloqueado;
}


class Jugador {
friend class Ficha;

private:

    std::string nombreJugador;
    Ficha * fichas;
    int cantidadFichas;
    Lista<Carta *> * cartas;
    estadoJugador estado;


public:  
        Jugador(std::string nombreJugador,Ficha * fichas,int cantidadFichas);

        ~Jugador();

        void tomarCarta( Carta * );

        Carta * usarCarta( unsigned  int );

        size_t getCantidadFichas() const;

        void disminuirCantidadFichas();

        bool estaBloqueado();

        void bloquear();

        void desbloquear();
};

#endif