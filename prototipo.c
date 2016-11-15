/*gcc prototipo.c -o prototipo.exe $(pkg-config –cflags –libs allegro-5) -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_audio -lallegro_acodec*/


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
                *thirdPersonaImage = NULL,
                *fundo = NULL,
                *pauseBtnImage = NULL,
                *settingsBtnImage = NULL,
                *voltar = NULL,
                *clockBtnImage = NULL,
                *soundBtnImage = NULL,
                *muteBtnImage = NULL,
                *soundBackup = NULL,
                *education = NULL,
                *fun = NULL,
                *health = NULL,
                *sanitation = NULL,
                *security = NULL,
                *fundo2 = NULL,
                *investiment = NULL;



ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
ALLEGRO_FONT *firstText = NULL,
             *secondText = NULL,
             *thirdText = NULL,
             *fonte = NULL,
             *songText = NULL,
             *nametext = NULL,
             *infotext = NULL,
             *configText = NULL;
ALLEGRO_AUDIO_STREAM *musica = NULL;
ALLEGRO_TIMER *contador = 0;
ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;

int botao = 0;
int sair = 0;
int r = 0, g = 0, b = 0;
int min = 5, seg = 0; 
 
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
    thirdPersonaImage = al_load_bitmap("Images/chooseImages/thirdPersonaImage.png");
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
    
    if (!taboaoLogoImage || !firstPersonaImage || !secondPersonaImage || !thirdPersonaImage ||
        !pauseBtnImage || !clockBtnImage || !soundBtnImage || !al_install_mouse() ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT) || !fonte ||
        !contador || !fila_contador || !fila_eventos || !al_init_acodec_addon() || 
        !al_install_audio() || !al_reserve_samples(1)){
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
 
    
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 22,0 );
    nametext = al_load_ttf_font("Font/Arial_Bold.ttf", 24,0 );
    infotext = al_load_ttf_font("Font/Arial_Bold.ttf", 18,0 );
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
    secondMajor.nome = "Candidata Luiza Maria";
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
    int educacaoInd; 
    int saudeInd; 
    int segurancaInd; 
    int saneamentoInd; 
    int lazerInd;
    int value; 

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
                        playScreen(sair, candidato);
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 2;
                        playScreen(sair, candidato);
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                        candidato = 3;
                        playScreen(sair, candidato);
                }else if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && value == 0){
                        value = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && value == 1){
                        value = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
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

        
        al_draw_filled_rectangle(100, 140, 900, 490, al_map_rgb(87, 87, 86));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_text(nametext, al_map_rgb(255, 255, 255), (1024/2), 170, ALLEGRO_ALIGN_CENTRE, majorName);
        al_draw_text(secondText, al_map_rgb(255, 255, 255), (1024/2), 250, ALLEGRO_ALIGN_CENTRE, majorDesc);
        al_draw_bitmap(firstPersonaImage, 145, 330, 0);
        al_draw_bitmap(secondPersonaImage, 415, 330, 0);
        al_draw_bitmap(thirdPersonaImage, 680, 330, 0);
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
        al_draw_text(infotext, al_map_rgb(255, 255, 255), 285, 510+50, 0, "Informações");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 275, 590+50, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_text(firstText, al_map_rgb(203, 187, 160), 320, 590+50, ALLEGRO_ALIGN_LEFT, "21/03/1997");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 275, 575+50, ALLEGRO_ALIGN_LEFT, majorName);
        al_draw_text(secondText, al_map_rgb(255, 255, 255), 275, 550+50, ALLEGRO_ALIGN_LEFT, majorMoney);
        al_draw_bitmap(education, 390+75, 555+50, 0);
        al_draw_bitmap(security, 445+75, 555+50, 0);
        al_draw_bitmap(sanitation, 500+75, 555+50, 0);
        al_draw_bitmap(health, 555+75, 555+50, 0);
        al_draw_bitmap(fun, 610+75, 555+50, 0);

        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;

}


int playScreen(int sair, int candidato){
    fundo = al_load_bitmap("Images/playScreen/background-black.png");
    firstPersonaImage = al_load_bitmap("Images/chooseImages/firstPersonaImage.png");
    secondPersonaImage = al_load_bitmap("Images/chooseImages/secondPersonaImage.png");
    thirdPersonaImage = al_load_bitmap("Images/chooseImages/thirdPersonaImage.png");
    pauseBtnImage = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    investiment = al_load_bitmap("Images/playScreen/investimento.png");
    education = al_load_bitmap("Images/globalImages/education-btn.png");
    fun = al_load_bitmap("Images/globalImages/fun-btn.png");
    health = al_load_bitmap("Images/globalImages/health-btn.png");
    sanitation = al_load_bitmap("Images/globalImages/sanitation-btn.png");
    security = al_load_bitmap("Images/globalImages/security-btn.png"); 
    fonte = al_load_font("Font/arial.ttf", 11,00);
    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();
    
    if (!fundo || !firstPersonaImage || !secondPersonaImage || !thirdPersonaImage ||
        !pauseBtnImage || !clockBtnImage || !soundBtnImage || !al_install_mouse() ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT) || !fonte ||
        !contador || !fila_contador || !fila_eventos || !al_init_acodec_addon() || 
        !al_install_audio() || !al_reserve_samples(1)){
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
 
    
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 22,0 );
    nametext = al_load_ttf_font("Font/Arial_Bold.ttf", 24,0 );
    infotext = al_load_ttf_font("Font/Arial_Bold.ttf", 18,0 );
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
    thirdMajor.nome = "CandiAlberto Santos";
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
    int educacaoInd; 
    int saudeInd; 
    int segurancaInd; 
    int saneamentoInd; 
    int lazerInd; 
    int value; 

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    //int candidato = 0;
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
            
            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if (evento.mouse.x >= 320 && evento.mouse.x <= 425 &&
                    evento.mouse.y >= 630 && evento.mouse.y <= 650){
                        budgetScreen(sair);
                }
                else if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && value == 0){
                        value = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && value == 1){
                        value = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
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
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 840, 23, 0, "PAUSAR");
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 35, 0, "CONSTRUA UM PISCINÃO");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "AS CHUVAS ESTÃO PRÓXIMAS, PREPARE A CIDADE");
        
        al_draw_textf(fonte, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        //detalhe prefeito
        al_draw_filled_rectangle(325, 530, 775, 550, al_map_rgb(87, 87, 86));
        al_draw_text(infotext, al_map_rgb(255, 255, 255), 335, 530, 0, "Informações");
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

        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
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