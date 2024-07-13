#!/usr/bin/env python3

import numpy as np
import cv2


def parse_v1(file):
    image = cv2.imread(file, cv2.IMREAD_GRAYSCALE)
    if image is None:
        raise Exception("Image is None")

    data = np.empty((0, image.shape[0]))
    for col in range(image.shape[1]):
        l = []
        for row in image:
            l.append(row[col])
        data = np.append(data, [l], axis=0)

    result = []
    for col in data:
        index = 0
        count = 0
        for i, px in enumerate(col):
            if px == 255:
                continue
            index += i
            count += 1
        if count == 0:
            result.append(0)
        else:
            result.append(image.shape[0] - index / count)
    return result


def write_to_file(data, file):
    counter = np.arange(len(data))
    np.savetxt("out.csv", np.array((counter, data)).T, fmt='%2f', delimiter=",")


def main():
    result = parse_v1("test.png")
    write_to_file(result, "out.csv")


if __name__ == "__main__":
    main()
