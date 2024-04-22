#include "edge_detection_filter.h"

const double INT_8_MAX = 255.0;
const uint8_t WHITE = 255;
const uint8_t BLACK = 0;
const int CENTER_SHARPENING = 4;
const int SIDES_SHARPENING = -1;

EdgeDetectionFilter::~EdgeDetectionFilter() {
    for (size_t i = 0; i < 3; ++i) {
        delete[] filter[i];
    }
    delete[] filter;
}

int** EdgeDetectionFilter::CreateFilter() {
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

EdgeDetectionFilter::EdgeDetectionFilter(double input) : MatrixFilter(CreateFilter()) {
    threshold = input;
}

void EdgeDetectionFilter::Process(Image& image) {
    GrayscaleFilter::Process(image);
    MatrixFilter::Process(image);
    for (uint32_t x = 0; x < image.Height(); ++x) {
        for (uint32_t y = 0; y < image.Width(); ++y) {
            if ((static_cast<double>(image.pixels[x][y].red) / INT_8_MAX) > threshold) {
                image.pixels[x][y] = {WHITE, WHITE, WHITE};
            } else {
                image.pixels[x][y] = {BLACK, BLACK, BLACK};
            }
        }
    }
}