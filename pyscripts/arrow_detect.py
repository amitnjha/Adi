import cv2
import numpy as np
from keras.models import load_model
import tensorflow as tf


cap = cv2.VideoCapture(0)
model = load_model('mixed_model_val_100__no_opt.h5')
graph = tf.get_default_graph()

angle90 = 90
scale = 1.0
while(True):
    # Capture frame-by-frame
    ret, orig = cap.read()
    (h, w) = orig.shape[:2]
    center = (w / 2, h / 2)
    M = cv2.getRotationMatrix2D(center, angle90, 1.25)
    rotated90 = cv2.warpAffine(orig, M, (h, w))
    
    frame = rotated90
    frame =  frame.astype('float32')
    frame /= 255
    frame = cv2.resize(orig, (150,150))

    frame = frame.reshape(1,150,150,3)
    # Our operations on the frame come here
    with graph.as_default():
        keras_pred = model.predict_classes(frame)[0]
    print(keras_pred)

    # Display the resulting frame
    cv2.imshow('frame',rotated90)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()

