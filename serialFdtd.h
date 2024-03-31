//
// Created by NZ on 2024/3/30.
//

#ifndef FDTD_SERIALFDTD_H
#define FDTD_SERIALFDTD_H

#include<vector>

using namespace std;

class serialFdtd {
protected:
    const double c = 300000000;

    vector<vector<vector<double>>> E;
    vector<vector<vector<double>>> H;
    double epsilon; //媒介的介电常数
    double mju; //媒介的磁导率
    double sigmaE; //电导率
    double sigmaM; //磁导率

    int n; //迭代次数
    double deltaT; //时间步长
    double deltaX, deltaY, deltaZ; //x,y,z轴上的空间距离
public:
    serialFdtd();
    void updateE();
    void updateH();
    void show();
};


#endif //FDTD_SERIALFDTD_H
