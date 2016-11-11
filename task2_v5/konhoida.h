#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

namespace Prog2 {

	struct Point
	{
		double x, y;
	};

	class Konhoida
	{
	public:
		Konhoida() :a(0), l(0) {} //пустой конструктор
		Konhoida(double, double); //конструктор
		void setParamA(double); //set'ер a
		void setParamL(double); //set'ер l
		double getParamA() const; //get'ер a
		double getParamL() const; //get'ер l
		double decart(double) const; //возвращает у в декартовой системе от х(и а,l)
		double polar(double) const; //возвращает полярный радиус в зависимости от угла для точки конхоиды
		double radiusOfCurvature(char) const; //возвращает радиус кривизны в характерных точках конхоиды
		double loopArea() const; //возвращает площадь петли конхоиды
		Point inflectionOfFunction() const; //возвращает точки перегиба конхоиды
	private:
		inline bool l_is_greater_then_a() const 
		{ 
			if (!(l > a))
				return false; 
			return true;
		};
		double a; //расстояние от полюса до основания 
		double l; //отрезок задающий геометрическое место точек конхоиды
	};

}