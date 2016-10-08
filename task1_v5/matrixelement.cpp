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

void inputmatrix::MatrixElement::showMatrix(MatrixElement *Name)
{
	int CurrentRow=Name->NumberOfRow;
	int CurrentColumn = -1;
	for (int i = 0; i < nodeQuantity; i++)
	{
		if (CurrentRow==Name->NumberOfRow)
		{
			if ((CurrentColumn==Name->NumberOfColumn)||(Name->NumberOfColumn<CurrentColumn))
			{
				throw 1;
			}
			std::cout.width(20);
			std::cout.setf(_IOSleft);
			std::cout << Name->element<<' ';
			CurrentColumn = Name->NumberOfColumn;
		}
		else
		{
			if (Name->NumberOfRow<CurrentRow)
			{
				throw 1;
			}
			std::cout << '\n';
			std::cout.width(20);
			std::cout.setf(_IOSleft);
			std::cout << Name->element << ' ';
			CurrentRow = Name->NumberOfRow;
			CurrentColumn = -1;
		}
		Name = Name->next;
	}
}

double inputmatrix::MatrixElement::SumOfRow()
{
	return 0.0;
}
