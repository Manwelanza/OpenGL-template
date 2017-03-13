#include "diabolo.h"


Diabolo::Diabolo()
{
}

Diabolo::Diabolo(int vertex_number, GLdouble radius, GLdouble height):
PiramideTri(vertex_number, radius, height)
{
	pyramid_degree_offset = 180.0 / vertex_number;
}


Diabolo::~Diabolo()
{
}

void Diabolo::draw() {
	//subo los ejes en la 'y'
	glTranslated(0, height, 0);
		//giramos en 'x' para que el pico quede hacia abajo
		glRotated(90, 1, 0, 0);
			//dibujamos primera pirámide
			PiramideTri::draw();
			//giramos en 'z' para que cuadren las pirámides
			glRotated(pyramid_degree_offset, 0, 0, 1);
				PiramideTri::draw();
			glRotated(-pyramid_degree_offset, 0, 0, 1);
		glRotated(-90, 1, 0, 0);
	glTranslated(0, -height, 0);
	//bajo los ejes en la 'y'
		glTranslated(0, -height, 0);
		//giramos en 'x' para que el pico quede hacia arriba
		glRotated(-90, 1, 0, 0);
			//dibujamos primera pirámide
			PiramideTri::draw();
			//giramos en 'z' para que cuadren las pirámides
			glRotated(pyramid_degree_offset, 0, 0, 1);
				PiramideTri::draw();
			glRotated(-pyramid_degree_offset, 0, 0, 1);
		glRotated(90, 1, 0, 0);
	glTranslated(0, height, 0);
}

bool Diabolo::load(char arch[]) {
	//TODO: Implementar esta función
	return true;
}