#pragma once


struct zy
{
	double z;
	double y;
};

class R
{
public:
	double U(double x, double y, double z)
	{
		return z/(x+1) - y/(x*(x+1)); //œŒÃ≈Õﬂ“‹!
	}
	zy method(double x, double y, double z, double h)
	{
		double q[4], k[4];
		q[0] = U(x, y, z);
		k[0] = z;
		q[1] = U(x + h / 2, y + k[0] * h / 2, z + q[0] * h / 2);
		k[1] = z + q[0] * h / 2;
		q[2] = U(x + h / 2, y + k[1] * h / 2, z + q[0] * h / 2);
		k[2] = z + q[1] * h / 2;
		q[3] = U(x + h, y + k[2] * h, z + q[2] * h);
		k[3] = z + q[2] * h;
		zy v;
		v.z = z + (q[0] + 2 * q[1] + 2 * q[2] + q[3]) * h / 6;
		v.y = y + (k[0] + 2 * k[1] + 2 * k[2] + k[3]) * h / 6;
		return v;
	}

};

class Reduction
{
public:
	Reduction(Task v) : task(v) {}
	std::vector<zy> F(double x_0, double y_0, double z_0)
	{
		std::vector<zy> res;
		double x, y, z;
		x = x_0;
		y = y_0;
		z = z_0;
		for (size_t i = 0; i < task.n; i++)
		{
			res.push_back(r.method(x, y, z, task.h));
			x = x + task.h;
			y = res[i].y;
			z = res[i].z;
		}
		return res;
	}
	std::vector<zy> Calc()
	{
		std::vector<zy> ZU;
		std::vector<zy> ZV;
		std::vector<zy> XY;
		ZU = F(task.a, task.u_a, task.u_a_);
		ZV = F(task.a, task.v_a, task.v_a_);
		double x = task.a;
		double C = (task.B - (task.beta0 * ZV[ZV.size() - 1].y + task.beta1 * ZV[ZV.size() - 1].z)) / (task.beta0 * ZU[ZU.size() - 1].y + task.beta1 * ZU[ZU.size() - 1].z);
		for (size_t i = 0; i < task.n; i++)
		{
			XY.push_back(*new zy({x,C* ZU[i].y + ZV[i].y }));
			x = x + task.h;
		}
		return XY;
	}
private:

	Task task;
	R r;
};