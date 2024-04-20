#include "Grid.h"
#include "macro.h"
#include "ezinc.h"
#include "omp.h"

void Grid::serial() {
    for (int time = 0; time < maxTime; time++) {
        updateH();
        updateE();

        Ex((sizeX - 1) / 2, sizeY / 2, sizeZ / 2) += ezInc(cdtds, 1.0, time, 0.0);

        abc();
        snapshot(10, time);
    }

}

void Grid::parallelCPU() {

}

void Grid::parallelGPU() {

}