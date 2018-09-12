#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class SortAssemblage
{
public:
	SortAssemblage();
	~SortAssemblage();

	void ShowSequence();
	void BuildSequence();
	void InsertionSort();
	void SelectionSort();

private:
	int sequence[50];
};

SortAssemblage::SortAssemblage()
{
	this->BuildSequence();
	for (size_t i = 0; i < 50; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}
		cout << this->sequence[i] << '\t';
	}
}

SortAssemblage::~SortAssemblage()
{
	cout << endl << "destruction called." << endl;
}

void SortAssemblage::ShowSequence()
{
	cout << endl;
	for (size_t i = 0; i < 50; i++)
	{
		if (i % 10 == 0)
		{
			cout << endl;
		}
		cout << this->sequence[i] << '\t';
	}
}

void SortAssemblage::BuildSequence()
{
	int seed = time(NULL);
	srand((unsigned int)seed + rand());
	for (size_t i = 0; i < 50; i++)
	{
		this->sequence[i] = rand() % 100;
	}
}

void SortAssemblage::InsertionSort()
{
	int loopViriable = 0;
	int tempBuff = 0;
	for (size_t i = 1; i < 50; i++)
	{
		if (this->sequence[i] < this->sequence[i - 1])
		{
			loopViriable = i - 1;

			tempBuff = this->sequence[i];
			this->sequence[i] = this->sequence[i - 1];
			this->sequence[i - 1] = tempBuff;

			while (loopViriable > 0)
			{
				if (this->sequence[loopViriable] < this->sequence[loopViriable - 1])
				{
					tempBuff = this->sequence[loopViriable];
					this->sequence[loopViriable] = this->sequence[loopViriable - 1];
					this->sequence[loopViriable - 1] = tempBuff;
				}
				else
				{
					break;
				}
				loopViriable--;
			}
		}

	}
}

void SortAssemblage::SelectionSort()
{
	int loopViriable = 0;
	int tempBuff = 0;
	for (size_t k = 0; k < 49; k++)
	{
		tempBuff = this->sequence[k];
		loopViriable = k;
		for (size_t j = loopViriable + 1; j < 50; j++)
		{
			if (this->sequence[j] < tempBuff)
			{
				tempBuff = this->sequence[j];
				loopViriable = j;
			}
		}
		this->sequence[loopViriable] = this->sequence[k];
		this->sequence[k] = tempBuff;
	}
}



int main()
{
	SortAssemblage* sortAss1 = new SortAssemblage();

	sortAss1->SelectionSort();
	sortAss1->ShowSequence();

	sortAss1->BuildSequence();
	sortAss1->ShowSequence();
	sortAss1->SelectionSort();
	sortAss1->ShowSequence();

	delete sortAss1;
	system("PAUSE");
	return 0;
}
