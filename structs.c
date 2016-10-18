#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct candidatos{
	
	int saude;
	int educacao;
	int saneamento;
	int seguranca;
	int lazer;
	
}CANDIDATO;


CANDIDATO* random_select(CANDIDATO *vec){
	
	srand( (unsigned)time(NULL) );
	int random;
	CANDIDATO *cand;
	cand = (CANDIDATO *)malloc(3 * sizeof(CANDIDATO));
	int aux[2];
	int i = 0; 
	while(1){
		s1: random = rand() % 6;
		if(!i){
			aux[0] = random;
			cand[i].saude = vec[random].saude;
			cand[i].educacao = vec[random].educacao;
			cand[i].saneamento = vec[random].saneamento;
			cand[i].seguranca = vec[random].seguranca;
			cand[i].lazer = vec[random].lazer;
			i++;
		}
		if(i == 1){
			if(random != aux[0]){
				aux[1] = random;
				cand[i].saude = vec[random].saude;
				cand[i].educacao = vec[random].educacao;
				cand[i].saneamento = vec[random].saneamento;
				cand[i].seguranca = vec[random].seguranca;
				cand[i].lazer = vec[random].lazer;
				i++;
			}
			else{
				goto s1;
			}
		}
		if(i == 2){
			if(random != aux[0] && random != aux[1]){
				cand[i].saude = vec[random].saude;
				cand[i].educacao = vec[random].educacao;
				cand[i].saneamento = vec[random].saneamento;
				cand[i].seguranca = vec[random].seguranca;
				cand[i].lazer = vec[random].lazer;
				goto s2;
			}
			else{
				goto s1;
			}
			
		}
	}
	s2: return cand;
	
}

int main(){
	
	CANDIDATO *vec;
	vec = (CANDIDATO *)malloc(6 * sizeof(CANDIDATO));
	//MEDIANO
	vec[0].educacao = 20;
	vec[0].lazer = 20;
	vec[0].saneamento = 20;
	vec[0].saude = 20;
	vec[0].seguranca = 20;
	//FOCO EM EDUCACAO
	
	vec[1].educacao = 40;
	vec[1].lazer = 0;
	vec[1].saude = 20;
	vec[1].seguranca = 15;
	vec[1].saneamento = 25;
	//FOCO PESADO EM SEGURANCA
	
	vec[2].seguranca = 50;
	vec[2].lazer = 10;
	vec[2].educacao = 5;
	vec[2].saude = 10;
	vec[2].saneamento = 25;
	//FOCO EM SANEAMENTO
	
	vec[3].saneamento = 30;
	vec[3].saude = 40;
	vec[3].educacao = 15;
	vec[3].lazer = 10;
	vec[3].seguranca = 5;
	//PESADO EM EDUCACAO
	
	vec[4].educacao = 50;
	vec[4].saude = 10;
	vec[4].seguranca = 10;
	vec[4].saneamento = 10;
	vec[4].lazer = 20; 
	//MILITAR
	
	vec[5].seguranca = 70;
	vec[5].lazer = 0;
	vec[5].saneamento = 15;
	vec[5].educacao = 0;
	vec[5].saude = 15;
	CANDIDATO *vector;
	vector = random_select(vec);
	int i, j;
	for(i = 0; i < 3; i++){
		printf("%dº candidato\n\n\n", i);
		printf("EDUCACAO: %d\n", vector[i].educacao);
		printf("SAUDE: %d\n", vector[i].saude);
		printf("SEGURANCA: %d\n", vector[i].seguranca);
		printf("SANEAMENTO: %d\n", vector[i].saneamento);
		printf("LAZER: %d\n\n\n", vector[i].lazer);
	}
	
	
	free(vec);
	return 0;
		
}
