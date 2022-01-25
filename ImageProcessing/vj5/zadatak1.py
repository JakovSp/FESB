import cv2
import numpy as np
import pdb

slika = cv2.imread('zadatak1.jpg', cv2.IMREAD_GRAYSCALE)
(prag, slika_original) = cv2.threshold(slika, 127, 255,cv2.THRESH_BINARY)

params = cv2.SimpleBlobDetector_Params()
params.blobColor = 255
params.filterByColor = True
params.filterByConvexity = False
#params.filterByCircularity = True
params.minCircularity = 0.1
params.maxArea = 10000
detector = cv2.SimpleBlobDetector_create(params)
moj_filter = np.ones((9,9), np.uint8)

keypoints_original = detector.detect(slika)
slika_erosion = cv2.erode(slika, moj_filter, iterations = 3)
keypoints_erosion = detector.detect(slika_erosion)

slika_original = cv2.drawKeypoints(slika_original, keypoints_original, np.array([]), (120, 120, 120),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
slika_erosion = cv2.drawKeypoints(slika_erosion, keypoints_erosion, np.array([]), (120, 120, 120),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

print("Prije: ",len(keypoints_original))
print("Poslije: ",len(keypoints_erosion))

cv2.imshow("Original", slika_original)
cv2.imshow('Erozija', slika_erosion)
cv2.waitKey(0)
