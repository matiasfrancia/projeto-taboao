// Para compilar
/*gcc prototipo.c -o prototipo.exe $(pkg-config –cflags –libs allegro-5) -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_audio -lallegro_acodec*/

// Bibliotecas que estamos usando
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
#include <stdio.h>

// Funções de tela
int mainScreen();
int nivelScreen();
int chooseScreen();
int playScreen();
int budgetScreen();
int loserScreen();
int winnerScreen();
int helpScreen();
int creditScreen();

// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

// Atributos Candidatos
CANDIDATO cidade;

// Atributos Investimentos
ITEM compra;


// Imagens/Fontes/Músicas usadas no jogo
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP  *taboaoLogoImage = NULL,
                *taboaoMiniLogoImage = NULL,
                *taboaoLogoImageloser = NULL,
                *instrucaoBtnImage = NULL,
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
                *voltar = NULL,
                *clockBtnImage = NULL,
                *soundBtnImage = NULL,
                *muteBtnImage = NULL,
                *soundBackup = NULL,
                *pauseBackup = NULL,
                *playBtnImage = NULL,
                *money = NULL,
                *garbage = NULL,
                *education = NULL,
                *educacao = NULL,
                *fun = NULL,
                *lazer = NULL,
                *health = NULL,
                *saude = NULL,
                *sanitation = NULL,
                *saneamento = NULL,
                *security = NULL,
                *seguranca = NULL,
                *majorImage = NULL,
                *investiment = NULL,
                *cautionBtn = NULL,
                *cautionIcon = NULL,
                *quietBtn = NULL,
                *investir = NULL,
                *quietIcon = NULL,
                *blackBack = NULL;

char *news = "NADA DE MAIS ESTA ACONTECENDO EM TABOÂO";

ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
ALLEGRO_FONT *onzePx = NULL,
            *quatorzePx =  NULL,
            *quinzePx = NULL,
            *dezesseisPx = NULL,
            *dezoitoPx = NULL,
            *vinteDoisPx = NULL,
            *vinteQuatroPx = NULL,
            *trintaDoisPx = NULL,
            *trintaQuatroBoldPx = NULL,
            *trintaOitopx = NULL;
ALLEGRO_AUDIO_STREAM *musica = NULL;
ALLEGRO_TIMER *contador = 0;
ALLEGRO_EVENT evento;
ALLEGRO_TIMEOUT timeout;

int botao = 0;
int sair = 0;
int r = 0, g = 0, b = 0;
int min = 5, seg = 0;
int candidato = 0;
int toggleSound = 1;    
char *pauseText = "PAUSAR";  
int togglePlay = 1;


