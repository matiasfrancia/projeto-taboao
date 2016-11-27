// Para compilar
/*gcc prototipo.c -o prototipo.exe $(pkg-config –cflags –libs allegro-5) -lallegro -lallegro_main -lallegro_image -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro_audio -lallegro_acodec -std=c99*/

// Bibliotecas e dependencias que estamos usando
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include <stdio.h>
#include "structs.h"
#include "eventos.h"


// Funções de tela
int mainScreen();
int nivelScreen();
int chooseScreen();
int playScreen();
int budgetScreen();
int eventScreen();
int loserScreen();
int winnerScreen();
int helpScreen();
int creditScreen();
int destroyall();
int saveScreen();

typedef struct controle_de_compra_eventos{

    int saude;
    int educacao;
    int lazer;
    int saneamento;
    int seguranca;

}CONTROLE;

// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;

// Atributos Candidatos
CANDIDATO cidade;

// Atributos Investimentos
ITEM compra;

CANDIDATO *vector_de_projetos;

// Imagens/Fontes/Músicas usadas no jogo
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP  *taboaoLogoImage = NULL,
                *taboaoMiniLogoImage = NULL,
                *taboaoLogoImageloser = NULL,
                *instrucaoBtnImage = NULL,
                *creditBtnImage = NULL,
                *continuarBtnImage = NULL,
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
                *blackBack = NULL,
                *compraNaoDisponivel = NULL,
                *solenidade = NULL,
                *eventBtn = NULL,
                *homeBtn = NULL,
                *allegroLogo = NULL,
                *senacLogo = NULL,
                *creditTaboao = NULL,
                *teste = NULL,
                *aceitarBtn = NULL,
                *recusarBtn = NULL;

char *news = "NADA DE MAIS ESTA ACONTECENDO EM TABOÂO";

ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
ALLEGRO_FONT *onzePx = NULL,
            *dozePx =  NULL,
            *dozeBoldPx =  NULL,
            *quatorzePx =  NULL,
            *quatorzeBoldPx =  NULL,
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

int botao = 0,
    mTotal = 0,
    backSave = 0,
    *bSave = &backSave,
    backHelpCredit = 0,
    *bHelpCredit = &backHelpCredit;

int sair = 0;
int r = 0, g = 0, b = 0;
int min = 5, seg = 0;
int segano = 0, ano = 2016;
int candidato = 0;
int toggleSound = 1;    
char *pauseText = "PAUSAR";  
int togglePlay = 1;


void inicializacao_compra_eventos(CONTROLE *compra){

    compra->lazer = 0;
    compra->educacao = 0;
    compra->seguranca = 0;
    compra->saneamento = 0;
    compra->saude = 0;

}

// Função para carregar conteúdo de images/fontes    
void globalDeclarations(){

    printf("FUNÇÃO globalDeclarations-----------------------------------------------------------------\n");

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
    continuarBtnImage = al_load_bitmap("Images/mainImages/continuar-botao.png");
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
    aceitarBtn = al_load_bitmap("Images/playScreen/aceitarBtn.png");
    recusarBtn = al_load_bitmap("Images/playScreen/recusarBtn.png");
    investiment = al_load_bitmap("Images/playScreen/investimento.png");
    cautionBtn = al_load_bitmap("Images/globalImages/caution-btn.png");
    cautionIcon = al_load_bitmap("Images/globalImages/caution-icon.png");
    quietBtn = al_load_bitmap("Images/globalImages/quiet-btn.png");
    quietIcon = al_load_bitmap("Images/globalImages/quiet-icon.png");
    facilBtnImage = al_load_bitmap("Images/nivelImages/facilBtnImage.png");
    medioBtnImage = al_load_bitmap("Images/nivelImages/medioBtnImage.png");
    dificilBtnImage = al_load_bitmap("Images/nivelImages/dificilBtnImage.png");
    compraNaoDisponivel = al_load_bitmap("Images/budgetScreen/noBudget-btn.png");
    solenidade = al_load_bitmap("Images/budgetScreen/taboao-btn.png");
    homeBtn = al_load_bitmap("Images/globalImages/home.png");
    eventBtn = al_load_bitmap("Images/budgetScreen/eventScreen.png");
    senacLogo = al_load_bitmap("Images/creditScreen/logoSenacre.png");
    allegroLogo = al_load_bitmap("Images/creditScreen/allegroLogo.png");
    creditTaboao = al_load_bitmap("Images/creditScreen/taboaoLogo.png");
    teste = al_load_bitmap("Images/creditScreen/creditScreen.png");
    //Global fontes
    onzePx = al_load_ttf_font("Font/arial.ttf", 11,0 );
    dozePx = al_load_ttf_font("Font/arial.ttf", 12,0 );
    dozeBoldPx = al_load_ttf_font("Font/Arial_Bold.ttf", 12,0 );
    quatorzePx = al_load_ttf_font("Font/arial.ttf", 14,0 );
    quatorzeBoldPx = al_load_ttf_font("Font/Arial_Bold.ttf", 14,0 );
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
    
    //printf("FUNÇÃO colorValidation------------------------\n");

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

    printf("FUNÇÃO main-----------------------------------\n");

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

    printf("FUNÇÃO mainScreen----------------------------------\n");

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
                    backHelpCredit = 1;
                    helpScreen(backHelpCredit);
            // Botão de CRÉDITOS
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 550 && evento.mouse.y <= 585){
                    backHelpCredit = 1;
                    creditScreen(backHelpCredit);
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

    destroyall();

    return 0;
}
int saveScreen(){



    printf("FUNÇÃO saveScreen----------------------------------\n");

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
                switch (backSave){
                    case 1:
                        chooseScreen(sair);
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_start_timer(contador);
                    break;
                    case 2:
                        playScreen(sair);
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_start_timer(contador);
                    break;
                    case 3:
                        budgetScreen(sair);
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_start_timer(contador);
                    break;
                    case 4:
                        eventScreen(sair);
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_start_timer(contador);
                    break;
                    default:
                        printf("valor home inválido");
                    break;
                }


            // Botão de INTRUÇÕES
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 500 && evento.mouse.y <= 535){
                    backHelpCredit = 2;
                    helpScreen(backHelpCredit);
            // Botão de CRÉDITOS
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 550 && evento.mouse.y <= 585){
                    backHelpCredit = 2;
                    creditScreen(backHelpCredit);
            }
        }
        
        al_draw_filled_rectangle(0, 0, 1080, 720, al_map_rgb(0, 0, 0));
        al_draw_text(trintaDoisPx, al_map_rgb(29, 113, 189), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "PROJETO TABOÃO");
        al_draw_bitmap(taboaoMiniLogoImage, 420, 200, 0);
        al_draw_bitmap(continuarBtnImage, 400, 450, 0);
        al_draw_bitmap(instrucaoBtnImage, 400, 500, 0);
        al_draw_bitmap(creditBtnImage, 400, 550, 0);
        
        al_flip_display();
    }

    destroyall();

    return 0;
}
// função da tela de Escolha de Dificuldade
int nivelScreen(){

    printf("FUNÇÃO nivelScreen---------------------------------------\n");

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
                    select_nivel(&cidade, 1);
                    print_candidato(&cidade);
                    chooseScreen();
            // Botão de Nivel MÉDIO
            }else if (evento.mouse.x >= 415 && evento.mouse.x <= 595 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                    select_nivel(&cidade, 2);
                    print_candidato(&cidade);
                    chooseScreen();
            // Botão de Nivel DIFICIL
            }else if (evento.mouse.x >= 665 && evento.mouse.x <= 845 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                    select_nivel(&cidade, 3);
                    print_candidato(&cidade);
                    chooseScreen();
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

    destroyall();

    return 0;
}

