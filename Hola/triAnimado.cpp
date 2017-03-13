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
	//TODO: Método que ejecuta una vuelta entera de la animación automáticamente
	if (objeto) {


	}
}

void TriAnimado::step() {
	// TODO: Método que solo ejecuta un paso de la animación
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