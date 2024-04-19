#include "ABC.h"

#define Eyx0(N, P) eyx0[(N) * (sizeZ) + (P)]
#define Ezx0(N, P) ezx0[(N) * (sizeZ - 1) + (P)]
#define Eyx1(N, P) eyx1[(N) * (sizeZ) + (P)]
#define Ezx1(N, P) ezx1[(N) * (sizeZ - 1) + (P)]

#define Exy0(N, P) exy0[(M) * (sizeZ) + (P)]
#define Ezy0(N, P) ezy0[(M) * (sizeZ - 1) + (P)]
#define Exy1(N, P) exy1[(M) * (sizeZ) + (P)]
#define Ezy1(N, P) ezy1[(M) * (sizeZ - 1) + (P)]

#define Exz0(N, P) exz0[(M) * (sizeY) + (N)]
#define Eyz0(N, P) eyz0[(M) * (sizeY - 1) + (N)]
#define Exz1(N, P) exz1[(M) * (sizeY) + (N)]
#define Eyz1(N, P) eyz1[(M) * (sizeY - 1) + (N)]

