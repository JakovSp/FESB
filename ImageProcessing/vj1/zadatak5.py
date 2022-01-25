import cv2
import numpy as np

#slika = cv2.imread('white.jpg')
slika = cv2.imread('lena-color.jpg')

cv2.waitKey(0)
cv2.destroyAllWindows()
retci = slika.shape[0]
stupci = slika.shape[1]

for i in range(0, retci):
    for j in range(0, stupci):
        if np.array_equal(slika[i,j],[255,255,255]):
            slika[i,j] = [0,0,0]

cv2.namedWindow('slika')
cv2.imshow('slika', slika)
cv2.waitKey(0)
cv2.destroyAllWindows()
