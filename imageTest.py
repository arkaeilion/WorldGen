from PIL import Image, ImageDraw
import numpy as np


def main():
    img = Image.new('RGB', (256, 256), color=(100, 100, 100))
    daw = ImageDraw.Draw(img)
    daw.text((10, 10), "Hello World", fill=(255, 255, 0))
    img.show()


    w, h = 512, 512
    data = np.zeros((h, w, 3), dtype=np.uint8)
    data[0:256, 0:256] = [255, 0, 0] # red patch in upper left
    img = Image.fromarray(data, 'RGB')
    img.show()


if __name__ == "__main__":
    main()