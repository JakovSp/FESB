import cv2
from matplotlib import pyplot as plt
slika_bgr = cv2.imread('lena-color.jpg')
slika_gray = cv2.cvtColor(slika_bgr, cv2.COLOR_BGR2GRAY)
histogram = cv2.calcHist([slika_gray], [0], None, [256], [0,256])

plt.hist(slika_gray.ravel(), 256, [0,256])
plt.title('Histogram slike')
plt.xlabel('Intenziteti sive boje')
plt.ylabel('Broj piksela')
plt.show(block = False)
plt.pause(3)
plt.close()