// Tela de escolha de candidatos
int chooseScreen(){

    printf("FUNÇÃO chooseScreen---------------------------------------\n");

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
        return -1;
    }
 
    CANDIDATO *vetor_de_candidatos;
    vetor_de_candidatos = select_candidato();

    // Descrição de candidatos
    vetor_de_candidatos[0].descricao = "Professor(a) de Agronomia da UNESP e foi ajudante de pedreiro";
    vetor_de_candidatos[1].descricao = "A favor da legalização do aborto e contra combustíveis fósseis";
    vetor_de_candidatos[2].descricao = "Empresário(a) da música a favor da biodiversidade";
    
    char *majorName; 
    char *majorDesc;  
    int educacao; 
    int saude; 
    int seguranca; 
    int saneamento; 
    int lazer;
    int dinheiro;

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
                        cidade.nome = vetor_de_candidatos[0].nome;
                        cidade.dinheiro += vetor_de_candidatos[0].dinheiro;
                        cidade.saneamento += vetor_de_candidatos[0].saneamento;
                        cidade.saude += vetor_de_candidatos[0].saude;
                        cidade.educacao += vetor_de_candidatos[0].educacao;
                        cidade.lazer += vetor_de_candidatos[0].lazer;
                        cidade.seguranca += vetor_de_candidatos[0].seguranca;
                        playScreen();
            
                }else if (evento.mouse.x >= 415 && evento.mouse.x <= 585 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 2
                        candidato = 2;
                        cidade.nome = vetor_de_candidatos[1].nome;
                        cidade.dinheiro += vetor_de_candidatos[1].dinheiro;
                        cidade.saneamento += vetor_de_candidatos[1].saneamento;
                        cidade.saude += vetor_de_candidatos[1].saude;
                        cidade.educacao += vetor_de_candidatos[1].educacao;
                        cidade.lazer += vetor_de_candidatos[1].lazer;
                        cidade.seguranca += vetor_de_candidatos[1].seguranca;
                        playScreen();
                }else if (evento.mouse.x >= 680 && evento.mouse.x <= 850 &&
                    evento.mouse.y >= 335 && evento.mouse.y <= 480){
                // candidato random 3
                        candidato = 3;
                        cidade.nome = vetor_de_candidatos[2].nome;
                        cidade.dinheiro += vetor_de_candidatos[2].dinheiro;
                        cidade.saneamento += vetor_de_candidatos[2].saneamento;
                        cidade.saude += vetor_de_candidatos[2].saude;
                        cidade.educacao += vetor_de_candidatos[2].educacao;
                        cidade.lazer += vetor_de_candidatos[2].lazer;
                        cidade.seguranca += vetor_de_candidatos[2].seguranca;
                        playScreen();
                }else if(evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 0){
                // botão de música
                        toggleSound = 1;
                        soundBtnImage = muteBtnImage;
                        al_set_audio_stream_playing(musica, false);
                }else if(evento.mouse.x >= 965 && evento.mouse.x <= 976 &&
                    evento.mouse.y >= 17 && evento.mouse.y <= 40){
                // botão HOME
                        backSave = 1;
                        saveScreen(backSave);
                        al_stop_timer(contador);
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && toggleSound == 1){
                // botão de pause
                        toggleSound = 0;
                        soundBtnImage = soundBackup;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                }
            }
        }if(toggleSound == 1){
                soundBtnImage = soundBackup;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
        }else if(toggleSound == 0){
                soundBtnImage = muteBtnImage;
                al_set_audio_stream_playing(musica, false);
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
            dinheiro = vetor_de_candidatos[0].dinheiro; 
        }else if (candidato == 2){
            majorName = *vetor_de_candidatos[1].nome;
            majorDesc = vetor_de_candidatos[1].descricao;
            educacao =  vetor_de_candidatos[1].educacao ; 
            saude =  vetor_de_candidatos[1].saude ; 
            seguranca =  vetor_de_candidatos[1].seguranca ; 
            saneamento =  vetor_de_candidatos[1].saneamento ; 
            lazer =  vetor_de_candidatos[1].lazer ; 
            dinheiro = vetor_de_candidatos[1].dinheiro;
        }else if(candidato == 3){
            majorName = *vetor_de_candidatos[2].nome;
            majorDesc = vetor_de_candidatos[2].descricao;
            educacao =  vetor_de_candidatos[2].educacao ; 
            saude =  vetor_de_candidatos[2].saude ; 
            seguranca =  vetor_de_candidatos[2].seguranca ; 
            saneamento =  vetor_de_candidatos[2].saneamento ; 
            lazer =  vetor_de_candidatos[2].lazer ; 
            dinheiro = vetor_de_candidatos[2].dinheiro;
        }else{
            majorName = "Escolha o seu Prefeito(a)";
            majorDesc = 0;
            educacao = 0; 
            dinheiro = 0;
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

        //cabeçalhSo
        al_draw_bitmap(homeBtn, 965, 20, 0);
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
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 275, 590+25, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_textf(onzePx, al_map_rgb(203, 187, 160), 320, 590+25, ALLEGRO_ALIGN_LEFT, "%d", ano);
        al_draw_text(quatorzeBoldPx, al_map_rgb(255, 255, 255), 275, 575+20, ALLEGRO_ALIGN_LEFT, majorName);
        
        // icones de parametros
        al_draw_bitmap(education, 390+75, 555+40, 0);
        al_draw_bitmap(security, 445+75, 555+40, 0);
        al_draw_bitmap(sanitation, 500+75, 555+40, 0);
        al_draw_bitmap(health, 555+75, 555+40, 0);
        al_draw_bitmap(fun, 610+75, 555+40, 0);

        // valores dos parametros
        if(educacao != 0 || saude != 0 || saneamento != 0 || seguranca != 0 || lazer != 0){
            colorValidation(educacao, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 475, 640, 0, "%d%%", educacao);
            colorValidation(saude, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 530, 640, 0, "%d%%", saude);
            colorValidation(saneamento, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 640, 640, 0, "%d%%", saneamento);
            colorValidation(seguranca, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 585, 640, 0, "%d%%", seguranca);
            colorValidation(lazer, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 695, 640, 0, "%d%%", lazer);
        }

        al_flip_display();
    }

    destroyall();
 
    return 0;
}

