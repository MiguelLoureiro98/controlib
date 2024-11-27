/*
 * WT_pitch_actuator_no_sat.c
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

#include "WT_pitch_actuator_no_sat.h"
#include "WT_pitch_actuator_no_sat_private.h"
#include "rt_logging_mmi.h"
#include "WT_pitch_actuator_no_sat_capi.h"

/* Block signals (default storage) */
B_WT_pitch_actuator_no_sat_T WT_pitch_actuator_no_sat_B;

/* Continuous states */
X_WT_pitch_actuator_no_sat_T WT_pitch_actuator_no_sat_X;

/* Disabled State Vector */
XDis_WT_pitch_actuator_no_sat_T WT_pitch_actuator_no_sat_XDis;

/* Real-time model */
static RT_MODEL_WT_pitch_actuator_no_T WT_pitch_actuator_no_sat_M_;
RT_MODEL_WT_pitch_actuator_no_T *const WT_pitch_actuator_no_sat_M =
  &WT_pitch_actuator_no_sat_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  WT_pitch_actuator_no_sat_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  WT_pitch_actuator_no_sat_step();
  WT_pitch_actuator_no_sat_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  WT_pitch_actuator_no_sat_step();
  WT_pitch_actuator_no_sat_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void WT_pitch_actuator_no_sat_step(void)
{
  if (rtmIsMajorTimeStep(WT_pitch_actuator_no_sat_M)) {
    /* set solver stop time */
    if (!(WT_pitch_actuator_no_sat_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&WT_pitch_actuator_no_sat_M->solverInfo,
                            ((WT_pitch_actuator_no_sat_M->Timing.clockTickH0 + 1)
        * WT_pitch_actuator_no_sat_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&WT_pitch_actuator_no_sat_M->solverInfo,
                            ((WT_pitch_actuator_no_sat_M->Timing.clockTick0 + 1)
        * WT_pitch_actuator_no_sat_M->Timing.stepSize0 +
        WT_pitch_actuator_no_sat_M->Timing.clockTickH0 *
        WT_pitch_actuator_no_sat_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(WT_pitch_actuator_no_sat_M)) {
    WT_pitch_actuator_no_sat_M->Timing.t[0] = rtsiGetT
      (&WT_pitch_actuator_no_sat_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(WT_pitch_actuator_no_sat_M)) {
    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/damping_ratio'
     *  Constant: '<Root>/natural_frequency'
     *  Product: '<Root>/Product3'
     */
    WT_pitch_actuator_no_sat_B.Gain2 =
      WT_pitch_actuator_no_sat_P.damping_ratio_Value *
      WT_pitch_actuator_no_sat_P.natural_frequency_Value *
      WT_pitch_actuator_no_sat_P.Gain2_Gain;

    /* Math: '<Root>/Square' incorporates:
     *  Constant: '<Root>/natural_frequency'
     */
    WT_pitch_actuator_no_sat_B.Square =
      WT_pitch_actuator_no_sat_P.natural_frequency_Value *
      WT_pitch_actuator_no_sat_P.natural_frequency_Value;

    /* Product: '<Root>/Product' incorporates:
     *  Constant: '<Root>/bias'
     *  Constant: '<Root>/u'
     *  Gain: '<Root>/effectiveness'
     *  Sum: '<Root>/Sum'
     */
    WT_pitch_actuator_no_sat_B.Product =
      (WT_pitch_actuator_no_sat_P.effectiveness_Gain *
       WT_pitch_actuator_no_sat_P.u_Value +
       WT_pitch_actuator_no_sat_P.bias_Value) *
      WT_pitch_actuator_no_sat_B.Square;
  }

  /* Integrator: '<Root>/Integrator' */
  WT_pitch_actuator_no_sat_B.beta_dot =
    WT_pitch_actuator_no_sat_X.Integrator_CSTATE;

  /* Sum: '<Root>/Add' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Integrator: '<Root>/Integrator1'
   *  Product: '<Root>/Product1'
   *  Product: '<Root>/Product2'
   */
  WT_pitch_actuator_no_sat_B.beta_dot_dot = (WT_pitch_actuator_no_sat_B.Product
    - WT_pitch_actuator_no_sat_B.Gain2 * WT_pitch_actuator_no_sat_B.beta_dot *
    WT_pitch_actuator_no_sat_P.Gain1_Gain) - WT_pitch_actuator_no_sat_B.Square *
    WT_pitch_actuator_no_sat_X.Integrator1_CSTATE *
    WT_pitch_actuator_no_sat_P.Gain_Gain;
  if (rtmIsMajorTimeStep(WT_pitch_actuator_no_sat_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(WT_pitch_actuator_no_sat_M->rtwLogInfo,
                        (WT_pitch_actuator_no_sat_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(WT_pitch_actuator_no_sat_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(WT_pitch_actuator_no_sat_M)!=-1) &&
          !((rtmGetTFinal(WT_pitch_actuator_no_sat_M)-
             (((WT_pitch_actuator_no_sat_M->Timing.clockTick1+
                WT_pitch_actuator_no_sat_M->Timing.clockTickH1* 4294967296.0)) *
              0.001)) > (((WT_pitch_actuator_no_sat_M->Timing.clockTick1+
                           WT_pitch_actuator_no_sat_M->Timing.clockTickH1*
                           4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(WT_pitch_actuator_no_sat_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&WT_pitch_actuator_no_sat_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++WT_pitch_actuator_no_sat_M->Timing.clockTick0)) {
      ++WT_pitch_actuator_no_sat_M->Timing.clockTickH0;
    }

    WT_pitch_actuator_no_sat_M->Timing.t[0] = rtsiGetSolverStopTime
      (&WT_pitch_actuator_no_sat_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      WT_pitch_actuator_no_sat_M->Timing.clockTick1++;
      if (!WT_pitch_actuator_no_sat_M->Timing.clockTick1) {
        WT_pitch_actuator_no_sat_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void WT_pitch_actuator_no_sat_derivatives(void)
{
  XDot_WT_pitch_actuator_no_sat_T *_rtXdot;
  _rtXdot = ((XDot_WT_pitch_actuator_no_sat_T *)
             WT_pitch_actuator_no_sat_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = WT_pitch_actuator_no_sat_B.beta_dot_dot;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = WT_pitch_actuator_no_sat_B.beta_dot;
}

/* Model initialize function */
void WT_pitch_actuator_no_sat_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)WT_pitch_actuator_no_sat_M, 0,
                sizeof(RT_MODEL_WT_pitch_actuator_no_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
                          &WT_pitch_actuator_no_sat_M->Timing.simTimeStep);
    rtsiSetTPtr(&WT_pitch_actuator_no_sat_M->solverInfo, &rtmGetTPtr
                (WT_pitch_actuator_no_sat_M));
    rtsiSetStepSizePtr(&WT_pitch_actuator_no_sat_M->solverInfo,
                       &WT_pitch_actuator_no_sat_M->Timing.stepSize0);
    rtsiSetdXPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
                 &WT_pitch_actuator_no_sat_M->derivs);
    rtsiSetContStatesPtr(&WT_pitch_actuator_no_sat_M->solverInfo, (real_T **)
                         &WT_pitch_actuator_no_sat_M->contStates);
    rtsiSetNumContStatesPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
      &WT_pitch_actuator_no_sat_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
      &WT_pitch_actuator_no_sat_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
      &WT_pitch_actuator_no_sat_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
      &WT_pitch_actuator_no_sat_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
      (boolean_T**) &WT_pitch_actuator_no_sat_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
                          (&rtmGetErrorStatus(WT_pitch_actuator_no_sat_M)));
    rtsiSetRTModelPtr(&WT_pitch_actuator_no_sat_M->solverInfo,
                      WT_pitch_actuator_no_sat_M);
  }

  rtsiSetSimTimeStep(&WT_pitch_actuator_no_sat_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&WT_pitch_actuator_no_sat_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&WT_pitch_actuator_no_sat_M->solverInfo, false);
  WT_pitch_actuator_no_sat_M->intgData.y = WT_pitch_actuator_no_sat_M->odeY;
  WT_pitch_actuator_no_sat_M->intgData.f[0] = WT_pitch_actuator_no_sat_M->odeF[0];
  WT_pitch_actuator_no_sat_M->intgData.f[1] = WT_pitch_actuator_no_sat_M->odeF[1];
  WT_pitch_actuator_no_sat_M->intgData.f[2] = WT_pitch_actuator_no_sat_M->odeF[2];
  WT_pitch_actuator_no_sat_M->contStates = ((X_WT_pitch_actuator_no_sat_T *)
    &WT_pitch_actuator_no_sat_X);
  WT_pitch_actuator_no_sat_M->contStateDisabled =
    ((XDis_WT_pitch_actuator_no_sat_T *) &WT_pitch_actuator_no_sat_XDis);
  WT_pitch_actuator_no_sat_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&WT_pitch_actuator_no_sat_M->solverInfo, (void *)
                    &WT_pitch_actuator_no_sat_M->intgData);
  rtsiSetSolverName(&WT_pitch_actuator_no_sat_M->solverInfo,"ode3");
  rtmSetTPtr(WT_pitch_actuator_no_sat_M,
             &WT_pitch_actuator_no_sat_M->Timing.tArray[0]);
  rtmSetTFinal(WT_pitch_actuator_no_sat_M, 10.0);
  WT_pitch_actuator_no_sat_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    WT_pitch_actuator_no_sat_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(WT_pitch_actuator_no_sat_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(WT_pitch_actuator_no_sat_M->rtwLogInfo, (NULL));
    rtliSetLogT(WT_pitch_actuator_no_sat_M->rtwLogInfo, "tout");
    rtliSetLogX(WT_pitch_actuator_no_sat_M->rtwLogInfo, "");
    rtliSetLogXFinal(WT_pitch_actuator_no_sat_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(WT_pitch_actuator_no_sat_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(WT_pitch_actuator_no_sat_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(WT_pitch_actuator_no_sat_M->rtwLogInfo, 0);
    rtliSetLogDecimation(WT_pitch_actuator_no_sat_M->rtwLogInfo, 1);
    rtliSetLogY(WT_pitch_actuator_no_sat_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(WT_pitch_actuator_no_sat_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(WT_pitch_actuator_no_sat_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &WT_pitch_actuator_no_sat_B), 0,
                sizeof(B_WT_pitch_actuator_no_sat_T));

  /* states (continuous) */
  {
    (void) memset((void *)&WT_pitch_actuator_no_sat_X, 0,
                  sizeof(X_WT_pitch_actuator_no_sat_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&WT_pitch_actuator_no_sat_XDis, 0,
                  sizeof(XDis_WT_pitch_actuator_no_sat_T));
  }

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  WT_pitch_actuator_no_sat_InitializeDataMapInfo();

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(WT_pitch_actuator_no_sat_M->rtwLogInfo, 0.0,
    rtmGetTFinal(WT_pitch_actuator_no_sat_M),
    WT_pitch_actuator_no_sat_M->Timing.stepSize0, (&rtmGetErrorStatus
    (WT_pitch_actuator_no_sat_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  WT_pitch_actuator_no_sat_X.Integrator_CSTATE =
    WT_pitch_actuator_no_sat_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  WT_pitch_actuator_no_sat_X.Integrator1_CSTATE =
    WT_pitch_actuator_no_sat_P.Integrator1_IC;
}

/* Model terminate function */
void WT_pitch_actuator_no_sat_terminate(void)
{
  /* (no terminate code required) */
}
