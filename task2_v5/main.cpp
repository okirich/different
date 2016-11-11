#include "konhoida.h"

int dialog(const char *msgs[], int N)
{
	int rc;
	int i;
	do {
		for (i = 0; i < N; ++i) // вывод списка альтернатив
			std::cout<<msgs[i]<<'\n';
		std::cout<<"Make your choice: --> "<<'\n';
		std::cin>>rc; // ввод номера альтернативы
	} while (rc < 0 || rc >= N);
	return rc;
}

void D_SetA(Prog2::Konhoida *Name) 
{
	double a;
	std::cout << "enter the value of a" << '\n';
	std::cin >> a;
	Name->setParamA(a);
}

void D_SetL(Prog2::Konhoida *Name)
{
	double l;
	std::cout << "enter the value of l" << '\n';
	std::cin >> l;
	Name->setParamL(l);
}

void D_GetA(Prog2::Konhoida *Name)
{
	std::cout << "the value of a=" << Name->getParamA()<< '\n';
}

void D_GetL(Prog2::Konhoida *Name)
{
	std::cout << "the value of l=" << Name->getParamL()<<'\n';
}

void D_Decart(Prog2::Konhoida *Name)
{
	double x;
	std::cout << "enter the value of x" << '\n';
	std::cin >> x;
	std::cout << "y=" << Name->decart(x) << '\n';
	std::cout << "-y=" << -1*Name->decart(x) << '\n';
}

void D_Polar(Prog2::Konhoida *Name)
{
	double fi;
	std::cout << "enter the value of fi" << '\n';
	std::cin >> fi;
	std::cout << "ro=" << Name->polar(fi) << '\n';
}

void D_Radius(Prog2::Konhoida *Name)
{
	char ch;
	std::cout << "Rc=c; Ro=o:" << '\n';
	std::cin >> ch;
	std::cout << "radius of curvature:" << Name->radiusOfCurvature(ch) << '\n';
}

void D_LoopArea(Prog2::Konhoida *Name)
{
	std::cout << "loop area is:" << Name->loopArea() <<'\n';
}

void D_Inflections(Prog2::Konhoida *Name)
{
	std::cout << "Points of inflection:" << '\n';
	std::cout << "x=" << Name->inflectionOfFunction().x << '\n';
	std::cout << "y=" << Name->inflectionOfFunction().y << '\n';
}

void(*fptr[])(Prog2::Konhoida *) = {D_SetA,D_SetL,D_GetA,D_GetL,D_Decart,D_Polar,D_Radius,D_LoopArea,D_Inflections};

int main()
{
	int rc;
	Prog2::Konhoida n1(0, 0);  
	const char *Msgs[] = { "0.Set a","1.Set l","2.Get A","3.Get L","4.Decart(y)","5.Polar(ro)","6.Radius of curvature","7.Loop area","8.Inflections of function","9.exit" };
	while ((rc=dialog(Msgs, 10)) != 9)
		try
	{
		fptr[rc](&n1);
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << std::endl;
	}
		
	return 0;
}
