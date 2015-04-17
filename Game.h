/* 
 * File:   Game.h
 * Author: zach
 *
 * Created on March 5, 2009, 1:26 PM
 */

#ifndef _GAME_H
#define	_GAME_H
#include <SDL/SDL.h>
#include <queue>
#include <memory>

class GameState;
class MenuState;
class RunningState;

class Game {
public:
    enum STATE {MENU_STATE, RUNNING_STATE, QUIT_STATE};
    ~Game();
    static Game* INSTANCE();
    void update();
    void render(SDL_Surface* screen);
    void start();
    void setState(STATE state);
    
private:
    const int screen_width;
    const int screen_height;
    const int screen_bpp;
    SDL_Surface* screen;
    SDL_Event event;
    GameState* gameState;
    //MenuState* menuState;
    std::auto_ptr<GameState> menuState;
    RunningState* runningState;
    void setState(GameState* gameState);
    static Game* SINGLETON;
    Game();
    Game(const Game&);
    Game& operator=(const Game&);   
    bool running;
};


#endif	/* _GAME_H */

