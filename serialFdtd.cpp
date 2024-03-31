//
// Created by NZ on 2024/3/30.
//

#include "serialFdtd.h"

serialFdtd::serialFdtd() {

}

bool serialFdtd::isStable() {
    return deltaT * c * sqrt(1/pow(deltaX, 2) + 1/pow(deltaY, 2) + 1/pow(deltaZ, 2)) <= 1;
}

void serialFdtd::updateE() {

}

void serialFdtd::updateH() {

}

void serialFdtd::show() {

}