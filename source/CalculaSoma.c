//
//  CalculaSoma.c
//  
//
//  Created by Alexander André De Souza Vieira on 11/10/2018.
//

#include <stdio.h>
#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    
    for(i=1; i <= n; ++i)
    {
        sum += i;   // sum = sum+i;
    }
    
    printf("Sum = %d",sum);

    return 0;
    
}
