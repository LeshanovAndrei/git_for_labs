#pragma once

//[1; 3]
//x(x-1)y''-xy'+y=0
//y'(1)=2
//2y'(2)-y(2)=1

//точное: x+xln(x)+1

class Task
{
public:
	double p(double x) { return 1 / (x - 1); }
	double q(double x) { return 1 / (x*(x - 1)); }
	double NNTR(double x) { return (1.0 / 3.0) * (5 * x + x * log(x) - 1); }
	double a = 1, b = 2;
	double alpha0 = 0, alpha1 = 1;
	double beta0 = -1, beta1 = 2;
	double A = 2, B = 1;
	int n;
	double h;
	double u_a = 1, u_a_ = 0;
	double v_a = 0, v_a_ = 2;
};