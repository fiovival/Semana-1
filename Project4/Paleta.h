#pragma once
#include<iostream>
using namespace std;
using namespace System;
class Paleta
{
public:
	Paleta(int ex);
	~Paleta();
	void borrar();
	void mover();
	void dibujar();
	void validarbordes(int alto);
	bool colision(int ex, int ey);
	void setdy(int edy);
private:
	int x, y, dx, dy;
	int alto;
};

Paleta::Paleta(int ex) {
	x = ex;
	y = 10;
	alto = 5;
	dy = 0;
}

Paleta::~Paleta()
{
}
void Paleta::borrar() {
	for (int i = 0; i < alto; i++) {
		Console::SetCursorPosition(x, y); cout << " ";
	}
}
void Paleta::mover() {
	y += dy;
}
void Paleta::dibujar() {
	for (int i = 0; i < alto; i++) {
		Console::SetCursorPosition(x, y + i); cout << "*";
	}
}
void Paleta::validarbordes(int alto) {
	if (y + dy<0 || y + dy + this->alto>alto) { dy = 0; }
}
bool Paleta::colision(int ex, int ey) {
	return ex == x && y <= ey && ey < y + alto;
}
void Paleta::setdy(int edy) { dy = edy; }

