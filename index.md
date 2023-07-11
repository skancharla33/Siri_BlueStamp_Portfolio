# Arduino Game Console
The arduino game console is a console that allows the user to play one of two games: hangman and star chaser. The user uses the buttons on the console to choose between the two games and play them. The game console also includes a pentiometer and a passive buzzer, which produces the sound effects from the games. 

<!-- Replace this text with a brief description (2-3 sentences) of your project. This description should draw the reader in and make them interested in what you’ve built. You can include what the biggest challenges, takeaways, and triumphs from completing the project were. As you complete your portfolio, remember your audience is less familiar than you are with all that your project entails! FIX BIO FORMATTING -->

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Siri K.| Irvington High School | Aerospace Engineering | Rising Junior


![Headstone Image](logo.svg)
  
# Final Milestone

  Since the completion of my second milestone, I have added the code and made sure the games work properly. The conosle is now fully functioning, though I would still like to add another game to the console. As a result of my decision, the bottom of the console is not yet secured.
  One of the biggest challenges for this milestone was getting the code to display on the LCD screen. I later learned that the problem was the display contrast, which I was easily able to fix. The next big challenge was getting the buttons to work. As a result of weak soldering, the 'D' button wouldn't work during one of the games, and the problem was fixed after redoing the soldering. The biggest challenge during the project was getting the LCD to light up and wiring the PCB, since I had to do thos since scratch. My biggest triumph was being able to get the LCD to turn on, since it was a problem I tried to fix for the longest time.
  Some key topics I learned throughout this project include learning how to use wires to recreate PCBs, how to drill, dremel, and cut acrylic, and code and troubleshoot. I learned that bridging helps connect mulitple wires together, and that they have to be secure so that there won't be any loose connections. I also learned that there are many ways to solve a specific issue, and you should keep finding those solutions because they might be easier. I hope to learn more about the different functions of each wiring connection after Bluestamp, as well as how to create more Arduino projects. 

<!-- https://www.youtube.com/watch?v=KGnOF_G8m-U + https://www.instructables.com/Arduino-LCD-Game/ - modifications -->

# Second Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/yEASH0IJAb4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  After finishing the PCB, I worked on adding the acrylic pieces to the game console. I ended up cutting and sanding the acrylic by hand so it could easily fit in the console. The acrylic also prevents the wires from going all over the place. I hot glued everything together once I was sure the LCD could turn on without having to hold the wires in a certain way. A big challenge I faced was trying to get the LCD to light up. I was able to get it to light up after realizing that it wasn't working because I didn't solder two wires together. Another challenge I faced was having to adjust the size of the hole the LCD would go in. Since it was too small for the LCD, I had to use a dremel to cut of some of the 3D print, which was challenging because I had to avoid all the wires that were still attached to the console. Next I will be adding the games to the console, which will be my third milestone. 

# First Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/J0KFbBLnFsk" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  My project is the Arduino game console, and to build it, I need to first start with assembling the PCB. It consists of mulitple pieces, such as the push buttons, that let the user play the games on the console, the potentiometer, which essentially control the volume, multiple wires which connect all the different parts to the Arduino nano inside, and most importantly, the LCD screen. So far, I have assembled the PCB and connected all the wires so that when connected to a power source, the LCD screen should light up. The biggest challenge I have faced so far was trying to recreate the PCB from scratch and modifying it. The next step would be to finish assembling the rest of the console so I can start adding the games to it.

# Starter Project
<iframe width="560" height="315" src="https://www.youtube.com/embed/60VA6kidIu0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

  For my starter project, I chose to build the useless box. I chose to do this because I always wondered how flipping a switch would cause an arm to move up from the box, flip the switch, and go back inside the box. Through building the useless box, I was able to find the answer to my question: flipping the switch triggers the motor, making it move counter-clockwise. This causes the arm, attached to the motor, to move up and out of the box. Once it moves far enough to flip the switch, the motor moves clockwise, moving the arm back to its original position. 

  Throughout the duration of this starter project, I ran into a couple of problems, mainly getting the motor to work and move the arm to flip the switch. When testing out the arm, the batteries began to overheat and give off smoke, which I later learned was caused by the solder that I applied on one of the two screw terminals. When I was soldering them in place, I accidentally created a “bridge,” which made the energy from the batteries travel through the bridge and back into the batteries, causing them to overheat. I fixed this problem by resoldering the screw terminals and removing the bridge between them.



<!-- # Schematics 

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
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|

# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here. -->
