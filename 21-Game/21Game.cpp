#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tirarDado();
int tirarTurno(int puntos);
void comprobarGanador(int puntajeU, int puntajeC, int apuestaTotal, int fichas);

main(){
	int x=1, fichas=10, dado1=0, dado2=0, apuesta=0, apuestaTotal=0, turno, puntajeU, opcion, puntajeC, turnoU, turnoC;
	srand (time(NULL));
	printf("********JUEGO CON DADOS: 21********\n");
	do{
	turno=1;
	puntajeU=0;
	opcion=1;
	puntajeC=0;
	turnoU=0;
	printf("\nDesea empezar el juego? 1/SI o Otro Valor/SALIR:");
	scanf("%d", &x);
	if(x==1){
		printf("Cuanto desea apostar?:");
		scanf("%d", &apuesta);
		fichas=fichas-apuesta;
		printf("Fichas disponibles: %d\n", fichas);
		apuestaTotal=2*apuesta;
		printf("Apuesta del computador: %d\n", apuesta);
		printf("Apuesta Total: %d\n", apuestaTotal);
		printf("\nTirando dados para determinar turno\n");
		do{
			dado1=tirarDado();
    		dado2=tirarDado();
    		turnoU=dado1+dado2;	
			printf("Usuario: Dado1: %d y Dado2: %d Total: %d\n", dado1, dado2, turnoU);
			dado1=tirarDado();
    		dado2=tirarDado();
    		turnoC=dado1+dado2;
    		printf("Computador: Dado1: %d y Dado2: %d Total: %d\n", dado1, dado2, turnoC);
		}while (turnoU==turnoC);
		
		if (turnoU> turnoC){
			printf("Tira primero: Usuario\n");
		}else{
			printf("Tira primero: Computador\n");
		}
		
		if(turnoU>turnoC){
			do{ 
			printf("\n         TURNO N: %d\n", turno);
			printf("*********USUARIO*********\n");
			printf("Desea tirar? : 1/SI o Cualquier otro valor/NO: ");
			scanf("%d", &opcion);		
			if(opcion==1){
			puntajeU=tirarTurno(puntajeU);
			}	
			if(opcion==1 && puntajeC<18){
			printf("*********COMPUTADOR*********\n");
			puntajeC=tirarTurno(puntajeC);
			}
			if(puntajeC>=18){
				printf("*********COMPUTADOR*********\n");
				printf("La CASA decidio NO jugar\n");
			}
			turno++;
		}while(puntajeU<=21 && opcion==1);
		}
		
		if(turnoC>turnoU){
			do{ 
			if(opcion==1 && puntajeC<18){
			printf("\n         TURNO N: %d\n", turno);
			printf("*********COMPUTADOR*********\n");
			puntajeC=tirarTurno(puntajeC);
			}
			if(puntajeC>=18){
				printf("*********COMPUTADOR*********\n");
				printf("La CASA decidio NO jugar\n");
			}
			printf("*********USUARIO*********\n");
			printf("Desea tirar? : 1/SI o Cualquier otro valor/NO: ");
			scanf("%d", &opcion);		
			if(opcion==1){
			puntajeU=tirarTurno(puntajeU);
			turno++;
			}	
			
		}while(puntajeU<=21 && opcion==1);
		}
		}
			
		printf("\n         PUNTAJES\n");
		printf("Puntaje USUARIO:%d\n", puntajeU);
		printf("Puntaje COMPUTADOR:%d\n", puntajeC);
		comprobarGanador(puntajeU, puntajeC, apuestaTotal, fichas);
		
		}while(x==1 && fichas>0);
	if(fichas<0){
	printf("\nUsted le debe a la casa: %d fichas\n", (-1)*fichas);
	}else{
	printf("\nUsted debe cobrar: %d fichas\n", fichas);
	}
	}
	
int tirarDado(){
	int numero=0;
	numero = rand() % 6+1;
	return numero;
}
int tirarTurno(int puntos){
	int dado1=0, dado2=0;
	if(puntos<14){
			dado1=tirarDado();
    		dado2=tirarDado();
    		puntos=puntos+dado1+dado2;
    		printf("Dado1: %d y Dado2: %d Total: %d\n",dado1, dado2, puntos);
			}else{
			dado1=tirarDado();
			puntos=puntos+dado1;
			printf("Dado1: %d Total: %d\n", dado1, puntos);
			}
			return puntos;
}
void comprobarGanador(int puntajeU, int puntajeC, int apuestaTotal, int fichas){
	if(puntajeU>puntajeC && puntajeU<=21 || puntajeC>21){
			printf("Ganador: USUARIO\n");
			printf("USUARIO GANA %d\n", apuestaTotal);
			fichas=fichas+apuestaTotal;
		}
		if(puntajeC>puntajeU && puntajeC<=21 || puntajeU>21){
			printf("Ganador: COMPUTADOR\n");
		}
}