// Função para carregar conteúdo de images/fontes    
void globalDeclarations(){

    al_set_window_title(janela, "Projeto Taboão");
    //Global Images
    taboaoMiniLogoImage = al_load_bitmap("Images/globalImages/taboaoMiniLogoImage.png");
    jogarBtnImage = al_load_bitmap("Images/mainImages/jogar-botao.png");
    instrucaoBtnImage = al_load_bitmap("Images/mainImages/instrucoes-botao.png");
    creditBtnImage = al_load_bitmap("Images/mainImages/creditos-botao.png");
    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoLogoImage.png");
    taboaoLogoImageloser = al_load_bitmap("Images/loserScreen/game-over.png");
    money = al_load_bitmap("Images/budgetScreen/money-btn.png");
    voltar = al_load_bitmap("Images/globalImages/back-btn.png");
    pauseBtnImage = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    pauseBackup = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    playBtnImage = al_load_bitmap("Images/chooseImages/playBtnImage.png");
    muteBtnImage = al_load_bitmap("Images/globalImages/mute-btn.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    soundBackup = al_load_bitmap("Images/globalImages/sound-btn.png");
    educacao = al_load_bitmap("Images/budgetScreen/education-btn.png");
    saude = al_load_bitmap("Images/budgetScreen/health-btn.png");
    seguranca = al_load_bitmap("Images/budgetScreen/security-btn.png");
    lazer = al_load_bitmap("Images/budgetScreen/laze-btn.png");
    saneamento = al_load_bitmap("Images/budgetScreen/sanitation-btn.png");
    garbage = al_load_bitmap("Images/budgetScreen/delete-btn.png");
    investir = al_load_bitmap("Images/budgetScreen/budget-btn.png");
    firstPersonaImage = al_load_bitmap("Images/chooseImages/firstPersonaImage.png");
    secondPersonaImage = al_load_bitmap("Images/chooseImages/secondPersonaImage.png");
    fundo = al_load_bitmap("Images/budgetScreen/tela.png");
    education = al_load_bitmap("Images/globalImages/education-btn.png");
    fun = al_load_bitmap("Images/globalImages/fun-btn.png");
    health = al_load_bitmap("Images/globalImages/health-btn.png");
    sanitation = al_load_bitmap("Images/globalImages/sanitation-btn.png");
    security = al_load_bitmap("Images/globalImages/security-btn.png");
    blackBack = al_load_bitmap("Images/playScreen/background-black.png");
    investiment = al_load_bitmap("Images/playScreen/investimento.png");
    cautionBtn = al_load_bitmap("Images/globalImages/caution-btn.png");
    cautionIcon = al_load_bitmap("Images/globalImages/caution-icon.png");
    quietBtn = al_load_bitmap("Images/globalImages/quiet-btn.png");
    quietIcon = al_load_bitmap("Images/globalImages/quiet-icon.png");
    facilBtnImage = al_load_bitmap("Images/nivelImages/facilBtnImage.png");
    medioBtnImage = al_load_bitmap("Images/nivelImages/medioBtnImage.png");
    dificilBtnImage = al_load_bitmap("Images/nivelImages/dificilBtnImage.png");
    //Global fontes
    onzePx = al_load_ttf_font("Font/arial.ttf", 11,0 );
    quatorzePx = al_load_ttf_font("Font/Arial_Bold.ttf", 14,0 );
    quinzePx = al_load_ttf_font("Font/arial.ttf", 15,0 );
    dezesseisPx = al_load_ttf_font("Font/Arial_Bold.ttf", 16,0 );
    dezoitoPx = al_load_ttf_font("Font/arial.ttf", 18,0 );
    vinteDoisPx = al_load_ttf_font("Font/arial.ttf", 22,0 );
    vinteQuatroPx = al_load_ttf_font("Font/arial.ttf", 24,0 );
    trintaDoisPx = al_load_ttf_font("Font/arial.ttf", 32,0 );
    trintaQuatroBoldPx = al_load_ttf_font("Font/Arial_Bold.ttf", 34,0 );
    trintaOitopx = al_load_ttf_font("Font/arial.ttf", 38,0 );
    //Global Allegro 
    fila_eventos = al_create_event_queue();
    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
} 


// Função para mudar a cor de verde para vermelho caso atributo fique menor que 50%
void colorValidation(int n, int *r, int *g, int *b){
    if (n < 50) {
            *r = 190;
            *g = 22;
            *b = 34;
        }else {
            *r = 0;
            *g = 150;
            *b = 64; 
        }
}


// Função principal para criar janela e chamar o menu principal 
int main(){


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

    mainScreen();

    return 0;
}

// Função de Menu Principal
int mainScreen(){

    globalDeclarations(); 

    if (!al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_flip_display();
 
    while (!sair){
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            // Botão de JOGAR
            if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 450 && evento.mouse.y <= 485){
                    nivelScreen(sair);
            // Botão de INTRUÇÕES
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 500 && evento.mouse.y <= 535){
                    helpScreen(sair);
            // Botão de CRÉDITOS
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 550 && evento.mouse.y <= 585){
                    creditScreen(sair);
            }
        }
        
        al_draw_filled_rectangle(0, 0, 1080, 720, al_map_rgb(0, 0, 0));
        al_draw_text(trintaDoisPx, al_map_rgb(29, 113, 189), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "PROJETO TABOÃO");
        al_draw_bitmap(taboaoMiniLogoImage, 420, 200, 0);
        al_draw_bitmap(jogarBtnImage, 400, 450, 0);
        al_draw_bitmap(instrucaoBtnImage, 400, 500, 0);
        al_draw_bitmap(creditBtnImage, 400, 550, 0);
        
        al_flip_display();
    }
    al_destroy_bitmap(botao_sair);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}

