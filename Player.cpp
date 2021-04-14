#include "Player.h"

Player::Player() : mPlayer(){
    mPlayer.setFillColor(Color::White);
    mPlayer.setSize(Vector2f(20,100));
}

Player::~Player() {

}

void Player::displayPos(int x, int y) {
    mPlayer.setPosition(x, y);
}

RectangleShape Player::Draw(Player& p) {
    return p.mPlayer;
}

void Player::keyInput(Keyboard::Key key, Keyboard::Key up, Keyboard::Key down, bool isPressed) {
    if(key == up)
        PressedUp = isPressed;
    if(key == down)
        PressedDown = isPressed;
}

void Player::movePlayer(Player& p) {
    p.y = 0;
    if(p.PressedUp && p.mPlayer.getPosition().y > 10)
        p.y = -0.4f;
    if(p.PressedDown && p.mPlayer.getPosition().y < 490)
        p.y = 0.4f;
    p.mPlayer.move(0,p.y);
}