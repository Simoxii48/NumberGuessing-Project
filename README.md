# Number Guessing Game - C++ Console Application

A console-based **Number Guessing Game** built using C++ where the player tries to guess a randomly generated number between 1 and 100.

This project focuses on **user interaction, input validation, and game state management**, while maintaining clean and modular code design.

---

## 🚀 Features

- 🎲 Random number generation (1–100)
- 🎯 User guess system with feedback:
  - Too High
  - Too Low
  - Correct
- 🔁 Continuous play (Play Again option)
- 🏆 Best score tracking (minimum attempts)
- ✅ Input validation for robust user experience

---

## 🧠 Core Concepts Applied

- **Enums (`enum`)** to represent guess results (High / Low / Equal)  
- **Structs (`struct`)** to organize:
  - Round data  
  - Game state (best score)  
- **Modular function design**  
- **Loop control & game flow management**  
- **Random number generation using `rand()`**  
- **Input validation using `cin.clear()` and `cin.ignore()`**  

---

## ⚙️ How It Works

1. The program generates a random number between 1 and 100  
2. The player inputs guesses  
3. The system provides feedback:
   - "Too High"  
   - "Too Low"  
4. The loop continues until the correct number is guessed  
5. The program tracks and updates the **best score (fewest attempts)**  

---

## 🛠️ How to Run

### Compile:
```bash
g++ -std=c++11 NumberGuessing.cpp -o game
./game
