import cv2
import numpy as np
import pdb

slika = cv2.imread('zadatak2.jpg', cv2.IMREAD_GRAYSCALE)
(prag, slika_original) = cv2.threshold(slika, 127, 255,cv2.THRESH_BINARY)

params = cv2.SimpleBlobDetector_Params()
params.blobColor = 255
params.filterByColor = True
params.filterByConvexity = False
params.filterByCircularity = True
params.minCircularity = 0.1
params.maxArea = 10000
detector = cv2.SimpleBlobDetector_create(params)
moj_filter = np.ones((8,8), np.uint8)

keypoints_original = detector.detect(slika)
slika_dilation = cv2.dilate(slika, moj_filter, iterations = 2)
slika_dilation = cv2.erode(slika_dilation, moj_filter, iterations = 2)
keypoints_dilation = detector.detect(slika_dilation)

slika_original = cv2.drawKeypoints(slika_original, keypoints_original, np.array([]), (120, 120, 120),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
slika_dilation = cv2.drawKeypoints(slika_dilation, keypoints_dilation, np.array([]), (120, 120, 120),cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

print("Prije: ",len(keypoints_original))
print("Poslije: ",len(keypoints_dilation))

cv2.imshow("Original", slika_original)
cv2.imshow("Dilatacija", slika_dilation)
cv2.waitKey(0)

#Regije nakon dilatacije nisu zadržale isti oblik kruga, pa se nakon erozije šire u obliku kvadrata jer je to glavni
#strukturni oblik filtera koji se koristi (kvadratna matrica jedinica)
