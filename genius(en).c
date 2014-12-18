/*
 *  Game Genius version 2.2
 *  Jhonatan Oliveira
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

int stage = 0;
int countRightAnswers = 0;
int timeGame = 1000;
int limit = 2;
int score = 0;
int recordScore = 0;

typedef struct originRegister{
	int number;
	struct originRegister * next;
}TPOrigin;

TPOrigin * origin = NULL;

void defineNumber(TPOrigin * currentOrigin);
void mistake();
void right();
void showNumber();
void createNewNumber(TPOrigin * currentOrigin, int limit);
void start();
void cleanList(TPOrigin * origin);
void disableCloseButton();
void closeApplication();

int main(){	
	disableCloseButton();		
	srand(time(NULL));
	start();
	createNewNumber(origin, limit);

	return 0;
}

void start(){
	int intensity;
	int key = 0;
	char SYSTEM[][10] = {"COLOR 2A", "COLOR 3A", "COLOR 6A", "COLOR 5A", "COLOR 8A",\
			     "COLOR 1A", "COLOR 9A", "COLOR 7A", "COLOR 8A", "COLOR 4A",\
			     "COLOR 6A", "COLOR 2A", "COLOR 5A", "COLOR 1A", "COLOR 8A", "COLOR 0A"};

	for(intensity = 300; intensity < 675; intensity+= 25){	
		printf("LOADING THE GAME...");
		system(SYSTEM[key++]);
		Beep(intensity,intensity);
		system("CLS");
	}
	system(SYSTEM[key]);
	
	Sleep(1000);
	printf("WELCOME TO GENIUS :) THE GAME WILL START IN INSTANTS.\nTO EXIT, PRESS \"-1 + ENTER\"/");
	Sleep(2500);	

	system("CLS");
	printf("STAGE 1 1000\n");
	
	Sleep(1500);
	system("CLS");
}

void createNewNumber(TPOrigin * currentOrigin, int limit){
	TPOrigin * newOrigin;
	
	newOrigin = (TPOrigin * ) malloc(sizeof(TPOrigin));
	newOrigin->number = rand() % limit;

	if(currentOrigin == NULL){
		origin = newOrigin;
		origin->next = NULL;
	}
	else{
		while(currentOrigin->next != NULL)
			currentOrigin = currentOrigin->next;
		newOrigin->next = NULL;
		currentOrigin->next = newOrigin;
	}
	showNumber(origin);
}

void showNumber(TPOrigin * currentOrigin){
	while(currentOrigin != NULL){
		switch(currentOrigin->number){
			case 0:
				printf("%d ", currentOrigin->number);
				system("COLOR 0A");
				Beep(200, 150);
				break;
			case 1:
				printf("%d ", currentOrigin->number);
				system("COLOR 1A");
				Beep(250, 150);
				break;
			case 2:
				printf("%d ", currentOrigin->number);
				system("COLOR 2A");
				Beep(300, 150);
				break;
			case 3:
				printf("%d ", currentOrigin->number);
				system("COLOR 3A");
				Beep(350, 150);
				break;
			case 4:
				printf("%d ", currentOrigin->number);
				system("COLOR 4A");
				Beep(400, 150);
				break;
			case 5:
				printf("%d ", currentOrigin->number);
				system("COLOR 5A");
				Beep(450, 150);
				break;
			case 6:
				printf("%d ", currentOrigin->number);
				system("COLOR 6A");
				Beep(500, 150);
				break;
			case 7:
				printf("%d ", currentOrigin->number);
				system("COLOR 7A");
				Beep(550, 150);
				break;
			case 8:
				printf("%d ", currentOrigin->number);
				system("COLOR 8A");
				Beep(600, 150);
				break;
			case 9:
				printf("%d ", currentOrigin->number);
				system("COLOR 9A");
				Beep(650, 150);
				break;			
		}
		Sleep(timeGame);
		system("CLS");
		currentOrigin = currentOrigin->next;
	}
	defineNumber(origin);
}

void defineNumber(TPOrigin * currentOrigin){
	int number;

	while(currentOrigin != NULL){
		system("COLOR 0A");
		
		//number = getch();
		scanf("%d", &number);
		//number = number - 48;		
		system("CLS");

		if(number == -1){		
			closeApplication();
		}

		if(currentOrigin->number != number){
			mistake();
			break;
		}
		else{
			switch(currentOrigin->number){
				case 0:
					system("COLOR 0A");
					Beep(200, 150);
					break;
				case 1:
					system("COLOR 1A");
					Beep(250, 150);
					break;
				case 2:
					system("COLOR 2A");
					Beep(300, 150);
					break;
				case 3:
					system("COLOR 3A");
					Beep(350, 150);
					break;
				case 4:
					system("COLOR 4A");
					Beep(400, 150);
					break;
				case 5:
					system("COLOR 5A");
					Beep(450, 150);
					break;
				case 6:
					system("COLOR 6A");
					Beep(500, 150);
					break;
				case 7:
					system("COLOR 7A");
					Beep(550, 150);
					break;
				case 8:
					system("COLOR 8A");
					Beep(600, 150);
					break;
				case 9:
					system("COLOR 9A");
					Beep(650, 150);
					break;
			}
		}
		currentOrigin = currentOrigin->next;
	}
	if(currentOrigin == NULL)
		right();
}

void right(){
	countRightAnswers++;
	score += 10;
	printf("IT MATCHED! \n\nSCORE: %d\n\n", score);
	system("COLOR 3A");
	Beep(700, 700);
	Sleep(500);
    system("CLS");

	if(countRightAnswers >= 4){
		score += 20 * (stage+1);

		printf("Bonus: %d\n\nSTAGE %d %d\n\n", 20 * (stage+1), stage+2, timeGame);
		countRightAnswers = 0;
		stage++;
		if(timeGame > 150){
			timeGame -= 50;
			limit++;
		}
	}
	Sleep(1500);
	system("CLS");
	createNewNumber(origin, limit);
}

void mistake(){
	cleanList(origin);

	if(score > recordScore)
		recordScore = score;
 	
	printf("VOU LOST \nSTAGE %d\n", stage+1);
	printf("SCORE: %d\nRECORD SCORE: %d\n\n", score, recordScore);
	printf("STAGE 1\n");
	system("COLOR 4A");

	Beep(900, 700);
	getch();
	Sleep(1500);
	
	score = 0;
	countRightAnswers = 0;
	stage = 0;
	timeGame = 1000;

	system("CLS");
	createNewNumber(origin, 2);
}

void cleanList(TPOrigin * currentOrigin){
	while (currentOrigin != NULL){
		origin = currentOrigin->next;
		free (currentOrigin);
		currentOrigin = origin;
	}
	origin = NULL;
}

void disableCloseButton(){
	HWND hnd;
	HMENU menu;
	int i, j, cont;
	LPTSTR buffer;

	hnd = GetConsoleWindow();
	menu = GetSystemMenu(hnd, 0);
	cont = GetMenuItemCount(menu); 
	j = -1;

	buffer = (TCHAR*) malloc (256 *sizeof(TCHAR));
	for (i=0; i<cont; i++){
		GetMenuString(menu, i, buffer, 255, MF_BYPOSITION);
		if (!strcmp(buffer, "&Fechar") || !strcmp(buffer, "&Close")){
			j = i;
			break;
		}
	}
	if (j >= 0)
		RemoveMenu(menu, j, MF_BYPOSITION);
}

void closeApplication(){
	cleanList(origin);
	printf("THANK YOU FOR PLAYING GENIUS!! :)");
	exit(1);
}
