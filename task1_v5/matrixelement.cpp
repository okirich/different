#include "matrixelement.h"

inputmatrix::MatrixElement::MatrixElement()
{
	NumberOfRow = 0;
	NumberOfColumn = 0;
	element = 0;
	next = nullptr;
}

bool inputmatrix::MatrixElement::matrixInput(MatrixElement *Name)
{
	char response;
	std::cout << "index i of the element:";
	while (!(std::cin >> Name->NumberOfRow)||(Name->NumberOfRow<0))
	{
		std::cout << "rong value" << '\n';
		std::cin.clear();
		std::cin.ignore();
	}
	std::cout << "index j of the element:";
	while (!(std::cin >> Name->NumberOfColumn)||(Name->NumberOfColumn<0))
	{
		std::cout << "rong value" << '\n';
		std::cin.clear();
		std::cin.ignore();
	}
	std::cout << "value of the element:";
	while(!(std::cin >> Name->element))
	{
		std::cout << "rong value" << '\n';
		std::cin.clear();
		std::cin.ignore();
	}
	std::cout << "continue?";
	std::cin >> response;
	if (response == 'y')
		return true;
	else 
		return false;
}

int inputmatrix::MatrixElement::newElement(MatrixElement *Name)
{
	while (matrixInput(Name))
	{
		Name->next = new MatrixElement;
		Name = Name->next;
		nodeQuantity++;
	}
	return nodeQuantity;
}

double **inputmatrix::MatrixElement::createMatrix(MatrixElement *Name,double **Matrix)
{
	while (Name != nullptr)
	{
		//проблема указатель всегда в памяти 4 байта
		int sizeOfMatrix = sizeof(**Matrix);
		int sizeOfRow = sizeof(Matrix[0]);
		int sizeOfElement = sizeof(Matrix[0][0]);
		if (Name->NumberOfRow>(sizeOfMatrix/sizeOfRow)||(Name->NumberOfColumn>(sizeOfRow/sizeOfElement)))
		{
			//выделение памяти
			double **tempMatrix = new double*[Name->NumberOfRow];
			for (int i = 0; i < Name->NumberOfRow; i++)
				tempMatrix[i] = new double[Name->NumberOfColumn];
			//запись элементов уже внесенных в матрицу
			for (int i = 0; i <(sizeOfRow/sizeOfElement); i++)
				for (int j = 0; j <(sizeOfMatrix/((sizeOfMatrix/sizeOfElement)*sizeOfElement)); j++)
				{
					tempMatrix[i][j] = Matrix[i][j];
				};
			//запись элемента в матрицу
			tempMatrix[Name->NumberOfRow-1][Name->NumberOfColumn-1] = Name->element;
			//освобождение памяти занимаемой прошлым вариантом матрицы
			for (int i = 0; i < (sizeof(Matrix) / sizeof(Matrix[0][0])); i++)
			{
				delete[] Matrix[i];
			}
			Matrix = tempMatrix;
		}
		else
		{
			Matrix[Name->NumberOfRow][Name->NumberOfColumn] = Name->element;
		}
		Name = Name->next;
	}
	return Matrix;
}

void inputmatrix::MatrixElement::showMatrix(MatrixElement *Name)
{

}
