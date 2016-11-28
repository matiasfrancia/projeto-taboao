#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct candidatos{
	
	char **nome;
	char *descricao;
	int homem;
	int dinheiro;
	int saude;
	int educacao;
	int saneamento;
	int seguranca;
	int lazer;
	
}CANDIDATO;

typedef struct item{

	int saude:4;
	int saneamento:4;
	int seguranca:4;
	int educacao:4;
	int lazer:4;

}ITEM;


void inicia_item(ITEM *aux){
	aux->saude = 0;
	aux->saneamento = 0;
	aux->seguranca = 0;
	aux->educacao = 0;
	aux->lazer = 0;
}


int precos[] = {250000, 500000, 750000, 1000000, 1500000};
int inc[] = {3, 7, 10, 15, 25};

char *homem[] = {"Henrique Medeiro", "Daniel Agulha", "Matheus Batata", "Caio Mathias", "Luiz Mendonca", "Antonio Pacaembu", "Carlos De Melo", "Felipe Jose", "Mauricio Schenneider","Frederico Babu " };
char *mulher[] = {"Viviane Luz", "Rosana Rocha", "Elaine Silva", "Sonia Araujo", "Eliana Cazé", "Neuza Mauá", "Talita Taboão", "Leticia de Oliveira", "Caroline Lucas", "Lais Sadia", "Livia Queiros", "Monalisa Santiago"};

void print_candidato(CANDIDATO *cand){

	printf("DINHEIRO: %d\n", cand->dinheiro);
	printf("SAUDE: %d\n", cand->saude);
	printf("SANEAMENTO: %d\n", cand->saneamento);
	printf("SEGURANCA: %d\n", cand->seguranca);
	printf("EDUCACAO: %d\n,", cand->educacao);
	printf("LAZER: %d\n", cand->lazer);

}

void print_item(ITEM *quantidade){

	printf("COMPRADO SAUDE: %d\n", quantidade->saude);
	printf("COMPRADO SANEAMENTO: %d\n", quantidade->saneamento);
	printf("COMPRADO SEGURANCA: %d\n", quantidade->seguranca);
	printf("COMPRADO EDUCACAO: %d\n,", quantidade->educacao);
	printf("COMPRADO LAZER: %d\n", quantidade->lazer);	

}

int name_select(CANDIDATO *aux, char ***pessoa){

	srand((unsigned)time(NULL));
	int random = rand() % 2;
	int aux_busca;
	if(!random){
		aux_busca = rand() % 10;
		*pessoa = &homem[aux_busca];
		aux->homem = 1;
		return aux_busca;
	}
	else{
		aux_busca = rand() % 12;
		*pessoa = &mulher[aux_busca];
		aux->homem = 0;
		return aux_busca;
	}
}


void select_nivel(CANDIDATO* cidade, int nivel){
	srand( (unsigned)time(NULL) );
	if(nivel == 1){
		cidade->dinheiro = 10000000;
		cidade->saneamento = 50 + (1 + rand() % 10);
		cidade->educacao = 50 + (1 + rand() % 10);
		cidade->saude = 50 + (1 + rand() % 10);
		cidade->seguranca = 50 + (1 + rand() % 10);
		cidade->lazer = 50 + (1 + rand() % 10);
	}
	if(nivel == 2){
		cidade->dinheiro = 7500000;
		cidade->saneamento = 35 + (1 + rand() % 5);
		cidade->educacao = 35 + (1 + rand() % 5);
		cidade->saude = 35 + (1 + rand() % 5);
		cidade->seguranca = 35 + (1 + rand() % 5);
		cidade->lazer = 35 + (1 + rand() % 5);
	}
	if(nivel == 3){
		cidade->dinheiro = 5000000;
		cidade->saneamento = 15 + (1 + rand() % 10);
		cidade->educacao = 15 + (1 + rand() % 10);
		cidade->saude = 15 + (1 + rand() % 10);
		cidade->seguranca = 15 + (1 + rand() % 10);
		cidade->lazer = 15 + (1 + rand() % 10);
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
			cand[i].dinheiro = vec[random].dinheiro;
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
				cand[i].dinheiro = vec[random].dinheiro;
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
				cand[i].dinheiro = vec[random].dinheiro;
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
	vec[0].educacao = 40;
	vec[0].dinheiro = -50000;
	vec[0].lazer = 0;
	vec[0].saneamento = 0;
	vec[0].saude = 0;
	vec[0].seguranca = 0;
	//FOCO EM EDUCACAO
	
	vec[1].educacao = 0;
	vec[1].dinheiro = -50000;
	vec[1].lazer = 40;
	vec[1].saude = 0;
	vec[1].seguranca = 0;
	vec[1].saneamento = 0;
	//FOCO PESADO EM SEGURANCA
	
	vec[2].seguranca = 40;
	vec[2].lazer = 0;
	vec[2].dinheiro = -50000;
	vec[2].educacao = 0;
	vec[2].saude = 0;
	vec[2].saneamento = 0;
	//FOCO EM SANEAMENTO
	
	vec[3].saneamento = 40;
	vec[3].saude = 0;
	vec[3].dinheiro = -50000;
	vec[3].educacao = 0;
	vec[3].lazer = 0;
	vec[3].seguranca = 0;
	//PESADO EM EDUCACAO
	
	vec[4].educacao = 2;
	vec[4].dinheiro = -40000;
	vec[4].saude = 8;
	vec[4].seguranca = 20;
	vec[4].saneamento = 10;
	vec[4].lazer = 0; 
	//MILITAR

	vec[5].seguranca = 0;
	vec[5].lazer = 40;
	vec[5].dinheiro = -50000;
	vec[5].saneamento = 0;
	vec[5].educacao = 0;
	vec[5].saude = 0;
	
	vec[6].saude = 20;
	vec[6].lazer = 5;
	vec[6].educacao = 5;
	vec[6].saneamento = 5;
	vec[6].dinheiro = -29000;
	vec[6].seguranca = 5;
	
	//CIRCO
	vec[7].lazer = 5;
	vec[7].seguranca = 0;
	vec[7].saneamento = 15;
	vec[7].saude = 15;
	vec[7].dinheiro = -25000;
	vec[7].educacao = 0;
	
	vec[8].seguranca = 10;
	vec[8].educacao = 0;
	vec[8].saude = 20;
	vec[8].dinheiro = -31000;
	vec[8].saneamento = 10;
	vec[8].lazer = 0;

	//PROFESSOR
	vec[9].educacao = 20;
	vec[9].saude = 0;
	vec[9].dinheiro = -31000;
	vec[9].seguranca = 20;
	vec[9].saneamento = 0;
	vec[9].lazer = 0;

	//medico
	vec[10].saude = 5;
	vec[10].dinheiro = -32000;
	vec[10].saneamento = 5;
	vec[10].educacao = 10;
	vec[10].seguranca = 10;
	vec[10].lazer = 10;

	CANDIDATO *vector;
	vector = random_select(vec);
	int i;
	int alocar;
	char **pessoa;
	int aux[3];
	for(i = 0; i < 3; i++){
		JUMP:
		alocar = name_select(&vector[i], &pessoa);
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



int compra_saude(CANDIDATO *cidade, ITEM *quantidade){
	print_item(quantidade);
	if(quantidade->saude < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->saude]){
			fprintf(stderr, "NAO POSSUI DINHEIRO\n");
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->saude];
			cidade->saude += inc[quantidade->saude];
			quantidade->saude++;
			print_candidato(cidade);
		}
		if(cidade->saude + inc[quantidade->saude] <= 100){
		cidade->saude += inc[quantidade->saude];
		}
		else{
		cidade->saude = 100;
		}
	}
	else{
		fprintf(stderr, "COMPROU TODOS OS UPGRADES\n");
		return -1;
	}

}

