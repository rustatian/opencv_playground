from __future__ import print_function
import cv2 as cv
import argparse


def read():
    color = cv.imread("data/lena.jpg")
    gray = cv.imread("data/lena.jpg", cv.IMREAD_GRAYSCALE)

    if color is None:
        print("Could not open or find the image\n")
        return

    cv.imwrite("data/lena_gray.jpg", gray)

    # shape [0] - cols
    # shape [1] - rows
    rows, cols, _ = color.shape
    pixel = color[rows - 1, cols - 1]
    print("pixel (B,G,R) {},{},{}\n".format(pixel[0], pixel[1], pixel[2]))

    cv.imshow("Lena BGR", color)
    cv.imshow("Lena Gray", gray)
    cv.waitKey(0)
    return


if __name__ == '__main__':
    read()
