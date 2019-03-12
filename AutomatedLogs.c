#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
	bool active;
	char name[150];
	char timeStart[15];
	char timeStop[15];
}ACTIVITY;

ACTIVITY activities[20]; // max of 20 activities a day, i think you don't do much more than that in total
int aCounter = 0;

time_t secs;
struct tm *local;
char timeString[15];

void Startd(), Add(), Stop(), Folder(), SaveCur(), GetTimeH();

int main() {
	
	secs = time(0);
	local = localtime(&secs);

	strftime(timeString, sizeof(timeString), "%H:%M:%S", local);

	//printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
<<<<<<< HEAD

	char* f = malloc(7);
=======
 
	char*caller = malloc(7),
		arg1 = malloc(50),
		arg2 = malloc(50),
		arg3 = malloc(50);
>>>>>>> 6417a48134e133296b911198e044115c2870d11d
	char path[100];

	char start[] = "start",
		add[] = "add",
		stop[] = "stop",
		folder[] = "folder",
		savecur[] = "savecur";

<<<<<<< HEAD
	while (strcmp(f, stop) != 0) {
		gets(f);
=======
	void Startd(), Add(), Stop(), Folder(), SaveCur();

	while (strcmp(caller, stop) != 0) {
		scanf("%c %c %c %c" ,caller, arg1, arg2, arg3);
>>>>>>> 6417a48134e133296b911198e044115c2870d11d
		
		if (strcmp(caller, start) == 0) {
			Startd();
		}
		else if (strcmp(caller, add) == 0) {
			Add();
		}
		else if (strcmp(caller, folder) == 0) {
			Folder(path);
		}
		else if (strcmp(caller, savecur) == 0) {
			SaveCur();
		}
		else if (strcmp(caller, "help") == 0) {
			printf("\ncommands:\nstart : 'takes one argument, argument is\n the activity you're about to start.\n\nadd : takes three arguments, first is the activity, \nsecond is time started, third is time it ended.\n\nstop : has two options, 'current' and 'day', \ncurrent stops current activity, day stops the day.\n\nfolder : takes one argument, path where you want your .txt's and .pdf's stored.\n");
			fflush(stdout);
		}
		else if(strcmp(caller, "") == 0 || strcmp(caller, stop)) {
			printf("\nnot a valid command, type 'help' for more information\n");
			fflush(stdout);
		}
	}

<<<<<<< HEAD
	free(f);
=======
	free(caller);
	free(arg1);
	free(arg2);
	free(arg3);
>>>>>>> 6417a48134e133296b911198e044115c2870d11d

	return 0;
}

void Startd() {
	
	fflush(stdout);

	printf("what activity do you want to start? : ");
	fflush(stdout);

	activities[aCounter].active = true;
	gets(activities[aCounter].name);

	GetTimeH();
	strcpy(activities[aCounter].timeStart, timeString);
	printf("\nActivity started at: ");
	printf(timeString);
	printf("\n");
	fflush(stdout);
}

void Add() {

}

void Stop() {
	
}

void Folder(char path[]) {
	gets(path);
	printf("\nFolder has been set to: ");
	printf(path);
	printf("\n");
	fflush(stdout);
}

void SaveCur() {
	GetTimeH();
	printf("activity ");
	printf(activities[aCounter].name);
	printf(" stopped.\n");
	strcpy(activities[aCounter].timeStop, timeString);
	fflush(stdout);
	aCounter = aCounter + 1;
}

void GetTimeH() {
	secs = time(0);
	local = localtime(&secs);
	strftime(timeString, sizeof(timeString), "%H:%M:%S", local);
}