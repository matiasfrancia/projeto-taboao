int precos[] = {1000000, 5000000, 10000000, 50000000, 100000000};

int inc[] = {5, 5, 10, 10, 25};

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

int compra_saude(CANDIDATO *cidade, ITEM *quantidade){

	if(quantidade->saude < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->saude]){
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->saude];
			cidade->saude += inc[quantidade->saude];
			quantidade->saude++;
		}
	}
	else{
		return -1;
	}

}

int compra_saneamento(CANDIDATO *cidade, ITEM *quantidade){

	if(quantidade->saneamento < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->saneamento]){
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->saneamento];
			cidade->saneamento += inc[quantidade->saneamento];
			quantidade->saneamento++;
		}
	}
	else{
		return -1;
	}

}

int compra_seguranca(CANDIDATO *cidade, ITEM *quantidade){

	if(quantidade->seguranca < (sizeof(inc) / sizeof(int))){
		if(cidade->dinheiro < precos[quantidade->seguranca]){
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->seguranca];
			cidade->seguranca += inc[quantidade->seguranca];
			quantidade->seguranca++;
		}
	}
	else{
		return -1;
	}

}

int compra_educacao(CANDIDATO *cidade, ITEM *quantidade){

	if(quantidade->educacao < (sizeof(inc) / sizeof(int))){
		if(cidade->educacao < precos[quantidade->educacao]){
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->educacao];
			cidade->educacao += inc[quantidade->educacao];
			quantidade->educacao++;
		}
	}
	else{
		return -1;
	}

}

int compra_lazer(CANDIDATO *cidade, ITEM *quantidade){

	if(quantidade->lazer < (sizeof(inc) / sizeof(int))){
		if(cidade->lazer < precos[quantidade->lazer]){
			return -1;
		}
		else{
			cidade->dinheiro -= precos[quantidade->lazer];
			cidade->lazer += inc[quantidade->lazer];
			quantidade->lazer++;
		}
	}
	else{
		return -1;
	}

}
