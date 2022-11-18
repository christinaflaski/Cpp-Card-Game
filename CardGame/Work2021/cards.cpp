#include "cards.h"
#include "graphics.h"
#include "defines.h"
#include "gameobject.h"
#include "time.h"
#include "game.h"




void Cards::draw()
{

    graphics::Brush br;



    br.outline_opacity = 0.0f;
    float h = m_highlighted_card * 1.0f;
    

    SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);

    if (position == 1) {
        br.texture = std::string(ASSET_PATH) + ("carddamage.png");
        graphics::drawText(pos_x + 2.50f, pos_y-1.0f, 0.7f, "Fighter card ", br);
        graphics::drawText(pos_x + 2.50f, pos_y - 0.6f, 0.5f, "Damage   +" + std::to_string(positive), br);
        graphics::drawText(pos_x + 2.50f, pos_y - 0.1f, 0.5f, "Life  -" + std::to_string(getNegative()), br);
        setPosition(1);


    }
    else if (position == 2) {
        br.texture = std::string(ASSET_PATH) + ("cardlife.png");
        float h = m_highlighted_card * 1.0f;
        graphics::drawText(pos_x + 2.50f, pos_y-1.0f , 0.7f, "Healer card ", br);
        graphics::drawText(pos_x + 2.50f, pos_y -0.6f , 0.5f, "Life +" + std::to_string(positive), br);
        graphics::drawText(pos_x + 2.50f, pos_y - 0.1f, 0.5f, "Armor -" + std::to_string(negative), br);
        setPosition(2);


    }
    else {
        br.texture = std::string(ASSET_PATH) + ("cardarmor.png");
        float h = m_highlighted_card * 1.0f;
        graphics::drawText(pos_x + 2.50f, pos_y-1.0f, 0.7f, "Soldier card ", br);
        graphics::drawText(pos_x + 2.50f, pos_y - 0.6f, 0.5f, "Armor   +" + std::to_string(positive), br);
        graphics::drawText(pos_x + 2.50f, pos_y - 0.1f, 0.5f, "Damage  -" + std::to_string(negative), br);
        setPosition(3);

    }
    graphics::drawRect(pos_x, pos_y, CARD_SIZE-1.50f , CARD_SIZE, br);


}


int Cards::changepositive()
{
    return(rand() % 9) + 2;

}

int Cards::changenegative(Cards* card, int a, int d, int l)
{


    if (card->getPosition() == 1) {
        while (l - n <= 0 ) {
            n = n - 4;
        }
    }
    else if (card->getPosition() == 2) {
        while (d - n < 0 || n<0) {
            if (d == 0) {
                n = 0;
                break;
            }
        n = n - 3;
            
                

        }
    }
    else if (card->getPosition() == 3) {
        while (a - n < 0 || n<0) {
            if (a == 0) {
                n = 0;
                break;
            }
         
            n = n - 5;

        }
        
    }

    
    return n;
        
}

bool Cards::contains(float x, float y)
{

    return distance(x, y, pos_x, pos_y) < PLAYER_SIZE * 0.3f;


}

Cards::Cards(float x, float y, int i)
{
    pos_x = x;
    pos_y = y;
    position = i;
}

Cards::~Cards()
{
}

;














