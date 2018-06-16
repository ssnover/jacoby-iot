# Jacoby IoT
This is a project I'm undertaking for fun to implement a custom Raspberry Pi based solution to a small Internet of Things subnet in my home. The goals of this project are to implement three components: a C\++ application for organizing data and maybe presenting it, a serial protocol for communication between the Linux processor and microcontrollers, and a bare metal C\++ application for controlling some stuff and sensing some stuff.

# Components
* `nucleus` The C++ application running on the Raspberry Pi.
* `protocol` The serial protocol for talking between the `nucleus` and the `coprocessor`.
* `coprocessor` The bare metal application doing the sensing and actuating.

## Nucleus
### Goals
The following objectives are to be completed for v1.0.0 of the `nucleus` application.
* Conversion of Jacoby packet into a Nucleus command.
* Generation and transmission of Jacoby packets.
* Development of Nucleus command queue for processing commands.
* Logging of temperature sensor data.

### Current Features

## Protocol
Information on the Jacoby protocol can be found in the associated README, when I make it.

## Coprocessor
### Goals
The following objectives are to be completed for v1.0.0 of the `coprocessor` application.
* Control of an LED via Jacoby.
* Reporting temperature values over Jacoby.
* Complete implementation of the Jacoby protocol.
* Implementation for the Arduino Uno.