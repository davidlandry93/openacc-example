#ifndef GAUSSIAN_H
#define GAUSSIAN_H

#include "point.h"

void gaussian_pdf(Point* points, int n_points, float* result);
float gaussian_pdf_of_point(const Point& point);
float mahalanobis_distance(const Point& point);

#endif
