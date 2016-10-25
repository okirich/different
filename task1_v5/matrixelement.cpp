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

		if (Name->NumberOfRow>Matrix->size()||Name->NumberOfColumn>Matrix->at(0).size())
		{

			//создание временной копии матрицы

			//определяем размеры временной матрицы
			int tempQrow;
			int tempQcolumn;

			sizeOfTemp(Name, Matrix, &tempQrow, &tempQcolumn);

			MatrixType* tempMatrix=new MatrixType(tempQrow, std::vector<double>(tempQcolumn, 0));

			//копирование элементов из старой матрицы в новую

			for (int i = 0; i < Matrix->size(); i++)
				for (int j = 0; j < Matrix->at(0).size(); j++)
				{
					tempMatrix->at(i).at(j) = Matrix->at(i).at(j);
				}
			
			//копирование значения элемента в копию матрицы

			tempMatrix->at(Name->NumberOfRow-1).at(Name->NumberOfColumn-1) = Name->element;

			//отчищение памяти

			Matrix->clear();

			//новое значение матрицы 

			Matrix = tempMatrix;  

		}
		else
		{
			Matrix->at(Name->NumberOfRow-1).at(Name->NumberOfColumn-1) = Name->element;
		}

		//берем следующий введенный элемент

		Name = Name->next;
	}
	return Matrix;
}

void inputmatrix::showMatrix(MatrixType* Matrix) 
{
	for (MatrixType::iterator it=Matrix->begin(); it != Matrix->end(); ++it)
	{
		//где то здесь вызов подсчета суммы
		for (std::vector<double>::iterator it2 = (*it).begin();it2 != (*it).end(); ++it2)
		{
			std::cout << *it2 << ' ';
		}
		std::cout << '\n';

	}
}

void inputmatrix::MatrixElement::sizeOfTemp(MatrixElement* Name,MatrixType* Matrix,int* tempQrow,int* tempQcolumn)
{
	if ((Name->NumberOfRow>Matrix->size()) && (Name->NumberOfColumn>Matrix->at(0).size())) //рядов и столбцов в новой больше чем в предыдущей
	{
		*tempQrow = Name->NumberOfRow;
		*tempQcolumn = Name->NumberOfColumn;
	}
	else if (Name->NumberOfRow > Matrix->size()) //рядов в новой больше чем в текущей
	{
		*tempQrow = Name->NumberOfRow;
		*tempQcolumn = Matrix->at(0).size();
	}
	else //столбцов в новой больше чем в текущей
	{
		*tempQrow = Matrix->size();
		*tempQcolumn =Name->NumberOfColumn ;
	}
}


