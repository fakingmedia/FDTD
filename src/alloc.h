#ifndef FDTD_ALLOC_H
#define FDTD_ALLOC_H

#include <iostream>
using namespace std;

#define ALLOC_1D(PNTR, NUM) \
PNTR = new double[NUM]; \
if (PNTR == nullptr) {std::cerr << "Allocation failed..." << std::endl;}

#define ALLOC_2D(PNTR, NUMX, NUMY) \
PNTR = new double[(NUMX) * (NUMY)]; \
if (PNTR == nullptr) {std::cerr << "Allocation failed..." << std::endl;}

#define ALLOC_3D(PNTR, NUMX, NUMY, NUMZ) \
PNTR = new double[(NUMX) * (NUMY) * (NUMZ)]; \
if (PNTR == nullptr) {std::cerr << "Allocation failed..." << std::endl;}



#endif //FDTD_ALLOC_H
