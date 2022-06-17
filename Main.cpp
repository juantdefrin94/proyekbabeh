#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include "Function.h"
#define MYERROR 9999999
#define USERNAME 1
#define PASSWORD 2
#define CLEAR system("cls")
#define PAUSE cout<<" Press Any Key . . .";getch()
#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
using namespace std;

class Main{
	
	public:
		Main(){
			login();
		}
		
		void login(){
			CLEAR;
			setFontSize(28, 64);
			string username, password;
			setWindowSize("25", "9");
			moveExacCenter();
			setcolor(4); printf("\n      %c", 206); cout << string(11, 205); printf("%c\n", 206);
			setcolor(4); printf("   >> %c", 186); setcolor(7); printf(" L O G I N "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n      %c", 206); cout << string(11, 205); printf("%c\n\n", 206); setcolor(7);
			printf(" Username : ");
			printf("\n Password : ");
			printf("\n");
			back:
			changeCursorPosition(12, 5);
			username = getString(USERNAME);
			changeCursorPosition(12, 6);
			password = getString(PASSWORD);
			if(username != "dedihadi0508" || password != "dedi0508"){
				MessageBox(0, "Username or Password is Wrong", "MYERROR", 0); 
				changeCursorPosition(12, 5);
				cout << string(12, ' ');
				changeCursorPosition(12, 6);
				cout << string(12, ' ');
				goto back;
			}else{
				mainPage();
			}
		}
		
		void mainPage(){
			time_t now = time(NULL);
			string day, temp = "";
			struct tm *now_tm = localtime(&now);
			int d = now_tm->tm_wday;
			if (d == 0) day = "Sunday";
			else if (d == 1) day = "Monday";
			else if (d == 2) day = "Tuesday";
			else if (d == 3) day = "Wednesday";
			else if (d == 4) day = "Thursday";
			else if (d == 5) day = "Friday";
			CLEAR;
			setFontSize(16, 38, 600);
			setWindowSize("36", "18");
			moveExacCenter();
			
			//Title
			setcolor(4); printf("\n        %c", 206); cout << string(18, 205); printf("%c\n", 206);
			printf("     >> %c", 186); setcolor(7); printf(" M A I N  P A G E "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n        %c", 206); cout << string(18, 205); printf("%c\n\n", 206); setcolor(7);
			
			//Hari, Sapaan
			if(d == 6) temp = " It's Saturday, it's time to collect";
			else{
				temp += " It's ";
				temp += day;
				temp += ", have a nice day :)";
			}
			printCenter(temp, 36);
			puts("\n");
			
			//Menu
			setcolor(8); printf("     >> Selling items in bag <<\n"); setcolor(7);
			printf("            Update Items   \n");
			printf("\t  View  Bag  Stock\n");
			printf("\t  View  Main Stock\n");
			printf("      Export file f/ Last Data\n");
			printf("\t  View Last History\n");
			printf("\t\tEXIT\n");
			changeCursorPosition(31, 7);
			
			//Ganti Menu
			int pil = 1;
			backHistory:
			char key = getch();
			while(key != 13){
				if(key == DOWN){
					if(pil == 1){
						changeCursorPosition(5, 7);
						printf("   Selling items in bag   ");
						changeCursorPosition(9, 8);
						setcolor(8); printf(">> Update Items <<"); setcolor(7);
						pil = 2;
					}else if(pil == 2){
						changeCursorPosition(9, 8);
						printf("   Update Items   ");
						changeCursorPosition(7, 9);
						setcolor(8); printf(">> View  Bag  Stock <<"); setcolor(7);
						pil = 3;
					}else if(pil == 3){
						changeCursorPosition(7, 9);
						printf("   View  Bag  Stock   ");
						changeCursorPosition(7, 10);
						setcolor(8); printf(">> View  Main Stock <<"); setcolor(7);
						pil = 4;
					}else if(pil == 4){
						changeCursorPosition(7, 10);
						printf("   View  Main Stock   ");
						changeCursorPosition(3, 11);
						setcolor(8); printf(">> Export file f/ Last Data <<"); setcolor(7);
						pil = 5;
					}else if(pil == 5){
						changeCursorPosition(3, 11);
						printf("   Export file f/ Last Data   ");
						changeCursorPosition(7, 12);
						setcolor(8); printf(">> View Last History <<"); setcolor(7);
						pil = 6;
					}else if(pil == 6){
						changeCursorPosition(7, 12);
						printf("   View Last History   ");
						changeCursorPosition(13, 13);
						setcolor(8); printf(">> EXIT <<"); setcolor(7);
						pil = 7;
					}
				}else if(key == UP){
					if(pil == 2){
						changeCursorPosition(9, 8);
						printf("   Update Items   "); 
						changeCursorPosition(5, 7);
						setcolor(8); printf(">> Selling items in bag <<"); setcolor(7);
						pil = 1;
					}else if(pil == 3){
						changeCursorPosition(7, 9);
						printf("   View  Bag  Stock   "); 
						changeCursorPosition(9, 8);
						setcolor(8); printf(">> Update Items <<"); setcolor(7);
						pil = 2;
					}else if(pil == 4){
						changeCursorPosition(7, 10);
						printf("   View  Main Stock   ");
						changeCursorPosition(7, 9);
						setcolor(8); printf(">> View  Bag  Stock <<"); setcolor(7);
						pil = 3;
					}else if(pil == 5){
						changeCursorPosition(3, 11);
						printf("   Export file f/ Last Data   ");
						changeCursorPosition(7, 10);
						setcolor(8); printf(">> View  Main Stock <<"); setcolor(7);
						pil = 4;
					}else if(pil == 6){
						changeCursorPosition(7, 12);
						printf("   View Last History   ");
						changeCursorPosition(3, 11);
						setcolor(8); printf(">> Export file f/ Last Data <<"); setcolor(7);
						pil = 5;
					}else if(pil == 7){
						changeCursorPosition(13, 13);
						printf("   EXIT   ");
						changeCursorPosition(7, 12);
						setcolor(8); printf(">> View Last History <<"); setcolor(7);
						pil = 6;
					}
				}
				key = getch();
			}
			int check = scanHistory();
			switch(pil){
				case 1:
					sellingItems();
					break;
				case 2:
					updateItem();
					break;
				case 3:
					viewBagStock();
					break;
				case 4:
					viewStock();
					break;
				case 5:
					if(check == 0) MessageBox(NULL,"No Data Found!","Error", MB_ICONERROR | MB_OK);
					else exportFile();
					break;
				case 6:
					if(check == 0) MessageBox(NULL,"No Data Found!","Error", MB_ICONERROR | MB_OK);
					else viewHistory();
					break;
				case 7:
					exit(1);
			}
			goto backHistory;
		}
		
		void sellingItems(){
			CLEAR;
			char key;
			setFontSize(10, 25, 600);
			viewStockPageWindows();
			scanGoodsInBag();
			moveCenter();
			
			//Title, stock di tas, yang mau dijual
			setcolor(4); printf("\n\t        %c", 206); cout << string(26, 205); printf("%c\n", 206);
			printf("\t     >> %c", 186); setcolor(7); printf(" S E L L L I N G  I T E M "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n\t        %c", 206); cout << string(26, 205); printf("%c\n\n", 206);
			
			//Head Table
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			setcolor(4); printf(" %c ", 186); setcolor(7); printf("ID "); setcolor(4); printf("%c       ", 186); setcolor(7); printf("Name       "); setcolor(4);
			printf("%c ", 186); setcolor(7); printf("Quantity "); setcolor(4); printf("%c ", 186); setcolor(7); printf("Purchase ");
			setcolor(4); printf("%c ", 186); setcolor(7); printf("Selling "); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			
			//Content
			int sizeGoods = goodsInBag.size();
			for(int i = 0; i < sizeGoods; i++){
				if(atoi(goodsInBag[i].quantity) > 0){
					printf(" %c ", 186); setcolor(7); printf("%-2d ", i + 1); setcolor(4); printf("%c ", 186); setcolor(7);
					printf("%-16s ", goodsInBag[i].name); setcolor(4); printf("%c ", 186); setcolor(7); printf("= %-6s ", goodsInBag[i].quantity); 
					setcolor(4); printf("%c ", 186); setcolor(7); printf("> %-6s ", goodsInBag[i].purchase); setcolor(4); printf("%c ", 186); setcolor(7);
					printf("< %-5s ", goodsInBag[i].selling); setcolor(4); printf("%c\n", 186);
					printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
					printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
				}
			}
			
			//Info
			setcolor(7);
			printf("\n Note: = (Quantity), > (Purchase Price), < (Selling Price)\n");
			printf(" Are there any buyers today ? <Yes(ENTER)/No(ESC)>");
			do{
				key = getch();
				if(key == ESC){
					mainPage();
					exit(0);
				}else if(key == ENTER){
					break;
				}
			}while(true);
			printf("\n Press ENTER to return to Main Page\n");
			string name;
			
			//Nama Pembeli
			printf(" Who is the buyer ? ");
			name = getString(USERNAME);
			if(name == ""){
				mainPage();
				exit(0);
			}
			int id;
			back:
			//Beli apa
			cout << "\n What did " << name << " buy (ID) ? ";
			id = getNumber();
			if(id == MYERROR){
				mainPage();
				exit(0);
			}else{
				if(id < 1 || id > goodsInBag.size() || strcmp(goodsInBag[id - 1].quantity,"0") == 0) goto back;	
			}
			//Berapa Belinya
			int many;
			back2:
			cout << "\n How much did " << name << " buy ? ";
			many = getNumber();
			if(many == MYERROR){ //Kalo cuma enter
				mainPage();
				exit(0);
			}else{
				if(many <= 0 || many > atoi(goodsInBag[id - 1].quantity)) goto back2;
			}
			
			//Bayarnya ngutang ato bayar langsung
			char paymentMethod[5];
			printf("\n What payment method ac is used ? <Debt(ENTER)/Cash(ESC)> ");
			do{
				key = getch();
				if(key == 13){
					strcpy(paymentMethod, "Debt");
					break;
				}else if(key == 27){
					strcpy(paymentMethod, "Cash");
					break;
				}
			}while(true);
			
			//Nanya datanya bener apa kaga
			printf("\n Are you sure the data is correct ? <Yes(ENTER)/No(ESC)> ");
			do{
				key = getch();
				if(key == 13){
					break; //Sell and Update data
				}else if(key == 27){
					mainPage(); //Cancel to Sell and Update data 
					exit(0);
				}
			}while(true);
			
			//Update the profit
			int prof = goodsInBag[id - 1].selling - goodsInBag[id - 1].purchase;
			prof *= many;
			int now;
			FILE *op = fopen("Data/Profits.txt", "r");
			fscanf(op, "%d", &now);
			fclose(op);
			now += prof;
			op = fopen("Data/Profits.txt", "w");
			fprintf(op, "%d", now);
			fclose(op);
			
			//Get Date
			time_t nows = time(NULL);
			struct tm *now_tm = localtime(&nows);
			int d = now_tm->tm_mday;
			int m = now_tm->tm_mon + 1;
			int y = now_tm->tm_year + 1900;
			
			//Update Stock
			char tempc[30];
			int temp = atoi(goodsInBag[id - 1].quantity);
			temp -= many;
			itoa(temp, tempc, 10);
			strcpy(goodsInBag[id - 1].quantity, tempc);
			op = fopen("StockinBag/StockinBag.txt", "w");
			int goodsSize = goodsInBag.size();
			for(int i = 0; i < goodsSize; i++){
				if(i != 0) fprintf(op, "\n%s %s %s %s", goodsInBag[i].quantity, goodsInBag[i].purchase, goodsInBag[i].selling, goodsInBag[i].name);
				else fprintf(op, "%s %s %s %s", goodsInBag[i].quantity, goodsInBag[i].purchase, goodsInBag[i].selling, goodsInBag[i].name);
			}
			
			//Updated History
			int check = scanHistory();
			char buyerName[50];
			strcpy(buyerName, name.c_str());
			if(check == 0){
				op = fopen("Data/History.txt", "w");
				fprintf(op, "%s#%s#%d#%s#%d#%d#%d", buyerName, goodsInBag[id - 1].name, many, paymentMethod, d, m, y);	
			}else{
				op = fopen("Data/History.txt", "a");
				fprintf(op, "\n%s#%s#%d#%s#%d#%d#%d", buyerName, goodsInBag[id - 1].name, many, paymentMethod, d, m, y);	
			}
			fclose(op);
			
			//Succes
			printf("\n Succesfully Updated !!!\n");
			fclose(op);
			PAUSE;
			mainPage();
		}
		
		void updateItem(){
			CLEAR;
			setFontSize(10, 25);
			viewStockPageWindows();
			moveCenter();
			scanGoods();
			
			//Title
			setcolor(4); printf("\n\t          %c", 206); cout << string(22, 205); printf("%c\n", 206);
			printf("\t       >> %c", 186); setcolor(7); printf(" U P D A T E  I T E M "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n\t          %c", 206); cout << string(22, 205); printf("%c\n\n", 206);
			
			//Head Table
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			setcolor(4); printf(" %c ", 186); setcolor(7); printf("ID "); setcolor(4); printf("%c       ", 186); setcolor(7); printf("Name       "); setcolor(4);
			printf("%c ", 186); setcolor(7); printf("Quantity "); setcolor(4); printf("%c ", 186); setcolor(7); printf("Purchase ");
			setcolor(4); printf("%c ", 186); setcolor(7); printf("Selling "); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			
			//Content
			int sizeGoods = goods.size();
			for(int i = 0; i < sizeGoods; i++){
				printf(" %c ", 186); setcolor(7); printf("%-2d ", i + 1); setcolor(4); printf("%c ", 186); setcolor(7);
				printf("%-16s ", goods[i].name); setcolor(4); printf("%c ", 186); setcolor(7); printf("= %-6s ", goods[i].quantity); 
				setcolor(4); printf("%c ", 186); setcolor(7); printf("> %-6s ", goods[i].purchase); setcolor(4); printf("%c ", 186); setcolor(7);
				printf("< %-5s ", goods[i].selling); setcolor(4); printf("%c\n", 186);
				printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
				printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			}
			
			//info
			setcolor(7);
			printf("\n Note: = (Quantity), > (Purchase Price), < (Selling Price)\n");
			printf(" Select the Item ID that you want to update . . .\n (ESC to Main Page) . . .\n");
			printf(" >> ");
			backUpdate:
			int pil = getNumber();
			if(pil > sizeGoods || pil < 1){
				if(pil == 9402){
					mainPage();
				}else{
					printf("\n Item ID not found . . .");
					changeCursorPosition(4, 52);
					cout << string(10, ' ');
					changeCursorPosition(4, 52);
					goto backUpdate;
				}
				exit(0);
			}
			update(pil - 1);
		}
		
		void update(int id){
			CLEAR;
			setFontSize(10, 25);
			viewStockPageWindows();
			moveCenter();
			
			int len = strlen(goods[id].name);
			printf("\n ESC to Main Page, blank ENTER to SKIP\n\n");
			
			//Head Table
			setcolor(4);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			setcolor(4); printf(" %c ", 186); setcolor(7); printf("ID "); setcolor(4); printf("%c       ", 186); setcolor(7); printf("Name       "); setcolor(4);
			printf("%c ", 186); setcolor(7); printf("Quantity "); setcolor(4); printf("%c ", 186); setcolor(7); printf("Purchase ");
			setcolor(4); printf("%c ", 186); setcolor(7); printf("Selling "); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			
			//Content
			printf(" %c ", 186); setcolor(7); printf("%-2d ", id + 1); setcolor(4); printf("%c ", 186); setcolor(7);
			printf("%-16s ", goods[id].name); setcolor(4); printf("%c ", 186); setcolor(7); printf("= %-6s ", goods[id].quantity); 
			setcolor(4); printf("%c ", 186); setcolor(7); printf("> %-6s ", goods[id].purchase); setcolor(4); printf("%c ", 186); setcolor(7);
			printf("< %-5s ", goods[id].selling); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			
			//Info
			setcolor(7);
			printf("\n >> %s\n", goods[id].name);
			printf(" ===");
			for(int i = 0; i < len; i++) printf("=");
			printf("\n\n");
			if(goods[id].quantity > 0){
				printf(" Do you want to put it in your bag <Yes(ENTER)/No(ESC)> ?\n");
				do{
					char key = getch();
					int stop = 0;
					if(key == ENTER){
						int quantity = -1;
						printf(" press ESC to cancel . . .\n");
						do{
							printf(" How many items do you want to add to your bag : ");
							quantity = getNumber();
							if(quantity == 9402){
								printf("\n Canceled . . .\n");
								stop = 1;
								break;	
							}else if(quantity <= 0) printf("\n The Quantity must be a positive number!\n");
							else if(quantity > atoi(goods[id].quantity)) printf("\n The Quantity is exceeds the limit!\n");
							else{
								char temp[30];
								int goodss = atoi(goods[id].quantity);
								goodss -= quantity;
								itoa(goodss, temp, 10);
								strcpy(goods[id].quantity, temp);
								FILE *op = fopen("Goods/MyGoods.txt", "w");
								int sizeGoodsg = goods.size();
								for(int i = 0; i < sizeGoodsg; i++){
									if(i != 0) fprintf(op, "\n%s %s %s %s", goods[i].quantity, goods[i].purchase, goods[i].selling, goods[i].name);
									else fprintf(op, "%s %s %s %s", goods[i].quantity, goods[i].purchase, goods[i].selling, goods[i].name);
								}
								fclose(op);
								goodss = atoi(goodsInBag[id].quantity);
								goodss += quantity;
								itoa(goodss, temp, 10);
								strcpy(goodsInBag[id].quantity, temp);
								op = fopen("StockinBag/StockinBag.txt", "w");
								int sizeGoodsgib = goodsInBag.size();
								for(int i = 0; i < sizeGoodsgib; i++){
									if(i != 0) fprintf(op, "\n%s %s %s %s", goodsInBag[i].quantity, goodsInBag[i].purchase, goodsInBag[i].selling, goodsInBag[i].name);
									else fprintf(op, "%s %s %s %s", goodsInBag[i].quantity, goodsInBag[i].purchase, goodsInBag[i].selling, goodsInBag[i].name);
								}
								fclose(op);
								scanGoodsInBag();
								stop = 1;
								printf("\n %s in your bag has now increased\n", goods[id].name);
								PAUSE;
								mainPage();
								break;
							}
						}while(quantity <= 0 || quantity > atoi(goods[id].quantity));
						if(stop == 1) break;
					}else if(key == ESC){
						int quantity = -1;
						int temp = atoi(goods[id].quantity);
						do{
							printf("\n Update quantity of %s : ", goods[id].name);
							quantity = getNumber();
							if(quantity < 0) printf("\n Quantity of %s must a positive number!\n", goods[id].name);
							if(quantity == 9402){
								mainPage();
								exit(0);
							}else if(quantity == MYERROR) quantity = temp;
							
						}while(quantity < 0);
						printf("\n");
						int purchase = -1;
						temp = atoi(goods[id].purchase);
						do{
							printf("\n Update purchase price of %s : ", goods[id].name);
							purchase = getNumber();
							if(purchase < 0) printf("\n Purchase Price of %s must a positive number!\n", goods[id].name);
							if(purchase == 9402){
								mainPage();
								exit(0);
							}else if(purchase == MYERROR) purchase = temp;
						}while(purchase < 0);
						printf("\n");
						int selling = -1;
						temp = atoi(goods[id].selling);
						do{
							printf("\n Update selling price of %s : ", goods[id].name);
							selling = getNumber();
							if(selling < 0) printf("\n Selling Price of %s must a positive number!\n", goods[id].name);
							if(selling == 9402){
								mainPage();
								exit(0);
							}else if(selling == MYERROR) selling = temp;
						}while(selling < 0);
						printf("\n Are you sure you will change %s <y(ENTER)/n(ESC)> ?\n", goods[id].name);
						do{
							char key = getch();
							if(key == ENTER){
								char temp[30];
								if(atoi(goods[id].quantity) != quantity || atoi(goods[id].purchase) != purchase || atoi(goods[id].selling) != selling){
									itoa(quantity, temp, 10);
									strcpy(goods[id].quantity, temp);
									itoa(purchase, temp, 10);
									strcpy(goods[id].purchase, temp);
									itoa(selling, temp, 10);
									strcpy(goods[id].selling, temp);
									FILE *op = fopen("Goods/MyGoods.txt", "w");
									int sizeGoodsg = goods.size();
									for(int i = 0; i < sizeGoodsg; i++){
										if(i != 0) fprintf(op, "\n%s %s %s %s", goods[i].quantity, goods[i].purchase, goods[i].selling, goods[i].name);
										else fprintf(op, "%s %s %s %s", goods[i].quantity, goods[i].purchase, goods[i].selling, goods[i].name);
									}
									fclose(op);
									scanGoods();
									printf(" Data updated successfully . . .");
								}else{
									printf(" No Data Updated . . .\n");
								}
								PAUSE;
								mainPage();
								exit(1);
							}else if(key == ESC){
								printf(" Data updated unsuccessfully ");
								PAUSE;
								mainPage();
								exit(0);
							}
						}while(true);
						break;
					}
				}while(true);
			}
		}
		
		void viewBagStock(){
			CLEAR;
			setFontSize(10, 25);
			viewStockPageWindows();
			moveCenter();
			scanGoods();
			
			//Title
			setcolor(4); printf("\n\t       %c", 206); cout << string(27, 205); printf("%c\n", 206);
			printf("\t    >> %c", 186); setcolor(7); printf(" V I E W  B A G  S T O C K "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n\t       %c", 206); cout << string(27, 205); printf("%c\n\n", 206);
			
			//Head Table
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			setcolor(4); printf(" %c ", 186); setcolor(7); printf("ID "); setcolor(4); printf("%c       ", 186); setcolor(7); printf("Name       "); setcolor(4);
			printf("%c ", 186); setcolor(7); printf("Quantity "); setcolor(4); printf("%c ", 186); setcolor(7); printf("Purchase ");
			setcolor(4); printf("%c ", 186); setcolor(7); printf("Selling "); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			
			//Content
			int sizeGoods = goodsInBag.size();
			for(int i = 0; i < sizeGoods; i++){
				if(atoi(goodsInBag[i].quantity) > 0){
					printf(" %c ", 186); setcolor(7); printf("%-2d ", i + 1); setcolor(4); printf("%c ", 186); setcolor(7);
					printf("%-16s ", goodsInBag[i].name); setcolor(4); printf("%c ", 186); setcolor(7); printf("= %-6s ", goodsInBag[i].quantity); 
					setcolor(4); printf("%c ", 186); setcolor(7); printf("> %-6s ", goodsInBag[i].purchase); setcolor(4); printf("%c ", 186); setcolor(7);
					printf("< %-5s ", goodsInBag[i].selling); setcolor(4); printf("%c\n", 186);
					printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
					printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
				}
			}
			setcolor(7);
			
			//info
			printf(" Note: = (Quantity), > (Purchase Price), < (Selling Price)\n");
			printf(" Press ENTER to return the item to main stock . . .\n");
			printf(" Press ESC to back to Main Menu . . . ");
			
			//Choose
			backKey:
			char key = getch();
			if(key == ENTER){
				int sizeGoods = goodsInBag.size();
				for(int i = 0; i < sizeGoods; i++){
					if(goodsInBag[i].quantity > 0){
						char temp[30];
						int goodss = atoi(goodsInBag[i].quantity);
						strcpy(goodsInBag[i].quantity, "0");
						int now = atoi(goods[i].quantity);
						now += goodss;
						itoa(now, temp, 10);
						strcpy(goods[i].quantity, temp);
					}
				}
				FILE *op = fopen("Goods/MyGoods.txt", "w");
				int sizeGoodsg = goods.size();
				for(int i = 0; i < sizeGoods; i++){
					if(i != 0) fprintf(op, "\n%s %s %s %s", goods[i].quantity, goods[i].purchase, goods[i].selling, goods[i].name);
					else fprintf(op, "%s %s %s %s", goods[i].quantity, goods[i].purchase, goods[i].selling, goods[i].name);
				}
				fclose(op);
				op = fopen("StockinBag/StockinBag.txt", "w");
				int sizeGoodsgib = goodsInBag.size();
				for(int i = 0; i < sizeGoodsgib; i++){
					if(i != 0) fprintf(op, "\n%s %s %s %s", goodsInBag[i].quantity, goodsInBag[i].purchase, goodsInBag[i].selling, goodsInBag[i].name);
					else fprintf(op, "%s %s %s %s", goodsInBag[i].quantity, goodsInBag[i].purchase, goodsInBag[i].selling, goodsInBag[i].name);
				}
				fclose(op);
				printf("\n The items in your bag have been moved . . .\n");
				PAUSE;
				mainPage();
			}else if(key == ESC) mainPage();
			else goto backKey;
		}
		
		void viewStock(){
			CLEAR;
			setFontSize(10, 25);
			viewStockPageWindows();
			moveCenter();
			
			//Title
			setcolor(4); printf("\n\t      %c", 206); cout << string(29, 205); printf("%c\n", 206);
			printf("\t   >> %c", 186); setcolor(7); printf(" V I E W  M A I N  S T O C K "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n\t      %c", 206); cout << string(29, 205); printf("%c\n\n", 206);
			
			//Head Table
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			setcolor(4); printf(" %c ", 186); setcolor(7); printf("ID "); setcolor(4); printf("%c       ", 186); setcolor(7); printf("Name       "); setcolor(4);
			printf("%c ", 186); setcolor(7); printf("Quantity "); setcolor(4); printf("%c ", 186); setcolor(7); printf("Purchase ");
			setcolor(4); printf("%c ", 186); setcolor(7); printf("Selling "); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			
			//Content
			int sizeGoods = goods.size();
			for(int i = 0; i < sizeGoods; i++){
				printf(" %c ", 186); setcolor(7); printf("%-2d ", i + 1); setcolor(4); printf("%c ", 186); setcolor(7);
				printf("%-16s ", goods[i].name); setcolor(4); printf("%c ", 186); setcolor(7); printf("= %-6s ", goods[i].quantity); 
				setcolor(4); printf("%c ", 186); setcolor(7); printf("> %-6s ", goods[i].purchase); setcolor(4); printf("%c ", 186); setcolor(7);
				printf("< %-5s ", goods[i].selling); setcolor(4); printf("%c\n", 186);
				printf(" %c", 206); cout << string(4, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
				printf("%c", 206); cout << string(10, 205); printf("%c", 206); cout << string(9, 205); printf("%c\n", 206);
			}
			setcolor(7);
	
			//Info
			printf(" Note: = (Quantity), > (Purchase Price), < (Selling Price)\n");
			PAUSE;
			mainPage();
		}
		
		void viewHistory(){
			CLEAR;
			setFontSize(10, 25);
			setWindowSize("74", "50");
			moveCenter();
			
			//Title
			setcolor(4); printf("\n\t\t\t     %c", 206); cout << string(15, 205); printf("%c\n", 206);
			printf("\t\t\t  >> %c", 186); setcolor(7); printf(" H I S T O R Y "); setcolor(4); printf("%c <<", 186);
			setcolor(4); printf("\n\t\t\t     %c", 206); cout << string(15, 205); printf("%c\n\n", 206);
			
			//Head Table
			printf(" %c", 206); cout << string(18, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(8, 205); printf("%c", 206); cout << string(12, 205); printf("%c\n", 206);
			setcolor(4); printf(" %c       ", 186); setcolor(7); printf("Name       "); setcolor(4); printf("%c   ", 186); setcolor(7); printf("Product Name   "); setcolor(4);
			printf("%c ", 186); setcolor(7); printf("Quantity "); setcolor(4); printf("%c ", 186); setcolor(7); printf("Method ");
			setcolor(4); printf("%c    ", 186); setcolor(7); printf("Date    "); setcolor(4); printf("%c\n", 186);
			printf(" %c", 206); cout << string(18, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(8, 205); printf("%c", 206); cout << string(12, 205); printf("%c\n", 206);
			
			//Content
			int historySize = history.size();
			for(int i = 0; i < historySize; i++){
				printf(" %c ", 186); setcolor(7); printf("%-16s ", history[i].name); setcolor(4); printf("%c ", 186); setcolor(7);
				printf("%-16s ", history[i].productName); setcolor(4); printf("%c ", 186); setcolor(7); printf("= %-6s ", history[i].quantity); 
				setcolor(4); printf("%c ", 186); setcolor(7); printf("$ %-4s ", history[i].method); setcolor(4); printf("%c ", 186); setcolor(7);
				printf("%-2d/%-2d/%-4d ", history[i].d, history[i].m, history[i].y); setcolor(4); printf("%c\n", 186);
				printf(" %c", 206); cout << string(18, 205); printf("%c", 206); cout << string(18, 205); printf("%c", 206); cout << string(10, 205); 
			printf("%c", 206); cout << string(8, 205); printf("%c", 206); cout << string(12, 205); printf("%c\n", 206);
			}
			
			//Info
			setcolor(7);
			printf("\n"); printCenter(" Note: = (Quantity), $ (Method)", 74); puts("\n");
			PAUSE;
			mainPage();
		}
		
		void exportFile(){
			setWindowSize("40", "10");
			setFontSize(20, 45);
			moveExacCenter();
			time_t now = time(NULL);
			string temp = "Exported Data/";
			struct tm *now_tm = localtime(&now);
			int d = now_tm->tm_wday;
			if (d == 0) temp += "Sunday. ";
			else if (d == 1) temp += "Monday. ";
			else if (d == 2) temp += "Tuesday. ";
			else if (d == 3) temp += "Wednesday. ";
			else if (d == 4) temp += "Thursday. ";
			else if (d == 5) temp += "Friday. ";
			else temp += "Saturday. ";
			char dd[5];
			itoa(now_tm->tm_mday, dd, 10); temp += dd; temp += ".";
			char mm[5];
			itoa(now_tm->tm_mon + 1, mm, 10); temp += mm; temp += ".";
			char yyyy[5];
			itoa(now_tm->tm_year + 1900, yyyy, 10); temp += yyyy; temp += ". ";
			char hour[5];
			itoa(now_tm->tm_hour, hour, 10); temp += hour; temp += ".";
			char minutes[5];
			itoa(now_tm->tm_min, minutes, 10);temp += minutes; temp += ".txt"; 
			
			//write file
			const char *open = temp.c_str();
			printf("\n\n ");
			printCenter("Exporting File      \n\n", 40);
			Sleep(500);
			printCenter("Wait a few seconds", 40);
			for(int i = 0; i < 3; i++){
				changeCursorPosition(25, 2);
				Sleep(300); printf(". ");
				Sleep(300); printf(". ");
				Sleep(300); printf(".");
				if(i != 2) {
					changeCursorPosition(25, 2);			
					printf("     ");
				}
			}
			printf("\n\n\n\n");
			FILE *op = fopen(open, "w");
			fprintf(op, "+------------------+------------------+----------+--------+------------+\n");
			fprintf(op, "|       Name       |   Product Name   | Quantity | Method |    Date    |\n");
			fprintf(op, "+------------------+------------------+----------+--------+------------+");
			scanHistory();
			int sizeHistory = history.size();
			for(int i = 0; i < sizeHistory; i++){
				if(i != 0) fprintf(op, "\n| %-16s | %-16s | %-8d |  %s  | %-2d/%-2d/%-4d |", history[i].name, history[i].productName, history[i].quantity, history[i].method, history[i].d, history[i].m, history[i].y);
				else fprintf(op, "\n| %-16s | %-16s | %-8d |  %s  | %-2d/%-2d/%-4d |", history[i].name, history[i].productName, history[i].quantity, history[i].method, history[i].d, history[i].m, history[i].y);
			}
			fprintf(op, "\n+------------------+------------------+----------+--------+------------+");
			fclose(op);
			printCenter("The data has been successfully exported", 40);
			PAUSE;
			mainPage();
		}
};

int main(){	
	scanGoods();
	scanGoodsInBag();
	setFontSize(28, 64, 600);
	SetConsoleTitle("My Business");
	Main *m = new Main();
	return 0;
}
