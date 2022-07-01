typedef struct StoreItems
{
	int ItemCode;
	char ItemName[30];
	
}STOREITEMS;


/* Basic Functionalities */
void InitializeItems();
int GetItemName(int ItemCode, char *ItemName);
void ListItems();

/* Helper Functions */
STOREITEMS *GetStoreItems();
int GetItemsCount();
void StockList();

