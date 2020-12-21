#include "Header.h"

int main()
{
	//srand(static_cast<unsigned int>(time(0)));
	//Checked<std::vector<int>> STLvector(10); //STL vector
	//Checked<vctor<int>> myVector(10); //My vector
	//int v;
	//std::cout << "Initialize vectors:\n";
	//for (size_t i = 0; i < myVector.size(); i++)
	//{
	//	myVector[i] = (10 - i);
	//	STLvector[i] = (100 - i);
	//}
	//std::cout << "My vector:\n";
	//for (size_t i = 0; i < myVector.size(); i++)
	//{
	//	std::cout << myVector[i] << ' ';
	//}
	//std::cout << "\nSTL vector:\n";
	//for (size_t i = 0; i < STLvector.size(); i++)
	//{
	//	std::cout << STLvector[i] << ' ';
	//}
	//std::cout << "\nTrying to take acces to my vector[15]:\n";
	//try
	//{
	//	v = myVector[15];
	//}
	//catch (const std::out_of_range&)
	//{
	//	std::cout << "We have OUT_OF_RANGE exeption!\n";
	//}
	//std::cout << "Trying to take acces to STL vector[15]:\n";
	//try
	//{
	//	v = STLvector[15];
	//}
	//catch (const std::out_of_range&)
	//{
	//	std::cout << "We have OUT_OF_RANGE exeption!\n";
	//}
	//std::cout << "\n\nstd::sort for my vector:\n";
	//std::sort(myVector.begin(), myVector.end());
	//for (size_t i = 0; i < myVector.size(); i++)
	//{
	//	std::cout << myVector[i] << ' ';

	//}
	//std::cout << "\n\nstd::sort for STL vector:\n";
	//std::sort(STLvector.begin(), STLvector.end());
	//for (size_t i = 0; i < STLvector.size(); i++)
	//{
	//	std::cout << STLvector[i] << ' ';

	//}
	//std::cout << "\n\nfill vectors with random numbers:\n";
	//for (size_t i = 0; i < myVector.size(); i++)
	//{
	//	myVector[i] = rand();
	//	STLvector[i] = rand();
	//}
	//std::cout << "\nMy:\n";
	//for (size_t i = 0; i < myVector.size(); i++)
	//{
	//	std::cout << myVector[i] << ' ';
	//}
	//std::cout << "\nSTL:\n";
	//for (size_t i = 0; i < STLvector.size(); i++)
	//{
	//	std::cout << STLvector[i] << ' ';
	//}
	//std::cout << "\n\nMy sort for my vector:\n";
	//sort(myVector.begin(), myVector.end());
	//for (size_t i = 0; i < myVector.size(); i++)
	//{
	//	std::cout << myVector[i] << ' ';
	//}
	//std::cout << "\n\nMy sort for STL vector:\n";
	//sort(STLvector.begin(), STLvector.end());
	//for (size_t i = 0; i < STLvector.size(); i++)
	//{
	//	std::cout << STLvector[i] << ' ';
	//}
	////cout << std::distance(vec.begin(),vec.end()) << ' ';
	//std::cout << '\n';
	

	std::list<int> lsInt;
	std::list<double> lsDouble;
	for (size_t i = 0; i < 10; i++)
	{
		lsInt.push_back(i);
		lsDouble.push_back(100 - i);
	}
	std::cout << *find(lsInt.begin(), lsInt.end(), 5) << '\n';
	std::cout << *find(lsDouble.begin(), lsDouble.end(), 93);

	return 0;
}