#include <iostream>

#include "matrixelement.h" 
#include "sortingofelements.h" 

using namespace inputmatrix;

int main()
{
	MatrixElement M0;
	M0.newElement(&M0);
	try
	{
		M0.showMatrix(&M0);
	}
	catch (int i)
	{
		std::cout << "caught exception:error while creating matrix" << '\n';
	}
	system("pause");
    return 0;
}
