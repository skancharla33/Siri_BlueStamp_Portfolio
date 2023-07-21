# Arduino Game Console
The arduino game console is a console that allows the user to play one of two games: hangman and star chaser. The user uses the buttons on the console to choose between the two games and play them. The game console also includes a pentiometer and a passive buzzer, which produces the sound effects from the games. 

<!-- Replace this text with a brief description (2-3 sentences) of your project. This description should draw the reader in and make them interested in what you’ve built. You can include what the biggest challenges, takeaways, and triumphs from completing the project were. As you complete your portfolio, remember your audience is less familiar than you are with all that your project entails! FIX BIO FORMATTING -->

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Siri K.| Irvington High School | Aerospace Engineering | Rising Junior


![Headstone Image](logo.svg)
# Modification
  For my modification, I chose to add a third game to the game console. Finding one that would match the demensions of my LCD was very challenging, so I settled for games meant for 16x2 LCDs. Originally, I chose to code a two player ping pong game, but since the code had too many issues, I chose flappy bird. I ended up having a similar problem with flappy bird, so I searched for different games until I found space invaders. After changing the code a little, the game worked perfectly. However, the game still hasn't been added to the original code, so I hope to do that next, as well as add more games to the console in the future.
  Some key topics I learned throughout this project include learning how to use wires to recreate PCBs, how to drill, dremel, and cut acrylic, and code and troubleshoot. I learned that bridging helps connect mulitple wires together, and that they have to be secure so that there won't be any loose connections. I also learned that there are many ways to solve a specific issue, and you should keep finding those solutions because they might be easier. I hope to learn more about the different functions of each wiring connection after Bluestamp, as well as how to create more Arduino projects. 
  
