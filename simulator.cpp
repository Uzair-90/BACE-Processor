#include<iostream>
using namespace std;

struct node{
	string ins;
	int address;
	int i;
	node *next;
	int p;
};

int ram[64] , ac = 0 , e = 0 , dr = 0, tr = 0;
string aC, dR, tR, ones;
node *pc;

char flip(char c) 
{
	return (c == '0')? '1': '0';	
}

// function to convert decimal to binary 
string DecimalToBinary(unsigned int dec)
{
    char binary[19] = {0}; 
    int i = 0;
    int ix = 20; // subscript of current character
    do 
    {
        binary[--ix] = '0' + dec % 2;
        dec /= 2;
        i++;
    } while (i<20);
    
    return  (binary+ix);    // ix is offset into char array where answer begins
}

int BinaryToDecimal(string binary) 
{
    int power = 1048576;
    int sum = 0;
//    assert(strlen(binary) == 20);

    for ( int i=0; i<20; ++i) {
        if ( i==0 && binary[i]!='0') {
            sum = -1048576;
        }
        else {
            sum += (binary[i]-'0')*power;
        }
        power /= 2;
    }
    return sum;
}



void insert(node *head)
{
	node *ptr; 	    
	for (ptr = head; ptr->next != NULL; ptr = ptr->next){}
	
	ptr->next = new node;
	ptr = ptr->next;
	cout<<"\n\n\tEnter Instruction: ";
	cin>>ptr->ins;
	
	if( ptr->ins == "AND" || ptr->ins == "ADD" || ptr->ins == "LDA" || ptr->ins == "STA" || ptr->ins == "BUN" || ptr->ins == "BSA" || ptr->ins == "ISZ" || ptr->ins == "NOR" || ptr->ins == "NAND" || ptr->ins == "SWP" || ptr->ins == "MUL" || ptr->ins == "SUB" || ptr->ins == "GTB" || ptr->ins == "BTG")
	{
		cout<<"\tEnter Address: ";
		cin>>ptr->address;
		cout<<"\tI: ";
		cin>>ptr->i;
	}

	ptr->next = NULL;
}

void displayMemory()
{
	cout<<endl<<"_________________________________________________________ MEMORY _______________________________________________________\n\n";
	for(int i = 0 ; i < 64 ; i++)
	{
		if(ram[i] != -9999)
			cout<<ram[i]<<"\t";
			
		else
			cout<<"_\t";
		
	}
	cout<<endl<<endl<<"________________________________________________________________________________________________________________________\n\n";
}

void displayRegisters()
{
	aC = DecimalToBinary(ac);
	dR = DecimalToBinary(dr);
	tR = DecimalToBinary(tr);
	
	cout<<"\n_________________________________________________________ Registers ____________________________________________________\n\n";
	cout<<"   | AC = "<<ac<<" , "<<aC<<" |	| DR = "<<dr<<" , "<<dR<<" |	| TR = "<<tr<<" , "<<tR<<" |";
	cout<<endl<<endl<<"________________________________________________________________________________________________________________________\n\n";
}

