import cv2

slika = cv2.imread('lena-color.jpg')
cv2.namedWindow('Prva slika')
cv2.imshow('Prva slika', slika)

retci, stupci, kanali = slika.shape
print('Broj redaka je ' + str(retci) + '.')
print('Broj stupaca je ' + str(stupci) + '.')
print('Broj kanala je ' + str(kanali) + '.')

cv2.waitKey(0)
cv2.destroyAllWindows()
