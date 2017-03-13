#include "triMovil.h"


TriMovil::TriMovil(GLdouble radius) :
MallaTri(3, radius)
{
	objeto = NULL;
}


TriMovil::~TriMovil()
{
}


void TriMovil::draw() {
	glTranslated(position.x, position.y, position.z);
	glRotated(rotation, 0, 0, 1);
	MallaTri::draw();
	glRotated(-rotation, 0, 0, 1);
	glTranslated(-position.x, -position.y, -position.z);
}

void TriMovil::rotate(GLdouble angle) {
	rotation += angle;
}

void TriMovil::move(PVec3 movement) {
	position.x += movement.x;
	position.y += movement.y;
	position.z += movement.z;
}

PVec3* TriMovil::getPoints() {
	PVec3 * result = new PVec3[3];
	PVec3 normal = PVec3(0, 0, 1);
	for (int i = 0; i < 3; i++) {
		result[i] = vertices[i].rotate_against_normal_vector(normal, -rotation) + position;
	}
	return result;
}