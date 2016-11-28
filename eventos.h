#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
time_t t;

char *positivo[] = 		   {"Sua Cidade foi escolhida para fazer a abertura dos Jogos Olimpicos", 
							"O próximo Brasil Game Show acontecerá em Taboão da Serra",
							"O São Paulo Fashion Week poderá ser em Taboão",
							"O Lollapalooza desta vez será em Taboão",
							"Um grupo influente de alemães veio para Taboão, o proximo Oktoberfest será aqui",
							"CATS(Clube atlético Taboão da Serra) disputará uma grande final",
							"Taboão gera atenção de turistas por grande frequência de relatos de OVINIS",
							"A final do próximo CBLOL ocorrerá no Estádio Municial de Taboão da Serra",
							"Ocorrerá uma Tomorrowland em Taboão",
							"Taboão chama atenção de empresas por sua localidade estratégica"
							};

char *negativo[] = 		   {"Chuva muito forte, realmente muito forte, em Taboão",
							"Fortes ventos em Taboão",
							"Um vírus misterioso atingiu Taboão",
							"Uma bactéria misteriosa está infectando os moradores de Taboão",
							"Terremoto causa grande dano em Taboão",
							"O shopping Taboão foi alvo de um atentado terrorista",
							"Taboão terá que pagar uma divida externa"
							"Sequencias de assaltos aterroziram cidadãos taboanenses",
							"Muitos raios antingem Taboão",
							"Chuva alaga a única avenida de Taboão"
							};

char *projetos_educacao[] = {"FEIRA DO LIVRO",
							 "PALESTRA EDUCATIVA",
							 "FEIRA DE ASTRONOMIA",
							 "FEIRA DE CIÊNCIA",
							 "OLIMPIADAS DE MATEMÁTICA",
							 "OLIMPIADAS DE FÍSICA",
							 "RODA DE ARTE",
							 "HACKATON",
							 "GRUPO DE DEBATE",
							 "CONCURSO DE ARTE"
							};

char *projetos_lazer[]    = {"FEIRA DE GASTRONOMIA",
							 "GRANDE MARATONA",
							 "FESTAS COMEMORATIVAS",
							 "ENCONTRO DE LAZER",
							 "FEIRA DE AUTOMOVEIS",
							 "INCENTIVO AO ESPORTE",
							 "EVENTOS NOTURNOS"
							};
char *projetos_seguranca[] = {"AUMENTO R$ PARA POLICIA",
							 "AUMENTO DA RONDA POLICIAL",
							 "ALISTAMENTO MELHORADO",
							 "MELHORIA NA SEGURANÇA",
							 "CONCURSO PARA POLICIA",
							 "CONSURSO PARA BOMBEIROS"
							};

char *projetos_saneamento[] = {"MELHORIA NO ENCANAMENTO",
							  "DESPOLUIÇÃO DO RIO TABOCA",
							  "MELHORIA PERIFERIA",
							  "ASFALTAMENTO",
							  "INCENTIVO À RECICLAGEM",
							  "CONTROLE DE PRAGA URBANA"
							};

char *projetos_saude[]     = {"MELHORIAS NOS HOSPITAIS",
							  "VACINAS",
							  "INCENTIVO À PRESERVATIVOS",
							  "CAMPANHA DE HIGIENE",
							  "EXAMES GRATUITOS",
							  "LUTA CONTRA A DENGUE",
							  "CAMPANHA CONTRA DOENÇAS",
							  "CONTROLE DE PRAGA URBANA"
							};

void select_event_description(char ***text, int a){
	srand((unsigned)time(&t));
	int idx = rand() % 6;
	if(a == 0){
		*text = &positivo[idx];
	}
	if(a == 1){
		*text = &negativo[idx];
	}
}

typedef struct evento_bom{
	//eventos para longo prazo, objetivos até o fim do mandato.
	//pode aceitar ou nao
	int dinheiro;
	char *text;
	int investimento;
	int saude;
	int educacao;
	int saneamento;
	int seguranca;
	int lazer;

}EVENTO_BOM;

typedef struct evento_ruim{
	//evento instantaneo, desastre natural.
	//nao tem opcao de aceitar.
	int dinheiro;
	int saude;
	char *text;
	int educacao;
	int saneamento;
	int seguranca;
	int lazer;

}EVENTO_RUIM;


