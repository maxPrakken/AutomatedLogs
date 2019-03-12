#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>
#include <time.h>

int main() {

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	//printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	char* f = malloc(7);
	char path[100];

	char start[] = "start",
		add[] = "add",
		stop[] = "stop",
		folder[] = "folder",
		savecur[] = "savecur";

	void Startd(), Add(), Stop(), Folder(), SaveCur();

	while (strcmp(f, stop) != 0) {
		gets(f);
		
		if (strcmp(f, start) == 0) {
			Startd();
		}
		else if (strcmp(f, add) == 0) {
			Add();
		}
		else if (strcmp(f, folder) == 0) {
			Folder(path);
		}
		else if (strcmp(f, savecur) == 0) {
			SaveCur();
		}
		else if (strcmp(f, "help") == 0) {
			printf("\ncommands:\nstart : 'takes one argument, argument is\n the activity you're about to start.\n\nadd : takes three arguments, first is the activity, \nsecond is time started, third is time it ended.\n\nstop : has two options, 'current' and 'day', \ncurrent stops current activity, day stops the day.\n\nfolder : takes one argument, path where you want your .txt's and .pdf's stored.\n");
			fflush(stdout);
		}
		else if(strcmp(f, "") == 0 || strcmp(f, stop)) {
			printf("\nnot a valid command, type 'help' for more information\n");
			fflush(stdout);
		}
	}

	free(f);

	return 0;
}

void Startd() {

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

}
