#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

]// Introduce the type bool
//typedef int bool;
//#define true 1
//#define false 0

void CliLoop();
void SigHandler(int);
void Destroy();
void MainMenu();
void StartCurses();

bool running = true;
bool mainmenu = true;

int option = 0;
int keylocation = 1;

int main(void)
{
    
    signal(SIGINT, SigHandler);
    CliLoop();
}

void ClearScreen()
{
  system("@cls||clear");
}

// Bring up CLI
void CliLoop(void)
{
    ClearScreen();
    
    while (running)
    {
        printf("Running CliLoop\n");

	if (mainmenu)
	{
	    MainMenu();
	    
	    while(option == 0)
	    {
		
		char c = getchar();

		if (c == '\n' )
		{
		    option = keylocation;
		}
		else if (c = '\033')
		{
		    getch();
		    switch(getch())
		    {
			// Arrow Up
		    case 'A':break;
			// Arrow Down
		    case 'B':break;
			// Arrow right
		    case 'C':break;
			// Arrow left
		    case 'D':break;
		    }
		}
	    }

	    if (option == 1)
	    {
		ClearScreen();
		printf("Quitting");
		exit(1);
	    }
	}
    }

    // Not Running
    printf("Quiting");
}

// Handle Exceptions
void SigHandler(int signum)
{
    printf("Quitting");
    Destroy();
    exit(1);
}

// Kill pointers
void Destroy()
{
    // Kill all pointers etc
}

void MainMenu()
{
    printf("Main Menu\n\n");
    printf("Test1\n");
    printf("Test2\n");
    printf("Test3\n");
    printf("Test4\n");
    printf("Test5\n");
    printf("Test6\n");
}


void StartCurses()
{
        // Initialize Ncurses
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}
