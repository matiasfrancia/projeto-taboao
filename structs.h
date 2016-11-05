#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct candidatos{
	
	char **nome;
	int saude;
	int educacao;
	int saneamento;
	int seguranca;
	int lazer;
	
}CANDIDATO;

char *homem[] = {"Henrique", "Daniel", "Matheus", "Caio", "Luiz", "Antonio", "Carlos", "Felipe", "Mauricio", "Marcos"};
char *mulher[] = {"Viviane", "Rosana", "Elaine", "Sonia", "Eliana", "Neuza", "Talita", "Leticia", "Caroline", "Lais", "Livia"};

int name_select(char ***pessoa){

	srand((unsigned)time(NULL));
	int random = rand() % 2;
	int aux_busca;
	if(!random){
		aux_busca = rand() % 10;
		*pessoa = &homem[aux_busca];
		return aux_busca;
	}
	else{
		aux_busca = rand() % 11;
		*pessoa = &mulher[aux_busca];
		return aux_busca;
	}
}

CANDIDATO* random_select(CANDIDATO *vec){
	
	srand( (unsigned)time(NULL) );
	int random;
	CANDIDATO *cand;
	cand = (CANDIDATO *)malloc(3 * sizeof(CANDIDATO));
	int aux[2];
	int i = 0; 
	while(1){
		s1: random = rand() % 11;
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

CANDIDATO *select_candidato(){
	
	CANDIDATO *vec;
	vec = (CANDIDATO *)malloc(11 * sizeof(CANDIDATO));
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
	
	vec[6].saude = 65;
	vec[6].lazer = 10;
	vec[6].educacao = 10;
	vec[6].saneamento = 10;
	vec[6].seguranca = 5;
	
	//CIRCO
	vec[7].lazer = 80;
	vec[7].seguranca = 10;
	vec[7].saneamento = 5;
	vec[7].saude = 5;
	vec[7].educacao = 0;
	
	vec[8].seguranca = 30;
	vec[8].educacao = 30;
	vec[8].saude = 30;
	vec[8].saneamento = 10;
	vec[8].lazer = 0;

	//PROFESSOR
	vec[9].educacao = 90;
	vec[9].saude = 5;
	vec[9].seguranca = 3;
	vec[9].saneamento = 2;
	vec[9].lazer = 0;

	//medico
	vec[10].saude = 50;
	vec[10].saneamento = 32;
	vec[10].educacao = 8;
	vec[10].seguranca = 9;
	vec[10].lazer = 1;

	CANDIDATO *vector;
	vector = random_select(vec);
	int i;
	int alocar;
	char **pessoa;
	int aux[3];
	for(i = 0; i < 3; i++){
		JUMP:
		alocar = name_select(&pessoa);
		if(!i){
			aux[0] = alocar;
			vector[i].nome = pessoa;
		}
		if(i == 1){
			aux[1] = alocar;
			if(aux[0] == aux[1]){
				goto JUMP;
			}
			else{
				vector[i].nome = pessoa;
			}
		}
		if(i == 2){
			aux[2] = alocar;
			if(aux[2] == aux[1] || aux[2] == aux[0]){
				goto JUMP;
			}
			else{
				vector[i].nome = pessoa;
			}
		}
		

	}


	
	free(vec);	
	return vector;	
}


