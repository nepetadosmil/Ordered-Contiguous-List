#pragma once
#include "ListaContigua.h"

// Lista que siempre se mantiene ordenada de menor a mayor
class ListaContiguaOrdenada : public ListaContigua
{

public:

	// Inserta un elemento en la posicion adecuada para que la lista siga ordenada
	// Par�metro: el nuevo elemento a insertar
	// Complejidad temporal: O(n) -O(lgn) para buscar la posicion adecuada y O(n) para insertar el elemento ah�-
	// Complejidad espacial: O(n) -O(lgn) para buscar la posicion adecuada y O(n) para insertar el elemento ah�-
	void insertar(int nuevoValor);

	// Busca la posici�n de un elemento en la ListaContigua
	// Par�metro: el elemento a buscar
	// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal y espacial: O(lgn), pues llama a buscarPosicion()
	int buscar(int elementoABuscar);

	// Elimina un elemento de la lista sin necesidad de dar su posici�n. Lo busca primero
	// con b�squeda binaria
	// Par�metro: elemento a eliminar
	// Precondici�n: elementoAEliminar existe
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(lgn), porque llama a buscarPosicion()
	void eliminar(int elementoAEliminar);

private:

	// Busca, mediante la b�squeda binaria recursiva, un elemento en una sublista de la lista actual. 
	// Si no existe, devuelve la posici�n en que deber�a ser insertado para mantener la lista ordenada
	// Par�metros:
	// - valorABuscar: el elemento que se quiere buscar entre lista[inicio] y lista[nSublista-1] (ambos inclusive)
	// - inicio: posicion de inicio de la sublista, dentro de la lista actual
	// - nSublista: n�mero de posiciones (a contar desde inicio, inclusive) que mide la sublista en donde buscar
	// Retorno: si lo encuentra, devuelve su posici�n. Si no lo encuentra, devuelve la 
	// posicion en que deber�a ser insertado para mantener ordenada a la lista (de 0 a m),
	// siendo m el tama�o de la sublista (posicionFinSublista-posicionInicioSublista+1)
	// Precondiciones:
	// - posicionInicioSublista pertenece a [0,n-1]
	// - posicionFinSublista pertenece a [0,n-1]
	// - posicionInicioSublista <= posicionFinSublista
	// Complejidad temporal y espacial: O(lgm), tal como calculamos en la actividad 3.5 
	int buscarPosicion(int valorABuscar, int posicionInicioSublista, int posicionFinSublista);
};

