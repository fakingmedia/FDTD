#include "Grid.h"
#include "macro.h"

void Grid::serial() {

    for (time = 0; time < maxTime; time++) {
        updateH();
        updateE();

        //高斯源 Ex((sizeX - 1) / 2, sizeY / 2, sizeZ / 2) += 1;

        abc();
        snapshot3d();
    }

}

void Grid::parallelCPU() {

}

void Grid::parallelGPU() {

}