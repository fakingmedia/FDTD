#ifndef FDTD_EZINC_H
#define FDTD_EZINC_H

#include <iostream>
#include <cmath>

double ezInc(double cdtds, double ppw, double time, double location) {
    double arg;

    if (ppw <= 0) {
        std::cerr << "ezInc: ezIncInit() must be called before ezInc." << std::endl;
    }

    arg = M_PI * ((cdtds * time - location) / ppw - 1.0);
    arg = arg * arg;

    return (1.0 - 2.0 * arg) * exp(-arg);
}

#endif //FDTD_EZINC_H
