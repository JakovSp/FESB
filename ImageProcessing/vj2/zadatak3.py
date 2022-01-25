import cv2
from matplotlib import pyplot as plt

slika_bgr = cv2.imread('lena-color.jpg')
b,g,r = cv2.split(slika_bgr)
histogram = cv2.calcHist([g], [0], None, [256], [0,256])

plt.hist(g.ravel(), 256, [0,256])
plt.title('Histogram slike')
plt.xlabel('Intenziteti sive boje')
plt.ylabel('Broj piksela')
plt.show(block = False)
plt.pause(3)
plt.close()
