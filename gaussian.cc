
#include <cmath>

#include "gaussian.h"

void gaussian_pdf(Point* points, int n_points, float* result) {

<<<<<<< HEAD
// #pragma acc data present(points[:n_points]) present(result[:n_points])
=======
>>>>>>> 3f58c45e6669d0a6b2a1902100d35702be9822ed
#pragma acc kernels
    {
    for(int i = 0; i < n_points; i++) {
        result[i] = gaussian_pdf_of_point(points[i]);
    }
    }
}
