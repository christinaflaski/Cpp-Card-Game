#include "game.h"
#include "graphics.h"
#include "defines.h"
#include "cards.h"
#include <string>

void Game::drawScreen(int i)
{
    graphics::Brush br;
    br.outline_opacity = 0.0f;
    if (i == 0)
    {
        br.texture = std::string(ASSET_PATH) + ("1table.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
    }
    else if (i == 1)
    {
        br.texture = std::string(ASSET_PATH) + ("2table.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    }
    else if (i == 2)
    {
        br.texture = std::string(ASSET_PATH) + ("3table.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    }

    if (status == STATUS_ROUND)
    {
        br.texture = std::string(ASSET_PATH) + ("round.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

    }
    else if (status == STATUS_WIN)
    {
        br.texture = std::string(ASSET_PATH) + ("ending.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
        for (auto player : m_players)
        {
            if (winner_for_screen == 1)
            {
                br.texture = std::string(ASSET_PATH) + ("Boss_Hades2.png");
                graphics::drawRect(15.0f, 10.50f, PLAYER_SIZE + 1.0f, PLAYER_SIZE, br);

            }
            else if (winner_for_screen == 2)
            {
               br.texture = std::string(ASSET_PATH) + ("Elemental_Titan_Ignis2.png");
                graphics::drawRect(15.0f,10.50f, PLAYER_SIZE + 1.0f, PLAYER_SIZE, br);

            }
        }


    }
    else if (status == STATUS_START)
    {
        br.texture = std::string(ASSET_PATH) + ("main.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
        br.texture = std::string(ASSET_PATH) + ("Boss_Hades2.png");
        graphics::drawRect(5.0f, 5.0f, PLAYER_SIZE + 1.0f, PLAYER_SIZE, br);
        br.texture = std::string(ASSET_PATH) + ("Elemental_Titan_Ignis2.png");
        graphics::drawRect(24.0f, 13.0f, PLAYER_SIZE+1.0f, PLAYER_SIZE, br);

    }
    else if (status == STATUS_MENU)
    {
        br.texture = std::string(ASSET_PATH) + ("main.png");
        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
    }

    

}


void Game::drawStartScreen()
{
    round = 0;
    graphics::Brush br2;
    br2.outline_opacity = 0.0f;

    drawScreen(70);
    SETCOLOR(br2.fill_color, 1.0f, 1.0f, 1.0f);

    
    
    graphics::drawText(9.0f, 2.0f, 1, "The Fear smells good", br2);
    graphics::drawText(11.0f, 5.0f, 0.7f, "3 GAME MODES", br2);
    graphics::drawText(11.0f, 6.0f, 0.5f, "1-> 100hp, Press 1", br2);
    graphics::drawText(11.0f, 7.0f, 0.5f, "2-> 200hp, Press 2", br2);
    graphics::drawText(11.0f, 8.0f, 0.5f, "3-> 500hp, Press 3", br2);
    graphics::drawText(10.50f, 10.0f, 0.5f, "Press Tab to read the rules", br2);
    graphics::drawText(8.50f, 15.0f, 0.7f, "Any time Press Esc to exit the game", br2);
    
    
    
    graphics::drawText(9.0f, 17.0f, 0.5f, "Copyrights 2021. Dimitris' and Christina's Game", br2);
    


}

void Game::draw() 
{
    if (status == STATUS_START)
    {
        drawStartScreen();
    }
    else if(status==STATUS_PLAYING)
    {
        drawLevelScreen();
    }
    else if(status==STATUS_MENU)
    {
        drawMenu();
    }
    else if(status==STATUS_ATTACK)
    {

        drawAfterAttack(red);
    }
    else if(status==STATUS_WIN)
    {
        drawWinner();
        
        
    }
    else
    {
        drawRound();
    }
    
    
}

void Game::drawMenu()
{
    round = 0;
    graphics::Brush br;
   
    br.outline_opacity = 0.0f;
    
    SETCOLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
    

    drawScreen(70);


    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 15.0f, 1, "Game rules:", br);
    
    char info[102];


    SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
    
    sprintf_s(info, "-2 Players fight, drawing one of three cards each round");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 14.0f, 0.5f, info, br);
    sprintf_s(info, "-The first card increases your Damage and reduces your Health points");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 13.0f, 0.5f, info, br);
    sprintf_s(info, "-The second card increases your Health Points but reduces your Armor");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 12.0f, 0.5f, info, br);
    
    sprintf_s(info, "-The third card increases your Armor but reduces your Damage");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 11.0f, 0.5f, info, br);

    sprintf_s(info, "-Your armor can only be reduced if you already have Armor, same thing with the damage!");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 10.0f, 0.5f, info, br);      
  
    sprintf_s(info, "-Each Player starts at same Health points and with 0 Damage and Armor");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 9.0f, 0.5f, info, br);

    sprintf_s(info, "-You choose the Health points of the players before the game begins");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 8.0f, 0.5f, info, br);

    sprintf_s(info, "-The game can go up to 3 rounds, as for a player to win needs 2 winning rounds");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 7.0f, 0.5f, info, br);
    
    sprintf_s(info, "-Each round concludes once one of the Players has 0 Health points");
    graphics::drawText(CANVAS_WIDTH - 28.0f, CANVAS_HEIGHT - 6.0f, 0.5f, info, br);
    

    SETCOLOR(br.fill_color, 1.0f, 0.0f, 0.0f);


    sprintf_s(info, "Good luck, Hope you have fun!");
    graphics::drawText(CANVAS_WIDTH - 20.0f, CANVAS_HEIGHT - 4.0f, 0.7f, info, br);

    graphics::drawText(CANVAS_WIDTH - 24.0f, CANVAS_HEIGHT - 2.0f, 1, "Press SPACE to return to the Home Screen!", br);
    graphics::drawText(CANVAS_WIDTH - 18.0f, CANVAS_HEIGHT - 0.5f, 0.7f, "Press Esc to EXIT!", br);
}

