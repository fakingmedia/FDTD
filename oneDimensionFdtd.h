//
// Created by MATEBOOK on 2024/4/9.
//

#ifndef FDTD_ONEDIMENSIONFDTD_H
#define FDTD_ONEDIMENSIONFDTD_H

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>


using namespace std;

class oneDimensionFdtd {
protected:
    int maxTime;
    int size;

    vector<double> hy, ez;//磁场和电场

    double pi;
    double epsilon0;//真空电容率
    double mju0;//真空的磁导率
    double c;//光速
    double eta0;//自由空间的特性阻抗

    double epsilonR;//相对电容率
    double mjuR;//相对磁导率

    double deltaT;//时间步长
    double deltaX;//X轴空间步长

    double courant1;//一维的稳定常数(小于一才稳定)

public:
    oneDimensionFdtd();

    void updateE();
    void updateH();

    void dataStore(int time);

    void iteration();
};


#endif //FDTD_ONEDIMENSIONFDTD_H
