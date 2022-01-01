#include "main.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <memory>

using namespace std;

// OpenCV includes
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

Mat calculate_light_pattern(Mat img) {
    Mat pattern;
    cv::blur(img, pattern, cv::Size(img.cols/3, img.cols/3));
    return pattern;
}

Mat remove_light(Mat img, Mat pattern) {
    Mat img32, pattern32;
    img.convertTo(img32, CV_32F);
    pattern.convertTo(pattern32, CV_32F);

    if ((pattern32.rows != img32.rows) || (pattern32.cols != img32.cols)) {
        auto w = img32.cols;
        auto h = img32.rows;
        Mat out;
        cv::resize(pattern32, out, Size(w, h),0,0, cv::INTER_LINEAR);
        Mat aux = 1 - (img32 / out);
        aux.convertTo(aux, CV_8U, 255);

        return aux;
    }

    Mat aux = 1 - (img32 / pattern32);
    aux.convertTo(aux, CV_8U, 255);

    return aux;
}

int main() {
    auto img = cv::imread("data/1.png");
    if (img.data == nullptr) {
        cout << "Error loading image " << endl;
        return 1;
    }

    auto pattern = cv::imread("data/pattern2.png");

    Mat img_noise;
    cv::medianBlur(img, img_noise, 3);

    auto out = remove_light(img_noise, pattern);
    cv::imshow("foo", out);
    cv::waitKey(0);
    cv::destroyAllWindows();

    auto lp = calculate_light_pattern(out);

    Mat img_thr;
    cv::threshold(img_noise, img_thr, 30, 255, THRESH_BINARY);

}
