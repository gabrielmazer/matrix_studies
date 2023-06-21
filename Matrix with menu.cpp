#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59
#define MAX 10

void voltarMenu();

void mostraOriginal(int mat[][MAX], int di){
    int i, j;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            printf("%4.d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void matrizPermutacao(int mat[][MAX], int di){
    int i, j, aux, count = 0, soma = 0, fail = 0;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            aux  = mat[i][j];
            soma += mat[i][j];
            if(mat[i][j]==0)
                count++;
        }
        if(soma != 1 || count != di-1)
            fail = 1;
        count = soma = 0;
    }
    if(fail==0){
        for(i=0; i<di; i++){
            for(j=0; j<di; j++){
                aux  = mat[j][i];
                soma += mat[j][i];
                if(mat[j][i]==0)
                    count++;
            }
            if(soma != 1 || count != di-1)
                fail = 1;
            count = 0; soma = 0;
        }
    }
    if(fail==0)
        printf("Eh uma matriz de permutacao!!\n\n");
    else
        printf("Nao eh matriz de permutacao\n\n");
}


void quadradoLatino(int mat[][MAX], int di){
    int i, k, j1, j2, aux, soma1 = 0, soma2 = 0, count = 0, fail = 0;
    for(i=0; i<1; i++){
        for(j1=0; j1<di; j1++){
            soma1 += mat[i][j1];
        }
    }
    for(k=0; k<di; k++){
        for(j1=0; j1<di; j1++){
            aux = mat[k][j1];
            soma2 += mat[k][j1];
            for(j2=0; j2<di; j2++){
                if(aux == mat[k][j2])
                    count++;
                if(count>1)
                    fail = 1;
            }
            count = 0;
        }
        if(soma2 != soma1 && k<di)
            fail = 1;
        soma2 = 0;
    }
    count = 0;
    if(fail==0){
        for(i=0; i<di; i++){
            for(j1=0; j1<di; j1++){
                aux = mat[j1][i];
                soma2 += mat[j1][i];
                for(j2=0; j2<di; j2++){
                    if(aux == mat[j2][i])
                        count++;
                    if(count>1)
                        fail = 1;
                }
                count = 0;
            }
            count = 0;
            if(soma2 != soma1 && i<di)
                fail = 1;
            soma2 = 0;
        }
        if(fail==0)
            printf("EH um quadrado latino de ordem %d !!\n\n", di);
        else
            printf("Que pena, nao eh um quadrado latino\n\n");
    }
    else
        printf("Nao eh quadrado latino\n\n");
}


void quadradoMagico(int mat[][MAX], int di){
    int i, j, soma = 0, principal = 0, secundaria = 0, secDi = di-1, fail = 0;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            if(i==j)
                principal += mat[i][j];
            if(j==secDi){
                secundaria += mat[i][j];
                secDi--;
            }
        }
    }
    if(principal != secundaria)
        fail = 1;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++)
            soma += mat[i][j];
        if(soma!=principal)
            fail = 1;
        soma = 0;
    }
    for(i=0; i<di; i++){
        for(j=0; j<di; j++)
            soma += mat[j][i];
        if(soma!=principal)
            fail = 1;
        soma = 0;
    }
    if(fail==0)
        printf("Eh quadrado magico! a soma comum eh %d\n\n", principal);
    else
        printf("Nao eh quadrado magico\n\n");
}


void verificarSimetria(int mat[][MAX], int di){
    int i, j, count=0, matSimetrica[MAX][MAX];
    for(i=0; i<di; i++){ // copia da matriz original
        for(j=0; j<di; j++){
            matSimetrica[i][j] = mat[j][i];
            if(matSimetrica[i][j] == mat[i][j])
                count++;
        }
    }
    if(count == di*di)
        printf("A matriz eh simetrica (transposta eh igual a original)\n\n");
    else
        printf("A matriz nao eh simetrica, pois a transposta nao eh igual a original!\n\n");
}    


