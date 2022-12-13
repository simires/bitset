#include <stdio.h>
#include <stdlib.h>
int main(){
	
	unsigned int vetor[200]; //vetor para guardar valores inteiros de 0 a 5000
	int pos; //guardar o valor da posicao dos bits ao verificar se estao acionados
	int valor; //guardar os valores digitados pelo usuario
	int i; //iterador
	int j; //iterador
	pos = 0;
	valor = 0;
	
	for(i = 0; i < 200; i++){ 
		vetor[i] = 0; //retirar o lixo de memoria do vetor de inteiros
	}
	
	while (valor != -1){ //ao digitar -1 as operacoes se encerram
		scanf("%d", &valor);
		if (valor >= 0 && valor <= 5000){ //se o valor digitado estiver entre 0 e 5000
			vetor[valor/32] = vetor[valor/32] | (2147483648 >> (valor%32)); //acionar o bit na posicao do numero que foi digitado
		
		}
	}	
	
	printf("Valores digitados anteriormente:\n");
	
	for(i = 0; i < 200; i++){ //percorrer as posicoes externas do vetor
		for(j = 0; j < 32; j++){ //percorrer os 32 bits de cada posicao do vetor
			if(vetor[i] & (2147483648 >> j)){ //se o bit estiver acionado
				printf("%d\n", (j + pos)); //imprimir o valor da posicao do bit
			}
		
		}
		pos = pos + 32;	//incrementar o valor da posicao em 32 a cada posicao externa que percorre
	}
		
	return 0;
}
