#pragma once
#include <raylib.h>
#include "laser.hpp"
#include "gameobject.hpp"
#include "tiro.hpp"
#include <vector>

class carro : public GameObject {
public:
    carro();
    ~carro();
    void Draw() override;
    void MovLeft();
    void MovRight();
    void MovUp();
    void MovDown();
    void FireLaser();
    Rectangle getRect();
    void Reset();
    std::vector<Tiro> tiros;
    bool isShooting = false;
    float shootTime = 0.0f;
    carro& operator+=(int valor_adicional);
    carro& operator-=(int valor_adicional);
    carro& operator=(float valor);
    bool operator>(const carro &outro) const;
    bool operator<(const carro &outro) const;
    bool operator==(const carro &outro) const;
    float operator-(const carro &outro) const;
    float operator+(const carro &outro) const;
    Texture2D image;
    double lastFireTime;
    int pontos;
    bool invencivel;
};