// função da tela de Escolha de Dificuldade
int nivelScreen(){

    globalDeclarations();

    if (!al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao carregar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));    
    
    while (!sair){
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }

        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            // Botão de Nivel FÁCIL
            if (evento.mouse.x >= 165 && evento.mouse.x <= 352 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                    chooseScreen(sair);
            // Botão de Nivel MÉDIO
            }else if (evento.mouse.x >= 415 && evento.mouse.x <= 595 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                    chooseScreen(sair);
            // Botão de Nivel DIFICIL
            }else if (evento.mouse.x >= 665 && evento.mouse.x <= 845 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                    chooseScreen(sair);
            }
        }
        
        al_draw_filled_rectangle(0, 0, 1080, 720, al_map_rgb(0, 0, 0));
        al_draw_text(trintaDoisPx, al_map_rgb(255, 255, 255), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "ESCOLHA UM NÍVEL");
        al_draw_text(dezoitoPx, al_map_rgb(255, 255, 255), (1024/2), 150, ALLEGRO_ALIGN_CENTRE, "Selecione um nível abaixo para começar.");
        al_draw_bitmap(facilBtnImage, 165, 250, 0);
        al_draw_bitmap(medioBtnImage, 415, 250, 0);
        al_draw_bitmap(dificilBtnImage, 665, 250, 0);
        al_draw_text(vinteQuatroPx, al_map_rgb(255, 255, 255), (1024/4), 450, ALLEGRO_ALIGN_CENTRE, "Fácil");
        al_draw_text(vinteQuatroPx, al_map_rgb(255, 255, 255), (1024/2), 450, ALLEGRO_ALIGN_CENTRE, "Médio");
        al_draw_text(vinteQuatroPx, al_map_rgb(255, 255, 255), 750, 450, ALLEGRO_ALIGN_CENTRE, "Difícil");
        
        al_flip_display();
    }

    al_destroy_bitmap(botao_sair);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}

