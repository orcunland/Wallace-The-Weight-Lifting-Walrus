// @AUTHOR_: orcunyilmaz
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>


// A utility function that returns maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns the maximum value that can be lift by wallace
int wallace(int wantedWeight, std::vector<int> &weightsVec, int sizeVar)
{
	int sumOfElements = std::accumulate(weightsVec.begin(), weightsVec.end(), 0);

	if ((sizeVar > 1))
	{
		if (sumOfElements < 1000)
			return sumOfElements;

		int ** K;

		K = new int*[sizeVar + 1];
		for (int i = 0; i < sizeVar + 1; i++)
			K[i] = new int[wantedWeight + 1];

		int i, w;
		std::vector<int> weights;

		// Build table K[][] in bottom up manner
		// This will give us the matrix of possible solutions
		// K is an array which allocated dynamicaly, it is indexing the possibilities
		for (i = 0; i <= sizeVar; i++)
		{
			for (w = 0; w <= wantedWeight; w++)
			{
				if (i == 0 || w == 0)
					K[i][w] = 0;
				else if (weightsVec[i - 1] <= w)
					K[i][w] = max(weightsVec[i - 1] + K[i - 1][w - weightsVec[i - 1]], K[i - 1][w]);
				else
					K[i][w] = K[i - 1][w];

				weights.push_back(K[i][w]);
			}
		}

		// Re-assigning values to tempVec, but this time they will be sorted and unique
		std::set<int> set(weights.begin(), weights.end());
		weights.assign(set.begin(), set.end());
		weights.shrink_to_fit();

		if (weights.back() >= 1001)
		{
			std::vector<int>::iterator itHigh = std::upper_bound(weights.begin(), weights.end(), 1000);
			std::vector<int>::iterator itLow = std::prev(itHigh);

			if ((*itLow == 1000) || ((*itHigh - 1000) > (1000 - *itLow)))
				return *itLow;
			else
				return *itHigh;
		}
		else
			return weights.back();
	}
	else
		return weightsVec[0];
}

int main(void)
{
	int numberOfWeights;
	std::cin >> numberOfWeights;

	std::vector<int> weights;
	int weight;

	// Assigning values to the weights vector
	for (int i = 0; i < numberOfWeights; i++)
	{
		std::cin >> weight;
		weights.push_back(weight);
	}

	int maxWeight = 1000 + *std::min_element(std::begin(weights), std::end(weights));

	// Clearing screen and showing the wanted output
	std::system("CLS");
	std::cout << wallace(maxWeight, weights, weights.size());

	getchar();
	getchar();

	return 0;
}