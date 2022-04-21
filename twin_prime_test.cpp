/**
    Programm to calculate and print twin primes 
    and their digital root after multiplication.
    
    A twin prime is a prime number that is either 2 less or 2 more 
    than another prime number. For example, either member of 
    the twin prime pair (3, 5), (11, 13) or (41, 43). 
    In other words, a twin prime is a prime that has a prime gap of two.
    
    After multiplying both members of the pair with each other,
    the digital root of the sum is always 8, if the pair starts
    with primes greater than 3.
*/

#include<stdio.h> 
#include<vector>
#include<string>
using namespace std;

bool check_prime(int n);
int print_digital_root(string n);

bool check_prime(int n)
{
    if(n == 1) return false;
    
    for(int i = 2; i < n; i++)
        if(n % i == 0) return false;
        
    return true;
}

int print_digital_root(string num)
{
    if (!num.compare("0")) return 0;
 
    int result = 0;
    for (int i = 0; i < num.length(); i++)
        result = (result + num[i] - '0') % 9;
    return (result == 0) ? 9 : result % 9;
}

int main(void)
{   

    int start = 5;
    int end = 200;
    int sum_pair;
    string num;
    vector<int> num_pairs;
    
    printf("*-- Print Twin Prime Pairs --*\n");
    for(int i = start; i < end; i++)
    {
        if(check_prime(i) && check_prime(i + 2))
        {           
            num_pairs.push_back(i);
            num_pairs.push_back(i + 2);
            printf("{%d, %d}\n", i, i + 2);
            i = i + 1; 
        }                
    }    

    printf("\n*-- Print Digital Sum --*\n");
    for(int i = 0; i < num_pairs.size() - 1; i += 2)
    {
        printf("%d * %d = ", num_pairs.at(i),num_pairs.at(i + 1));
        sum_pair = num_pairs.at(i) * num_pairs.at(i + 1);
        printf("%d", sum_pair);
        num = to_string(sum_pair); 
        printf(" = %d \n", print_digital_root(num));
    }
    
    return 0;
}