// tela de jogar
int playScreen(){
    printf("FUNÇÃO playScreen---------------------------------------\n");

    globalDeclarations();
    
    srand((unsigned)time(NULL));


    EVENTO_RUIM ruim;
    EVENTO_BOM bom;
    char **texto_evento;

    int global_timer = 60 * min;
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
    
    int togglePopup = 3;
    int toggleColor = 3;
    int rEduc = 0, 
        rSaud = 0,
        rSane = 0,
        rSegu = 0,
        rLaze = 0,
        rsegundos = 60;
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
                segano++;
                if (seg == -1) {
                    min--;
                    seg = 59;
                }
                if (segano %75 == 0){
                    ano++;
                }
            }


            // caso o tempo de 5 minutos ou o dinheiro acabe
            if ((min == 0 && seg == 0) || cidade.dinheiro <= 0){
                loserScreen(sair);
            }

            // eventos bons e ruins aleatorios 
            global_timer = (60 * min) + seg;
            if(global_timer % 10 == 0){
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
                    cidade.dinheiro += ruim.dinheiro;
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
                    evento.mouse.y >= 630 && evento.mouse.y <= 660 && togglePlay == 1 ){
                    // botao de investimento
                        budgetScreen();
                }else if((togglePopup == 0) &&
                        evento.mouse.x >= 477 && evento.mouse.x <= 578 && 
                        evento.mouse.y >= 344 && evento.mouse.y <= 361){
                    // botao de voltar quando evento ruim
                    
                        togglePopup = 3;
                        al_start_timer(contador);
                        toggleColor = 0;
                

                }else if((togglePopup == 1) && 
                        evento.mouse.x >= 412 && evento.mouse.x <= 513 && 
                        evento.mouse.y >= 344 && evento.mouse.y <= 363){
                    // botao de aceitar quando evento bom
                        cidade.dinheiro += bom.investimento;                    
                        togglePopup = 3;
                        al_start_timer(contador);
                        toggleColor = 1;
                
                }else if((togglePopup == 1) && 
                        evento.mouse.x >= 537 && evento.mouse.x <= 637 && 
                        evento.mouse.y >= 344 && evento.mouse.y <= 363){
                    // botao de negar quando evento bom
                        togglePopup = 3;
                        al_start_timer(contador);
                
                }else if(evento.mouse.x >= 965 && evento.mouse.x <= 976 &&
                    evento.mouse.y >= 17 && evento.mouse.y <= 40){
                // botão de música
                        backSave = 2;
                        saveScreen(backSave);
                        al_stop_timer(contador);
                }else if(togglePopup == 3 && evento.mouse.x >= 830 && evento.mouse.x <= 840 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                    // botao em play
                        togglePlay = 0;
                        pauseText = "PLAY";                          
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                        
                
                }else if (togglePopup == 3 && evento.mouse.x >= 830 && evento.mouse.x <= 840 && 
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 0){
                    // botao pausado
                        togglePlay = 1;
                        pauseText = "PAUSAR";                        
                        pauseBtnImage = pauseBackup;
                        toggleSound = 1;
                        al_set_audio_stream_playing(musica, false);
                        al_start_timer(contador);
                        
                                        
                }
            }
        }if(toggleSound == 1){
                soundBtnImage = soundBackup;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
        }else if(toggleSound == 0){
                soundBtnImage = muteBtnImage;
                al_set_audio_stream_playing(musica, false);
        }else if(togglePlay == 1){
                pauseText = "PLAY";                          
                pauseBtnImage = playBtnImage;
                toggleSound = 0;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
                al_stop_timer(contador);
        }else if(togglePlay == 0){
                pauseText = "PAUSAR";                        
                pauseBtnImage = pauseBackup;
                toggleSound = 1;
                al_set_audio_stream_playing(musica, false);
                al_start_timer(contador);
        }
        
        al_clear_to_color(al_map_rgb(0, 0, 0));
 
        al_set_target_bitmap(firstPersonaImage);
     
        al_set_target_bitmap(al_get_backbuffer(janela));

        //coloração de fundo para indicar estado de taboão
        mTotal = ((cidade.educacao + cidade.saude + cidade.saneamento + cidade.seguranca + cidade.lazer)/5);

        if (mTotal >= 70){
            al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(29,113,184));
        }
        if (mTotal < 70 && mTotal >= 60){
            al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(84,85,138));
        }
        if (mTotal < 60 && mTotal >= 40){
            al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(125,65,105));
        }
        if (mTotal < 40 && mTotal >= 20){
            al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(196,30,48));
        }
        if (mTotal < 20 && mTotal >= 0){
            al_draw_filled_rectangle(0,0,1200,600, al_map_rgb(190,22,34));
        }

        al_draw_bitmap(blackBack, 0, -10, 0);
        // imagem do prefeito(a)
        if(cidade.homem){
            al_draw_bitmap(firstPersonaImage, 145, 530, 0);    
        }
        else{
            al_draw_bitmap(secondPersonaImage, 145, 530, 0);
        }


        
        // cabeçalho
        al_draw_bitmap(homeBtn, 965, 20, 0);
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

        // detalhe prefeito
        al_draw_filled_rectangle(325, 530, 775, 550, al_map_rgb(87, 87, 86));        
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 325, 610, ALLEGRO_ALIGN_LEFT, "Taboão - ");
        al_draw_textf(onzePx, al_map_rgb(203, 187, 160), 370, 610, ALLEGRO_ALIGN_LEFT, "%d", ano);
        al_draw_text(onzePx, al_map_rgb(255, 255, 255), 325, 595, ALLEGRO_ALIGN_LEFT, *cidade.nome);
        
        if(toggleColor == 1){
            al_draw_textf(vinteDoisPx, al_map_rgb(0, 150, 64), 325, 570, ALLEGRO_ALIGN_LEFT, "R$%d", cidade.dinheiro);
            int testemin = 0;
            int testeseg = 3;
            while (!sair){
                if (!al_is_event_queue_empty(fila_contador)){
                    ALLEGRO_EVENT evento;
                    al_wait_for_event(fila_contador, &evento);
                    
                    if (evento.type == ALLEGRO_EVENT_TIMER)
                    {
                        testeseg--;
                        if (testeseg == -1)
                        {
                            testemin--;
                            testeseg = 59;
                        }
                    }
                    if(testeseg == 0){
                        toggleColor = 3;
                    }
                }    
            }
        }else if (toggleColor == 0){
            al_draw_textf(vinteDoisPx, al_map_rgb(190, 22, 34), 325, 570, ALLEGRO_ALIGN_LEFT, "R$%d", cidade.dinheiro);
            int testemin = 0;
            int testeseg = 3;
            while (!sair){
                if (!al_is_event_queue_empty(fila_contador)){
                    ALLEGRO_EVENT evento;
                    al_wait_for_event(fila_contador, &evento);
                    
                    if (evento.type == ALLEGRO_EVENT_TIMER)
                    {
                        testeseg--;
                        if (testeseg == -1)
                        {
                            testemin--;
                            testeseg = 59;
                        }
                    }
                    if(testeseg == 0){
                        toggleColor = 3;
                    }
                }    
            }

        }else{
            al_draw_textf(vinteDoisPx, al_map_rgb(255, 255, 255), 325, 570, ALLEGRO_ALIGN_LEFT, "R$%d", cidade.dinheiro);

        }
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
            al_draw_bitmap(aceitarBtn, 410, 340, 0);
            al_draw_bitmap(recusarBtn, 535, 340, 0);

        }
        else if(togglePopup == 0){
            al_draw_filled_rectangle(300, 260, 750, 375, al_map_rgb(255, 255, 255));
            al_draw_bitmap(cautionIcon, (1024/2), 270, 0);
            al_draw_text(onzePx, al_map_rgb(0, 0, 0), (1024/2), 300, ALLEGRO_ALIGN_CENTRE, *texto_evento);
            al_draw_text(onzePx, al_map_rgb(0, 0, 0), (1024/2), 320, ALLEGRO_ALIGN_CENTRE, ruim.text);
            al_draw_bitmap(cautionBtn, 475, 340, 0);

        }

            colorValidation(cidade.educacao, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 475+50, 620, 0, "%d%%", cidade.educacao);
            colorValidation(cidade.saude, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 530+50, 620, 0, "%d%%", cidade.saude);
            colorValidation(cidade.saneamento, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 640+50, 620, 0, "%d%%", cidade.saneamento);
            colorValidation(cidade.seguranca, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 585+50, 620, 0, "%d%%", cidade.seguranca);
            colorValidation(cidade.lazer, &r, &g, &b);
            al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 695+50, 620, 0, "%d%%", cidade.lazer);

        al_flip_display();
    }

    destroyall();
 
    return 0;
}

