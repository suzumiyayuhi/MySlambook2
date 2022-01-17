#include <iostream>
#include <eigen3/Eigen/Core>

using namespace std;
using namespace Eigen;

int main(int argc, char *argv[])
{
	Matrix<int, 5, 5> matrix_5_5;
	matrix_5_5 << 1, 2, 3, 4, 5, 0, 9, 8, 7, 6, 9, 8, 7, 6, 5, 1, 0, 5, 7, 3, 1, 2, 3, 4, 5;
	cout << matrix_5_5 << "\n\n\n";

	Matrix<int, 3, 3> matrix_3_3;
	matrix_3_3 = Matrix3i::Zero();
	cout << matrix_3_3 << "\n\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_3_3(i, j) = matrix_5_5(i, matrix_5_5.cols() - 3 + j);
		}
	}
	cout << matrix_3_3 << "\n\n\n";
	return 0;
}