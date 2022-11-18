#pragma once
#include "player.h"
#include "defines.h"
#include <list>
#include "cards.h"
class Game
{
    typedef enum{STATUS_START,STATUS_MENU,STATUS_ATTACK,STATUS_PLAYING,STATUS_WIN,STATUS_ROUND} status_t;
    static Game* m_instance;
    float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT / 2;

    Player* player = nullptr;
    std::list<Player*> m_players;


    Player* m_active_player = nullptr;

    Cards* cards = nullptr;
    std::list<Cards*> m_cards;

    Cards* m_active_card = nullptr;
    status_t status = STATUS_START;
    Player* cur_player = nullptr;
    int red ;
    int winner = 0;
    int turns = 0;
    int round = 0;
    int round_winner = 0;
    int win_1st_round = 0;
    int win_2nd_round = 0;
    int finishpl = 0;
    int finishcard = 1;
    int winner_for_screen = 0;
    int score_1st_player = 0;
    int score_2nd_player=0;
    
   

public:
    
    int lp = 0;
    bool restart = false;
    void drawStartScreen();
    void drawLevelScreen();
    void drawMenu();
    void draw();
    void drawAfterAttack(int red);
    void drawWinner();
    void drawRound();
    void updateStartScreen();
    void updateLevelScreen();
    void updateMenu();
    void update();
    void updateAfterAttack();
    void updateWinner();
    void updateRound();
    void init();
    void init2();
    void drawScreen(int i);
    
    Game();
    ~Game();

    


}
;