// Tela de escolha de candidatos
int chooseScreen(){

    globalDeclarations();
         
    if (!al_install_mouse() ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT) ||
        !al_init_acodec_addon() || !al_install_audio() || !al_reserve_samples(1)){
        fprintf(stderr, "Falha ao carregar o audio ou a mouse.\n");
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

    // Descrição de candidatos
    vetor_de_candidatos[0].descricao = "Professor(a) de Agronomia da UNESP e foi ajudante de pedreiro";
    vetor_de_candidatos[1].descricao = "A favor da legalização do aborto e contra combustíveis fósseis";
    vetor_de_candidatos[2].descricao = "Empresário(a) da música a favor da biodiversidade";
   
    vetor_de_candidatos[0].dinheiro = 10000000; 
    vetor_de_candidatos[1].dinheiro = 10000000;
    vetor_de_candidatos[2].dinheiro = 10000000;
    
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
                // candidato random 1
                       candidato = 1;
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 2
                        candidato = 2;
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 3
                        candidato = 3;
                    }
            }           
            else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if (evento.mouse.x >= 145 && evento.mouse.x <= 315 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 1
                        candidato = 1;
                        al_set_audio_stream_playing(musica, false);
                        cidade = vetor_de_candidatos[0];
                        playScreen();
            
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 2
                        candidato = 2;
                        al_set_audio_stream_playing(musica, false);
                        cidade = vetor_de_candidatos[1];
                        playScreen();
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 3
                        candidato = 3;
                        al_set_audio_stream_playing(musica, false);
                        cidade = vetor_de_candidatos[2];
                        playScreen();
                }else if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && teste_som == 0){
                // botão de música
                        teste_som = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && teste_som == 1){
                // botão de pause
                        teste_som = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                }
            }
        }
 
        al_clear_to_color(al_map_rgb(0, 0, 0));
        
        // atribuir parametros dos candidatos de acordo com o movimento do mouse
        al_set_target_bitmap(firstPersonaImage);
        if (candidato == 1){
            majorName = *vetor_de_candidatos[0].nome;
            majorDesc = vetor_de_candidatos[0].descricao;
            educacao =  vetor_de_candidatos[0].educacao ; 
            saude =  vetor_de_candidatos[0].saude ; 
            seguranca =  vetor_de_candidatos[0].seguranca ; 
            saneamento =  vetor_de_candidatos[0].saneamento ; 
            lazer =  vetor_de_candidatos[0].lazer ; 
        }else if (candidato == 2){
            majorName = *vetor_de_candidatos[1].nome;
            majorDesc = vetor_de_candidatos[1].descricao;
            educacao =  vetor_de_candidatos[1].educacao ; 
            saude =  vetor_de_candidatos[1].saude ; 
            seguranca =  vetor_de_candidatos[1].seguranca ; 
            saneamento =  vetor_de_candidatos[1].saneamento ; 
            lazer =  vetor_de_candidatos[1].lazer ; 
        }else if(candidato == 3){
            majorName = *vetor_de_candidatos[2].nome;
            majorDesc = vetor_de_candidatos[2].descricao;
            educacao =  vetor_de_candidatos[2].educacao ; 
            saude =  vetor_de_candidatos[2].saude ; 
            seguranca =  vetor_de_candidatos[2].seguranca ; 
            saneamento =  vetor_de_candidatos[2].saneamento ; 
            lazer =  vetor_de_candidatos[2].lazer ; 
        }else{
            majorName = "Escolha o seu Prefeito(a)";
            majorDesc = 0;
            educacao = 0; 
            saude = 0; 
            seguranca = 0; 
            saneamento = 0; 
            lazer = 0;
        }

        al_set_target_bitmap(al_get_backbuffer(janela));
        
        al_draw_filled_rectangle(100, 140, 900, 490, al_map_rgb(87, 87, 86));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_text(vinteQuatroPx, al_map_rgb(255, 255, 255), (1024/2), 170, ALLEGRO_ALIGN_CENTRE, majorName);
        al_draw_text(vinteDoisPx, al_map_rgb(255, 255, 255), (1024/2), 250, ALLEGRO_ALIGN_CENTRE, majorDesc);

        // sorteio de imagens de candidatos de acordo com o sexo
        if(vetor_de_candidatos[0].homem == 1){
            al_draw_bitmap(firstPersonaImage, 145, 330, 0);    
        }else{
            al_draw_bitmap(secondPersonaImage, 145, 330, 0);
        }

        if(vetor_de_candidatos[1].homem == 1){
            al_draw_bitmap(firstPersonaImage, 415, 330, 0);
        }else{
            al_draw_bitmap(secondPersonaImage, 415, 330, 0);
        }

        if(vetor_de_candidatos[2].homem == 1){
            al_draw_bitmap(firstPersonaImage, 680, 330, 0);
        }else{
            al_draw_bitmap(secondPersonaImage, 680, 330, 0);
        }   

        //cabeçalho
        al_draw_bitmap(pauseBtnImage, 830, 25, 0);
        al_draw_bitmap(clockBtnImage, 765, 20, 0);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 840, 23, 0, "PAUSAR");
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 30, 35, 0, "ESCOLHA O SEU PREFEITO");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "AS ELEIÇÕES ESTÃO PRÓXIMAS");
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        
        // relógio
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        // detalhes candidatos
        al_draw_filled_rectangle(275, 510+50, 725, 530+50, al_map_rgb(87, 87, 86));
        al_draw_text(dezoitoPx, al_map_rgb(255, 255, 255), 285, 510+50, 0, "Informações");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 275, 590+30, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_text(onzePx, al_map_rgb(203, 187, 160), 320, 590+30, ALLEGRO_ALIGN_LEFT, "21/03/1997");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 275, 575+30, ALLEGRO_ALIGN_LEFT, majorName);
        
        // icones de parametros
        al_draw_bitmap(education, 390+75, 555+40, 0);
        al_draw_bitmap(security, 445+75, 555+40, 0);
        al_draw_bitmap(sanitation, 500+75, 555+40, 0);
        al_draw_bitmap(health, 555+75, 555+40, 0);
        al_draw_bitmap(fun, 610+75, 555+40, 0);

        // valores dos parametros
        if(educacao != 0 || saude != 0 || saneamento != 0 || seguranca != 0 || lazer != 0){
            colorValidation(educacao, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 475, 640, 0, "%d%%", educacao);
            colorValidation(saude, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 530, 640, 0, "%d%%", saude);
            colorValidation(saneamento, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 640, 640, 0, "%d%%", saneamento);
            colorValidation(seguranca, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 585, 640, 0, "%d%%", seguranca);
            colorValidation(lazer, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 695, 640, 0, "%d%%", lazer);
        }

        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}

