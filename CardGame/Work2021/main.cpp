#include "graphics.h"
#include "defines.h"
#include <string>
#include "game.h"
#include "main.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    graphics::MouseState mouse;
    graphics::getMouseState(mouse);
    game->update();
    

}

// The window content drawing function.
void draw()
{
    Game* game = reinterpret_cast<Game*>(graphics::getUserData());
    game->draw();
    


}

int main()
{
    Game mygame;
    graphics::createWindow(1200, 800, "The fear smells good");
    
    graphics::setUserData(&mygame);
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
    mygame.init();
    mygame.init2();
    
       
       
    
    if (mygame.restart == true)
        mygame.~Game();
    
    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    graphics::setFont(std::string(ASSET_PATH) + "flexi.ttf");


    
    graphics::startMessageLoop();
    

    return 0;
}