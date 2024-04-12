#include "../include/utilities.h"
#include "../include/constants.h"
#include <cmath>
float abs(float num){
    if (num > 0){
        return num;
    } else {
        return num * -1;
    }
}
float distanceCalculator(float base, float height){
    return sqrt(pow(abs(base),2)+ pow(abs(height),2));
}

float degreesToRadians(float x){
    return x / 180 * pi;
}