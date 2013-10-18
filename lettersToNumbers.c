//write num bers given in letters as numbers.  ie an input of "one two" gives an output of "12"

#include <stdio.h>
#include <string.h>

//some global variables
int index = 0;
int output[10];

// words like "million, "thousand" and "hundred" will multiply the current index of output[].  Incrementing the index value where apporpriate is handled by 
//the sussWord() after the call to multiplyIndexBy() is made
void multiplyIndexBy(int n){
	int m = output[index];
	m = m*n;
	output[index] = m;
}
//add a value to the current index of output[]
void addToIndex(int n){
	int m = output[index];
	m = m + n;
	output[index] =m;
}

//take individual words derived from the user string and decide what they mean
void sussWord(char word[]){
	int match = 0;
	if(strcmp(word,"zero")==0){
		addToIndex(0);
		match = 1;
	}
	if(strcmp(word,"one")==0){
		addToIndex(1);
		match = 1;
	}
	if(strcmp(word,"two")==0){
		addToIndex(2);
		match = 1;
	}
	if(strcmp(word,"three")==0){
		addToIndex(3);
		match = 1;
	}
	if(strcmp(word,"four")==0){
		addToIndex(4);
		match = 1;
	}
	if(strcmp(word,"five")==0){
		addToIndex(5);
		match = 1;
	}
	if(strcmp(word,"six")==0){
		addToIndex(6);
		match = 1;
	}
	if(strcmp(word,"seven")==0){
		addToIndex(7);
		match = 1;
	}
	if(strcmp(word,"eight")==0){
		addToIndex(8);
		match = 1;
	}
	if(strcmp(word,"nine")==0){
		addToIndex(9);
		match = 1;
	}
	if(strcmp(word,"ten")==0){
		addToIndex(10);
		match = 1;
	}
	if(strcmp(word,"eleven")==0){
		addToIndex(12);
		match = 1;
	}
	if(strcmp(word,"twelve")==0){
		addToIndex(12);
		match = 1;
	}
	if(strcmp(word,"thirteen")==0){
		addToIndex(13);
		match = 1;
	}
	if(strcmp(word,"fourteen")==0){
		addToIndex(14);
		match = 1;
	}
	if(strcmp(word,"fifteen")==0){
		addToIndex(15);
		match = 1;
	}
	if(strcmp(word,"sixteen")==0){
		addToIndex(16);
		match = 1;
	}
	if(strcmp(word,"seventeen")==0){
		addToIndex(17);
		match = 1;
	}
	if(strcmp(word,"eighteen")==0){
		addToIndex(18);
		match = 1;
	}
	if(strcmp(word,"nineteen")==0){
		addToIndex(19);
		match = 1;
	}
	if(strcmp(word,"twenty")==0){
		addToIndex(20);
		match = 1;
	}
	if(strcmp(word,"thirty")==0){
		addToIndex(30);
		match = 1;
	}
	if(strcmp(word,"fourty")==0){
		addToIndex(40);
		match = 1;
	}
	if(strcmp(word,"fifty")==0){
		addToIndex(50);
		match = 1;
	}
	if(strcmp(word,"sixty")==0){
		addToIndex(60);
		match = 1;
	}
	if(strcmp(word,"seventy")==0){
		addToIndex(70);
		match = 1;
	}
	if(strcmp(word,"eighty")==0){
		addToIndex(80);
		match = 1;
	}
	if(strcmp(word,"ninety")==0){
		addToIndex(90);
		match = 1;
	}
	if(strcmp(word, "billion")==0){
		multiplyIndexBy(1000000000);
		index+=1;  //increment index of output[]
		match = 1;
	}
	if(strcmp(word, "million")==0){
		multiplyIndexBy(1000000);
		index+=1;  //increment index of output[]
		match = 1;
	}
	if(strcmp(word, "thousand")==0){
		multiplyIndexBy(1000);
		index+=1;  //increment index of output[]
		match = 1;
	}
	if(strcmp(word, "hundred")==0){
		multiplyIndexBy(100);
		//i+=1;  //increment index of output[]
		match = 1;
	}
	if (strcmp(word, " ")==0){
		match = 1;
	}
		
	
	else if(match == 0){
		printf("the program did not recognize one or more of the words you have input.\nYou may need to check your spelling.\n");
		//fprintf(stderr, "%d", sizeof(word));

	}
}

//add a char to the end of a string
void append(char string[], char c, int n){
	string[n] = c;
	string[n+1] = '\0';
}

//get each individual word from the user input and deal with it appropriately
parseString(char string[]){
	int i = 0;  //index of the user input string
	int n = 0;	//index for where the next character in each individual word will go
	char word[10];
	do{//parse the string char by char until we reach the Null byte (end of string)
		char c = string[i];
		if (c != ' '){			//if it's not a space, it should get tacked onto the end of the current word
			append(word, c, n); //smash the letter onto the end of the current word
			n++;				//index for the word string where the next letter will go
		}
		else if (c == ' '){                  //we have parsed white space								
			sussWord(word);		//interperet the word
			printf("\"%s\"\n", word); //place holder so I can see what's going on
			word[0] = '\0';			//make the null byte the first character so that it's treated like and empty string
			n = 0;				//next char goes at the first index.  It's a new word
		}		
		i+=1;					//whether white space or not, we are onto the next index
	}while (string[i] != '\0');//end while loop
}

//insert a white space at the end of the user string so that the other functions will work properly
insertSpace(char string[]){
	int i = 0;
	do{
		i+=1;
	}while (string[i] != '\0');
	append(string, ' ', i-1);
}

int main(){
	int finalOut = 0;
	int e;
	char string[130];
	printf("enter in a number as a text phrase like\n \"one hundred thousand twenty one\" or as single numbers, like \"one one seven\"\n use 130 characters or less and keep your number to 2147000000 or less\n");
	fgets(string, 100, stdin);
	insertSpace(string);
	parseString(string);
	for (e = 0; e <= index; e++){
		finalOut = finalOut + output[e];
	}
	printf("%i\n", finalOut);
	
	return 0;
}