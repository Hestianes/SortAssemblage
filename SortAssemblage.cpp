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
	cout << "destruction called." << endl;
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

int main()
{
	SortAssemblage* sortAss1 = new SortAssemblage();

	sortAss1->InsertionSort();
	sortAss1->ShowSequence();

	sortAss1->BuildSequence();
	sortAss1->ShowSequence();
	sortAss1->InsertionSort();
	sortAss1->ShowSequence();

	system("PAUSE");

	return 0;
}
