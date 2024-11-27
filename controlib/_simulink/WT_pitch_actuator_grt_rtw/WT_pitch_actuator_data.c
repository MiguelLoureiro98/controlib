/*
 * WT_pitch_actuator_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WT_pitch_actuator".
 *
 * Model version              : 1.14
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C source code generated on : Wed Nov 27 16:25:09 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "WT_pitch_actuator.h"

/* Block parameters (default storage) */
P_WT_pitch_actuator_T WT_pitch_actuator_P = {
  /* Expression: 0.6
   * Referenced by: '<Root>/damping_ratio'
   */
  0.6,

  /* Expression: 11.11
   * Referenced by: '<Root>/natural_frequency'
   */
  11.11,

  /* Expression: 2
   * Referenced by: '<Root>/Gain2'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: deg2rad(8)
   * Referenced by: '<Root>/beta_dot_sat'
   */
  0.13962634015954636,

  /* Expression: deg2rad(-8)
   * Referenced by: '<Root>/beta_dot_sat'
   */
  -0.13962634015954636,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: deg2rad(90)
   * Referenced by: '<Root>/beta_sat'
   */
  1.5707963267948966,

  /* Expression: deg2rad(0)
   * Referenced by: '<Root>/beta_sat'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/u'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/effectiveness'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/bias'
   */
  0.0
};
