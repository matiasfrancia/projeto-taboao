#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct evento_bom{
	//eventos para longo prazo, objetivos até o fim do mandato.
	//pode aceitar ou nao
	int dinheiro;
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
	ruim = (EVENTO_RUIM *)malloc(1 * sizeof(EVENTO_RUIM));

	//chuva insana
	ruim[0].dinheiro = 100000; //dinheiro que vai ser perdido
	ruim[0].saude = 5;
	ruim[0].saneamento = 0;
	ruim[0].lazer = 2;
	ruim[0].seguranca = 0;
	ruim[0].educacao = 0;
	//outros parametros nao serao alterados

	int idx = rand() % 1;
	aux->dinheiro = ruim[idx].dinheiro;
	aux->seguranca = ruim[idx].seguranca;
	aux->saneamento = ruim[idx].saneamento;
	aux->lazer = ruim[idx].lazer;
	aux->saude = ruim[idx].saude;
	aux->educacao = ruim[idx].educacao;

}

void select_evento_bom(EVENTO_BOM *aux){

	EVENTO_BOM *bom;
	srand((unsigned)time(NULL));
	
	bom = (EVENTO_BOM *)malloc(1 * sizeof(EVENTO_BOM));
	
	//copa do mundo, objetivo a ser alcançado
	bom[0].dinheiro = 2000000;
	bom[0].seguranca = 70;
	bom[0].lazer = 20;
	bom[0].saude = 10;
	bom[0].saneamento = 0;
	bom[0].educacao = 0;


	int idx = rand() % 1;
	aux->dinheiro = bom[idx].dinheiro;
	aux->seguranca = bom[idx].seguranca;
	aux->lazer = bom[idx].lazer;
	aux->saude = bom[idx].saude;
	aux->saneamento = bom[idx].saneamento;
	aux->educacao = bom[idx].educacao;

	
}


/*
###############################################################################################
#																							  #	
#																							  #
#			         FUNCAO MAIN DEVERÁ CHAMAR FUNCAO DA SEGUINTE FORMA:                      #
#																							  #
#																							  #
###############################################################################################

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