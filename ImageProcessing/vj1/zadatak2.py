import cv2
slika = cv2.imread('lena-color.jpg')

slikaduplo = cv2.resize(slika, (0, 0), fx = 2, fy = 2)

cv2.namedWindow('Prva slika')
cv2.imshow('Prva slika', slikaduplo)
cv2.waitKey(0)
cv2.destroyAllWindows()
