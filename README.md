# Digital-Ohmmeter

![Status](https://img.shields.io/badge/Status-In_Process-yellow)
![Language](https://img.shields.io/badge/Language-c++-blue)
![Processor](https://img.shields.io/badge/Microcontroller-Arduino_Nano-orange)
![Application](https://img.shields.io/badge/Application-Eletronics-purple)

Measure the resistive value of an impedance and display its value on an LCD screen

<div align="center">
  <img width="724" height="429" alt="image" src="https://github.com/user-attachments/assets/b17082f1-9461-4e07-8882-3c6e672e9a8d" />  
</div>
<div align="center">
  Design of the electrical circuit    
</div>  
<br/>  

The NPN transistor holds the configuration of maintaing the current on the emissor the same as the sum of the colector and base:  

$$
Ie = Ic + Ib
$$

                                                    
As the current on the base is very low, we can assume that the current that passes through the unknown resistance has the same value as the one that passes through R3.  

The arduino nano reads the tension both on the unknown resistance and the R3 resistor and calculates the current on the last one.  
By keeping the value of the tension on UNKNOWN and the current recently calculated, it calculates the resistance of the unknown charge and shows on the LCD screen.  
The potentiometer works as a regulation to the accuracy of the measurement.

<div align="center">
  <img width="1853" height="866" alt="image" src="https://github.com/user-attachments/assets/3826ee18-2ad8-46be-ae68-d7d228535aa7" />
</div>  
<div align="center">
  Circuit on TinkerCad   
</div>  
<br/>  
