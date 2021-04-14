#include "Ball.h"

Ball::Ball() : mBall(){
    mBall.setRadius(10.0f);
    mBall.setFillColor(Color::White);
}

Ball::~Ball() {
    
}

void Ball::displayPos(Vector2f Pos) {
    this->Pos = Pos;
    mBall.setPosition(Pos);
}

CircleShape Ball::Draw(Ball& b) {
    return b.mBall;
}

void Ball::MoveBall() {
    Pos += MovePos;    
    mBall.setPosition(Pos);    
}