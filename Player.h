#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
using namespace sf;

class Player {
private:
    RectangleShape mPlayer;
    float x, y;
public:
    Player();
    virtual ~Player();

    void displayPos(int x, int y);
    static RectangleShape Draw(Player& p);
};

#endif /* PLAYER_H */
