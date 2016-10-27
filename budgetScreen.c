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
    ALLEGRO_BITMAP *taboaoLogoImage = NULL;
    ALLEGRO_BITMAP *fundo = NULL;
    ALLEGRO_BITMAP *pauseBtnImage = NULL;
    ALLEGRO_BITMAP *settingsBtnImage = NULL;
    ALLEGRO_BITMAP *atributosBtnImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL, *fila_contador = NULL;
    ALLEGRO_FONT *firstText = NULL;
    ALLEGRO_FONT *secondText = NULL;
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
    if (!taboaoLogoImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }
    pauseBtnImage = al_load_bitmap("Images/playImages/pauseBtnImage.png");
    if (!pauseBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem4.\n");
        al_destroy_display(janela);
        return -1;
    }
    settingsBtnImage = al_load_bitmap("Images/playImages/settingsBtnImage.png");
    if (!settingsBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem4.\n");
        al_destroy_display(janela);
        return -1;
    }
    atributosBtnImage = al_load_bitmap("Images/atributos.png");
    if (!atributosBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem4.\n");
        al_destroy_display(janela);
        return -1;
    }
    if (!al_install_mouse()){
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(janela);
        return -1;
    }
    fonte = al_load_font("Font/arial.ttf", 11,00);
    if (!fonte)
    {
        fprintf(stderr, "Falha ao carregar fonte.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    contador = al_create_timer(1.0);
    if (!contador)
    {
        fprintf(stderr, "Falha ao criar timer.\n");
        al_destroy_font(fonte);
        al_destroy_display(janela);
        return -1;
    }
 
    fila_contador = al_create_event_queue();
    if (!fila_contador)
    {
        fprintf(stderr, "Falha ao criar fila do contador.\n");
        al_destroy_timer(contador);
        al_destroy_font(fonte);
        al_destroy_display(janela);
        return -1;
    }
    fila_eventos = al_create_event_queue();
    if (!fila_eventos){
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }

    firstText = al_load_ttf_font("Font/arial.ttf", 11,0 );
    secondText = al_load_ttf_font("Font/arial.ttf", 24,0 );

    char *majorName; 
    char *majorDesc; 
    int educacaoInd = 401; 
    int saudeInd = 401; 
    int segurancaInd = 401; 
    int saneamentoInd = 401; 
    int lazerInd = 401;   

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
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_set_target_bitmap(al_get_backbuffer(janela));
        
        al_draw_filled_rectangle(100, 140, 900, 490, al_map_rgb(87, 87, 86));
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_bitmap(pauseBtnImage, 815, 25, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 827, 23, 0, "PAUSAR");
        al_draw_bitmap(settingsBtnImage, 885, 22, 0);
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 908, 23, 0, "CONFIGURAÇÕES");
        al_draw_bitmap(atributosBtnImage, 140, 175, 0);
        al_draw_filled_rectangle(320, 10, 720, 55, al_map_rgb(87, 87, 86));
        al_draw_filled_rectangle(25, 10, 250, 55, al_map_rgb(29, 113, 189));
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 15, 0, "OBJETIVO:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), 30, 35, 0, "CONSTRUA UM HOSPITAL");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 15, ALLEGRO_ALIGN_CENTRE, "NEWS:");
        al_draw_text(firstText, al_map_rgb(255, 255, 255), (1024/2), 35, ALLEGRO_ALIGN_CENTRE, "Manifestantes queimam materiais e interditam Régis Bittencourt.");

        // grafico
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

        //relogio
        al_draw_textf(fonte, al_map_rgb(255, 255, 255), 750, 23, ALLEGRO_ALIGN_CENTRE, "%d:%d", min, seg);

        al_flip_display();
        
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_event_queue(fila_contador);

    return 0;

}