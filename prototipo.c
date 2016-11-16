/*gcc prototipo.c -o prototipo.exe $(pkg-config –cflags –libs allegro-5) -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_audio -lallegro_acodec*/


// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "structs.h"
#include "eventos.h"
#include <time.h>
 
// Para utilizarmos o fprintf
#include <stdio.h>


int nivelScreen();
int chooseScreen();
int playScreen();
int budgetScreen();
int settingScreen();


// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

typedef struct prefeito {
      char *nome;
      char *descricao;
      char *dinheiro; 
      int educacaoInd; 
      int saudeInd; 
      int segurancaInd; 
      int saneamentoInd; 
      int lazerInd;
   }prefeito; 



ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP  *taboaoLogoImage = NULL,
                *instrucaoBtnImage = NULL,
                *configBtnImage = NULL,
                *creditBtnImage = NULL,
                *jogarBtnImage = NULL,
                *facilBtnImage = NULL,
                *medioBtnImage = NULL,
                *dificilBtnImage = NULL,
                *botao_sair = NULL,
                *firstPersonaImage = NULL,
                *secondPersonaImage = NULL,
                *sencondPersonaImage = NULL,
                *thirdPersonaImage = NULL,
                *fundo = NULL,
                *pauseBtnImage = NULL,
                *settingsBtnImage = NULL,
                *voltar = NULL,
                *clockBtnImage = NULL,
                *soundBtnImage = NULL,
                *muteBtnImage = NULL,
                *soundBackup = NULL,
                *pauseBackup = NULL,
                *playBtnImage = NULL,
                *education = NULL,
                *fun = NULL,
                *health = NULL,
                *sanitation = NULL,
                *security = NULL,
                *fundo2 = NULL,
                *investiment = NULL,
                *cautionBtn = NULL,
                *cautionIcon = NULL,
                *quietBtn = NULL,
                *quietIcon = NULL;



ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
ALLEGRO_FONT *firstText = NULL,
             *secondText = NULL,
             *thirdText = NULL,
             *fonte = NULL,
             *songText = NULL,
             *nametext = NULL,
             *infotext = NULL,
             *configText = NULL,
             *nameText = NULL,
             *infoText = NULL,
             *optionText =  NULL;
ALLEGRO_AUDIO_STREAM *musica = NULL;
ALLEGRO_TIMER *contador = 0;
ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;

int botao = 0;
int sair = 0;
int r = 0, g = 0, b = 0;
int min = 5, seg = 0;
int candidato = 0;
 
int main(void){


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

    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoMiniLogoImage.png");
    jogarBtnImage = al_load_bitmap("Images/mainImages/jogar-botao.png");
    instrucaoBtnImage = al_load_bitmap("Images/mainImages/instrucoes-botao.png");
    configBtnImage = al_load_bitmap("Images/mainImages/configuracoes-botao.png");
    creditBtnImage = al_load_bitmap("Images/mainImages/creditos-botao.png");
    fila_eventos = al_create_event_queue();
    firstText = al_load_ttf_font("Font/arial.ttf", 32,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 18,0 );
    thirdText = al_load_ttf_font("Font/arial.ttf", 24,0 );
    
    if (!al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)||
        !taboaoLogoImage || !jogarBtnImage || !instrucaoBtnImage || !configBtnImage || !creditBtnImage ||
        !fila_eventos){
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_flip_display();
 
    while (!sair){
        //ALLEGRO_EVENT evento;
        //ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 450 && evento.mouse.y <= 485){
                nivelScreen(sair);
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                      evento.mouse.y >= 500 && evento.mouse.y <= 535){
                      nivelScreen(sair);
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                      evento.mouse.y >= 550 && evento.mouse.y <= 585){
                      settingScreen(sair);
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                      evento.mouse.y >= 600 && evento.mouse.y <= 635){
                      nivelScreen(sair);
            }
        }
        
        al_draw_filled_rectangle(0, 0, 1080, 720, al_map_rgb(0, 0, 0));
        al_draw_text(firstText, al_map_rgb(29, 113, 189), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "PROJETO TABOÃO");
        al_draw_bitmap(taboaoLogoImage, 420, 200, 0);
        al_draw_bitmap(jogarBtnImage, 400, 450, 0);
        al_draw_bitmap(instrucaoBtnImage, 400, 500, 0);
        al_draw_bitmap(configBtnImage, 400, 550, 0);
        al_draw_bitmap(creditBtnImage, 400, 600, 0);
        
        al_flip_display();
    }

}