void select_evento_ruim(EVENTO_RUIM *aux){
	
	EVENTO_RUIM *ruim;
	srand((unsigned)time(&t));
	ruim = (EVENTO_RUIM *)malloc(10 * sizeof(EVENTO_RUIM));

	//chuva insana
	ruim[0].dinheiro = -100000; //dinheiro que vai ser perdido
	ruim[0].text = "CUSTO DE R$100.000";
	ruim[0].saude = -6;
	ruim[0].saneamento = 0;
	ruim[0].lazer = -4;
	ruim[0].seguranca = 0;
	ruim[0].educacao = 0;
	//outros parametros nao serao alterados

	//Terremoto
	ruim[1].dinheiro = -250000;
	ruim[1].saude = 0;
	ruim[1].text = "CUSTO DE R$250.000";
	ruim[1].saneamento = -4;
	ruim[1].lazer = 0;
	ruim[1].seguranca = -5;
	ruim[1].educacao = -6;

	//Aliens invadiram Taboao
	ruim[2].dinheiro = -500000;
	ruim[2].text = "CUSTO DE R$500.000";
	ruim[2].saude = -7;
	ruim[2].saneamento = -2;
	ruim[2].lazer = -3;
	ruim[2].seguranca = -8;
	ruim[2].educacao = 0; //eles nos deixam burros! idhauifhiwu

	ruim[3].dinheiro = -750000;
	ruim[3].saude = 5;
	ruim[3].text = "CUSTO DE R$750.000";
	ruim[3].saneamento = -8;
	ruim[3].lazer = -6;
	ruim[3].seguranca = -6;
	ruim[3].educacao = -4;

	ruim[4].dinheiro = -1000000;
	ruim[4].saude = -7;
	ruim[4].text = "CUSTO DE R$1.000.000";
	ruim[4].saneamento = -7;
	ruim[4].lazer = -9;
	ruim[4].seguranca = -7;
	ruim[4].educacao = -10;

	ruim[5].dinheiro = -100000; 
	ruim[5].text = "CUSTO DE R$100.000";
	ruim[5].saude = -1;
	ruim[5].saneamento = -3;
	ruim[5].lazer = -2;
	ruim[5].seguranca = -2;
	ruim[5].educacao = -2;

	ruim[6].dinheiro = -100000; 
	ruim[6].text = "CUSTO DE R$100.000";
	ruim[6].saude = 0;
	ruim[6].saneamento = -2;
	ruim[6].lazer = 0;
	ruim[6].seguranca = -6;
	ruim[6].educacao = -2;

	ruim[7].dinheiro = -250000; 
	ruim[7].text = "CUSTO DE R$250.000";
	ruim[7].saude = 0;
	ruim[7].saneamento = -5;
	ruim[7].lazer = -7;
	ruim[7].seguranca = -3;
	ruim[7].educacao = 0;

	ruim[8].dinheiro = -250000; 
	ruim[8].text = "CUSTO DE R$250.000";
	ruim[8].saude = -4;
	ruim[8].saneamento = 0;
	ruim[8].lazer = -4;
	ruim[8].seguranca = 0;
	ruim[8].educacao = -7;

	ruim[9].dinheiro = -500000; 
	ruim[9].text = "CUSTO DE R$500.000";
	ruim[9].saude = -1;
	ruim[9].saneamento = -4;
	ruim[9].lazer = -4;
	ruim[9].seguranca = -4;
	ruim[9].educacao = -4;

	int idx = rand() % 10; //seleciona um indice aleatorio do vetor ruim idem para EVENTO_BOM
	aux->dinheiro = ruim[idx].dinheiro; //atribui valores a struct adicional
	aux->seguranca = ruim[idx].seguranca;
	aux->text = ruim[idx].text;
	aux->saneamento = ruim[idx].saneamento;
	aux->lazer = ruim[idx].lazer;
	aux->saude = ruim[idx].saude;
	aux->educacao = ruim[idx].educacao;

}

