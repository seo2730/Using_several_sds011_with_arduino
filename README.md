# Using_several_sds011_with_arduino
Using four sds011 sensors with arduino based on https://github.com/sensebox/SDS011-select-serial<br>
I only check PM10 values so if you want to check PM2.5, just add String in Serial.println.<br>
Example : <br>
Serial.println("P25_1: "+String(sp25_1) + "  P25_2: "+String(sp25_2) + "  P25_3: "+String(sp25_3)+ "  P25_4: "+String(sp25_4));

# Connect sds011 with arduino
Red line : Vcc , Black line : Gnd , Green line : TXD(sds011) , Blue line : RXD(sds011)
![arduino_sds011_circuits ps](https://user-images.githubusercontent.com/42115807/54341625-9c617600-467d-11e9-8250-38ff43135bee.png)

# Example
![sds011_arduino](https://user-images.githubusercontent.com/42115807/54341892-65d82b00-467e-11e9-908a-c08819106806.jpg)

# Serial 
![serial](https://user-images.githubusercontent.com/42115807/54342467-e0ee1100-467f-11e9-9c51-78605f760537.gif)





      
