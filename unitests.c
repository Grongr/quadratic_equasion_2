#include "unitests.h"
#include "qesolver.h"

int unit_test() {

    //   num   a    b    c   x1   x2                RootsCount
    TEST(1,    0,   0,   0,   0,   0, INFINITE_NUMBER_OF_ROOTS)
    TEST(2,    1,   1,   1,   0,   0,                        0)
    TEST(3,    1,   0,   0,   0,   0, INFINITE_NUMBER_OF_ROOTS)
    TEST(4,    1,   2,   1,  -1,   0, INFINITE_NUMBER_OF_ROOTS)

    return 0;
}