// tela de investimentos
int budgetScreen(){

    printf("FUNÇÃO budgetScreen-------------------------------------\n");
    
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
                segano++;
                if (seg == -1) {
                    min--;
                    seg = 59;
                }
                if (segano %75 == 0){
                    ano++;
                }
            }

            // fim de jogo por tempo ou falta de dinheiro
            if (min == 0 && seg == 0 || cidade.dinheiro <= 0){
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
                          evento.mouse.y >= 163 && evento.mouse.y <= 265 && togglePlay == 1){
                          //botão investimento EDUCAÇÃO
                          printf("botao1\n");
                          compra_educacao(&cidade, &compra);
                }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                          evento.mouse.y >= 301 && evento.mouse.y <= 401 && togglePlay == 1){
                          //botão investimento SEGURANÇA
                          printf("botao 2\n");
                          compra_seguranca(&cidade, &compra);
                }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                          evento.mouse.y >= 439 && evento.mouse.y <= 539 && togglePlay == 1){
                          //botão investimento SANEAMENTO
                          printf("botao 3\n");
                          compra_saneamento(&cidade, &compra);
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 163 && evento.mouse.y <= 263 && togglePlay == 1){
                          //botão investimento SAÚDE
                          printf("botao 4\n");
                          compra_saude(&cidade, &compra);
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 301 && evento.mouse.y <= 401 && togglePlay == 1){
                          //botão investimento LAZER
                          printf("botao 5\n" );
                          compra_lazer(&cidade, &compra);
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 339 && evento.mouse.y <= 539 && togglePlay == 1){
                          //botão investimento SOLENIDADES
                          printf("botao 6\n" );
                          eventScreen();
                }else if (evento.mouse.x >= 140 && evento.mouse.x <= 200 &&
                          evento.mouse.y >= 558 && evento.mouse.y <= 578 && togglePlay == 1){
                          //botão de VOLTAR
                          printf("botao 7\n" );
                          playScreen();
                }
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
                
                }else if(evento.mouse.x >= 965 && evento.mouse.x <= 976 &&
                    evento.mouse.y >= 17 && evento.mouse.y <= 40){
                // botão de música
                        backSave = 3;
                        saveScreen(backSave);
                        al_stop_timer(contador);
                }else if(evento.mouse.x >= 830 && evento.mouse.x <= 840 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                    // botao em play
                
                        togglePlay = 0;
                        pauseText = "PLAY";                          
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                        
                
                }else if (evento.mouse.x >= 830 && evento.mouse.x <= 840 && 
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 0){
                    // botao pausado
                
                        togglePlay = 1;
                        pauseText = "PAUSAR";                        
                        pauseBtnImage = pauseBackup;
                        toggleSound = 1;
                        al_set_audio_stream_playing(musica, false);
                        al_start_timer(contador);
                
                }
            }
        }if(toggleSound == 1){
                soundBtnImage = soundBackup;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
        }else if(toggleSound == 0){
                soundBtnImage = muteBtnImage;
                al_set_audio_stream_playing(musica, false);
        }else if(togglePlay == 1){
                pauseText = "PLAY";                          
                pauseBtnImage = playBtnImage;
                toggleSound = 0;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
                al_stop_timer(contador);
        }else if(togglePlay == 0){
                pauseText = "PAUSAR";                        
                pauseBtnImage = pauseBackup;
                toggleSound = 1;
                al_set_audio_stream_playing(musica, false);
                al_start_timer(contador);
        }  

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));
        
        // Cabeçalho
        al_draw_bitmap(homeBtn, 965, 20, 0);
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
        al_draw_filled_rectangle(390, 428, 633, 532, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 152, 923, 255, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 290, 923, 393, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 428, 923, 532, al_map_rgb(60, 60, 59));
        
        
        if(cidade.dinheiro >= precos[compra.educacao] && 
           precos[compra.educacao] != 0 && cidade.educacao <= 100){
            al_draw_bitmap(investir, 539, 226, 0);    
        }
        else{
            al_draw_bitmap(compraNaoDisponivel, 539, 226, 0);
        }


        if(cidade.dinheiro >= precos[compra.seguranca] && 
           precos[compra.seguranca] != 0 && cidade.seguranca <= 100){
            al_draw_bitmap(investir, 539, 364, 0);    
        }
        else{
            al_draw_bitmap(compraNaoDisponivel, 539, 364, 0);
        }
        

        if(cidade.dinheiro >= precos[compra.saneamento] && 
           precos[compra.saneamento] != 0 && cidade.saneamento <= 100){
            al_draw_bitmap(investir, 539, 502, 0);    
        }
        else{
            al_draw_bitmap(compraNaoDisponivel, 539, 502, 0);
        }
        

        if(cidade.dinheiro >= precos[compra.saude] && 
           precos[compra.saude] != 0 && cidade.saude <= 100){
            al_draw_bitmap(investir, 824, 226, 0);    
        }
        else{
            al_draw_bitmap(compraNaoDisponivel, 824, 226, 0);
        }
        
        if(cidade.dinheiro >= precos[compra.lazer] && 
           precos[compra.lazer] != 0 && cidade.lazer <= 100){
            al_draw_bitmap(investir, 824, 364, 0);    
        }
        else{
            al_draw_bitmap(compraNaoDisponivel, 824, 364, 0);
        }
        
        al_draw_bitmap(educacao, 405, 163, 0);
        al_draw_bitmap(seguranca, 405, 301, 0);
        al_draw_bitmap(saneamento, 405, 439, 0);
        al_draw_bitmap(saude, 693, 163, 0);
        al_draw_bitmap(lazer, 693, 301, 0);
        al_draw_bitmap(solenidade, 693, 439, 0);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 540, 167, ALLEGRO_ALIGN_CENTRE, "EDUCACÃO");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 545, 306, ALLEGRO_ALIGN_CENTRE, "SEGURANCA");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 550, 447, ALLEGRO_ALIGN_CENTRE, "SANEAMENTO");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 813, 167, ALLEGRO_ALIGN_CENTRE, "SAÚDE");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 812, 306, ALLEGRO_ALIGN_CENTRE, "LAZER");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 840, 447, ALLEGRO_ALIGN_CENTRE, "SOLENIDADES");
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 840+3, 447+20, ALLEGRO_ALIGN_CENTRE, "Crie eventos e contri-");
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 840+5, 447+33, ALLEGRO_ALIGN_CENTRE, "bua com o desenvolvi-");
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 835, 447+46, ALLEGRO_ALIGN_CENTRE, "mento de Taboão.");

        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 542-40, 167+20, 0, "R$ %d", precos[compra.educacao]);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 542-40, 306+20, 0, "R$ %d", precos[compra.seguranca]);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 542-40, 447+20, 0, "R$ %d", precos[compra.saneamento]);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 813-20, 167+20, 0, "R$ %d", precos[compra.saude]);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 812-20, 306+20, 0, "R$ %d", precos[compra.lazer]);
        
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 378, 0, "EDUCACÃO");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 411, 0, "SAÚDE");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 444, 0, "SEGURANCA");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 477, 0, "LAZER");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 510, 0, "SANEAMENTO");
        
        colorValidation(cidade.educacao, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 378, 0, "%d%%", cidade.educacao);
        colorValidation(cidade.saude, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 411, 0, "%d%%", cidade.saude);
        colorValidation(cidade.seguranca, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 444, 0, "%d%%", cidade.seguranca);
        colorValidation(cidade.lazer, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 477, 0, "%d%%", cidade.lazer);
        colorValidation(cidade.saneamento, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 510, 0, "%d%%", cidade.saneamento);
        
        int n = 337;
        for (int i = 0; i < 6; i++){
            al_draw_filled_rectangle(140, (n+=1), 350, (n+=32), al_map_rgb(255, 255, 255));        
        }
        al_draw_bitmap(voltar, 140, 568, 0);
        al_draw_bitmap(money, 135, 325, 0);
        al_draw_textf(dezesseisPx, al_map_rgb(104, 94, 35), 165, 330, 0, "R$ %d", cidade.dinheiro);
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
    }

    destroyall();

    return 0;
}

