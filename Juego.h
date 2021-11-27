#ifndef _JUEGO_H
#define _JUEGO_H

#include <iostream>
#include <string>

#include "Tablero.h"
#include "Jugador.h"
#include "Carta.h"
#include "Cola.h"
#include "Interfaz.h"

class Juego {

private:
	Lista < Jugador * > * jugadores; // lista circular de jugadores
    Cola < Carta * > * mazo;
    Jugador * jugadorEnTurno; // Jugador que se encuentra jugando en el turno actual
    Jugador * ganador;
    Tablero * tablero;
    Interfaz * interfaz;
    unsigned int cantidadMaximaCartas;  // Cantidad maxima de cartas que puede tener un jugador en la mano
  	int jugadaAnterior[2][3];   // Representa las coordenadas de donde se hizo la última modificacion en el tablero

public:
	/*
	 * Post: crea un nuevo juego inicializando una Interfaz, un Jugador ganador nulo y una estructura
	 * para almacenar la jugadaAnterior. Luego pide por pantalla al usuario las dimensiones con las
	 * que desea crear el tablero, la cantidad de Jugadores y la cantidad maxima de cartas en mano
	 * con las que desea jugar
	 */
	Juego();

	/*
	 * Post: se libera memoria del heap usada para tablero, lista de jugadores, mazo de cartas
	 */
	~Juego();

	/*
	 * Pre: recibe las coordenadas del tablero donde se desea colocar la ficha
	 * Post: valida y coloca la ficha del jugador actual en el Casillero ubicado
	 * en las coordenadas del Tablero recibidas. Si el Casillero está bloqueado
	 * u ocupado lanza una excepcion
	 */
	void ponerFicha(unsigned int x, unsigned int y, unsigned int z);

	/*
	 * juega jaja
	 */
    void jugar();

	/*
	 * recibe 2 coordenadas en el tablero; el jugador es el actual
	 */
	void moverFicha(unsigned int x1, unsigned int y1, unsigned int z1,
                    unsigned int x2, unsigned int y2, unsigned int z2);

	/*
	 * Pre: recibe el número perteneciente a una carta del mazo (del 1 al 6?)
	 * Post: si el jugador no posee esa carta, no se hace nada
	 * el juego actúa según lo que haga la carta
	 */
	void activarCarta( unsigned int );


	/*
	 * Post: avanza una posicion en la lista de jugadores
	 * establece el nuevo jugadorEnTurno
	 */
 	void cambiarTurno();


	/* itera la lista de jugadores, para cada uno
	 * 		retira una carta del mazo
	 *    agrega una carta al jugador (llama a tomarCarta)
	 * post: disminuyen cartas del mazo, cada jugador toma una carta
	 */
	//void repartirCartas();

	void entregarCarta();

private:

    /*
     * Pre: recibe el número de jugador al que corresponde el nombre, por ejemplo:
     * Jugador 1: Tomás, Jugador 2: Miguel, etc.
     * Post: pide por pantalla el nombre al jugador y devuelve una cadena con dicho nombre
     */
    std::string pedirNombre(int jugadorNumero);

    /*
     * Post: pide por pantalla la cantidad de jugadores que tendra el juego. Lanza excepcion
     * si se ingresa valor inválido
     */
    unsigned int pedirCantidadJugadores();

    /*
     * Post: pide por pantalla la cantidad de fichas que tendra cada Jugador. Lanza excepcion
     * si se ingresa valor inválido
     */
    unsigned int pedirCantidadFichas();

    void bloquearSiguienteJugador();

    void bloquearFicha( int, int, int );

    void bloquearCasillero( int, int, int );

    /*
     * Post: se deshace la jugada del jugador anterior al actual (la jugada realizada
     		por el jugadorEnTurno queda intacta)
     */
    void volverJugadaAtras();

    void devolverFichaAJugadorAnterior();

};

#endif // _JUEGO_H
