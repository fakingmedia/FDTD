//
// Created by MATEBOOK on 2024/4/1.
//

#ifndef FDTD_PARALLELFDTD_H
#define FDTD_PARALLELFDTD_H

#include "serialFdtd.h"
#include <omp.h>

class parallelFdtd:
        protected serialFdtd {
private:
    int threadNum;
public:
    parallelFdtd(int threadNum);

    void updateE();
    void updateH();
};

#endif //FDTD_PARALLELFDTD_H
