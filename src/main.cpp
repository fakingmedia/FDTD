#include <iostream>
#include "Grid.h"

int main() {
    Grid *g = new Grid(3);

    g->serial();
    g->parallelCPU();

    return 0;
}
