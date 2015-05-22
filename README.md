# Arduino Ohmmeter
## Motivation
![Alt text](https://dl.dropboxusercontent.com/u/9118489/Github%20Pictures/Arduino%20Ohmmeter/resistor1.jpg "Resistor")

So I have some five-band resistors at home like the one shown above. They were all mixed together in one bag and I wanted to sort them. Because of the dark colour coating of the resistor itself, it was incredibly hard for me to even read the colour codes and figure out the value of the resistor (e.g. is it blue or is it black?). I don't have an ohmmeter or a mulitmeter. So, using my arduino and some basic circuits, I created my own ohmmeter!

##Basic Circuits 101 - Ohm's Law and Voltage Division
###Ohm's Law

Without going deep into the underlying physics, Ohm's Law states that the voltage across any circuit element(s) is proportional to the current passing through the circuit element(s). In my case, the proportionality constant is essentially the resistance. This means that

<p align ="center">V = i * R</p>
where:
- V: Voltage across the circuit element(s)
- i: Current across the circuit element(s)
- R: Total resistance of the circuit elements being measured

###Voltage Division
![Alt text](http://upload.wikimedia.org/wikipedia/commons/2/21/Resistive_divider2.svg)

Given the circuit above, the voltage across each resistor is related by Ohm's Law. The sum of the voltage across each resistor must equal to the input voltage, as follows

Vin = i * (R1 + R2)

Solving for current,

i = Vin/(R1+R2)

To calculate the voltage Vout, we will use Ohm's Law and the current formula above. Vout is the voltage for the resistor R2.

Vout = i * R2

Vout = Vin * R2 / (R1 + R2)

##Creating the Arduino Ohmmeter
###Circuit
We applied the circuit shown above in our custom ohmmeter. R1 is our known resistance (the resistor value is arbitrary) and R2 is the unknown resistance you want to figure out. The input voltage is connected to one of the voltage source from the Arduino, and the output voltage is connected to the analog pin A0. The actual wiring of the circuit is shown below:

![Alt text](https://dl.dropboxusercontent.com/u/9118489/Github%20Pictures/Arduino%20Ohmmeter/voltage%20divider%20schematic.jpg)

I used an additional analog pin A1 to detect what the input voltage source.

###Code
You can view the source code for the Arduino in this repository. The main jist of the code is to detect the input voltage and output voltage, and using the formula above from the voltage division section, we solve for R2.

