A wheel encoder is a sensor attached to a motor or wheel that counts how much the wheel rotates.
How far has the robot moved?
Has it traveled the length of the panel?
How much should it move sideways before starting the next cleaning strip?

Use:
DC gear motors with built-in encoders
One encoder on each drive wheel
Measure Wheel Diameter one wheel revolution moves the robot about pie*D

distance = encoder_count * distance_per_pulse;
encoder_count = variable that stores how many encoder pulses have been received.

 Define Panel Dimensions : panel length,panel width,brush width
Distance per pulse: distance per rev/no of pulses per rev
Check motor datasheet for no.of pulses per rev
Minimum
4 IR sensors on left and right edges
2 wheel encoders
Better
6 IR sensors
2 front
2 left side
2 right side
2 wheel encoders

