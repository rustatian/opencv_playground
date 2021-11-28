#include "main.h"
#include <iostream>
#include <sstream>

using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace cv;

int main(int argc, const char **argv) {
    // read images
    Mat color = imread("lena.png");
    Mat gray = imread("lena.png", ImreadModes::IMREAD_GRAYSCALE);

    if (!color.data) {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    imwrite("lenaGray.jpg", gray);

    int myCol = color.rows-1;
    int myRow = color.cols-1;
    Vec3b pixel = color.at<Vec3b>(myRow, myCol);

    cout << "Pixel value (B, G, R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] <<")" << endl;
    imshow("Lena BGR", color);
    imshow("Lena Gray", gray);

    waitKey(0);

    return 0;
}
