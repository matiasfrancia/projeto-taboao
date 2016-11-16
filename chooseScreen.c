#include "structs.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <stdlib.h>
 
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720; 
int r =0;
int g =150; 
int b = 64;

void colorValidation(int n, int *r, int *g, int *b){
    if (n < 50) {
            *r = 0;
            *g = 150;
            *b = 64; 
        }else {
            *r = 190;
            *g = 22;
            *b = 34;
        }
}
  
int main(void){

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *taboaoLogoImage = NULL, *thirdPersonaImage = NULL, *firstPersonaImage = NULL, 
        *secondPersonaImage = NULL, *fundo = NULL, *pauseBtnImage = NULL, *soundBtnImage = NULL, 
        *muteBtnImage = NULL, *soundBackup = NULL, *clockBtnImage = NULL, *education = NULL, 
        *fun = NULL, *health = NULL, *sanitation = NULL, *security = NULL, *fundo2 = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
    ALLEGRO_FONT *firstText = NULL, *secondText = NULL, *nameText = NULL, *infoText = NULL, *optionText =  NULL;
    ALLEGRO_TIMER *contador = 0;
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_AUDIO_STREAM *musica = NULL;
    int sair = 0;
    int min = 5, seg = 0; 
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

 
    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoLogoImage.png");
    firstPersonaImage = al_load_bitmap("Images/chooseImages/firstPersonaImage.png");
    secondPersonaImage = al_load_bitmap("Images/chooseImages/secondPersonaImage.png");
    
    pauseBtnImage = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    muteBtnImage = al_load_bitmap("Images/globalImages/mute-btn.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    soundBackup = al_load_bitmap("Images/globalImages/sound-btn.png");
    education = al_load_bitmap("Images/globalImages/education-btn.png");
    fun = al_load_bitmap("Images/globalImages/fun-btn.png");
    health = al_load_bitmap("Images/globalImages/health-btn.png");
    sanitation = al_load_bitmap("Images/globalImages/sanitation-btn.png");
    security = al_load_bitmap("Images/globalImages/security-btn.png"); 
    fundo2 = al_load_bitmap("Images/chooseImages/chooseScreen.png");
    fonte = al_load_font("Font/arial.ttf", 11,00);
    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 22,0 );
    nameText = al_load_ttf_font("Font/Arial_Bold.ttf", 24,0 );
    infoText = al_load_ttf_font("Font/Arial_Bold.ttf", 18,0 );
    optionText = al_load_ttf_font("Font/Arial_Bold.ttf", 14,0 );
    
    if (!taboaoLogoImage || !firstPersonaImage || !secondPersonaImage ||
        !pauseBtnImage || !clockBtnImage || !soundBtnImage || !al_install_mouse() || !infoText ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT) || !fonte || !optionText ||
        !contador || !fila_contador || !fila_eventos || !firstText || !secondText || !nameText || 
        !al_init_acodec_addon() || !al_install_audio() || !al_reserve_samples(1)){
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
 
    CANDIDATO *vetor_de_candidatos;
    vetor_de_candidatos = select_candidato();

    
    vetor_de_candidatos[0].descricao = "Professor de Ciência Política da USP e foi ministro da Educação";
    
    vetor_de_candidatos[1].descricao = "Defende uma maior participação feminina e favorável à reforma política";
    
    vetor_de_candidatos[2].descricao = "É um empresário, jornalista, publicitário e político brasileiro";
    
    char *majorName; 
    char *majorDesc;  
    int educacao; 
    int saude; 
    int seguranca; 
    int saneamento; 
    int lazer; 
    int teste_som = 1;

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    int candidato = 0;
    while (!sair){
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
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
                sair = 1;
            }
            
            if (evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if (evento.mouse.x >= 145 && evento.mouse.x <= 315 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                       candidato = 1;
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 2;
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 3;
                    }
            }           
            else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if (evento.mouse.x >= 145 && evento.mouse.x <= 315 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                       candidato = 1;
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 2;
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 3;
                }else if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && teste_som == 0){
                        teste_som = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && teste_som == 1){
                        teste_som = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                }
            }
        }
 
        al_clear_to_color(al_map_rgb(0, 0, 0));
 
        al_set_target_bitmap(firstPersonaImage);
        if (candidato == 1){
            majorName = *vetor_de_candidatos[0].nome;
            majorDesc = vetor_de_candidatos[0].descricao;
            educacao = vetor_de_candidatos[0].educacao; 
            saude = vetor_de_candidatos[0].saude; 
            seguranca = vetor_de_candidatos[0].seguranca; 
            saneamento = vetor_de_candidatos[0].saneamento; 
            lazer = vetor_de_candidatos[0].lazer; 
        }else if (candidato == 2){
            majorName = *vetor_de_candidatos[1].nome;
            majorDesc = vetor_de_candidatos[1].descricao;
            educacao = vetor_de_candidatos[1].educacao; 
            saude = vetor_de_candidatos[1].saude; 
            seguranca = vetor_de_candidatos[1].seguranca; 
            saneamento = vetor_de_candidatos[1].saneamento; 
            lazer = vetor_de_candidatos[1].lazer; 
        }else if(candidato == 3){
            majorName = *vetor_de_candidatos[2].nome;
            majorDesc = vetor_de_candidatos[2].descricao;
            educacao = vetor_de_candidatos[2].educacao; 
            saude = vetor_de_candidatos[2].saude; 
            seguranca = vetor_de_candidatos[2].seguranca; 
            saneamento = vetor_de_candidatos[2].saneamento; 
            lazer = vetor_de_candidatos[2].lazer; 
        }else{
            majorName = "Escolha o seu Prefeito(a)";
            majorDesc = NULL;
            educacao = 0; 
            saude = 0; 
            seguranca = 0; 
            saneamento = 0; 
            lazer = 0;
        }

        al_set_target_bitmap(al_get_backbuffer(janela));

        
        al_draw_filled_rectangle(100, 140, 900, 490, al_map_rgb(87, 87, 86));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_text(nameText, al_map_rgb(255, 255, 255), (1024/2), 170, ALLEGRO_ALIGN_CENTRE, majorName);
        al_draw_text(secondText, al_map_rgb(255, 255, 255), (1024/2), 250, ALLEGRO_ALIGN_CENTRE, majorDesc);
        if(vetor_de_candidatos[0].homem == 1){
            al_draw_bitmap(firstPersonaImage, 145, 330, 0);    
        }
        else{
            al_draw_bitmap(secondPersonaImage, 145, 330, 0);
        }
        if(vetor_de_candidatos[1].homem == 1){
            al_draw_bitmap(firstPersonaImage, 415, 330, 0);
        }
        else{
            al_draw_bitmap(secondPersonaImage, 415, 330, 0);
        }
        if(vetor_de_candidatos[2].homem == 1){
            al_draw_bitmap(firstPersonaImage, 680, 330, 0);
        }
        else{
            al_draw_bitmap(secondPersonaImage, 680, 330, 0);
        }   
        al_draw_bitmap(pauseBtnImage, 830, 25, 0);
        al_draw_bitmap(clockBtnImage, 765, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 840, 23, 0, "PAUSAR");
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 35, 0, "ESCOLHA O SEU PREFEITO");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "AS ELEIÇÕES ESTÃO PRÓXIMAS");
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        
        al_draw_textf(fonte, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        //al_draw_bitmap(fundo2, 0, 0, 0);
        al_draw_filled_rectangle(275, 510+50, 725, 530+50, al_map_rgb(87, 87, 86));
        al_draw_text(infoText, al_map_rgb(255, 255, 255), 285, 510+50, 0, "Informações");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 275, 590+30, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_text(firstText, al_map_rgb(203, 187, 160), 320, 590+30, ALLEGRO_ALIGN_LEFT, "21/03/1997");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 275, 575+30, ALLEGRO_ALIGN_LEFT, majorName);
        
        al_draw_bitmap(education, 390+75, 555+40, 0);
        al_draw_bitmap(security, 445+75, 555+40, 0);
        al_draw_bitmap(sanitation, 500+75, 555+40, 0);
        al_draw_bitmap(health, 555+75, 555+40, 0);
        al_draw_bitmap(fun, 610+75, 555+40, 0);
        
        colorValidation(educacao, &r, &g, &b);
        al_draw_textf(optionText, al_map_rgb(r, g, b), 475, 640, 0, "%d", educacao);
        colorValidation(saude, &r, &g, &b);
        al_draw_textf(optionText, al_map_rgb(r, g, b), 530, 640, 0, "%d", saude);
        colorValidation(saneamento, &r, &g, &b);
        al_draw_textf(optionText, al_map_rgb(r, g, b), 640, 640, 0, "%d", saneamento);
        colorValidation(seguranca, &r, &g, &b);
        al_draw_textf(optionText, al_map_rgb(r, g, b), 585, 640, 0, "%d", seguranca);
        colorValidation(lazer, &r, &g, &b);
        al_draw_textf(optionText, al_map_rgb(r, g, b), 695, 640, 0, "%d", lazer);


        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}