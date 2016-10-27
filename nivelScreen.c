// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
 
// Para utilizarmos o fprintf
#include <stdio.h>
 
// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;
 
int main(void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *facilBtnImage = NULL;
    ALLEGRO_BITMAP *medioBtnImage = NULL;
    ALLEGRO_BITMAP *dificilBtnImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *firstText = NULL;
    ALLEGRO_FONT *secondText = NULL;
    ALLEGRO_FONT *thirdText = NULL;
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

    facilBtnImage = al_load_bitmap("Images/nivelImages/facilBtnImage.png");
    if (!facilBtnImage)
    {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    medioBtnImage = al_load_bitmap("Images/nivelImages/medioBtnImage.png");
    if (!medioBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }dificilBtnImage = al_load_bitmap("Images/nivelImages/dificilBtnImage.png");
    if (!dificilBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }if (!al_install_mouse())
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
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }
    
    firstText = al_load_ttf_font("Font/arial.ttf", 32,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 18,0 );
    thirdText = al_load_ttf_font("Font/arial.ttf", 24,0 );
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    
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
            if (evento.mouse.x >= 165 && evento.mouse.x <= 352 &&
                evento.mouse.y >= 250 && evento.mouse.y <= 437){
                sair = 1;
            }else if (evento.mouse.x >= 415 && evento.mouse.x <= 595 &&
                      evento.mouse.y >= 250 && evento.mouse.y <= 437){
                      sair = 1;
            }else if (evento.mouse.x >= 665 && evento.mouse.x <= 845 &&
                      evento.mouse.y >= 250 && evento.mouse.y <= 437){
                      sair = 1;
            }else if (evento.mouse.x >= 10 && evento.mouse.x <= 30 &&
                      evento.mouse.y >= 10 && evento.mouse.y <= 30){
                      sair = 1;
            }
        }
 
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