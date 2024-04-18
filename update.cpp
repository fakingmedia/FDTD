#include "Grid.h"
#include "macro.h"

void Grid::updateE() {

}

void Grid::updateH() {
    int mm, nn, pp;

    if (type == oneGrid) {
        for (mm = 0; mm < sizeX - 1; mm++)
            Hy1(mm) = Chyh1(mm) * Hy1(mm) + Chye1(mm) * (Ez1(mm + 1) - Ez1(mm));
    } else if (type == tmZGrid) {
        for (mm = 0; mm < sizeX; mm++)
            for (nn = 0; nn < sizeY - 1; nn++)
                Hx2(mm, nn) = Chxh2(mm, nn) * Hx2(mm, nn) - Chxe2(mm, nn) * (Ez2(mm, nn + 1) - Ez2(mm, nn));

        for (mm = 0; mm < sizeX - 1; mm++)
            for (nn = 0; nn < sizeY; nn++)
                Hy2(mm, nn) = Chyh2(mm, nn) * Hy2(mm, nn) + Chye2(mm, nn) * (Ez2(mm + 1, nn) - Ez2(mm, nn));
    } else if (type == teZGrid) {
        for (mm = 0; mm < sizeX - 1; mm++)
            for (nn = 0; nn < sizeY - 1; nn++)
                Hz2(mm, nn) = Chzh2(mm, nn) * Hz2(mm, nn)
                        - Chze2(mm, nn) * ((Ey2(mm + 1, nn) - Ey2(mm, nn)) - (Ex2(mm, nn + 1) - Ex2(mm, nn)));
    } else if (Ty)



}