/*
 * WT_pitch_actuator_no_sat_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WT_pitch_actuator_no_sat".
 *
 * Model version              : 1.3
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Nov 27 16:25:59 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "WT_pitch_actuator_no_sat_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "WT_pitch_actuator_no_sat.h"
#include "WT_pitch_actuator_no_sat_capi.h"
#include "WT_pitch_actuator_no_sat_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("WT_pitch_actuator_no_sat/Gain2"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("WT_pitch_actuator_no_sat/Integrator"),
    TARGET_STRING("beta_dot"), 0, 0, 0, 0, 1 },

  { 2, 0, TARGET_STRING("WT_pitch_actuator_no_sat/Square"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("WT_pitch_actuator_no_sat/Product"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("WT_pitch_actuator_no_sat/Add"),
    TARGET_STRING("beta_dot_dot"), 0, 0, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 5, TARGET_STRING("WT_pitch_actuator_no_sat/bias"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 6, TARGET_STRING("WT_pitch_actuator_no_sat/damping_ratio"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 7, TARGET_STRING("WT_pitch_actuator_no_sat/natural_frequency"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 8, TARGET_STRING("WT_pitch_actuator_no_sat/u"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 9, TARGET_STRING("WT_pitch_actuator_no_sat/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 10, TARGET_STRING("WT_pitch_actuator_no_sat/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 11, TARGET_STRING("WT_pitch_actuator_no_sat/Gain2"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 12, TARGET_STRING("WT_pitch_actuator_no_sat/effectiveness"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 13, TARGET_STRING("WT_pitch_actuator_no_sat/Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 14, TARGET_STRING("WT_pitch_actuator_no_sat/Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static const rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx
   */
  { 15, 0, TARGET_STRING("WT_pitch_actuator_no_sat/Integrator"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 1, 1, -1, 0 },

  { 16, 1, TARGET_STRING("WT_pitch_actuator_no_sat/Integrator1"),
    TARGET_STRING(""),
    TARGET_STRING(""),
    0, 0, 0, 0, 1, 1, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Root Inputs information */
static const rtwCAPI_Signals rtRootInputs[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Root Outputs information */
static const rtwCAPI_Signals rtRootOutputs[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &WT_pitch_actuator_no_sat_B.Gain2,   /* 0: Signal */
  &WT_pitch_actuator_no_sat_B.beta_dot,/* 1: Signal */
  &WT_pitch_actuator_no_sat_B.Square,  /* 2: Signal */
  &WT_pitch_actuator_no_sat_B.Product, /* 3: Signal */
  &WT_pitch_actuator_no_sat_B.beta_dot_dot,/* 4: Signal */
  &WT_pitch_actuator_no_sat_P.bias_Value,/* 5: Block Parameter */
  &WT_pitch_actuator_no_sat_P.damping_ratio_Value,/* 6: Block Parameter */
  &WT_pitch_actuator_no_sat_P.natural_frequency_Value,/* 7: Block Parameter */
  &WT_pitch_actuator_no_sat_P.u_Value, /* 8: Block Parameter */
  &WT_pitch_actuator_no_sat_P.Gain_Gain,/* 9: Block Parameter */
  &WT_pitch_actuator_no_sat_P.Gain1_Gain,/* 10: Block Parameter */
  &WT_pitch_actuator_no_sat_P.Gain2_Gain,/* 11: Block Parameter */
  &WT_pitch_actuator_no_sat_P.effectiveness_Gain,/* 12: Block Parameter */
  &WT_pitch_actuator_no_sat_P.Integrator_IC,/* 13: Block Parameter */
  &WT_pitch_actuator_no_sat_P.Integrator1_IC,/* 14: Block Parameter */
  &WT_pitch_actuator_no_sat_X.Integrator_CSTATE,/* 15: Continuous State */
  &WT_pitch_actuator_no_sat_X.Integrator1_CSTATE,/* 16: Continuous State */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), (uint8_T)SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, (boolean_T)0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    (int8_T)1, (uint8_T)0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    (int8_T)0, (uint8_T)0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 5,
    rtRootInputs, 0,
    rtRootOutputs, 0 },

  { rtBlockParameters, 10,
    rtModelParameters, 0 },

  { rtBlockStates, 2 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2782478303U,
    3097218046U,
    4193220635U,
    869372604U },
  (NULL), 0,
  (boolean_T)0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  WT_pitch_actuator_no_sat_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void WT_pitch_actuator_no_sat_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi,
    (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(WT_pitch_actuator_no_sat_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C"
{

#endif

  void WT_pitch_actuator_no_sat_host_InitializeDataMapInfo
    (WT_pitch_actuator_no_sat_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, (NULL));

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, (NULL));

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, (NULL));

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}

#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: WT_pitch_actuator_no_sat_capi.c */
