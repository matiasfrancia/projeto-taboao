// Os arquivos de cabeçalho
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
 
// Para utilizarmos o fprintf
#include <stdio.h>
 
// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

typedef struct prefeito {
      char *nome;
      char *descricao;
      int educacaoInd; 
      int saudeInd; 
      int segurancaInd; 
      int saneamentoInd; 
      int lazerInd;
   }prefeito; 


int main(void){

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *pauseBtnImage = NULL, *soundBtnImage = NULL, *soundBackup = NULL, *fundo = NULL,
        *money = NULL,*majorImage = NULL, *investir = NULL, *garbage = NULL, *educacao = NULL,
        *saude = NULL,*seguranca = NULL, *lazer = NULL, *saneamento = NULL, *clockBtnImage = NULL,
        *voltar = NULL, *pauseBackup = NULL, *playBtnImage = NULL;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
    ALLEGRO_FONT *firstText = NULL, *secondText = NULL, * optionText = NULL, *moneyText = NULL;
    ALLEGRO_TIMER *contador = 0;
    ALLEGRO_BITMAP *botao_sair = NULL;
    ALLEGRO_AUDIO_STREAM *musica = NULL;
    int sair = 0;
    int r = 0, g = 0, b = 0;
    int min = 5, seg = 0;  
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

    al_set_window_title(janela, "Projeto Taboão");

    money = al_load_bitmap("Images/budgetScreen/money-btn.png");
    voltar = al_load_bitmap("Images/globalImages/back-btn.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    educacao = al_load_bitmap("Images/budgetScreen/education-btn.png");
    saude = al_load_bitmap("Images/budgetScreen/health-btn.png");
    seguranca = al_load_bitmap("Images/budgetScreen/security-btn.png");
    lazer = al_load_bitmap("Images/budgetScreen/laze-btn.png");
    saneamento = al_load_bitmap("Images/budgetScreen/sanitation-btn.png");
    garbage = al_load_bitmap("Images/budgetScreen/delete-btn.png");
    investir = al_load_bitmap("Images/budgetScreen/budget-btn.png");
    majorImage = al_load_bitmap("Images/budgetScreen/secondMajor.png");
    pauseBtnImage = al_load_bitmap("Images/globalImages/pauseBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    soundBackup = al_load_bitmap("Images/globalImages/sound-btn.png");
    playBtnImage = al_load_bitmap("Images/chooseImages/playBtnImage.png");
    pauseBackup = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    //settingsBtnImage = al_load_bitmap("Images/chooseImages/settingsBtnImage.png");
    fundo = al_load_bitmap("Images/budgetScreen/tela.png");
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 24,0 );
    optionText = al_load_ttf_font("Font/Arial_Bold.ttf", 14,0 );
    moneyText = al_load_ttf_font("Font/Arial_Bold.ttf", 16,0 );
    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();

    if (!janela || !garbage || !firstText || !secondText || !clockBtnImage || !soundBtnImage || !soundBackup ||
        !investir || !majorImage || !fila_eventos || !optionText || !moneyText || !pauseBackup ||
        !fila_contador || !pauseBtnImage || 
        !contador || !fundo || !al_install_mouse() ||  !money ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao carregar o arquivo.\n");
        al_destroy_display(janela);
        return -1;
    }

    if(!al_init_acodec_addon() || !al_install_audio() || !al_reserve_samples(1)){
        fprintf(stderr, "Falha ao carregar o audio.\n");
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

    char *majorName; 
    char *majorDesc;
    char *pauseText = "PAUSAR";

    int togglePopup = 3;
    int togglePlay = 1;
    int toggleSound = 1; 

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    int candidato = 0;

    while (!sair){
        ALLEGRO_EVENT evento;
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
 
        while (!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT timeout;
            al_init_timeout(&timeout, 0.5);
 
            int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
     
            if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                break;
        
            }
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (evento.mouse.x >= 405 && evento.mouse.x <= 604 &&
                evento.mouse.y >= 163 && evento.mouse.y <= 265){
                sair = 1;
            }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                      evento.mouse.y >= 301 && evento.mouse.y <= 401){
                      sair = 1;
            }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                      evento.mouse.y >= 439 && evento.mouse.y <= 539){
                      sair = 1;
            }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                      evento.mouse.y >= 163 && evento.mouse.y <= 263){
                      sair = 1;
            }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                      evento.mouse.y >= 301 && evento.mouse.y <= 401){
                      sair = 1;
            }else if (evento.mouse.x >= 900 && evento.mouse.x <= 950 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 40){
                      sair = 1;
            }else if (evento.mouse.x >= 140 && evento.mouse.x <= 150 &&
                      evento.mouse.y >= 568 && evento.mouse.y <= 571){
                      sair = 1;
            }else if(togglePopup == 3 && evento.mouse.x >= 815 && evento.mouse.x <= 845 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                
                        togglePlay = 0;
                        pauseText = "PAUSAR";
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                
                }else if (togglePopup == 3 && evento.mouse.x >= 815 && evento.mouse.x <= 845 && 
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 0){
                
                        togglePlay = 1;
                        pauseText = "PLAY";
                        pauseBtnImage = pauseBackup;
                        toggleSound = 1;
                        al_set_audio_stream_playing(musica, false);
                        al_start_timer(contador);
                
                }
        }
        }      

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));
        
        al_draw_bitmap(pauseBtnImage, 815, 25, 0);
        al_draw_bitmap(clockBtnImage, 750, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 827, 23, 0, "PAUSAR");
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());

        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 35, 0, "CONSTRUA UM HOSPITAL");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "Manifestantes queimam materiais e interditam Régis Bittencourt.");
        
        al_draw_bitmap(majorImage, 140, 152, 0);
        al_draw_filled_rectangle(390, 152, 633, 255, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(390, 290, 633, 393, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(390, 428, 633, 542, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 290, 923, 393, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 152, 923, 255, al_map_rgb(60, 60, 59));
        al_draw_bitmap(investir, 539, 226, 0);
        al_draw_bitmap(investir, 539, 364, 0);
        al_draw_bitmap(investir, 539, 502, 0);
        al_draw_bitmap(investir, 824, 226, 0);
        al_draw_bitmap(investir, 824, 364, 0);
        al_draw_bitmap(garbage, 509, 226, 0);
        al_draw_bitmap(garbage, 509, 364, 0);
        al_draw_bitmap(garbage, 509, 502, 0);
        al_draw_bitmap(garbage, 790, 226, 0);
        al_draw_bitmap(garbage, 790, 364, 0);
        al_draw_bitmap(educacao, 405, 163, 0);
        al_draw_bitmap(seguranca, 405, 301, 0);
        al_draw_bitmap(saneamento, 405, 439, 0);
        al_draw_bitmap(saude, 693, 163, 0);
        al_draw_bitmap(lazer, 693, 301, 0);
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 540, 167, ALLEGRO_ALIGN_CENTRE, "EDUCACÃO");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 545, 306, ALLEGRO_ALIGN_CENTRE, "SEGURANCA");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 550, 447, ALLEGRO_ALIGN_CENTRE, "SANEAMENTO");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 813, 167, ALLEGRO_ALIGN_CENTRE, "SAÚDE");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 812, 306, ALLEGRO_ALIGN_CENTRE, "LAZER");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 140, 378, 0, "EDUCACÃO");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 140, 411, 0, "SAÚDE");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 140, 444, 0, "SEGURANCA");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 140, 477, 0, "LAZER");
        al_draw_textf(optionText, al_map_rgb(255, 255, 255), 140, 510, 0, "SANEAMENTO");
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 323, 378, 0, "90%%");
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 323, 411, 0, "82%%");
        al_draw_textf(optionText, al_map_rgb(190, 22, 34), 323, 444, 0, "29%%");
        al_draw_textf(optionText, al_map_rgb(190, 22, 34), 323, 477, 0, "42%%");
        al_draw_textf(optionText, al_map_rgb(05, 150, 64), 323, 510, 0, "73%%");
        int n = 337;
        for (int i = 0; i < 6; i++){
            al_draw_filled_rectangle(140, (n+=1), 350, (n+=32), al_map_rgb(255, 255, 255));        
        }
        al_draw_bitmap(voltar, 140, 568, 0);
        al_draw_bitmap(money, 456, 82, 0);
        al_draw_textf(moneyText, al_map_rgb(104, 94, 35), 486, 87, 0, "R$ 2.000.000,00");
        al_draw_textf(firstText, al_map_rgb(255, 255, 255), 785, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
        
    }

    al_destroy_bitmap(botao_sair);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);

    return 0;

}
