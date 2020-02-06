#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;

#define S1 1
#define S2 2
#define S3 3
#define S4 4 
#define S5 5
#define DONE 6
#define END 7


int main()
{
    char str[50];
    int temp=0;
    char c;
    char outstr[50];
    int pos=0;
    int state=S1;
    
    printf("Enter Input");
    scanf("%s",str);
    while(!(state==DONE || state==END))
    {
        c = str[pos];
        if(c=='\000')
        printf("End of String!\n");
        if(c=='0') temp=0;
        else if(c=='1') temp=1;
        else if (c=='2') temp=2;
        else if (c=='\000') temp=3;
        else {
            printf("Invalid Alphabet! Exiting!");
            break;
        } 
        switch(temp)
        {
            case 0:{
                if(state==S1)
                {  
                    outstr[pos] = c;
                    state = S2;
                    pos++;
                }
                else if(state==S2)
                {
                    outstr[pos] = c;
                    state = S2;
                    pos++;
                }
                else if(state==S3)
                {
                    outstr[pos] = c;
                    pos++;
                    state = S2;
                }
                else
                {
                    state = DONE;
                }
                break;
            }

            case 1:{
                if(state==S1)
                {
                    state = END;
                }
                else if(state==S2)
                {
                    outstr[pos] = c;
                    pos++;
                    state= S4;
                }
                else if(state==S3)
                {
                    state=END;
                }
                else
                {
                    state = DONE;
                }
                break;
            }

            case 2:{
                if(state==S1)
                {
                    outstr[pos] = c;
                    pos++;
                    state = S3;
                }
                else if(state==S2)
                {
                    state= END;
                }
                else if(state==S3)
                {
                    state = END;
                }
                else if(state==S4)
                {
                    outstr[pos] = c;
                    pos++;
                    state = S5; 
                }
                else if(state==S5)
                {
                    outstr[pos] = c;
                    pos++;
                    state = S5;
                }
                else 
                {
                    state = DONE;
                    break;
                }
                break;
            }
            case 3:
            {
                if((state==S1) || (state==S2) || (state==S3))
                {
                    state = END;
                }
                else if( (state==S4) || (state==S5))
                {
                   // outstr[pos]=c;
                    state=DONE;
                }
                else
                {
                    state=END;
                }
                break;
            }
            default:
            {
                printf("Invalid Charater!!\n");
                state = END;
                break;
            }
        }
    }

    if(state==DONE)
    {
        outstr[pos] = '\000';
        printf("%s",outstr);
    }
    else
    printf("NULL");
    return 0;
}