void Game::drawAfterAttack(int red)
{
    drawScreen(round);

    float posx{}, posy{};
    for (auto player : m_players)
    {
        player->draw();
        if (player->getPosition() == red) {
            posx = player->getPosX();
            posy = player->getPosY();
        }

    }
    graphics::Brush br;
    

    SETCOLOR(br.fill_color, 1.0f, 0.0f, 0.0f);
    if (red == 1)
    {
        br.texture = std::string(ASSET_PATH) + ("Elemental_Titan Ignis.png");
    }
    else if(red==2)
    {
        br.texture = std::string(ASSET_PATH) + ("Boss_Hades.png");
    }
    br.outline_opacity = 0.0f;
    graphics::drawRect(posx, posy, PLAYER_SIZE + 1.0f, PLAYER_SIZE, br);
}



void Game::drawWinner()
{
    

    graphics::Brush br;

    br.outline_opacity = 0.0f;


   
    std::string s = std::to_string(winner);
    std::string r = std::to_string(round);
    if (round <= 3)
    {
        drawScreen(round);
        graphics::drawText(CANVAS_WIDTH - 18.0f, CANVAS_HEIGHT - 16.0f, 2, "GAME OVER", br);
        graphics::drawText(CANVAS_WIDTH - 16.0f, CANVAS_HEIGHT - 13.0f, 1, "PLAYER" + s + " WON", br);

        graphics::drawText(CANVAS_WIDTH - 27.0f, CANVAS_HEIGHT - 15.0f, 0.5f, "Press enter to visit start menu", br);
        graphics::drawText(CANVAS_WIDTH - 27.0f, CANVAS_HEIGHT - 14.0f, 0.5f, "Press esc to exit", br);
        graphics::drawText(CANVAS_WIDTH - 18.0f, CANVAS_HEIGHT - 3.0f, 1, "We hope you had fun!", br);
    }
    

    for (auto player : m_players)
    {
        player->setAttack(0);
        player->setDefence(0);
        player->setLifepoint(lp);
    }
    
    restart = true;
        
    win_1st_round = 0;
    win_2nd_round = 0;
    score_1st_player = 0;
    score_2nd_player = 0;
}


