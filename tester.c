#include<stdio.h>
#include<stdlib.h>
int main ()
{

    int length;
    

    while(1)
    { 
    int count=0;
    scanf("%d", &length);
    if(length==0)
    {
        break;
    }

    int numbers[length];
    int maximum;

    for(int k=0; k<length; k++)
    {
        scanf("%d", &numbers[k]);
    }

    
    for(int i=0; i<length;i++)
    {
         maximum=numbers[i];
        if(numbers[i]> maximum)
        {
          maximum = numbers[i];
        }
    }

    for(int j=0; j<length; j++)
    {
        if(maximum==numbers[j])
        {
            count++;
        }
    }
    printf("%d\n", count);



    }

    

return EXIT_SUCCESS;
}