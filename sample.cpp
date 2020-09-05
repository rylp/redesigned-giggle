//Code and Logic is exactly same as unbounded kpsack, inputs and size & N need to be understood

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rod_cutting(vector<int>& length, vector<int>& price, int size, int N)
{
	// size <---> n <---> i 
	// N <---> W/sum <---> j 
	
	///MADE SOME CHANGES

	///MADE MORE CHANGES

	//MAKING CHANGES AGAIN


	int t[100][100]; //t[size+1][N+1]

	//INIT

	for (int i = 0; i < (size + 1); i++)
	{
		for (int j = 0; j < (N + 1); j++)
		{
			if (i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	//SUBPROB SOLN

	for (int i = 1; i < (size + 1); i++)
	{
		for (int j = 1; j < (N + 1); j++)
		{
			if (length[i - 1] <= j)
			{
				t[i][j] = max( price[i - 1] + t[i][j - length[i - 1]] , //selected 
									t[i - 1][j]); //Not selected
			}
			else
			{
				t[i][j] = t[i - 1][j];
			}
		}
	}

	return t[size][N];
}


int main()
{
	int N = 0; //DENOTES Length of the Rod to be cut
	cout << "Enter length of the rod" << endl;
	cin >> N;

	int size = 0; //DENOTES size of the array fro which prices and lengths are given
	cout << "Enter size of the length & prices arrayy" << endl;
	cin >> size;
	// N may/may not be equal to (=) size

	vector<int>length(size + 1);
	vector<int>price(size + 1);

	cout << "Enter Length Array values:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> length[i];
	}
	cout << "Enter Price Array values:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> price[i];
	}

	int profit = rod_cutting(length, price, size, N);

	cout << "Max Profit : " << profit << endl;

	return 0;
}