void Game::drawLevelScreen()
{
    drawScreen(round);

    for (auto player : m_players)
    {
        
        player->draw();

    }
    
    graphics::Brush br;

    for (auto player : m_players)
    {
        
        for (auto cards : m_cards)
        {
            
            if (player == m_active_player && m_active_player != nullptr) {
                int posx = m_active_player->getPosX();
                int posy = m_active_player->getPosY();
                
                cards->setNegative(cards->changenegative(cards, cur_player->getAttack(), cur_player->getDefence(), cur_player->getLifepoints()));
                cards->draw();
                
                
                SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
                if (m_active_player->getPosition() == 1) {
                    graphics::drawText(posx , posy - 4.50f, 0.5f, "You are playing... ", br);
                }
                else if (m_active_player->getPosition() == 2) {
                    graphics::drawText(posx -3.0f, posy - 4.50f, 0.5f, "You are playing... ", br);
                }
               
            }


        }
        
    }

    SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
    graphics::drawText(10, 0.8f, 1, "Let the battle begin", br);
    
    
    
    graphics::drawText(13, 2.0f, 1,  std::to_string(score_1st_player) + "-" + std::to_string(score_2nd_player), br);

}


void Game::drawRound()
{
    graphics::Brush br;

    br.outline_opacity = 0.0f;

    drawScreen(round);

    std::string r = std::to_string(round);
    std::string rw = std::to_string(round_winner);
    graphics::drawText(CANVAS_WIDTH - 18.0f, CANVAS_HEIGHT - 16.0f, 1, "Round " + r + " is over!", br);
    graphics::drawText(CANVAS_WIDTH - 21.0f, CANVAS_HEIGHT - 14.0f, 1, "Winner of this round: PLAYER " + rw ,br);
    
    graphics::drawText(CANVAS_WIDTH - 27.0f, CANVAS_HEIGHT - 11.0f, 0.5f, "Press ENTER for the next round " , br);
    graphics::drawText(CANVAS_WIDTH - 27.0f, CANVAS_HEIGHT - 10.0f, 0.5f, "Press ESC to exit  " + rw, br);

    for (auto player : m_players)
    {
        player->setAttack(0);
        player->setDefence(0);
        player->setLifepoint(lp);
    }
    restart = true;
    
}


void Game::updateStartScreen()
{
    if (graphics::getKeyState(graphics::SCANCODE_1))
    {
        lp = 100;
        status = STATUS_PLAYING;
    }
    else if (graphics::getKeyState(graphics::SCANCODE_2))
    {
        lp = 200;
        status = STATUS_PLAYING;
    }
    else if (graphics::getKeyState(graphics::SCANCODE_3))
    {
        lp = 500;
        status = STATUS_PLAYING;
    }
    else if (graphics::getKeyState(graphics::SCANCODE_TAB))
    {
        status = STATUS_MENU;
    }

    for (auto player : m_players)
    {
        player->setLifepoint(lp);
    }
}

void Game::updateMenu()
{
    if (graphics::getKeyState(graphics::SCANCODE_SPACE))
        status = STATUS_START;
}



void Game::update() {
    if (status == STATUS_START)
    {
        
        updateStartScreen();
    }
    else if(status==STATUS_PLAYING)
    {
        
        updateLevelScreen();
       
    }
    else if(status==STATUS_MENU)
    {
        updateMenu();
    }
    else if(status==STATUS_ATTACK)
    {
        updateAfterAttack();

    }
    else if(status==STATUS_WIN)
    {
        updateWinner();
    }
    else
    {
        updateRound();
    }
    
}


void Game::updateAfterAttack()
{
    
    if (graphics::getDeltaTime()>8)
    {
        status = STATUS_PLAYING;
    }

}

void Game::updateWinner()
{
    
    if (graphics::getKeyState(graphics::SCANCODE_RETURN))
        status = STATUS_START;
    
    
}

void Game::updateRound()
{
    if (graphics::getKeyState(graphics::SCANCODE_RETURN))
        status = STATUS_PLAYING;

}



