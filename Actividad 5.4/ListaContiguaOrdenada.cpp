#include "ListaContiguaOrdenada.h"



int ListaContiguaOrdenada::buscarPosicion(int valorABuscar, int posicionInicioSublista, int posicionFin)
{
	assert(posicionInicioSublista >= 0 && posicionInicioSublista < this->getN());
	assert(posicionFin >= 0 && posicionFin < this->getN());
	assert(posicionInicioSublista <= posicionFin);

	if (posicionFin - posicionInicioSublista < 2) {			// If we ended up with 2 elements
		if (valorABuscar <= this->getValor(posicionInicioSublista))	// If number is smaller or equal to first, return position there
			return posicionInicioSublista;
		else if (valorABuscar <= this->getValor(posicionFin))		// If not, if it's at least smaller than the second, return position
			return posicionFin;
		else														// Else, it's greater than both, so return position after both
			return posicionFin + 1;
	}


	int posicionHalf = posicionInicioSublista + ((posicionFin - posicionInicioSublista) / 2); // Find middle of array

	if (valorABuscar == this->getValor(posicionHalf))	// Check if middle number is number to be found
		return posicionHalf;
	else if (valorABuscar < this->getValor(posicionHalf))	// If number is smaller, check in the left half
		return this->buscarPosicion(valorABuscar, posicionInicioSublista, posicionHalf - 1);
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
	int tmp_i = this->buscarPosicion(elementoABuscar, 0, this->getN() - 1);

	if (this->getValor(tmp_i) == elementoABuscar)
		return tmp_i;
	else
		return -1;
}



void ListaContiguaOrdenada::eliminar(int elementoAEliminar)
{
	int tmp_i = this->buscarPosicion(elementoAEliminar, 0, this->getN() - 1);

	assert(this->getValor(tmp_i) == elementoAEliminar);
	
	ListaContigua::eliminar(tmp_i);
}