#include "Game.h"

Game::Game() : wGame(VideoMode(900, 600), "Ping-pong!"){

}

Game::~Game() {

}

void Game::run() {
    while (wGame.isOpen()) {
        processEvent();
        update();
        render();
    }
    
}

void Game::processEvent() {
    Event e;
    while (wGame.pollEvent(e)) {

        switch (e.type) {
        case Event::Closed:
            wGame.close();
            break;
        }

    }
    
}

void Game::update() {

}

void Game::render() {
    wGame.clear(Color::Black);
    wGame.draw(Player::Draw(p1));
    wGame.draw(Player::Draw(p2));
    wGame.display();
}