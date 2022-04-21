#include<stdio.h> 
#include<bits/stdc++.h>
using namespace std;
bool check_prime(int n);
int print_digital_root(string n);


int main(void)
{   

    int start = 5;
    int end = 200;
    int sum;
    string num;
    std::vector<int> num_pairs;
    
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
    printf("*-- Finished Counting --* \n\n");
    
    for(int i = 0; i < num_pairs.size() - 1; i += 2)
    {
        printf("%d * %d = ", num_pairs.at(i),num_pairs.at(i + 1));
        sum = num_pairs.at(i) * num_pairs.at(i + 1);
        printf("%d", sum);
        num = to_string(sum); 
        printf(" = %d \n", print_digital_root(num));
    }
    printf("*-- Finished Digital Sum --* \n\n");
    
    return 0;
}

bool check_prime(int n)
{
    if(n == 1) return false;
    
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int print_digital_root(string num)
{
    if (num.compare("0") == 0) return 0;
 
    int ans = 0;
    for (int i=0; i<num.length(); i++)
        ans = (ans + num[i]-'0') % 9;
 
    return (ans == 0)? 9 : ans % 9;
}
