//
//  aeb.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "aeb".
//
//  Model version              : 1.4
//  Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
//  C++ source code generated on : Wed Jun  5 18:49:50 2024
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef aeb_h_
#define aeb_h_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "MW_Raspi_PulseIn.h"
#include "MW_gpio.h"
#include "linuxTimeLogger.h"
#include "MW_TCPSendReceive.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include "aeb_types.h"
#include <memory>

// Class declaration for model aeb
class aeb final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_aeb_T {
    double brake_command;              // '<S1>/MATLAB Function'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_aeb_T {
    sensors_raspberrypi_UltrasonicBlock_aeb_T obj;// '<S1>/Ultrasonic Sensor'
    codertarget_raspi_internal_RaspiTCPReceive_aeb_T obj_i;// '<Root>/TCP//IP Receive' 
  };

  // Copy Constructor
  aeb(aeb const&) = delete;

  // Assignment Operator
  aeb& operator= (aeb const&) & = delete;

  // Move Constructor
  aeb(aeb &&) = delete;

  // Move Assignment Operator
  aeb& operator= (aeb &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  aeb();

  // Destructor
  ~aeb();

  // private data and function members
 private:
  // Block signals
  B_aeb_T aeb_B;

  // Block states
  DW_aeb_T aeb_DW;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  void aeb_SystemCore_setup(codertarget_raspi_internal_RaspiTCPReceive_aeb_T
    *obj);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination
//  Block '<Root>/Scope1' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'aeb'
//  '<S1>'   : 'aeb/Enabled Subsystem'
//  '<S2>'   : 'aeb/Enabled Subsystem/MATLAB Function'

#endif                                 // aeb_h_
