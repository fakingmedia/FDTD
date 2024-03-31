//
// Created by NZ on 2024/3/30.
//

#ifndef FDTD_SERIALFDTD_H
#define FDTD_SERIALFDTD_H

#include<cmath>
#include<vector>

using namespace std;

class serialFdtd {
protected:
    const double c = 300000000;

    vector<vector<vector<vector<double>>>> E; //电场强度(t,x,y,z)
    vector<vector<vector<vector<double>>>> H; //磁场强度(t,x,y,z)
    vector<vector<vector<vector<double>>>> J; //电流密度(t,x,y,z)
    vector<vector<vector<vector<double>>>> M; //磁流密度(t,x,y,z)

    double epsilon; //媒介的介电常数
    double mju; //媒介的磁导率
    double sigmaE; //电导率
    double sigmaM; //磁导率

    int n; //迭代次数
    double deltaT; //时间步长
    double deltaX, deltaY, deltaZ; //x,y,z轴上的空间距离
public:
    serialFdtd();

    bool isStable();

    void updateE();
    void updateH();

    void show();
};


#endif //FDTD_SERIALFDTD_H
