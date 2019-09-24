/*
    Hangman Game C Code by S RITHESH 19PW29, 1st Year MSc Software Systems

//The header files
//stdio.h has input has been used for basic I/O processes.
//string.h is used to handle character arrays
//stdlib.h is used for random randomise functions.
//conio.h is used for getting a character.
//windows.h is used for using virtual key codes and sleep functions.*/



#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>


void instruction();
void printhangman();

int main()
{

    srand(time(NULL));

    // Already Declared Words.


    char GuessWord[][20] =  {
                              "orange",
                              "yellow",
                              "blue",
                              "plate",
                              "laptop",
                              "shift",
                              "smart",
                              "Phone"             //8 Words index is 7
                            };

        int i;
        printf("\t\t\t");

        for(i=0;i<6;i++)
        {
            printf("*");
        }
            printf("HANGMAN");

        for(i=0;i<6;i++)
        {
            printf("*");
        }

        printf("\n\n");

    int RanIndex = rand()%7;

    int LengthOfWord= strlen(GuessWord[RanIndex]);
    int Guessed=0;
    int oldGuess=0;

    char guessed[20];
    int AvaiLives=5;

    int letterGuesses[8]={0};

    int Exit=0;

    char letterGuessed;
    int choice;
    int invalidinput;


    printf("%s\n\n",GuessWord[RanIndex]);

    do
    {

        printf("1.Play\n");
        printf("2.Instructions\n");
        printf("3.Exit\n\n");

        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
                       break;

        case 2:        instruction();
                       choice=-1;
                       break;

        case 3:        exit(0);
                       break;

        default:       printf("***INVALID INPUT***\n");
                       choice=-1;

        }

    }       while(choice<0);

    // A while loop that runs till the game ends.

    for(i=1;i<100;i++)
    {
        printf("\n\n\n\n\t\t\t\tLOADING");
        system("cls");
        Sleep(5);
    }


    while(Guessed<LengthOfWord)
    {


            oldGuess=Guessed;

            printf("The String now is\n\n");

            for(i=0;i<LengthOfWord;i++)
            {
                    if(letterGuesses[i]==1)
                    {
                        printf("%c ",GuessWord[RanIndex][i]);
                    }

                    else
                    {
                        printf("_ ");
                    }
            }

            printf("\n\n");
            printf("No of Correct Guesses are %d\n\n",Guessed);

            printf("Number of lives remaining:%d\n\n",AvaiLives);

            printf("Guess a letter:  ");

            scanf("\n");
            fgets(guessed,8, stdin);

            printf("\n\n");

            if(strncmp(guessed, "quit" ,4) == 0 )
            {
                Exit=1;
                break;
            }

            letterGuessed=guessed[0];

            if( letterGuessed>='a'&& letterGuessed<='z')
            {

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
        }

        else
        {
            invalidinput=1;
        }

            if(oldGuess==Guessed && !invalidinput)
            {
                AvaiLives--;
                printf("You Entered a wrong answer :(\n");
            }

            if(!AvaiLives && !invalidinput)
            {
                printf("Game over, you ran out of lives!\n");
                break;
            }

            if(oldGuess!=Guessed  && !invalidinput)
                printf("You Entered a correct answer :)\n");

            if(invalidinput)
            {
                printf("****INVALID INPUT****\n\n\n\n");
            }

            //printf("Press Enter to continue\n");
            while(1)
            {
                if(GetAsyncKeyState(VK_RETURN)<0)
                {
                    break;
                }
            }

            invalidinput=0;
            printf("\n");
    }

            printf("\n\n");
            if(Exit)        // If Player wishes to quit the game
            {
                printf("You Exited The game");
            }

            else if(!AvaiLives)
            {
                printf("The word was  %s\n\n",GuessWord[RanIndex]);
            }

            else
            {
                for(i=0;i<LengthOfWord;i++)
                {
                    printf("%c ",GuessWord[RanIndex][i]);
                }
                printf("You won!!!!\n\n");
            }

            return 0;

}





void instruction()
{
    //The player can visit the instruction page through the menu by giving the corresponding input.
    //How to play.


    printf("1.The Game hangman is a simple word guessing game.\n");
    printf("2.The player will have to guess a letter which is in the word.\n");
    printf("3.The player has 5 lives.\n");
    printf("4.The lives reduce one by one for each wrong guess,\n");
    printf("5.Lives are saved for correct guesses.\n");
    printf("6.The Player also can quit the game if he or she is not interested by typing the QUIT in small case when the player is asked for a letter guess.\n");
    printf("7.The player wins he his or her guesses are within the word's total number of letters and having more than 0 zero lives.\n");
    printf("8.The player loses if he or she does not satisfy the above criteria.\n");
    printf("7.The game is involves more luck compared to the logic.\n\n");
    printf("8.You can only guess one letter at a time");
    printf("*****GOOD LUCK*****\n\n\n\n\n\n\n");

}


/*void printhangman()
{

    //Function to depict the picture of hangman.
    //Depends upon number of guesses.


    printf("\t\t\t\t\t\t_____________________\n");

    //To Print the


    printf("\t\t\t\t\t\t          |         \n");
    printf("\t\t\t\t\t\t          |         \n");
    if(AvaiLives==4)
    {
    printf("\t\t\t\t\t\t          0         \n");

    printf("\t\t\t\t\t\t          |         \n");

    //  "\\" since double is a escape sequence,double slash is to escape the backslash

    printf("\t\t\t\t\t\t         \\|/      \n");
    printf("\t\t\t\t\t\t          |         \n");
    printf("\t\t\t\t\t\t         / \\        \n");
}       */







