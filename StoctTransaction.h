typedef struct StockTransaction{

	int ItemCode;
	char st;
	float Quantity;	   
	
}STOCK;

void StockList();
void ReceiptEntry();
void ListTransactions();
void IssueEntry();
int GetClosingStock(int ItemCode);

