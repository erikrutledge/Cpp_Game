## Terminal Greed - Overview
---
This is a 2-player game that runs in terminal/console. The main objective of the game is to take all the money from the other player without running out yourself.

Each player starts a number of lives and coins. The game entices both players by placing a random amount of money in the center pot. Each player takes their turn deciding if they want to steal the money or pass. Depending on both player choices they will be punished or rewarded following the game's rules.


## Game Rules
---
1. Each player starts with 3 lives and 50 coins.
2. The player can buy an extra life for 100 coins.
3. Players are limited to buying 1 life per round.
4. The amount of coins in the center pool is randomly generated from 0-100 coins.
5. If one person steals the money and the other passes, the player that chose to steal gets the money added to their wallet.
6. If both players choose to take the money, neither of them get it and they both lose that amount from their wallets.
7. If NEITHER player takes the money, it stays in the pot and gets added to the next round.
8. If a player hits drops below 0 coins in their wallet they lose a life and are set back to 50 coins.
9. No matter how many points below 0 the player would fall, they only lose 1 life and get 50 coins.
10. The game continues until one player is eliminated.


## Project Structure 
---
The project files and folders are organized as follows:
```
Terminal Greed          (root folder)
+-- README.md           (general info)
+-- greedgame           (source code for game)
  +-- greedgame.cpp     (C++ code file)
  +-- greedgame.exe     (executable game file)
```

## Video Walkthrough
https://youtu.be/iVJHJiF7BaI

## Development Environment
---
The project was written in C++ using the C/C++ Extension for VS Code.

## Future Improvements
---
- This program was written with maintainability in mind, and uses Classes to create the player objects. In the future I plan on adding a prompt to ask how many players will be in the game so I can create a loop that generates player objects according to the user input.
- I found out while testing that there needs to be an upper limit instead of just losing for reaching 0 lives. Right now it's possible to "pass" for every turn and never die, I'd like to add a coin limit that ends the game when a player reaches 500 for example. This has the added benefit of making purchasing lives more of a decision. 
- When players are inputing either "steal" or "pass" the other player needs to look away so they don't see what the other player is choosing. I have the console clear itself once the player presses enter, but I'd like to add an obscuring feature to prevent seeing what is being typed.

## Author Info
---
Erik Rutledge 
erik.rutledge14@gmail.com 
1/19/2023 
