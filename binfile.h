#pragma once

#include <cerrno>
#include <cstdio>
#include <iostream>

#include <opencv2/opencv.hpp>

namespace bf {

using cv::Mat;

const int N_SAMPLES = 6400;
const int N_A_LINES = 1000;

const int SIZE_Y = 1300; // from 6400
const int SIZE_X = 1000; // from 1000

/**
 * Reconstruct PAM from binary file, returns uint8 image
 */
Mat process_PA_bin(const char *fname, int dB, int size_y = SIZE_Y,
                   int size_x = SIZE_X);

/**
 * Reconstruct B scan from binary file, returns uint8 image
 */
Mat process_US_bin(const char *fname, int dB, int size_y = SIZE_Y,
                   int size_x = SIZE_X);

// Read US bin file (little endian)
Mat read_bin_file(const char *fname);

} // namespace bf
