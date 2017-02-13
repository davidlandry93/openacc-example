
#include <cmath>

#include "gaussian.h"

void gaussian_pdf(Point* points, int n_points, float* result) {
#pragma acc kernels
    {
    for(int i = 0; i < n_points; i++) {
        result[i] = gaussian_pdf_of_point(points[i]);
    }
    }
}

// PDF of a zero centered, 1-covariance gaussian.
float gaussian_pdf_of_point(const Point& point) {
    return exp(-0.5 * mahalanobis_distance(point)) / sqrt(pow(2 * M_PI, 3.0));
}

// Mahalanobis distance in the case of a centerend, 1-covariance gaussian.
float mahalanobis_distance(const Point& point) {
    return sqrt(0.1 * point.x * point.x + 0.1 * point.y * point.y + 0.1 * point.z * point.z);
}
