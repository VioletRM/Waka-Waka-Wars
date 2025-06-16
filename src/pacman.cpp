// === pacman.cpp ===
#include "../include/juego.h"

Pacman::Pacman() {
    texture.loadFromFile("assets/images/Pacman.png");
    sprite.setTexture(texture);
    float escala = (32.0f * 0.8f) / texture.getSize().x;
    sprite.setScale(escala, escala);
    sprite.setOrigin(0, 0);
    sprite.setPosition(1 * 32, 1 * 32);
    speed = 32.0f / 8.0f;
}

void Pacman::move(int dx, int dy, int mapa[15][20], int tileSize) {
    float nextX = sprite.getPosition().x + dx * getVelocidad();
    float nextY = sprite.getPosition().y + dy * getVelocidad();
    int fila = nextY / tileSize;
    int col = nextX / tileSize;

    if (fila >= 0 && fila < 15 && col >= 0 && col < 20 && mapa[fila][col] == 0)
        sprite.move(dx * getVelocidad(), dy * getVelocidad());

    if (animClock.getElapsedTime().asMilliseconds() > 150) {
        frame = (frame + 1) % 2;
        animClock.restart();
    }

    if (dx == -1) sprite.setRotation(180);
    else if (dx == 1) sprite.setRotation(0);
    else if (dy == -1) sprite.setRotation(270);
    else if (dy == 1) sprite.setRotation(90);
}

void Pacman::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Pacman::getBounds() const {
    return sprite.getGlobalBounds();
}

sf::Vector2f Pacman::getPosition() const {
    return sprite.getPosition();
}

void Pacman::sumarPunto() {
    puntos++;
}

void Pacman::agregarVida() {
    vidas++;
}

void Pacman::activarVelocidad() {
    velocidadExtra = true;
    velocidadTimer.restart();
}

void Pacman::actualizarVelocidad() {
    if (velocidadExtra && velocidadTimer.getElapsedTime().asSeconds() > 5)
        velocidadExtra = false;
}

int Pacman::getPuntos() const {
    return puntos;
}

int Pacman::getVidas() const {
    return vidas;
}

float Pacman::getVelocidad() const {
    return velocidadExtra ? speed * 2.0f : speed;
}
