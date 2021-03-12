#include "Player.h"

Player::Player() : mPlayer(){
    mPlayer.setFillColor(Color::White);
    mPlayer.setSize(Vector2f(20,100));
}

Player::~Player() {

}

void Player::displayPos(int x, int y) {
    this->x = x;
    this->y = y;
    mPlayer.setPosition(x, y);
}

RectangleShape Player::Draw(Player& p) {
    return p.mPlayer;
}