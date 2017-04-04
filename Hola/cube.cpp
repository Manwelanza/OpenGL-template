#include "cube.h"


Cube::Cube()
{
}

Cube::Cube(GLdouble width, Color4 color_) {
	numDat = 8;
	vertices = new PVec3[numDat];
	textura = NULL;
	vertices[0] = PVec3(width, width, width);
	vertices[1] = PVec3(-width, width, width);
	vertices[2] = PVec3(width, width, -width);
	vertices[3] = PVec3(-width, width, -width); 
	vertices[4] = PVec3(width, -width, -width);
	vertices[5] = PVec3(-width, -width, -width);
	vertices[6] = PVec3(width, -width, width); 
	vertices[7] = PVec3(-width, -width, width);
	color = color_;
}

Cube::~Cube()
{
}

void Cube::draw() {
	activar();
	//glNormal3d(normales[0].x, normales[0].y, normales[0].z);
	glColor4d(color.r, color.g, color.b, color.a);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numDat);
	glRotated(90, 0,0,1);
	glScaled(1,1,-1);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numDat);
	glScaled(1, 1, -1);
	glRotated(-90, 0, 0, 1);
	desactivar();
}

void Cube::activar() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	if (textura) {
		textura->activar();
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_DOUBLE, 0, coordText);
	}
}

void Cube::desactivar() {
	glDisableClientState(GL_VERTEX_ARRAY);
	if (textura) {
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		textura->desactivar();
	}

}