int nivelScreen(){

    facilBtnImage = al_load_bitmap("Images/nivelImages/facilBtnImage.png");
    medioBtnImage = al_load_bitmap("Images/nivelImages/medioBtnImage.png");
    dificilBtnImage = al_load_bitmap("Images/nivelImages/dificilBtnImage.png");
    if (!facilBtnImage || !medioBtnImage || !dificilBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    
    while (!sair){
        //janela = NULL;
        //ALLEGRO_EVENT evento;
        //ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }

        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (evento.mouse.x >= 165 && evento.mouse.x <= 352 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                chooseScreen(sair);
            }else if (evento.mouse.x >= 415 && evento.mouse.x <= 595 &&
                      evento.mouse.y >= 250 && evento.mouse.y <= 437){
                      chooseScreen(sair);
            }else if (evento.mouse.x >= 665 && evento.mouse.x <= 845 &&
                      evento.mouse.y >= 250 && evento.mouse.y <= 437){
                      chooseScreen(sair);
            }
        }
        
        al_draw_filled_rectangle(0, 0, 1080, 720, al_map_rgb(0, 0, 0));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "ESCOLHA UM NÍVEL");
        al_draw_text(secondText, al_map_rgb(255, 255, 255), (1024/2), 150, ALLEGRO_ALIGN_CENTRE, "Selecione um nível abaixo para começar.");
        al_draw_bitmap(facilBtnImage, 165, 250, 0);
        al_draw_bitmap(medioBtnImage, 415, 250, 0);
        al_draw_bitmap(dificilBtnImage, 665, 250, 0);
        al_draw_text(thirdText, al_map_rgb(255, 255, 255), (1024/4), 450, ALLEGRO_ALIGN_CENTRE, "Fácil");
        al_draw_text(thirdText, al_map_rgb(255, 255, 255), (1024/2), 450, ALLEGRO_ALIGN_CENTRE, "Médio");
        al_draw_text(thirdText, al_map_rgb(255, 255, 255), 750, 450, ALLEGRO_ALIGN_CENTRE, "Difícil");
        
        al_flip_display();
    }

    al_destroy_bitmap(botao_sair);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}

int chooseScreen(){

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
                   playScreen(sair);
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 2;
                        playScreen(sair);
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 3;
                        playScreen(sair);
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
            educacao = 401 + vetor_de_candidatos[0].educacao + 99; 
            saude = 401 + vetor_de_candidatos[0].saude + 99; 
            seguranca = 401 + vetor_de_candidatos[0].seguranca + 99; 
            saneamento = 401 + vetor_de_candidatos[0].saneamento + 99; 
            lazer = 401 + vetor_de_candidatos[0].lazer + 99; 
        }else if (candidato == 2){
            majorName = *vetor_de_candidatos[1].nome;
            majorDesc = vetor_de_candidatos[1].descricao;
            educacao = 401 + vetor_de_candidatos[1].educacao + 99; 
            saude = 401 + vetor_de_candidatos[1].saude + 99; 
            seguranca = 401 + vetor_de_candidatos[1].seguranca + 99; 
            saneamento = 401 + vetor_de_candidatos[1].saneamento + 99; 
            lazer = 401 + vetor_de_candidatos[1].lazer + 99; 
        }else if(candidato == 3){
            majorName = *vetor_de_candidatos[2].nome;
            majorDesc = vetor_de_candidatos[2].descricao;
            educacao = 401 + vetor_de_candidatos[2].educacao + 99; 
            saude = 401 + vetor_de_candidatos[2].saude + 99; 
            seguranca = 401 + vetor_de_candidatos[2].seguranca + 99; 
            saneamento = 401 + vetor_de_candidatos[2].saneamento + 99; 
            lazer = 401 + vetor_de_candidatos[2].lazer + 99; 
        }else{
            majorName = "Escolha o seu Prefeito(a)";
            majorDesc = NULL;
            educacao = 401; 
            saude = 401; 
            seguranca = 401; 
            saneamento = 401; 
            lazer = 401;
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
        
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 475, 640, 0, "90%%");
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 530, 640, 0, "90%%");
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 585, 640, 0, "90%%");
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 640, 640, 0, "90%%");
        al_draw_textf(optionText, al_map_rgb(0, 150, 64), 695, 640, 0, "90%%");


        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}