// tela de jogar
int playScreen(){

    globalDeclarations();
    
    srand((unsigned)time(NULL));

    EVENTO_RUIM ruim;
    EVENTO_BOM bom;
    char **texto_evento;

    int global = 60 * min;
    int random_value = 295;
    fprintf(stderr, "VALOR ALEATORIO: %d\n", random_value);

    if(!al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao setar o mouse.\n");
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

    int togglePopup = 3;
    char *majorName; 
    char *majorDesc; 
    char *majorMoney;

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    while (!sair){
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);

            //função relogio 
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                seg--;
                if (seg == -1) {
                    min--;
                    seg = 59;
                }
            }

            // caso o tempo de 5 minutos acabe
            if (min == 0 && seg == 0){
                loserScreen(sair);
            }

            // eventos bons e ruins aleatorios 
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
                    // botao para mutar
                        
                        toggleSound = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
               
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 1){
                    // botao de som ativado
                
                        toggleSound = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                
                }else if (evento.mouse.x >= 325 && evento.mouse.x <= 450 &&
                    evento.mouse.y >= 630 && evento.mouse.y <= 660 && toggleSound == 1){
                    // botao de investimento
                    budgetScreen();
                }

                else if((togglePopup == 1 || togglePopup == 0) || evento.mouse.x >= 475 && 
                    evento.mouse.x <= 485 && evento.mouse.y >= 320 && evento.mouse.y <= 345){
                    // botao de som
                    
                        togglePopup = 3;
                        al_start_timer(contador);
                
                }else if(togglePopup == 3 && evento.mouse.x >= 830 && evento.mouse.x <= 840 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                    // botao em play
                
                        togglePlay = 0;
                        pauseText = "PAUSAR";
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                
                }else if (togglePopup == 3 && evento.mouse.x >= 830 && evento.mouse.x <= 840 && 
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 0){
                    // botao pausado
                
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
     
        al_set_target_bitmap(al_get_backbuffer(janela));

        al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(29,113,184));
        al_draw_bitmap(blackBack, 0, -10, 0);
        // imagem do prefeito(a)
        if(cidade.homem){
            al_draw_bitmap(firstPersonaImage, 145, 530, 0);    
        }
        else{
            al_draw_bitmap(secondPersonaImage, 145, 530, 0);
        }
        
        // cabeçalho
        al_draw_bitmap(pauseBtnImage, 830, 25, 0);
        al_draw_bitmap(clockBtnImage, 765, 20, 0);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 840, 23, 0, pauseText);
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(310, 10, 730, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 30, 35, 0, "ESCOLHA O SEU PREFEITO");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, news);
        
        // relogio
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());

        // detalhe prefeito
        al_draw_filled_rectangle(325, 530, 775, 550, al_map_rgb(87, 87, 86));        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 325, 610, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_text(onzePx, al_map_rgb(203, 187, 160), 370, 610, ALLEGRO_ALIGN_LEFT, "21/03/1997");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 325, 595, ALLEGRO_ALIGN_LEFT, *cidade.nome);
        al_draw_textf(vinteDoisPx, al_map_rgb(255, 255, 255), 325, 570, ALLEGRO_ALIGN_LEFT, "R$%d", cidade.dinheiro);
        al_draw_bitmap(investiment, 325, 630, ALLEGRO_ALIGN_LEFT);
        al_draw_bitmap(education, 390+75+50, 575, 0);
        al_draw_bitmap(security, 445+75+50, 575, 0);
        al_draw_bitmap(sanitation, 500+75+50, 575, 0);
        al_draw_bitmap(health, 555+75+50, 575, 0);
        al_draw_bitmap(fun, 610+75+50, 575, 0);

        // PopUp de eventos
        if(togglePopup == 1) {
            al_draw_filled_rectangle(300, 260, 750, 375, al_map_rgb(255, 255, 255));
            al_draw_bitmap(quietIcon, (1024/2), 270, 0);
            al_draw_text(onzePx, al_map_rgb(0, 0, 0), (1024/2), 300, ALLEGRO_ALIGN_CENTRE, *texto_evento);
            al_draw_text(onzePx, al_map_rgb(0, 0, 0), (1024/2), 320, ALLEGRO_ALIGN_CENTRE, bom.text);
            al_draw_bitmap(quietBtn, 475, 340, 0);

        }
        else if(togglePopup == 0){
            al_draw_filled_rectangle(300, 260, 750, 375, al_map_rgb(255, 255, 255));
            al_draw_bitmap(cautionIcon, (1024/2), 270, 0);
            al_draw_text(onzePx, al_map_rgb(0, 0, 0), (1024/2), 300, ALLEGRO_ALIGN_CENTRE, *texto_evento);
            al_draw_text(onzePx, al_map_rgb(0, 0, 0), (1024/2), 320, ALLEGRO_ALIGN_CENTRE, ruim.text);
            al_draw_bitmap(cautionBtn, 475, 340, 0);

        }

            colorValidation(cidade.educacao, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 475+50, 620, 0, "%d%%", cidade.educacao);
            colorValidation(cidade.saude, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 530+50, 620, 0, "%d%%", cidade.saude);
            colorValidation(cidade.saneamento, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 640+50, 620, 0, "%d%%", cidade.saneamento);
            colorValidation(cidade.seguranca, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 585+50, 620, 0, "%d%%", cidade.seguranca);
            colorValidation(cidade.lazer, &r, &g, &b);
            al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 695+50, 620, 0, "%d%%", cidade.lazer);

        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}

