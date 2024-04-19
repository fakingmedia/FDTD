#include "macro.h"
#include "alloc.h"



void Grid::abcInit() {
    abcoef = (cdtds - 1.0) / (cdtds + 1.0);

    ALLOC_2D(eyx0, sizeY - 1, sizeZ)
    ALLOC_2D(ezx0, sizeY, sizeZ - 1);
    ALLOC_2D(eyx1, sizeY - 1, sizeZ);
    ALLOC_2D(ezx1, sizeY, sizeZ - 1);

    ALLOC_2D(exy0, sizeX - 1, sizeZ);
    ALLOC_2D(ezy0, sizeX, sizeZ - 1);
    ALLOC_2D(exy1, sizeX - 1, sizeZ);
    ALLOC_2D(ezy1, sizeX, sizeZ - 1);

    ALLOC_2D(exz0, sizeX - 1, sizeY);
    ALLOC_2D(eyz0, sizeX, sizeY - 1);
    ALLOC_2D(exz1, sizeX - 1, sizeY);
    ALLOC_2D(eyz1, sizeX, sizeY - 1);
}

void Grid::abcDelete() {
    delete[] eyx0;
    delete[] ezx0;
    delete[] eyx1;
    delete[] ezx1;
    delete[] exy0;
    delete[] ezy0;
    delete[] exy1;
    delete[] ezy1;
    delete[] exz0;
    delete[] eyz0;
    delete[] exz1;
    delete[] eyz1;
}

void Grid::abc() {
    int mm, nn, pp;

    if (abcoef == 0.0) {
        std::cerr << "abc: abcInit must be called before abc. Terminating..." << std::endl;
    }

    //x0处的ABC
    mm = 0;
    for (nn = 0; nn < sizeY - 1; nn++)
        for (pp = 0; pp < sizeZ; pp++) {
            Ey(mm, nn, pp) = Eyx0(nn, pp) + abcoef * (Ey(mm + 1, nn, pp) - Ey(mm, nn, pp));
            Eyx0(nn, pp) = Ey(mm + 1, nn, pp);
        }
    for (nn = 0; nn < sizeY; nn++)
        for (pp = 0; pp < sizeZ - 1; pp++) {
            Ez(mm, nn, pp) = Ezx0(nn, pp) + abcoef * (Ez(mm + 1, nn, pp) - Ez(mm, nn, pp));
            Ezx0(nn, pp) = Ez(mm + 1, nn, pp);
        }

    //x1处的ABC
    mm = sizeX - 1;
    for (nn = 0; nn < sizeY - 1; nn++)
        for (pp = 0; pp < sizeZ; pp++) {
            Ey(mm, nn, pp) = Eyx1(nn, pp) + abcoef * (Ey(mm - 1, nn, pp) - Ey(mm, nn, pp));
            Eyx1(nn, pp) = Ey(mm - 1, nn, pp);
        }
    for (nn = 0; nn < sizeY; nn++)
        for (pp = 0; pp < sizeZ - 1; pp++) {
            Ez(mm, nn, pp) = Ezx1(nn, pp) + abcoef * (Ez(mm - 1, nn, pp) - Ez(mm, nn, pp));
            Ezx1(nn, pp) = Ez(mm - 1, nn, pp);
        }

    //y0处的ABC
    nn = 0;
    for (mm = 0; mm < sizeX - 1; mm++)
        for (pp = 0; pp < sizeZ; pp++) {
            Ex(mm, nn, pp) = Exy0(mm, pp) + abcoef * (Ex(mm, nn + 1, pp) - Ex(mm, nn, pp));
            Exy0(mm, pp) = Ex(mm, nn + 1, pp);
        }
    for (mm = 0; mm < sizeX; mm++)
        for (pp = 0; pp < sizeZ - 1; pp++) {
            Ez(mm, nn, pp) = Ezy0(mm, pp) + abcoef * (Ez(mm, nn + 1, pp) - Ez(mm, nn, pp));
            Ezy0(mm, pp) = Ez(mm, nn + 1, pp);
        }

    //y1处的ABC
    nn = sizeY - 1;
    for (mm = 0; mm < sizeX - 1; mm++)
        for (pp = 0; pp < sizeZ; pp++) {
            Ex(mm, nn, pp) = Exy1(mm, pp) + abcoef * (Ex(mm, nn - 1, pp) - Ex(mm, nn, pp));
            Exy1(mm, pp) = Ex(mm, nn - 1, pp);
        }
    for (mm = 0; mm < sizeX; mm++)
        for (pp = 0; pp < sizeZ - 1; pp++) {
            Ez(mm, nn, pp) = Ezy1(mm, pp) + abcoef * (Ez(mm, nn - 1, pp) - Ez(mm, nn, pp));
            Ezy1(mm, pp) = Ez(mm, nn - 1, pp);
        }

    //z0处的ABC
    pp = 0;
    for (mm = 0; mm < sizeX - 1; mm++)
        for (nn = 0; nn < sizeY; nn++) {
            Ex(mm, nn, pp) = Exz0(mm, nn) + abcoef * (Ex(mm, nn, pp + 1) - Ex(mm, nn, pp));
            Exz0(mm, nn) = Ex(mm, nn, pp + 1);
        }
    for (mm = 0; mm < sizeX; mm++)
        for (nn = 0; nn < sizeY - 1; nn++) {
            Ey(mm, nn, pp) = Eyz0(mm, nn) + abcoef * (Ey(mm, nn, pp + 1) - Ey(mm, nn, pp));
            Eyz0(nn, pp) = Ey(mm, nn, pp + 1);
        }

    //z1处的ABC
    pp = sizeZ - 1;
    for (mm = 0; mm < sizeX - 1; mm++)
        for (nn = 0; nn < sizeY; nn++) {
            Ex(mm, nn, pp) = Exz1(mm, nn) + abcoef * (Ex(mm, nn, pp - 1) - Ex(mm, nn, pp));
            Exz1(mm, nn) = Ex(mm, nn, pp - 1);
        }
    for (mm = 0; mm < sizeX; mm++)
        for (nn = 0; nn < sizeY - 1; nn++) {
            Ey(mm, nn, pp) = Eyz1(mm, nn) + abcoef * (Ey(mm, nn, pp - 1) - Ey(mm, nn, pp));
            Eyz1(nn, pp) = Ey(mm, nn, pp - 1);
        }

}