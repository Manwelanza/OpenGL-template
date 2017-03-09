#include "escena.h"
#include <GL/freeglut.h>

//-------------------------------------------------------------------------

Escena::Escena(int width, int height, Estados modo_) :
ejes(200),
modo(modo_),
textura(Textura()),
rect(Object()),
tri(Object()),
piram(Object()),
dia(Object()),
geometry(Geometry::Instance()),
triangulo(geometry->createTriangle(3, 60)),
rectangulo(geometry->createRect(width, height)),
piramide(geometry->createPyramid(3, 100, 100)),
diabolo(geometry->createDiabolo(3, 100, 100))
{
	rect.malla = &rectangulo;
	tri.malla = &triangulo;
	piram.malla = &piramide;
	dia.malla = &diabolo;
}

//-------------------------------------------------------------------------

void Escena::init(){
	switch (modo)
	{
	case Recortar:
		recortarInit();
		break;
	case Animar:
		animarInit();
		break;
	case Collage:
		collageInit();
		break;
	case EDiabolo:
		eDiaboloInit();
		break;
	case Pruebas:
		pruebasInit();
		break;
	default:
		throw std::exception("Estado no reconocido");
		break;
	}
}

void Escena::recortarInit(){

}

void Escena::animarInit() {

}

void Escena::collageInit(){

}

void Escena::eDiaboloInit() {

}

void Escena::pruebasInit() {
	// texturas
	glEnable(GL_TEXTURE_2D);
	textura.init();
	textura.load("ray.bmp");
	rectangulo.setTexture(&textura);
	triangulo.setTexture(&textura);
	piramide.setTexture(&textura);
	diabolo.setTexture(&textura);
	glDisable(GL_TEXTURE_2D);
	// luces
}

//-------------------------------------------------------------------------

Escena::~Escena(){
   // liberar memoria y recursos 
	if (geometry) {
		delete geometry;
		geometry = NULL;
	}
}

//-------------------------------------------------------------------------

void Escena::draw(){
	switch (modo)
	{
	case Recortar:
		recortarDraw();
		break;
	case Animar:
		animarDraw();
		break;
	case Collage:
		collageDraw();
		break;
	case EDiabolo:
		eDiaboloDraw();
		break;
	case Pruebas:
		pruebasDraw();
		break;
	default:
		throw std::exception("Estado no reconocido");
		break;
	}
}

void Escena::recortarDraw(){

}

void Escena::animarDraw(){

}

void Escena::collageDraw(){

}

void Escena::eDiaboloDraw(){

}

void Escena::pruebasDraw() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	//piram.draw();
	//tri.draw();
	dia.draw();
	//rect.draw();
	glDisable(GL_TEXTURE_2D);

	ejes.draw();
}

//-------------------------------------------------------------------------

void Escena::key(unsigned char key, bool& need_redisplay) {
	bool aux_redisplay = true;
	switch (modo)
	{
	case Recortar:
		recortarKey(key, aux_redisplay);
		break;
	case Animar:
		animarKey(key, aux_redisplay);
		break;
	case Collage:
		collageKey(key, aux_redisplay);
		break;
	case EDiabolo:
		eDiaboloKey(key, aux_redisplay);
		break;
	case Pruebas:
		pruebasKey(key, aux_redisplay);
		break;
	default:
		throw std::exception("Estado no reconocido");
		break;
	}

	need_redisplay |= aux_redisplay;
}

void Escena::recortarKey(unsigned char key, bool& need_redisplay) {

}

void Escena::animarKey(unsigned char key, bool& need_redisplay){

}

void Escena::collageKey(unsigned char key, bool& need_redisplay){

}

void Escena::eDiaboloKey(unsigned char key, bool& need_redisplay){

}

void Escena::pruebasKey(unsigned char key, bool& need_redisplay) {
	switch (key) {
	case 'x':
		rotation(PVec3(1.0, 0, 0));
		break;
	case 'X':
		rotation(PVec3(-1.0, 0, 0));
		break;
	case 'y':
		rotation(PVec3(0, 1.0, 0));
		break;
	case 'Y':
		rotation(PVec3(0, -1.0, 0));
		break;
	case 'z':
		rotation(PVec3(0, 0, 1.0));
		break;
	case 'Z':
		rotation(PVec3(0, 0, -1.0));
		break;
	default:
		need_redisplay = false;
		break;
	}//switch
}

//-------------------------------------------------------------------------

void Escena::resize(int width, int height) {
	// Cambiamos el tama�o del fondo y lo centramos
	rect.resize(width, height);
	rect.posicion = PVec3(-width / 2, -height / 2, 0);
}

//-------------------------------------------------------------------------

void Escena::rotation(PVec3 angles) {
	dia.rotation(angles);
}

//-------------------------------------------------------------------------

Ejes::Ejes(GLdouble l) {
  vertices[0].set(0, 0, 0);
  vertices[1].set(l, 0, 0);
  vertices[2].set(0, 0, 0);
  vertices[3].set(0, l, 0);
  vertices[4].set(0, 0, 0);
  vertices[5].set(0, 0, l);

  colores[0].set(1, 0, 0);
  colores[1].set(1, 0, 0);
  colores[2].set(0, 1, 0);
  colores[3].set(0, 1, 0);
  colores[4].set(0, 0, 1);
  colores[5].set(0, 0, 1);
}

//-------------------------------------------------------------------------

void Ejes::draw(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertices);
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3, GL_DOUBLE, 0, colores);

  glLineWidth(2);
  glDrawArrays(GL_LINES, 0, 6); 
  glLineWidth(1);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

 /* 
  glLineWidth(2);
  glBegin(GL_LINES);
     glColor3d(1.0, 0.0, 0.0); // red
     glVertex3d(vertices[0].x, vertices[0].y, vertices[0].z);   // origin
     glVertex3d(vertices[1].x, vertices[1].y, vertices[1].z);   // x   

     glColor3d(0.0, 1.0, 0.0); // green
     glVertex3d(vertices[2].x, vertices[2].y, vertices[2].z);   // origin
     glVertex3d(vertices[3].x, vertices[3].y, vertices[3].z);	  // y

     glColor3d(0.0, 0.0, 1.0); // blue
     glVertex3d(vertices[4].x, vertices[4].y, vertices[4].z);   // origin
     glVertex3d(vertices[5].x, vertices[5].y, vertices[5].z);	  // z   
  glEnd();
  glLineWidth(1);
  */
}

//-------------------------------------------------------------------------



