//
// Created by NZ on 2024/3/30.
//

#include "serialFdtd.h"

serialFdtd::serialFdtd() {

    eta = deltaT * c * sqrt(1/pow(deltaL, 2) + 1/pow(deltaL, 2) + 1/pow(deltaL, 2));

    n = 0;
}

bool serialFdtd::isStable() {
    return eta <= 1;
}



void serialFdtd::updateE() {
    for (int i = 0; i < numX; i++)
        for (int j = 0; j < numY; j++)
            for (int k = 0; k < numZ; k++) {
                ExPrev = Ex;
                EyPrev = Ey;
                EzPrev = Ez;

                Ex = ExPrev + ;
            }
}

void serialFdtd::updateH() {

}

void serialFdtd::show() {

}