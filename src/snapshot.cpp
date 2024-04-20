#include "Grid.h"
#include "macro.h"

#include <fstream>

void Grid::snapshot(int temporalStride, int time) {
    int mm, nn, pp;

    std::ofstream f;

    if (time % temporalStride == 0) {
        f.open("D:\\FDTD\\data\\sim." + std::to_string(time));

        mm = (sizeX - 1) / 2;
        for (pp = sizeZ - 1; pp >= 0; pp--)
            for (nn = 0; nn < sizeY; nn++) {
                float temp = (float)Ex(mm, nn, pp);
                f << temp << std::endl;
            }

        f.close();
    }
}