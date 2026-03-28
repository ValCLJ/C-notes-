#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void question();
void enterNotes(int *studentsNumber, int *enteredStudents, char name[100][100], int *numberNotes, int *enteredNotes, int notes[100][100], int *displayEnteredNotes);
void displayMenu();

int main(int argc, char* argv[]) {
    question();
    return 0;
}

void question() {
    char answer;
    printf("Welcome to notes book!\nDo you want to start entering notes? (y/n): ");
    scanf(" %c", &answer);  // Note: space before %c to consume newline
    if (answer == 'y') {
        int studentsNumber = 0;
        int enteredStudents = 0;
        char name[100][100];
        int numberNotes = 0;
        int enteredNotes = 0;
        int notes[100][100];
        int displayEnteredNotes = 0;
        enterNotes(&studentsNumber, &enteredStudents, name, &numberNotes, &enteredNotes, notes, &displayEnteredNotes);
    } else if (answer == 'n') {
        displayMenu();
    } else {
        printf("You have to answer with 'y' (yes) or 'n' (no)\n");
        question();  // Retry
    }
}

void enterNotes(int *studentsNumber, int *enteredStudents, char name[100][100], int *numberNotes, int *enteredNotes, int notes[100][100], int *displayEnteredNotes) {
    system("clear");
    printf("How many students do you have? (1-100): ");
    scanf("%d", studentsNumber);
    if (*studentsNumber < 1 || *studentsNumber > 100) {
        printf("Sorry, you have to enter a number of students between 1 and 100\n");
        enterNotes(studentsNumber, enteredStudents, name, numberNotes, enteredNotes, notes, displayEnteredNotes);
        return;
    }
    int i = 0;  // Start from 0
    while (*enteredStudents < *studentsNumber) {
        printf("Student number %d\n", i + 1);
        printf("Name: ");
        scanf("%s", name[i]);
        printf("Number of notes for %s? ", name[i]);
        scanf("%d", numberNotes);
        if (*numberNotes < 1 || *numberNotes > 100) {
            printf("Number of notes must be between 1 and 100\n");
            continue;  // Retry for this student
        }
        *enteredNotes = 0;
        *displayEnteredNotes = 1;
        while (*enteredNotes < *numberNotes) {
            printf("Note number %d: ", *displayEnteredNotes);
            scanf("%d", &notes[*enteredNotes][i]);
            (*enteredNotes)++;
            (*displayEnteredNotes)++;
        }
        i++;
        (*enteredStudents)++;
    }
    // After entering all, perhaps display or save, but for now, end
    printf("All notes entered.\n");
}

void displayMenu() {
    printf("Menu not implemented yet.\n");
}