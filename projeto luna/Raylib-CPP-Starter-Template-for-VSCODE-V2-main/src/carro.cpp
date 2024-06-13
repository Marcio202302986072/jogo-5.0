#include "carro.hpp"

carro::carro() : GameObject({50, 250}) {
    image = LoadTexture("carro.png");
    lastFireTime = 0.0;
    pontos = 0;
    invencivel = false;
}

carro::~carro() {
    UnloadTexture(image);
}

void carro::Draw() {
    if (invencivel) {
        DrawTextureV(image, position, GREEN); // Desenhar o carro como verde durante a invencibilidade
    } else {
        DrawTextureV(image, position, WHITE); // Desenho padrão em branco
    }

    // Desenhar tiros
    for (auto& t : tiros) {
        t.Draw();
    }
}

void carro::MovLeft() {
    if (position.x > 0) {
        position.x -= 3.5;
    }
}

void carro::MovRight() {
    if (position.x < GetScreenWidth() - 250) {
        position.x += 3.5;
    }
}

void carro::MovUp() {
    if (position.y > 0) {
        position.y -= 3.5;
    }
}

void carro::MovDown() {
    if (position.y < GetScreenHeight() - image.height) {
        position.y += 3.5;
    }
}

void carro::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) {
        tiros.push_back(Tiro({position.x + image.width / 2 - 2, position.y + image.height / 2 + 10}, -6));
        lastFireTime = GetTime();
    }
}

Rectangle carro::getRect() {
    return {position.x, position.y, float(image.width), float(image.height)};
}

void carro::Reset() {
    position.x = 50;
    position.y = 250;
    tiros.clear(); // Limpar os tiros
}

carro& carro::operator+=(int valor_adicional) {
    this->pontos += valor_adicional;
    return *this;
}

carro& carro::operator-=(int valor_adicional) {
    this->pontos -= valor_adicional;
    return *this;
}

carro& carro::operator=(float valor) {
    this->position.x = valor;
    return *this;
}

bool carro::operator>(const carro &outro) const {
    return this->pontos > outro.pontos;
}

bool carro::operator<(const carro &outro) const {
    return this->pontos < outro.pontos;
}

bool carro::operator==(const carro &outro) const {
    return this->pontos == outro.pontos;
}

float carro::operator-(const carro &outro) const {
    return this->pontos - outro.pontos;
}

float carro::operator+(const carro &outro) const {
    return this->pontos + outro.pontos;
}
