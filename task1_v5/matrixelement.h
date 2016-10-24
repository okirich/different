#ifndef MATRIXELEMENT
#define MATRIXELEMENT

#include <iostream>

namespace inputmatrix
{
	class MatrixElement //класс элемента разреженной матрицы 
	{
	public:
		MatrixElement();
		bool matrixInput(MatrixElement *);
		int newElement(MatrixElement *);
		double** createMatrix(MatrixElement *,double **Matrix);
		void showMatrix(MatrixElement *);
	private:
		int nodeQuantity=1;
		int NumberOfRow;
		int NumberOfColumn;
		double element;
		MatrixElement* next;
		double SumOfRow();
	};
}

#endif // MATRIXELEMENT

