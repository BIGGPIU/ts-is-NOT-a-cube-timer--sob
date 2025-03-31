import serial
import pyautogui
import serial.tools
import serial.tools.list_ports
def findArduino() -> str:
        sercom = serial.tools.list_ports.comports()
        for i in sercom:
            if "Arduino Uno" in i.description:
                return i.device      
        return "no arduino found"

def loop(ser):
    
    bufferB = False
    bufferA = False
    while True:
        x = ser.read(1)
        x = x.decode()
        print(x)
        print(f"buffer B {bufferB}")
        print(f"buffer A: {bufferA}")
        if x[0] == "A":
            # pyautogui.keyDown("space")
            bufferA = True     
        elif x[0] == "C":                       
            # pyautogui.keyUp("space")
            bufferA = False
        elif x[0] == "B":
            # pyautogui.keyDown("ctrlright")
            bufferB = True
        elif x[0] == "D":
            # pyautogui.keyUp("ctrlright")
            bufferB = False
        
        if bufferB and bufferA:
            pyautogui.keyDown("space")
            print("Space Down")
        else:
            pyautogui.keyUp("space")

if __name__ == "__main__":
    ser = serial.Serial(port=findArduino())
    while True:
        loop(ser)