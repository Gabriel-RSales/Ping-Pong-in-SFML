#ifndef CONFIG_H
#define CONFIG_H

#include "Ball.h"
#include "Player.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class Config{
private:
    float RANDOM_MAX = 0.3f, RANDOM_MIN = 0.4f;
private:
    bool CollisionBallInPlayer(Player& p, Ball& b);
    bool CollisionBallInWindow(RenderTarget& w, Ball& b);
    void CollisionReaction(Ball& b, bool InPlayer);
    void MarkedPoint(Player& p);
public:
    Config();
    virtual ~Config();

    void updateCollisionShapes(Player& p, Ball& b);
    void updateCollisionWindow(RenderTarget& w, Ball& b);
    void MarkPoint(Player& p1, Player& p2, Ball& b);
    void setInicialPosEntity(Player& p1, Player& p2, Ball& b);
};

#endif /* CONFIG_H */