// tela de investimentos
int budgetScreen(){
    
    globalDeclarations();
    
    if (!al_install_mouse() || !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao carregar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador);

    if(&compra == NULL){
        inicia_item(&compra);
    }
    while (!sair){
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);
            
            // relogio
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                seg--;
                if (seg == -1) {
                    min--;
                    seg = 59;
                }
            }

            // fim de jogo por tempo
            if (min == 0 && seg == 0){
                loserScreen(sair);
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
                if       (evento.mouse.x >= 405 && evento.mouse.x <= 604 &&
                          evento.mouse.y >= 163 && evento.mouse.y <= 265){
                          //botão investimento EDUCAÇÃO
                          compra_educacao(&cidade, &compra);
                }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                          evento.mouse.y >= 301 && evento.mouse.y <= 401){
                          //botão investimento SEGURANÇA
                          printf("botao 2\n");
                }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                          evento.mouse.y >= 439 && evento.mouse.y <= 539){
                          //botão investimento SANEAMENTO
                          printf("botao 3\n");
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 163 && evento.mouse.y <= 263){
                          //botão investimento SAÚDE
                          printf("botao 4\n");
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 301 && evento.mouse.y <= 401){
                          //botão investimento LAZER
                          printf("botao 5\n" );
                }else if (evento.mouse.x >= 140 && evento.mouse.x <= 200 &&
                          evento.mouse.y >= 558 && evento.mouse.y <= 578){
                          //botão de VOLTAR
                          printf("botao 6\n" );
                          playScreen();
                }else if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 0){
                        //botão de MUDO
                        toggleSound = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
               
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 1){
                        //botão de SOM ativo
                        toggleSound = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
            
                }else if( evento.mouse.x >= 830 && evento.mouse.x <= 840 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                        // botão de PAUSAR
                        togglePlay = 0;
                        pauseText = "PAUSAR";
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                
                }else if ( evento.mouse.x >= 830 && evento.mouse.x <= 840 && 
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 0){
                        //botão de PLAY
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
        
        // Cabeçalho
        al_draw_bitmap(pauseBtnImage, 830, 25, 0);
        al_draw_bitmap(clockBtnImage, 765, 20, 0);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 840, 23, 0, pauseText);
        al_draw_bitmap(soundBtnImage, 900, 20, 0);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 925, 23, 0, "SOM");
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 30, 35, 0, "CONSTRUA UM HOSPITAL");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, news);
        //imagem do prefeito(a)
        if(cidade.homem){
            al_draw_bitmap(firstPersonaImage, 140, 152, 0);    
        }else{
            al_draw_bitmap(secondPersonaImage, 140, 152, 0);
        }
        //desenhando botões de investimento
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
        //al_draw_bitmap(garbage, 509, 226, 0);
        //al_draw_bitmap(garbage, 509, 364, 0);
        //al_draw_bitmap(garbage, 509, 502, 0);
        //al_draw_bitmap(garbage, 790, 226, 0);
        //al_draw_bitmap(garbage, 790, 364, 0);
        al_draw_bitmap(educacao, 405, 163, 0);
        al_draw_bitmap(seguranca, 405, 301, 0);
        al_draw_bitmap(saneamento, 405, 439, 0);
        al_draw_bitmap(saude, 693, 163, 0);
        al_draw_bitmap(lazer, 693, 301, 0);
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 540, 167, ALLEGRO_ALIGN_CENTRE, "EDUCACÃO");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 545, 306, ALLEGRO_ALIGN_CENTRE, "SEGURANCA");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 550, 447, ALLEGRO_ALIGN_CENTRE, "SANEAMENTO");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 813, 167, ALLEGRO_ALIGN_CENTRE, "SAÚDE");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 812, 306, ALLEGRO_ALIGN_CENTRE, "LAZER");

        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 542-40, 167+20, 0, "R$");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 542-40, 306+20, 0, "R$");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 542-40, 447+20, 0, "R$");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 813-20, 167+20, 0, "R$");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 812-20, 306+20, 0, "R$");
        
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 140, 378, 0, "EDUCACÃO");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 140, 411, 0, "SAÚDE");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 140, 444, 0, "SEGURANCA");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 140, 477, 0, "LAZER");
        al_draw_textf(quatorzePx, al_map_rgb(255, 255, 255), 140, 510, 0, "SANEAMENTO");
        
        colorValidation(cidade.educacao, &r, &g, &b);
        al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 323, 378, 0, "%d%%", cidade.educacao);
        colorValidation(cidade.saude, &r, &g, &b);
        al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 323, 411, 0, "%d%%", cidade.saude);
        colorValidation(cidade.seguranca, &r, &g, &b);
        al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 323, 444, 0, "%d%%", cidade.seguranca);
        colorValidation(cidade.lazer, &r, &g, &b);
        al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 323, 477, 0, "%d%%", cidade.lazer);
        colorValidation(cidade.saneamento, &r, &g, &b);
        al_draw_textf(quatorzePx, al_map_rgb(r, g, b), 323, 510, 0, "%d%%", cidade.saneamento);
        
        int n = 337;
        for (int i = 0; i < 6; i++){
            al_draw_filled_rectangle(140, (n+=1), 350, (n+=32), al_map_rgb(255, 255, 255));        
        }
        al_draw_bitmap(voltar, 140, 568, 0);
        al_draw_bitmap(money, 456, 82, 0);
        al_draw_textf(dezesseisPx, al_map_rgb(104, 94, 35), 486, 87, 0, "R$ %d", cidade.dinheiro);
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
    }
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);

    return 0;
}

