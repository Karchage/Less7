#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void delSpaceInFile()
{
	FILE *file = NULL;
	FILE *out = NULL;
	char simbol = NULL;
	
	file = fopen("1.txt","r");
	out = fopen("out.txt","w");
	
	while((simbol = fgetc(file))!=EOF)
	{
		if(simbol == '\n')
		{
			fputc(simbol,out);
			do
			{
				simbol = fgetc(file);
			}
			while((simbol == 32)||( simbol == 9));
			fputc(simbol,out);
		}
		else fputc(simbol,out);
	}
	fclose(file);
	fclose(out);
}
void levelUp(int &level,FILE * file)
{
	for(int i=0;i<level;i++)
	{
		fputc('	',file);	
	}
}
void returnInfoToFile()
{
	FILE * file = NULL;
	FILE * out = NULL;
	char simbol = NULL;
	int level = 0;
	
	file = fopen("1.txt","w");
	out = fopen("out.txt","r");
	
	while((simbol = fgetc(out))!= EOF)
	{
		if(simbol == 123)
		{
			
			fputc(simbol,file);
			level ++;
		}
		else if(simbol == 125)
		{
			level--;
		}
		else if(simbol == '\n')
		{	
			fputc(simbol,file);
			simbol = fgetc(out);
			if(simbol != '}')
			{		
				levelUp(level,file);
			}
			else 
			{	
				level--;
				levelUp(level,file);
				fputc(simbol,file);
			}
			fseek(out,-1,SEEK_CUR);		
		}
		else fputc(simbol,file);;
	}
	fclose(file);
	fclose(out);
}
int main(int argc, char** argv)
{
	delSpaceInFile();
	returnInfoToFile();
	remove("out.txt");
	return 0;
}
