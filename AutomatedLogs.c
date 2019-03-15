#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <time.h>
#include <stdbool.h>

typedef struct { // activity struct, has 4 variables that determen what you did and when
	bool active;
	char name[150];
	char timeStart[15];
	char timeStop[15];
}ACTIVITY;

ACTIVITY activities[20]; // max of 20 activities a day, i think you don't do much more than that in total
int aCounter = 0; // counter for activities array

time_t secs; // time from epoch in secs
struct tm *local; // local time info
char timeString[15]; // char that gets time pushed in as char

void Startd(), Add(), Stop(), Folder(), SaveCur(), GetTimeH(); // void functions

int main() {
	
	secs = time(0); // declare secs on epoch 
	local = localtime(&secs); // get localtime with help of secs

	strftime(timeString, sizeof(timeString), "%H:%M:%S", local); // converts time in hours, minutes, seconds in the timestring as chars

	//printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	char* f = malloc(7); // char that holds the called function
	char path[100]; // path you can set through Folder(), max of 100 chars, dont think you need much more

	char start[] = "start", 
		add[] = "add",
		stop[] = "stop",
		folder[] = "folder",
		savecur[] = "savecur";

	while (strcmp(f, stop) != 0) { // if command is not stop
		gets(f); // put console input in f
		
		if (strcmp(f, start) == 0) { // checks if f equals start
			Startd(); // calls startd function
		}
		else if (strcmp(f, add) == 0) { // checks if f equals add
			Add(); // calls add function
		}
		else if (strcmp(f, folder) == 0) { // checks if f equals folder
			Folder(path); // calls folder function and passes the path variable
		}
		else if (strcmp(f, savecur) == 0) { // checks if f equals savecur
			SaveCur(); // calls savecur function
		}
		else if (strcmp(f, "help") == 0) { // checks if f equals help
			printf("\ncommands:\nstart : 'takes one argument, argument is\n the activity you're about to start.\n\nadd : takes three arguments, first is the activity, \nsecond is time started, third is time it ended.\n\nstop : has two options, 'current' and 'day', \ncurrent stops current activity, day stops the day.\n\nfolder : takes one argument, path where you want your .txt's and .pdf's stored.\n");
			fflush(stdout); // instantly prints anything left on stdout aka the printf
		}
		else if(strcmp(f, "") == 0 || strcmp(f, stop)) { // checks if f equals stop
			printf("\nnot a valid command, type 'help' for more information\n");
			fflush(stdout); // instantly prints anything left on stdout aka the printf
		}
		else { // if stop is called is pressed
			printf("test");
			fflush(stdout);
		}
	}

	free(f); // frees f variable from the stack

	return 0; // stops program
}

void Startd() {
	
	fflush(stdout); // flushes stdout just in case

	printf("what activity do you want to start? : ");
	fflush(stdout); // instantly prints stdout

	activities[aCounter].active = true; // sets the current activity to true
	gets(activities[aCounter].name); // gets and sets activity name from the console

	GetTimeH(); // refreshes time in timeString
	strcpy(activities[aCounter].timeStart, timeString); // copies timestring to activity timestart
	printf("\nActivity started at: ");
	printf(timeString);
	printf("\n");
	fflush(stdout); // instantly prints stdout
}

void Add() {

}

void Stop() {
	
}

void Folder(char path[]) {
	gets(path); // gets and sets path from console
	printf("\nFolder has been set to: ");
	printf(path);
	printf("\n");
	fflush(stdout); // instantly prints stdout
}

void SaveCur() {
	GetTimeH(); // refreshes timeString
	printf("activity ");
	printf(activities[aCounter].name);
	printf(" stopped.\n");
	strcpy(activities[aCounter].timeStop, timeString); // copies timeString into activity timestop
	fflush(stdout); // instantly prints stdout
	aCounter = aCounter + 1; // adds one to aCounter
}

void GetTimeH() {
	secs = time(0); // sets secs back to epoch
	local = localtime(&secs); // refreshes localtime
	strftime(timeString, sizeof(timeString), "%H:%M:%S", local); // turn localtime into timestring
}
