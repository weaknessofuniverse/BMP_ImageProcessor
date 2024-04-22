#pragma once
#include "abstract_filter.h"
#include "grayscale_filter.h"
#include "matrix_filter.h"

class EdgeDetectionFilter final : public MatrixFilter, public GrayscaleFilter {
public:
    int** filter;
    double threshold;
    explicit EdgeDetectionFilter(double);
    ~EdgeDetectionFilter() override;
    void Process(Image& image) override;
    int** CreateFilter();
};