// tela de eventos
int eventScreen(){

    printf("FUNÇÃO eventScreen---------------------------------------\n");
    CONTROLE *compra_qtd;
    if(compra_qtd == NULL){
           inicializacao_compra_eventos(compra_qtd);
    }
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
    if(vector_de_projetos == NULL){
        vector_de_projetos = select_projeto();
    }

    while (!sair){
        if (!al_is_event_queue_empty(fila_contador)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_contador, &evento);
            
            // relogio
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                seg--;
                segano++;
                if (seg == -1) {
                    min--;
                    seg = 59;
                }
                if (segano %75 == 0){
                    ano++;
                }
            }

            // fim de jogo por tempo
            if (min == 0 && seg == 0){
                if (mTotal > 60)
                {
                    winnerScreen(sair);
                }
                else{
                    loserScreen(sair);
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
                if       (evento.mouse.x >= 405 && evento.mouse.x <= 604 &&
                          evento.mouse.y >= 163 && evento.mouse.y <= 265 && togglePlay == 1){
                          //botão evento 1
                          printf("botao1\n");
                          if(cidade.dinheiro >= -(vector_de_projetos[0].dinheiro)){
                            aplica_alteracao(&cidade, &vector_de_projetos[0]);
                            goto DESATIVA_PRIMERO_BOTAO;
                          }
                }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                          evento.mouse.y >= 301 && evento.mouse.y <= 401 && togglePlay == 1){
                          //botão evento 2
                          printf("botao 2\n");
                          if(cidade.dinheiro >= -(vector_de_projetos[1].dinheiro)){
                            aplica_alteracao(&cidade, &vector_de_projetos[1]);
                            goto DESATIVA_SEGUNDO_BOTAO;
                          }
                }else if (evento.mouse.x >= 405 && evento.mouse.x <= 605 &&
                          evento.mouse.y >= 439 && evento.mouse.y <= 539 && togglePlay == 1){
                          //botão evento 3
                          printf("botao 3\n");
                          if(cidade.dinheiro >= -(vector_de_projetos[2].dinheiro)){
                            aplica_alteracao(&cidade, &vector_de_projetos[2]);
                            goto DESATIVA_TERCEIRO_BOTAO;
                          }
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 163 && evento.mouse.y <= 263 && togglePlay == 1){
                          //botão evento 4
                          printf("botao 4\n");
                          if(cidade.dinheiro >= -(vector_de_projetos[3].dinheiro)){
                            aplica_alteracao(&cidade, &vector_de_projetos[3]);
                            goto DESATIVA_QUARTO_BOTAO;
                          }
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 301 && evento.mouse.y <= 401 && togglePlay == 1){
                          //botão evento 5
                          printf("botao 5\n" );
                          if(cidade.dinheiro >= -(vector_de_projetos[4].dinheiro)){
                            aplica_alteracao(&cidade, &vector_de_projetos[4]);
                            goto DESATIVA_QUINTO_BOTAO;
                          }
                }else if (evento.mouse.x >= 693 && evento.mouse.x <= 893 &&
                          evento.mouse.y >= 439 && evento.mouse.y <= 539 && togglePlay == 1){
                          //botão evento 6
                          printf("botao 6\n" );
                          if(cidade.dinheiro >= -(vector_de_projetos[5].dinheiro)){
                            aplica_alteracao(&cidade, &vector_de_projetos[5]);
                            goto DESATIVA_SEXTO_BOTAO;
                          }
                }else if (evento.mouse.x >= 140 && evento.mouse.x <= 200 &&
                          evento.mouse.y >= 558 && evento.mouse.y <= 578){
                          //botão de VOLTAR
                          printf("botao 7\n" );
                          budgetScreen();
                }
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

                }else if(evento.mouse.x >= 965 && evento.mouse.x <= 976 &&
                    evento.mouse.y >= 17 && evento.mouse.y <= 40){
                // botão de home
                        backSave = 4;
                        saveScreen(backSave);
                        al_stop_timer(contador);
                }else if(evento.mouse.x >= 830 && evento.mouse.x <= 840 &&
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 1){
                    // botao em play
                
                        togglePlay = 0;
                        pauseText = "PLAY";                          
                        pauseBtnImage = playBtnImage;
                        toggleSound = 0;
                        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                        al_set_audio_stream_playing(musica, true);
                        al_stop_timer(contador);
                                                
                
                }else if (evento.mouse.x >= 830 && evento.mouse.x <= 840 && 
                    evento.mouse.y >= 25 && evento.mouse.y <= 35 && togglePlay == 0){
                    // botao pausado
                
                        togglePlay = 1;
                        pauseText = "PAUSAR";                        
                        pauseBtnImage = pauseBackup;
                        toggleSound = 1;
                        al_set_audio_stream_playing(musica, false);
                        al_start_timer(contador);
                        
                
                }
            }
        }if(toggleSound == 1){
                soundBtnImage = soundBackup;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
        }else if(toggleSound == 0){
                soundBtnImage = muteBtnImage;
                al_set_audio_stream_playing(musica, false);
        }else if(togglePlay == 1){
                pauseText = "PLAY";                          
                pauseBtnImage = playBtnImage;
                toggleSound = 0;
                al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
                al_set_audio_stream_playing(musica, true);
                al_stop_timer(contador);
        }else if(togglePlay == 0){
                pauseText = "PAUSAR";                        
                pauseBtnImage = pauseBackup;
                toggleSound = 1;
                al_set_audio_stream_playing(musica, false);
                al_start_timer(contador);
        }    

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));
        
        // Cabeçalho
        al_draw_bitmap(homeBtn, 965, 20, 0);
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
        al_draw_filled_rectangle(390, 152, 633+30, 255, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(390, 290, 633+30, 393, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(390, 428, 633+30, 532, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 152, 923+30, 255, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 290, 923+30, 393, al_map_rgb(60, 60, 59));
        al_draw_filled_rectangle(680, 428, 923+30, 532, al_map_rgb(60, 60, 59));
        
        if(cidade.dinheiro >= -(vector_de_projetos[0].dinheiro) && 
           vector_de_projetos[0].dinheiro != 0){
            al_draw_bitmap(investir, 495, 226, 0);    
        }
        else{
            DESATIVA_PRIMERO_BOTAO:
                al_draw_bitmap(compraNaoDisponivel, 495, 226, 0);
        }

        if(cidade.dinheiro >= -(vector_de_projetos[1].dinheiro) && 
           vector_de_projetos[1].dinheiro != 0){
            al_draw_bitmap(investir, 495, 364, 0);    
        }
        else{
            DESATIVA_SEGUNDO_BOTAO:
                al_draw_bitmap(compraNaoDisponivel, 495, 364, 0);
        }

        if(cidade.dinheiro >= -(vector_de_projetos[2].dinheiro) && 
           vector_de_projetos[2].dinheiro != 0){
            al_draw_bitmap(investir, 495, 502, 0);    
        }
        else{
            DESATIVA_TERCEIRO_BOTAO:
                al_draw_bitmap(compraNaoDisponivel, 495, 502, 0);
        }

        if(cidade.dinheiro >= -(vector_de_projetos[3].dinheiro) && 
           vector_de_projetos[3].dinheiro != 0){
            al_draw_bitmap(investir, 780, 226, 0);   
        }
        else{
            DESATIVA_QUARTO_BOTAO:
                al_draw_bitmap(compraNaoDisponivel, 780, 226, 0);
        }

        if(cidade.dinheiro >= -(vector_de_projetos[4].dinheiro) && 
           vector_de_projetos[4].dinheiro != 0){
            al_draw_bitmap(investir, 780, 364, 0);    
        }
        else{
            DESATIVA_QUINTO_BOTAO:
                al_draw_bitmap(compraNaoDisponivel, 780, 364, 0);
        }

        if(cidade.dinheiro >= -(vector_de_projetos[5].dinheiro) && 
           vector_de_projetos[5].dinheiro != 0){
            al_draw_bitmap(investir, 780, 502, 0);    
        }
        else{
            DESATIVA_SEXTO_BOTAO:
                al_draw_bitmap(compraNaoDisponivel, 780, 502, 0);
        }

        al_draw_bitmap(eventBtn, 405, 163, 0);
        al_draw_bitmap(eventBtn, 405, 301, 0);
        al_draw_bitmap(eventBtn, 405, 439, 0);
        al_draw_bitmap(eventBtn, 693, 163, 0);
        al_draw_bitmap(eventBtn, 693, 301, 0);
        al_draw_bitmap(eventBtn, 693, 439, 0);
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 493, 167, 0, "%s", *vector_de_projetos[0].nome);
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 493, 306, 0, "%s", *vector_de_projetos[1].nome);
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 493, 447, 0, "%s", *vector_de_projetos[2].nome);
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 780, 167, 0, "%s", *vector_de_projetos[3].nome);
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 780, 306, 0, "%s", *vector_de_projetos[4].nome);
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 780, 447, 0, "%s", *vector_de_projetos[5].nome);
        
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 542-45, 167+20, 0, "R$ %d", -(vector_de_projetos[0].dinheiro));
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 542-45, 306+20, 0, "R$ %d", -(vector_de_projetos[1].dinheiro));
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 542-45, 447+20, 0, "R$ %d", -(vector_de_projetos[2].dinheiro));
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 813-30, 167+20, 0, "R$ %d", -(vector_de_projetos[3].dinheiro));
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 812-30, 306+20, 0, "R$ %d", -(vector_de_projetos[4].dinheiro));
        al_draw_textf(dozeBoldPx, al_map_rgb(255, 255, 255), 812-30, 447+20, 0, "R$ %d", -(vector_de_projetos[5].dinheiro));
        
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 378, 0, "EDUCACÃO");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 411, 0, "SAÚDE");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 444, 0, "SEGURANCA");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 477, 0, "LAZER");
        al_draw_textf(quatorzeBoldPx, al_map_rgb(255, 255, 255), 140, 510, 0, "SANEAMENTO");
        
        colorValidation(cidade.educacao, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 378, 0, "%d%%", cidade.educacao);
        colorValidation(cidade.saude, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 411, 0, "%d%%", cidade.saude);
        colorValidation(cidade.seguranca, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 444, 0, "%d%%", cidade.seguranca);
        colorValidation(cidade.lazer, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 477, 0, "%d%%", cidade.lazer);
        colorValidation(cidade.saneamento, &r, &g, &b);
        al_draw_textf(quatorzeBoldPx, al_map_rgb(r, g, b), 323, 510, 0, "%d%%", cidade.saneamento);
        
        int n = 337;
        for (int i = 0; i < 6; i++){
            al_draw_filled_rectangle(140, (n+=1), 350, (n+=32), al_map_rgb(255, 255, 255));        
        }
        al_draw_bitmap(voltar, 140, 568, 0);
        al_draw_bitmap(money, 135, 325, 0);
        al_draw_textf(dezesseisPx, al_map_rgb(104, 94, 35), 165, 330, 0, "R$ %d", cidade.dinheiro);
        al_draw_textf(onzePx, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
    }

    destroyall();

    return 0;
}

