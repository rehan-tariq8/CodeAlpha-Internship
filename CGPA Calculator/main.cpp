#include "raylib.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

// COURSE CLASS
class Course {
public:
    char courseName[100];
    float grade;
    int creditHours;

    Course(const char* name, float g, int ch) {
        strcpy(courseName, name);
        grade = g;
        creditHours = ch;
    }

    float getGradePoints() const {
        return grade * creditHours;
    }
};

// CGPA CALCULATOR
class CGPACalculator {
private:
    vector<Course> courses;

public:

    void addCourse(const char* name, float grade, int credits) {
        courses.push_back(Course(name, grade, credits));
    }

    void deleteCourse(int index) {

        if (index >= 0 && index < (int)courses.size()) {
            courses.erase(courses.begin() + index);
        }
    }

    float calculateCGPA() {

        float totalPoints = 0;
        int totalCredits = 0;

        for (size_t i = 0; i < courses.size(); i++) {

            totalPoints += courses[i].getGradePoints();
            totalCredits += courses[i].creditHours;
        }

        if (totalCredits == 0)
            return 0;

        return totalPoints / totalCredits;
    }

    int getTotalCredits() {

        int total = 0;

        for (size_t i = 0; i < courses.size(); i++) {
            total += courses[i].creditHours;
        }

        return total;
    }

    vector<Course>& getCourses() {
        return courses;
    }
};

