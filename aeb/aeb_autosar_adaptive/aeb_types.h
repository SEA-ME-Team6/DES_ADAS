//
//  aeb_types.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "aeb".
//
//  Model version              : 1.3
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Thu Jun  6 12:32:57 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef aeb_types_h_
#define aeb_types_h_
#include <stdbool.h>
#include <stdint.h>
#ifndef struct_sensors_raspberrypi_UltrasonicBlock_aeb_T
#define struct_sensors_raspberrypi_UltrasonicBlock_aeb_T

struct sensors_raspberrypi_UltrasonicBlock_aeb_T
{
  bool matlabCodegenIsDeleted;
  int32_t isInitialized;
  bool isSetupComplete;
  double SampleTime;
};

#endif                      // struct_sensors_raspberrypi_UltrasonicBlock_aeb_T

#ifndef struct_codertarget_raspi_internal_RaspiTCPReceive_aeb_T
#define struct_codertarget_raspi_internal_RaspiTCPReceive_aeb_T

struct codertarget_raspi_internal_RaspiTCPReceive_aeb_T
{
  int32_t isInitialized;
  uint16_t connStream_;
  double isServer_;
};

#endif               // struct_codertarget_raspi_internal_RaspiTCPReceive_aeb_T
#endif                                 // aeb_types_h_
