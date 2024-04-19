#ifndef FDTD_GRID_H
#define FDTD_GRID_H

enum GRIDTYPE {oneGrid, teZGrid, tmZGrid, threeGrid};

class Grid {
private:
    double imp0;

    double *hx, *chxh, *chxe;
    double *hy, *chyh, *chye;
    double *hz, *chzh, *chze;
    double *ex, *cexh, *cexe;
    double *ey, *ceyh, *ceye;
    double *ez, *cezh, *ceze;

    int sizeX, sizeY, sizeZ;
    int time, maxTime;
    int type;
    double cdtds;

public:
    Grid(int type);
    ~Grid();

    void snapshotInit1d();
    void snapshotInit2d();
    void snapshotInit3d();
    void snapshot1d();
    void snapshot2d();
    void snapshot3d();

    void updateE();
    void updateH();

    void serial();
    void parallelCPU();
    void parallelGPU();

};


#endif //FDTD_GRID_H
