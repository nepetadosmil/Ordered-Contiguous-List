#include "ListaContiguaOrdenada.h"



int ListaContiguaOrdenada::buscarPosicion(int valorABuscar, int posicionInicioSublista, int posicionFin)
{
	assert(posicionInicioSublista >= 0 && posicionInicioSublista <= this->getN());
	assert(posicionFin >= 0 && posicionFin < this->getN());
	assert(posicionInicioSublista <= posicionFin);
	
	if (posicionInicioSublista == this->getN())					// If we're at the last element of the list
		if (valorABuscar <= this->getValor(this->getN() - 1))		// If number is smaller or equal to last element, insert there
			return this->getN() - 1;
		else														// If not, insert after it
			return this->getN();

	if (posicionFin == posicionInicioSublista)					// If we ended up at one element only
		if (valorABuscar <= this->getValor(posicionInicioSublista))	// If number is smaller or equal to it, insert there
			return posicionInicioSublista;
		else														// If not, insert after it
			return posicionInicioSublista + 1;


	int posicionHalf = posicionInicioSublista + ((posicionFin - posicionInicioSublista) / 2); // Find middle of array

	if (valorABuscar == this->getValor(posicionHalf))	// Check if middle number is number to be found
		return posicionHalf;

	if (valorABuscar < this->getValor(posicionHalf))	// If number is smaller, check in the left half
		return this->buscarPosicion(valorABuscar, posicionInicioSublista, posicionHalf);
	else												// If number is larger, check in the right half
		return this->buscarPosicion(valorABuscar, posicionHalf + 1, posicionFin);
}



void ListaContiguaOrdenada::insertar(int nuevoValor)
{
	if (this->getN() == 0) // List is empty
		ListaContigua::insertar(0, nuevoValor);
	else
		ListaContigua::insertar(this->buscarPosicion(nuevoValor, 0, this->getN() - 1), nuevoValor);
}



int ListaContiguaOrdenada::buscar(int elementoABuscar)
{
	int tmp_i = this->buscarPosicion(elementoABuscar, 0, this->getN());

	if (this->getValor(tmp_i) == elementoABuscar)
		return tmp_i;
	else
		return -1;
}



void ListaContiguaOrdenada::eliminar(int elementoAEliminar)
{
	int tmp_i = this->buscarPosicion(elementoAEliminar, 0, this->getN());

	assert(this->getValor(tmp_i) == elementoAEliminar);
	
	ListaContigua::eliminar(tmp_i);
}