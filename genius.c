/*
 *  Jogo Genius versão 2.2
 *  Jhonatan Oliveira
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

int fase = 0;
int contarAcertos = 0;
int tempoJogo = 1000;
int limite = 2;
int pontuacao = 0;
int pontuacaoRecorde = 0;

typedef struct registroOrigem{
	int numero;
	struct registroOrigem * proximo;
}TPOrigem;

TPOrigem * origem = NULL;

void definirNumero(TPOrigem * origemAtual);
void errou();
void acertou();
void mostranumero();
void criaNovoNumero(TPOrigem * origemAtual, int limite);
void inicia();
void limparLista(TPOrigem * origem);
void desabilitarBotaoFechar();
void fecharPrograma();

int main(){
	srand(time(NULL));
	desabilitarBotaoFechar();
	inicia();
	criaNovoNumero(origem, limite);

	return 0;
}

void inicia(){
	int frequencia;
	int chave = 0;
	char SYSTEM[][10] = {"COLOR 2A", "COLOR 3A", "COLOR 6A", "COLOR 5A", "COLOR 8A",\
			     "COLOR 1A", "COLOR 9A", "COLOR 7A", "COLOR 8A", "COLOR 4A",\
			     "COLOR 6A", "COLOR 2A", "COLOR 5A", "COLOR 1A", "COLOR 8A", "COLOR 0A"};

	for(frequencia = 300; frequencia < 675; frequencia+= 25){	
		printf("CARREGANDO O JOGO...");
		system(SYSTEM[chave++]);
		Beep(frequencia,frequencia);
		system("CLS");
	}
	system(SYSTEM[chave]);

	Sleep(1000);
	printf("BEM VINDO AO GENIUS :) O jogo vai iniciar em instantes.\n");
	Sleep(2500);	

	system("CLS");
	printf("Fase 1 1000\n");

	Sleep(1500);
	system("CLS");
}

void criaNovoNumero(TPOrigem * origemAtual, int limite){
	TPOrigem * novaOrigem;

	novaOrigem = (TPOrigem * ) malloc(sizeof(TPOrigem));
	novaOrigem->numero = rand() % limite;

	if(origemAtual == NULL){
		origem = novaOrigem;
		origem->proximo = NULL;
	}
	else{
		while(origemAtual->proximo != NULL)
			origemAtual = origemAtual->proximo;
		novaOrigem->proximo = NULL;
		origemAtual->proximo = novaOrigem;
	}
	mostranumero(origem);
}

void mostranumero(TPOrigem * origemAtual){
	while(origemAtual != NULL){
		switch(origemAtual->numero){
			case 0:
				printf("%d ", origemAtual->numero);
				system("COLOR 0A");
				Beep(200, 150);
				break;
			case 1:
				printf("%d ", origemAtual->numero);
				system("COLOR 1A");
				Beep(250, 150);
				break;
			case 2:
				printf("%d ", origemAtual->numero);
				system("COLOR 2A");
				Beep(300, 150);
				break;
			case 3:
				printf("%d ", origemAtual->numero);
				system("COLOR 3A");
				Beep(350, 150);
				break;
			case 4:
				printf("%d ", origemAtual->numero);
				system("COLOR 4A");
				Beep(400, 150);
				break;
			case 5:
				printf("%d ", origemAtual->numero);
				system("COLOR 5A");
				Beep(450, 150);
				break;
			case 6:
				printf("%d ", origemAtual->numero);
				system("COLOR 6A");
				Beep(500, 150);
				break;
			case 7:
				printf("%d ", origemAtual->numero);
				system("COLOR 7A");
				Beep(550, 150);
				break;
			case 8:
				printf("%d ", origemAtual->numero);
				system("COLOR 8A");
				Beep(600, 150);
				break;
			case 9:
				printf("%d ", origemAtual->numero);
				system("COLOR 9A");
				Beep(650, 150);
				break;
		}
		Sleep(tempoJogo);
		system("CLS");
		origemAtual = origemAtual->proximo;
	}
	definirNumero(origem);
}

void definirNumero(TPOrigem * origemAtual){
	int numero;

	while(origemAtual != NULL){
		system("COLOR 07");

		//numero = getch();
		scanf("%d", &numero);
		//numero = numero - 48;
		system("CLS");
		
		if(numero == -1){
			fecharPrograma();
		}

		if(origemAtual->numero != numero){
			errou();
			break;
		}
		else{
			switch(origemAtual->numero){
				case 0:
					system("COLOR A");
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
		origemAtual = origemAtual->proximo;
	}
	if(origemAtual == NULL)
		acertou();
}

void acertou(){	
	contarAcertos++;
	pontuacao += 10;
	printf("Voce acertou!\n\nPontuacao: %d\n\n", pontuacao);
	system("COLOR 3A");
	Beep(700, 700);
	Sleep(500);
    system("CLS");    

	if(contarAcertos >= 4){		
		pontuacao += 20 * (fase+1);
		
		printf("Bonus: %d\n\nFase %d %d\n\n", 20 * (fase+1), fase+2, tempoJogo);
		contarAcertos = 0;		
		fase++;
		if(tempoJogo > 150){
			tempoJogo -= 50;
			limite++;			
		}
	}
	Sleep(1500);
	system("CLS");
	criaNovoNumero(origem, limite);
}

void errou(){
	limparLista(origem);		

	if(pontuacao > pontuacaoRecorde)
		pontuacaoRecorde = pontuacao;

	printf("Voce errou \nFase %d\n", fase+1);
	printf("Pontuacao: %d\nPontuacao recorde: %d\n\n", pontuacao, pontuacaoRecorde);
	printf("Fase 1\n");
	system("COLOR 4A");			

	Beep(900, 700);
	getch();
	Sleep(1500);

	pontuacao = 0;
	contarAcertos = 0;
	fase = 0;
	tempoJogo = 1000;

	system("CLS");
	criaNovoNumero(origem, 2);
}

void limparLista(TPOrigem * origemAtual){
    while (origemAtual != NULL){
        origem = origemAtual->proximo;
        free (origemAtual);
        origemAtual = origem;
    }
    origem = NULL;
}

void desabilitarBotaoFechar(){	
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

void fecharPrograma(){
	limparLista(origem);
	printf("Obrigado por jogar Genius!! :)");
	exit(0);
}
