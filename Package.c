#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int main()
{

    srand(time(NULL));

    char GuessWord[][20] =  {
                              "orange",
                              "yellow",
                              "blue",
                              "program",
                              "laptop",
                              "shift",
                              "display",
                              "Phone"             //8 Words index is 7
                            };

    int RanIndex = rand()%7;

    int LengthOfWord= strlen(GuessWord[RanIndex]);
    int Guessed=0;
    int oldGuess=0;

    char guessed[20];
    int AvaiLives=LengthOfWord;

    int letterGuesses[8]={0};
    int i;
    int exit=0;

    char letterGuessed;

    // Game Loop
    while(Guessed<LengthOfWord)
    {
        printf("No of Correct Guesses are %d\n",Guessed);
        printf("Guess a letter:");
        fgets(guessed,8, stdin);

        if(strncmp(guessed, "quit" ,4) == 0 )
        {
            exit=1;    break;
        }

        letterGuessed=guessed[0];


        for(i=0;i< LengthOfWord;i++)
        {
            if(letterGuesses[i]==1)
            {
                continue;
            }
            if(letterGuessed == GuessWord[RanIndex][i])
            {
                letterGuesses[i]=1;
                Guessed++;
            }
        }

        if(oldGuess==Guessed)
         {
                AvaiLives--;
          printf("You Entered a wrong answer :(\n");
         }

        if(!AvaiLives)
        {
            printf("Game over, you ran out of lives!\n");
            break;
        }
        if(oldGuess!=Guessed)
            printf("You Entered a correct answer :)\n");

    }

        if(exit)        // If Player wishes to quit the game
        {
            printf("You Exited The game");
        }

        else if(!AvaiLives)
        {
            printf("The word was  %s",GuessWord[RanIndex]);
        }

        else
        {
            printf("You won!!!!");
        }
  return 0;

}
