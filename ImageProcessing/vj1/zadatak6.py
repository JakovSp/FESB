import cv2
slika = cv2.imread('lena-color.jpg')

retci = slika.shape[0]
stupci = slika.shape[1]
kanali = slika.shape[2]

for i in range(0, retci):
    for j in range(0, stupci):
        gray = ((slika[i, j, 0]/255 + slika[i, j, 1]/255 + slika[i, j, 2]/255)/3)*255
        for k in range(0, kanali):
            slika[i, j, k] = gray

cv2.namedWindow('slika')
cv2.imshow('slika', slika)
cv2.waitKey(0)
cv2.destroyAllWindows()
