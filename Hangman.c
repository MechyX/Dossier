
//A Very Simple hangman game.



#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>


void instruction();
void printhangman();

int main()
{

    srand(time(NULL));          //uses the system time to generate different numbers.

    // Already Declared Words.


    char GuessWord[][20] = {
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
    int invalidinput=0;

    int ultra=1;

    // Runs Until user decides to play or quit.
    do
    {
        system("COLOR 4E");
        printf("1.Play\n");
        printf("2.Instructions\n");                     //Menu Display
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

    for(i=1;i<30;i++)
    {
        printf("\n\n\n\n\t\t\t\tLOADING");
        Sleep(50);
        system("cls");
        Sleep(50);
    }

        system("COLOR 0C");
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

            printhangman(AvaiLives);



            if(AvaiLives==1)
            {
                printf("It is Your last chance the save man!!!\n\n");
            }

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
                printf("****INVALID INPUT****\n\n\n\n");         //prints it whenever user enters a incorrect input.
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

            printf("Thank you for trying this game!\n");
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
    printf("7.The game is involves more luck compared to the logic.\n");
    printf("9.You can only guess one letter at a time\n");
    printf("10.guessing the same correct letter does not affect the lives\n\n\n");
    printf("\t\t\t\t\t*****GOOD LUCK*****\n\n\n\n\n\n\n");

}


void printhangman(int p)
{

    //Function to depict the picture of hangman.
    //Depends upon number of guesses.

        printf("_____________________\n");

    //To Print the rope

        printf("          |         \n");
        printf("          |         \n");

   if(p<=4)
    {
        printf("          0         \n");
    }

   if(p<=3)
    {
        printf("          |         \n");
    }

    //  "\\" since double is a escape sequence,double slash is to escape the backslash

   if(p<=2)
    {
        printf("         \\|/      \n");
    }
   if(p<=1)
    {
        printf("          |         \n");
        printf("         / \\       \n");
    }

}




