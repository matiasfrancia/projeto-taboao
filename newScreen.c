// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
 
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
  
int main(void){

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *taboaoLogoImage = NULL;
    ALLEGRO_BITMAP *firstPersonaImage = NULL;
    ALLEGRO_BITMAP *secondPersonaImage = NULL;
    ALLEGRO_BITMAP *thirdPersonaImage = NULL;
    ALLEGRO_BITMAP *fundo = NULL;
    ALLEGRO_BITMAP *pauseBtnImage = NULL;
    ALLEGRO_BITMAP *soundBtnImage = NULL;
    ALLEGRO_BITMAP *muteBtnImage = NULL;
    ALLEGRO_BITMAP *soundBackup = NULL;
    ALLEGRO_BITMAP *clockBtnImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
    ALLEGRO_FONT *firstText = NULL;
    ALLEGRO_FONT *secondText = NULL;
    ALLEGRO_FONT *nametext = NULL;
    ALLEGRO_TIMER *contador = 0;
    ALLEGRO_FONT *fonte = NULL;
	int sair = 0;
    int r = 0, g = 0, b = 0;
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
    thirdPersonaImage = al_load_bitmap("Images/chooseImages/thirdPersonaImage.png");
    pauseBtnImage = al_load_bitmap("Images/chooseImages/pauseBtnImage.png");
    muteBtnImage = al_load_bitmap("Images/globalImages/mute-btn.png");
    clockBtnImage = al_load_bitmap("Images/globalImages/clockBtnImage.png");
    soundBtnImage = al_load_bitmap("Images/globalImages/sound-btn.png");
    soundBackup = al_load_bitmap("Images/globalImages/sound-btn.png");
    fonte = al_load_font("Font/arial.ttf", 11,00);
    contador = al_create_timer(1.0);
    fila_contador = al_create_event_queue();
    fila_eventos = al_create_event_queue();
    
    if (!taboaoLogoImage || !firstPersonaImage || !secondPersonaImage || !thirdPersonaImage ||
        !pauseBtnImage || !clockBtnImage || !soundBtnImage || !al_install_mouse() || !muteBtnImage ||
        !al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT) || !fonte ||
        !contador || !fila_contador || !fila_eventos){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    
    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 22,0 );
    nametext = al_load_ttf_font("Font/Arial_Bold.ttf", 24,0 );
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

    char *majorName; 
    char *majorDesc; 
    char *majorMoney; 
    int educacaoInd; 
    int saudeInd; 
    int segurancaInd; 
    int saneamentoInd; 
    int lazerInd; 
    /*majorName = "Escolha o seu Prefeito(a)";
    majorDesc = NULL;
    educacaoInd = 046; 
    saudeInd = 046; 
    segurancaInd = 046; 
    saneamentoInd = 046; 
    lazerInd = 046;*/ 

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
            int value;
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
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && value == 0){
                        value = 1;
                        soundBtnImage = muteBtnImage;
                }else if (evento.mouse.x >= 900 && evento.mouse.x <= 920 &&
                    evento.mouse.y >= 20 && evento.mouse.y <= 35 && value == 1){
                        value = 0;
                        soundBtnImage = soundBackup;
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
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 240, 515, ALLEGRO_ALIGN_RIGHT, "ATRIBUTOS DO(A) CANDIDATO(A)");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 240, 545, ALLEGRO_ALIGN_RIGHT, majorName);
        al_draw_text(nametext, al_map_rgb(255, 255, 255), 240, 575, ALLEGRO_ALIGN_RIGHT, majorMoney);
        al_draw_filled_rectangle(400, 525, 401, 665, al_map_rgb(255, 255, 255));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 390, 530, ALLEGRO_ALIGN_RIGHT, "EDUCAÇÃO");
        al_draw_filled_rectangle(400, 525, educacaoInd, 545, al_map_rgb(255, 255, 255));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 390, 560, ALLEGRO_ALIGN_RIGHT, "SAÚDE");
        al_draw_filled_rectangle(400, 555, saudeInd, 575, al_map_rgb(255, 255, 255));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 390, 590, ALLEGRO_ALIGN_RIGHT, "SEGURANÇA");
        al_draw_filled_rectangle(400, 585, segurancaInd, 605, al_map_rgb(255, 255, 255));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 390, 620, ALLEGRO_ALIGN_RIGHT, "SANEAMENTO");
        al_draw_filled_rectangle(400, 615, saneamentoInd, 635, al_map_rgb(255, 255, 255));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 390, 650, ALLEGRO_ALIGN_RIGHT, "LAZER");
        al_draw_filled_rectangle(400, 645, lazerInd, 665, al_map_rgb(255, 255, 255));
        al_draw_textf(fonte, al_map_rgb(255, 255, 255), 795, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
    }
    al_destroy_bitmap(secondPersonaImage);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);
 
    return 0;
}