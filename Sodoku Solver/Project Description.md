# Sudoku Solver Game 🧩

A GUI-based **Sudoku Solver Game** developed using **C++** and the **Raylib** graphics library.
This project allows users to input Sudoku puzzles manually and solve them automatically using the **Backtracking Algorithm**.

---

## 📌 Features

* Interactive Sudoku Grid
* User-friendly GUI using Raylib
* Manual Number Input
* Automatic Sudoku Solver
* Clear Board Functionality
* Cell Selection Highlighting
* Real-time Board Updates

---

## 🚀 Technologies Used

* C++
* Raylib Graphics Library
* Backtracking Algorithm
* Object-Oriented Programming Concepts

---

## 🧠 Algorithm Used

The project uses the **Backtracking Algorithm** to solve Sudoku puzzles efficiently.

### Steps:

1. Find an empty cell.
2. Try numbers from 1 to 9.
3. Check if the number placement is valid.
4. Recursively solve the remaining board.
5. Backtrack if no valid number exists.

---

## 🎮 How to Play

1. Run the program.
2. Click on any empty cell.
3. Press numbers from **1-9** to input values.
4. Click the **SOLVE** button to solve the puzzle automatically.
5. Use **BACKSPACE** or **DELETE** to erase a number.
6. Click **CLEAR** to reset the board.

---

## 🛠️ Installation & Setup

### Prerequisites

* C++ Compiler (G++)
* Raylib Library Installed

### Compile the Project

```bash
g++ main.cpp -o sudoku -lraylib -lopengl32 -lgdi32 -lwinmm
```

### Run the Program

```bash
./sudoku
```

---

## 📷 GUI Components

* Sudoku Grid
* Solve Button
* Clear Button
* Instructions Panel
* Highlighted Selected Cell

---

## 🎯 Learning Outcomes

Through this project, I improved my understanding of:

* GUI Development
* Event Handling
* Recursion
* Backtracking Algorithms
* Problem Solving
* C++ Application Development

---

## 🙌 Acknowledgment

This project was developed as part of my **C++ Programming Internship at CodeAlpha**.

---
