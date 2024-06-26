//
//  lkas.h
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
//
//  Target selection: autosar_adaptive.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
//  Code generation objectives: Unspecified
//  Validation result: Not run


#ifndef lkas_h_
#define lkas_h_
#include <stdbool.h>
#include <stdint.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "complex_types.h"
#include "MW_availableWebcam.h"
#include "MW_v4l2_cam.h"
#include "vipsvd_rt.h"
#include "MW_TCPSendReceive.h"
#include "providedinterface_skeleton.h"
#include <stddef.h>
#include "lkas_types.h"
#include <array>
#include <memory>

// Class declaration for model lkas
class lkas final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_lkas_T {
    std::array<double, 921600> ColorSpaceConversion;// '<S5>/Color Space  Conversion' 
    std::array<double, 921600> ImageDataTypeConversion;
    double jj_data[307200];
    double ii_data[307200];
    std::array<double, 307200> srcXIntrinsic;
    std::array<double, 307200> srcYIntrinsic;
    int32_t ii_data_m[307200];
    int32_t jj_data_c[307200];
    int32_t tmp_data[307200];
    int32_t tmp_data_k[307200];
    int32_t tmp_data_c[307200];
    int32_t tmp_data_b[307200];
    std::array<int8_t, 307200> inputImage;
    std::array<bool, 307200> bv;
    std::array<bool, 307200> bv1;
    std::array<uint8_t, 307200> uv;
    std::array<uint8_t, 307200> uv1;
    std::array<uint8_t, 307200> uv2;
    std::array<uint8_t, 307200> uv3;
    bool b_data[307200];
    bool c_data[307200];
    bool d_data[307200];
    bool g_data[307200];
    bool h_data[307200];
    bool b_tmp_data[307200];
    bool tmp_data_p[307200];
    bool tmp_data_cv[307200];
    bool tmp_data_f[307200];
    bool tmp_data_g[307200];
    bool tmp_data_g1[307200];
    bool tmp_data_m[307200];
    bool tmp_data_n[307200];
    double OutportBufferForthrottle;   // '<S1>/Constant'
    double error;                      // '<S3>/MATLAB Function1'
    std::array<uint8_t, 921600> outputImage;// '<S1>/MATLAB Function'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_lkas_T {
    codertarget_raspi_internal_Raspiv4l2Capture_lkas_T obj;// '<S1>/V4L2 Video Capture' 
    vision_internal_blocks_Warp_lkas_T obj_p;// '<S5>/Warp'
    codertarget_raspi_internal_RaspiTCPReceive_lkas_T obj_e;// '<Root>/TCP//IP Receive' 
    std::array<double, 921600> ColorSpaceConversion_DWORK1;// '<S5>/Color Space  Conversion' 
  };

  // Invariant block signals (default storage)
  struct ConstB_lkas_T {
    double Constant;                   // '<S1>/Constant'
  };

  // Copy Constructor
  lkas(lkas const&) = delete;

  // Assignment Operator
  lkas& operator= (lkas const&) & = delete;

  // Move Constructor
  lkas(lkas &&) = delete;

  // Move Assignment Operator
  lkas& operator= (lkas &&) = delete;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  lkas();

  // Destructor
  ~lkas();

  // private data and function members
 private:
  // Block signals
  B_lkas_T lkas_B;

  // Block states
  DW_lkas_T lkas_DW;
  std::shared_ptr<skeleton::ProvidedInterfaceSkeleton> ProvidedPort;

  // private member function(s) for subsystem '<Root>'
  void lkas_v4l2Capture_updateV4L2Settings
    (codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *obj, bool forceUpdate);
  void lkas_SystemCore_step(codertarget_raspi_internal_Raspiv4l2Capture_lkas_T
    *obj, uint8_t varargout_1[307200], uint8_t varargout_2[307200], uint8_t
    varargout_3[307200]);
  void lkas_Warp_stepImpl(vision_internal_blocks_Warp_lkas_T *b_this, const bool
    Image[307200], const double input2[9], bool Jout[307200]);
  void lkas_eml_find(const bool x[307200], int32_t i_data[], int32_t *i_size,
                     int32_t j_data[], int32_t *j_size);
  void lkas_and(bool in1_data[], int32_t *in1_size, const bool in2_data[], const
                int32_t *in2_size, const bool in3_data[], const int32_t
                *in3_size);
  void lkas_binary_expand_op_3(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const int32_t in3_data[], const int32_t
    *in3_size);
  double lkas_mean(const double x_data[], const int32_t *x_size);
  double lkas_maximum(const double x_data[], const int32_t *x_size);
  void lkas_binary_expand_op_2(bool in1_data[], int32_t *in1_size, const bool
    in2_data[], const int32_t *in2_size, const bool in3_data[], const bool
    in4_data[], const int32_t *in4_size, const bool in5_data[], const int32_t
    *in5_size);
  void lkas_binary_expand_op(bool in1_data[], int32_t *in1_size, const int32_t
    in2_data[], const int32_t *in2_size, double in3, double in4, const int32_t
    in5_data[], const int32_t *in5_size, double in6);
  void lkas_binary_expand_op_1(bool in1_data[], int32_t *in1_size, const double
    in2_data[], const int32_t *in2_size, double in3, double in4, const double
    in5_data[], const int32_t *in5_size, double in6);
  codertarget_raspi_internal_Raspiv4l2Capture_lkas_T
    *lkas_Raspiv4l2Capture_Raspiv4l2Capture
    (codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *obj);
  void lkas_SystemCore_setup(codertarget_raspi_internal_Raspiv4l2Capture_lkas_T *
    obj);
  void lkas_SystemCore_setup_h(codertarget_raspi_internal_RaspiTCPReceive_lkas_T
    *obj);
};

extern const lkas::ConstB_lkas_T lkas_ConstB;// constant block i/o

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
//  '<Root>' : 'lkas'
//  '<S1>'   : 'lkas/Enabled Subsystem'
//  '<S2>'   : 'lkas/Enabled Subsystem/MATLAB Function'
//  '<S3>'   : 'lkas/Enabled Subsystem/Perception Unit'
//  '<S4>'   : 'lkas/Enabled Subsystem/RGB to Image'
//  '<S5>'   : 'lkas/Enabled Subsystem/Perception Unit/Image Processing'
//  '<S6>'   : 'lkas/Enabled Subsystem/Perception Unit/MATLAB Function1'
//  '<S7>'   : 'lkas/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function1'
//  '<S8>'   : 'lkas/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function2'
//  '<S9>'   : 'lkas/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function7'
//  '<S10>'  : 'lkas/Enabled Subsystem/Perception Unit/Image Processing/MATLAB Function8'

#endif                                 // lkas_h_