void execute(node *head)
{
	if (pc->ins == "AND")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			dr = pc->address;
		}
		else if (ram[pc->address] == -9999)
		{
			cout << "Address you entered is empty\nEnter operand in the memory: ";
			cin >> ram[pc->address];
		}
		
		
		if (pc->i == 00)
		{
			dr = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			dr = ram[ram[pc->address]];
		}
		
		
		aC = DecimalToBinary(ac);
		dR = DecimalToBinary(dr);
		
		for(int i = 0 ; i < 20 ; i++)
		{
			if(aC[i] == '1' && dR[i] == '1')
				aC[i] = '1';
			else
				aC[i] = '0';
		}
		
		ac = BinaryToDecimal(aC)/2;
	}
	
	else if (pc->ins== "ADD") 
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			dr = pc->address;
		}
		
		else if (ram[pc->address] == -9999)
		{
			cout << "Address you entered is empty\nEnter operand in the memory: ";
			cin >> ram[pc->address];
		}
		
		
		if (pc->i == 00)
		{
			dr = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			dr = ram[ram[pc->address]];
		}
		

		ac = ac + dr;
	}
	
	else if (pc->ins == "LDA")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			ac = pc->address;
		}
		
		else if (ram[pc->address] == -9999) 
		{
			cout << "Address you entered is empty\nEnter operand: ";
			cin >> ram[pc->address];
		}
		
		if (pc->i == 00)
		{
			ac = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			ac = ram[ram[pc->address]];
		}
		
	}

	else if (pc->ins == "STA") 
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		
		if (pc->i == 00)
		{
			ram[pc->address] = ac;	
		}
		else if(pc->i == 01)
		{
			ram[ram[pc->address]] = ac;
		}
		
	}

	else if (pc->ins == "BUN")
	{
//		cout<<"\nBUN...\n";
//		if (pc->i == 00)
//		{
//			ram[pc->address] = ac;	
//		}
//		else if(pc->i == 01)
//		{
//			ram[ram[pc->address]] = ac;
//		}
	}

	else if (pc->ins == "BSA")
	{
		//pc = ar;
	}
	
	else if (pc->ins == "ISZ")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			dr = pc->address;
		}
		
		else if (ram[pc->address] == -9999)
		{
			cout << "Address you entered is empty\nEnter operand in the memory: ";
			cin >> ram[pc->address];
		}
		
		if (pc->i == 00)
		{
			dr = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			dr = ram[ram[pc->address]];
		}
		
		if(dr == 0)
		{
			cout<<"\nSkipped because DR is zero";
		}
		else
		{
			dr++;
		}
			
		
	}
	
	else if (pc->ins == "NOR")
	{
		//pc = ar;
	}
	
	else if (pc->ins == "NAND")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			dr = pc->address;
		}
		
		else if (ram[pc->address] == -9999)
		{
			cout << "Address you entered is empty\nEnter operand in the memory: ";
			cin >> ram[pc->address];
		}
		
		
		if (pc->i == 00)
		{
			dr = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			dr = ram[ram[pc->address]];
		}
		
		aC = DecimalToBinary(ac);
		dR = DecimalToBinary(dr);
		
		for(int i = 0 ; i < 20 ; i++)
		{
			if(aC[i] == '1' && dR[i] == '1')
				aC[i] = '1';
			else
				aC[i] = '0';
		}
		
		ac = BinaryToDecimal(aC)/2;
		aC = DecimalToBinary(ac);
		
		for (int i = 0; i < 20; i++) 
			ones += flip(aC[i]);
		
		aC = ones;
		ac = BinaryToDecimal(aC)/2;
	}
	
	else if (pc->ins == "SWP")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if (pc->i == 00)
		{
			tr = ac;
			ac = ram[pc->address];
			ram[pc->address] = tr;
		}
		else if(pc->i == 01)
		{
			tr = ac;
			ac = ram[ram[pc->address]];
			ram[ram[pc->address]] = tr;
		}
		
	}
	
	else if (pc->ins == "MUL")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			dr = pc->address;
		}
		
		else if (ram[pc->address] == -9999)
		{
			cout << "Address you entered is empty\nEnter operand in the memory: ";
			cin >> ram[pc->address];
		}
		
		if (pc->i == 00)
		{
			dr = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			dr = ram[ram[pc->address]];
		}
		ac = ac * dr;
	}
	
	else if (pc->ins == "SUB")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		if(pc->i == 10)
		{
			dr = pc->address;
		}
		
		else if (ram[pc->address] == -9999)
		{
			cout << "Address you entered is empty\nEnter operand in the memory: ";
			cin >> ram[pc->address];
		}
		
		if (pc->i == 00)
		{
			dr = ram[pc->address];	
		}
		else if(pc->i == 01)
		{
			dr = ram[ram[pc->address]];
		}

		ac = ac - dr;
	}
	
	else if (pc->ins == "GTB")
	{
		//pc = ar;
	}
	
	else if (pc->ins == "BTG")
	{
		//pc = ar;
	}

	//Register Reference Instructions
	
	else if (pc->ins == "CLA")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		ac = 0;
	}
	
	else if (pc->ins == "CLE")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		e = 0;
	}
	
	else if (pc->ins == "CMA")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		aC = DecimalToBinary(ac);
		
		for (int i = 0 ; i < 20 ; i++)
			ones += flip(aC[i]);
			
		aC = ones;
		ac = BinaryToDecimal(aC)/2;
	}
	
	else if (pc->ins == "CME")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		
		e = flip(e);
	}
	
	else if (pc->ins == "CIR")
	{
		//pc = ar;
	}
	
	else if (pc->ins == "CIL")
	{
		//pc = ar;
	}
	  
	else if(pc->ins == "INC")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		ac++;
	}
	                          
	 else if (pc->ins == "DEC")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		ac--;
	}
	
	else if (pc->ins == "SPA")
	{
		if(ac > 0)
		{
			if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}            
			pc = pc->next;
		}
	}
	
	else if (pc->ins == "SNA")
	{
		if(ac < 0)
		{
			if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
			pc = pc->next;
		}
	}
	
	else if (pc->ins == "SZA")
	{
		if(ac == 0)
		{
			if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
			pc = pc->next;
		}
	}
	
	else if (pc->ins == "SZE")
	{
		if(e == 0) 
		{
			if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
			pc = pc->next;
		}
	}
	
	else if (pc->ins == "IND")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		dr++;
	}
	
	else if (pc->ins == "HLT")
	{
		if( pc->ins == "AND" || pc->ins == "ADD" || pc->ins == "LDA" || pc->ins == "STA" || pc->ins == "BUN" || pc->ins == "BSA" || pc->ins == "ISZ" || pc->ins == "NOR" || pc->ins == "NAND" || pc->ins == "SWP" || pc->ins == "MUL" || pc->ins == "SUB" || pc->ins == "GTB" || pc->ins == "BTG")
		{
			cout<<"\t"<<pc->i<<" "<<pc->ins<<" "<<pc->address<<endl;
		}
		
		else
		{
			cout<<"\t  "<<pc->ins<<endl;
		}
		pc->next = NULL;
	}
	
	displayRegisters();
	displayMemory();
}

