#pragma once

#include "CalibrationData.h"

#include <opencv2/opencv.hpp>
#include <vector>

class Triangulator {
public:
  Triangulator(CalibrationData _calibration);
  CalibrationData getCalibration() { return calibration; }
  ~Triangulator() {}
  // Reconstruction
  void triangulate(cv::Mat &up, cv::Mat &vp, cv::Mat &mask, cv::Mat &shading,
                   cv::Mat &pointCloud);

private:
  void triangulateFromUp(cv::Mat &up, cv::Mat &xyz);
  void triangulateFromVp(cv::Mat &vp, cv::Mat &xyz);
  void triangulateFromUpVp(cv::Mat &up, cv::Mat &vp, cv::Mat &xyz);
  CalibrationData calibration;
  cv::Mat determinantTensor;
  cv::Mat uc, vc;
  cv::Mat lensMap1, lensMap2;
  std::vector<cv::Mat> xyzwPrecomputeOffset;
  std::vector<cv::Mat> xyzwPrecomputeFactor;
};
