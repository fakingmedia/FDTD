#include "Grid.h"
#include "macro.h"
#include "ezinc.h"
#include "omp.h"

void Grid::serial() {
    double begin, end;

    begin = omp_get_wtime();

    for (int time = 0; time < maxTime; time++) {
        updateH();
        updateE();

        Ex((sizeX - 1) / 2, sizeY / 2, sizeZ / 2) += ezInc(cdtds, 1.0, time, 0.0);

        abc();
        snapshot(10, time);
    }

    end = omp_get_wtime();

    std::cout << "Serial time: " << end - begin << "s" << std::endl;

}

void Grid::parallelCPU() {
    double begin, end;

    begin = omp_get_wtime();
#pragma omp parallel
    {
#pragma omp for
        for (int time = 0; time < maxTime; time++) {
            updateH();
            updateE();

            Ex((sizeX - 1) / 2, sizeY / 2, sizeZ / 2) += ezInc(cdtds, 1.0, time, 0.0);

            abc();
            snapshot(10, time);
        }
    }

    end = omp_get_wtime();

    std::cout << "Parallel CPU time: " << end - begin << "s" << std::endl;
}

void Grid::parallelGPU() {

}