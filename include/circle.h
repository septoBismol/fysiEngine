#ifndef CIRCLE_H
#define CIRCLE_H
#include "object.h"
#include "axisrectangle.h"
class circle : public object{
public:
    bool checkCollision(circle colObj);
    bool checkCollisionRect(axisrectangle colObj);
    float radius;
private:
    SDL_Rect* rect;
};

#endif