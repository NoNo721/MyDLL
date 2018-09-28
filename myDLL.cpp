#include <iostream>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

extern "C"
{

void procBar(int rate)
{

	int ratep = rate/2;
	char bar[52];		//51个“=”，一个"\0"
	const char *label = "|/-\\";

	memset(bar, 0, 52*sizeof(char));
	
	int i = 0;
	while(i <= ratep)
	{
		bar[i] = '=';
		i++;
	}
	
	printf("Proc:[%-51s][%d%%][%c]\r", bar, rate, label[rate%4]);	//"-"代表左对齐，‘\r’回车（即光标位于行首）
	fflush(stdout);	

}

int mygetch(void) 
//win~getch()
{
	struct termios oldt, newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}

}






