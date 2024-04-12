#ifndef CIRCLE_H
#define CIRCLE_H
#include "object.h"
#include "axisrectangle.h"
class circle : public object{
public:
    bool checkCollision(circle colObj);
    float radius;
    float dir;
    float vel;
private:
    SDL_Rect* rect;
};

#endif