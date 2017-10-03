/*EP2 - MAC0422 Sistemas Operacionais
Guilherme Feulo do Espirito Santo       6431749
Sergio Rosendo                          xxxxxxx */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include "cyclist.h"
#include "error.h"
#include <time.h>
#include <errno.h>

sem_t *arrive, *cont;
void* cyclist_thread(void * cyclist);
int** track;

void* cyclist_thread(void * cyclist);
void print_track(int d, int s);
char* print_cell(int t, int s);

int main(int argc, char **argv) {
	
	//TRATAMENTO DA ENTRADA
	set_prog_name(argv[0]);
	if (argc < 3) 
    		die("Usage: %s <speedway_lenght> <number_of_cyclists> <number_of_laps> [-d]\n", argv[0]);		

	int d = atoi(argv[1]);
	int n = atoi(argv[2]);
	int v = atoi(argv[3]);
	int debug=0;
	if(!strcmp(argv[4],"-d"))
		debug=1;
        printf("caralho\n");
	fflush(stdout);
	//INICILIZA PISTA
		track = (int**) emalloc(d*sizeof(int*));
		for(int i=0;i<d;i++)
			track[i]= (int*) emalloc(10*sizeof(int));
		for(int i=0;i<d;i++){
			for(int j=0;j<10;j++)
				track[i][j]=-1;
		}
	track[1][3]=1;
	track[3][5]=5;
	track[4][9]=13;
	track[8][0]=8;
        char temp[5];
        sprintf(temp,"%d",n-1);
	int s = strlen(temp);
	printf("%d\n\n",s);
	//INICIALIZA VETOR ARRIVE
	arrive = (sem_t*) emalloc(n*sizeof(sem_t));
	for(int i=0;i<n;i++)
		sem_init(arrive+i,0,0);
	//INCIALIZA VETOR CONT
	cont = (sem_t*) emalloc(n*sizeof(sem_t));
	for(int i=0;i<n;i++)
		sem_init(cont+i,0,0);
	//INCIALIZA SEMENTE NUMEROS ALEATORIOS PARA SORTEIO 
	srand(time(NULL));
	
	// CRIA OS N CICLISTAS
	Cyclist **cyclists = create_cyclists(n);
	
	//CRIA AS THREAD DOS CORREDORES
	pthread_t racers[n];
	for(int i=0;i<n;i++){
		if(pthread_create(racers+i, NULL,cyclist_thread, cyclists[i]))
      			die(":");
		}
        //print_track(d,s);
	//AQUI COMEÇA O LOOP DA CORRIDA

	for(int j=0; j<10;j++){	
		for(int i=0;i<n;i++)
			sem_wait(arrive+i);

		printf("\n\n");
	
		for(int i=0;i<n;i++)
			sem_post(cont+i);
	}

	// DA JOIN NAS THREAD PARA FINALIZAR
	for(int i=0; i<n ; i++){
		 if(pthread_join(racers[i], NULL))
      			die(":");
    	}
	print_track(d,s);
	//printf("\n%s\n",print_cell(13,2));
return 0;
}


//FUNÇÃO PARA A THREAD QUE REPRENTA CADA CICLISTA
void* cyclist_thread(void * cyclist){
	
	Cyclist* racer = (Cyclist*) cyclist; 
	printf("ciclista %d criado\n", racer->id);
	for(int i=0;i<10;i++){
		sem_post(arrive+racer->id);
		sem_wait(cont+racer->id);
		printf("ciclista %d volta: %d\n", racer->id, racer->lap++);
		printf("ciclista %d velocidade: %d\n", racer->id, speed_cyclist(racer->speed));
		if(break_cyclist())
			printf("ciclista %d quebrou", racer->id);
	}
	return NULL;
}
//FUNCAO IMPRIME PISTA
char* print_cell(int t, int s){
	char* a = (char*) emalloc((s+1)*sizeof(char));	
	if (t<0){
		for(int i=0;i<s;i++)
			a[i]=' ';
		a[s]='\0';
	}
	else{
		//printf("entro no else\n");	
		char temp[s+1];
		sprintf(temp,"%d",t);
		int k =strlen(temp);
		//printf("k=%d",k);
		int i=0;
		int j=0;
		while (i<(s-k)/2)
			a[i++]=' ';
		while(j<k)
			a[i++]=temp[j++];
		while(i<s)
			a[i++]=' ';
		a[i]='\0';	
			
	}	 
	return a;
}
void print_track(int d, int s){
	
	int p,k=0;
	
	while(d>0){
		if(d>45)
			p=45;
		else
			p=d;
		for(int j=0;j<10;j++){
			if(k==0)
				printf("||");
			for(int i=0;i<p;i++){
				printf("%s|",print_cell(track[45*k+i][j],s));	
			}
			if(p!=45)
				printf("|");	
			printf("\n");
			
		}
	k++;
	d=d-45;
	printf("\n\n");
	}
}



