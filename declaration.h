#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

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