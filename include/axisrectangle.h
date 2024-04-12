#ifndef AXISRECTANGLE_H
#define AXISRECTANGLE_H
#include "utilities.h"
#include "object.h"
#include "circle.h"
class axisrectangle : public object{
public:
    axisrectangle(int x, int y, float dir, float vel);
    void reposition(int x, int y);
    void stepMovement();
    bool checkCollision(axisrectangle colObj);
    int width;
    int height;
    SDL_Rect rect;
    float dir;
    float vel;
private:
    
};

#endif