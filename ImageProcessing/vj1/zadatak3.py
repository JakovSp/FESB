import cv2
import matplotlib.pyplot as plt
slika = cv2.imread('lena-color.jpg')

b, g, r = cv2.split(slika)
cv2.imwrite('b.jpg', b)
cv2.imwrite('g.jpg', g)
cv2.imwrite('r.jpg', r)

#Zeleni kanal izgleda najprirodnije
plt.subplot(131)
plt.imshow(b, cmap="gray")
plt.title('Plavi kanal')
plt.xticks([])
plt.yticks([])
plt.subplot(132)
plt.imshow(g, cmap="gray")
plt.title('Zeleni kanal')
plt.xticks([])
plt.yticks([])
plt.subplot(133)
plt.imshow(r, cmap="gray")
plt.title('Crveni kanal')
plt.xticks([])
plt.yticks([])

plt.show()
