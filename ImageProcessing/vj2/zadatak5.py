import cv2
from PIL import Image, ImageOps

slika = Image.open("lena-color.jpg")
slika = ImageOps.grayscale(slika)

nova_slika = ImageOps.autocontrast(slika, cutoff = 30)
nova_slika.show()
