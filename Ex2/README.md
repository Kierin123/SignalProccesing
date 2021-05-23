# Single electrode control

When is only one muscle to read some useful signal to precessing and control we need to change the concept of the system. I assume the signal has not so much noise and we dont use any other signals(sensors, voice, buttons)

To provide the open and close move, we can use constant speed control. Value read from the EMG sensor will be position set value for the fingers mechanism. The system should work in negative feedback loop, so that we need to use some position sensor(of instance  encoder) to control the position of the fingers. 
For example: to close the fingers the muscle must be completely tense(read value ~[1000]) and to open the fingers the muscle must be loose(read value ~[0]). Some value in a middle (~[500]) means fingers not compleatly closed. 

To reach the 3rd kind of move, we can implement in software a short range of sensor values where the state can be activated([50,150]). The range has to be above the noise range to skip disturbances. To activate the 3rd state, the muscle has to be tense and stay in this range for a short time (2 seconds for instance). When the time is up the 3rd grip is activated and fingers perform the move sequence(pinch grip).
For example when the patient tense the muscle lightly(value around [90]) and keep the muscle like this for some time(2 seconds) the prosthesis get into 3rd state and start to close the fingers to pinch grip. To come back from the 3rd state need to loose the muscle.

# Advantages and disadvantages

The advantage of this solution is the possibility to use 3 different kind of grips and not so compilated to implement in code. The other advantage is posibility to develope this concept and reach more then 3 possible moves - for example to implement second range to get 4th state.

The disadvangage of this solution is the sensivity for noises at the and of the ranges. The other disadvantage is complexity to learn by patient to use the 3rd state without any mistakes. Patient can mix the open-close move with the change of grip pattern. It can be also annoying to make the move always with the same speed. To use this concept we should concern the strength of the grips, to avoid the crash of some items by finger grip.