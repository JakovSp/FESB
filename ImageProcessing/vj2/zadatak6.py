import cv2
from matplotlib import pyplot as plt

slika = cv2.imread("lena-color.jpg")
slika = cv2.cvtColor(slika, cv2.COLOR_BGR2GRAY)
slikaeq = cv2.equalizeHist(slika)


plt.subplot(221)
plt.imshow(slika, cmap="gray")
plt.subplot(222)
plt.hist(slika.ravel(), 256, [0,256])
plt.xlabel('Intenziteti sive boje')
plt.ylabel('Broj piksela')
plt.show(block = False)

plt.subplot(223)
plt.imshow(slikaeq, cmap="gray")
plt.subplot(224)
plt.hist(slikaeq.ravel(), 256, [0,256])
plt.xlabel('Intenziteti sive boje')
plt.ylabel('Broj piksela')
plt.show(block = False)

plt.pause(3)
