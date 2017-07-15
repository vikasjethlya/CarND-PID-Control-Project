#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
	this->Kp = Kp_ ;
	this->Ki = Ki_ ;
	this->Kd = Kd_ ;

	this->d_error = 0;
	this->i_error = 0;
	this->p_error = 0;
}

void PID::UpdateError(double cte)
{
	d_error = cte - p_error ;
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() {

	double total_err = 0.0;

	total_err = -Kp * p_error - Ki * i_error - Kd * d_error;

	return total_err;
}

