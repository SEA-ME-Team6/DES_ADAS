//
//  control_types.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "control".
//
//  Model version              : 1.1
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Wed Jun  5 20:33:01 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef control_types_h_
#define control_types_h_
#include <stdint.h>
#ifndef struct_codertarget_raspi_internal_RaspiTCPSend_control_T
#define struct_codertarget_raspi_internal_RaspiTCPSend_control_T

struct codertarget_raspi_internal_RaspiTCPSend_control_T
{
  int32_t isInitialized;
  uint16_t connStream_;
  double isServer_;
  uint8_t isLittleEnd_;
};

#endif              // struct_codertarget_raspi_internal_RaspiTCPSend_control_T
#endif                                 // control_types_h_