void Game::updateLevelScreen()
{
    graphics::MouseState ms;
    graphics::getMouseState(ms);

    float mx = graphics::windowToCanvasX(ms.cur_pos_x);
    float my = graphics::windowToCanvasY(ms.cur_pos_y);
    
    if (turns == 0) {
        for (auto player : m_players)
        {
            if (player->contains(mx, my))
            {
                player->setHighlight(true);
                cur_player = player;


            }
            else {
                player->setHighlight(false);
            }

        }
        if (ms.button_left_pressed && cur_player)
        {
            m_active_player = cur_player;

            for (auto player : m_players)
            {
                for (auto cards : m_cards)
                {
                    cards->setActiveCard(false);
                    
                }

            }

        }
    }
    else {
        for (auto player : m_players) 
        {
            if (cur_player) 
            {
                m_active_player = cur_player;
            }
        }
        if (cur_player) {
            m_active_player->setActive(true);
            for (auto player : m_players)
            {
                for (auto cards : m_cards)
                {
                    cards->setActiveCard(false);
                    
                }

            }
        }
    }

    Cards* cur_card = nullptr;



    for (auto cards : m_cards)
    {
        if (cards->contains(mx, my))
        {
            cards->setHighlightCard(true);
            cur_card = cards;
        }
        else
            cards->setHighlightCard(false);
    }
    
    if (ms.button_left_pressed && cur_card)
    {
        m_active_card = cur_card;
        m_active_card->setActiveCard(true);
        m_active_player->addstatistics(m_active_card->getPositive(), m_active_card->getNegative(),m_active_card->getPosition());

        for (auto player : m_players)
        {
            if (player != m_active_player)
            {
                player->attacking(player, m_active_player->getAttack());
                red = player->getPosition();
                if (m_active_player->getAttack() > 0)
                {
                    status = STATUS_ATTACK;
                        
                }
                
            }
        }

        for (auto player : m_players)
        {
            if (player->getLifepoints() <= 0)
            {
                round++;
                if (round == 3)
                {
                    status = STATUS_WIN;
                    winner = player->getPosition();
                    winner_for_screen = winner;


                }
                else if (round == 2)
                {
                    status = STATUS_ROUND;
                    winner = player->getPosition();
                    round_winner = player->getPosition();
                    win_2nd_round = player->getPosition();
                    if (win_2nd_round == 1)
                    {
                        score_1st_player = score_1st_player + 1;
                    }
                    else if (win_2nd_round == 2)
                    {
                        score_2nd_player = score_2nd_player + 1;
                    }
                }
                else if (round==1)
                {
                    status = STATUS_ROUND;
                    round_winner = player->getPosition();
                    win_1st_round = player->getPosition();
                    if (win_1st_round == 1)
                    {
                        score_1st_player = score_1st_player + 1;
                    }
                    else if (win_1st_round == 2 )
                    {
                        score_2nd_player = score_2nd_player + 1;
                    }
                    
                }

                
                if (win_1st_round == win_2nd_round && win_1st_round != 0)
                {
                    status = STATUS_WIN;
                    winner = player->getPosition();
                    winner_for_screen = winner;
                }

            }
        }

        for (auto cards : m_cards)
        {
            if (cards != m_active_card) {
                cards->setActiveCard(false);
                for(auto player: m_players)
                {
                    if (player != m_active_player) {
                        cur_player = player;
                    }
                    player->setActive(false);
                }
            }
        }
        turns++;

       
        
        
        for (auto c : m_cards)
        {
            delete c;
        }
        m_cards.clear();

        Game::init2();
       
    }
    
    

        


    
}

void Game::init()
{

    status = STATUS_START;
    for (int i = 0; i < 2; i++)
    {
        Player* p = new Player(CANVAS_WIDTH * (i + 0.5f) / 2.0f, 8.0f, i);
        m_players.push_front(p);

    }
    
    
    graphics::playMusic(ASSET_PATH + std::string("Of_Far_Different_Nature_-_Flow_CC-BY.ogg"), 0.1f, true, 0);
      
}
void Game::init2()
{
    for (int i = 0; i < 3; i++)
    {
        Cards* c = new Cards((CANVAS_WIDTH * (i + 0.80f) / 3.30f) - 3.0f, 15.50f, i + 1);
        m_cards.push_front(c);    

    }

}

Game::~Game()
{
    
    for (auto p : m_players)
    {
        delete p;
    }
    m_players.clear();
    
}


Game::Game()
{


}



Game* Game::m_instance = nullptr;