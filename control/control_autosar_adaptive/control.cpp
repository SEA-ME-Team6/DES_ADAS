//
//  control.cpp
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


#include "control.h"
#include "control_types.h"
#include <cstring>
#include <cmath>
#include <stdint.h>
#include <array>
#include <stddef.h>

void control::control_TCPSend_setupImpl
  (codertarget_raspi_internal_RaspiTCPSend_control_T *obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

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

  // Start for MATLABSystem: '<Root>/TCP//IP Send'
  TCPStreamSetup(3334, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

void control::control_TCPSend_setupImpl_m
  (codertarget_raspi_internal_RaspiTCPSend_control_T *obj)
{
  std::array<char, 14> ipaddr;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  static const std::array<char, 14> ipaddr_0{ { '1', '9', '2', '.', '1', '6',
      '8', '.', '1', '.', '1', '5', '5', '\x00' } };

  obj->isServer_ = 0.0;
  for (int32_t i{0}; i < 14; i++) {
    ipaddr[i] = ipaddr_0[i];
  }

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

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  TCPStreamSetup(3335, 0, &obj->connStream_, tmp_0, 0.0, &errorNo, &ipaddr[0]);
  littleEndianCheck(&obj->isLittleEnd_);
}

void control::RequiredPortSvcHandler(ara::com::ServiceHandleContainer< proxy::
  RequiredInterfaceProxy::HandleType > svcHandles, const ara::com::
  FindServiceHandle fsHandle)
{
  if ((!RequiredPort) && (svcHandles.size() > 0U)) {
    RequiredPort = std::make_shared< proxy::RequiredInterfaceProxy >
      (*svcHandles.begin());
    RequiredPort->Aeb.Subscribe(1U);
    RequiredPort->Lkas.Subscribe(1U);
    proxy::RequiredInterfaceProxy::StopFindService(fsHandle);
  }
}

void control::RequiredPortLkasReceive(ara::com::SamplePtr< proxy::events::Lkas::
  SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive'
  control_B.EventReceive = *elementPtr;
}

void control::RequiredPortAebReceive(ara::com::SamplePtr< proxy::events::Aeb::
  SampleType const > elementPtr)
{
  // Receive: '<Root>/Event Receive1'
  control_B.EventReceive1 = *elementPtr;
}

// Model step function
void control::step()
{
  std::array<uint8_t, 8> y;
  std::shared_ptr<ara::core::Result<size_t>> resultPtr;
  double rtb_Gain;
  double tmp;
  int16_t errorNo;
  uint16_t tmp_0;
  uint8_t xtmp;
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->Lkas.GetNewSamples(std::move(std::bind(&control::
          RequiredPortLkasReceive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }

  // Gain: '<Root>/Gain'
  rtb_Gain = 0.008 * control_B.EventReceive;

  // MATLABSystem: '<Root>/TCP//IP Send'
  if (control_DW.obj_i.isLittleEnd_ == 1) {
    std::memcpy((void *)&y[0], (void *)&rtb_Gain, (uint32_t)((size_t)8 * sizeof
      (uint8_t)));
    xtmp = y[0];
    y[0] = y[7];
    y[7] = xtmp;
    xtmp = y[1];
    y[1] = y[6];
    y[6] = xtmp;
    xtmp = y[2];
    y[2] = y[5];
    y[5] = xtmp;
    xtmp = y[3];
    y[3] = y[4];
    y[4] = xtmp;
    std::memcpy((void *)&rtb_Gain, (void *)&y[0], (uint32_t)((size_t)1 * sizeof
      (double)));
  }

  tmp = std::round(control_DW.obj_i.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  TCPStreamStepSend(&rtb_Gain, 8U, control_DW.obj_i.connStream_, tmp_0, &errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send'
  if (RequiredPort) {
    resultPtr = std::make_shared< ara::core::Result<size_t> >
      (RequiredPort->Aeb.GetNewSamples(std::move(std::bind(&control::
          RequiredPortAebReceive, this, std::placeholders::_1)), 1U));
    if (resultPtr->HasValue()) {
      resultPtr->Value();
    }
  }

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant1'

  if (control_B.EventReceive1 > 0.0) {
    rtb_Gain = 0.45;
  } else {
    rtb_Gain = 0.0;
  }

  // End of Switch: '<Root>/Switch'

  // MATLABSystem: '<Root>/TCP//IP Send1'
  if (control_DW.obj.isLittleEnd_ == 1) {
    std::memcpy((void *)&y[0], (void *)&rtb_Gain, (uint32_t)((size_t)8 * sizeof
      (uint8_t)));
    xtmp = y[0];
    y[0] = y[7];
    y[7] = xtmp;
    xtmp = y[1];
    y[1] = y[6];
    y[6] = xtmp;
    xtmp = y[2];
    y[2] = y[5];
    y[5] = xtmp;
    xtmp = y[3];
    y[3] = y[4];
    y[4] = xtmp;
    std::memcpy((void *)&rtb_Gain, (void *)&y[0], (uint32_t)((size_t)1 * sizeof
      (double)));
  }

  tmp = std::round(control_DW.obj.isServer_);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = static_cast<uint16_t>(tmp);
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = UINT16_MAX;
  }

  TCPStreamStepSend(&rtb_Gain, 8U, control_DW.obj.connStream_, tmp_0, &errorNo);

  // End of MATLABSystem: '<Root>/TCP//IP Send1'
}

// Model initialize function
void control::initialize()
{
  // Start for MATLABSystem: '<Root>/TCP//IP Send'
  control_DW.obj_i.isInitialized = 1;
  control_TCPSend_setupImpl(&control_DW.obj_i);

  // Start for MATLABSystem: '<Root>/TCP//IP Send1'
  control_DW.obj.isInitialized = 1;
  control_TCPSend_setupImpl_m(&control_DW.obj);

  // Initialize service requester instance - RequiredPort
  proxy::RequiredInterfaceProxy::StartFindService(std::move(std::bind(&control::
    RequiredPortSvcHandler, this, std::placeholders::_1, std::placeholders::_2)),
    ara::com::InstanceIdentifier(ara::core::StringView("1")));
}

// Model terminate function
void control::terminate()
{
  // (no terminate code required)
}

// Constructor
control::control():
  control_B(),
  control_DW()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
control::~control() = default;