// tela caso o jogador perca
int loserScreen(){

    printf("FUNÇÃO loserScreen---------------------------------------\n");

    globalDeclarations();
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador); 
    min = 0;
    seg = 3;
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
            if(seg == 0){
                min =5;
                seg = 0;
                mainScreen();
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
    }    
        al_clear_to_color(al_map_rgb(0, 0, 0));
        
        al_draw_bitmap(taboaoLogoImageloser,  460, 200, 0);
        al_draw_text(trintaQuatroBoldPx, al_map_rgb(190,22,34),  (1024/2), 400, ALLEGRO_ALIGN_CENTRE, "VOCÊ É UM PÉSSIMO PREFEITO!");

        al_flip_display();
    }

    destroyall();

    /*al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);*/
 
    return 0;
}

// tela caso o jogador ganha
int winnerScreen(){

    printf("FUNÇÃO winnerScreen---------------------------------------\n");

    globalDeclarations();
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    al_register_event_source(fila_contador, al_get_timer_event_source(contador));

    al_start_timer(contador); 
    min = 0;
    seg = 3;

    taboaoLogoImage = al_load_bitmap("Images/winnerScreen/winner-btn.png");
    fila_eventos = al_create_event_queue();
    if (!taboaoLogoImage || !fila_eventos ) {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem 1.\n");
        al_destroy_display(janela);
        return -1;
    }

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
            if(seg == 0){
                mainScreen();
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
    }    
        al_clear_to_color(al_map_rgb(0, 0, 0));
        
        al_draw_bitmap(taboaoLogoImage,  460, 200, 0);
        al_draw_text(trintaQuatroBoldPx, al_map_rgb(190,22,34),  (1024/2), 400, ALLEGRO_ALIGN_CENTRE, "VOCÊ É UM PÉSSIMO PREFEITO!");

        al_flip_display();
    }

    destroyall();

    /*al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);*/
 
    return 0;
}

