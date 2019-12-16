from keras.models import load_model
import tensorflow as tf
import cv2
import numpy as np

cap = cv2.VideoCapture(0)
model = load_model('handmodel_fingers_model.h5')

cap.set(cv2.CAP_PROP_FRAME_WIDTH, 128)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 128)
angle90 = 90
scale = 1.0

def img_to_sample(img, kernel = None):
    img = img.astype(np.uint8)
    img = np.reshape(img, (128, 128))
    
    img = process_image(img, kernel)
    
    img = np.reshape(img, (128, 128, 1))
    return img

def process_image(img,kernel):
    # img = cv2.resize(img, (128, 128))
    img = cv2.GaussianBlur(img,(5,5),0)
    _,img = cv2.threshold(img,80,255,cv2.THRESH_BINARY)
    
    im_floodfill = img.copy()
    h, w = img.shape[:2]
    mask = np.zeros((h+2, w+2), np.uint8)
    cv2.floodFill(im_floodfill, mask, (0,0), 255)
    im_floodfill_inv = cv2.bitwise_not(im_floodfill)
    img = img | im_floodfill_inv
    
    
    img = img/255
    return img

while(True):
    ret, orig = cap.read()
    orig = cv2.cvtColor(orig, cv2.COLOR_BGR2GRAY)
    (h, w) = orig.shape[:2]
    center = (w / 2, h / 2)
    M = cv2.getRotationMatrix2D(center, angle90, 1)
    rotated90 = cv2.warpAffine(orig, M, (h, w))
    rotated90 = cv2.GaussianBlur(rotated90,(5,5),0)
    (thresh, blackAndWhiteImage) = cv2.threshold(rotated90, 80, 255, cv2.THRESH_BINARY)
    #print('rotate 90 shape', rotated90.shape)
    
    im_floodfill = blackAndWhiteImage.copy()
    h, w = blackAndWhiteImage.shape[:2]
    mask = np.zeros((h+2, w+2), np.uint8)
    cv2.floodFill(im_floodfill, mask, (0,0), 255)
    im_floodfill_inv = cv2.bitwise_not(im_floodfill)
    img = blackAndWhiteImage | im_floodfill_inv
    img = img/255
    for_model =  blackAndWhiteImage.reshape(1,128,128,1)
    print(model.predict(for_model))
    #cv2.imshow('frame',img_to_sample(rotated90,None))
    cv2.imshow('img',img)
    cv2.imshow('blackAndWhiteImage',blackAndWhiteImage)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break


cap.release()
cv2.destroyAllWindows()
