#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class SortAssemblage
{
public:
	SortAssemblage();
	~SortAssemblage();
	void CppTest();

	void ShowSequence();
	void BuildSequence();
	void InsertionSort();
	void SelectionSort();
	void QuickSort();
	void MergeSort();

private:
	int sequence[50];
	void atom_QuickSort(int head, int tail);
	void atom_MergeSort(int head, int tail);
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

void SortAssemblage::CppTest()
{
	cout << 7 / 2 << 7 / 3;
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

void SortAssemblage::QuickSort()
{
	this->atom_QuickSort(0, 49);
}
void SortAssemblage::atom_QuickSort(int head, int tail)
{
	if (head >= tail)
	{
		return;
	}

	int SwitchPoint = head, CheckPoint = tail;
	int standard = sequence[head];

	while (SwitchPoint < CheckPoint)
	{
		while (SwitchPoint < CheckPoint && this->sequence[CheckPoint] >= standard)
		{
			CheckPoint--;
		}
		this->sequence[SwitchPoint] = this->sequence[CheckPoint];

		while (SwitchPoint < CheckPoint && this->sequence[SwitchPoint] <= standard)
		{
			SwitchPoint++;
		}
		this->sequence[CheckPoint] = this->sequence[SwitchPoint];
	}
	this->sequence[SwitchPoint] = standard;

	this->atom_QuickSort(head, SwitchPoint - 1);
	this->atom_QuickSort(SwitchPoint + 1, tail);
}

void SortAssemblage::MergeSort()
{
	this->atom_MergeSort(0, 49);
}
void SortAssemblage::atom_MergeSort(int head, int tail)
{
	int mid = (head + tail) / 2;
	if ( (tail - head) > 1 )
	{
		this->atom_MergeSort(head, mid);
		this->atom_MergeSort(mid + 1, tail);
	}
	int testA = 0, testB = 0;
	int length = tail - head + 1;
	int InsertPointA = head, InsertPointB = mid + 1;
	int* tempBuff = new int[length];

	if (head == tail)
	{
		InsertPointB = head;
	}

	for (size_t k = 0; k < length; k++)
	{
		if (this->sequence[InsertPointA] <= this->sequence[InsertPointB])
		{
			tempBuff[k] = this->sequence[InsertPointA];
			testA = tempBuff[k];
			InsertPointA++;
			if (InsertPointA > mid)
			{
				while (k + 1 < length)
				{
					tempBuff[k + 1] = this->sequence[InsertPointB++];
					testB = tempBuff[k + 1];
					k++;
				}
				break;
			}
		}
		else if (this->sequence[InsertPointA] > this->sequence[InsertPointB])
		{
			tempBuff[k] = this->sequence[InsertPointB];
			testB = tempBuff[k];
			InsertPointB++;
			if (InsertPointB > tail)
			{
				while (k + 1 < length)
				{
					tempBuff[k + 1] = this->sequence[InsertPointA++];
					testA = tempBuff[k + 1];
					k++;
				}

				break;
			}
		}

	}
	//cout << endl << length << endl;
	for (size_t j = 0; j < length; j++)
	{
		//cout << tempBuff[j] << '\t';
		this->sequence[j + head] = tempBuff[j];

	}


	delete tempBuff;
}

int main()
{
	SortAssemblage* sortAss1 = new SortAssemblage();

	sortAss1->MergeSort();
	sortAss1->ShowSequence();

	sortAss1->BuildSequence();
	sortAss1->ShowSequence();
	sortAss1->MergeSort();
	sortAss1->ShowSequence();
	delete sortAss1;
	system("PAUSE");
	return 0;
}
