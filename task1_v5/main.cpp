#include <iostream>

#include "matrixelement.h" 

using namespace inputmatrix;

int main()
{
	MatrixType Matrix(1, std::vector<double>(1,0));
	MatrixElement M0;
	M0.newElement(&M0);
	M0.createMatrix(&M0,&Matrix);
	//M0.showMatrix(&M0);
	system("pause");
    return 0;
}
