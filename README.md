# AutomatedLogs
this is a C based terminal application that makes logging what you do and did in a day extreemly easy

How to compile and use:

  -Inbefore: if you get the .exe from the release page you can skip to step 5

  -Step 1: instal MinGW and add it to your path variable in your environment settings

  -Step 2: clone the project where ever you see fit

  -Step 3: open a console window/bash window inside the project folder

  -Step 4: type in the console : "gcc -o AutomatedLogs AutomatedLogs.c"

  -Step 5: add the location to AutomatedLogs.exe to your path variable in your environment settings

Here are the commands and what they do:

  -start : takes one argument, the name of the activity you want to name it. call this to start your day or add a new activity in a already   ongoing day.

  -add : takes three arguments, the name of the activity you want to name it, the start time, and the end time, use this if you want to add   something in the day that you forgot to start.\

  -stop : stops the day, does a final save on your day and rounds it up.

  -folder : sets the folder where you want your .txt's and .pdf's to save.
