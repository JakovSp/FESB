import cv2
from matplotlib import pyplot as plt
import numpy as np

def Histogram(imagedata):
    
    histdata = np.zeros(256)

    for i in range(0,imagedata.shape[0]):
        for j in range(0,imagedata.shape[1]):
            histdata[imagedata[i,j]] += 1

    return histdata

slika_bgr = cv2.imread('lena-color.jpg')
b,g,r = cv2.split(slika_bgr)
histogram = cv2.calcHist([g], [0], None, [256], [0,256])

#plt.hist(g.ravel(), 256, [0,256])
plt.plot(np.arange(0,256),Histogram(g))

plt.title('Histogram slike')
plt.xlabel('Intenziteti zelene boje')
plt.ylabel('Broj piksela')
plt.show(block = False)
plt.pause(3)
plt.close()
