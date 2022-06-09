#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 9

bool vote(char name[]);
void print_winner(void);

typedef struct
{
    string name;
    int votes;
}
candidate;
        
candidate candidates[9];
int candidate_count;  
int voternum;
int i; 
int result0 = 1;
int result1 = 1;
int result2 = 1;
int result3 = 1;
int result4 = 1;
int result5 = 1;
int result6 = 1;
int result7 = 1;
int result8 = 1;
int I;

int main(int argc, char *argv[])  
{
    
    

    candidate_count = argc - 1;
    if (argc >= 2 && argc <= 10) 
    {
        
        for (i = 0; i < candidate_count; i++)
        {
            candidates[i].name = "";
            candidates[i].votes = 0;
            candidates[i].name = argv[i + 1];
            printf("%s\n", candidates[i].name);
        }
        
        voternum = get_int("Number of voters: ");
        int cyclecount = 0;
        
        for (I = 0; I <= voternum - 1; I++)
        {
            
            char name[10];
            printf("Vote: ");
            scanf("%s", name);
            if (!vote(name))
            {
                printf("Invalid vote.\n");
            }
        }
     
    
               
        
        
        print_winner();
    }
    else
    {
        return 1;
    }    
    return 0;
}

bool vote(char name[])
{
    for (i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
            
        }
    }
    return false;
}

void print_wanner(void)
{
    
    int changes = 0;
    candidate temp;
   
   
    
    while (changes == 0) 
    {
        changes = 0;
        for (I = 0; I < candidate_count; I++)
        {
            
        
        
            for (i = 0; i < candidate_count - 1; i++)
            {
                
                
                if (candidates[i].votes > candidates[i + 1].votes)
                {
                    
                    //printf("%s\n", candidates[i].name);
                    
                    temp = candidates[i];
                    candidates[i] = candidates[i + 1];
                    candidates[i + 1] = temp;
                    changes++;
                    
                    
                }
                else
                {
                    
                    changes++;
                }
                
                
                
            }
            
            
            
            
        }    
        
    }
}

void print_winner(void)
{
    
    print_wanner();
    
    for (i = 0; i <= candidate_count; i++)
    {
        
        if (candidates[i].votes == candidates[candidate_count - 1].votes)
        {
            printf("%s\n", candidates[i].name);
            
        }
        
        
    }
    //printf("%s\n", candidates[candidate_count - 1].name);
    
    
        
   
        
    
    
}