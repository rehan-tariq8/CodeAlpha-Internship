# CGPA Calculator with Raylib GUI

A modern and interactive **CGPA Calculator Application** developed in **C++** using **Raylib** for GUI implementation.
This project demonstrates the practical use of **Object-Oriented Programming (OOP)** concepts and **Data Structures (DSA)** while providing a visually appealing desktop application for calculating CGPA.

The application allows users to add multiple courses, enter grades and credit hours, calculate total credits and CGPA dynamically, and manage records with an interactive graphical interface.

---

## 🚀 Features

* Interactive GUI built with **Raylib**
* Add unlimited courses dynamically
* Input:

  * Course Name
  * Grade
  * Credit Hours
* Automatic CGPA calculation
* Total credits calculation
* Delete specific courses individually
* Dynamic course list rendering
* Multi-line course name support for long course titles
* Modern UI design with styled buttons and panels
* Real-time updates without restarting the application
* Responsive spacing and aligned interface
* Uses vectors for dynamic data storage
* Clean implementation of OOP principles

---

# 🖥️ GUI Functionalities

### Input Section

Users can:

* Enter course name
* Enter grade points
* Enter credit hours
* Add the course using the **ADD COURSE** button

### Course Display Table

The application displays:

* Course Name
* Grade
* Credit Hours
* Delete Button

### Dynamic Text Expansion

If a course name is too large:

* The row height automatically increases
* Text moves to the next line properly
* UI remains clean and readable

### Delete Feature

Each course has its own **DELETE** button:

* Removes the selected course instantly
* CGPA updates automatically

### Result Panel

Displays:

* Total Credits
* Calculated CGPA

---

# 🧠 OOP Concepts Used

## 1. Classes and Objects

Implemented:

* `Course` class
* `CGPACalculator` class

## 2. Encapsulation

Course data and CGPA calculations are managed inside classes.

## 3. Member Functions

Used for:

* Adding courses
* Deleting courses
* Calculating CGPA
* Getting total credits

---

# 📚 DSA Concepts Used

## Vector (Dynamic Array)

Used:

```cpp
vector<Course> courses;
```

Benefits:

* Dynamic memory allocation
* Easy insertion and deletion
* Efficient data handling

---

# 🛠️ Technologies Used

* C++
* Raylib
* STL Vector
* Object-Oriented Programming
* Data Structures & Algorithms

---

# ⚙️ How to Run the Project

## Step 1: Install Raylib

Download and install Raylib:

[Raylib Official Website](https://www.raylib.com/?utm_source=chatgpt.com)

---

## Step 2: Compile the Program

### Using g++

```bash
g++ main.cpp -o cgpa_app -lraylib -lopengl32 -lgdi32 -lwinmm
```

---

## Step 3: Run the Application

```bash
./cgpa_app
```

---

# 🧪 Example Inputs

| Course Name                  | Grade | Credits |
| ---------------------------- | ----- | ------- |
| Programming Fundamentals     | 3.7   | 3       |
| Data Structures & Algorithms | 3.5   | 4       |
| Object Oriented Programming  | 3.9   | 3       |
| Database Systems             | 3.4   | 3       |

---

# 📊 Sample Output

```text
TOTAL CREDITS : 13
CGPA : 3.62
```

---

# 🎯 Learning Outcomes

This project helps in understanding:

* GUI development using Raylib
* Event-driven programming
* Input handling in graphical applications
* Dynamic rendering techniques
* OOP implementation in real-world applications
* DSA usage in GUI-based systems
* User interaction management

---

# 🔥 Future Improvements

Possible future enhancements:

* Save CGPA records to file
* Edit existing courses
* Semester-wise GPA calculation
* Dark/Light theme switch
* Mouse cursor effects
* Keyboard navigation
* Export report as PDF
* Animation effects

---

# 📌 Conclusion

This CGPA Calculator is a complete beginner-to-intermediate level desktop application project that combines:

* GUI Programming
* OOP Concepts
* Data Structures
* Real-time Calculations
* User Interaction

The project is suitable for:

* Academic projects
* Portfolio showcase
* Internship tasks
* C++ GUI practice
* DSA + OOP implementation learning
