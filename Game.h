#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Game {
private:
    RenderWindow wGame;
    Player p1, p2;
private:
    void processEvent();
    void update();
    void render();
public:
    Game();
    virtual ~Game();

    void run();
};

#endif /* GAME_H */
