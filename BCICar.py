
# coding: utf-8

# # BCI Car

# In[1]:


from NeuroPy import NeuroPy
import numpy as np
import serial
import time


# In[34]:


# Instantiation of Mindwave Mobile 
mindwave = NeuroPy(port="COM12", baudRate=57600)
mindwave.start()


# In[35]:


# Instantiation of Bluetooth to Arduino and flush serial
HC06_port = "COM15"
ser = serial.Serial(port=HC06_port, baudrate=9600)
ser.reset_input_buffer()
ser.reset_output_buffer()


# In[37]:


# Instantiation of maximum and minimum speeds
maxSpeed = 240
minSpeed = 35
atten_thres = 20

# Control loop for car to move forward
while True:
    attention = float(mindwave.attention)
    meditation = float(mindwave.meditation)

    print "Attention " + str(attention)
    
    if(attention > atten_thres):
        speed = np.floor( minSpeed+(attention/100*(maxSpeed-minSpeed)) )
        ser.write(str(speed)+'\n')
        
    else:
        ser.write('0\n')

    time.sleep(1)


# In[33]:


# Close and terminate existing ports
ser.close()
mindwave.stop()

