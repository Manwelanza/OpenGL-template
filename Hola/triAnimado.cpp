#include "triAnimado.h"


TriAnimado::TriAnimado(int vertex_number, GLdouble radius, GLdouble turn_radius):
MallaTri(vertex_number, radius)
{
	objeto = NULL;
	velocidad = 1.0;
	radio = 5.0;
	(*this).turn_radius = turn_radius;
}


TriAnimado::~TriAnimado()
{
}

void TriAnimado::play() {
	//TODO: M�todo que ejecuta una vuelta entera de la animaci�n autom�ticamente
	if (objeto) {


	}
}

void TriAnimado::step() {
	// TODO: M�todo que solo ejecuta un paso de la animaci�n
	if (objeto) {
		

	}
}

void TriAnimado::draw() {
	glTranslated(turn_radius, 0, 0);
	glRotated(rotation_angle, 0, 0, 1);
	MallaTri::draw();
	glRotated(-rotation_angle, 0, 0, 1);
	glTranslated(-turn_radius, 0, 0);
}

void TriAnimado::rotate(GLdouble angle) {
	rotation_angle += angle;
}