#include "player.h"
#include "graphics.h"
#include "defines.h"
#include "time.h"

int k = 0;
void Player::draw()
{
    graphics::Brush br;
    graphics::Brush br2;

    SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
        

    if (position == 1) {
        br.texture = std::string(ASSET_PATH) + ("Elemental_Titan Ignis.png");
        graphics::drawText(pos_x + 2.0f, pos_y - 7.0f, 0.5f, "HP:  " + std::to_string(life_points), br);
        graphics::drawText(pos_x + 2.0f, pos_y - 6.5f, 0.5f, "Damage:  " + std::to_string(attack), br);
        graphics::drawText(pos_x + 2.0f, pos_y - 6.0f, 0.5f, "Armor:  " + std::to_string(defence), br);
        k = 1;
        setPosition(1);
    
    }
    else {
        br.texture = std::string(ASSET_PATH) + ("Boss_Hades.png");
        graphics::drawText(pos_x - 6.0f, pos_y - 7.0f, 0.5f, "HP:  " + std::to_string(life_points), br);
        graphics::drawText(pos_x - 6.0f, pos_y - 6.5f, 0.5f, "Damage:  " + std::to_string(attack), br);
        graphics::drawText(pos_x - 6.0f, pos_y - 6.0f, 0.5f, "Armor:  " + std::to_string(defence), br);
        k = 2;
        setPosition(2);
       


    }
    br.outline_opacity = 0.0f;
    graphics::drawRect(pos_x, pos_y, PLAYER_SIZE+1.0f, PLAYER_SIZE, br);
     



}



void Player::addstatistics(int a, int b, int i)
{
    if (i == 1) {
        attack += a;
        life_points -= b;

    }
    else if (i == 2) {
        life_points += a;
        defence -= b;
        

    }
    else if (i == 3) {
        defence += a;
        attack -= b;
    }
}



void Player::attacking(Player * p1, int att)
{   
    if (att>p1->getDefence())
    {
        p1->setLifepoint(p1->getDefence() + p1->getLifepoints() - att);
    }
    
}

bool Player::contains(float x, float y) 
{
    return distance(x, y, pos_x, pos_y) < PLAYER_SIZE * 0.3f;

}

Player::Player(float x, float y, int i)
{
    pos_x = x;
    pos_y = y;
    position = i;

}

Player::~Player()
{
  
};
