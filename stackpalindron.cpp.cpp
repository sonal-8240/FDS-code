#include<iostream>
#include<string.h>
#define max 50
using namespace std;

class STACK
{
	private:
		char a[max];
		int top;
	
	public:
		STACK()
		{
			top=-1;	
		}	
		
		void push(char);
		void reverse();	
		void convert(char[]);
		void palindrome();
};

void STACK::push(char c)
{
	top++;
	a[top] = c;
	a[top+1]='\0';
	
	cout<<endl<<c<<" is pushed on stack ...";
}

void STACK::reverse()
{
	char str[max];
	
	cout<<"\n\nReverse string is : ";
		
	for(int i=top,j=0; i>=0; i--,j++)
	{
		cout<<a[i];
		str[j]=a[i];
	}
	
	cout<<endl;
}


void STACK::convert(char str[])
{
	int j,k,len = strlen(str);

	for(j=0, k=0; j<len; j++)
	{
		if( ( (int)str[j] >= 97 && (int)str[j] <=122 ) || ( (int)str[j] >= 65 && (int)str[j] <=90 ))/*(int)str[j]: This converts the character at index j in the string str to its ASCII value represented as an integer.
((int)str[j] >= 97 && (int)str[j] <= 122): This checks if the ASCII value of the character is within the lowercase letter range (97-122 in ASCII corresponds to 'a' to 'z').
((int)str[j] >= 65 && (int)str[j] <= 90): This checks if the ASCII value of the character is within the uppercase letter range (65-90 in ASCII corresponds to 'A' to 'Z').
||: This is the logical OR operator, meaning that if any of the conditions on either side of it are true, the entire expression evaluates to true.
Therefore, the entire conditional statement is checking whether the character at index j in the string str is either a lowercase letter ('a' to 'z') or an uppercase letter ('A' to 'Z'). If it is, the condition will be true.*/
		{
			if( (int)str[j] <=90 )
			{
				str[k] = (char)( (int)str[j] + 32 );
			}else
			{
				str[k] = str[j];				
			}

			k++;			
		}
	}
	str[k]='\0';

	cout<<endl<<"Converted String : "<<str<<"\n";
}




void STACK::palindrome()
{	
	char str[max];
	int i,j;		

	for(i=top,j=0; i>=0; i--,j++)
	{
		str[j]=a[i];
	}
	str[j]='\0';
	
	
	if(strcmp(str,a) == 0)
		cout<<"\n\nString is palindrome...";
	else
		cout<<"\n\nString is not palindrome...";
}


int main()
{
	STACK stack;

	char str[max];
	int i=0;
	
	cout<<"\nEnter string to be reversed and check is it palindrome or not : \n\n";
	
	cin.getline(str , 50);
	
	stack.convert(str);
	
	while(str[i] != '\0')
	{
		stack.push(str[i]);
		i++;
	}

	stack.palindrome();

	stack.reverse();
	
}
