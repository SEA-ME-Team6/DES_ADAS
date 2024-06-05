//
//  aeb.cpp
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


#include "aeb.h"
#include "aeb_types.h"
#include <cmath>
#include <stdint.h>
#include <array>

void aeb::aeb_SystemCore_setup(codertarget_raspi_internal_RaspiTCPReceive_aeb_T *
  obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  uint8_t isLittleEndian;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  obj->isInitialized = 1;
  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  tmp = std::round(obj->isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  TCPStreamSetup(3333, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&isLittleEndian);
}

// Model step function
void aeb::step()
{
  double tmp;
  uint32_t duration;
  int16_t errorNo;
  uint16_t tmp_0;
  int8_t b_varargout_2;
  uint8_t b_varargout_1;

  // MATLABSystem: '<Root>/TCP//IP Receive'
  tmp = std::round(aeb_DW.obj_i.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  TCPStreamStepRecv(&b_varargout_1, &b_varargout_2, 1, aeb_DW.obj_i.connStream_,
                    &errorNo, tmp_0);

  // Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S1>/Enable'

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  if (b_varargout_1 > 0) {
    // MATLABSystem: '<S1>/Ultrasonic Sensor'
    if (aeb_DW.obj.SampleTime != -1.0) {
      aeb_DW.obj.SampleTime = -1.0;
    }

    MW_UltrasonicRead(&duration, 1, 4U, 17U, 10, 5);

    // MATLAB Function: '<S1>/MATLAB Function' incorporates:
    //   MATLABSystem: '<S1>/Ultrasonic Sensor'
    //
    aeb_B.brake_command = (static_cast<double>(duration) * 0.000343 / 2.0 < 0.12);
  }

  // End of Outputs for SubSystem: '<Root>/Enabled Subsystem'

  // Send: '<Root>/Event Send'
  // Send event
  ProvidedPort->Out1.Send(aeb_B.brake_command);
}

// Model initialize function
void aeb::initialize()
{
  // SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem'
  // Start for MATLABSystem: '<S1>/Ultrasonic Sensor'
  aeb_DW.obj.matlabCodegenIsDeleted = false;
  aeb_DW.obj.SampleTime = -1.0;
  aeb_DW.obj.isInitialized = 1;
  EXT_GPIO_init(4U, 1);
  EXT_GPIO_init(17U, 0);
  aeb_DW.obj.isSetupComplete = true;

  // End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem'

  // Start for MATLABSystem: '<Root>/TCP//IP Receive'
  aeb_SystemCore_setup(&aeb_DW.obj_i);

  // Initialize service provider instance - ProvidedPort
  ProvidedPort = std::make_shared< skeleton::ProvidedInterfaceSkeleton >(ara::
    com::InstanceIdentifier(std::string("1")), ara::com::
    MethodCallProcessingMode::kEventSingleThread);
  ProvidedPort->OfferService();
}

// Model terminate function
void aeb::terminate()
{
  // Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem'
  // Terminate for MATLABSystem: '<S1>/Ultrasonic Sensor'
  if (!aeb_DW.obj.matlabCodegenIsDeleted) {
    aeb_DW.obj.matlabCodegenIsDeleted = true;
    if ((aeb_DW.obj.isInitialized == 1) && aeb_DW.obj.isSetupComplete) {
      EXT_GPIO_terminate(17U);
      EXT_GPIO_terminate(4U);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/Ultrasonic Sensor'
  // End of Terminate for SubSystem: '<Root>/Enabled Subsystem'
  ProvidedPort->StopOfferService();
}

// Constructor
aeb::aeb():
  aeb_B(),
  aeb_DW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
aeb::~aeb() = default;
