#OpenPad

OpenPad is an input device for your feet, meant to be used with [Stepmania](https://github.com/stepmania/stepmania). The goal of the project is to provide all the information and tools to build your own custom pad. Currently, OpenPad is using load cell sensors in an attempt to improve on the original arcade's rubber sensors, which often need to be replaced.

<img src="/images/Surface.jpg" width="600">
<img src="/images/PIU0.jpg" width="600">

#Sample Videos

Here are a couple videos that show previously built pads in action:

[Video 1](https://www.youtube.com/watch?v=cm8mnnq7L38)
[Video 2](https://goo.gl/photos/KiCTnwc1QsV53fR2A)

#Sensor

Load cells have proved exceptional sensors for dance pads for these reasons:

* Rated to withstand an arbitrarily large amount of weight. I've the 200kg ones.
* Only 1, max 2 required per sensing surface.
* Have not broken in the year tested.
* The data they provide is analog, and as such you can set the actuation force required through software

It does have some disadvantages:

* Since they must be screwed from the top and bottom, mounting holes must be precise
* Adjusting the hardware can be very tricky and time consuming, in order to maximize the readings from the sensors

#Project Structure

#####Arduino
This directory provides all the Arduino firmware and sketches so that your pad can act as an USB HID keyboard. Long gone are the days of having to dismantle your MadCatz PS2 controller.

#####Schematics
Here you will find 3D models, renders, and wiring schematics.

#####Images
Pictures of previous pads that have been built.