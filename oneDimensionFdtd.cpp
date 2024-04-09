//
// Created by MATEBOOK on 2024/4/9.
//

#include "oneDimensionFdtd.h"

using namespace std;

oneDimensionFdtd::oneDimensionFdtd() {
    pi = 3.14159265358979323846264338327950288419716939937510;
    epsilon0 = 8.854187817e-12;
    mju0 = 4 * pi / 1e7;
    c = 1 / sqrt(epsilon0 * mju0);
    eta0 = sqrt(mju0 / epsilon0);

    epsilonR = 1;
    mjuR = 1;

    //courant1 = c * deltaT / deltaX;
    courant1 = 1;

    maxTime = 1000;
    size = 200;

    ez.resize(size, 0.);
    hy.resize(size, 0.);
}

void oneDimensionFdtd::updateE() {
    for(int i = 1; i < size; i++)
        ez[i] = ez[i] + courant1 / mjuR * (hy[i] - hy[i - 1]) / eta0;
}

void oneDimensionFdtd::updateH() {
    for(int i = 0; i < size - 1; i++)
        hy[i] = hy[i] + courant1 / epsilonR * (ez[i + 1] - ez[i]) * eta0;
}

void oneDimensionFdtd::iteration() {
    for (int i = 0; i < maxTime; i++) {
        updateE();
        updateH();
        ez[0] = exp(-(i - 30.) * (i - 30.) / 100.);
        cout << i << "  ";
        cout << ez[50] << endl;
    }
}