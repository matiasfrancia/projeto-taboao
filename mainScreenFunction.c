// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
 
// Para utilizarmos o fprintf
#include <stdio.h>

void imagem(){
    ALLEGRO_DISPLAY *janela = NULL;

    fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
    al_destroy_display(janela);
}

// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;
 
int main(void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *taboaoLogoImage = NULL;
    ALLEGRO_BITMAP *instrucaoBtnImage = NULL;
    ALLEGRO_BITMAP *configBtnImage = NULL;
    ALLEGRO_BITMAP *creditBtnImage = NULL;
    ALLEGRO_BITMAP *jogarBtnImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *firstText = NULL;
    ALLEGRO_BITMAP *botao_sair = NULL;
    int botao = 0;
    int sair = 0;

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

    // Torna apto o uso de mouse na aplicação
    if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    taboaoLogoImage = al_load_bitmap("Images/globalImages/taboaoMiniLogoImage.png");
    if (!taboaoLogoImage)
    {
        imagem();
        return -1;
    }
    jogarBtnImage = al_load_bitmap("xpto/mainImages/jogar-botao.png");
    if (!jogarBtnImage){
        imagem();
        //fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        //al_destroy_display(janela);
        return -1;
    }instrucaoBtnImage = al_load_bitmap("Images/mainImages/instrucoes-botao.png");
    if (!instrucaoBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    configBtnImage = al_load_bitmap("Images/mainImages/configuracoes-botao.png");
    if (!configBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    creditBtnImage = al_load_bitmap("Images/mainImages/creditos-botao.png");
    if (!creditBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }
    
    firstText = al_load_ttf_font("Font/arial.ttf", 32,0 );
 
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    
    //al_draw_text(firstText, al_map_rgb(29, 113, 189), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "PROJETO TABOÃO");
    //al_draw_bitmap(taboaoLogoImage, 420, 200, 0);
    //al_draw_bitmap(jogarBtnImage, 400, 450, 0);
    //al_draw_bitmap(configBtnImage, 400, 550, 0);
    //al_draw_bitmap(instrucaoBtnImage, 400, 500, 0);
    //al_draw_bitmap(creditBtnImage, 400, 600, 0);
 
    al_flip_display();
 
    while (!sair){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
        
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                evento.mouse.y >= 450 && evento.mouse.y <= 485){
                sair = 1;
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                      evento.mouse.y >= 500 && evento.mouse.y <= 535){
                      sair = 1;
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                      evento.mouse.y >= 550 && evento.mouse.y <= 585){
                      sair = 1;
            }else if (evento.mouse.x >= 400 && evento.mouse.x <= 630 &&
                      evento.mouse.y >= 600 && evento.mouse.y <= 635){
                      sair = 1;
            }
        }
        
 
        al_draw_text(firstText, al_map_rgb(29, 113, 189), (1024/2), 100, ALLEGRO_ALIGN_CENTRE, "PROJETO TABOÃO");
        al_draw_bitmap(taboaoLogoImage, 420, 200, 0);
        al_draw_bitmap(jogarBtnImage, 400, 450, 0);
        al_draw_bitmap(instrucaoBtnImage, 400, 500, 0);
        al_draw_bitmap(configBtnImage, 400, 550, 0);
        al_draw_bitmap(creditBtnImage, 400, 600, 0);
        
        al_flip_display();
    }

    al_destroy_bitmap(botao_sair);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}