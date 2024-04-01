//
// Created by NZ on 2024/3/30.
//

#ifndef FDTD_SERIALFDTD_H
#define FDTD_SERIALFDTD_H

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class serialFdtd {
protected:
    const double c = 300000000;

    vector<vector<vector<double>>> Ex; //电场强度(t,x,y,z)
    vector<vector<vector<double>>> Ey;
    vector<vector<vector<double>>> Ez;

    vector<vector<vector<double>>> ExPrev; //电场强度(t,x,y,z)
    vector<vector<vector<double>>> EyPrev;
    vector<vector<vector<double>>> EzPrev;

    vector<vector<vector<double>>> Hx; //磁场强度(t,x,y,z)
    vector<vector<vector<double>>> Hy;
    vector<vector<vector<double>>> Hz;

    vector<vector<vector<double>>> HxPrev; //磁场强度(t,x,y,z)
    vector<vector<vector<double>>> HyPrev;
    vector<vector<vector<double>>> HzPrev;

    vector<vector<vector<vector<double>>>> J; //电流密度(t,x,y,z)
    vector<vector<vector<vector<double>>>> M; //磁流密度(t,x,y,z)

    double Vx, Vy, Vz; //仿真空间大小
    int maxN; //迭代次数上限

    double epsilon; //媒介的介电常数
    double mju; //媒介的磁导率
    //double sigmaE; //电导率
    //double sigmaM; //磁导率

    double deltaT; //时间步长
    double deltaX, deltaY, deltaZ; //x,y,z轴上的空间距离

    double Sc; //稳定常数
    double eta; //特性阻抗

    int n; //迭代次数
    int numX, numY, numZ; //x, y, z轴的检测点数量

public:
    serialFdtd();

    bool isStable();

    virtual void serialUpdateE();
    virtual void serialUpdateH();

    virtual void iteration();

    void show();
};

#endif //FDTD_SERIALFDTD_H
