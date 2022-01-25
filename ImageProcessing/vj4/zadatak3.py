import cv2
import pdb
import numpy as np
import math

slika = cv2.imread('..\\lena-color.jpg', cv2.IMREAD_GRAYSCALE)
rows, columns = np.shape(slika)
filtslika = np.zeros((rows,columns))

fltmat = np.array([ [-1,-1,-1],
                    [-1,3,-1],
                    [-1,-1,-1]    ])
block = np.zeros((3,3),dtype="uint8")

for i in range(1,rows-1):
    for j in range(1,columns-1):
        acc = 0
        block = np.array(slika[i-1:i+2,j-1:j+2])
        for m in range(0,2):
            for n in range(0,2):
                acc += fltmat[m,n]*block[m,n]
        if(acc < 0):
           acc = 0
        elif(acc > 255):
            acc = 255 
        filtslika[i,j] = acc

cv2.imshow("Originalna slika", slika)
cv2.imshow("Filtrirana slika", filtslika)
cv2.waitKey(0)
cv2.destroyAllWindows()
