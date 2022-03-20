#include<stdio.h>
#include<locale.h>
#define N 8

void bin_hexa(int *bin){
	int i, num1 = 0, num2 = 0, aux =  1;
	char h;
	
	printf(" = ");
	for(i = 3; i >= 0; i--){
		if(bin[i] == 1){
			num2 = num2 + aux;
			aux = aux *2;
		}else{
			aux = aux*2;
		}
	}
	if(num2 > 9){
		switch(num2){
			case 10:
				h = 'a';
				printf("%c", h);
				break;
			case 11:
				h = 'b';
				printf("%c", h);
				break;
			case 12:
				h = 'c';
				printf("%c", h);
				break;
			case 13:
				h = 'd';
				printf("%c", h);
				break;
			case 14:
				h = 'e';
				printf("%c", h);
				break;
			case 15:
				h = 'f';
				printf("%c", h);
				break;
		}
	}else{
		printf("%d",num2);
	}
	
	aux = 1;
	for(i = N - 1; i >= 4; i--){
		if(bin[i] == 1){
			num1 = num1 + aux;
			aux = aux *2;
		}else{
			aux = aux*2;
		}
	}
	if(num1 > 9){
		switch(num1){
			case 10:
				h = 'a';
				printf("%c", h);
				break;
			case 11:
				h = 'b';
				printf("%c", h);
				break;
			case 12:
				h = 'c';
				printf("%c", h);
				break;
			case 13:
				h = 'd';
				printf("%c", h);
				break;
			case 14:
				h = 'e';
				printf("%c", h);
				break;
			case 15:
				h = 'f';
				printf("%c", h);
				break;
		}
	}else{
		printf("%d",num1);
	}
}

void complementar(int *comp){
	int i;
		printf("\nComplementar:");
			for(i = 0; i < N; i++){
				if(comp[i] == 0){
					comp[i] = 1;
					printf("%d",comp[i]);
				}else{
					comp[i] = 0;
					printf("%d", comp[i]);
				}
			}
		printf("\n----------------------\n");
}

int main(){
	setlocale(LC_ALL,"Portuguese");
	int op, i, bin1[N], bin2[N], e[N], ouex[N], ou[N], comp[N];
	char hexa1[10], hexa2[10];
	
	printf("--------TIPO DE ENTRADA--------\n");
	printf("(1) - HEXADECIAL\n");
	printf("(2) - BINÁRIO\n");
	printf("Opção: ");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			printf("---------HEXADECIMAL---------\n");
			printf("Primeiro Valor:");
			scanf("%s",&hexa1);
			printf("Segundo Valor:");
			scanf("%s",&hexa2);
			break;
		case 2:
			printf("---------BINÁRIO---------\n");
			for(i = 0; i < N; i++){
				printf("Valor:");
				scanf("%d", &bin1[i]);
			}
			for(i = 0; i < N; i++){
				printf("%d", bin1[i]);
			}
			bin_hexa(bin1);
			complementar(bin1);
			
			
			printf("\n\n");
			for(i = 0; i < N; i++){
				printf("Valor:");
				scanf("%d", &bin2[i]);
			}
			for(i = 0; i < N; i++){
				printf("%d", bin2[i]);
			}
			bin_hexa(bin2);
			complementar(bin2);
			
			printf("\n----------------------\nBitwise 'e' - (&):");
			for(i = 0; i < N; i++){
				e[i] = bin1[i] & bin2[i];
				printf("%d",e[i]);
			}
			bin_hexa(e);
			
			
			printf("\n----------------------\nBitwise 'ou exclusivo' - (^):");
			for(i = 0; i < N; i++){
				ouex[i] = bin1[i] ^ bin2[i];
				printf("%d",ouex[i]);
			}
			bin_hexa(ouex);
			
			printf("\n----------------------\nBitwise 'ou' - (|):");
			for(i = 0; i < N; i++){
				ou[i] = bin1[i] | bin2[i];
				printf("%d",ou[i]);
			}
			bin_hexa(ou);
			break;
	}
}
