#include <iostream>

#include <memory>
#include <opencv2/opencv.hpp>

#include "binfile.h"

int main() {

  const auto fpath = "/home/tiger/Downloads/125321/NormalUS1l.bin";

  auto res = bf::read_bin_file(fpath);

  std::cout << res.size() << std::endl;
  std::cout << res.at<double>(0, 0) << " "<< res.at<double>(0, 1) << std::endl;
  std::cout << res.at<double>(1, 0) << " "<< res.at<double>(1, 1) << std::endl;

  return 0;
}
