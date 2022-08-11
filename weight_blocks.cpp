#include <iostream>

int main ()
{
	unsigned N, R;
	std::cin >> N >> R;

	unsigned long long acc_sum = 0;

	for (unsigned i = 0; i < N; ++i)
	{
		unsigned long long W, H, D;
		std::cin >> W >> H >> D;
		acc_sum += W*H*D;
	}

	acc_sum *= R;
	std::cout << acc_sum << "\n";

	return 0;
}