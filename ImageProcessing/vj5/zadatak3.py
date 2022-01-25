import cv2
import numpy as np
import pdb

slika = cv2.imread('zadatak1.jpg', cv2.IMREAD_GRAYSCALE)
(prag, slika_original) = cv2.threshold(slika, 127, 255,cv2.THRESH_BINARY)

params = cv2.SimpleBlobDetector_Params()
params.blobColor = 255
params.filterByColor = True
params.filterByConvexity = False
params.filterByCircularity = True
params.minCircularity = 0.1
params.maxArea = 10000
detector = cv2.SimpleBlobDetector_create(params)
#moj_filter = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(12,12))
moj_filter = np.ones((9,9), np.uint8)

keypoints_original = detector.detect(slika)
slika_morph = cv2.erode(slika, moj_filter, iterations = 3)
slika_morph = cv2.dilate(slika_morph, moj_filter, iterations = 3)
keypoints_morph = detector.detect(slika_morph)

#slika_original = cv2.drawKeypoints(slika_original, keypoints_original, np.array([]), (120, 120, 120),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
#slika_morph = cv2.drawKeypoints(slika_morph, keypoints_morph, np.array([]), (120, 120, 120),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

print("Prije: ",len(keypoints_original))
print("Poslije: ",len(keypoints_morph))

cv2.imshow("Original", slika_original)
cv2.imshow("Morph otvaranje", slika_morph)
cv2.waitKey(0)


#S obzirom na strukturni element(filter, u ovom slučaju matrica u obliku kvadrata ili elipse), granice su glatke,
#neke regije su odvojene iako su bile dilatirane

