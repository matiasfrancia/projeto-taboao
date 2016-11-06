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


int main(){

	EVENTO_BOM *bom;
	EVENTO_RUIM *ruim;
	srand((unsigned)time(NULL));
	bom = (EVENTO_BOM *)malloc(1 * sizeof(EVENTO_BOM));
	ruim = (EVENTO_RUIM *)malloc(1 * sizeof(EVENTO_RUIM));

	//chuva insana
	ruim[0].dinheiro = 100000; //dinheiro que vai ser perdido
	ruim[0].saude = 5;
	ruim[0].saneamento = 0;
	ruim[0].lazer = 2;
	ruim[0].seguranca = 0;
	ruim[0].educacao = 0;
	//outros parametros nao serao alterados


	//copa do mundo, objetivo a ser alcançado
	bom[0].dinheiro = 2000000;
	bom[0].seguranca = 70;
	bom[0].lazer = 20;
	bom[0].saude = 10;
	bom[0].saneamento = 0;
	bom[0].educacao = 0;

	
	int select = rand() % 2;
	int i;
	if(select){
		int idx = rand() % 1;
		if(bom[idx].dinheiro != 0){
			printf("DINHEIRO: %d\n", bom[idx].dinheiro);
		}
		if(bom[idx].seguranca != 0){
			printf("SEGURANCA: %d\n", bom[idx].seguranca);
		}
		if(bom[idx].saneamento != 0){
			printf("SANEAMENTO: %d\n", bom[idx].saneamento);
		}
		if(bom[idx].lazer != 0){
			printf("LAZER: %d\n", bom[idx].lazer);
		}
		if(bom[idx].saude != 0){
			printf("SAUDE: %d\n", bom[idx].saude);
		}
	}
	else{

		int idx = rand() % 1;
		if(ruim[idx].dinheiro != 0){
			printf("DINHEIRO: %d\n",ruim[idx].dinheiro);
		}
		if(ruim[idx].seguranca != 0){
			printf("SEGURANCA: %d\n",ruim[idx].seguranca);
		}
		if(ruim[idx].saneamento != 0){
			printf("SANEAMENTO: %d\n",ruim[idx].saneamento);
		}
		if(ruim[idx].lazer != 0){
			printf("LAZER: %d\n",ruim[idx].lazer);
		}
		if(ruim[idx].saude != 0){
			printf("SAUDE: %d\n",ruim[idx].saude);
		}	
	}

	return 0;
}