#include<iostream>
#include<string>

using namespace std;

int in_num,flag = 0,win =0,winner=-1,count=0,entered[10] = {0};
char a[3][3],num = 57;      // ascii value of 9 is 57.
char user1_marker,user2_marker;
string user1,user2;

// Initialization.
void Initialize()
{
	for (int i=0; i<3; i++)
	{
		for (int j =2; j>=0; j--)
		{
			a[i][j] = num;            // initializing the matrix with values from 9-1 same as numpad provided in systems.
			num--;
		}
	}
}

void print_board()   // printing the game board.
{
	cout << a[0][0] << " | " << a[0][1] << " | " << a[0][2] << endl;
	cout << "--+---+--" << endl;
	cout << a[1][0] << " | " << a[1][1] << " | " << a[1][2] << endl;
	cout << "--+---+--" << endl;
	cout << a[2][0] << " | " << a[2][1] << " | " << a[2][2] << endl;
	cout << endl;
}

void marker()         // function takes names as input and gives the option to user1 to choose 'x' or 'o' and prints respective marks of users.
{
    cout << "Enter name of user 1: ";
    getline(cin,user1);
    
    cout << "Enter name of user 2: ";
    getline(cin,user2);
		
	cout<< user1 <<" please choose the mark 'X' or 'O' : ";
	cin >> user1_marker;
	
	if(user1_marker == 'X' || user1_marker == 'x')
	{
		user2_marker = 'O';
	}
	else{
	user2_marker = 'X';
    }
    
    cout<< user1 <<"'s mark is :" << user1_marker << endl;
    cout << user2 <<"'s mark is :" << user2_marker << endl << endl;	
}

void main_logic()    // implements the main logic.
{
	if (count!=9)
	{
		
	for (int i=0; i<3; i++)          // for checking if any row forms a winning situation.
	{
		int j=0;
		if(a[i][j]==user1_marker && a[i][j+1]==user1_marker && a[i][j+2]==user1_marker)
		{
			win = 1;
			winner = 1;
			break;
		}
		else if(a[i][j]==user2_marker && a[i][j+1]==user2_marker && a[i][j+2]==user2_marker)
		{
			win = 1;
			winner = 2;
			break;
		}
	}
	
	for (int j=0; j<3; j++)     // for checking if any column forms a winning situation.
	{
		int i=0;
		if(a[i][j]==user1_marker && a[i+1][j]==user1_marker && a[i+2][j]==user1_marker)
		{
			win = 1;
			winner = 1;
			break;
		}
		else if(a[i][j]==user2_marker && a[i+1][j]==user2_marker && a[i+2][j]==user2_marker)
		{
			win = 1;
			winner = 2;
			break;
		}
	}
	
	// for forward diagonal.
	if (a[0][0]==user1_marker && a[1][1]==user1_marker && a[2][2]==user1_marker)   // checks for user 1.
	{
		win = 1;
		winner =1;
	}
	else if(a[0][0]==user2_marker && a[1][1]==user2_marker && a[2][2]==user2_marker) // checks for user 2.
	{
		win = 1;
		winner = 2;
	}
	// for backward diagonal.
	else if (a[0][2]==user1_marker && a[1][1]==user1_marker && a[2][0]==user1_marker)
	{
		win = 1;
		winner =1;
	}
	else if(a[0][2]==user2_marker && a[1][1]==user2_marker && a[2][0]==user2_marker)
	{
		win = 1;
		winner = 2;
	}
	
    }// terminating if for count.
    else
    {
	   win = 1;
    }	
}

void input_position()             //takes the input position for the game.
{
	while(!win)
	{
		if(flag == 0)
		{
			cout<< user1 <<" turn: ";
			cin >> in_num;                    
			if(entered[in_num]!= in_num)    // once position is entered we fill that position as entered position in entered array
			{                               // so that next time this position should not be used.
		    	entered[in_num] = in_num;
		    	cout << endl;
			    count++;
			    flag = 1;
			    for (int i=0; i<3; i++)
	            {
		           for (int j =0; j<3; j++)
		           {
		       	     if(a[i][j] == (in_num+48) )
		       	        {
		       	        	a[i][j] = user1_marker;
		       	        	print_board();
		       	        	main_logic();
		       	         	break;
				      	}
		           }
		        }
		    }
			else
			{
				cout << "This position is already filled." << endl;
			}      	
		}
		else if(flag == 1)
		{
			cout<< user2 <<" turn: ";
			cin >> in_num;
			if (entered[in_num]!= in_num)       // once position is entered we fill that position as entered position in entered array
			{                                  // so that next time this position should not be used.
		        entered[in_num]= in_num;
		    	cout << endl;
		    	count++;
	     		flag = 0;
	    		for (int i=0; i<3; i++)
	            {
	       	       for (int j =0; j<3; j++)
	      	       {
		        	 if(a[i][j] == (in_num+48) )
		         	    {
		        	    	a[i][j] = user2_marker;
		        	    	print_board();
		        	    	main_logic();
		        	    	break;
		    			}
		           }
		        }
			} // ending if statement.
			else
			{
				cout << "This position is already filled." << endl;
			}       	
		}     // end  if(flag=1)
	}  // end while
}

int main()
{
	marker();
	Initialize();
	print_board();
	input_position();
	if (count == 9)
	{
		cout << "Game draw!!";
	}
	else 
	if (winner == 1)
	{
		cout << user1 <<" won";
	}
	else if( winner == 2)
	{
		cout << user2 <<" won";
	}	
	return 0;
}
