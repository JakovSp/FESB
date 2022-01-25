import cv2
import pdb
import numpy as np
import math

def cutoff(value):
    if(value < 0):
       value = 0
    elif(value > 255):
        value = 255 
    return value



slika = cv2.imread('..\\lena-color.jpg', cv2.IMREAD_GRAYSCALE)
rows, columns = np.shape(slika)
sobelx = np.array([ [-1,0,1],
                    [-2,0,2],
                    [-1,0,1]    ])
sobely = np.array([ [1,2,1],
                    [0,0,0],
                    [-1,-2,-1]    ])

filtslika = np.zeros((rows,columns),dtype="uint8")
block = np.zeros((3,3),dtype="uint8")

for i in range(1,rows-1):
    for j in range(1,columns-1):
        Gx = 0
        Gy = 0
        block = np.array(slika[i-1:i+2,j-1:j+2])
        for m in range(0,2):
            for n in range(0,2):
                Gx += sobelx[m,n]*block[m,n]
                Gy += sobely[m,n]*block[m,n]
        filtslika[i,j] = (math.sqrt(math.pow(Gx,2) + math.pow(Gy,2)))
            
cv2.imshow("Originalna slika", slika)
cv2.imshow("Filtrirana slika", filtslika)
cv2.waitKey(0)
cv2.destroyAllWindows()

