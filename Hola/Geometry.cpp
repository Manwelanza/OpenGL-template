#include <stddef.h>  // defines NULL
#include "Geometry.h"
#include <iostream>

Geometry* Geometry::_instance = NULL;

Geometry::Geometry(PVec3 eje_):
eje(eje_)
{
}

Geometry::~Geometry()
{
}

Geometry* Geometry::Instance() {
	if (!_instance)
		_instance = new Geometry();

	return _instance;
}

bool Geometry::isInitiated() {
	if (!_instance)
		return false;

	return true;
}

// Lines
void Geometry::drawLine(PVec3 origin, PVec3 destination, PVec3 color ) {
	PVec3 points[2], colors[2];
	points[0] = origin;
	points[1] = destination;
	colors[0] = color;
	colors[1] = color;

	drawLines(2, points, colors);
}

void Geometry::drawLines(int lines, PVec3 points[], PVec3 color) {
	PVec3* colors = new PVec3[lines];
	for (int i = 0; i < lines; i++) {
		colors[i] = color;
	}
		
	drawLines(lines, points, colors);
}

void Geometry::drawLines(int lines, PVec3 points[], PVec3 colors[]){
	for (int i = 0; i < lines; i++)
		points[i].add(eje);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, points);
	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_DOUBLE, 0, colors);

	glDrawArrays(GL_LINES, 0, lines);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

// Triangles
void Geometry::drawTriangle(int vertex_number, GLdouble radius) {
	//TODO: A�adir que se le pase un punto como eje central y lo dibujo con ese centro
	MallaTri triangle = *new MallaTri(vertex_number, radius);
	triangle.draw();
}

MallaTri Geometry::createTriangle(int vertex_number, GLdouble radius) {
	return *new MallaTri(vertex_number, radius);
}

void Geometry::drawPyramid(int vertex_number, GLdouble radius, GLdouble height) {
	//TODO: A�adir que se le pase un punto como eje central y lo dibujo con ese centro
	PiramideTri pyramid = *new PiramideTri(vertex_number, radius, height);
	pyramid.draw();
}

PiramideTri Geometry::createPyramid(int vertex_number, GLdouble radius, GLdouble height) {
	return *new PiramideTri(vertex_number, radius, height);
}

// Rectangles

void Geometry::drawRect(GLdouble width, GLdouble height, PVec3 color) {
	PVec3 *aux = new PVec3[4];
	aux[0] = color;
	aux[1] = color;
	aux[2] = color;
	aux[3] = color;
	drawRect(width, height, aux);
}

void Geometry::drawRect(GLdouble width, GLdouble height, PVec3 colores[4]) {
	MallaRect rect = MallaRect(width, height, colores);
	rect.draw();
}

MallaRect Geometry::createRect(GLdouble width, GLdouble height, PVec3 color) {
	PVec3 *aux = new PVec3[4];
	aux[0] = color;
	aux[1] = color;
	aux[2] = color;
	aux[3] = color;
	return createRect(width, height, aux);
}

MallaRect Geometry::createRect(GLdouble width, GLdouble height, PVec3 colores [4]) {
	return MallaRect(width, height, colores);
}