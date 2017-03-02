#include "piramideTri.h"


PiramideTri::PiramideTri()
{
}

PiramideTri::PiramideTri(int vertex_number, GLdouble radius, GLdouble height) {
	numDat = vertex_number * 3;

	GLdouble angle = PI/2;
	//Como avanza el calculo de puntos en el circulo (2 pi radianes / el numero de puntos que quieras en el circulo)
	GLdouble angle_step = 2 * PI / (GLdouble)vertex_number;
	vertices = new PVec3[vertex_number * 3];
	normales = new PVec3[vertex_number * 3];
	for (int i = 0; i < vertex_number; i++) {
		//calculamos el primer vértice de la base
		PVec3 a = PVec3(
			radius * cos(angle),
			radius * sin(angle),
			0);
		//incrementamos el ángulo y calculamos el segundo vértice de la base
		angle += angle_step;
		PVec3 b = PVec3(
			radius * cos(angle),
			radius * sin(angle),
			0);
		//por último calculamos el vértice compartido por todos los triángulos
		//(vértice de la pirámide)
		PVec3 c = PVec3(
			0,
			0,
			height);
		//calculamos la normal como el producto vectorial normalizado de dos lados del triángulo 
		PVec3 n = ((a - c).cross(b - c)).get_normalized_vector();
		
		vertices[3 * i] = a;
		vertices[3 * i + 1] = b;
		vertices[3 * i + 2] = c;
		normales[3 * i] = n;
		normales[3 * i + 1] = n;
		normales[3 * i + 2] = n;
	}

}

PiramideTri::~PiramideTri()
{
}

void PiramideTri::draw() {
	activar();
	glColor4d(1, 0.5, 0.5, 0.5);
	glDrawArrays(GL_TRIANGLES, 0, numDat);
	desactivar();
}

bool PiramideTri::load(char arch[]) {
	//TODO: Implementar esta función
	return true;
}
