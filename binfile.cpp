#include "binfile.h"

namespace bf {
Mat process_PA_bin(const char *fname, int dB, int size_y, int size_x) {
  // load bin file
  auto mat = read_bin_file(fname);

  // apply filters

  // resize to B scan

  return mat;
}

Mat read_bin_file(const char *fname) {

  Mat mat(N_A_LINES, N_SAMPLES, CV_64FC1);

  std::FILE *fp = std::fopen(fname, "rb");
  if (fp) {
    std::fseek(fp, 0, SEEK_END);
    std::rewind(fp);
    std::fread(mat.data, 1, N_SAMPLES * N_A_LINES, fp);
    std::fclose(fp);

    return mat.t();
  }

  throw(errno);
}

} // namespace bf
