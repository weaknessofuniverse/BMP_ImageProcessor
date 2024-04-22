#pragma once
#include "matrix_filter.h"

class SharpeningFilter : public MatrixFilter {
public:
    int** filter;
    SharpeningFilter();
    ~SharpeningFilter() override;
    int** CreateFilter();
};