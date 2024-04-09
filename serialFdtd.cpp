//
// Created by NZ on 2024/3/30.
//

#include "serialFdtd.h"

serialFdtd::serialFdtd() {

    eta = deltaT * c * sqrt(1/pow(deltaX, 2) + 1/pow(deltaY, 2) + 1/pow(deltaZ, 2));

    n = 0;
}

bool serialFdtd::isStable() {
    return eta <= 1;
}



void serialFdtd::serialUpdateE() {
    for (int i = 0; i < numX; i++)
        for (int j = 0; j < numY; j++)
            for (int k = 0; k < numZ; k++) {
                ExPrev[i][j][k] = Ex[i][j][k];
                EyPrev[i][j][k] = Ey[i][j][k];
                EzPrev[i][j][k] = Ez[i][j][k];
                Ex[i][j][k] += deltaT/epsilon*((Hz[i][j+1][k]-Hz[i][j][k])/deltaY-(Hy[i][j][k+1]-Hy[i][j][k])/deltaZ);
                Ey[i][j][k] += deltaT/epsilon*((Hx[i][j+1][k]-Hx[i][j][k])/deltaZ-(Hz[i][j][k+1]-Hz[i][j][k])/deltaX);
                Ez[i][j][k] += deltaT/epsilon*((Hy[i][j+1][k]-Hy[i][j][k])/deltaX-(Hx[i][j][k+1]-Hx[i][j][k])/deltaY);
            }
}

void serialFdtd::serialUpdateH() {
    for (int i = 0; i < numX; i++)
        for (int j = 0; j < numY; j++)
            for (int k = 0; k < numZ; k++) {
                HxPrev[i][j][k] = Hx[i][j][k];
                HyPrev[i][j][k] = Hy[i][j][k];
                HzPrev[i][j][k] = Hz[i][j][k];
                Hx[i][j][k] -= deltaT/mju*((Ez[i][j+1][k]-Ez[i][j][k])/deltaY-(Ey[i][j][k+1]-Ey[i][j][k])/deltaZ);
                Hy[i][j][k] -= deltaT/mju*((Ex[i][j+1][k]-Ex[i][j][k])/deltaZ-(Ez[i][j][k+1]-Ez[i][j][k])/deltaX);
                Hz[i][j][k] -= deltaT/mju*((Ey[i][j+1][k]-Ey[i][j][k])/deltaX-(Ex[i][j][k+1]-Ex[i][j][k])/deltaY);
            }
}

void serialFdtd::iteration() {
    if (isStable())
        for (int i; i < maxN; i++) {
            serialUpdateE();
            serialUpdateH();
        }
    else
        cout << "数据不稳定，不允许迭代" << endl;
}

void serialFdtd::show() {

}