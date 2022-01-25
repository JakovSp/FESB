import cv2
import numpy as np
slika = cv2.imread('..\\lena-color.jpg', cv2.IMREAD_GRAYSCALE)

moj_filter = np.ones((9,9), np.float32)

for i in range(0,9):
    for j in range(0,9): 
        moj_filter[i,j]= (np.float32)(moj_filter[i,j]/81)


#Ako uzmemo manje dimenzije za filter dobijemo manje mutnu sliku jer ujednačavamo manji prostor

filtrirana_slika = cv2.filter2D(slika, -1, moj_filter,
anchor=(-1,-1), borderType=cv2.BORDER_CONSTANT)
cv2.namedWindow("Originalna slika")
cv2.namedWindow("Filtrirana slika")
cv2.imshow("Originalna slika", slika)
cv2.imshow("Filtrirana slika", filtrirana_slika)
cv2.waitKey(0)
cv2.destroyAllWindows()
