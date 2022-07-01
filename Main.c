#include <stdio.h>
#include "Store_Items.h"
#include "StoctTransaction.h"

int Menu();

int main()
{
	InitializeItems();
	Menu();
}

int Menu()
{
	int Option;
	
	while(1)
	{
		/* Clear Screen */
		system("cls");
		
		/* Display Menu */
		printf("Zoho Crop Stock Managment");
		printf("\n\n1.Receipt Entry");
		printf("\n2.Issue Entry");
		printf("\n3.Stock List");
		printf("\n4.Stock Transaction Report");
		printf("\n5.View Store Items");
		printf("\n6.Exit");
	
		/* Choice From User */
		printf("\n\nEnter Your Choice (1-6) : ");
		scanf("%d",&Option);
		
		/* Clear Buffer */
		fflush(stdin);
		
		switch(Option)
		{
			case 1 :
				ReceiptEntry(); /* Receip Entery */
				break;
			case 2 :
				IssueEntry(); /* Issue Entery */
				break;
			case 3 :
				StockList(); /* Stock List */
				break;
			case 4 :
				ListTransactions(); /* Stock Transaction Report */
				break;
			case 5 :
				ListItems(); /* List Items */
				break;
			case 6 :
				return;
				break;
			default:
				printf("\nInvalid Option. Pls Try Again!");
				break;	  
		}
		
		printf("\n\nPress Any Key To Continue.......");
		getch();	
	}
}

