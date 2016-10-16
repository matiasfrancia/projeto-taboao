// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
 
// Para utilizarmos o fprintf
#include <stdio.h>
 
// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

/*
gcc creditScreen.c -o teste $(pkg-config –cflags –libs allegro-5) -lallegro -lallegro_primitives -lallegro_main -lallegro_image


*/

int main(void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    //ALLEGRO_BITMAP *mainScreen = NULL;
    ALLEGRO_BITMAP *taboaoLogoImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *nomes = NULL;

    al_init_font_addon(); 
    al_init_ttf_addon();

    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

 
    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    al_set_window_title(janela, "Projeto Taboão");

 
    taboaoLogoImage = al_load_bitmap("creditImages/taboaoLogoImage.png");
    if (!taboaoLogoImage)
    {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem 1.\n");
        al_destroy_display(janela);
        return -1;
    }
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }
    font = al_load_ttf_font("creditFonts/arial.ttf", 38,0 );
    nomes = al_load_ttf_font("creditFonts/arial.ttf", 15,0 );
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    //al_draw_rounded_rectangle(250, 50, 750, 600, 0.5, 0.5, al_map_rgb(52, 52, 51), 5);
    //al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
    //al_draw_filled_rectangle(252, 48, 748, 598, al_map_rgb(52, 52, 51));
    //al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
    //al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
    //al_draw_text(font, al_map_rgb(255, 255, 255), (1024/2), 80, ALLEGRO_ALIGN_CENTRE, "CREDITOS");
    //al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 150, 0, "*              Caio Luzano");
    //al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 200, 0, "*              Daniel Moniz");
    //al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 250, 0, "*              Henrique Shodi");
    //al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 300, 0, "*              Luiz Frederico");
    //al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 350, 0, "*              Matheus Souza");
    //al_draw_filled_rectangle(250, 50, 750, 650, al_map_rgb(52, 52, 51));
    //al_draw_bitmap(mainScreen, 400, 450, 0);
 
    while(1){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
        
        al_draw_rounded_rectangle(250, 50, 750, 600, 0.5, 0.5, al_map_rgb(52, 52, 51), 5);
        al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
        al_draw_filled_rectangle(252, 48, 748, 598, al_map_rgb(52, 52, 51));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
        al_draw_text(font, al_map_rgb(255, 255, 255), (1024/2), 80, ALLEGRO_ALIGN_CENTRE, "CREDITOS");
        al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 150, 0, "*                     Caio Luzano");
        al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 200, 0, "*                     Daniel Moniz");
        al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 250, 0, "*                     Henrique Shodi");
        al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 300, 0, "*                     Luiz Frederico");
        al_draw_text(nomes, al_map_rgb(255, 255, 255), (1024/4), 350, 0, "*                     Matheus Souza");
        //al_draw_filled_rectangle(250, 50, 750, 650, al_map_rgb(52, 52, 51));
        //al_draw_bitmap(mainScreen, 400, 450, 0);

        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}