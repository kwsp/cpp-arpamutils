#include <fftw3.h>

#include "hilbert.h"

namespace hb {

void hilbert_old(double *x, double *x_imag, const int length) {

  {
    fftw_complex *in, *out;
    fftw_plan p;

    // malloc fftw in, out
    in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * length);
    out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * length);

    // copy data to fftw in
    for (int i = 0; i < length; i++) {
      in[i][0] = x[0];
      in[i][1] = 0;
    }

    // create plan
    p = fftw_plan_dft_1d(length, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    // execute plan
    fftw_execute(p);

    //
    for (int i = 1; i < length / 2; i++) {
      out[i][0] = 0;
      out[i][1] = 0;
    }

    for (int i = length / 2 + 1; i < length; i++) {
      out[i][0] = 0;
      out[i][1] = 0;
    }

    // use out as input buffer
    p = fftw_plan_dft_1d(length, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(p);

    for (int i = 0; i < length; i++) {
      x_imag[i] = in[i][1] / length;
    }

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);
  }
}
} // namespace hb
