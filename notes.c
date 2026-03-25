#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	return 0;
}

void question(char answer){
		printf("Welcome to notes book!\n Do you want to start entering notes? (y/n)");
		scanf("%c", &answer);
		if (answer == 'y'){
				int studentsNumber = 0;
				int enteredStudents = 0;
				char name[100][100];
				int numberNotes = 0;
				int enteredNotes = 0;
				int notes[100][100];
				int displayEnteredNotes = 0;
			enterNotes(studentsNumber, enteredStudents, name, numberNotes, enteredNotes, notes, displayEnteredNotes);
		}
		else if (answer == 'n'){
			displayMenu();
		}
		else {
			printf("You have do answer with 'y' (yes) or 'n' (no)");
		}
}

void enterNotes(int studentsNumber, int enteredStudents, char name[100][100], int numberNotes, int enteredNotes, int notes[][100], int displayEnteredNotes) {
	system("clear");
	printf("How many students do you have ? (1-100)");
	scanf("%d", studentsNumber);
	if (studentsNumber > 100){
		printf("Sorry, you have to enter a number of students between 1 and 100\n");
		enterNotes(studentsNumber, enteredStudents, name, numberNotes, enteredNotes, notes, displayEnteredNotes);
	}
	int i = 1;
	while (enteredStudents < studentsNumber){
		printf("Student number %d\n", i);
		printf("Name:\n");
		scanf("%s", name[i]);
		printf("Number of notes from %s ?", name[i]);
		scanf("%d", numberNotes);
		enteredNotes = 0;
		displayEnteredNotes = enteredNotes + 1;
		while (enteredNotes < numberNotes) {
			printf("Note number %d", displayEnteredNotes);
			scanf("%d", &notes[enteredNotes][enteredStudents]);
			enteredNotes++;
		}
		i++;
		enteredNotes = 0;
		}
}

void displayMenu(){

}