void select_evento_bom(EVENTO_BOM *aux){

	EVENTO_BOM *bom;
	srand((unsigned)time(&t));
	
	bom = (EVENTO_BOM *)malloc(10 * sizeof(EVENTO_BOM));
	
	//copa do mundo, objetivo a ser alcançado
	bom[0].dinheiro = 200000;
	bom[0].investimento = 100000;
	bom[0].text = "INVESTIMENTO: R$100.000";
	bom[0].seguranca = 2;
	bom[0].lazer = 2;
	bom[0].saude = 2;
	bom[0].saneamento = 4;
	bom[0].educacao = 0;

	//olimpiada
	bom[1].dinheiro = 500000;
	bom[1].investimento = 250000;
	bom[1].text = "INVESTIMENTO: R$250.000";
	bom[1].seguranca = 7;
	bom[1].lazer = 0;
	bom[1].saude = 5;
	bom[1].saneamento = 5;
	bom[1].educacao = 8;

	//campus party
	bom[2].dinheiro = 1000000;
	bom[2].investimento = 500000;
	bom[2].text = "INVESTIMENTO: R$500.000";
	bom[2].seguranca = 6;
	bom[2].lazer = 6;
	bom[2].saude = 12;
	bom[2].saneamento = 6;
	bom[2].educacao = 3;

	bom[3].dinheiro = 1500000;
	bom[3].investimento = 750000;
	bom[3].text = "INVESTIMENTO: R$750.000";
	bom[3].seguranca =8 ;
	bom[3].lazer = 9;
	bom[3].saude = 7;
	bom[3].saneamento = 11;
	bom[3].educacao = 5;

	bom[4].dinheiro = 2000000;
	bom[4].investimento = 1000000;
	bom[4].text = "INVESTIMENTO: R$1.000.000";
	bom[4].seguranca = 8;
	bom[4].lazer = 11;
	bom[4].saude = 9;
	bom[4].saneamento = 7;
	bom[4].educacao = 15;

	bom[5].dinheiro = 2000000;
	bom[5].investimento = 1000000;
	bom[5].text = "INVESTIMENTO: R$1.000.000";
	bom[5].seguranca = 10;
	bom[5].lazer = 10;
	bom[5].saude = 10;
	bom[5].saneamento = 8;
	bom[5].educacao = 12;

	bom[6].dinheiro = 1000000;
	bom[6].investimento = 1000000;
	bom[6].text = "INVESTIMENTO: R$1.000.000";
	bom[6].seguranca = 15;
	bom[6].lazer = 5;
	bom[6].saude = 9;
	bom[6].saneamento = 13;
	bom[6].educacao = 8;

	bom[7].dinheiro = 1000000;
	bom[7].investimento = 500000;
	bom[7].text = "INVESTIMENTO: R$500.000";
	bom[7].seguranca = 5;
	bom[7].lazer = 5;
	bom[7].saude = 7;
	bom[7].saneamento = 4;
	bom[7].educacao = 9;

	bom[8].dinheiro = 1500000;
	bom[8].investimento = 750000;
	bom[8].text = "INVESTIMENTO: R$750.000";
	bom[8].seguranca =12 ;
	bom[8].lazer = 8;
	bom[8].saude = 4;
	bom[8].saneamento = 9;
	bom[8].educacao = 8;

	bom[9].dinheiro = 2000000;
	bom[9].investimento = 1000000;
	bom[9].text = "INVESTIMENTO: R$1.000.000";
	bom[9].seguranca = 8;
	bom[9].lazer = 7;
	bom[9].saude = 15;
	bom[9].saneamento = 10;
	bom[9].educacao = 10;


	int idx = rand() % 10;
	aux->dinheiro = bom[idx].dinheiro;
	aux->investimento = bom[idx].investimento;
	aux->text = bom[idx].text;
	aux->seguranca = bom[idx].seguranca;
	aux->lazer = bom[idx].lazer;
	aux->saude = bom[idx].saude;
	aux->saneamento = bom[idx].saneamento;
	aux->educacao = bom[idx].educacao;
	
}

void aplica_alteracao(CANDIDATO *cidade, CANDIDATO *item){
	cidade->dinheiro += item->dinheiro;
	
	if(cidade->saneamento + item->saneamento <= 100){
		cidade->saneamento += item->saneamento;
	}
	else{
		cidade->saneamento = 100;
	}
	
	if(cidade->saude + item->saude <= 100){
		cidade->saude += item->saude;
	}
	else{
		cidade->saude = 100;
	}

	if(cidade->seguranca + item->seguranca <=100){
		cidade->seguranca += item->seguranca;
	}
	else{
		cidade->seguranca = 100;
	}

	if(cidade->lazer + item->lazer <= 100){
		cidade->lazer += item->lazer;
	}
	else{
		cidade->lazer = 100;
	}
	
	if(cidade->educacao + item->educacao <= 100){
		cidade->educacao += item->educacao;
	}
	else{
		cidade->educacao = 100; 
	}
	

}

