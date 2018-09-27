#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

const int MAXLENGTH=80;
const int MAX_TRIES=5;
const int MAXROW=7;

int letterFill (char, char[], char[]);
void initUnknown (char[], char[]);

int main(){
  char unknown [MAXLENGTH];
  char letter;
  int num_of_wrong_guesses=0;
  char word[MAXLENGTH];
  char words[][MAXLENGTH] =
  {
          "bitcoin",
          "cardano",
          "dgb",
          "doge",
          "ether",
          "litecoin",
          "monero",
          "nem",
          "tron",
          "xlm"
  };

  // choose and copy  word from array of words randomly
  randomize();
  int n=random(10);
  strcpy(word,words[n]);

  // init the secret word with the * character
  initUnknown(word, unknown);

  // welcome the user
  cout << "\n\n Welcome to BitHangMan... GUess a cryptocurrency/cryptotoken";
  cout << "\n\n Each letter is represented by a star.";
  cout << "\n\n You have to type only one letter in one try";
  cout << "\n\n You have " << MAX_TRIES << " tries to try and guess the word.";
  cout << "\n ########################################";

  // loop until the guesses are used up
  while(num_of_wrong_guesses < MAX_TRIES)
  {
        cout << "\n\n" << unknown;
        cout << "\n\n Guess a letter";
        cin >> letter;

        if(letterFill(letter, word, unknown)==0)
        {
          cout << endl << "Whoops! That letter isn't in there!"<<endl;
          num_of_wrong_guesses++;
        }
        else
        {
          cout << endl << "You found a letter! Isn't that exciting?" << endl;
        }
        //Tell user how many guesses has left;
        cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
        cout << " guesses left." << endl;
        // Check if they guessed the word;
        if(strcmp(word, unknown)==0)
        {
          cout << word << endl;
          cout << "Yeah! You got it!";
          break;
        }
  }
  if(num_of_wrong_guesses == MAX_TRIES)
  {
        cout << "\nSorry, you lose... you've been hanged." <<endl;
        cout << "The word was : " <<word << endl;
  }
  getch();
  return 0;
}
