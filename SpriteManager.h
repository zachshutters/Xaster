/* 
 * File:   SpriteManager.h
 * Author: zach
 *
 * Created on March 7, 2009, 8:56 PM
 */

#ifndef _SPRITEMANAGER_H
#define	_SPRITEMANAGER_H
#include <vector>
#include <SDL/SDL.h>

class Sprite;

class SpriteManager {
public:
    static SpriteManager* INSTANCE();
    void update();
    void generateAsteroidWave();
    void addProjectile(Sprite* s);
    void addObstacle(Sprite* s);
    void render(SDL_Surface* screen);
    void checkForCollisions();
private:
    static SpriteManager* SINGLETON;
    SpriteManager();
    SpriteManager(const SpriteManager&);
    SpriteManager& operator=(const SpriteManager&);
    int randomFromRange(int lowest, int highest);
    std::vector<Sprite*> obstacles;
    std::vector<Sprite*> projectiles;
};

#endif	/* _SPRITEMANAGER_H */

