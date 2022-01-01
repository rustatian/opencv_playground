import cv2 as cv
import numpy as np


def remove_light(img, pattern):
    img = np.float32(img)
    pattern = np.float32(pattern)

    img = img - img.min()
    img = img / img.max() * 255

    aux = 1 - (np.divide(img, pattern))

    cv.imshow("foo", aux)
    cv.waitKey(0)
    cv.destroyWindow("foo")
    return aux


def calculate_pattern(img):
    height, width = img.shape[:2]
    bl = cv.blur(img, (height, width))
    return bl


def run():
    img = cv.imread("../data/test_noise.pgm")
    img = cv.medianBlur(img, 3)
    pattern = cv.imread("../data/light.pgm")
    aux = remove_light(img, pattern)
    bl = calculate_pattern(aux)
    cv.imshow("blur", bl)
    cv.waitKey(0)
    cv.destroyWindow("blur")


if __name__ == '__main__':
    run()
