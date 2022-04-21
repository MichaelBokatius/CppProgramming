#include<stdio.h> // include stdio.h library
bool check_prime(int n);

int main(void)
{   

    int start = 0;
    int end = 100;
    
    for(int i = start; i < end; i++)
    {
        if(check_prime(i) && check_prime(i + 2))
        {            
            printf("{%d, %d}\n", i, i + 2);
            i = i + 1; 
        }                
    }    
    printf("*-- Finished Counting --* \n");
    return 0;
}

bool check_prime(int n)
{
    if(n == 1)
    {
        return false;
    }
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}
