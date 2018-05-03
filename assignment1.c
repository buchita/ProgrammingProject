
/*
DESCRIPTION :
    You are required to develop a program that will operate on an ATM machine for a
    bank. Your program should allow bank customers to manage their PIN. The PIN is a
    4-digit number. You can assume that the PIN has been initially assigned the number:1234
    Your program should be menu-driven and must display a simple menu when run. The
    menu should include the following options:
        1. Enter PIN and verify correct
        2. Change PIN
        3. Display the number of times the PIN was entered (i) Successfully (ii)Incorrectly
        4. Exit Program

Author : Buchita Gitchamnan
Starting Date 01/11/2016
OS version : Windows 10
Complier : Code blocks


*/


#include <stdio.h>
#define PIN 1234

int main()

{
    int password ;
    int currentPin = PIN;
    int option;
    int newPin;
    int newPin2;
    int correct= 0;
    int incorrect = 0;


    do
    {

        //display the menu

        printf("\n Option: \n 1. Enter The PIN \n 2. change the PIN \n 3. Number of times PIN entered \n 4. Exit \n ");
        printf("\n Enter your option Number \n");
        scanf("%d",&option);



            switch(option)
            {
                case 1: //Option 1 Enter the PIN and verify
                {
                    printf("\n Enter the PIN \n");
                    scanf("%d", &password);

                    // to calculate the number of times the PIN entered correctly and incorrectly
                    if (password == currentPin)
                    {
                        printf("\n It is the Correct PIN \n \n");
                        correct++;
                    }// end if

                    else
                    {
                        printf("\n This is an invalid PIN \n \n");
                        incorrect++;

                    }// end else

                    break;
                }//end case 1


                case 2: //Option 2: change the PIN
                {
                    //ask the user to enter the current pin
                    printf("\n Please enter your current PIN \n ");
                    scanf("%d", &password);

                    if (password == currentPin)
                    {
                        correct++;
                        // check if the new PIN is 4 digits

                        if (currentPin > 999 && currentPin < 10000)
                        {
                            //ask the user to enter new pin
                            printf (" \n Please enter the new PIN \n");
                            scanf("%d", &newPin);

                            // ask to enter a new PIN again to verify the correct PIN
                            printf(" \n Please re-enter your new PIN \n");
                            scanf("%d", &newPin2);

                            if (newPin != newPin2)
                            {
                                printf(" The new PIN entered does not match \n Please try again later \n \n");
                            }// end if inner

                            else
                            {
                                printf(" Your new PIN is %d \n \n", newPin);
                                currentPin=newPin;
                            }// end else inner

                        }//end if inner

                    }// end if outer

                    else
                    {
                        // if the pin entered is not the same as 1234 = error
                        incorrect++;
                        printf(" This is an incorrect PIN \n ");

                    }// end else

                    break;

                }//end case 2


            case 3:  //option 3: display the number of times PIN entered
                {
                    printf("\n The number of times you entered the Pin Correctly is %d Incorrectly is %d \n \n", correct, incorrect);

                    break;
                }// end case 3


            case 4: //option 4: Exit
                {
                    return 0;
                }// end case 4


            default:
                {
                    printf("\n Please enter a number between 1 to 4\n ");
                    break;
                }// end default


                }//end switch

    }
    while( option != 4);

}// end main

