#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int funcrand()
{
	int var = rand()%10;
	if(var<5) return 1;
	else return 0;
}
void replace(std::string &str,int i,char *path)
{
	FILE *file;
	file = fopen(path,"r");
	char simbol;
		while((simbol = fgetc(file)) !=EOF)
		{
			if(str[i]==simbol)
			{
			fgetc(file);
			simbol = fgetc(file);
			str[i]=simbol;
			}
		}
	fclose(file);
}
std::string convert(std::string &str,char *path)
{
	int i=0;
	while(str[i]!='\0')
	{ 
		switch(funcrand())
		{	
			case 0:
				str[i]=toupper(str[i]);
				i++;
				break;
			case 1:
				replace(str,i,path);
				i++;
				break;	
		}	
	}
	return str;
}
std::string getstring(std::string &str,char **argv)
{
	FILE *file=fopen(argv[1],"r");
	int i = 0;
	char simbol;
	while((simbol = fgetc(file) ) !=EOF)
	{
		str+=simbol;
		i++;
	}
	fclose(file);
	return str;
}
void Vone()
{
	char path[] = "replaces.txt";
	std::string str;
	std::cin>>str;
	convert(str,path);
	std::cout<<str;
}
void Vtwo(char **argv)
{
	char path[] = "replaces.txt";
	
	std::string str;
	getstring(str,argv);
	std::cout<<"This string in file: "<<str<<"\n";
	
	convert(str,path);
	std::cout<<str;
}
void VFree(char **argv)
{
	char path[] = "replaces.txt";
	FILE *file;
	std::string str;
	getstring(str,argv);
	std::cout<<"This string in file: "<<str<<"\n";
	convert(str,path);
	file = fopen(argv[2],"w");
	int i=0;
	while(str[i]!='\0')
	{
		fputc(str[i],file);
		i++;
	}
	fclose(file);
}

int main(int argc, char** argv) 
{
	if(argc==1) Vone();
	else if(argc==2)Vtwo(argv);
	else if(argc==3)VFree(argv);
	return 0;
}