void select_projeto_random(CANDIDATO *aux){


	int random = rand() % 5;
	if(random == 1 ){
		random = rand() % 10;
		aux->dinheiro = -(10000 * (rand() % 101)); 						//preco varia entre 1000 e 10000
		aux->nome = &projetos_educacao[random];
		aux->educacao = 5;
		aux->seguranca = 0;
		aux->saude = 0;
		aux->lazer = 0;
		aux->saneamento = 0;
	}
	else if(random == 2){
		random = rand() % 6;
		aux->dinheiro = -(10000 * (rand() % 101));
		aux->nome = &projetos_lazer[random];
		aux->lazer = 5;
		aux->saude = 0;
		aux->saneamento = 0;
		aux->seguranca = 0;
		aux->educacao = 0;
	}
	else if(random == 3){
		random = rand() % 6;
		aux->dinheiro = -(10000 * (rand() % 101));
		aux->nome = &projetos_seguranca[random];
		aux->lazer = 0;
		aux->saude = 0;
		aux->saneamento = 0;
		aux->seguranca = 5;
		aux->educacao = 0;
	}
	else if(random == 4){
		random = rand() % 6;
		aux->dinheiro = -(10000 * (rand() % 101));
		aux->nome = &projetos_saneamento[random];
		aux->lazer = 0;
		aux->saude = 0;
		aux->saneamento = 5;
		aux->seguranca = 0;
		aux->educacao = 0;
	}
	else if(random == 0){
		random = rand() % 7;
		aux->dinheiro = -(10000 * (rand() % 100));
		aux->nome = &projetos_saude[random];
		aux->lazer = 0;
		aux->saude = 5;
		aux->saneamento = 0;
		aux->seguranca = 0;
		aux->educacao = 0;
	}
	printf("RANDOM: %d\n", random);

}

CANDIDATO* select_projeto(){

	CANDIDATO *vector_de_projetos;
	vector_de_projetos = (CANDIDATO *)malloc(6 * sizeof(CANDIDATO));
	srand((unsigned)time(&t));
	for(int i = 0; i < 6; i++){
		select_projeto_random(&vector_de_projetos[i]);
	}
	return vector_de_projetos;
}

void aplica_evento_ruim(CANDIDATO *cidade, EVENTO_RUIM evento){

	if(cidade->educacao + evento.educacao >= 0){
		cidade->educacao += evento.educacao;
	}
	else{
		cidade->educacao = 0;
	}


	if(cidade->seguranca + evento.seguranca >= 0){
		cidade->seguranca += evento.seguranca;
	}
	else{
		cidade->seguranca = 0;
	}

	if(cidade->saude + evento.saude >= 0){
		cidade->saude += evento.saude;
	}
	else{
		cidade->saude = 0;
	}

	if(cidade->saneamento + evento.saneamento >= 0){
		cidade->saneamento += evento.saneamento;
	}
	else{
		cidade->saneamento = 0;
	}

	if(cidade->lazer + evento.lazer >= 0){
		cidade->lazer += evento.lazer;
	}
	else{
		cidade->lazer = 0;
	}
}

void aplica_evento_bom(CANDIDATO *cidade, EVENTO_BOM evento){

	if(cidade->educacao + evento.educacao <= 100){
		cidade->educacao += evento.educacao;
	}
	else{
		cidade->educacao = 100;
	}


	if(cidade->seguranca + evento.seguranca <= 100){
		cidade->seguranca += evento.seguranca;
	}
	else{
		cidade->seguranca = 100;
	}

	if(cidade->saude + evento.saude <= 100){
		cidade->saude += evento.saude;
	}
	else{
		cidade->saude = 100;
	}

	if(cidade->saneamento + evento.saneamento <= 100){
		cidade->saneamento += evento.saneamento;
	}
	else{
		cidade->saneamento = 100;
	}

	if(cidade->lazer + evento.lazer <= 100){
		cidade->lazer += evento.lazer;
	}
	else{
		cidade->lazer = 100;
	}
}

/*

#################################################################################
#																				#	
#																				#
#       FUNCAO DE SELECAO DE EVENTOS DEVERA SER CHAMADA DA SEGUINTE FORMA:      #
#																				#
#																				#
#################################################################################


int main(int argc, char const *argv[]){
	
	EVENTO_BOM bom;
	EVENTO_RUIM ruim;
	srand((unsigned)time(NULL));
	int decide = rand() % 2;
	if(decide == 1){
		select_evento_bom(&bom);
		printf("EVENTO BOM\nSAUDE: %d\n", bom.saude);
		printf("DINHEIRO: %d\n", bom.dinheiro);
		printf("SEGURANCA: %d\n", bom.seguranca);
		printf("LAZER: %d\n", bom.lazer);
		printf("SANEAMTENO: %d", bom.saneamento);
		printf("EDUCACAO: %d\n", bom.educacao);
	}
	else{
		select_evento_ruim(&ruim);
		printf("EVENTO RUIM\nSAUDE: %d\n", ruim.saude);
		printf("DINHEIRO: %d\n", ruim.dinheiro);
		printf("SEGURANCA: %d\n", ruim.seguranca);
		printf("LAZER: %d\n", ruim.lazer);
		printf("SANEAMTENO: %d\n", ruim.saneamento);
		printf("EDUCACAO: %d\n", ruim.educacao);
	}
	return 0;
}
*/
