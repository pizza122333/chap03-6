#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
    // 1. 행렬 A, B, C 초기화 (CV_32F: 실수형 행렬)
    Mat A = (Mat_<float>(2, 2) << 1, 3, -4, 2);
    Mat B = (Mat_<float>(2, 2) << 2, 3, 0, 5);
    Mat C = (Mat_<float>(2, 2) << -2, -2, -2, -3);

    // 2. 수식 계산
    // B.inv()는 역행렬을 계산합니다.
    // OpenCV에서 Mat 객체에 스칼라를 더하거나 빼면 모든 원소에 적용됩니다.
    Mat X = 3 * A + B.inv() + 10 * C - 5;

    // 3. 결과 출력
    cout << "행렬 A:\n" << A << endl << endl;
    cout << "행렬 B:\n" << B << endl << endl;
    cout << "행렬 C:\n" << C << endl << endl;
    cout << "결과 행렬 X (3*A + B^-1 + 10*C - 5):\n" << X << endl;

    return 0;
}