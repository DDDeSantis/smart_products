#Collect Keypoints for Calibration By Dylan DeSantis
##################################
# This program finds corners of a checkered board and
# outputs them to a text file and saves the image
##################################

import sensor, image, time

#Sensor Setup
#################################
sensor.reset()
sensor.set_pixformat(sensor.RGB565)
#sensor.set_pixfor_circle(circ.x(),circ.y(), circ.r()+4, color =(rgb[0],rgb[1],rgb[2]))
#img.drawmat(sensor.GRAYSCALE)
sensor.set_contrast(3)
#sensor.set_brightness(-3)
sensor.set_gainceiling(16)
#sensor.set_framesize(sensor.VGA)
sensor.set_framesize(sensor.QQVGA)
#sensor.set_windowing((480,400))
#sensor.set_lens_correction(True,25,500)
sensor.skip_frames(time = 4000)
sensor.set_auto_gain(False, value =100)
clock = time.clock()
#################################

#Initialize Parameters
#################################
fo = open("lines.txt","w")
iters = 0
cal_points = []
cond = 0
break_away = 0
#################################

#Main Loop
#################################
# You may need to adjust the thresholds for your own
# Camera. This will save an image and corners to your
# Camera, and will take up alot of space so make sure
# you delete the files after you export them.
#################################

#################################
# Control the lines that are selected by only accepting
# the length of lines that are under len_limit
#################################
len_limit = 15

#################################
while(True):
    clock.tick()
    img = image.Image("./test_image_label.bmp",copy_to_fb=True)
    #img = sensor.snapshot()#.lens_corr(1.7)#.morph(1,[2,4,-2,-4,2,4,-2,-4,2],mult=10,add=0).gaussian(3)
    if cond ==1:
        break_away = 1
    for line in img.find_line_segments(merge_distance = 0,max_theta_difference = 15):
        if line.length()<len_limit:
            cal_points.append(line.line())
            img.draw_line(line.line(),color =(255,0,0))
            iters +=2
            time.sleep(100)

    if iters>300 and break_away ==0:
        cond = 1
        #img = sensor.snapshot()#.lens_corr(1.7)
        for pt in cal_points:
            str1a = '{},{},{},{}'.format(pt[0],pt[1],pt[2],pt[3])
            fo.write(str1a+'\n')
        fo.close()
        #img.save("test_image_label")
    if break_away ==1:
        break


