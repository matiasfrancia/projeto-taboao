// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
 
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

int main(void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *taboaoLogoImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *font = NULL;

    al_init_font_addon(); 
    al_init_ttf_addon();

    if (!al_init()) {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }
 
    if (!al_init_image_addon()) {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela) {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    al_set_window_title(janela, "Projeto Taboão");

 
    taboaoLogoImage = al_load_bitmap("Images/winnerScreen/winner-btn.png");
    fila_eventos = al_create_event_queue();
    font = al_load_ttf_font("Font/Arial_Bold.ttf", 34,0 );
    if (!taboaoLogoImage || !fila_eventos || !font ) {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem 1.\n");
        al_destroy_display(janela);
        return -1;
    }
   
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    while(1){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
        
        al_draw_bitmap(taboaoLogoImage,  420, 200, 0);
        al_draw_text(font, al_map_rgb(0,150,64),  (1024/2), 450, ALLEGRO_ALIGN_CENTRE, "PARABÉNS, VOCÊ GANHOU!");

        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}