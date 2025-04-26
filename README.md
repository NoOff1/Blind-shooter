# Blind-shooter
Blind shooter CLI game written in C.

# Overview
A simple and fun command-line game where you and the computer compete to find a hidden target on a 4x4 grid.
Take turns aiming — first one to hit the secret spot wins!

# Gameplay
- You and the computer take turns choosing a number from 1 to 16.
- Each number represents a cell on a 4×4 battlefield.
- The target is hidden randomly at the start.
- If you guess the right spot — you win!
- If the computer finds it first — you lose.

# Features
- Turn-based gameplay (you vs. computer).
- Random target generation every game.
- Input validation (only valid numbers allowed).
- Simple and readable CLI grid.
- Friendly win/lose messages.

# Compilation
Compile the code with `gcc -o blind_shooter blind_shooter.c`.
