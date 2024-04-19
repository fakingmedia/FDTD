//
// Created by MATEBOOK on 24-4-19.
//

#ifndef FDTD_ABC_H
#define FDTD_ABC_H

#include "alloc.h"
#include "macro.h"

class ABC {
private:
    double abcoef;
    double *exy0, *exy1, *exz0, *exz1, *eyx0, *eyx1, *eyz0, *eyz1, *ezx0, *ezx1, *ezy0, *ezy1;
public:
    ABC(Grid *g);
    ~ABC();

    void abc(Grid *g);
};

#endif //FDTD_ABC_H
