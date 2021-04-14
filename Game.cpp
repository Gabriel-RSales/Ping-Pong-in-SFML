#include "Game.h"

Game::Game() : wGame(VideoMode(900, 600), "Ping-pong!"){

}

Game::~Game() {

}

void Game::run() {
    setInicialPosEntity(p1, p2, b);

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
            case sf::Event::KeyPressed:
                p1.keyInput(e.key.code, Keyboard::W, Keyboard::S, true);
                p2.keyInput(e.key.code, Keyboard::Up, Keyboard::Down, true);
                break;

            case sf::Event::KeyReleased:
                p1.keyInput(e.key.code, Keyboard::W, Keyboard::S, false);
                p2.keyInput(e.key.code, Keyboard::Up, Keyboard::Down, false);
                break;

            case Event::Closed:
                wGame.close();
                break;
        }

    }
    
}

void Game::update() {

    updateCollisionWindow(wGame, b);

    updateCollisionShapes(p1, b);
    updateCollisionShapes(p2, b);
    MarkPoint(p1, p2, b);

    Player::movePlayer(p1);
    Player::movePlayer(p2);
    b.MoveBall();
}

void Game::render() {
    wGame.clear(Color::Black);
    wGame.draw(Player::Draw(p1));
    wGame.draw(Player::Draw(p2));
    wGame.draw(Ball::Draw(b));
    wGame.display();
}