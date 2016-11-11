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
		Konhoida() :a(0), l(0) {} //������ �����������
		Konhoida(double, double); //�����������
		void setParamA(double); //set'�� a
		void setParamL(double); //set'�� l
		double getParamA() const; //get'�� a
		double getParamL() const; //get'�� l
		double decart(double) const; //���������� � � ���������� ������� �� �(� �,l)
		double polar(double) const; //���������� �������� ������ � ����������� �� ���� ��� ����� ��������
		double radiusOfCurvature(char) const; //���������� ������ �������� � ����������� ������ ��������
		double loopArea() const; //���������� ������� ����� ��������
		Point inflectionOfFunction() const; //���������� ����� �������� ��������
	private:
		inline bool l_is_greater_then_a() const 
		{ 
			if (!(l > a))
				return false; 
			return true;
		};
		double a; //���������� �� ������ �� ��������� 
		double l; //������� �������� �������������� ����� ����� ��������
	};

}