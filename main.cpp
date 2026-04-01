#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

// 타입을 기호 상수로 변환하는 함수
string get_type_string(int type) {
    string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
    }

    r += "C";
    r += (chans + '0');

    return "CV_" + r;
}

int main() {
    // 1. 휴대폰으로 찍은 사진 파일 로드 (파일명 확인 필요)
    Mat img = imread("C:/Users/pizza/OneDrive/사진/photo1.jpg");

    if (img.empty()) {
        cerr << "영상을 불러올 수 없습니다! 파일명을 확인하세요." << endl;
        return -1;
    }

    // 2. 정보 추출
    int rows = img.rows;       // 행의 수 (높이)
    int cols = img.cols;       // 열의 수 (너비)
    int channels = img.channels(); // 채널 수
    string typeStr = get_type_string(img.type()); // 타입 기호 상수

    // 3. 화면 출력
    cout << "========== 영상 정보 ==========" << endl;
    cout << "행의 수 (Rows):    " << rows << endl;
    cout << "열의 수 (Cols):    " << cols << endl;
    cout << "채널 수 (Channels): " << channels << endl;
    cout << "타입 (Type):       " << typeStr << endl;
    cout << "===============================" << endl;

    imshow("My Photo", img);
    waitKey(0);

    return 0;
}