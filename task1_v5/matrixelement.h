#ifndef MATRIXELEMENT
#define MATRIXELEMENT

#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> MatrixType;

namespace inputmatrix
{
	class MatrixElement //класс элемента разреженной матрицы 
	{
	public:
		MatrixElement();
		bool matrixInput(MatrixElement *);
		int newElement(MatrixElement *);
		MatrixType* createMatrix(MatrixElement *, MatrixType *);
		//void showMatrix(MatrixElement *);
	private:
		int nodeQuantity=1;
		int NumberOfRow;
		int NumberOfColumn;
		double element;
		MatrixElement* next;
		//double sumOfRow();
		//void sortingOfRow
	};
}

#endif // MATRIXELEMENT

