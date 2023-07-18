# Improvised RC line following car
It is a NodeMCU-based white line following car project. I made this project for an architectural model where I needed to use a small toy RC car so that it can automatically drive in a circular path all by itself. The completely black-painted road was lined with white scotch tape so that the car could follow the line. An ultrasonic sensor was installed in the front of the car so that it could stop if something came in front of it. I placed the remote control circuit inside the toy car and manipulated the remote control circuit with Node MCU microcontroller. If you press any of the front back left right buttons of the remote, it gets grounded and the other buttons have voltage. So I have grounded the voltage to the button which is needed to run the car by commanding the node MCU. I have used a 30W 2A PWM DC motor speed controller to control the speed of the vehicle.
