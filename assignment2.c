/*
        DESCRIPTION:
                                    Assignment 2
                                                                The program for security authorisation based on access codes.
                                                                The access codes are 4 single-digit integer numbers between 0-9.
                                                                The program should allow a user to enter a code, encrypt the number and compare it
                                                                to an authorised access code. The program should also allow the user to decrypt an
                                                                encrypted code.
        DATE :  27/02/17

        AUTHOR:  Buchita Gitchamnan - C16348651

        COMPLIER: CodeBlocks

*/

#include <stdio.h>
#include <stdlib.h>


#define SIZE 4
#define COUNT 2

//Declare prototypes
void opt1 (int*);
void opt2 (int*, int* );
void opt3 (int*);
void opt4 (int*);
void compare (int*, int*);


int main()
{
    int option;
    int pass[SIZE];
    int counter[COUNT] = { 0, 0 };
    int check[COUNT] = { 0, 0 };

    //start of do...while loop
    do
    {
        //Display the options
        printf("\n \n ----------Select an option----------"
                    "\n 1. Enter code "
                    "\n 2. Encrypt code"
                    "\n 3. Decrypt code "
                    "\n 4. Display the number of times the code was entered i.correctly and  ii. incorrectly "
                    "\n 5. Exit Program. \n  \n ");
       //scan in the option selected
        scanf("%d", &option);

        switch(option)
        {
            case 1 : //option 1 enter in the PIN
            {
                //pass to option one for entering the PIN
                opt1(pass);

                //increment the PIN is entered
                (*check)++;

                break;
            }//end case 1

            case 2 : //option 2 encrypt PIN
            {
                //check if the PIN is entered or else the user can't enter this option.
                if (*check >=1)
                {
                    //pass to option two for encryption.
                    opt2(pass, counter );

                    //increment the PIN is encrypted.
                    (*(check+1) )++;

                }//end if
                else
                {
                    printf("\n Please enter your PIN before encrypt it. \n");
                }
                break;
            }//end case 2

            case 3 : //decrypt PIN
            {
                //check if the PIN is encrypted and the PIN is entered.
                if( ((*(check+1)) >=1) && (*check >=1) )
                {
                    //pass to function 3 for decryption.
                    opt3(pass);
                }
                else
                {
                    printf("\nPlease select encryption option before select the decryption the PIN. \n ");
                }
                break;
            }//end case 3

           case 4 : //display : correctly? incorrectly?
            {
                //pass to option 4 for displaying PIN entered in correctly or incorrrectly.
                opt4 (counter);

                break;
            }//end case 4

            case 5 : //terminate the program
            {
                return 0;
            }//end case 5

            default:
            {
                //error checking
                printf(" \n Please select the option 1 to 5. \n");
                break;

            }//end default

        }//end switch()

    }//end do()
    while(option != 5);  //infinite loop unless terminate it

}//end main()






//Implement function option1
void opt1 (int *code)
{
    int i;

    //Ask user to enter code
    printf("\n \nEnter 4 digits code one by one. \n");

    //scan in the 4 digits PIN.
    for (i=0; i<SIZE; i++)
    {
        scanf("%d", &*( code+i) );

        //error checking - if the number is bigger than 9 , ask the user to  enter another number.
        if ( *(code+i) >9 )
        {
            printf("\nPlease enter a new digit. \n");
            scanf("%d", &*(code+i ));
            break;
        }//end if
    }//end for()

    //display the PIN entered
    printf("\nYour PIN is ");
    for (i=0; i<SIZE; i++)
    {
        printf("%d", *(code+i));
    }
}//end function 1





//Implement function option 2
void opt2 (int *pass, int *counter1)
{
    //Encryption
    int temp;
    int temp1;
    int i;


    //Swap the 1st number with the 3rd number.

    temp = *pass;       //put value of  1st element to temp
    *pass =  *(pass+2);     //put value of 3rd element to 1st element
    *(pass+2) = temp;       //put value of temp into 3rd element


    //Swap the 2nd number with the 4th number.

    temp1 = *(pass+1);      //put value of 2nd element to temp
    *(pass+1) = *(pass+3);      //put value of 4th element to 2nd element
    *(pass+3) = temp1;      //put value of temp to 4th element


    //Add 1 to each number.
    for(i=0; i<SIZE; i++)
    {
       (*(pass + i))++ ;
    }

    //if any number has a value equal to 10, change this value to 0
    for (i=0; i<SIZE; i++)
    {
        if ( *(pass+i) ==10)
        {
            *(pass+i)= 0;

        }//end if

    }//end for

    //display the encrypted code
    printf("\nThe encrypted code is ");
    for(i=0; i<SIZE; i++)
    {
        printf("%d", *(pass+i));
    }//end for

    //pass to comparision function
    compare(pass, counter1);

}//end function option 2





//Implement function option 3
void opt3 (int *pass)
{
    //Decryption
    int i;
    int temp;
    int temp1;


    //subtract 1 from each number
    for (i=0; i<SIZE; i++)
    {
        (*(pass+i))--;

    }//end for


    //if any number has a value equal to -1, change this value to 9.
    for(i=0; i<SIZE; i++)
    {
        if( *(pass+i) == -1)
        {
            (*(pass+i) ) = 9;

        }//end if

    }//end for


    //swap the 1st number with the 3rd number.

    temp = *pass;       //put value of 1st element to temp
    *pass = *(pass+2);      //put value of 3rd element to 1st eleme nt
    *(pass+2) = temp;       //put value of temp to 3rd element

    //swap the 2nd number with the 4th number

    temp1 = *(pass+1);      //put value of the 2nd element to temp
    *(pass+1) = *(pass+3);      //put value of the 4th element to 2nd element
    *(pass+3) = temp1;      //put value of temp to 4th element

    //display the decrypted code
    printf("\nThe decrypt code is ");
    for ( i = 0; i<SIZE; i++)
    {
        printf("%d", *(pass+i));
    }//end for

}//end function option3





//Implement option 4
void opt4 (int *counter1)
{
    //display the num of times code was entered correctly and incorrectly
    printf("\nThe code was entered %d correctly and %d incorrectly.\n", *counter1, *(counter1+1) );

}//end function option 4




//implement the compqrision function.
void compare(int * pass, int * counter1)
{
    int i;
    int correct =0;
    int incorrect =0;
    const int access_code[SIZE] = {4,5,2,3};            //can't be changed

    //compare the PIN to access_code
    for ( i=0; i<SIZE; i++)
    {
        if ( *(access_code+i) == *(pass+i) )
        {
            correct++;

        }//end if

        else
        {
            incorrect++;

        }//emd else

    }//end for

    //verify the correct PIN
    if ( correct == 4 )
    {
        printf("\nCORRECT CODE. \n");

        //counter to count correct.
        (*counter1 )++;

    }//end if
    else
    {
        printf("\nERROR CODE.\n");

        //counter to count incorrect.
        (*(counter1+1))++;

    }//end else

}//end comparision function


