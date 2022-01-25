import cv2
import pdb
import numpy as np
import math
slika = cv2.imread('grainy.png')
kanali = cv2.split(slika)

rows, columns,depth = np.shape(slika)
block = np.zeros((3,3),dtype="uint8")
filtkanal = np.ones((rows,columns), dtype="uint8")


filtkanali = kanali
for k in range(0,depth): 
    for i in range(1,rows-1):
        for j in range(1,columns-1):
            block = np.array(kanali[k][i-1:i+2,j-1:j+2])
            block = block.flatten(order='C')
            block = sorted(block)
            filtkanali[k][i,j]=block[4]

filtslika = cv2.merge(filtkanali)
cv2.imshow("Originalna slika", slika)
cv2.imshow("Filtrirana slika", filtslika)
cv2.waitKey(0)
cv2.destroyAllWindows()
