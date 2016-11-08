// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
 
// Para utilizarmos o fprintf
#include <stdio.h>
 
// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;
 

int main(void){

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *taboaoLogoImage = NULL, *fundo = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *configText = NULL, *songText = NULL;
    ALLEGRO_AUDIO_STREAM *musica = NULL;
    int sair = 0;
    al_init_font_addon(); 
    al_init_ttf_addon();


    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }
 
    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return -1;
    }
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela){
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    al_set_window_title(janela, "Projeto Taboão");
    fila_eventos = al_create_event_queue();
    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoLogoImage.png");
    
    if (!taboaoLogoImage || !al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)||
     !al_install_audio() || !al_init_acodec_addon() || !al_reserve_samples(1) || !fila_eventos){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }
    musica = al_load_audio_stream("teste.ogg", 4, 1024);
    if (!musica)
    {
        fprintf(stderr, "Falha ao carregar audio.\n");
        al_destroy_event_queue(fila_eventos);
        al_destroy_display(janela);
        return false;
    }
    

    configText = al_load_ttf_font("Font/arial.ttf", 33,0 );
    songText = al_load_ttf_font("Font/arial.ttf", 25,0 );

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    while (!sair){
      while (!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT timeout;
            al_init_timeout(&timeout, 0.5);
 
            int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
     
            if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                sair = 1;
            }
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                if (evento.mouse.x >= 145 && evento.mouse.x <= 315 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                       al_reserve_samples(0);
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        al_reserve_samples(1);
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        al_reserve_samples(2);
                    }
                }
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));

        
        al_draw_filled_rectangle(100, 45, 900, 666, al_map_rgb(87, 87, 86));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_text(configText, al_map_rgb(255, 255, 255), (1024/2), 70, ALLEGRO_ALIGN_CENTRE, "CONFIGURAÇÕES");
        al_draw_text(songText, al_map_rgb(255, 255, 255), 200, 200, 0, "Volume");
        //al_draw_filled_rectangle(690, 197, 700, 237, al_map_rgb(255, 255, 255));
        al_draw_filled_rectangle(300, 212, 800, 222, al_map_rgb(255, 255, 255));
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        al_set_audio_stream_playing(musica, true);

        al_flip_display();


    }

    al_destroy_audio_stream(musica);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;

}