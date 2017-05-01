# Haunted House

This is a [video](https://www.youtube.com/watch?v=yRpC1_ZGsWk&rel=0) of the 3rd annual haunted house that my daughters (aged 7 and 8) and I put on for our neighborhood.  It's a great tradition for having fun, scaring our friends, and learning how to make new things.

[![Hanted house](https://img.youtube.com/vi/yRpC1_ZGsWk/0.jpg)](https://www.youtube.com/watch?v=yRpC1_ZGsWk&rel=0)

[Watch the video](https://www.youtube.com/watch?v=yRpC1_ZGsWk&rel=0)

All of the props, except for the spectral projection, are Arduino controlled, attached to IR sensors and pushbuttons.  This was the first year we introduced thunder along with the witch, and the all-new IKEA bed coffin.

## Light up ghost
![Light up ghost](https://cloud.githubusercontent.com/assets/51732/25567950/76afb4a2-2dc6-11e7-988d-d63e7122c591.jpg)

This was a simple Halloween prop from Christmas Tree Shop.  I took it apart, found the trigger circuit, and wired that in to a breadboard.  The breadboard connects up a 2N3904 transistor as the switch across the trigger circuit, a 47k-ohm resistor, and a HC-SR501 PIR sensor.  See [the Arduino file](PIRSensorGhost.ino) for all the details. 

## Spectral projection

![Spectral projection](https://cloud.githubusercontent.com/assets/51732/25568033/41900a7c-2dc8-11e7-8feb-ae18de8b96e8.jpg)

This is a looping Halloween video, projected onto a frosted clear shower curtain.  There is no sensor or controller this year, though I'm thinking about making one next year because when the timing is perfect, the spectre is very scary.

## Witch and thunder

![Witch](https://cloud.githubusercontent.com/assets/51732/25568061/fbf3b8d2-2dc8-11e7-9fd4-4ef74aa7005c.jpg)

This is another prop from Christmas Tree Shop that I hacked apart to be [trigger from an IR sensor](PIRSensorWitch.ino).  I found it handy to use CAT5 cable to run lines from her head/neck where the motor was down to the Arduino on the ground.  The video doesn't do it justice, but there's a cauldron with smoke from a fog machine, and flashing banks of LED lights in the cauldron controlled by DMX (the [protocol](https://en.wikipedia.org/wiki/DMX512), not the [rapper](https://en.wikipedia.org/wiki/DMX_(rapper)))

Also, for the first time this year, there's a loud thunderclap produced by a second [Arduino](Thunder.ino) driving an amplified speaker using pulse code modulation.  This [high-low tech tip](http://highlowtech.org/?p=1963) was extremely handy.  Since this is triggered by the IR sensor, the timing is almost always perfect for a good startle.


## Hall of masks

![Hall of Masks](https://cloud.githubusercontent.com/assets/51732/25568211/ec2218f6-2dcb-11e7-9f6b-93d72d714607.jpg)

This one is pure low tech.  Inspired by this [blog post](http://mizerella.blogspot.com/2011/01/13-black-light-mask-room.html), we glued a bunch of plastic masks to black plastic hung from the ceiling.  Add in a spooky whispers soundtrack plus black lights and this hallway becomes the freakiest part of the house.  If you really want to scare your guests, dress in all black, wear a matching mask, and stand in the corner.  No one will notice you until you jump out, causing lasting trauma.  This has been a go-to prop for us since the first annual haunted house, so it's time to lovingly retire it.

## IKEA bed coffin with reaper
<img src="https://cloud.githubusercontent.com/assets/51732/25568774/6e81d578-2dd8-11e7-9666-294577dc787b.jpg" width="400"><img src="https://cloud.githubusercontent.com/assets/51732/25568773/6e80942e-2dd8-11e7-8406-ba28a44974a3.jpg" width="400"><img src="https://cloud.githubusercontent.com/assets/51732/25568772/6e7d6e20-2dd8-11e7-9ed1-34c41da56660.jpg" width="400"><img src="https://cloud.githubusercontent.com/assets/51732/25568775/6e859884-2dd8-11e7-9835-77823620d723.jpg">