// MAIN
int main() {

    const int screenWidth = 1200;
    const int screenHeight = 850;

    InitWindow(screenWidth, screenHeight, "CGPA Calculator");

    SetTargetFPS(60);

    CGPACalculator calculator;

    char courseName[100] = "";
    char gradeInput[10] = "";
    char creditInput[10] = "";

    int activeInput = 0;

    while (!WindowShouldClose()) {

        // INPUT HANDLING

        int key = GetCharPressed();

        while (key > 0) {

            if ((key >= 32) && (key <= 125)) {

                if (activeInput == 1 && strlen(courseName) < 99) {

                    int len = strlen(courseName);

                    courseName[len] = (char)key;
                    courseName[len + 1] = '\0';
                }

                else if (activeInput == 2 && strlen(gradeInput) < 9) {

                    int len = strlen(gradeInput);

                    gradeInput[len] = (char)key;
                    gradeInput[len + 1] = '\0';
                }

                else if (activeInput == 3 && strlen(creditInput) < 9) {

                    int len = strlen(creditInput);

                    creditInput[len] = (char)key;
                    creditInput[len + 1] = '\0';
                }
            }

            key = GetCharPressed();
        }

        // BACKSPACE

        if (IsKeyPressed(KEY_BACKSPACE)) {

            if (activeInput == 1) {

                int len = strlen(courseName);

                if (len > 0)
                    courseName[len - 1] = '\0';
            }

            else if (activeInput == 2) {

                int len = strlen(gradeInput);

                if (len > 0)
                    gradeInput[len - 1] = '\0';
            }

            else if (activeInput == 3) {

                int len = strlen(creditInput);

                if (len > 0)
                    creditInput[len - 1] = '\0';
            }
        }

        // INPUT BOXES

        Rectangle nameBox = {80, 140, 350, 50};
        Rectangle gradeBox = {470, 140, 120, 50};
        Rectangle creditBox = {640, 140, 120, 50};

        // ADD BUTTON

        Rectangle addButton = {850, 140, 180, 50};

        if (CheckCollisionPointRec(GetMousePosition(), addButton)
            && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            if (strlen(courseName) > 0 &&
                strlen(gradeInput) > 0 &&
                strlen(creditInput) > 0) {

                float grade = atof(gradeInput);
                int credits = atoi(creditInput);

                calculator.addCourse(courseName, grade, credits);

                strcpy(courseName, "");
                strcpy(gradeInput, "");
                strcpy(creditInput, "");
            }
        }

        // INPUT CLICK

        if (CheckCollisionPointRec(GetMousePosition(), nameBox)
            && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            activeInput = 1;
        }

        else if (CheckCollisionPointRec(GetMousePosition(), gradeBox)
            && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            activeInput = 2;
        }

        else if (CheckCollisionPointRec(GetMousePosition(), creditBox)
            && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

            activeInput = 3;
        }

        // DRAWING

        BeginDrawing();

        ClearBackground(Color{18, 18, 28, 255});

        // TITLE

        DrawText("CGPA CALCULATOR", 360, 40, 42, SKYBLUE);

        // LABELS

        DrawText("Course Name", 80, 105, 22, LIGHTGRAY);
        DrawText("Grade", 470, 105, 22, LIGHTGRAY);
        DrawText("Credits", 640, 105, 22, LIGHTGRAY);

        // INPUT BOXES

        DrawRectangleRounded(nameBox, 0.2f, 10,
                             activeInput == 1 ? DARKBLUE : GRAY);

        DrawRectangleRounded(gradeBox, 0.2f, 10,
                             activeInput == 2 ? DARKBLUE : GRAY);

        DrawRectangleRounded(creditBox, 0.2f, 10,
                             activeInput == 3 ? DARKBLUE : GRAY);

        DrawText(courseName, 90, 155, 22, WHITE);
        DrawText(gradeInput, 500, 155, 22, WHITE);
        DrawText(creditInput, 670, 155, 22, WHITE);

        // ADD BUTTON

        DrawRectangleRounded(addButton, 0.3f, 10, GREEN);

        const char* addText = "ADD COURSE";

        int addTextWidth = MeasureText(addText, 22);

        DrawText(
            addText,
            addButton.x + (addButton.width - addTextWidth) / 2,
            addButton.y + 14,
            22,
            WHITE
        );

        // TABLE HEADER

        DrawRectangle(70, 240, 1060, 45, DARKBLUE);

        DrawText("Course Name", 100, 252, 22, WHITE);
        DrawText("Grade", 650, 252, 22, WHITE);
        DrawText("Credits", 780, 252, 22, WHITE);
        DrawText("Delete", 950, 252, 22, WHITE);

        // COURSE LIST

        vector<Course>& courses = calculator.getCourses();

        int startY = 310;

        for (size_t i = 0; i < courses.size(); i++) {

            string name = courses[i].courseName;

            int maxCharsPerLine = 30;

            vector<string> lines;

            for (size_t j = 0; j < name.length(); j += maxCharsPerLine) {

                lines.push_back(name.substr(j, maxCharsPerLine));
            }

            // Dynamic row height
            int rowHeight = 40 + (lines.size() * 28);

            DrawRectangleRounded(
                {(float)80, (float)startY, 1000, (float)rowHeight},
                0.2f,
                10,
                Color{40, 40, 60, 255}
            );

            // COURSE NAME

            for (size_t line = 0; line < lines.size(); line++) {

                DrawText(
                    lines[line].c_str(),
                    100,
                    startY + 12 + (line * 24),
                    20,
                    WHITE
                );
            }

            // CENTERED TEXT

            int centerY = startY + (rowHeight / 2) - 10;

            DrawText(
                TextFormat("%.2f", courses[i].grade),
                660,
                centerY,
                22,
                YELLOW
            );

            DrawText(
                TextFormat("%d", courses[i].creditHours),
                800,
                centerY,
                22,
                ORANGE
            );

            // DELETE BUTTON

            Rectangle deleteBtn = {
                920,
                (float)(startY + (rowHeight / 2) - 20),
                120,
                40
            };

            DrawRectangleRounded(deleteBtn, 0.3f, 10, RED);

            const char* deleteText = "DELETE";

            int deleteTextWidth = MeasureText(deleteText, 20);

            DrawText(
                deleteText,
                deleteBtn.x + (deleteBtn.width - deleteTextWidth) / 2,
                deleteBtn.y + 10,
                20,
                WHITE
            );

            // DELETE FUNCTION

            if (CheckCollisionPointRec(GetMousePosition(), deleteBtn)
                && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

                calculator.deleteCourse((int)i);
                break;
            }

            // Dynamic spacing between rows
            startY += rowHeight + 20;
        }

        // RESULT BOX

        float cgpa = calculator.calculateCGPA();

        DrawRectangleRounded(
            {(float)350, 720, 500, 90},
            0.2f,
            10,
            Color{30, 60, 90, 255}
        );

        DrawText(
            TextFormat("TOTAL CREDITS : %d",
                       calculator.getTotalCredits()),
            390,
            740,
            28,
            WHITE
        );

        DrawText(
            TextFormat("CGPA : %.2f", cgpa),
            390,
            775,
            30,
            GREEN
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}