# Final Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/7_M6H3smQ3E" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  Since the completion of my second milestone, I have added the code and made sure the games work properly. The conosle is now fully functioning, though I would still like to add another game to the console. As a result of my decision, the bottom of the console is not yet secured.
  One of the biggest challenges for this milestone was getting the code to display on the LCD screen. I later learned that the problem was the display contrast, which I was easily able to fix. The next big challenge was getting the buttons to work. As a result of weak soldering, the 'D' button wouldn't work during one of the games, and the problem was fixed after redoing the soldering. The biggest challenge during the project was getting the LCD to light up and wiring the PCB, since I had to do thos since scratch. My biggest triumph was being able to get the LCD to turn on, since it was a problem I tried to fix for the longest time.

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
``` -->

# Bill of Materials

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Arduino Nano [A000005]| contains the code + displays it on the LCD screen | $26.00 | <a href="https://www.amazon.com/Arduino-A000005-ARDUINO-Nano/dp/B0097AU5OU/ref=sr_1_15?keywords=arduino+nano&qid=1689619724&sprefix=ardui%2Caps%2C312&sr=8-15"> Link </a>|
|:--:|:--:|:--:|:--:|
| Push Buttons | the buttons used to play the games | $12.49 | <a href="https://www.amazon.com/dp/B09BKXT1J1/ref=redir_mobile_desktop?_encoding=UTF8&aaxitk=e5ba732c2d3ca4c21552ac330b3c7721&content-id=amzn1.sym.43de8b42-cb89-4910-88e0-25fae4edd09e%3Aamzn1.sym.43de8b42-cb89-4910-88e0-25fae4edd09e&hsa_cr_id=8823072600001&pd_rd_plhdr=t&pd_rd_r=b0be636c-167c-4005-8e93-7c5ca7bdcd33&pd_rd_w=EZTWJ&pd_rd_wg=7vyMv&qid=1689619885&ref_=sbx_be_s_sparkle_lsi4d_asin_0_img&sr=1-1-5aa29f2a-1490-4ae2-848e-815fb6406bcf"> Link </a> |
|:--:|:--:|:--:|:--:|
| 20x4 LCD with IIC | displays the game code | $20.99 | <a href="https://www.amazon.com/Backlight-Module-Shield-Character-R3，Yellow-Green/dp/B09L15ZRDB/ref=sr_1_23_sspa?crid=1X766E6X1OC1U&keywords=20x4+lcd+green&qid=1689619992&s=industrial&sprefix=20x4+lcd+green%2Cindustrial%2C225&sr=1-23-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9idGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Power Switch | turns on the LCD and starts the code | $5.99 | <a href="https://www.amazon.com/5Pcs-Rocker-Switch-Position-QTEATAK/dp/B07Y1GDRQG/ref=sr_1_31_sspa?crid=3IIKEQV8TQU6A&keywords=power%2Bswitch&qid=1689620179&s=industrial&sprefix=power%2Bswitch%2Cindustrial%2C172&sr=1-31-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9idGY&th=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Passive Buzzer | plays the sounds for the games | $7.99 | <a href="https://www.amazon.com/Gikfun-Terminals-Passive-Electronic-Arduino/dp/B01GJLE5BS/ref=sr_1_1_sspa?crid=10R1ME2HY8TNB&keywords=passive+buzzer&qid=1689620324&s=industrial&sprefix=passive+buzze%2Cindustrial%2C163&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| 5K Potentiometer | controls the volume of the buzzer sounds | $9.29 | <a href="https://www.amazon.com/HiLetgo-Single-Joint-Potentiometer-Variable-Resistors/dp/B00N1ZIXKA/ref=sr_1_1_sspa?crid=2NR1CC9X47527&keywords=5k+potentiometer&qid=1689620479&s=industrial&sprefix=5k+potentiometer%2Cindustrial%2C203&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| PCB Slide Switch | when flipped with the power switch, the LCD turns on | $5.39 | <a href="https://www.amazon.com/HiLetgo-SS-12D00-Toggle-Switch-Vertical/dp/B07RTJDW27/ref=sr_1_1_sspa?crid=L9I00AUUZ6FI&keywords=pcb+slide+switch&qid=1689704060&sprefix=pcb+slide+switch%2Caps%2C209&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Jumper Wires | connects the LCD to the screw terminals | $6.99 | <a href="https://www.amazon.com/EDGELEC-Breadboard-Optional-Assorted-Multicolored/dp/B07GD2BWPY/ref=sr_1_1_sspa?crid=2QFB4HN24N83&keywords=jumper%2Bwires&qid=1689704142&sprefix=jumper%2Bwires%2Caps%2C177&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Wires | connects to the PCB parts | $8.99 | <a href="https://www.amazon.com/Fermerry-Silicone-Electrical-Cables-Stranded/dp/B089D2B6T6/ref=sr_1_1_sspa?crid=1REQ7JJZ2YCNK&keywords=wires&qid=1689704239&sprefix=wires%2Caps%2C222&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Screw terminals | holds multiple wires | $8.99 | <a href="https://www.amazon.com/Tnisesm-0-2inch-Terminal-Connector-Spliced/dp/B088LSS14J/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.1c86ab1a-a73c-4131-85f1-15bd92ae152d%3Aamzn1.sym.1c86ab1a-a73c-4131-85f1-15bd92ae152d&crid=2WFAVKKDE9HRQ&cv_ct_cx=screw+terminal&keywords=screw+terminal&pd_rd_i=B088LSS14J&pd_rd_r=3bfba2d0-d147-454b-903e-613e748f20cb&pd_rd_w=XdRQl&pd_rd_wg=7mtsr&pf_rd_p=1c86ab1a-a73c-4131-85f1-15bd92ae152d&pf_rd_r=X3RS20J0PQWFG8DW3T8S&qid=1689704357&sbo=RZvfv%2F%2FHxDF%2BO5021pAnSA%3D%3D&sprefix=screw+t%2Caps%2C175&sr=1-2-364cf978-ce2a-480a-9bb0-bdb96faa0f61-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9zZWFyY2hfdGhlbWF0aWM&psc=1"> Link </a> |
|:--:|:--:|:--:|:--:|
| Anker Power Core | provides power to the game console | $17.99 | <a href="https://www.amazon.com/Anker-PowerCore-Ultra-Compact-High-Speed-Technology/dp/B01CU1EC6Y/ref=sr_1_5?keywords=anker+power+core&qid=1689704440&sr=8-5"> Link </a> |
|:--:|:--:|:--:|:--:|


<!-- # Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here. -->
