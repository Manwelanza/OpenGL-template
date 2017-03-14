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
	GLfloat width;
	glGetFloatv(GL_LINE_WIDTH, &width);
	glLineWidth(5);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	MallaTri::draw();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glLineWidth(width);
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

CTex2* TriMovil::getCoordTexts(int width, int height) {
	PVec3* vertices = getPoints();
	CTex2* coordText_ = new CTex2[3];
	for (int i = 0; i < 3; i++) {
		vertices[i] += PVec3(width / 2.0, height / 2, 0);
		coordText_[i] = CTex2(vertices[i].x / width, vertices[i].y / height);
	}
	return coordText_;
}