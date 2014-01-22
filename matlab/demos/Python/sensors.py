# -*- encoding: utf-8 -*-

import socket
import tkinter as tk
import struct
import threading

mainWindow = tk.Tk () 

def UDPRecv (lineEdits):
    sRecv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sRecv.bind(('', 9500))
    while True:
        s = sRecv.recv (256)
        cmd, value = struct.unpack('bi', s)
        lineEdits[cmd].configure(text=str(value))

if __name__ == "__main__":

    sensors = ["Gyroscope X", "Gyroscope Y", "Gyroscope Z", 
               "Accelerometer X", "Accelerometer Y", "Accelerometer Z",
               "Magnetometer X", "Magnetometer Y", "Magnetometer Z",
               "Height", "Pressure", "Temperature"]

    lineEdits = []

    mainWindow.title("AR.Drone 2.0 - Sensors")

    mainWindow.columnconfigure(0, weight=1)
    mainWindow.columnconfigure(1, weight=1)

    for i, sensor in enumerate(sensors):
        mainWindow.rowconfigure(i, weight=1)
        tk.Label(mainWindow, text=sensor).grid(column=0, row=i, sticky=tk.E)
        lab = tk.Label(mainWindow, text="0")
        lab.grid(column=1, row=i, sticky=tk.W)
        lineEdits.append(lab)

    threading._start_new_thread(UDPRecv, (lineEdits, ))

    mainWindow.mainloop ()