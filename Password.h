#if !defined PASSWORD_H
#define PASSWORD_H
#include "ListArray.h"
#include "Text.h"
using namespace CSC2110;
/**
	*Stores two lists of passwords in list arrays, and provides methods for guessing passwords and providing a best guess.
	*Provides methods for guessing a word, by passing an index, getting a best guess from all words, and various functions regarding size and length
	*Very little is hidden from the user, aside from the actual data, which is done to prevent direct data manipulation.
	*/

class Password
{
   private:
      ListArray<String>* viable_words;  //the list of words that can still be the password
      ListArray<String>* all_words;  //the original list of words
      int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

      //a private helper method to report the number of character matches between two Strings
      int getNumMatches(String* curr_word, String* word_guess);

   public:
		Password();//! Creates a Password. Nothing is passed, as all data in the Password is added manually.
		~Password();//! Deletes individual data within password, and destroys everything within
		void addWord(String* word); //! Adds a single word to the Password, requires an abstract String pointer.
		void guess(int try_password, int num_matches);//! Used to guess at the password. Will remove all strings with less or equal matches from the viable words. Requires the index of the password guessed, and how many matches there were.
		int getNumberOfPasswordsLeft();//! Returns the number of viable passwords.
		void displayViableWords(); //! Prints the viable passwords to the screen.
		int bestGuess();//! Chooses the word which will eliminate the most viable words that are wrong, chosen from all words.
		String* getOriginalWord(int index);//! Gets a word from the list of all words.

};

#endif