// tela de INSTRUÇÕES
int helpScreen(){

    printf("FUNÇÃO helpScreen---------------------------------------\n");

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
            sair == 1;
        }
        if (tem_eventos && evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            printf("%d\n", backSave);
            if (backHelpCredit == 1){
                mainScreen();
            }
            else{
                saveScreen();
            }
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

    destroyall();

    /*al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);*/
 
    return 0;
}

//tela de CRÉDITOS
int creditScreen(){

    printf("FUNÇÃO creditScreen---------------------------------------\n");
    
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
            printf("%d\n", backSave);
            if (backHelpCredit == 1){
                mainScreen();
            }
            else{
                saveScreen();
            }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        //al_draw_bitmap(teste, 100, 0, 0);
        al_draw_bitmap(creditTaboao, 645, 130, 0);
        al_draw_bitmap(allegroLogo, 140, 375, 0);
        al_draw_bitmap(senacLogo, 150, 480, 0);
        al_draw_text(dozeBoldPx, al_map_rgb(255, 255, 255), 399, 66, 0, "Caio Luzano");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 93, 0, "Caio, conhecido como Menino Caio.");
        al_draw_text(dozeBoldPx, al_map_rgb(255, 255, 255), 399, 126, 0, "Daniel Moniz");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 153, 0, "Daniel, conhecido por ter um grupo");
        al_draw_text(dozeBoldPx, al_map_rgb(255, 255, 255), 399, 190, 0, "Henrique Shodi");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 217, 0, "Herinque, conhecido como Shodi");
        al_draw_text(dozeBoldPx, al_map_rgb(255, 255, 255), 399, 246, 0, "Luiz Frederico");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 273, 0, "Luiz, conhecido como Fred");
        al_draw_text(dozeBoldPx, al_map_rgb(255, 255, 255), 399, 312, 0, "Matheus Souzas");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 339, 0, "Matheus, conhecido como menino sim, não e não sei");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 395, 0, "Gostariamos de agradecer a todos os programadores envolvidos neste projeto e lembra-los que sem");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 410, 0, "eles nada disso seria possível. Também a todos os outros alunos do BCC que nos motivaram diaria-");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 425, 0, "mente com ideias e criticas que foram de suma importancia para continualidade do projeto.");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 440, 0, "À todos os professores do curso e um agradecimento em especial ao Rafael Toledo, do blog do Rafael");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 455, 0, "Toledo, que foi nosso grande mentor no decorrer desse projeto. E claro, impossível não agradecer aos");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 470, 0, "desenvolvedores que criaram a bliblioteca allegro e a linguagem C, sem eles nada disso seria possível.");
        al_draw_text(dozePx, al_map_rgb(255, 255, 255), 399, 505, 0, "Atenciosamente,");
        al_draw_text(dozeBoldPx, al_map_rgb(255, 255, 255), 399, 528, 0, "DEUSES DO SENAC");


        
        al_flip_display();
    }

    destroyall();

    /*
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);*/
 
    return 0;
}

