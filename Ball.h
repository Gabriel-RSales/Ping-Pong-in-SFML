#ifndef BALL_H
#define BALL_H

#include <SFML\Graphics.hpp>
using namespace sf;

class Ball {
private:
    CircleShape mBall;
    Vector2f Pos;
    Vector2f MovePos = Vector2f(0.3f,0.01f);
public:
    Ball();
    virtual ~Ball();

    void displayPos(Vector2f Pos);
    static CircleShape Draw(Ball& b);
    void MoveBall();
    friend class Config;
};


#endif /* BALL_H */