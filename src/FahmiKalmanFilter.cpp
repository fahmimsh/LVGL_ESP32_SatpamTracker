#include "Arduino.h"
#include "FahmiKalmanFilter.h"
#include <math.h> 
//referensi
//https://github.com/fahmimsh/quadcopter-stm32f407/blob/main/Core/Src/Kalman.c

FahmiKalmanFilter::FahmiKalmanFilter(float mea_e, float est_e, float q)
{
  _err_measure=mea_e;
  _err_estimate=est_e;
  _q = q;
}

void FahmiKalmanFilter::setMeasurementError(float mea_e)
{
  _err_measure=mea_e;
}

void FahmiKalmanFilter::setEstimateError(float est_e)
{
  _err_estimate=est_e;
}

void FahmiKalmanFilter::setProcessNoise(float q)
{
  _q=q;
}

float FahmiKalmanFilter::updateEstimate(float mea)
{
  _kalman_gain = _err_estimate/(_err_estimate + _err_measure);
  _current_estimate = _last_estimate + _kalman_gain * (mea - _last_estimate);
  _err_estimate =  (1.0 - _kalman_gain)*_err_estimate + fabs(_last_estimate-_current_estimate)*_q;
  _last_estimate=_current_estimate;

  return _current_estimate;
}

float FahmiKalmanFilter::getKalmanGain() {
  return _kalman_gain;
}

float FahmiKalmanFilter::getEstimateError() {
  return _err_estimate;
}
