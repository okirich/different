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
	private:
		//поля данных
		int nodeQuantity=1;
		int NumberOfRow;
		int NumberOfColumn;
		double element;
		MatrixElement* next;
		//функции
		void sizeOfTemp(MatrixElement*,MatrixType*,int*,int*);
	};

	void showMatrix(MatrixType *);
	std::vector<double>* sumOfRow(MatrixType *);
	void sortingOfRow(std::vector<double>*);
}

#endif // MATRIXELEMENT

