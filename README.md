# Halflife
repo for half-life 
This is a PCB that can can control four 3 pin outputs with data power and ground which will allow the final build to control 2 servos for movement as well as a mini air pump for sticking to walls with suction cups In addition two a camera. It also has a USBC port allowing charge for the battery which is not connected to the board but can be attached as well as being charged from the board. This provides 3.7 v which is reduced to 3.3 then supplied to the esp32 as well as the nrf32 unit with a lower stable voltage. In addition the 3.7 v battery will go into a buck converter to raise it to 5 volts for powering the servos and the air pump. Now that everything is powered the nrf32 unit will give data input to the esp32 allowing it to control the servos.

Assembly 
Take all surface mount components capacitors diodes resistors etc. and sauder then on making sure there in the right orentation and position
Connect the ports and esp32 and nrf32 to board as well as other chips
make sure all connections are stable 

BE aware that the reason that any remaining errors occur is because in the Schematic i connected any unconnected pins to avoid the unconnected pins warning when checking the pcb to make it easier to navigate to more important waning's but all of these have are not in the layout and the design is not having issues 

BOM
CONN RCP USB2.0 C 6POS SMD RA
IC BATT CNTL LI-ION 1CEL SOT23-5
IC REG LINEAR 3.3V 600MA SOT-25
LED RED DIFFUSED 5MM ROUND T/H
BAG-O-CAPACITORS
IC REG BOOST 5V 2.5A SOT23-5
RF TXRX MOD ISM>1GHZ PCB THTH
RF TXRX MODULE BT PCB TRACE SMD
CONN HEADER VERT 3POS 2.54MM
<img width="1920" height="1020" alt="image" src="https://github.com/user-attachments/assets/cca2c968-4488-4db7-bf11-1ae14367119e" />
