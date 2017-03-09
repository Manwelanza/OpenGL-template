#include "mallaTri.h"


MallaTri::MallaTri()
{
}

MallaTri::MallaTri(int vertex_number, GLdouble radius) {
	numDat = vertex_number;
	double angle = PI / 2;
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

	//Inicializa las coordenadas de textura
	//TODO: Esto petará si vertex_number no vale 3
	coordText = new CTex2[vertex_number];
	coordText[0] = CTex2(0.5, 1);
	coordText[1] = CTex2(0, 0);
	coordText[2] = CTex2(1, 0);
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
	//TODO: Implementar esta función
	return true;
}
