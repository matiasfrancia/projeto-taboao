//Cabeçalho da biblioteca Allegro
#include <allegro5/allegro.h>
//Cabeçalho do add-on de imagens
#include <allegro5/allegro_image.h>

int main(){

    //variável da janela principal
    ALLEGRO_DISPLAY *janela;

    // variável da imagem
    ALLEGRO_BITMAP *imagem;

    //inicializa a Allegro
    al_init();

    //inicializa add-on para utilização de imagens
    al_init_image_addon();

    //carrega janela
    janela = al_create_display(1000, 745);

    //Carrega a imagem.
    imagem = al_load_bitmap("trump_bingolinha.jpg");

    //desenha a imagem na tela
    al_draw_bitmap(imagem, 0, 0, 0);
    //Primeiro imagem, posição x, posição y, Flags de posicionamento (ALLEGRO_FLIP_VERTICAL ou ALLEGRO_FLIP_HORIZONTAL)

    //atualiza a tela
    al_flip_display();

    //segura a execução por 10 segundos 
    al_rest(2.0);

    // finaliza a janela
    al_destroy_display(janela);

    return 0;

}
