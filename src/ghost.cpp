// === ghost.cpp ===
#include "../include/juego.h"

Ghost::Ghost() {
    texture.loadFromFile("assets/images/ghost.png");
    sprite.setTexture(texture);
    float escala = (32.0f * 0.8f) / texture.getSize().x;
    sprite.setScale(escala, escala);
    sprite.setOrigin(0, 0);
    sprite.setPosition(13 * 32, 9 * 32);
    speed = 32.0f / 8.0f;
}

void Ghost::move(int dx, int dy, int mapa[15][20], int tileSize) {
    float nextX = sprite.getPosition().x + dx * getVelocidad();
    float nextY = sprite.getPosition().y + dy * getVelocidad();
    int fila = nextY / tileSize;
    int col = nextX / tileSize;

    if (fila >= 0 && fila < 15 && col >= 0 && col < 20 && mapa[fila][col] == 0)
        sprite.move(dx * getVelocidad(), dy * getVelocidad());
}

void Ghost::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Ghost::getBounds() const {
    return sprite.getGlobalBounds();
}

sf::Vector2f Ghost::getPosition() const {
    return sprite.getPosition();
}

void Ghost::sumarPunto() {
    puntos++;
}

void Ghost::agregarVida() {
    vidas++;
}

void Ghost::activarVelocidad() {
    velocidadExtra = true;
    velocidadTimer.restart();
}

void Ghost::actualizarVelocidad() {
    if (velocidadExtra && velocidadTimer.getElapsedTime().asSeconds() > 5)
        velocidadExtra = false;
}

int Ghost::getPuntos() const {
    return puntos;
}

int Ghost::getVidas() const {
    return vidas;
}

float Ghost::getVelocidad() const {
    return velocidadExtra ? speed * 2.0f : speed;
}
