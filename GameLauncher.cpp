#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
class NumberGame{
    private:
    void greet(){
    cout<<"welcome"<<endl<<"let's play number guessing game"<<endl<<"lets start"<<endl;
    
}
int mode(){
    int x;
    cout<<"select difficulty level"<<"1 for easy 2 for medium 3 for hard"<<endl;
    cin>>x;
   if(x==1){
    return 7;
   }
   else if(x==2){
    return 5; 
   }
   else if(x==3){
    return 3;
   }
   else{
    cout<<"invalid difficulty level";
    cin.clear();
    cin.ignore(100000,'\n');
    
   }
   return 0;


}

int guess(int x,int i,int level){
     int guess_no;
     cout<<"guess the number 1 to 100: ";
     cin>>guess_no;

         if(guess_no==x)
         {
             cout<<"winner:correct guess"<<endl;
             return 1;
            
         }
         else if(guess_no>x)
         {
             cout<<"guess number is large"<<endl;
             cout<<"remaining "<<level-i<<" chances"<<endl;
         }
         else
         {
             cout<<"guess number is small"<<endl;
             cout<<"remaining "<<level-i<<" chances"<<endl;
         }
         return 0;
}
int check(){
    
     return rand()%100+1; 
 }
 int wanna_play(){
    int choice;
    cout<<"PLAY AGAIN"<<endl<<"0 for play and 1 for exit"<<endl;
    cin>>choice;
    return choice;

 }

    public:
    void play(){
    

    int play=0;
    while(play==0){
    
    int flag=0,level;
    greet();
    
    
    
    do{
      level=mode();
      }while(level==0);
    
    
    
    
    
    int c=check();
    while(c<1||c>100){
        cout<<"secret number is not between 1 and 100"<<endl;
        c=check();
    }
    for(int i=1;i<=level;i++){
        flag=guess(c,i,level);
        if(flag==1){
            break;
        }

    }
    if(flag!=1){
        cout<<"game over"<<endl;
        cout<<"Secret number is "<<c<<endl;
    }

    play=wanna_play();
    
    while(play!=0 && play!=1){
        cout<<"invalid choice"<<endl;

        play=wanna_play();
        
        


    }
    if(play==1){
        cout<<"THANKYOU"<<endl;
        ;

    }
}
    
    
        
    
    }
};

class HangMan{
    private:
    void greet(){
        cout<<"lets play HangMan game"<<endl;
    }
      void secret(string &secret_word)
      {
        struct Word{
        string word;
        string category;
        };

        Word words[]{
          {"mango","fruit"},
          {"apple","fruit"},
          {"potato","vegetable"},
          {"onion","vegetable"},
          {"chess","indoor game"},
          {"ludo","indoor game"},
          {"cat","animal"},
          {"dog","animal"}
        };

      int i=rand()%(sizeof(words)/sizeof(words[0]));
      secret_word=words[i].word;
      cout<<"Category: "<<words[i].category<<endl;
      cout<<"secret word consists of "<<secret_word.length()<<" letters"<<endl;
    
    }
    void disp_men(int lose_count){
      cout<<"___"<<endl;
      cout<<"|   |"<<endl;
    

      string man[]{
          "|   O    ",
          "|   |    ",
          "|  /|\\  ",
          "| / | \\ ",
          "|   |    ",
          "|  / \\ \n| /   \\ "
      };
      for(int i=0;i<=lose_count;i++){
        cout<<man[i]<<endl;;
      }
    }
    void check(const string &secret_word,char letter,string &s,int &win_count,int &lose_count){
       int i,flag=0;
    
       for(i=0;i<secret_word.length();i++){
         if(secret_word[i]==letter){
            s[i]=letter;
            flag=1;
            }
        }
      win_count=0;
      for( i=0;i<secret_word.length();i++){
        if(s[i]!='_'){
            win_count++;
        }
      }
     cout<<s<<endl;
     if(flag==0){
        cout<<"OOPS! WRONG LETTER"<<endl;
       
        disp_men(lose_count);
        lose_count++;
        
      }

    
    }
    void user(const string &secret_word,string &s,int &win_count,int &lose_count,string &guessed_letters){
    char letter;
    
    cout<<"Guess the letter"<<endl;
    cin>>letter;
    letter=tolower(letter);
    
    while(!isalpha(letter)){
        
        cout<<"INVALID LETTER"<<endl<<"type again"<<endl;
        cin>>letter;
        letter=tolower(letter);
        
    }
    for(int i=0;i<guessed_letters.length();i++){
        if(guessed_letters[i]==letter){
            cout<<"ALREADY GUESSED"<<endl;
            return;
        }
        
    }
    guessed_letters=guessed_letters+letter;
    
    check(secret_word,letter,s,win_count,lose_count);
    }    

