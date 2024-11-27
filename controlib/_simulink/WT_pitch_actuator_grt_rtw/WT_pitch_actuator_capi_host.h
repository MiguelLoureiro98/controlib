#ifndef WT_pitch_actuator_cap_host_h__
#define WT_pitch_actuator_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} WT_pitch_actuator_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C"
{

#endif

  void WT_pitch_actuator_host_InitializeDataMapInfo
    (WT_pitch_actuator_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}

#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* WT_pitch_actuator_cap_host_h__ */

/* EOF: WT_pitch_actuator_capi_host.h */
