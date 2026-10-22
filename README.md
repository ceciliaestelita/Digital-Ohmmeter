# Digital-Ohmmeter

![Status](https://img.shields.io/badge/Status-In_Process-yellow)
![Language](https://img.shields.io/badge/Language-c++-blue)
![Processor](https://img.shields.io/badge/Microcontroller-Arduino_Nano-orange)
![Application](https://img.shields.io/badge/Application-Eletronics-purple)

Measure the resistive value of an impedance and display it on an LCD screen

<div align="center">
  <img width="1210" height="858" alt="image" src="https://github.com/user-attachments/assets/0a73066d-9031-43a4-9665-9964209a298a" />



</div>
<div align="center">
  Scheme of the electrical circuit    
</div>  
<br/>  

The NPN transistor holds the configuration of maintaing the current on the emissor the same as the sum of the colector and base:  

$$
Ie = Ic + Ib
$$

                                                    
As the current on the base is very low, we can assume that the current that passes through the unknown resistance has the same value as the one that passes through R2 or R3.  

The circuit always starts with the reference resistance as R2, for a lower resistances range, which is used for the first calculation of the current of the circuit (I1):

$$
I1=Va0/R2
$$

That is then used in the upper part of the circuit:

$$
Vx = 5V - Va1
$$

$$
Rx = (5V-Va1)/I1
$$

The choice between R2 and R3 for the real measurement is then made by a commutation system that, based of the Rx calculated, estimates if Rx is int the range of low or high resistances. If it is a low resistance, the arduino sends a digital signal from d5, if it's high, sends a digital signal from d6.  
Those digital signals are the tensions needed to activate the LED inside the photomos, that closes the circuit (as a mosfet) and lets current flow through R2 (for Rx = lower resistances) or R3 (for Rx = higher resistances).  
By letting current flow, the new current is taken by the calculation of Rx, and a more precise measure is made.

This circuit is designed to work in a range of resistances between 200 Ohms and 20 kOhms with a 1% error rate.

<div align="center">
  <img width="1853" height="866" alt="Électronique et Signaux Numérique" src="https://github.com/user-attachments/assets/fa9291ee-53b4-4e8d-a9ac-6f78de2eeccd" />
</div>  
<div align="center">
  Circuit on TinkerCad   
</div>  
<br/>  
