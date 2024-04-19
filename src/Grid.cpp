#include "Grid.h"
#include "macro.h"
#include "alloc.h"
#include <cmath>

Grid::Grid(int type) {
    imp0 = 376.730313461;
    int mm, nn, pp;

    if (type == 3) {
        sizeX = 32;
        sizeY = 31;
        sizeZ = 31;
        maxTime = 300;
        cdtds = 1.0 / sqrt(3.0);

        ALLOC_3D(hx, sizeX, sizeY - 1, sizeZ - 1);
        ALLOC_3D(chxh, sizeX, sizeY - 1, sizeZ - 1);
        ALLOC_3D(chxe, sizeX, sizeY - 1, sizeZ - 1);

        ALLOC_3D(hy, sizeX - 1, sizeY, sizeZ - 1);
        ALLOC_3D(chyh, sizeX - 1, sizeY, sizeZ - 1);
        ALLOC_3D(chye, sizeX - 1, sizeY, sizeZ - 1);

        ALLOC_3D(hz, sizeX - 1, sizeY - 1, sizeZ);
        ALLOC_3D(chzh, sizeX - 1, sizeY - 1, sizeZ);
        ALLOC_3D(chze, sizeX - 1, sizeY - 1, sizeZ);

        ALLOC_3D(ex, sizeX - 1, sizeY, sizeZ);
        ALLOC_3D(cexe, sizeX - 1, sizeY, sizeZ);
        ALLOC_3D(cexh, sizeX - 1, sizeY, sizeZ);

        ALLOC_3D(ey, sizeX, sizeY - 1, sizeZ);
        ALLOC_3D(ceye, sizeX, sizeY - 1, sizeZ);
        ALLOC_3D(ceyh, sizeX, sizeY - 1, sizeZ);

        ALLOC_3D(ez, sizeX, sizeY, sizeZ - 1);
        ALLOC_3D(ceze, sizeX, sizeY, sizeZ - 1);
        ALLOC_3D(cezh, sizeX, sizeY, sizeZ - 1);

        for (mm = 0; mm < sizeX - 1; mm++)
            for (nn = 0; nn < sizeY; nn++)
                for (pp = 0; pp < sizeZ; pp++) {
                    Cexe(mm, nn, pp) = 1.0;
                    Cexh(mm, nn, pp) = cdtds * imp0;
                }

        for (mm = 0; mm < sizeX; mm++)
            for (nn = 0; nn < sizeY - 1; nn++)
                for (pp = 0; pp < sizeZ; pp++) {
                    Ceye(mm, nn, pp) = 1.0;
                    Ceyh(mm, nn, pp) = cdtds * imp0;
                }

        for (mm = 0; mm < sizeX; mm++)
            for (nn = 0; nn < sizeY; nn++)
                for (pp = 0; pp < sizeZ - 1; pp++) {
                    Ceze(mm, nn, pp) = 1.0;
                    Cezh(mm, nn, pp) = cdtds * imp0;
                }

        for (mm = 0; mm < sizeX; mm++)
            for (nn = 0; nn < sizeY - 1; nn++)
                for (pp = 0; pp < sizeZ - 1; pp++) {
                    Chxh(mm, nn, pp) = 1.0;
                    Chxe(mm, nn, pp) = cdtds / imp0;
                }

        for (mm = 0; mm < sizeX - 1; mm++)
            for (nn = 0; nn < sizeY; nn++)
                for (pp = 0; pp < sizeZ - 1; pp++) {
                    Chyh(mm, nn, pp) = 1.0;
                    Chye(mm, nn, pp) = cdtds / imp0;
                }

        for (mm = 0; mm < sizeX - 1; mm++)
            for (nn = 0; nn < sizeY - 1; nn++)
                for (pp = 0; pp < sizeZ; pp++) {
                    Chzh(mm, nn, pp) = 1.0;
                    Chze(mm, nn, pp) = cdtds / imp0;
                }
    }
}

Grid::~Grid() {
    delete[] hx;
    delete[] chxh;
    delete[] chxe;
    delete[] hy;
    delete[] chyh;
    delete[] chye;
    delete[] hz;
    delete[] chzh;
    delete[] chze;
    delete[] ex;
    delete[] cexh;
    delete[] cexe;
    delete[] ey;
    delete[] ceyh;
    delete[] ceye;
    delete[] ez;
    delete[] cezh;
    delete[] ceze;
}