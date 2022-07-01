#include <stdio.h>
#include <string.h>
#include "Store_Items.h"


char File[]=".\\binaryfile.bin";
STOREITEMS Items[100];
int CountOfItems=0;

void InitializeItems()
{
	STOREITEMS Item;
	FILE *F;
	
	/* open the file */
	F=fopen(File,"rb");
	
	/* Read The File  load the content hardisk to memory*/
	while(fread(&Item,sizeof(STOREITEMS),1,F))
	{
		Items[CountOfItems].ItemCode=Item.ItemCode;
		strcpy(Items[CountOfItems].ItemName,Item.ItemName);
		CountOfItems++;
	}
	
	/* Close the file */
	fclose(F);	  
}

void ListItems()
{
	int i;
	STOREITEMS Item;
	
	printf("\n\nList Items");
	printf("\n-------------");
	
	for(i=0;i<CountOfItems;i++)
	{
		Item=Items[i];
		printf("\n%2d  %-30s",Item.ItemCode,Item.ItemName);
	}
}

int GetItemName(int ItemCode, char *ItemName)
{
	int ItemFound=0;
	int i;
	
	for(i=0;i<CountOfItems;i++)
	{
		if(ItemCode==Items[i].ItemCode)
		{
			strcpy(ItemName,Items[i].ItemName);
			ItemFound=1;
			break;
		}
	
	}
	return ItemFound;
}
void StockList()
{	 
	int i;
	STOREITEMS Item;
	float ClosingStock;
	
	for(i=0;i<CountOfItems;i++)
	{
		Item=Items[i];
		ClosingStock=GetClosingStock(Item.ItemCode);
		printf("\n%3d %-30s %10.2f",Item.ItemCode,Item.ItemName,ClosingStock);	  
	}
	
}

