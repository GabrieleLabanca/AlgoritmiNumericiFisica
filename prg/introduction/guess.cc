/* guess.cc
 * the program asks to guess a number in 0:100
 * each trial bisects the interval so that it is easier to guess
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
  int seed = time(NULL);
  srand(seed);
  int mistery = rand() % 100;
  int inf_lim = 0;
  int sup_lim = 100;
  int guess;
  int n_trials = 0;
  while( guess != mistery ){
    n_trials++;
    if(guess < inf_lim or guess > sup_lim)
      cout << "Numero fuori dall'intervallo!\n";
    else if(mistery > guess){
      cout << "Il numero e' nell'intervallo ["
	   << guess   << ";" << sup_lim << "]\n";
      inf_lim = guess;
    }
    else if(mistery < guess){
      cout << "Il numero e' nell'intervallo ["
	   << inf_lim << ";" << guess   << "]\n";
      sup_lim = guess;
    }
    cin >> guess;
  }
  cout << "BINGO! in " << n_trials << "trials\n"; 





  return 0;
}
