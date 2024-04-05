#include "../include/axisrectangle.h"
#include "../include/utilities.h"
bool axisrectangle::checkCollision(axisrectangle colObj){
    if ((this->x+this->width >= colObj.x || this->x <= colObj.x+colObj.width)&&(this->y <= colObj.y+colObj.height|| this->y+this->height >= colObj.y)){
        return true;
    }
    return false;
}
bool axisrectangle::checkCollisionCircle(circle colObj){
    if (distanceCalculator(this->x-colObj.x, this->y-colObj.y) > (this->width/2)+colObj.radius){
        return true;
    }
    return false;
}