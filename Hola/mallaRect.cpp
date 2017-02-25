#include "mallaRect.h"


MallaRect::MallaRect()
{
}

MallaRect::MallaRect(GLdouble width, GLdouble height, PVec3 color) {
	PVec3 *aux = new PVec3[4];
	aux[0] = color;
	aux[1] = color;
	aux[2] = color;
	aux[3] = color;
	init(width, height, aux);
}

MallaRect::MallaRect(GLdouble width, GLdouble height, PVec3 color [4]) {
	init(width, height, color);
}

void MallaRect::init(GLdouble width, GLdouble height, PVec3 colores_[4]) {
	numDat = 4;
	normales = NULL;
	vertices = new PVec3[4];
	colores = new PVec3[4];
	vertices[0] = PVec3(0, 0, 0);
	vertices[1] = PVec3(0, height, 0);
	vertices[2] = PVec3(width, 0, 0);
	vertices[3] = PVec3(width, height, 0);
	for (int i = 0; i < 4; i++) {
		colores[i] = colores_[i];
	}
}

MallaRect::~MallaRect()
{
	if (colores) {
		delete[] colores;
		colores = NULL;
	}
}

void MallaRect::draw() {
	activar();
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numDat);
	desactivar();
}

void MallaRect::activar() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_DOUBLE, 0, colores);
}

void MallaRect::desactivar() {
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

bool MallaRect::load(char arch[]) {
	//TODO: Implementar esta función
	return true;
}
