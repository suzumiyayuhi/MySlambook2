#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int args, char *argv[])
{
	Matrix3f A;
	Vector3f b, x;
	A << 1, 2, 3, 4, 5, 6, 7, 8, 10;
	b << 3, 3, 4;
	//Method 1
	/*
	x = A.colPivHouseholderQr().solve(b);
	cout << x << "\n\n";
	*/
	//Method 2
	/**/
	Matrix3f A_ = A;
	Vector3f b_ = b;
	cout << A_ << "\n\n";
	cout << b_ << "\n\n";
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 2 - k; i++)
		{
			float tem_s = A_(i + k + 1, k) / A_(k, k);
			for (int j = k; j < 3; j++)
			{
				A_(i + k + 1, j) = A_(i + k + 1, j) - tem_s * A_(k, j);
			}
			b_(i + k + 1) = b_(i + k + 1) - tem_s * b_(k);
		}
	}

	float tem_s = A_(1, 2) / A_(2, 2);
	A_(1, 2) = 0;
	b_(1) = b_(1) - b_(2) * tem_s;

	tem_s = A_(0, 2) / A_(2, 2);
	A_(0, 2) = 0;
	b_(0) = b_(0) - b_(2) * tem_s;

	tem_s = A_(0, 1) / A_(1, 1);
	A_(0, 1) = 0;
	b_(0) = b_(0) - b_(1) * tem_s;

	for (int i = 0; i < 3; i++)
	{
		x(i) = b_(i) / A_(i, i);
	}
	cout << x << "\n";
	/*
	for (int k = 0; k < 2; k++)
	{
		for (int i = k; i < 2; i++)
		{
			float tem_s = A_(2 - k - i, 2 - k) / A_(2 - k, 2 - k);
			for (int j = 0; j < 2 - k; j++)
			{
				A_(1 - i, 2 - j) = A_(i - k, i - k)
			}
		}
	}
*/

	return 0;
}