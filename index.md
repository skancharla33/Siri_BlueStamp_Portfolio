# Arduino Game Console
The arduino game console is a console that allows the user to play one of two games: hangman and star chaser. The user uses the buttons on the console to choose between the two games and play them.
| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Siri K.| Irvington High School | Aerospace Engineering | Rising Junior


![Headstone Image](logo.svg)
  
# Final Milestone


# Second Milestone


# First Milestone


# Starter Project
  For my starter project, I chose to build the useless box. I chose to do this because I always wondered how flipping a switch wowuld cause an arm to move up from the box, flip the switch, and go back inside the box. Through building the useless box, I was able to find the answer to my question: flipping the switch triggers the motor, making it move counter-clockwise. This causes the arm, attached to the motor, to move up and out of the box. Once it moves far enough to flip the switch, the motor moves clockwise, moving the arm back to its original position. 

  Throughout the duration of this starter project, I ran into a couple of problems, mainly getting the motor to work and move the arm to flip the switch. When testing out the arm, the batteries began to overheat and give off smoke, which I later learned was caused by the solder that I applied on one of the two screw terminals. When I was soldering them in place, I accidentally created a “bridge,” which made the energy from the batteries travel through the bridge and back into the batteries, causing them to overheat. I fixed this problem by resoldering the screw terminals and removing the bridge between them.

<iframe width="560" height="315" src="https://www.youtube.com/embed/60VA6kidIu0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

# Schematics 

# Code

```c++
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

# Bill of Materials

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Cylewet 12Pcs 12mm Self-Locking Latching Push Button Switch | the buttons used to play the games | $6.99 | <a href="[https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/](https://www.amazon.com/Cylewet-Self-Locking-Latching-Button-CYT1091/dp/B075VBV4QH/ref=sr_1_3?crid=RCATN019DRYE&keywords=cylewet+self+locking+latching+push+button+switch&qid=1686851815&s=industrial&sprefix=cylewet+self+locking+latching+push+button+switch%2Cindustrial%2C136&sr=1-3)"> Link </a> |
|:--:|:--:|:--:|:--:|
| ItMT3608 Boost Converter | What the item is used for | $1.90 | <a href="[https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/](https://www.amazon.com/dp/B07TLJR2S9/ref=twister_B07TNPZHBR?_encoding=UTF8&psc=1)"> Link </a> |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|

# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.
