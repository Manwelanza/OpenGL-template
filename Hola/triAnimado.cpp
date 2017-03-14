#include "triAnimado.h"
#include <thread>


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
	//if (objeto) {
		std::thread t1(&TriAnimado::doPlay, this, 10);
		t1.detach();
	//}
}

void TriAnimado::doPlay(int msdelay) {
	int i;
	for (i = 0; i < 360; i++) {
		step();
		Sleep(msdelay);
	}
}

void TriAnimado::step() {
	// TODO: Método que solo ejecuta un paso de la animación
	//if (objeto) {
		rotate(1);
	//}
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