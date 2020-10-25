/*
ATM Machine simulator
	1. Prompt for Pin
	2. Pin correct
		- display:
			- balence inquiry
				- display cash balence
				- Prompt for performing another transaction
			- cash withdraw
				- prompt for amount
				- check for available for balence
				- debit the amount and show available balence
				- Prompt for performing another transaction
			- Deposit Cash
				- prompt for amount deposited
				- add amount to balence
				- Prompt for performing another transaction
			- Exit
		- if not correct: ask for pin again
*/

#include <stdio.h>

int ATM_Transaction();
int anothertransaction, amountToWithdraw, amountToDeposit, pin;
double balence = 5000;

int main()
{
	printf("***** Welcome to your bank ***** \n");
	PIN_PROMPT();
}

int PIN_PROMPT()
{
	printf("Enter your pin number please: \n");
	scanf("%d", &pin);
	if(pin != 1234)
	{
		printf("Pin is incorrect.\n");
		PIN_PROMPT();
	}
	else {
		ATM_Transaction();
	}
}

int ATM_Transaction() 
{
	int choice;
	printf("Enter any option to be served! \n\n");
	printf("1. Balence Inquiry\n");
	printf("2. Cash Withdraw\n");
	printf("3. Deposit Cash\n");
	printf("4. Exit\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: 
			printf("Your bank balence is: %.2f", balence);
			printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit \n\n");
			scanf("%d", &anothertransaction);
			if (anothertransaction == 1)
			{
				ATM_Transaction();
			}
			break;
		case 2: 
			printf("How much do you wish to withdraw?\n");
			scanf("%d", &amountToWithdraw);
			if (amountToWithdraw <= balence) 
			{
				printf("Please collect your cash\n");
				balence -= amountToWithdraw;
				printf("Your available balence is %.2f\n", balence);
				printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit \n\n");
				scanf("%d", &anothertransaction);
				if (anothertransaction == 1)
				{
					ATM_Transaction();
				}	
			}
			else
			{
				printf("It looks like you don't have enough in your account.");
				printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit \n\n");
				scanf("%d", &anothertransaction);
				if (anothertransaction == 1)
				{
					ATM_Transaction();
				}	
			}
			break;
		case 3: 
			printf("How much do you wish to deposit?\n");
			scanf("%d", &amountToDeposit);
			balence += amountToDeposit;
			printf("Your available balence is %.2f\n", balence);
			printf("\n\nDo you want to perform another transaction?\nPress 1 to proceed and 2 to exit \n\n");
			scanf("%d", &anothertransaction);
			if (anothertransaction == 1)
				{
					ATM_Transaction();
				}
			break;
		default: 
			printf("Thanks for using this ATM. Hope to see you again soon.\n");
			break;
	}
}