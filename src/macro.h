#include "Grid.h"


//一维网格
#define Hy1(M) hy[M]
#define Chyh1(M) chyh[M]
#define Chye1(M) chye[M]

#define Ez1(M) hy[M]
#define Cezh1(M) cezh[M]
#define Ceze1(M) ceze[M]


//TMz网格
#define Hx2(M, N) hx[(M) * (sizeY - 1) + N]
#define Chxh2(M, N) chxh[(M) * (sizeY - 1) + N]
#define Chxe2(M, N) chxe[(M) * (sizeY - 1) + N]

#define Hy2(M, N) hy[(M) * sizeY + N]
#define Chyh2(M, N) chyh[(M) * sizeY + N]
#define Chye2(M, N) chye[(M) * sizeY + N]

#define Ez2(M, N) ez[(M) * sizeY + N]
#define Cezh2(M, N) cezh[(M) * sizeY + N]
#define Ceze2(M, N) ceze[(M) * sizeY + N]


//TEz网格
#define Ex2(M, N) ex[(M) * sizeY + N]
#define Cexh2(M, N) cexh[(M) * sizeY + N]
#define Cexe2(M, N) cexe[(M) * sizeY + N]

#define Ey2(M, N) ey[(M) * (sizeY - 1) + N]
#define Ceyh2(M, N) ceyh[(M) * (sizeY - 1) + N]
#define Ceye2(M, N) ceye[(M) * (sizeY - 1) + N]

#define Hz2(M, N) hz[(M) * (sizeY - 1) + N]
#define Chzh2(M, N) chzh[(M) * (sizeY - 1) + N]
#define Chze2(M, N) chze[(M) * (sizeY - 1) + N]


//三维网格
#define Hx(M, N, P) hx[((M) * (sizeY - 1) + N) * (sizeZ - 1) + P]
#define Chxh(M, N, P) chxh[((M) * (sizeY - 1) + N) * (sizeZ - 1) + P]
#define Chxe(M, N, P) chxe[((M) * (sizeY - 1) + N) * (sizeZ - 1) + P]

#define Hy(M, N, P) hy[((M) * sizeY + N) * (sizeZ - 1) + P]
#define Chyh(M, N, P) chyh[((M) * sizeY + N) * (sizeZ - 1) + P]
#define Chye(M, N, P) chye[((M) * sizeY + N) * (sizeZ - 1) + P]

#define Hz(M, N, P) hz[((M) * (sizeY - 1) + N) * sizeZ + P]
#define Chzh(M, N, P) chzh[((M) * (sizeY - 1) + N) * sizeZ + P]
#define Chze(M, N, P) chze[((M) * (sizeY - 1) + N) * sizeZ + P]

#define Ex(M, N, P) ex[((M) * sizeY + N) * sizeZ + P]
#define Cexh(M, N, P) cexh[((M) * sizeY + N) * sizeZ + P]
#define Cexe(M, N, P) cexe[((M) * sizeY + N) * sizeZ + P]

#define Ey(M, N, P) ey[((M) * (sizeY - 1) + N) * sizeZ + P]
#define Ceyh(M, N, P) ceyh[((M) * (sizeY - 1) + N) * sizeZ + P]
#define Ceye(M, N, P) ceye[((M) * (sizeY - 1) + N) * sizeZ + P]

#define Ez(M, N, P) ez[((M) * sizeY + N) * (sizeZ - 1) + P]
#define Cezh(M, N, P) cezh[((M) * sizeY + N) * (sizeZ - 1) + P]
#define Ceze(M, N, P) ceze[((M) * sizeY + N) * (sizeZ - 1) + P]


//ABC
#define Eyx0(N, P) eyx0[(N) * (sizeZ) + (P)]
#define Ezx0(N, P) ezx0[(N) * (sizeZ - 1) + (P)]
#define Eyx1(N, P) eyx1[(N) * (sizeZ) + (P)]
#define Ezx1(N, P) ezx1[(N) * (sizeZ - 1) + (P)]

#define Exy0(M, P) exy0[(M) * (sizeZ) + (P)]
#define Ezy0(M, P) ezy0[(M) * (sizeZ - 1) + (P)]
#define Exy1(M, P) exy1[(M) * (sizeZ) + (P)]
#define Ezy1(M, P) ezy1[(M) * (sizeZ - 1) + (P)]

#define Exz0(M, N) exz0[(M) * (sizeY) + (N)]
#define Eyz0(M, N) eyz0[(M) * (sizeY - 1) + (N)]
#define Exz1(M, N) exz1[(M) * (sizeY) + (N)]
#define Eyz1(M, N) eyz1[(M) * (sizeY - 1) + (N)]