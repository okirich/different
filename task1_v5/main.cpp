#include <iostream>

#include "matrixelement.h" 
#include "sortingofelements.h" 

using namespace inputmatrix;

int main()
{
	double **Matrix = new double *[1];
	Matrix[0] = new double[1];
	Matrix[0][0] = 0;
	MatrixElement M0;
	M0.newElement(&M0);
	M0.createMatrix(&M0,Matrix);
	//M0.showMatrix(&M0);
	system("pause");
    return 0;
}
