#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void delCom(FILE *file1, FILE *file2)
{
	char simbol,buf;

	
	while((simbol = fgetc(file1))!=EOF)
	{
		if(simbol == '/')
		{
			buf = simbol;
			simbol = fgetc(file1);
			
			if(simbol =='/')
			{
				while(simbol != '\n')
				{
					simbol = fgetc(file1);
					if(simbol ==EOF ) break;
				}
			}
			else if(simbol =='*')
			{
				while((simbol = fgetc(file1))!= EOF)
				{
					if(simbol == '*')
					{
						simbol = fgetc(file1);
						if(simbol == '/')
						{
							break;
						}
					}
				}
				
			}
			else 
			{
			fputc(buf,file2);
			fputc(simbol,file2);
			}
		}else fputc(simbol,file2);
	}

}
int main(int argc, char** argv) 
{
	FILE*file1;
	FILE*file2;
	file1 = fopen("12.txt","r");
	file2 = fopen("out.txt","w");
	if(file1 == NULL) std::cout<<"Please check path to file\n";
	if(file2 != NULL) std::cout<<"Buffer file create\nStart processing...\n";
	delCom(file1,file2);	
	fclose(file1);
	fclose(file2);
	
	
	file1 = fopen("12.txt","w");
	file2 = fopen("out.txt","r");
	char simbol;
	while((simbol=fgetc(file2))!=EOF)
	{
		fputc(simbol,file1);
	}
	fclose(file1);
	fclose(file2);
	remove("out.txt");
	std::cout<<"Buffer file delete\n";
	return 0;
}
