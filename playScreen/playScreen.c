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
    ALLEGRO_BITMAP *taboaoLogoImage = NULL;
    ALLEGRO_BITMAP *firstPersonaImage = NULL;
    ALLEGRO_BITMAP *sencondPersonaImage = NULL;
    ALLEGRO_BITMAP *thirdPersonaImage = NULL;
    ALLEGRO_BITMAP *fundo = NULL;
    ALLEGRO_BITMAP *pauseBtnImage = NULL;
    ALLEGRO_BITMAP *settingsBtnImage = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *pauseBtnText = NULL;
    ALLEGRO_FONT *settingsBtnText = NULL;
 
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

 
    taboaoLogoImage = al_load_bitmap("Images/taboaoLogoImage.png");
    if (!taboaoLogoImage)
    {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem0.\n");
        al_destroy_display(janela);
        return -1;
    }
    firstPersonaImage = al_load_bitmap("Images/firstPersonaImage.png");
    if (!firstPersonaImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem1.\n");
        al_destroy_display(janela);
        return -1;
    }
    sencondPersonaImage = al_load_bitmap("Images/sencondPersonaImage.png");
    if (!sencondPersonaImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem2.\n");
        al_destroy_display(janela);
        return -1;
    }
    thirdPersonaImage = al_load_bitmap("Images/thirdPersonaImage.png");
    if (!thirdPersonaImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem3.\n");
        al_destroy_display(janela);
        return -1;
    }
    fundo = al_load_bitmap("Images/fundoTaboao.png");
    if (!fundo){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem4.\n");
        al_destroy_display(janela);
        return -1;
    }pauseBtnImage = al_load_bitmap("Images/pauseBtnImage.png");
    if (!pauseBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem4.\n");
        al_destroy_display(janela);
        return -1;
    }settingsBtnImage = al_load_bitmap("Images/settingsBtnImage.png");
    if (!settingsBtnImage){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem4.\n");
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
    
    pauseBtnText = al_load_ttf_font("playFonts/arial.ttf", 11,0 );
    settingsBtnText = al_load_ttf_font("playFonts/arial.ttf", 11,0 );
 

    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
    
    //al_draw_bitmap(fundo, 0, 0, 0);
    al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
    al_draw_bitmap(firstPersonaImage, 145, 330, 1);
    al_draw_bitmap(sencondPersonaImage, 415, 330, 0);
    al_draw_bitmap(thirdPersonaImage, 690, 330, 0);
    al_draw_bitmap(pauseBtnImage, 820, 25, 0);
    al_draw_bitmap(settingsBtnImage, 885, 20, 0);
    al_draw_text(pauseBtnText, al_map_rgb(255, 255, 255), 20, 300, 20, "CREDITOS");

             
 
    al_flip_display();
 
    while (1){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
 
        //al_draw_bitmap(fundo, 0, 0, 0);
        al_draw_bitmap(taboaoLogoImage, 325, 170, 0);
        al_draw_bitmap(firstPersonaImage, 145, 330, 1);
        al_draw_bitmap(sencondPersonaImage, 415, 330, 0);
        al_draw_bitmap(thirdPersonaImage, 690, 330, 0);
        al_draw_bitmap(pauseBtnImage, 820, 25, 0);
        al_draw_bitmap(settingsBtnImage, 885, 20, 0);
        al_draw_text(pauseBtnText, al_map_rgb(255, 255, 255), 20, 300, 20, "CREDITOS");

        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}