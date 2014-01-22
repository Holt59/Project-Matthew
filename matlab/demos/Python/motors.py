# -*- encoding: utf-8 -*-

import socket
import tkinter as tk
import struct
import threading
import copy

mainWindow = tk.Tk () 

def sendMotor (what, offset, _ = None):
    if what == "moveto":
        sSend = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sSend.sendto(struct.pack('bi', 4, int(float(offset) * 100)), ('127.0.0.1', 9500))

LEDValues = [tk.StringVar(mainWindow), 
             tk.StringVar(mainWindow), 
             tk.StringVar(mainWindow), 
             tk.StringVar(mainWindow)]

def sendLED (led, value):
    sSend = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sSend.sendto(struct.pack('bi', led, ["OFF", "RED", "GREEN", "ORANGE"].index(value)), ('127.0.0.1', 9500))

if __name__ == "__main__":

    mainWindow.title("AR.Drone 2.0 - Actuators")

    mainWindow.minsize(500, 0)
    mainWindow.resizable(False, True)

    for i in range(4):
        frame = tk.Frame(mainWindow)
        tk.Label(frame, text="LED " + str(i)).pack(side="left")
        LEDValues[i].set("OFF")
        tk.OptionMenu(frame, LEDValues[i], "OFF", "RED", "GREEN", "ORANGE", command=lambda x, led=i : sendLED(led, x)).pack(side="right")
        frame.pack()

    tk.Label(mainWindow, text="Motors").pack(side="left", expand=True)
    sc = tk.Scrollbar(mainWindow, command=sendMotor, orient=tk.HORIZONTAL)
    sc.pack(side="right", expand=True, fill=tk.X)

    mainWindow.mainloop ()