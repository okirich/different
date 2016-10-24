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

MatrixType* inputmatrix::MatrixElement::createMatrix(MatrixElement *Name, MatrixType *Matrix)
{
	while (Name != nullptr)
	{

		// в матрице нет соотв строки/столбца

		if (Name->NumberOfRow>Matrix->size()-1||Name->NumberOfColumn>Matrix->at(0).size()-1)
		{
			//выделение памяти

			MatrixType tempMatrix(Name->NumberOfRow, std::vector<double>(Name->NumberOfColumn, 0));

			//копирование элементов из старой матрицы в новую

			for (int i = 0; i < Matrix->size(); i++)
				for (int j = 0; j < Matrix->at(0).size(); j++)
				{
					tempMatrix[i][j] = Matrix->at(i).at(j);
				}
			
			//копирование значения элемента в матрицу
			tempMatrix[Name->NumberOfRow-1][Name->NumberOfColumn-1] = Name->element;

			//отчищение памяти

			Matrix->clear();

			//новое значение матрицы 

			Matrix = &tempMatrix; //проблема!

		}
		else
		{
			Matrix->at(Name->NumberOfRow).at(Name->NumberOfColumn) = Name->element;
		}
	}
	return Matrix;
}

