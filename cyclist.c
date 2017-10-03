/*EP2 - MAC0422 Sistemas Operacionais
Guilherme Feulo do Espirito Santo       6431749
Sergio Rosendo                          xxxxxxx */

#include "cyclist.h"
#include "error.h"

Cyclist *init_cyclist(int cycId) {
  
	Cyclist *c = (Cyclist*) emalloc(sizeof(Cyclist));
	c->points = 0;
  	//c->points_placing = -1;
  	//c->placing = -1;
  	c->lap = 0;
  	c->speed = 30;
  	c->id = cycId;
	c->index = cycId;
	c->elapsed=0;
	c->broke;  
  //	c->accident_lap = -1;
  //	c->accident_placing = -1;
  //	c->accident_points_placing = -1;

  	return c;
}


Cyclist **create_cyclists(int n){
	Cyclist **array = (Cyclist**) emalloc(n * sizeof(Cyclist*));
	for(int i=0;i<n;i++)
		array[i] = init_cyclist(i);
	return array;
}
		

void free_cyclists(Cyclist **cyclists, int n){
	
	for(int i = 0;i<n;i++)
		free(cyclists[i]);
	free(cyclists);

}

int flip(){
	int i = rand() % 100;
	return i;
}

int break_cyclist(){
if (flip()<1)
	return 1;
else
	return 0;
}

int speed_cyclist(int last_speed){
	if(last_speed==30){
		if (flip() <70)
			return 60;
		else
			return 30;
	}
	else{
		if(flip()<50)
			return 60;
		else
			return 30;
	}		
}
//void calculate_raced_cyclists(Cyclist** cyclists, int n, int d){

//	for(int i=0; i<n; i++)
//		cyclists[i]->elapsed = cyclists[i]->lap*d+
//}


//int order_pos_cyclists(const void *a, const void *b){

//	return ((Cyclist*) b)-> - ((Cyclist*)b)->postion;
//{

