// Os arquivos de cabeçalho
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
 
// Para utilizarmos o fprintf
#include <stdio.h>
 
// Atributos da tela
const int LARGURA_TELA = 1024;
const int ALTURA_TELA = 720;
 
int main(void)
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *imagem = NULL;
    ALLEGRO_BITMAP *iniciar = NULL;
    ALLEGRO_BITMAP *config = NULL;
    ALLEGRO_BITMAP *credito = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
 
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

 
    imagem = al_load_bitmap("mainImages/taboao.png");
    if (!imagem)
    {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    iniciar = al_load_bitmap("mainImages/instrucoes-botao.png");
    if (!iniciar){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    config = al_load_bitmap("mainImages/configuracoes-botao.png");
    if (!config){
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
    credito = al_load_bitmap("mainImages/creditos-botao.png");
    if (!credito){
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
 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_draw_bitmap(imagem, 420, 150, 0);
    al_draw_bitmap(iniciar, 400, 450, 0);
    al_draw_bitmap(config, 400, 500, 0);
    al_draw_bitmap(credito, 400, 550, 0);
 
    al_flip_display();
 
    while (1){
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.5);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
        }
 
        al_draw_bitmap(imagem, 420, 150, 0);
        al_draw_bitmap(iniciar, 400, 450, 0);
        al_draw_bitmap(config, 400, 500, 0);
        al_draw_bitmap(credito, 400, 550, 0);
        al_flip_display();
    }

    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}