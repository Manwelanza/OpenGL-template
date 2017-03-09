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
	//TODO: Añadir que se le pase un punto como eje central y lo dibujo con ese centro
	MallaTri triangle = *new MallaTri(vertex_number, radius);
	triangle.draw();
}

MallaTri Geometry::createTriangle(int vertex_number, GLdouble radius) {
	return *new MallaTri(vertex_number, radius);
}

void Geometry::drawPyramid(int vertex_number, GLdouble radius, GLdouble height) {
	//TODO: Añadir que se le pase un punto como eje central y lo dibujo con ese centro
	PiramideTri pyramid = *new PiramideTri(vertex_number, radius, height);
	pyramid.draw();
}

PiramideTri Geometry::createPyramid(int vertex_number, GLdouble radius, GLdouble height) {
	return *new PiramideTri(vertex_number, radius, height);
}

// Rectangles

void Geometry::drawRect(GLdouble width, GLdouble height, Color4 color) {
	MallaRect rect = MallaRect(width, height, color);
	rect.draw();
}


MallaRect Geometry::createRect(GLdouble width, GLdouble height, Color4 color) {
	return MallaRect(width, height, color);
}

// Diabolo

void Geometry::drawDiabolo(int vertex_number, GLdouble radius, GLdouble height) {
	Diabolo dia = Diabolo(vertex_number, radius, height);
	dia.draw();
}

Diabolo Geometry::createDiabolo(int vertex_number, GLdouble radius, GLdouble height) {
	return Diabolo(vertex_number, radius, height);
}