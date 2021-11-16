#pragma once

namespace hb {

// uses fftw3.3
void hilbert_old(double *x, double *x_imag, const int length);

} // namespace hb
