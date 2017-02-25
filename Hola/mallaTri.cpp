#include "mallaTri.h"


MallaTri::MallaTri()
{
}

MallaTri::MallaTri(int vertex_number, GLdouble radius) {
	numDat = vertex_number;
	double angle = 0;
	//Como avanza el calculo de puntos en el circulo (2 pi radianes / el numero de puntos que quieras en el circulo)
	double angle_step = 2 * PI / (double)vertex_number; 
	//Inicializa los vertices
	vertices = new PVec3[vertex_number];
	for (int i = 0; i < vertex_number; i++) {
		vertices[i] = PVec3(
			radius * cos(angle),
			radius * sin(angle),
			0);
		angle += angle_step;
	}

	//Inicializa las normales
	normales = new PVec3[vertex_number];
	for (int i = 0; i < vertex_number; i++)
		normales[i] = PVec3(0, 0, 1);
}

MallaTri::~MallaTri()
{
}

void MallaTri::draw() {
	activar();
	glColor4d(0.5, 0.5, 0.5, 0.5);
	glDrawArrays(GL_TRIANGLES, 0, numDat);
	desactivar();
}

bool MallaTri::load(char arch[]){
	//TODO: Implementar esta funci�n
	return true;
}