void trocaDiagonal(int mat[][MAX], int di){
    int matDiagonal[MAX][MAX], i, j, aux, k = di-1;
    for(i=0; i<di; i++){ // copia da matriz original
        for(j=0; j<di; j++){
            matDiagonal[i][j] = mat[i][j];
        }
    }
    for(i=0; i<di; i++){ // troca das diagonais somente na matDiagonal(copia)
        for(j=0; j<di; j++){
            if (i == j){
                aux = matDiagonal[i][j];
                matDiagonal[i][j] = matDiagonal[i][k];
                matDiagonal[i][k] = aux;
                k--;
            }     
        }
    }
    mostraOriginal(mat, di);    
    printf("Matriz com diagonais principal e secundaria trocadas:\n\n");
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            printf("%4.d", matDiagonal[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void trocaColuna(int mat[][MAX], int di){
    int matLinha[MAX][MAX], X, Y, A, B, i, j;
    do{
    printf("\nDigite quais colunas quer trocar (dimensao %d):\n", di);
    scanf("%d %d", &X, &Y);
    } while(X>di || X<1 || Y>di || Y<1);
    A = X; X--; B = Y; Y--;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            if(j==X){
                matLinha[i][j] = mat[i][Y];
            }
            else if(j==Y){
                matLinha[i][j] = mat[i][X];
            }
            else{
                matLinha[i][j] = mat[i][j];
            }
        }
    }
    mostraOriginal(mat, di);      
    printf("Matriz trocada coluna %d pela %d:\n\n", A, B);
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            printf("%4.d", matLinha[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void trocaLinha(int mat[][MAX], int di){
    int matLinha[MAX][MAX], X, Y, A, B, i, j;
    do{
    printf("\nDigite quais linhas quer trocar (dimensao %d):\n", di);
    scanf("%d %d", &X, &Y);
    } while(X>di || X<1 || Y>di || Y<1);
    A = X; X--; B = Y, Y--;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            if(i==X){
                matLinha[i][j] = mat[Y][j];
            }
            else if(i==Y){
                matLinha[i][j] = mat[X][j];
            }
            else{
                matLinha[i][j] = mat[i][j];
            }
        }
    }
    mostraOriginal(mat, di);
    printf("Matriz trocada linha %d pela %d\n\n", A, B);
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            printf("%4.d", matLinha[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void leitura(int mat[][MAX], int di){
    int i, j;
    for(i=0; i<di; i++){
        for(j=0; j<di; j++){
            printf("  mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}


void dimensao(int *di){
    do
    {
        scanf("%d", &*di);
    } while (*di < 1 || *di > MAX); 
}

//-------------------------------------------------------------------------
void gotoxy (int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void clear_part(int start_line, int end_line){
	int x, y; 
	for (y = start_line; y <= end_line; y++){
		gotoxy (1,y); // vai para o início da linha y 
		for (x = 1; x <= 80; x++)
			printf(" "); // imprime um espaço em branco 
	}
}
//-------------------------------------------------------------------------
int SetColor (char color) {
  HANDLE h;
  h = GetStdHandle (STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute (h,color);
}
//-------------------------------------------------------------------------
void escreveTexto (int x, int y, char texto[], int cor){
  SetColor (cor);
  gotoxy (y,x);
  printf ("%s",texto);
}
//-------------------------------------------------------------------------
void menu (int op){
  char vet[][60] = {"Mostrar os elementos da matriz", "Troque os elementos da linha X pela linha Y",
   "Troque os elementos da coluna X pela coluna Y", "Troque os elementos da diagonal principal pela secundaria",
    "Verificar se eh uma matriz simetrica","Verificar se a matriz eh um quadrado magico",
	"Verificar se a matriz eh um quadrado latino", "Verificar se eh matriz de permutacao",
	"Sair"};
  int i;
  system ("cls");
  for (i = 0; i < 9; i++)
    escreveTexto (3+i,9,vet[i],10);
  escreveTexto (2+op,9,vet[op-1],5);  
}
//-------------------------------------------------------------------------


int main(){
  int op, matriz[MAX][MAX], n, countmain = 0;
  char t, stop;
  op = 1;
  menu (op);
  do{
	  t = getch();
	  // se for caracter especial
	  if (t <= 0){
	    t = getch();
	  if (t == baixo){
	    if (op != 9) op++; 
		   else op = 1;
		menu (op);
	  }
	  else if (t == cima) {
	  	if (op != 1) op--;
		else op = 9;
		menu (op);
	  }
	  else if (t == f1)
	         printf ("AJUDA");
    }
    else
      if (t == enter){
      	if(countmain != 1){
      		gotoxy(15, 15);
      		escreveTexto (15,2,"Primeiro, diga qual a dimensao da matriz (MAX 10): ",2);
      		dimensao(&n);
      		leitura(matriz, n);
      		clear_part(15, 30);
		}
		switch (op){
			case 1: escreveTexto (15,10,"Voce escolheu mostrar a Matriz original:\n\n",1);
					mostraOriginal(matriz, n);
					voltarMenu();
					break;
			case 2: escreveTexto (15,10,"Voce escolheu trocar linhas \n\n",3);
					countmain = 1;
					trocaLinha(matriz, n);
					voltarMenu();
					break;
			case 3: escreveTexto (15,10,"Voce escolheu trocar colunas \n\n",4);
					trocaColuna(matriz, n);
					voltarMenu();
					break;
			case 4: escreveTexto (15,10,"Voce escolheu inverter as diagonais \n\n",5);
					trocaDiagonal(matriz, n);
					voltarMenu();
					break;
			case 5: escreveTexto (15,10,"Voce escolheu verificar a simetria da matriz \n\n",6);
					verificarSimetria(matriz, n);
					voltarMenu();
					break;
			case 6: escreveTexto (15,10,"Voce escolheu verificar se a matriz eh um quadrado magico \n\n",7);
					quadradoMagico(matriz, n);
					voltarMenu();
					break;
			case 7: escreveTexto (15,10,"Voce escolheu verificar se a matriz eh um quadrado latino\n\n",8);
					quadradoLatino(matriz, n);
					voltarMenu();
					break;
			case 8: escreveTexto (15,10,"Voce escolheu verificar se eh uma matriz de permutacao \n\n",9);
					matrizPermutacao(matriz, n);
					voltarMenu();
					break;
			case 9: escreveTexto (15,10,"Sair",4);
					t = esc;
					break;
//			case 10: escreveTexto (15,2,"Voce escolheu recomecar com outra matriz \n\n",4);
//					break;
		}
		
	}
	} while (t != esc);
}


void voltarMenu(){
		char stop;
		printf("Prescione F2 para voltar ao menu");
		do{
			stop = getch();
			if (stop <= 0)
				stop = getch();
		} while (stop != 60);
		main();
}
