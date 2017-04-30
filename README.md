# Haunted House

This is a [video](https://www.youtube.com/watch?v=yRpC1_ZGsWk) of the 3rd annual haunted house that my daughters (aged 7 and 8) and I put on for our neighborhood:

[![Hanted house](https://img.youtube.com/vi/yRpC1_ZGsWk/0.jpg)](https://www.youtube.com/watch?v=yRpC1_ZGsWk)

[Watch the video](https://www.youtube.com/watch?v=yRpC1_ZGsWk)

All of the props, except for the spectral projection, are Arduino controlled, attached to IR sensors and pushbuttons.  This was the first year we introduced thunder along with the witch, and the all-new IKEA bed coffin.

## Light up ghost
![Light up ghost](https://cloud.githubusercontent.com/assets/51732/25567950/76afb4a2-2dc6-11e7-988d-d63e7122c591.jpg)

This was a simple Halloween prop from Christmas Tree Shop.  I took it apart, found the trigger circuit, and wired that in to a breadboard.  The breadboard connects up a 2N3904 transistor as the switch across the trigger circuit, a 47k-ohm resistor, and a HC-SR501 PIR sensor.  See [the Arduino file](PIRSensorGhost.ino) for all the details. 

## Spectral projection

![Spectral projection](https://cloud.githubusercontent.com/assets/51732/25568033/41900a7c-2dc8-11e7-8feb-ae18de8b96e8.jpg)

This is a looping Halloween video, projected onto a frosted clear shower curtain.  There is no sensor or controller this year, though I'm thinking about making one next year because when the timing is perfect, the spectre is very scary.

## Witch and thunder

## Hall of masks

## IKEA bed coffin with reaper
