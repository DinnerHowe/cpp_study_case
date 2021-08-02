#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>
#include <Eigen/Dense>
#include <Eigen/Core>

typedef Eigen::Array2i DataIndex;

using namespace std;
using namespace Eigen;
void CastToMap(Eigen::MatrixXi &mat)
{
    DataIndex index(1, 2);
    std::cout << "CastToMap: " << mat(index(0), index(1)) << std::endl;
    mat(index(0), index(1)) = 8;
}

int main(int argc, char **argv)
{
    // MatrixXi mat(4, 5);
    // MatrixXi mat2(4, 5);
    // MatrixXi mat3(4, 5);
    // MatrixXi mat4(4, 5);

    // mat << 1, 2, 3, 4, 5,
    //     6, 7, 8, 9, 10,
    //     11, 12, 13, 14, 15,
    //     16, 17, 18, 19, 20;

    // mat2 << 0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     16, 17, 18, 19, 20;

    // mat3 << 0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 20;

    // mat4 << 0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0,
    //     0, 0, 0, 0, 0;
    // Eigen::Array<int, 1, 4> quadrant_4;
    // quadrant_4 << 0, 0, 0, 0;
    // std::cout << std::boolalpha << "quadrant_4: " << quadrant_4.any() << std::endl;
    // std::cout << "block: " << mat.block(0, 0, 0, 0) << std::boolalpha << mat.block(0, 0, 0, 0).size() << std::endl;
    // // std::cout << "new block2: " << new_mat2 << std::endl;

    // std::cout << std::boolalpha << "mat.any(): " << mat.any() << ", mat2.any(): " << mat2.any() << ", mat3.any(): " << mat3.any() << ", mat4.any(): " << mat4.any() << std::endl;
    // std::cout << std::boolalpha << "mat.all(): " << mat.all() << ", mat2.all(): " << mat2.all() << ", mat3.all(): " << mat3.all() << ", mat4.all(): " << mat4.all() << std::endl;

    // // std::cout << "mat(1, 2): " << mat(1, 2) << std::endl;
    // // CastToMap(mat);
    // // std::cout << "mat(1, 2): " << mat(1, 2) << std::endl;
    // MatrixXi maxVal = mat.rowwise().maxCoeff();
    // MatrixXf::Index maxIndex[2];
    // // for (int i = 0; i < 2; ++i)
    // // {
    // //     maxVal(i) = mat.row(i).maxCoeff(&maxIndex[i]);
    // //     std::cout << "max val: " << maxVal(i) << ", at row: " << i << std::endl;
    // // }
    // std::cout << std::endl;
    // // std::cout << "======= total cols: " << mat.cols() << ", " << std::numeric_limits<int>::min() << ", " << std::numeric_limits<int>::max() << std::endl;
    // // for (int i = 0; i < mat.cols(); ++i)
    // // {
    // //     std::cout << "col: " << i << ", at col: " << std::boolalpha << mat.col(i).any() << std::endl;
    // //     std::cout << std::endl;
    // // }
    // int element_row = 1;
    // int element_col = 3;
    // int max_row = mat.rows();
    // int min_row = 0;
    // int max_col = mat.cols();
    // int min_col = 0;
    // std::cout << mat(element_row, element_col) << std::endl;
    // int block_row = max_row - element_row;
    // int block_col = max_col - element_col;
    // std::cout << "max_row: " << max_row << ", max_col: " << max_col
    //           << "\nelement_row: " << element_row << ", element_col: " << element_col
    //           << "\nblock_row " << block_row << ", block_col " << block_col << std::endl;
    // std::cout << std::endl;

    // auto new_mat1 = mat.block(min_row, min_col, element_row + 1, element_col + 1);
    // std::cout << "new mat1: " << new_mat1 << std::endl;
    // std::cout << std::endl;

    // auto new_mat2 = mat.block(min_row, element_col, element_row + 1, block_col);
    // std::cout << "new mat2: " << new_mat2 << std::endl;
    // std::cout << std::endl;

    // auto new_mat3 = mat.block(element_row, min_col, block_row, element_col + 1);
    // std::cout << "new mat3: " << new_mat3 << std::endl;
    // std::cout << std::endl;

    // auto new_mat4 = mat.block(element_row, element_col, block_row, block_col);
    // std::cout << "new mat4: " << new_mat4 << std::endl;
    // std::cout << "========================" << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;

    // element_row = 1;
    // element_col = 1;
    // max_row = new_mat3.rows();
    // max_col = new_mat3.cols();
    // block_row = max_row - element_row;
    // block_col = max_col - element_col;
    // std::cout << new_mat3(element_row, element_col) << std::endl;
    // std::cout << "max_row: " << max_row << ", max_col: " << max_col
    //           << "\nelement_row: " << element_row << ", element_col: " << element_col
    //           << "\nblock_row " << block_row << ", block_col " << block_col << std::endl;
    // std::cout << std::endl;

    // auto new_mat31 = new_mat3.block(min_row, min_col, element_row + 1, element_col + 1);
    // std::cout << "new mat31: " << new_mat31 << std::endl;
    // std::cout << std::endl;

    // auto new_mat32 = new_mat3.block(min_row, element_col, element_row + 1, block_col);
    // std::cout << "new mat32: " << new_mat32 << std::endl;
    // std::cout << std::endl;

    // auto new_mat33 = new_mat3.block(element_row, min_col, block_row, element_col + 1);
    // std::cout << "new mat33: " << new_mat33 << std::endl;
    // std::cout << std::endl;

    // auto new_mat34 = new_mat3.block(element_row, element_col, block_row, block_col);
    // std::cout << "new mat34: " << new_mat34 << std::endl;
    // std::cout << std::endl;

    return 0;
}
