ALLEGRO_MONITOR_INFO info;

    int res_x_comp, res_y_comp;
    al_get_monitor_info(0, &info);

    res_x_comp = info.x2 - info.x1;
    res_y_comp = info.y2 - info.y2;
 	
 	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    janela = al_create_display(res_x_comp, res_y_comp);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    float red_x = res_x_comp / (float) LARGURA_TELA;
    float red_y = res_y_comp / (float) ALTURA_TELA;

    ALLEGRO_TRANSFORM transformar;
    al_identity_transform(&transformar);
    al_scale_transform(&transformar, red_x, red_y);
    al_use_transform(&transformar);