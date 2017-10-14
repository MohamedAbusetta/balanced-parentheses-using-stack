#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Balanced (char *arr , unsigned char siz);

char Stack[20];
char SP = -1;
char pop (void);
void push (char);


int main()
{
    char input[20];
    printf("Enter String = ");
    gets(input);
    Balanced(input,strlen(input));
    return 0;
}

void Balanced (char *arr , unsigned char siz)
{
    unsigned char i , x = -1 ,y =0;
    char temp[20];

    //clear all chars except parentheses
    for(i = 0 ; i < siz ; i++)
    {
        if( arr[i] == '(' || arr[i] == ')' || arr[i] == '[' || arr[i] == ']' || arr[i] == '{' || arr[i] == '}')
            {
                x++;
                temp[x] = arr[i];

            }
    }

    // if the number is odd then there is no balance
    if(x % 2 == 0) return printf("FALSE");

    //loop half size of temp
    while( y < ((x/2)+1) )
    {
        if (  temp[y] == '(' || temp[y] == '{' || temp[y] == '[' )
                    push(temp[y]);

        else
        {   //Check the Empty stack
            //if Stack Empty then there is closed brac without open one
            if(SP == -1) return printf("FALSE");

            i = pop();

            switch (temp[y])
            {
            case ')':
                if ( i == '(' ) break;
                else return printf("FALSE");

            case '}':
                if ( i == '{' ) break;
                else return printf("FALSE");

            case ']':
                if ( i == '[' ) break;
                else return printf("FALSE");
            }

        }
        y++;
    }
    return printf("TRUE");
}
void push(char x)
{
    if(SP < 19)
        Stack[++SP] = x ;
}

char pop (void)
{
    return (SP > -1)?  Stack[SP--]: printf("Faild");
}
