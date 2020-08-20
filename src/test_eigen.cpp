#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
    MatrixXf mat(2,4);
    mat << 1, 2, 6, 9,
           3, 1, 7, 2;

    VectorXf maxVal = mat.rowwise().maxCoeff();
	MatrixXf::Index   maxIndex[2];
	for(int i=0; i<2; ++i) {
    	maxVal(i) = mat.row(i).maxCoeff( &maxIndex[i] );
		std::cout << maxVal(i) << std::endl;
	}
    return 0;
}
