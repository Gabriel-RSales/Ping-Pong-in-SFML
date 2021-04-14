#include "Config.h" 
#include <iostream>

Config::Config() {

}

Config::~Config() {

}


void Config::updateCollisionShapes(Player& p, Ball& b) {
    if (CollisionBallInPlayer(p, b)) 
        CollisionReaction(b, true);
}

void Config::updateCollisionWindow(RenderTarget& w, Ball& b) {
    if(CollisionBallInWindow(w, b))
        CollisionReaction(b, false);
}

bool Config::CollisionBallInPlayer(Player& p, Ball& b) {
    return b.mBall.getGlobalBounds().intersects(p.mPlayer.getGlobalBounds());
}

bool Config::CollisionBallInWindow(RenderTarget& w, Ball& b) {
    if(b.mBall.getPosition().y <= 10 || b.mBall.getPosition().y >= w.getSize().y - 10)
        return true;
    else
        return false;
}

void Config::CollisionReaction(Ball& b, bool InPlayer) {
    b.MovePos.y = -b.MovePos.y;
    if(InPlayer) {
        b.MovePos.x = -b.MovePos.x;
        //b.MovePos.y = RANDOM_MIN+float(rand())/float(RAND_MAX/(RANDOM_MAX - RANDOM_MIN));
        b.MovePos.y = 0.1f;
    }
}

void Config::MarkPoint(Player& p1, Player& p2, Ball& b) {
    if(b.mBall.getPosition().x <= p1.mPlayer.getPosition().x) {
        setInicialPosEntity(p1, p2, b);
        MarkedPoint(p1);
    }
    else if(b.mBall.getPosition().x + b.mBall.getRadius() >= p2.mPlayer.getPosition().x + p2.mPlayer.getSize().x) {
        setInicialPosEntity(p1, p2, b);
        MarkedPoint(p2);
    }
}

void Config::setInicialPosEntity(Player& p1, Player& p2, Ball& b) {
    p1.displayPos(10, 250);
    p2.displayPos(870, 250);
    b.displayPos(Vector2f(440,290));
    b.MovePos.y = 0;
}

void Config::MarkedPoint(Player& p) {
    p.score++;
    std::cout<<p.score<<",";
}