#Created by Randa Shady
#rshady@hawk.iit.edu

import numpy as np
import cv2

cap = cv2.VideoCapture(1)
cam = cv2.VideoCapture(1)
img_counter = 0
cv2.namedWindow("test")


# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))

while(cap.isOpened()):
    ret, frame = cap.read()
    cv2.imshow("test", frame)
    if not ret:
        break
    k = cv2.waitKey(1)


    if k%256 == 32:
        # SPACE pressed
        img_name = "opencv_frame_{}.png".format(img_counter)
        cv2.imwrite(img_name, frame)
        print("{} written!".format(img_name))
        img_counter += 1
    out.write(frame)
    cv2.imshow('frame',frame)
    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break

# Release everything if job is finished
cap.release()
out.release()
cv2.destroyAllWindows()
