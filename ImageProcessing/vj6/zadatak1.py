import cv2
import numpy as np
import pdb

slika = cv2.imread('lena-color.jpg', cv2.IMREAD_GRAYSCALE)
rows, columns = np.shape(slika)
klase = np.zeros((rows,columns),dtype="uint8")

for i in range(1,rows-1):
    for j in range(1,columns-1):
        if(slika[i,j] >= 0 and slika[i,j] <= 85):
            klase[i,j] = 0
        elif(slika[i,j] >= 86 and slika[i,j] <= 171):
            klase[i,j] = 86
        elif(slika[i,j] >= 172 and slika[i,j] <= 255):
            klase[i,j] = 172

cv2.imshow("Klase", klase)
cv2.waitKey(0)
cv2.destroyAllWindows()
