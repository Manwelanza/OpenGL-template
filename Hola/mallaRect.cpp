#include "mallaRect.h"


MallaRect::MallaRect(GLdouble width, GLdouble height, Color4 color_)
{
	textura = NULL;
	numDat = 4;
	normales = new PVec3[1];
	normales[0] = PVec3(0.0, 0.0, 1.0);
	vertices = new PVec3[4];
	coordText = new CTex2[4];
	coordText[0] = CTex2(0, 0);
	coordText[1] = CTex2(0, 1);
	coordText[2] = CTex2(1, 0);
	coordText[3] = CTex2(1, 1);
	color = color_;
	createPoints(width, height);
}

void MallaRect::createPoints(GLdouble width, GLdouble height) {
	vertices[0] = PVec3(0, 0, 0);
	vertices[1] = PVec3(0, height, 0);
	vertices[2] = PVec3(width, 0, 0);
	vertices[3] = PVec3(width, height, 0);
}

MallaRect::~MallaRect()
{
}

void MallaRect::draw() {
	activar();
	glNormal3d(normales[0].x, normales[0].y, normales[0].z);
	glColor4d(color.r, color.g, color.b, color.a);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numDat);
	desactivar();
}

void MallaRect::resize(int width, int height) {
	setSize(width, height);
}

void MallaRect::activar() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	if (textura) {
		textura->activar();
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_DOUBLE, 0, coordText);
	}
}

void MallaRect::desactivar() {
	glDisableClientState(GL_VERTEX_ARRAY);
	if (textura) {
		textura->desactivar();
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	
}

bool MallaRect::load(char arch[]) {
	//TODO: Implementar esta función
	return true;
}

void MallaRect::setSize(GLdouble width, GLdouble height) {
	createPoints(width, height);
}

