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
	for (int i = 0; i < vertex_number; i++) {
		vertices[3 * i] = PVec3(
			radius * cos(angle),
			radius * sin(angle),
			0);
		angle += angle_step;
		vertices[3 * i + 1] = PVec3(
			radius * cos(angle),
			radius * sin(angle),
			0);
		vertices[3 * i + 2] = PVec3(
			0,
			0,
			height);
	}

	angle = angle_step / 2;
	normales = new PVec3[vertex_number];
	for (int i = 0; i < vertex_number; i++) {
		//normal x: cos(angle)
		//normal y: sin(angle)
		//normal z: atan(height/radius)/PI
		GLdouble nz = atan(height / radius) / PI;

		//TODO: Calcular normales como es debido
		normales[i] = PVec3(0, 0, 1);

		angle += angle_step;
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
