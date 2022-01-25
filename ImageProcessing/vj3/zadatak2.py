import cv2
import numpy as np
slika = cv2.imread('..\\lena-color.jpg', cv2.IMREAD_GRAYSCALE)
# Kreiranje i ispis filtera
moj_filter = np.zeros((30,100), np.float32)
print(moj_filter)
moj_filter[29,0] = 1
print()
print(moj_filter)
# Primjena filtera na sliku
filtrirana_slika = cv2.filter2D(slika, -1, moj_filter,
anchor=(-1,-1), borderType=cv2.BORDER_CONSTANT)
cv2.namedWindow("Originalna slika")
cv2.namedWindow("Filtrirana slika")
cv2.imshow("Originalna slika", slika)
cv2.imshow("Filtrirana slika", filtrirana_slika)
cv2.waitKey(0)
cv2.destroyAllWindows()
