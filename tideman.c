#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int sov;
}
temppair;

bool checkcirc(int from, int to);


temppair temppairs[MAX * (MAX - 1) / 2];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
temppair temp;
int pair_count;
int candidate_count;
int hops;
// Function prototypes
void printgraph();
int path(int loser);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int a = 0; a < candidate_count; a++)
    {
        if (strcmp(candidates[a], name) == 0)
        {
            ranks[rank] = a;
            //printf("%d\n", ranks[rank]);
            //printf("%d\n", rank);
            return true;

        }

    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int e = 0; e < candidate_count; e++)
    {

        for (int o = e + 1; o < candidate_count; o++)
        {
            preferences[ranks[e]][ranks[o]]++;
            //printf("Preferences: %d\n", preferences[ranks[e]][ranks[o]]);

        }

    }

    /*
    for (int w = 0; w < candidate_count; w++)
    {
        for (int y = 0; y < candidate_count; y++)
        {
            printf("%d   ", preferences[w][y]);


        }
        printf("\n");
    }
    */
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int o = i + 1; o < candidate_count; o++)
        {
            if ((preferences[i][o] - preferences[o][i]) > 0)
            {
                pair_count++;
                temppairs[pair_count - 1].sov = preferences[i][o] - preferences[o][i];
                temppairs[pair_count - 1].winner = i;
                temppairs[pair_count - 1].loser = o;
                pairs[pair_count - 1].winner = i;
                pairs[pair_count - 1].loser = o;                
                //printf("W: %d, L: %d\n", pairs[pair_count - 1].winner, pairs[pair_count - 1].loser);
                //printf("sov: %d\n", pairs[pair_count - 1].sov);
            }
            else if ((preferences[o][i] - preferences[i][o]) > 0)
            {

                pair_count++;
                temppairs[pair_count - 1].sov = preferences[o][i] - preferences[i][o];
                temppairs[pair_count - 1].winner = o; 
                temppairs[pair_count - 1].loser = i;
                pairs[pair_count - 1].winner = o;
                pairs[pair_count - 1].loser = i; 
                //printf("W: %d, L: %d\n", pairs[pair_count - 1].winner, pairs[pair_count - 1].loser);
                //printf("sov: %d\n", pairs[pair_count - 1].sov);
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int changes = 0;
    
    do 
    {
        changes = 0;
        for (int i = 0; i < pair_count - 1; i++)
        {
            for (int j = i + 1; j < pair_count; j++)
            {
                if (temppairs[i].sov < temppairs[j].sov)
                {
                    temp = temppairs[i];
                    temppairs[i] = temppairs[j];
                    temppairs[j] = temp;
                    changes++; 
                }
            }
        }
    } 
    while (changes > 0);

 
    // fill array with winner preferences
    int sov[pair_count];

    for (int i = 0; i < pair_count; i++)
    {
        sov[i] = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
    }

    //sorting function
    int sov_temp;
    pair temporal;
    do
    {
        changes = 0;
        for (int i = 0; i < pair_count - 1; i++)
        {
            for (int j = i + 1; j < pair_count; j++)
            {
                if (sov[i] < sov[j])
                {
                    temporal = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = temporal;

                    sov_temp = sov[j];
                    sov[j] = sov[i];
                    sov[i] = sov_temp;
                }
            }
        }
    } 
    while (changes > 0);
    /*
        for (int i = 0; i < pair_count; i++)
        {
        printf("Temppairs: W: %d, L: %d  || Pairs: W: %d, L %d\n", temppairs[i].winner, temppairs[i].loser, pairs[i].winner, 
        pairs[i].loser);
        }
    */
    return;

}


bool checkcirc(int from, int to)
{
    // first case
    if (from == to)
    {
        return true;    // it forms a cycle
    }
    else
    {
        // second case
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[from][i])    // next node is found
            {
                return checkcirc(i, to);
            }
        }
        return false;
    }
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int winner = 0;
    int loser = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int a = 0; a < pair_count; a++)
        {
            locked[i][a] = false;
        }
    }

    for (int i = 0; i < pair_count; i++)
    {
        //printf("i: %d, Winner: %s, Loser: %s\n", i,pairs[i].winner, pairs[i].loser);
        for (int a = 0; a < candidate_count; a++)
        {
            if (a == pairs[i].winner)
            {
                //printf("Winner: %s, %d\n", candidates[a], a);
                winner = a;
            }
            if (a == pairs[i].loser)
            {
                //printf("Loser: %s, %d\n", candidates[a].name, a);
                loser = a;
            }
        } // Old version, not needed anymore
        hops = 0;

        if (checkcirc(loser, winner) == false)
        {
            locked[winner][loser] = true;
        }
        else
        {
            // circular, so do nothing
        }
    }
    //printgraph();
    return;
}

void printgraph()
{
    for (int locali = 0; locali < candidate_count; locali++)
    {

        for (int locala = 0; locala < candidate_count; locala++)
        {
            printf("%s  ", locked[locali][locala] ? "true" : "false");
        }
        printf("\n");
    }
}
// Print the winner of the election
void print_winner(void)
{
    // TODO
    int counter = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        counter = 0;
        for (int a = 0; a < candidate_count; a++)
        {

            if (locked[a][i] == false)
            {
                counter++;



            }
            if (counter == candidate_count)
            {

                printf("Winner: %s\n", candidates[i]);

            }

        }
    
    }
    return;
}