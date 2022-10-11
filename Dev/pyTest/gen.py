from PIL import Image, ImageDraw
import numpy as np
import opensimplex as osimx


def main():
    w, h = 512, 512
    frequency = .04

    osimx.seed(1234)
    data = np.zeros((h, w, 3), dtype=np.uint8)
    for y in range(h):
        for x in range(w):
            v = osimx.noise2( x * frequency, y * frequency ) * 255
            data[y][x] = [ v, v, v ]

    # data[0:256, 0:256] = [255, 0, 0] # red patch in upper left
    img = Image.fromarray(data, 'RGB')
    img.show()
    

if __name__ == "__main__":
    main()
