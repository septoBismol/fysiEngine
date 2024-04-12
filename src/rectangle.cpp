#include "../include/axisrectangle.h"
#include "../include/utilities.h"
#include <cmath>

axisrectangle::axisrectangle(int x, int y, float dir, float vel){
    this->dir = dir;
    this->vel = vel;
    this->x = x;
    this->y = y;
    this->width = 50;
    this->height = 50;
    this->rect.x = this->x;
    this->rect.y = this->y;
    this->rect.w = this->width;
    this->rect.h = this->height;
    
}
bool axisrectangle::checkCollision(axisrectangle colObj){
    if ((this->x+this->width >= colObj.x || this->x <= colObj.x+colObj.width)&&(this->y <= colObj.y+colObj.height|| this->y+this->height >= colObj.y)){
        return true;
    }
    return false;
}
void axisrectangle::reposition(int x, int y){
    this->x = x;
    this->y = y;
}
void axisrectangle::stepMovement(){
    float base = ceil(sin(degreesToRadians(dir)) * vel);
    float height = ceil(cos(degreesToRadians(dir)) * vel);
    this->x += base;
    this->y += height;
    this->rect.x = this->x;
    this->rect.y = this->y;
}