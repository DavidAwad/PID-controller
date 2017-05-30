#include "PID.h"

#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
  the tau constants and the errors
  double p_error;
  double i_error;
  double d_error;
*/

double total_cte = 0.0;
double prev_cte = 0.0;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  // proportional error
  p_error = - Kp * cte;

  // integral error with sum of all error so far
  i_error = - Ki * total_cte;

  // differential error
  d_error = - Kd * (cte - prev_cte);

  // add to our total error so far
  total_cte += cte;
  // update the previous error pointer
  prev_cte = cte;
}

double PID::TotalError() {
  // return proportional + integral + differential
	return p_error + i_error + d_error;
}

