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

    maxTime = 450;
    size = 200;

    ez.resize(size, 0.);
    hy.resize(size, 0.);
}

void oneDimensionFdtd::updateE(int time) {
    ez[0] = ez[1];

    for(int i = 1; i < size; i++)
        ez[i] = ez[i] + courant1 / mjuR * (hy[i] - hy[i - 1]) * eta0;

    ez[50] += courant1 / mjuR * exp(-(time + 0.5 -(-0.5) - 30.) * (time + 0.5 -(-0.5) - 30.) / 100.);
}

void oneDimensionFdtd::updateH(int time) {
    hy[size - 1] = hy[size - 2];

    for(int i = 0; i < size - 1; i++)
        hy[i] = hy[i] + courant1 / epsilonR * (ez[i + 1] - ez[i]) / eta0;

    hy[49] -= courant1 / epsilonR * exp(-(time - 30.) * (time - 30.) / 100.) / eta0;
}

void oneDimensionFdtd::dataStore(int time) {
    if (time % 10 == 0) {
        ofstream fs;
        fs.open("D:\\FDTD\\data\\sim." + to_string(time));
        for (int i = 0; i < size; i++)
            fs << ez[i] << endl;
        fs.close();
    }
}

void oneDimensionFdtd::iteration() {
    for (int i = 0; i < maxTime; i++) {
        updateH(i);
        updateE(i);

        dataStore(i);
    }
}