#include "konhoida.h"

Prog2::Konhoida::Konhoida(double A, double L)
{
	a = A;
	l = L;
}

void Prog2::Konhoida::setParamA(double A) 
{
	a = A;
}

void Prog2::Konhoida::setParamL(double L)
{
	l = L;
}

double Prog2::Konhoida::getParamA() const
{
	return a;
}

double Prog2::Konhoida::getParamL() const
{
	return l;
}

double Prog2::Konhoida::decart(double x) const
{
	if ((x==a)||(x<(a-l))||(x>(l+a)))
		throw std::exception("invalid x");
	double y = sqrt( (l*l*x*x) / ((x - a)*(x - a)) - x*x );
	return y;
}

double Prog2::Konhoida::polar(double fi) const
{
	double x = cos((fi*M_PI )/ 180.0);
	if (x==6.1232339957367660e-17)
		throw std::exception("invalid fi");
	double ro = a/x+l;
	return ro;
}

double Prog2::Konhoida::radiusOfCurvature(char ch) const
{
	double Ra,Rc,Ro;
	if (!l_is_greater_then_a())
	{
		Rc = 0;
		Ro = 0;
	}
	else
	{
		Rc = pow((l - a), 2) / l;
		Ro = ((l*sqrt(l*l - a*a)) / (2 * a));
	}
	Ra = pow((l + a), 2) / l;
	if (ch=='o')
	{
		return Ro;
	}
	else if (ch=='c')
	{
		return Rc;
	}
	else
	return Ra;
}

double Prog2::Konhoida::loopArea() const
{
	if (l_is_greater_then_a())
	{
		double S = a*(sqrt(l*l - a*a)) - 2 * a*l*log((l + sqrt(l*l - a*a))/ a) + l*l*acos(a / l);
		return S;
	}
	else
	{
		return 0;
	}
}

Prog2::Point Prog2::Konhoida::inflectionOfFunction() const
{
	 Prog2::Point *ptr = new Prog2::Point;
	 double Wpow3a,w1,x1,y1;
	 double Wpow3b, w2, x2, y2;
	 double p, q, r, D;
	 r = 1.0 / 3.0;
	 p = 3 * a*a;
	 q = 2 * a*(a*a - l*l);
	 D = sqrt(q*q + (4 * pow(p, 3)) / 27);
	 Wpow3a = (-q + D) / 2;
	 Wpow3b = (-q - D) / 2;
	if (Wpow3a<0)
	{
		w2 = pow(Wpow3b, r);
		x2 = pow(w2, r);
		ptr->x = x2;
		ptr->y = decart(x2);
		return *ptr;
	}
	else
	{
		w1 = pow(Wpow3a, r);
		x1 = pow(w1, r);
		ptr->x = x1;
		ptr->y = decart(x1);
		return *ptr;
	}
}
