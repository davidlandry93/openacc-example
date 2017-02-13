
#include <cmath>

#include "gaussian.h"

void gaussian_pdf(Point* points, int n_points, float* result) {
    Point *pts = points;
    float *rslt = result;

#pragma acc data present(pts[:n_points]) present(rslt[:n_points])
#pragma acc kernels
    {
    for(int i = 0; i < n_points; i++) {
        rslt[i] = gaussian_pdf_of_point(pts[i]);
    }
    }
}
