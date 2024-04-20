#ifndef FDTD_GRID_H
#define FDTD_GRID_H

enum GRIDTYPE {oneGrid, teZGrid, tmZGrid, threeGrid};

class Grid {
private:
    double imp0;

    int type;//维度的标志

    int maxTime;

    double *hx, *chxh, *chxe;
    double *hy, *chyh, *chye;
    double *hz, *chzh, *chze;
    double *ex, *cexh, *cexe;
    double *ey, *ceyh, *ceye;
    double *ez, *cezh, *ceze;

    double cdtds;

    int sizeX, sizeY, sizeZ;

    //abc
    double abcoef;
    double *exy0, *exy1, *exz0, *exz1, *eyx0, *eyx1, *eyz0, *eyz1, *ezx0, *ezx1, *ezy0, *ezy1;

public:
    Grid(int type);
    ~Grid();

    void snapshot(int temporalStride, int time);

    void updateE();
    void updateH();

    void serial();
    void parallelCPU();
    void parallelGPU();

    void abcInit();
    void abcDelete();
    void abc();

};


#endif //FDTD_GRID_H