int compra_saneamento(CANDIDATO *cidade, ITEM *quantidade){
	print_item(quantidade);
	if(quantidade->saneamento < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->saneamento]){
			fprintf(stderr, "NAO POSSUI DINHEIRO\n");
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->saneamento];
			cidade->saneamento += inc[quantidade->saneamento];
			quantidade->saneamento++;
			print_candidato(cidade);
		}
		if(cidade->saneamento + inc[quantidade->saneamento] <= 100){
		cidade->saneamento += inc[quantidade->saneamento];
		}
		else{
		cidade->saneamento = 100;
		}
	}
	else{
		fprintf(stderr, "COMPROU TODOS OS UPGRADES\n");
		return -1;
	}

}

int compra_seguranca(CANDIDATO *cidade, ITEM *quantidade){
	print_item(quantidade);
	if(quantidade->seguranca < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->seguranca]){
			fprintf(stderr, "NAO POSSUI DINHEIRO\n");
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->seguranca];
			cidade->seguranca += inc[quantidade->seguranca];
			quantidade->seguranca++;
			print_candidato(cidade);
		}
		if(cidade->seguranca + inc[quantidade->seguranca]<= 100){
		cidade->seguranca += inc[quantidade->seguranca];
		}
		else{
		cidade->seguranca = 100;
		}
	}
	else{
		fprintf(stderr, "COMPROU TODOS OS UPGRADES\n");
		return -1;
	}

}

int compra_educacao(CANDIDATO *cidade, ITEM *quantidade){
	print_item(quantidade);
	if(quantidade->educacao < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->educacao]){
			fprintf(stderr, "NAO POSSUI DINHEIRO\n");
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->educacao];
			cidade->educacao += inc[quantidade->educacao];
			quantidade->educacao++;
			print_candidato(cidade);
		}
		if(cidade->educacao + inc[quantidade->educacao] <= 100){
		cidade->educacao += inc[quantidade->educacao];
		}
		else{
		cidade->educacao = 100;
		}
	}
	else{
		fprintf(stderr, "COMPROU TODOS OS UPGRADES\n");
		return -1;
	}

}

int compra_lazer(CANDIDATO *cidade, ITEM *quantidade){
	print_item(quantidade);
	if(quantidade->lazer < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->lazer]){
			fprintf(stderr, "NAO POSSUI DINHEIRO\n");
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->lazer];
			cidade->lazer += inc[quantidade->lazer];
			quantidade->lazer++;
			print_candidato(cidade);
		}
		if(cidade->lazer + inc[quantidade->lazer] <= 100){
		cidade->lazer += inc[quantidade->lazer];
		}
		else{
		cidade->lazer = 100;
		}
	}
	else{
		fprintf(stderr, "COMPROU TODOS OS UPGRADES\n");
		return -1;
	}

}