void run(node *head)
{
	for (; pc != NULL; pc = pc->next)
	{
		system("cls");
		execute(head);
		cout<<endl<<"	";
		system("pause");
	}
	
}

void display(node *head)
{
	node *ptr = head->next;
	cout<<endl<<endl<<"_________________________________________________________ INSTRUCTIONS _________________________________________________\n\n\n";
	if(head->next == NULL)
	{
		cout<<"You haven't written any instruction!!!";
	}
	else
	{
		for (; ptr != NULL; ptr = ptr->next)
		{
			if( ptr->ins == "AND" || ptr->ins == "ADD" || ptr->ins == "LDA" || ptr->ins == "STA" || ptr->ins == "BUN" || ptr->ins == "BSA" || ptr->ins == "ISZ" || ptr->ins == "NOR" || ptr->ins == "NAND" || ptr->ins == "SWP" || ptr->ins == "MUL" || ptr->ins == "SUB" || ptr->ins == "GTB" || ptr->ins == "BTG")
			{
				cout<<"\t"<<ptr->i<<" "<<ptr->ins<<" "<<ptr->address<<endl;
			}
			else
			{
				cout<<"\t  "<<ptr->ins<<endl;
			}
		}
	}

	cout<<"________________________________________________________________________________________________________________________\n";	
	cout<<endl;
}





int main() 
{
	node *head = new node;
	head->next = NULL;
	
	char opt = 'y';
	int choice = 0;
	
	for(int i = 0 ; i < 64 ; i++ )
	{
		ram[i] = -9999;	
	}
	
	ram[0] = 6;
	ram[1] = 5;
	ram[2] = -15;
	ram[3] = 19;
	ram[4] = -10;
	ram[5] = 2;
	ram[6] = 111;
	ram[7] = -26;
	ram[8] = 5;
	ram[9] = 63;
	
	while(choice != 5)
	{
		displayMemory();
		displayRegisters();
		system("color f0");
		cout<<"_________________________________________________________ MENU _________________________________________________________\n"
		<<"\n	1. Write Program"
		<<"\n	2. Display Written Instructions"
		<<"\n	3. Run Program"
		<<"\n	4. Display Memory"
		<<"\n	5. Exit"
		<<"\n________________________________________________________________________________________________________________________"
		<<"\n\n	SELECT OPERATION: ";
		
		cin>>choice;
		
		if(choice == 1)
		{
			opt = 'y';
			while(opt != 'n')
			{
				insert(head);
				cout<<"\n\tDo you want to write more instructions(y/n)? ";
				cin>>opt;
			}
			system("cls");
		}
		
		else if(choice == 2)
		{
			system("cls");
			display(head);
			cout<<endl<<"	";
			system("pause");
		}
		
		else if(choice == 3)
		{
			pc = head;
			run(head);
			head->next = NULL;
			system("cls");
		}
		
		else if(choice == 4)
		{
			displayMemory();
			
		}
		
		else
		{
			choice == 5;
		}
		
	}
	return 0;
}
