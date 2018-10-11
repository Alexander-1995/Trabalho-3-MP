//
//  printasc.c
//  
//
//  Created by Alexander André De Souza Vieira on 10/10/2018.
//

#include <stdio.h>
#include <stdio.h>
int main()
{
    
    /*I don't know where I'm going But I sure know where I've been*/
    char c;
    printf("Enter a character: ");
    
    // Reads character input from the user
    scanf("%c", &c);
    
    // %d displays the integer value of a character
    // %c displays the actual character
    printf("ASCII value of %c = %d", c, c);
    return 0;
}
