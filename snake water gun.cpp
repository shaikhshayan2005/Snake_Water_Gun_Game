#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomChoice();

int main() 
{
    printf("\t\t\t\t\t\t SNAKE WATER AND GUN \t\t\t\t\n\n");

    int totalRounds = 3;

    int userChoices[3];
    int computerChoices[3];
    int roundResults[3];  

    for (int round = 0; round < totalRounds; round++) 
	{
        printf("\n\t\t\t\t       --- ROUND %d ---  \t\t\t\t\n\n\n", round + 1);

        int yourChoice, computerChoice;

        printf("\t\t --- USER CHOICE ---\n\n");
        printf("You have three choices :\n");
        printf("1. Snake\n");
        printf("2. Water\n");
        printf("3. Gun\n\n");

        printf("Choose a number : ");
        scanf("%d", &yourChoice);

        userChoices[round] = yourChoice;

        printf("Your choice is : ");
        switch (yourChoice) 
		{
            case 1:
                printf("Snake\n\n");
                break;
            case 2:
                printf("Water\n\n");
                break;
            case 3:
                printf("Gun\n\n");
                break;
            default:
                printf("Invalid choice\n");
                continue;

        }

        srand(time(NULL));
        computerChoice = getRandomChoice();
        computerChoices[round] = computerChoice;

        printf("\t\t --- COMPUTER'S TURN --- \n");
        printf("1. Snake\n");
        printf("2. Water\n");
        printf("3. Gun\n\n");

        printf("Computer choice : %d\n", computerChoice);
        
        printf("Computer choice is : ");
        
        switch (computerChoice)
		 {
            case 1:
                printf("Snake\n\n");
                break;
            case 2:
                printf("Water\n\n");
                break;
            case 3:
                printf("Gun\n\n");
                break;
            default:
                printf("Invalid choice\n");
                continue;  
        }
        printf(" Result :\n");
        if (yourChoice == computerChoice)
		 {
            printf("\t TIE!\a\n");
            roundResults[round] = 0; 
        }
		 else if ((yourChoice == 1 && computerChoice == 2) ||
                   (yourChoice == 2 && computerChoice == 3) ||
                   (yourChoice == 3 && computerChoice == 1))
				    {
   
            printf("\t   You win!\n");
            roundResults[round] = 1; 
        } 
		else
		 {
            printf("\t You lose\n\a");
        
            roundResults[round] = 2; 
        }
    }

    
    printf("\n\t\t\t\t --- FINAL RESULTS --- \t\t\t\t\n");

    int userWins = 0, computerWins = 0, ties = 0;

    for (int i = 0; i < totalRounds; ++i)
	 {
        printf("Round %d: User's Choice: %d, Computer's Choice: %d, Result: ", i + 1, userChoices[i], computerChoices[i]);
        if (roundResults[i] == 0)
		 {
            printf("Tie\n");
            ties++;
        }
		 else if (roundResults[i] == 1) 
		 {
            printf("User wins\n");
            userWins++;
        }
		 else
		  {
            printf("Computer wins\n");
            computerWins++;
        }
    }

    
    printf("\n\t\t\t\t --- FINAL WINNER --- \t\t\t\t\n");

    if (userWins > computerWins) 
	{
        printf("Congratulations! You are the final winner!\n");
    }
	 else if (computerWins > userWins)
	  {
        printf("Oh no! Computer is the final winner!\n");
    }
	 else
	  {
        printf("It's a tie! No final winner.\n");
    }

    return 0;
}

int getRandomChoice() 
{
    return (rand() % 3) + 1;
}