int playScreen(int sair, int candidato){
    
    srand((unsigned)time(NULL));

    EVENTO_RUIM ruim;
    EVENTO_BOM bom;
    char **texto_evento;

    int global = 60 * min;
    int random_value = 295;
    fprintf(stderr, "VALOR ALEATORIO: %d\n", random_value);
 
    
    fundo = al_load_bitmap("Images/playScreen/background-black.png");
    firstPersonaImage = al_load_bitmap("Images/chooseImages/firstPersonaImage.png");
    sencondPersonaImage = al_load_bitmap("Images/chooseImages/secondPersonaImage.png");
    thirdPersonaImage = al_load_bitmap("Images/chooseImages/thirdPersonaImage.png");
    pauseBtnImage = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    pauseBackup = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    playBtnImage = al_load_bitmap("Images/chooseImages/playBtnImage.png");
    muteBtnImage = al_load_bitmap("Images/globalImages/mute-btn.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    soundBackup = al_load_bitmap("Images/globalImages/sound-btn.png");
    investiment = al_load_bitmap("Images/playScreen/investimento.png");
    education = al_load_bitmap("Images/globalImages/education-btn.png");
    fun = al_load_bitmap("Images/globalImages/fun-btn.png");
    health = al_load_bitmap("Images/globalImages/health-btn.png");
    sanitation = al_load_bitmap("Images/globalImages/sanitation-btn.png");
    security = al_load_bitmap("Images/globalImages/security-btn.png");
    cautionBtn = al_load_bitmap("Images/globalImages/caution-btn.png");
    cautionIcon = al_load_bitmap("Images/globalImages/caution-icon.png");
    quietBtn = al_load_bitmap("Images/globalImages/quiet-btn.png");
    quietIcon = al_load_bitmap("Images/globalImages/quiet-icon.png");

    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 22,0 );
    nameText = al_load_ttf_font("Font/Arial_Bold.ttf", 24,0 );
    infoText = al_load_ttf_font("Font/Arial_Bold.ttf", 18,0 );

    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();

    
    if(!al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao setar o mouse.\n");
        return -1;
    }

    if (!fundo || !firstPersonaImage || !sencondPersonaImage || !thirdPersonaImage ||
        !pauseBtnImage || !clockBtnImage || !muteBtnImage || !soundBackup || !pauseBackup || !soundBtnImage || 
        !cautionBtn || !cautionIcon || !quietBtn || !quietIcon){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }

    if(!contador){
        fprintf(stderr, "Falha ao carregar o contador.\n");
        return -1;
    }

    if(!fila_eventos || !fila_contador){
        fprintf(stderr, "Falha ao carregar a fila de enventos.\n");
        return -1;
    }

    if(!firstText || !secondText || !nameText || !infoText){
        fprintf(stderr, "Falha ao carregar os arquivos de texto.\n");
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

    prefeito firstMajor;
    prefeito secondMajor;
    prefeito thirdMajor;
    firstMajor.nome = "Candidato Fernando Haddad";
    firstMajor.descricao = "Professor de Ciência Política da USP e foi ministro da Educação";
    firstMajor.dinheiro = "R$1000000,00";
    firstMajor.educacaoInd = 20; 
    firstMajor.saudeInd = 20; 
    firstMajor.segurancaInd = 20; 
    firstMajor.saneamentoInd = 10; 
    firstMajor.lazerInd = 30;
    secondMajor.nome = "Candidata Luiza Erundina";
    secondMajor.descricao = "Defende uma maior participação feminina e favorável à reforma política";
    secondMajor.dinheiro = "R$10000,00";
    secondMajor.educacaoInd = 20;
    secondMajor.saudeInd = 30;
    secondMajor.segurancaInd = 10;
    secondMajor.saneamentoInd = 30;
    secondMajor.lazerInd = 20;
    thirdMajor.nome = "Candidato João Doria";
    thirdMajor.descricao = "É um empresário, jornalista, publicitário e político brasileiro";
    thirdMajor.dinheiro = "R$100000000,00";
    thirdMajor.educacaoInd = 10;
    thirdMajor.saudeInd = 20;
    thirdMajor.segurancaInd = 40;
    thirdMajor.saneamentoInd = 10;
    thirdMajor.lazerInd = 10;

    int togglePopup = 3;
    int togglePlay = 1;
    char *majorName; 
    char *majorDesc; 
    char *majorMoney; 
    int educacaoInd; 
    int saudeInd; 
    int segurancaInd; 
    int saneamentoInd; 
    int lazerInd;
    int toggleSound = 1;

    char *news = "NADA DE MAIS ESTA ACONTECENDO EM TABOÂO";
    char *pauseText = "PAUSAR";  

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    while (!sair){
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);
 
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                seg--;
                if (seg == -1) {
                    min--;
                    seg = 59;
                }
            }
            global = (60 * min) + seg;
            if(global == random_value){
                random_value = rand() % 2;
                if(!random_value){
                    select_evento_bom(&bom);
                    printf("EVENTO BOM\nSAUDE: %d\n", bom.saude);
                    printf("DINHEIRO: %d\n", bom.dinheiro);
                    printf("INVESTIMENTO: %d\n", bom.investimento);
                    printf("SEGURANCA: %d\n", bom.seguranca);
                    printf("LAZER: %d\n", bom.lazer);
                    printf("SANEAMTENO: %d", bom.saneamento);
                    printf("EDUCACAO: %d\n", bom.educacao);
                    togglePopup = 1;
                    select_event_description(&texto_evento, 0);
                    news = *texto_evento;
                    al_stop_timer(contador);
                }
                else{
                    select_evento_ruim(&ruim);
                    fprintf(stderr, "GASTO: %d\n", ruim.dinheiro);
                    printf("EVENTO RUIM\nSAUDE: %d\n", ruim.saude);
                    printf("DINHEIRO: %d\n", ruim.dinheiro);
                    printf("SEGURANCA: %d\n", ruim.seguranca);
                    printf("LAZER: %d\n", ruim.lazer);
                    printf("SANEAMTENO: %d\n", ruim.saneamento);
                    printf("EDUCACAO: %d\n", ruim.educacao);
                    togglePopup = 0;
                    select_event_description(&texto_evento, 1);
                    news = *texto_evento;
                    al_stop_timer(contador);
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
            
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 0){
                        
                        toggleSound = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
               
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 1){
                
                        toggleSound = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                
                }else if((togglePopup == 1 || togglePopup == 0) || evento.mouse.x >= 475 && 
                    evento.mouse.x <= 485 && evento.mouse.y >= 320 && evento.mouse.y <= 345){
                    
                        togglePopup = 3;
                        al_start_timer(contador);
                
                }else if(togglePopup == 3 && evento.mouse.x >= 830 && evento.mouse.x <= 840 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                
                        togglePlay = 0;
                        pauseText = "PAUSAR";
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                
                }else if (togglePopup == 3 && evento.mouse.x >= 830 && evento.mouse.x <= 840 && 
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
 
        al_set_target_bitmap(firstPersonaImage);
        if (candidato == 1){
            majorName = firstMajor.nome;
            majorMoney = firstMajor.dinheiro;
            majorDesc = firstMajor.descricao;
            educacaoInd = 401 + firstMajor.educacaoInd + 99; 
            saudeInd = 401 + firstMajor.saudeInd + 99; 
            segurancaInd = 401 + firstMajor.segurancaInd + 99; 
            saneamentoInd = 401 + firstMajor.saneamentoInd + 99; 
            lazerInd = 401 + firstMajor.lazerInd + 99; 
        }else if (candidato == 2){
            majorName = secondMajor.nome;
            majorDesc = secondMajor.descricao;
            majorMoney = secondMajor.dinheiro;
            educacaoInd = 401 + secondMajor.educacaoInd + 99; 
            saudeInd = 401 + secondMajor.saudeInd + 99; 
            segurancaInd = 401 + secondMajor.segurancaInd + 99; 
            saneamentoInd = 401 + secondMajor.saneamentoInd + 99; 
            lazerInd = 401 + secondMajor.lazerInd + 99; 
        }else if(candidato == 3){
            majorName = thirdMajor.nome;
            majorDesc = thirdMajor.descricao;
            majorMoney = thirdMajor.dinheiro;
            educacaoInd = 401 + thirdMajor.educacaoInd + 99; 
            saudeInd = 401 + thirdMajor.saudeInd + 99; 
            segurancaInd = 401 + thirdMajor.segurancaInd + 99; 
            saneamentoInd = 401 + thirdMajor.saneamentoInd + 99; 
            lazerInd = 401 + thirdMajor.lazerInd + 99; 
        }else{
            majorName = "Escolha o seu Prefeito(a)";
            majorDesc = NULL;
            majorMoney = "R$0,00";
            educacaoInd = 401; 
            saudeInd = 401; 
            segurancaInd = 401; 
            saneamentoInd = 401; 
            lazerInd = 401;
        }

        al_set_target_bitmap(al_get_backbuffer(janela));
        
        al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(29,113,184));
        al_draw_bitmap(fundo, 0, -10, 0);
        al_draw_bitmap(firstPersonaImage, 145, 530, 0);
        al_draw_bitmap(pauseBtnImage, 830, 25, 0);
        al_draw_bitmap(clockBtnImage, 765, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 840, 23, 0, pauseText);
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(310, 10, 730, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 35, 0, "ESCOLHA O SEU PREFEITO");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, news);
        
        al_draw_textf(firstText, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        //detalhe prefeito
        al_draw_filled_rectangle(325, 530, 775, 550, al_map_rgb(87, 87, 86));
        al_draw_text(infoText, al_map_rgb(255, 255, 255), 335, 530, 0, "Informações");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 325, 610, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_text(firstText, al_map_rgb(203, 187, 160), 370, 610, ALLEGRO_ALIGN_LEFT, "21/03/1997");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 325, 595, ALLEGRO_ALIGN_LEFT, majorName);
        al_draw_text(secondText, al_map_rgb(255, 255, 255), 325, 570, ALLEGRO_ALIGN_LEFT, majorMoney);
        al_draw_bitmap(investiment, 325, 630, ALLEGRO_ALIGN_LEFT);
        al_draw_bitmap(education, 390+75+50, 575, 0);
        //al_draw_text(firstText, al_map_rgb(255, 255, 255), 390+75+50, 620, ALLEGRO_ALIGN_LEFT, "%d", educacaoInd);
        al_draw_bitmap(security, 445+75+50, 575, 0);
        //al_draw_text(firstText, al_map_rgb(255, 255, 255), 445+75+50, 620, ALLEGRO_ALIGN_LEFT, "%d", segurancaInd);
        al_draw_bitmap(sanitation, 500+75+50, 575, 0);
        //al_draw_text(firstText, al_map_rgb(255, 255, 255), 500+75+50, 620, ALLEGRO_ALIGN_LEFT, "%d", saneamentoInd);
        al_draw_bitmap(health, 555+75+50, 575, 0);
        //al_draw_text(firstText, al_map_rgb(255, 255, 255), 555+75+50, 620, ALLEGRO_ALIGN_LEFT, "%d", saudeInd);
        al_draw_bitmap(fun, 610+75+50, 575, 0);
        //al_draw_text(firstText, al_map_rgb(255, 255, 255), 610+75+50, 620, ALLEGRO_ALIGN_LEFT, "%d", lazerInd);

        if(togglePopup == 1) {
            al_draw_filled_rectangle(300, 260, 750, 375, al_map_rgb(255, 255, 255));
            al_draw_bitmap(quietIcon, (1024/2), 270, 0);
            al_draw_text(firstText, al_map_rgb(0, 0, 0), (1024/2), 300, ALLEGRO_ALIGN_CENTRE, *texto_evento);
            al_draw_text(firstText, al_map_rgb(0, 0, 0), (1024/2), 320, ALLEGRO_ALIGN_CENTRE, bom.text);
            al_draw_bitmap(quietBtn, 475, 340, 0);

        }
        else if(togglePopup == 0){
            al_draw_filled_rectangle(300, 260, 750, 375, al_map_rgb(255, 255, 255));
            al_draw_bitmap(cautionIcon, (1024/2), 270, 0);
            al_draw_text(firstText, al_map_rgb(0, 0, 0), (1024/2), 300, ALLEGRO_ALIGN_CENTRE, *texto_evento);
            al_draw_text(firstText, al_map_rgb(0, 0, 0), (1024/2), 320, ALLEGRO_ALIGN_CENTRE, ruim.text);
            al_draw_bitmap(cautionBtn, 475, 340, 0);

        }

        al_flip_display();
    }
    al_destroy_bitmap(sencondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}








