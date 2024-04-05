#ifndef AXISRECTANGLE_H
#define AXISRECTANGLE_H
#include "object.h"
#include "circle.h"
class axisrectangle : public object{
public:
    bool checkCollision(axisrectangle colObj);
    bool checkCollisionCircle(circle colObj);
    int width;
    int height;
private:
    SDL_Rect* rect;
};

#endif