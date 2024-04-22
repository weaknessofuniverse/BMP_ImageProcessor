#pragma once
#include "abstract_filter.h"

class MatrixFilter : public AbstractFilter {
public:
    int** matrix;
    explicit MatrixFilter(int** input);
    ~MatrixFilter() override;
    void Process(Image& image) override;
};
