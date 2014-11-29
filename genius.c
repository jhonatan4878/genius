/*
 *  Jogo Genius versão 1.0
 *  Jhonatan Oliveira 
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int i = 0;	
int fase = 0;
int acerto = 0;
int tempo = 1000;

void informanumero(int k[]);
void errou();
void acertou();
void mostranumero(int v[]);
void geranumero(int v[]);
void inicia();

int v[1000];
int k[1000];

int main(){
	
	srand(time(NULL));
	inicia();
	geranumero(v);		

	getch();
	return 0;
}

void inicia(){
	int l, i = 0;
	char SYSTEM[][10] = {"COLOR 2A", "COLOR 3A", "COLOR 6A", "COLOR 5A", "COLOR 8A",\
						 "COLOR 1A", "COLOR 9A", "COLOR 7A", "COLOR 8A", "COLOR 4A",\
						 "COLOR 6A", "COLOR 2A", "COLOR 5A", "COLOR 1A", "COLOR 8A", "COLOR 0A"};
	for(l = 300; l < 675; l+= 25){	
		printf("CARREGANDO O JOGO...");
		system(SYSTEM[i++]);
		Beep(l,l);		
		system("CLS");
	}
	system(SYSTEM[i]);
	Sleep(1000);
	printf("BEM VINDO AO GENIUS :) Pressione uma tecla para iniciar ");	
	getch();
	Sleep(1500);
	system("CLS");
}

void geranumero(int v[]){
			
	v[i] = rand() % 5;		
	mostranumero(v);
	
}

void mostranumero(int v[]){	
	int j;
	
	for(j = 0; j <= i; j++){		
		switch(v[j]){		
			case 0:		
				printf("%d ", v[j]);
				system("COLOR 0A");
				Beep(400, 150);
				break;
			case 1:								
				printf("%d ", v[j]);
				system("COLOR 1A");			
				Beep(600, 150);
				break;
			case 2:								
				printf("%d ", v[j]);
				system("COLOR 2A");			
				Beep(800, 150);
				break;		
			case 3:		
				printf("%d ", v[j]);
				system("COLOR 3A");
				Beep(1000, 150);
				break;
			case 4:								
				printf("%d ", v[j]);
				system("COLOR 4A");			
				Beep(1200, 150);
				break;											
		}
		Sleep(tempo);
		system("CLS");
	}	
	
	informanumero(k);	
}
	
void informanumero(int k[]){
	system("COLOR 07");
	int j;
	char ch;
	for(j = 0; j <= i; j++){				
		ch = getch();
		
		k[j] = ch-48;
		system("CLS");
		
		if(v[j] != k[j]){		
			errou();
			break;
		}
		else{
			switch(k[j]){			
			case 0:					
				Beep(400, 150);
				break;
			case 1:								
				Beep(600, 150);
				break;
			case 2:							
				Beep(800, 150);
				break;		
			case 3:		
				Beep(1000, 150);
				break;
			case 4:							
				Beep(1200, 150);
				break;	
			}
		}
	}
	
	if(j > i)
		acertou();	
}

void acertou(){
	i++;
	acerto++;
	printf("Voce acertou \n\n");		
	system("COLOR 3A");			
	Beep(700, 700);
		
	if(acerto >= 3){	
	
		printf("Fase %d %d\n\n", fase+2, tempo);	
		acerto = 0;
		fase++;
		if(tempo > 175)
		tempo -= 75;
	}
	Sleep(1500);
	system("CLS");
	geranumero(v);
}	

void errou(){
	i = 0;
	acerto = 0;
	fase = 0;
	tempo = 1000;
			
	printf("Voce errou \nFase 1\n");		
	system("COLOR 4A");	
					
	Beep(900, 700);
	Sleep(1500);
	
	system("CLS");
	geranumero(v);

}


