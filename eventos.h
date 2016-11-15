#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *positivo[] = {"Sua Cidade foi escolhida para fazer a abertura dos Jogos Olimpicos", 
					"O próximo Brasil Game Show acontecerá em Taboão da Serra",
					"O São Paulo Fashion Week poderá ser em Taboão",
					"O Lollapalooza desta vez será em Taboão",
					"Um grupo influente de alemães veio para Taboão, o proximo Oktoberfest será aqui"
					};

char *negatico[] = {"Chuva muito forte, realmente muito forte, em Taboão",
					"Fortes ventos em Taboão",
					"Um vírus misterioso atingiu Taboão",
					"Uma bactéria misteriosa está infectando os moradores de Taboão",
					"Muitos raios antingem Taboão"
					};

void select_event_description(char ***text, int a){
	srand((unsigned)time(NULL));
	int idx = rand() % 5;
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
	int educacao;
	int saneamento;
	int seguranca;
	int lazer;

}EVENTO_RUIM;

void select_evento_ruim(EVENTO_RUIM *aux){
	
	EVENTO_RUIM *ruim;
	srand((unsigned)time(NULL));
	ruim = (EVENTO_RUIM *)malloc(3 * sizeof(EVENTO_RUIM));

	//chuva insana
	ruim[0].dinheiro = -100000; //dinheiro que vai ser perdido
	ruim[0].saude = -12;
	ruim[0].saneamento = -10;
	ruim[0].lazer = -5;
	ruim[0].seguranca = -3;
	ruim[0].educacao = -13;
	//outros parametros nao serao alterados

	//Terremoto
	ruim[1].dinheiro = -500000;
	ruim[1].saude = 0;
	ruim[1].saneamento = -10;
	ruim[1].lazer = -10;
	ruim[1].seguranca = -10;
	ruim[1].educacao = -10;

	//Aliens invadiram Taboao
	ruim[2].dinheiro = -1000000;
	ruim[2].saude = -20;
	ruim[2].saneamento = 0;
	ruim[2].lazer = -30;
	ruim[2].seguranca = -20;
	ruim[2].educacao = -50; //eles nos deixam burros! idhauifhiwu

	int idx = rand() % 3; //seleciona um indice aleatorio do vetor ruim idem para EVENTO_BOM
	aux->dinheiro = ruim[idx].dinheiro; //atribui valores a struct adicional
	aux->seguranca = ruim[idx].seguranca;
	aux->saneamento = ruim[idx].saneamento;
	aux->lazer = ruim[idx].lazer;
	aux->saude = ruim[idx].saude;
	aux->educacao = ruim[idx].educacao;

}

void select_evento_bom(EVENTO_BOM *aux){

	EVENTO_BOM *bom;
	srand((unsigned)time(NULL));
	
	bom = (EVENTO_BOM *)malloc(3 * sizeof(EVENTO_BOM));
	
	//copa do mundo, objetivo a ser alcançado
	bom[0].dinheiro = 2000000;
	bom[0].investimento = 1000000;
	bom[0].seguranca = 70;
	bom[0].lazer = 20;
	bom[0].saude = 10;
	bom[0].saneamento = 14;
	bom[0].educacao = 2;

	//olimpiada
	bom[1].dinheiro = 700000;
	bom[1].investimento = 500000;
	bom[1].seguranca = 50;
	bom[1].lazer = 30;
	bom[1].saude = 5;
	bom[1].saneamento = 10;
	bom[1].educacao = 13;

	//campus party
	bom[2].dinheiro = 800000;
	bom[2].investimento = 250000;
	bom[2].seguranca = 90;
	bom[2].lazer = 0;
	bom[2].saude = 0;
	bom[2].saneamento = 5;
	bom[2].educacao = 30;


	int idx = rand() % 3;
	aux->dinheiro = bom[idx].dinheiro;
	aux->investimento = bom[idx].investimento;
	aux->seguranca = bom[idx].seguranca;
	aux->lazer = bom[idx].lazer;
	aux->saude = bom[idx].saude;
	aux->saneamento = bom[idx].saneamento;
	aux->educacao = bom[idx].educacao;

	
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
