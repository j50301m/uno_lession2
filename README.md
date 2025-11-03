# Arduino LED Brightness Control Project

[中文](README-zh.md)

## Project Description

This project is designed as an Arduino practice project for learning **button debouncing** techniques and **analog output** functionality.

## Features

- Control LED brightness using a button
- Implement button debouncing mechanism to prevent false triggers
- Control LED brightness through PWM (analog output)
- 5-level brightness adjustment: 0, 64, 128, 192, 255

## Wiring Instructions

- **LED Positive**: Connect to Pin 9 (PWM output pin)
- **Button**: Connect to Pin 2 (using internal pull-up resistor)
- **LED Negative**: Connect to GND through appropriate resistor
- **Button Other End**: Connect to GND

## Working Principle

1. **Button Debouncing**: Uses time interval detection to avoid multiple triggers caused by mechanical button bounce
2. **Analog Output**: Uses `analogWrite()` function to generate PWM signals for LED brightness control
3. **State Cycling**: Each button press increases brightness by one level, returning to 0 after reaching maximum value

## Learning Objectives

- Digital input processing and debouncing techniques
- PWM analog output principles and applications
- Arduino basic I/O operations
- State machine programming concepts

## Usage

1. Press the button to gradually increase LED brightness
2. 4 brightness levels available for cycling
3. After reaching maximum brightness, next button press returns to minimum brightness

## Technical Specifications

- Debounce delay: 25 milliseconds
- Brightness levels: 4 stages (0, 64, 128, 192)
- PWM frequency: Arduino default (~490Hz)