// tela caso o jogador perca
int loserScreen(){

    globalDeclarations();
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    while (!sair){
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);
 
        while (!al_is_event_queue_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            ALLEGRO_TIMEOUT timeout;
            al_init_timeout(&timeout, 0.5);
 
            int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
     
            if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                sair = 1;
            }
        }
    }    
        al_clear_to_color(al_map_rgb(0, 0, 0));
        
        al_draw_bitmap(taboaoLogoImageloser,  460, 200, 0);
        al_draw_text(trintaQuatroBoldPx, al_map_rgb(190,22,34),  (1024/2), 400, ALLEGRO_ALIGN_CENTRE, "VOCÊ É UM PÉSSIMO PREFEITO!");

        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}

// tela de INSTRUÇÕES
int helpScreen(){

    globalDeclarations();   
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    while(!sair){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        al_register_event_source(fila_eventos, al_get_mouse_event_source());
        al_register_event_source(fila_eventos, al_get_display_event_source(janela));
        
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }
        if (tem_eventos && evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            mainScreen();
        }

        al_draw_rounded_rectangle(250, 50, 750, 600, 0.5, 0.5, al_map_rgb(52, 52, 51), 5);
        al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
        al_draw_filled_rectangle(252, 48, 748, 598, al_map_rgb(52, 52, 51));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
        al_draw_text(trintaOitopx, al_map_rgb(255, 255, 255), (1024/2), 80, ALLEGRO_ALIGN_CENTRE, "INSTRUÇÕES");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 150, 0, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 200, 0, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 250, 0, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 300, 0, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 350, 0, "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        
        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}

//tela de CRÉDITOS
int creditScreen(){
    
    globalDeclarations();
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    while(!sair){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        al_register_event_source(fila_eventos, al_get_mouse_event_source());
        al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            sair = 1;
        }
        if (tem_eventos && evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            mainScreen();
        }

        al_draw_rounded_rectangle(250, 50, 750, 600, 0.5, 0.5, al_map_rgb(52, 52, 51), 5);
        al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
        al_draw_filled_rectangle(252, 48, 748, 598, al_map_rgb(52, 52, 51));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_rounded_rectangle(250, 50, 750, 600, 5, 5, al_map_rgb(52, 52, 51), 20);
        al_draw_text(trintaOitopx, al_map_rgb(255, 255, 255), (1024/2), 80, ALLEGRO_ALIGN_CENTRE, "CREDITOS");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 150, 0, "*                     Caio Luzano");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 200, 0, "*                     Daniel Moniz");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 250, 0, "*                     Henrique Shodi");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 300, 0, "*                     Luiz Frederico");
        al_draw_text(quinzePx, al_map_rgb(255, 255, 255), (1024/4), 350, 0, "*                     Matheus Souza");
        
        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}