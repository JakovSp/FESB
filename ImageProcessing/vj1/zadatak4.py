import cv2
import matplotlib.pyplot as plt


slika = cv2.imread('lena-color.jpg')
b, g, r = cv2.split(slika)

slika = cv2.cvtColor(slika, cv2.COLOR_BGR2HSV)
h, s, v = cv2.split(slika)

plt.subplot(231)
plt.imshow(r, cmap="gray")
plt.title('Red')
plt.xticks([])
plt.yticks([])
plt.subplot(232)
plt.imshow(g, cmap="gray")
plt.title('Green')
plt.xticks([])
plt.yticks([])
plt.subplot(233)
plt.imshow(b, cmap="gray")
plt.title('Blue')
plt.xticks([])
plt.yticks([])


plt.subplot(234)
plt.imshow(h, cmap="gray")
plt.title('Hue')
plt.xticks([])
plt.yticks([])
plt.subplot(235)
plt.imshow(s, cmap="gray")
plt.title('Saturation')
plt.xticks([])
plt.yticks([])
plt.subplot(236)
plt.imshow(v, cmap="gray")
plt.title('Value')
plt.xticks([])
plt.yticks([])

plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()
