#include "includes.h"

int main()
{
	Task v11;
	std::ofstream fout("t1.csv");
	std::ofstream fout2("t2.csv");
	int n;
	std::cin >> n;
	v11.n = n+1;
	v11.h = (v11.b-v11.a) / n;
	Reduction calc(v11);
	std::vector<zy> res;
	res = calc.Calc();
	for (size_t i = 0; i < n; i++)
	{
		std::cout << res[i].z << "\t" << res[i].y << "\t\t" << v11.NNTR(res[i].z)<< "\n";
		fout << res[i].z << ";" << res[i].y << std::endl;
		fout2 << res[i].z << ";" << v11.NNTR(res[i].z) << std::endl;
	}
	return 0;
}