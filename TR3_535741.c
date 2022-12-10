#include <stdio.h>
#include <stdlib.h>
int main(){
	
	unsigned int k[200]; //vetor para guardar valores inteiros de 1 a 5000
	int x; //guardar o valor da posicao dos bits ao verificar se estao acionados
	int y; //guardar os valores digitados pelo usuario
	int i; //iterador
	int j; //iterador
	x = 0;
	y = 0;
	
	for(i = 0; i < 200; i++){ 
		k[i] = 0; //retirar o lixo de memoria do vetor de inteiros
	}
	
	while (y != -1){ //ao digitar -1 as operacoes se encerram
		scanf("%d", &y);
		if (y >= 0 && y <= 5000){ //se o valor digitado estiver entre 0 e 5000
			k[y/32] = k[y/32] | (2147483648 >> (y%32)); //acionar o bit na posicao do numero que foi digitado
		
		}
	}	
	
	printf("Valores digitados anteriormente:\n");
	
	for(i = 0; i < 200; i++){ //percorrer as posicoes externas do vetor k
		for(j = 0; j < 32; j++){ //percorrer os 32 bits de cada posicao do vetor k
			if(k[i] & (2147483648 >> j)){ //se o bit estiver acionado
				printf("%d\n", (j + x)); //imprimir o valor da posicao do bit
			}
		
		}
		x = x + 32;	//incrementar o valor da posicao em 32 a cada posicao externa que percorre
	}
		
	return 0;
}
