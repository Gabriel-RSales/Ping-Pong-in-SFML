#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Ball.h"
#include "Config.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Game : public Config{
private:
    RenderWindow wGame;
    Player p1, p2;
    Ball b;
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
