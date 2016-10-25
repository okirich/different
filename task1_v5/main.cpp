#include <iostream>

#include "matrixelement.h" 

using namespace inputmatrix;

int main()
{
	MatrixType Matrix(1, std::vector<double>(1,0));
	MatrixElement M0;
	M0.newElement(&M0);
	MatrixType *output = M0.createMatrix(&M0, &Matrix);
	std::cout << "sorurce matrix" << '\n';
	showMatrix(output);
	std::vector<double>* row=sumOfRow(output);
	sortingOfRow(row);
	std::cout << "modified matrix" << '\n';
	showMatrix(output);
	system("pause");
    return 0;
}
