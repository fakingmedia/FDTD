//
// Created by MATEBOOK on 2024/4/1.
//

#include "parallelFdtd.h"

parallelFdtd::parallelFdtd(int threadNum) {
    this->threadNum = threadNum;

}

void parallelFdtd::updateE() {
#pragma omp parallel
    {
#pragma opm for
        updateE();
    }
}

void parallelFdtd::updateH() {
#pragma omp parallel
    {
#pragma opm for
        updateH();
    }
}