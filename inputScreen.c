#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "eventos.h"
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

int main(void){
    ALLEGRO_DISPLAY *janela = NULL;
 	ALLEGRO_BITMAP *fundo = NULL,
    			   *taboaoLogoImage = NULL, *pauseBtnImage = NULL, *muteBtnImage = NULL, *clockBtnImage = NULL, *soundBtnImage = NULL,
    			   *soundBackup = NULL, *education = NULL, *security = NULL, *sanitation = NULL, *health = NULL, *laze = NULL, *investir = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
    ALLEGRO_FONT *firstText = NULL, *secondText = NULL;
    ALLEGRO_TIMER *contador = 0;
    int min = 5, seg = 0; 
 	al_init_font_addon(); 
    al_init_ttf_addon();


    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro 5\n");
        return -1;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }

    al_set_window_title(janela, "Projeto Taboão");



    fundo = al_load_bitmap("Images/eventScreen/eventScreen.png");
    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoLogoImage.png");
    pauseBtnImage = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    muteBtnImage = al_load_bitmap("Images/globalImages/mute-btn.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    soundBackup = al_load_bitmap("Images/globalImages/sound-btn.png");
    education = al_load_bitmap("Images/eventScreen/educationOption.png");
    security = al_load_bitmap("Images/eventScreen/securityOption.png");
    sanitation = al_load_bitmap("Images/eventScreen/sanitationOption.png");
    health = al_load_bitmap("Images/eventScreen/healthOption.png");
    laze = al_load_bitmap("Images/eventScreen/funOption.png");
    investir = al_load_bitmap("Images/eventScreen/investimentBtn.png");
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 20,0 );
    fila_eventos = al_create_event_queue();
    fila_contador = al_create_event_queue();
    contador = al_create_timer(1.0);

    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();


    if (!fundo || !taboaoLogoImage || !pauseBtnImage || !muteBtnImage || !pauseBtnImage || !clockBtnImage || !soundBtnImage ||
    	!soundBackup || !fila_eventos|| !fila_contador || !contador || !firstText || !education || !security || !sanitation ||
    	!health || !laze || !investir || !secondText){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }
 

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    while (1){

        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }


        if (!al_is_event_queue_empty(fila_contador)){
            al_wait_for_event(fila_contador, &evento);
 
            if (evento.type == ALLEGRO_EVENT_TIMER)
            {
                seg--;
                if (seg == -1)
                {
                    min--;
                    seg = 59;
                }
            }
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_set_target_bitmap(al_get_backbuffer(janela));
        al_draw_bitmap(pauseBtnImage, 830, 25, 0);
        al_draw_bitmap(clockBtnImage, 765, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 840, 23, 0, "PAUSAR");
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "AS ELEIÇÕES ESTÃO PRÓXIMAS");
        al_draw_text(secondText, al_map_rgb(255, 255, 255), 500+25, 240, ALLEGRO_ALIGN_CENTRE, "DIGITE O NOME DE SEU EVENTO:");
        al_draw_filled_rectangle(352+15, 280, 670+15, 311, al_map_rgb(255, 255, 255));
        al_draw_text(secondText, al_map_rgb(255, 255, 255), 500+15, 330, ALLEGRO_ALIGN_CENTRE, "ONDE VOCE DESEJA INVESTIR:");
        al_draw_bitmap(education, 352+15, 382, 0);
        al_draw_bitmap(security, 418+15, 382, 0);
        al_draw_bitmap(sanitation, 486+15, 382, 0);
        al_draw_bitmap(health, 551+15, 382, 0);
        al_draw_bitmap(laze, 618+15, 382, 0);
        al_draw_bitmap(investir, 357+15, 460, 0);

        al_flip_display();
    
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}