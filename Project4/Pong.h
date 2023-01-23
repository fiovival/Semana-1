#pragma once
#include<iostream>
using namespace std;
using namespace System;
class Pong
{
public:
	Pong();
	~Pong();
	void borrar();
	bool validarbordes(int ancho, int alto);
	void forzarmover();
	void mover();
	void dibujar();
	int getx();
	int gety();
	void vuelta();
	void recolocar();
private:
	int x, y, dx, dy, aceleracion;

};

Pong::Pong() {
	x = 40;
	y = 12;
	aceleracion = 0;
	do {
		dx = rand() % 3 - 1;
		//rand()%(max-min+1)+min;
		dy = rand() % (1 - (-1) + 1) + (-1);
	} while (dx == 0 || dy == 0);// no existan lineas rectas
}

Pong::~Pong()
{
}
void Pong::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
bool Pong::validarbordes(int ancho, int alto) {
	if (y + dy < 0 || y + dy>alto) { dy = -dy; }
	if (x + dx < 0 || x + dx>ancho) { return true; }
	return false;
}
void Pong::forzarmover() {
	x += dx;
	y += dy;
}
void Pong::mover() {
	if (aceleracion == 3) {
		x += dx;
		y += dy;
		aceleracion = 0;
	}
	else { aceleracion++; }
}
void Pong::dibujar() {
	Console::SetCursorPosition(x, y); cout << "*";
}
int Pong::getx() { return x; }
int Pong::gety() { return y; }
void Pong::vuelta() { dx = -dx; }
void Pong::recolocar() {
	x = 40;
	y = 12;
	do {
		dx = rand() % 3 - 1;
		//rand()%(max-min+1)+min;
		dy = rand() % (1 - (-1) + 1) + (-1);
	} while (dx == 0 || dy == 0);// no existan lineas rectas
}
