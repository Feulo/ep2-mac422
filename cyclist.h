/*EP2 - MAC0422 Sistemas Operacionais
Guilherme Feulo do Espirito Santo	6431749
Sergio Rosendo				xxxxxxx */
// Author: Sergio Rosendo 

#ifndef _cyclist_h
#define _cyclist_h
#include <stddef.h>

typedef struct cyclist_struct {
  int points; //pontos do ciclista
  int points_pos;
  int place;
  int lap;   // volta que ele está
  int speed;
  int index; //indice no vetor de ciclistas	 
  int id;    //identificador do ciclista
  int broke; // o ciclista quebrou
  int elapsed;// distancia percorrida
  //int accident_lap; //volta que qubrou
  //int accident_placing; // local onde quebrou
  //int accident_points_placing;
} Cyclist;

Cyclist **create_cyclists(int n);
void free_cyclists(Cyclist **cyclists, int n);
int break_cyclist();
int speed_cyclist(int last_speed);
#endif
