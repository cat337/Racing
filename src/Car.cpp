#include "Car.h"

const int num = 8; //checkpoints

int points[num][2] = { 300, 610,
                      1270,430,
                      1380,2380,
                      1900,2460,
                      1970,1700,
                      2550,1680,
                      2560,3150,
                      500, 3300 };

void Car::move()
{
    x += sin(angle) * speed;
    y -= cos(angle) * speed;
}

void Car::findTarget()
{
    float tx = points[n][0];
    float ty = points[n][1];
    float beta = angle - atan2(tx - x, -ty + y);
    if (sin(beta) < 0)
        angle += 0.005 * speed;
    else
        angle -= 0.005 * speed;
    if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25) // Pythagoras theorem formula sqrt(x^2 + y^2)
        n = (n + 1) % num;
}

void Car::reset()
{
    x = 0; y = 0; speed = 2; angle = 0; n = 0;
}