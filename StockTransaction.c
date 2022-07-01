#include <stdio.h>

#include "StoctTransaction.h"

char StockTrasactionFile[]="StockTransaction.bin";

void IssueEntry()
{
	char Option;
	int ItemFound;
	char ItemName[30];
	STOCK stock;
	FILE *F;
	
	printf("\nEnter Item Code : ");
	scanf("%d",&stock.ItemCode);
	
	fflush(stdin);
	
	/* Display Item Name */
	ItemFound=GetItemName(stock.ItemCode,ItemName);
	
	if(!ItemFound)
	{
		printf("\nInvalid Item Code!...");
		return;	   	   
	}
	
	printf("\nItem Name : %-30s",ItemName);
	printf("\n\nItem Name is Currect? (Y/N) : ");
	scanf("%c",&Option);
	
	fflush(stdin);
	
	if(Option =='n'||Option=='N') return ;
	
	printf("\nEnter the Quantity : ");
	scanf("%f",&stock.Quantity);
	
	fflush(stdin);
	
	stock.st='I';
	
	F=fopen(StockTrasactionFile,"ab");
	
	fwrite(&stock,sizeof(STOCK),1,F);
	
	fclose(F);	  
	
}

void ReceiptEntry()
{
	char Option;
	int ItemFound;
	char ItemName[30];
	STOCK stock;
	FILE *F;
	
	printf("\nEnter Item Code : ");
	scanf("%d",&stock.ItemCode);
	
	fflush(stdin);
	
	/* Display Item Name */
	ItemFound=GetItemName(stock.ItemCode,ItemName);
	
	if(!ItemFound)
	{
		printf("\nInvalid Item Code!...");
		return;	   	   
	}
	
	printf("\nItem Name : %-30s",ItemName);
	printf("\n\nItem Name is Currect? (Y/N) : ");
	scanf("%c",&Option);
	
	fflush(stdin);
	
	if(Option =='n'||Option=='N') return ;
	
	printf("\nEnter the Quantity : ");
	scanf("%f",&stock.Quantity);
	
	fflush(stdin);
	
	stock.st='R';
	
	F=fopen(StockTrasactionFile,"ab");
	
	fwrite(&stock,sizeof(STOCK),1,F);
	
	fclose(F);	  
}

void ListTransactions()
{
	float ClosingStock;
	float ReceiptTotal,IssueTotal;
	FILE *F;
	STOCK Item;
	int ItemCode,ItemFound;
	char ItemName[30],Option;
	
	ReceiptTotal=IssueTotal=0;

	printf("\nEnter Item Code : ");
	scanf("%d",&ItemCode);
	
	fflush(stdin);
	
	/* Display Item Name */
	ItemFound=GetItemName(ItemCode,ItemName);
	
	if(!ItemFound)
	{
		printf("\nInvalid Item Code!...");
		return;	   	   
	}
	
	printf("\nItem Name : %-30s",ItemName);
	printf("\n\nItem Name is Currect? (Y/N) : ");
	scanf("%c",&Option);
	
	fflush(stdin);
	
	if(Option =='n'||Option=='N') return ;
	
	F=fopen(StockTrasactionFile,"rb");
	
	while(fread(&Item,sizeof(STOCK),1,F))
	{
		if(ItemCode==Item.ItemCode)
		{
			if(Item.st=='R')
			{
				printf("\nReceipt %10.2f",Item.Quantity);
				ReceiptTotal+=Item.Quantity;
			}
			else 
			{
				printf("\nIssue %20.2f",Item.Quantity);
				IssueTotal+=Item.Quantity;
			} 
		}	  	  	  	  
	}
	
	if(ReceiptTotal!=0 && IssueTotal!=0)
	{
		ClosingStock=(ReceiptTotal-IssueTotal);
			
		printf("\n---------------------------");
		printf("\nTotal   %10.2f %8.2f",ReceiptTotal,IssueTotal);
		printf("\n---------------------------");
		printf("\n\nClosing Stock =%.2f",ClosingStock);
	}
	else
		printf("\nNo Transaction Found!");	  
	
	fclose(F);
}

int GetClosingStock(int ItemCode)
{
	float ck;
	float R,I;
	FILE *F;
	STOCK Item;
	
	R=I=0;
	
	F=fopen(StockTrasactionFile,"rb");
	
	while(fread(&Item,sizeof(STOCK),1,F))
	{
		if(ItemCode==Item.ItemCode)
		{
			if(Item.st=='R')
				R+=Item.Quantity;
			else 
				I+=Item.Quantity;	   	   	   	  
		}	 	  
	}	

	fclose(F);
	
	ck=(R-I);
	
	return ck;	  
}




