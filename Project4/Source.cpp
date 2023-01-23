#include"Paleta.h"
#include"Pong.h"
#include<conio.h>
void main() {
	Pong* objpelota = new Pong();
	Paleta* objpaleta = new Paleta(1);
	Paleta* objpaleta1 = new Paleta(78);
	while (true) {
		objpelota->borrar();
		if (objpelota->validarbordes(80, 25)) {
			objpelota->recolocar();
		}
		objpelota->mover();
		objpelota->dibujar();

		objpaleta->borrar();
		objpaleta1->borrar();
		if (kbhit()) {
			switch (toupper(getch())) {
			case 'W': objpaleta->setdy(-1); break;
			case 'S': objpaleta->setdy(1); break;
			case 'O': objpaleta1->setdy(-1); break;
			case 'L': objpaleta1->setdy(1); break;
			}
		}
		else {
			objpaleta->setdy(0);
			objpaleta1->setdy(0);
		}
		objpaleta->validarbordes(25);
		objpaleta1->validarbordes(25);
		objpaleta->mover();
		objpaleta1->mover();
		objpaleta->dibujar();
		objpaleta1->dibujar();

		if (objpaleta->colision(objpelota->getx(), objpelota->gety()) ||
			objpaleta1->colision(objpelota->getx(), objpelota->gety())) {
			objpelota->vuelta();

			objpelota->borrar();
			if (objpelota->validarbordes(80, 25)) {
				objpelota->recolocar();
			}
			objpelota->forzarmover();
			objpelota->dibujar();
		}
		_sleep(50);
	}
	delete objpaleta;
	delete objpaleta1;
	delete objpelota;
}