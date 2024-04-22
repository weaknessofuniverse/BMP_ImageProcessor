#include "sharpening_filter.h"

const int CENTER_SHARPENING = 5;
const int SIDES_SHARPENING = -1;

SharpeningFilter::~SharpeningFilter() {
    for (size_t i = 0; i < 3; ++i) {
        delete[] filter[i];
    }
    delete[] filter;
}

int** SharpeningFilter::CreateFilter() {
    filter = new int*[3];
    for (size_t i = 0; i < 3; ++i) {
        filter[i] = new int[3];
    }
    filter[0][0] = 0;
    filter[0][1] = SIDES_SHARPENING;
    filter[0][2] = 0;
    filter[1][0] = SIDES_SHARPENING;
    filter[1][1] = CENTER_SHARPENING;
    filter[1][2] = SIDES_SHARPENING;
    filter[2][0] = 0;
    filter[2][1] = SIDES_SHARPENING;
    filter[2][2] = 0;
    return filter;
}

SharpeningFilter::SharpeningFilter() : MatrixFilter(CreateFilter()) {
}