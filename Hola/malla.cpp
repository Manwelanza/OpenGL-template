#include "malla.h"


Malla::Malla()
{
	
}


Malla::~Malla()
{
	if (vertices != NULL) {
		delete[] vertices;
		vertices = NULL;
	}
		
	if (normales) {
		delete[] normales;
		normales = NULL;
	}

	if (coordText) {
		delete[] coordText;
		coordText = NULL;
	}

	if (textura) {
		// TODO: Arreglar esto, si lo intentas borrar peta
		//delete textura;
		textura = NULL;
	}
}

void Malla::activar() {
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_DOUBLE, 0, normales); // (Tipo, Offset, PtrArray)
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
}

void Malla::desactivar() {
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}