int destroyall(){

    printf("FUNÇÃO destroyall---------------------------------------\n");

    al_destroy_bitmap(taboaoLogoImage);
    al_destroy_bitmap(taboaoMiniLogoImage);
    al_destroy_bitmap(taboaoLogoImageloser);
    al_destroy_bitmap(instrucaoBtnImage);
    al_destroy_bitmap(creditBtnImage);
    al_destroy_bitmap(jogarBtnImage);
    al_destroy_bitmap(facilBtnImage);
    al_destroy_bitmap(medioBtnImage);
    al_destroy_bitmap(dificilBtnImage);
    al_destroy_bitmap(botao_sair);
    al_destroy_bitmap(firstPersonaImage);
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_bitmap(thirdPersonaImage);
    al_destroy_bitmap(fundo);
    al_destroy_bitmap(pauseBtnImage);
    al_destroy_bitmap(voltar);
    al_destroy_bitmap(clockBtnImage);
    al_destroy_bitmap(soundBtnImage);
    al_destroy_bitmap(muteBtnImage);
    al_destroy_bitmap(soundBackup);
    al_destroy_bitmap(pauseBackup);
    al_destroy_bitmap(playBtnImage);
    al_destroy_bitmap(money);
    al_destroy_bitmap(garbage);
    al_destroy_bitmap(education);
    al_destroy_bitmap(educacao);
    al_destroy_bitmap(fun);
    al_destroy_bitmap(lazer);
    al_destroy_bitmap(health);
    al_destroy_bitmap(saude);
    al_destroy_bitmap(sanitation);
    al_destroy_bitmap(saneamento);
    al_destroy_bitmap(security);
    al_destroy_bitmap(seguranca);
    al_destroy_bitmap(majorImage);
    al_destroy_bitmap(investiment);
    al_destroy_bitmap(cautionBtn);
    al_destroy_bitmap(cautionIcon);
    al_destroy_bitmap(quietBtn);
    al_destroy_bitmap(investir);
    al_destroy_bitmap(quietIcon);
    al_destroy_bitmap(blackBack);
    al_destroy_bitmap(compraNaoDisponivel);

    al_destroy_font(onzePx);
    al_destroy_font(quatorzeBoldPx);
    al_destroy_font(quinzePx);
    al_destroy_font(dezesseisPx);
    al_destroy_font(dezoitoPx);
    al_destroy_font(vinteDoisPx);
    al_destroy_font(vinteQuatroPx);
    al_destroy_font(trintaDoisPx);
    al_destroy_font(trintaQuatroBoldPx);
    al_destroy_font(trintaOitopx);

    al_destroy_audio_stream(musica);
    al_destroy_timer(contador);
    //al_destroy_event(evento);
    //al_destroy_timeout(timeout);

    al_destroy_event_queue(fila_contador);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);


    return 0;

}