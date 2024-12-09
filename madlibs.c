//Author:Junhao Chen , Zachary Detton , Guadalupe Arreola
//Date:11/29
//Purpose: replace the letters with the word you input and output
#include<stdio.h>
#define FILE_NAME "madlib1.txt"

void loadMadlib (FILE *fin , char madlibText[][1000] , int *lineCount);
void askUser (char *letter , char *input);
void getWord (char madlibText[][1000] , int lineCount , char word[][500]);
void fillMadlib (char madlibText[][1000] , char word[][500] , char finalText[][1000] , int lineCount);
void printMadlib (char finalText[][1000] , int lineCount);
void removeNewLine (char *str);

int main(){
	char madlibText[1000][1000];
	char word[500][500];
	char finalText[1000][1000];
	int lineCount = 0;
	
	FILE *fp = fopen ( FILE_NAME , "r" );
	if(fp==NULL){
		printf("error opening the file \n");
		return 0;
	}
	
	loadMadlib (fp , madlibText , &lineCount);
	fclose(fp);
	getWord (madlibText , lineCount , word);
	
	fillMadlib (madlibText , word , finalText , lineCount);
	
	printMadlib (finalText , lineCount);
	
	return 0 ;
}
void loadMadlib (FILE *fin , char madlibText[][1000] , int *lineCount){
	while (fgets(madlibText[*lineCount],1000,fin)){
		removeNewLine(madlibText[*lineCount]);
		(*lineCount)++;
		
	}
}
void askUser (char *letter , char *input ){
	switch(letter[0]){
		case 'A':
			printf("Please enter an adjective: ");
			break;
		case 'V':
			printf("Please enter a verb: ");
			break;
		case 'N':	
			printf("Please enter a noun: ");
			break;
		default:
			break;
	}
	fgets (input , 500 , stdin);
	removeNewLine(input);
	
}
void getWord (char madlibText[][1000] , int lineCount , char word[][500]){
	int rows = 0; 
	for (int i = 1 ; i < lineCount ; i+=2){
		if (madlibText[i][0] == 'A' || madlibText[i][0] == 'V' || madlibText[i][0] == 'N'){
			askUser(madlibText[i] , word[rows]);
			rows++;
			
		}
	}
}
void fillMadlib (char madlibText[][1000] , char word[][500] , char finalText[][1000] , int lineCount){
	
	for (int line = 0 ; line < lineCount ; line++){
		if (line % 2 == 1 && (madlibText[line][0] == 'A'|| madlibText[line][0] == 'V' || madlibText[line][0] == 'N')){
			int rows = 0;
			int colus = 0;
			while(word[rows][colus] != '\0'){
				finalText[line][colus] = word[rows][colus];
				colus++;
			}
		
			finalText[line][colus] = '\0';
			rows++;
		}
		else{
			int colus = 0;
			while (madlibText[line][colus] != '\0'){
				finalText[line][colus] = madlibText[line][colus];
				colus++;
			}
		finalText[line][colus]='\0';
		}
	}
}
void printMadlib (char finalText[][1000] , int lineCount){
	for (int i = 0 ; i < lineCount ; i++){
		printf("%s ",finalText[i]);
	}
	printf("\n");
}
void removeNewLine(char *str){
	int i = 0;
	while(str[i]!='\0'){
		if(str[i]=='\n'){
			str[i]='\0';
			break;
		}
		i++;
	}
}



