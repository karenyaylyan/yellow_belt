#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	if (n <= 0)
	{
		std::cout << 0 << "\n";
		return 0;
	}
	long long sum = 0;

	std::vector<long long> temperatures(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> temperatures[i];
		sum += temperatures[i];
	}
	long long avg = sum/n;

	std::vector<int> above_average_temperatures;
	
	for (int i = 0; i < n; ++i)
	{
		if (temperatures[i] > avg)
		{
			above_average_temperatures.push_back(i);
		}
	}

	std::cout << above_average_temperatures.size() << "\n";
	for (const auto& x : above_average_temperatures)
	{
		std::cout << x << ' ';
	}
	std::cout << "\n";

	
}