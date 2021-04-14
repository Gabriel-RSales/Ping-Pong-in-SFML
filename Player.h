#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Graphics.hpp>
using namespace sf;

class Player {
private:
    RectangleShape mPlayer;
    float y;
    bool PressedUp = false, PressedDown = false;
    int score = 0;
public:
    Player();
    virtual ~Player();

    void displayPos(int x, int y);
    static RectangleShape Draw(Player& p);
    void keyInput(Keyboard::Key key, Keyboard::Key up, Keyboard::Key down, bool isPressed);
    static void movePlayer(Player& p);
    friend class Config;
};

#endif /* PLAYER_H */
