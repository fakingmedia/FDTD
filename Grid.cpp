#include "Grid.h"
#include "alloc.h"
#include <cmath>




Grid::Grid(int type) {
    imp0 = 376.730313461;
    sizeX = 32;
    sizeY = 31;
    sizeZ = 31;
    maxTime = 300;
    cdtds = 1.0 / sqrt(3.0);

    ALLOC_3D(hx, sizeX, sizeY - 1, sizeZ - 1);



}

Grid::~Grid() {

}