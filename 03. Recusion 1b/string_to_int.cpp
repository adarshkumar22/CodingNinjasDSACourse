#include<string.h>
#include<math.h>
int stringToNumber(char input[])
{
    if (strlen(input) ==1){
        int a = input[0] - '0';
        return a;
    }
    int y = stringToNumber(input +1);
    int x = input[0] - '0';
    
    return x*pow(10,strlen(input)-1)+y;
}