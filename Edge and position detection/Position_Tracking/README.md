# Position Tracking and Edge Detection

## Overview

This module is responsible for:

- Position Tracking
- Left and Right Edge Detection
- Safe Navigation on Solar Panels

The robot uses wheel encoders to estimate its position and IR sensors to detect panel boundaries.

---

## Position Tracking

### Wheel Encoder

A wheel encoder is a sensor attached to a motor or wheel that counts how much the wheel rotates.

It helps determine:

- How far has the robot moved?
- Has it travelled the length of the panel?
- How much should it move sideways before starting the next cleaning strip?

### Hardware Required

- DC gear motors with built-in encoders
- One encoder on each drive wheel

### Wheel Circumference

Measure wheel diameter:

```text
D = Wheel Diameter
```

Wheel Circumference:

```text
C = π × D
```

One wheel revolution moves the robot approximately equal to the wheel circumference.

### Encoder Count

```c
encoder_count
```

`encoder_count` is a variable that stores how many encoder pulses have been received.

### Pulses Per Revolution

Check the motor datasheet to determine the number of pulses generated per revolution.

Example:

```text
20 Pulses Per Revolution
```

### Distance Per Pulse

```text
Distance Per Pulse = Wheel Circumference / Pulses Per Revolution
```

Example:

```text
Wheel Circumference = 25 cm
Pulses Per Revolution = 20

Distance Per Pulse = 25 / 20
                   = 1.25 cm
```

### Distance Travelled

```c
distance = encoder_count * distance_per_pulse;
```

This allows the robot to estimate how far it has travelled.

### Panel Parameters

Define:

- Panel Length
- Panel Width
- Brush Width

Example:

```text
Panel Length = 200 cm
Panel Width  = 100 cm
Brush Width  = 20 cm
```

These values are used for navigation and strip planning.

---

## Edge Detection

IR sensors are used to detect solar panel boundaries.

### Sensor Output

```text
1 = Panel Present
0 = Edge Detected
```

### Minimum Configuration

#### IR Sensors

- Front Left (FL)
- Rear Left (RL)
- Front Right (FR)
- Rear Right (RR)

#### Wheel Encoders

- Left Wheel Encoder
- Right Wheel Encoder

Purpose:

- Left edge detection
- Right edge detection
- Distance tracking

### Recommended Configuration

#### IR Sensors


Left Side:

- Left Front
- Left Rear

Right Side:

- Right Front
- Right Rear

optional but improves accuracy : 1 sensor and front,one sensor at back palced at bottom
#### Wheel Encoders

- Left Wheel Encoder
- Right Wheel Encoder

Purpose:

- Front edge detection
- Left edge detection
- Right edge detection
- Accurate position tracking

---

## Sensor Placement

```text
          FRONT

FL                      FR
↓                       ↓

+-----------------------+
|                       |
|        ROBOT          |
|                       |
+-----------------------+

↓                       ↓
RL                      RR

          REAR
```

All IR sensors face downward toward the solar panel surface.

---

## Working Principle

### Position Tracking

```text
Wheel Rotation
      ↓
Encoder Pulses
      ↓
Encoder Count
      ↓
Distance Calculation
      ↓
Position Estimation
```

### Edge Detection

```text
IR Sensor
      ↓
Panel Present ?
      ↓
Yes → Continue Movement

No
↓
Edge Detected
↓
Stop Robot
↓
Correct Direction
```

---

## Navigation Strategy

1. Robot starts moving along a cleaning strip.
2. Wheel encoders continuously count pulses.
3. Distance travelled is calculated.
4. Position is estimated using encoder data.
5. IR sensors continuously monitor panel boundaries.
6. If a left edge is detected, the robot moves right.
7. If a right edge is detected, the robot moves left.
8. After completing one strip, the robot shifts sideways by one brush width.
9. Cleaning continues on the next strip.

---


