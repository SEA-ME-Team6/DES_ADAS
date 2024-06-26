//
//  normPts_D_D.cpp
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "lkas".
//
//  Model version              : 1.2
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Thu Jun  6 12:21:23 2024
//  Created for block: lkas


#include <stdint.h>
#include "normPts_D_D.h"
#include <cmath>

void normPts_D_D(const double pts[], const uint32_t samples[], uint32_t ptsNum,
                 uint32_t sampleNum, double ptsNorm[], double scale[], double
                 cents[])
{
  double sumDis;

  // S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
  // Normalize the points.
  cents[0U] = 0.0;
  cents[1U] = 0.0;
  for (uint32_t i{0U}; i < sampleNum; i++) {
    sumDis = pts[samples[i] + ptsNum];
    ptsNorm[i + sampleNum] = sumDis;
    cents[0U] += sumDis;
    sumDis = pts[samples[i]];
    ptsNorm[i] = sumDis;
    cents[1U] += sumDis;
  }

  cents[0U] /= static_cast<double>(sampleNum);
  cents[1U] /= static_cast<double>(sampleNum);
  sumDis = 0.0;
  for (uint32_t i{0U}; i < sampleNum; i++) {
    uint32_t j;
    j = i + sampleNum;
    ptsNorm[j] -= cents[0U];
    ptsNorm[i] -= cents[1U];
    sumDis += std::sqrt(ptsNorm[j] * ptsNorm[j] + ptsNorm[i] * ptsNorm[i]);
  }

  if (sumDis > 0.0) {
    scale[0U] = 1.4142135623730951;
    scale[0U] *= static_cast<double>(sampleNum);
    scale[0U] /= sumDis;
    for (uint32_t i{0U}; i < sampleNum + sampleNum; i++) {
      ptsNorm[i] *= scale[0U];
    }
  }

  // End of S-Function (svipesttform): '<S5>/Estimate Geometric Transformation'
}
