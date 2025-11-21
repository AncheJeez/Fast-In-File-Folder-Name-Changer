#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printGreen(const char* text){
	#if defined(_WIN32) || defined(_WIN64)
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	    printf("%s", text);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	#else
	    printf("\033[32m%s\033[0m", text);
	#endif
}

void printRed(const char* text){
	#if defined(_WIN32) || defined(_WIN64)
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	    printf("%s", text);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	#else
	    printf("\033[31m%s\033[0m", text);
	#endif
}

void printBlue(const char* text){
	#if defined(_WIN32) || defined(_WIN64)
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	    printf("%s", text);
	    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	#else
	    printf("\033[34m%s\033[0m", text);
	#endif
}

int main(int argc, char *argv[]) {
	
	printf("Hello! This is ");
	printGreen("Fast In File/Folder Name Changer\n");
	printf("I will ask you for a ");printBlue("folder");printf(" or a ");printBlue("file");printf(" to search.\n");
	printf("After that I'll ask you for the word to search.\n");
	printf("Then I'll substitute it for the new word you give me.\n");
	
	printRed("This will change every instance of the name for the new one, comprende?\n");
	
	char answer[10];
	while(1){
		printf("Am I searching in a single file or all the files in a folder ");
		printGreen("(1/2)");
		printf(": ");
		
		scanf("%9s", answer);

        if (answer[0] == '1' || answer[0] == '2') {
            break;
        }

	}
	
	if (answer[0] == '1'){
		printf("Type the path to the directory: ");
		char path[256];
		scanf("%255s", path);
		FILE *fptr;
		fptr = fopen(path, "r");
		
		if(fptr == NULL){
			printRed("Error file missing\n");
            exit(-1);
		}
		printf("Please enter a word(enter $ to end): ");
		char word[100] = {0};
		char string[50];
        scanf("%s", word);
        int num =0;
		while(fscanf(fptr,"%s", string) == 1){
            if(strstr(string, word)!="$") {
                num++;
            }
        }
//        printf("I found the word %s in the file %d times\n",word,num );
	}

		
	
	return 0;
}
