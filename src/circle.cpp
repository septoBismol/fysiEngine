#include "../include/circle.h"
#include "../include/utilities.h"

bool circle::checkCollision(circle colObj){
    if (this->radius + colObj.radius < distanceCalculator(colObj.x-this->x, colObj.y-this->y)){
        return true;
    }
    return false;
}