    public:
    void play(){
    greet();  
    int play=0;
    while(play==0){
        int win_count=0,lose_count=0;
    string secret_word,guessed_letters="";
    secret(secret_word); 
    string s(secret_word.length(),'_');
    while(win_count<secret_word.length()&& lose_count<6){
        user(secret_word,s,win_count,lose_count,guessed_letters);      
    };
    
    if(win_count==secret_word.length()){
        cout<<"YOU WON"<<endl;
    }
    else if(lose_count>=6){
        cout<<"YOU LOSE"<<endl;
    }
    
    cout<<"PLAY AGAIN 1 for exit 0 to play again"<<endl;
    cin>>play;
     while(play!=0&&play!=1){
        cout<<"INVALID choice enter again"<<endl;
        cin>>play;

     }
    }
    
    }   
    

    
    
};
class TicTacToe{
    private:
    void greet(){
        cout<<"play tictactoe"<<endl;
    }

void system_choice(vector<vector<char>> &board,bool &c){
    int i=rand()%3;
    int j=rand()%3;
    while(board[i][j]=='x' || board[i][j]=='o'){
        i=rand()%3;
        j=rand()%3;
    }
        board[i][j]='x';
         c=check_win(board);
         cout<<"BOARD:"<<endl;
        for(int i=0;i<3;i++){
          for(int j=0;j<3;j++)
          {
            cout<<board[i][j]<<" ";      
          }
          cout<<endl;
        } 

}
void user(vector<vector<char>> &board,bool &c){
    int index,i,j;
    cout<<"enter index number from (1 to 9) you want to place o"<<endl;
    cin>>index;
    while(cin.fail()){
        cin.clear();
        cin.ignore(100000,'\n');
        cout<<"INVALID index"<<endl<<"enter again"<<endl;
        cin>>index;
    }

    while(index<1 || index>9){
        cout<<"invalid index"<<endl<<"enter index again from 1 to 9"<<endl;
        cin>>index;
    }
    switch(index){
        case 1: i=0,j=0;
        break;
        case 2: i=0,j=1;
        break;
        case 3: i=0,j=2;
        break;
        case 4: i=1,j=0;
        break;
        case 5: i=1,j=1;
        break;
        case 6: i=1,j=2;
        break;
        case 7: i=2,j=0;
        break;
        case 8: i=2,j=1;
        break;
        case 9: i=2,j=2;
        break;

    }
    if(board[i][j]!='x' && board[i][j]!='o'){
        board[i][j]='o';
        c=check_win(board); 
        cout<<"BOARD:"<<endl;
        
         for(int i=0;i<3;i++){
          for(int j=0;j<3;j++)
          {
            cout<<board[i][j]<<" ";      
          }
          cout<<endl;
        }     
    }
    else
    {
        cout<<"index already filled"<<endl;
        return user(board,c);
    } 
    
    

}
bool check_win(vector<vector<char>> &board){
    if(check(board[0][0],board[1][1],board[2][2])) return true; 
    if(check(board[0][2],board[1][1],board[2][0])) return true;  
    if(check(board[0][0],board[0][1],board[0][2])) return true;  
    if(check(board[1][0],board[1][1],board[1][2])) return true;  
    if(check(board[2][0],board[2][1],board[2][2])) return true;  
    if(check(board[0][0],board[1][0],board[2][0])) return true;  
    if(check(board[0][1],board[1][1],board[2][1])) return true;  
    if(check(board[0][2],board[1][2],board[2][2])) return true;   
    return false;        
}
bool check(char a,char b,char c){
    if(a==b&&a==c){
        if(a=='x'){
            cout<<"Computer win! you lose"<<endl;
            return true;
        }
        if(a=='o'){
            cout<<"win"<<endl;
            return true;
        }
    }
    return false;
    

}

public:
 void play(){
    greet();
    int play=0;

   while(play==0){
    int moves=0;
     bool c=false;

    vector<vector<char>> board(3,vector<char>(3,'.'));
    
       
            while(moves<9){
                system_choice(board,c);
                moves++;
             
                 if(c==true || moves>=9){
                   break;
                 }
 
                user(board,c);
                moves++;
                if(c==true || moves>=9){
                   break;
                 }
                
            }
            if(c==false){
                cout<<"draw"<<endl;
            }
            
          
  
       cout<<"press enter key to continue....."<<endl;
       cin.ignore();
       cin.get();
       
       
       cout<<"enter 0 to play again and 1 for exit"<<endl;
       cin>>play;
   }

   cout<<"THANKYOU FOR PLAYING"<<endl;
    
    
   
    

 }
};
class StoneGame{
    private:
    int start(){
   
    int index=rand()%3;
    return index;
}
void greet(){
    cout<<"stone,paper & scissor game"<<endl<<"let's start"<<endl;
}
string user(){
    string user_choice;
    int z=0;
    while(z==0){
        cout<<"enter your choice"<<endl;
        cin>>user_choice;
        for(int i=0;i<user_choice.length();i++){
        user_choice[i]=tolower(user_choice[i]);
        } 
        if(user_choice!="stone"&&user_choice!="paper"&&user_choice!="scissor"){
        cout<<"invalid choice"<<endl;
        }
        else{
            z=1;
        }
    }
       
    return user_choice;

}
void check(string choosen,string user_input){
    if(user_input=="stone"){
        if(choosen=="stone"){
            cout<<"tie"<<endl;
        }
        else if(choosen=="paper"){
            cout<<"loser"<<endl;
        }
        else
        cout<<"winner"<<endl;
    }
    else if(user_input=="paper"){
         if(choosen=="stone"){
             cout<<"winner"<<endl;
         }
         else if(choosen=="paper"){
             cout<<"tie"<<endl;
         }
         else
         cout<<"loser"<<endl;
    }
    else{
        if(choosen=="stone"){
             cout<<"loser"<<endl;
         }
         else if(choosen=="paper"){
             cout<<"winner"<<endl;
         }
         else
         cout<<"tie"<<endl;

    }


}
int wanna_play(){
    int playc;
    cout<<"play again"<<endl<<"0 to play again and 1 for exit"<<endl;
    cin>>playc;

    if(cin.fail()){
        cin.clear();
        cin.ignore(100000,'\n');
        cout<<"enter 0 and 1 only"<<endl;
        return wanna_play();
    }
    return playc;

}
public:
  void play(){
   string choice[3]={"stone","paper","scissor"};
    
     greet();
     int play=0;
     string choosen;
     while(play==0){
         choosen=choice[start()];
    
    string user_input=user();
    check(choosen,user_input);
    cout<<"system chooses "<<choosen<<endl;
    play=wanna_play();

    while(play!=0 && play!=1){
        cout<<"invalid"<<endl;
        play=wanna_play();
    }
    
    
    }
    
    cout<<"THANKYOU"<<endl;


  }
};


int main(){
    srand(time(0));
    cout<<endl;
    cout<<"============================================================================================================="<<endl;
    cout<<"                                   G A M E  L A U N C H E R                                                  "<<endl;
    cout<<"============================================================================================================="<<endl;
    cout<<endl;
    StoneGame g1;
    HangMan g2;
    TicTacToe g3;
    NumberGame g4;
    int choice;
    
    do{
        cout<<"enter 1 to play Stone,Paper,Scissor"<<endl<<"enter 2 to play HangMan"<<endl<<"enter 3 to play Tic tac toe"<<endl<<"enter 4 to Number guessing game"<<endl<<"enter 0 to exit game"<<endl;
        cout<<"enter which game you want to play"<<endl;
        cin>>choice;
        switch(choice){
        case 0: cout<<"game over"<<endl;break;
        case 1: g1.play();break;
        case 2: g2.play();break;
        case 3: g3.play();break;
        case 4: g4.play();break;
        default:
        cout<<"INVALID choice enter again"<<endl;
        

      }
    }while(choice!=0);

    cout<<"================================================================================================================"<<endl;
    cout<<"                                      G A M E    E N D                                                          "<<endl;
    cout<<"================================================================================================================"<<endl;                    
   
    return 0;
}