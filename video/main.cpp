//
// Created by valery on 28/11/2021.
//

#include "main.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>


int main(int argc, char **argv) {
    const char *keys =
            {
                    "{help h usage ? | | print this message}"
                    "@video | | Video file, if not defined try to use webcamera"
            };


    cv::VideoCapture cap;
    cap.open(0);

    if (!cap.isOpened()) {
        return -1;
    }

    cv::namedWindow("Video", 1);

    for (;;) {
        cv::Mat frame;

        cap >> frame;

        cv::imshow("Video", frame);

        if (cv::waitKey(30) >= 0){
            break;
        }
    }

    cap.release();


    return 0;
}