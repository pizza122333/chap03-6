#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
    // 1. 영상 불러오기 (lenna.jpg 또는 아무 이미지 파일)
    Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

    if (src.empty()) {
        cerr << "영상을 불러올 수 없습니다!" << endl;
        return -1;
    }

    int brightness;
    cout << "밝기 변화량을 입력하세요 (예: 150 또는 -150): ";
    cin >> brightness;

    // 2. 행렬 연산을 이용한 밝기 조절
    // src 영상의 모든 픽셀에 brightness 값을 더합니다.
    // OpenCV의 + 연산자는 자동으로 포화 연산(0~255 제한)을 수행합니다.
    Mat dst = src + brightness;

    // 3. 결과 출력
    imshow("Original", src);
    imshow("Brightness Modified", dst);

    waitKey(0);
    return 0;
}