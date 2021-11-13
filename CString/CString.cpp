#include<conio.h>

//Takes an array of chars and put them in the console 1 by 1
void print(const char* s)
{
	for (; *s != NULL; s++)
	{
		_putch(*s);
	}
}

//Reads input from the keyboard until the user hits ENTER
void Read(char* buff, int size)// buffer: we don't know how many keys the user will enter so we pass it a big array with enough space that we think the user will press
{
	const char* const pEnd = buff + size;

	//char c = _getch(): Assigning a char from keyboard 
	//13 = ENTER
	// c != 13 && (buff + 1 < pEnd) plus 1 because we need to leave a space for the NULL character at the end
	for (char c = _getch(); c != 13 && (buff + 1 < pEnd); c = _getch(), buff++)
	{
		_putch(c);
		*buff = c;
	}

	*buff = 0;
}

//Returns a string that has been converted from an integer
int StringToInt(const char* s)
{
	//Scan to start point
	const char* p = s; //startting point
	//This moves the pointer all the way to end
	for (; *p >= '0' && *p <= '9'; p++);
	p--; //Moves pointer by one from the invalid cahracter to the valid character

	int value = 0;
	int place = 1; //1 place, 10th place, 100 place

	for (; p >= s; p--)
	{
		value += (*s - '0') * place;
		place *= 10;
	}

	return value;

	/*/Converting single digit
	if (*s >= '0' && *s <= '9')
	{
		return *s - '0';
	}
	else
	{
		return -1;
	}*/
}

void IntToChar(int val, int* buf, int size)
{
	for (; val > 0; val /= 10, buf++)
	{
		*buf = '0' + val % 10;
	}

	*buf = 0;
}

int Fibonacci(int x)
{
	if (x <= 1)
	{
		return x;
	}
		
	return Fibonacci(x - 1) + Fibonacci(x - 2);
}

void Chart()
{
	print("(l)oad (s)ave (a)dd (q)uit or (p)rint? ");
	char ans[5];
}

int main()
{
	//_putch(69); //puts a single character on the screen 69 in ASCII is 'E'
	//char literal
	//_putch('D'); //puts the ASCII value of what is inside the single quote. Same as above but we don't have to look for each ASCII value
	
	//const char name[] = { 'D', 'I', 'E', 'G', 'O', 0 }; //our array that we will pass to the print function, alson knowng as a C-String
	//print(name); //should print out DIEGO
	//const char name2[] = "\nJessica"; //same concept as above only thing is we put the name in double quotes. Also \n is equal to a NEWLINE
	//print(name2);

	//const char* wife = "\nMYWIFE\n"; //instead of copyinh the characters to a local array, we can get a char pointer to a string itself
	//technically not a good thing since the memory is loaded into a read only when executed
	//Which is why it is better to create an array string
	//print(wife);

	//char c = _getch(); //Gets input
	//_putch(c); //puts the input character on screen

	/*
	//Using the Read function	
	print("Type some shit: ");
	char inBuff[18];
	Read(inBuff, 18);
	print("\nYou typed: ");
	print(inBuff);
	*/

	/*
	print("How many apples? ");
	char answer[100];
	Read(answer, 100);

	const int appleCount = StringToInt(answer);
	print("\n");

	for (int i = 0; i < appleCount; i++)
	{
		print("Apples!");
	}
	

	print("Which Fibonacci number do you want to know? ");
	char answer[5];
	Read(answer, 5);
	int fib = Fibonacci(StringToInt(answer));
	print("\nThat Fibonaaci number is ");
	print((char*)fib);
	*/


	while (!_kbhit()); //loop as long as user does not press something on keyboard

	return 0;
}