int budgetScreen(int sair, int candidato){

    ALLEGRO_BITMAP *pauseBtnImage = NULL, *settingsBtnImage = NULL, *fundo = NULL, *money = NULL, 
        *majorImage = NULL, *investir = NULL, *garbage = NULL, *educacao = NULL, *saude = NULL,
        *seguranca = NULL, *lazer = NULL, *saneamento = NULL, *clockBtnImage = NULL, *voltar = NULL;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
    ALLEGRO_FONT *firstText = NULL, *secondText = NULL, * optionText = NULL, *moneyText = NULL;
    
    
    int candidatob = candidato;

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
    majorImage = al_load_bitmap("Images/chooseImages/firstPersonaImage.png");
    pauseBtnImage = al_load_bitmap("Images/globalImages/pauseBtnImage.png");
    settingsBtnImage = al_load_bitmap("Images/chooseImages/settingsBtnImage.png");
    fundo = al_load_bitmap("Images/budgetScreen/tela.png");
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 24,0 );
    optionText = al_load_ttf_font("Font/Arial_Bold.ttf", 14,0 );
    moneyText = al_load_ttf_font("Font/Arial_Bold.ttf", 16,0 );
    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();

    if ( !garbage || !firstText || !secondText || !clockBtnImage ||
        !investir || !majorImage || !fila_eventos || !optionText || !moneyText ||
        !fila_contador || !pauseBtnImage || !settingsBtnImage || 
        !contador || !fundo || !al_install_mouse() ||  !money ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao carregar o arquivo.\n");
        al_destroy_display(janela);
        return -1;
    }

    prefeito firstMajor;
    prefeito secondMajor;
    prefeito thirdMajor;
    firstMajor.nome = "Candidato Carlos Eduardo";
    firstMajor.descricao = "Professor de Ciência Política da USP e foi ministro da Educação";
    firstMajor.dinheiro = "R$1000000,00";
    firstMajor.educacaoInd = 20; 
    firstMajor.saudeInd = 20; 
    firstMajor.segurancaInd = 20; 
    firstMajor.saneamentoInd = 10; 
    firstMajor.lazerInd = 30;
    secondMajor.nome = "Candidata Maria";
    secondMajor.descricao = "Defende uma maior participação feminina e favorável à reforma política";
    secondMajor.dinheiro = "R$10000,00";
    secondMajor.educacaoInd = 20;
    secondMajor.saudeInd = 30;
    secondMajor.segurancaInd = 10;
    secondMajor.saneamentoInd = 30;
    secondMajor.lazerInd = 20;
    thirdMajor.nome = "Candidato Alberto Santos";
    thirdMajor.descricao = "É um empresário, jornalista, publicitário e político brasileiro";
    thirdMajor.dinheiro = "R$100000000,00";
    thirdMajor.educacaoInd = 10;
    thirdMajor.saudeInd = 20;
    thirdMajor.segurancaInd = 40;
    thirdMajor.saneamentoInd = 10;
    thirdMajor.lazerInd = 10;

    char *majorName; 
    char *majorDesc;
    char *majorMoney; 
    //int candidato;
    int educacaoInd; 
    int saudeInd; 
    int segurancaInd; 
    int saneamentoInd; 
    int lazerInd;  


       	if (candidato == 1){
            majorName = firstMajor.nome;
            majorMoney = firstMajor.dinheiro;
            majorDesc = firstMajor.descricao;
            educacaoInd = 401 + firstMajor.educacaoInd + 99; 
            saudeInd = 401 + firstMajor.saudeInd + 99; 
            segurancaInd = 401 + firstMajor.segurancaInd + 99; 
            saneamentoInd = 401 + firstMajor.saneamentoInd + 99; 
            lazerInd = 401 + firstMajor.lazerInd + 99; 
        }else if (candidato == 2){
            majorName = secondMajor.nome;
            majorDesc = secondMajor.descricao;
            majorMoney = secondMajor.dinheiro;
            educacaoInd = 401 + secondMajor.educacaoInd + 99; 
            saudeInd = 401 + secondMajor.saudeInd + 99; 
            segurancaInd = 401 + secondMajor.segurancaInd + 99; 
            saneamentoInd = 401 + secondMajor.saneamentoInd + 99; 
            lazerInd = 401 + secondMajor.lazerInd + 99; 
        }else if(candidato == 3){
            majorName = thirdMajor.nome;
            majorDesc = thirdMajor.descricao;
            majorMoney = thirdMajor.dinheiro;
            educacaoInd = 401 + thirdMajor.educacaoInd + 99; 
            saudeInd = 401 + thirdMajor.saudeInd + 99; 
            segurancaInd = 401 + thirdMajor.segurancaInd + 99; 
            saneamentoInd = 401 + thirdMajor.saneamentoInd + 99; 
            lazerInd = 401 + thirdMajor.lazerInd + 99; 
        }else{
            majorName = "Escolha o seu Prefeito(a)";
            majorDesc = NULL;
            majorMoney = "R$0,00";
            educacaoInd = 401; 
            saudeInd = 401; 
            segurancaInd = 401; 
            saneamentoInd = 401; 
            lazerInd = 401;
        }

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);


    while (!sair){
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (evento.mouse.x >= 130 && evento.mouse.x <= 200 &&
                evento.mouse.y >= 558 && evento.mouse.y <= 578){
            	candidato = 1;
                playScreen(sair, candidato);
        }

    }
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);
 
            if (evento.type == ALLEGRO_EVENT_TIMER){
                seg--;
                if (seg == -1){
                    min--;
                    seg = 59;
                }
                else if(min == 0 && seg == 0 ){
                    sair = 1;
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
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));
        
         al_draw_bitmap(pauseBtnImage, 815, 25, 0);
        al_draw_bitmap(clockBtnImage, 750, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 827, 23, 0, "PAUSAR");
        al_draw_bitmap(settingsBtnImage, 885, 22, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 908, 23, 0, "CONFIGURAÇÕES");
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 35, 0, "CONSTRUA UM HOSPITAL");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "Epidemia de Dengue e Zica vírus é eminente.");
        //al_draw_bitmap(fundo, 120, ALLEGRO_ALIGN_CENTRE, 0);
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
        // 104 94 35
        al_draw_bitmap(voltar, 140, 568, 0);
        al_draw_bitmap(money, 456, 82, 0);
        al_draw_textf(moneyText, al_map_rgb(104, 94, 35), 486, 87, 0, "R$1000000,00");
        al_draw_textf(firstText, al_map_rgb(255, 255, 255), 785, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
        
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);

    return 0;

}
int settingScreen(void){
    voltar = al_load_bitmap("Images/globalImages/back-btn.png");
    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoLogoImage.png");
    fila_eventos = al_create_event_queue();
    
    if (!taboaoLogoImage || !al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)||
     !al_install_audio() || !al_init_acodec_addon() || !al_reserve_samples(1) || !fila_eventos){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }
    musica = al_load_audio_stream("teste.ogg", 8, 1024);
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
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (evento.mouse.x >= 130 && evento.mouse.x <= 200 &&
                evento.mouse.y >= 558 && evento.mouse.y <= 578){
                al_set_audio_stream_playing(musica, false);
        }
        else if (evento.mouse.x >= 200 && evento.mouse.x <= 400 &&
                evento.mouse.y >= 558 && evento.mouse.y <= 578){
               al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
              al_set_audio_stream_playing(musica, true);
        }

    }
      

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));

        
        al_draw_filled_rectangle(100, 45, 900, 666, al_map_rgb(87, 87, 86));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_text(configText, al_map_rgb(255, 255, 255), (1024/2), 70, ALLEGRO_ALIGN_CENTRE, "CONFIGURAÇÕES");
        al_draw_text(songText, al_map_rgb(255, 255, 255), 200, 200, 0, "Volume");
        al_draw_bitmap(voltar, 140, 568, 0);
        //al_draw_filled_rectangle(690, 197, 700, 237, al_map_rgb(255, 255, 255));
        al_draw_filled_rectangle(300, 212, 800, 222, al_map_rgb(255, 255, 255));
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        

        al_flip_display();


    }

    al_destroy_audio_stream(musica);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;

}