#include <iostream>
#include <iomanip>

using namespace std;


class animal
{
public:
  animal(int P, float R, /*float M,*/ float S) : population(P),reproduction(R),/*mortality(M),*/strength(S) {};
  int get_pop() {return population;}
  float get_repr() {return reproduction;}
  //float get_mort() {return mortality;}
  float get_str() {return strength;}
  //private:
  int population;
  float reproduction;
  //float mortality;
  float strength;
};



class prey: public animal
{
public:
  prey (int P, float R, /*float M,*/ float S) : animal(P,R,/*M,*/S) {};
  void season(animal* a)
  {
    /*population += 0.05 * population;
    population -= 0.01 * a->get_pop();
    */
    population *= (1 + this->reproduction /*- this->mortality*/);
    population -= a->get_pop()*0.2  / (this->strength / a->get_str() );
    
    if(population < 0) population = 0;
    return;
  }
};

class predator: public animal
{
public:
  predator (int P, float R, /*float M,*/ float S) : animal(P,R,/*M,*/S){};
  void season(animal * a)
  {
    /*population += 0.04 * population + 0.3 * a->get_pop();
    population -= 0.05 * population;
    */
    population *= (1 + this->reproduction/* - this->mortality*/);
    population += a->get_pop()*0.1 * (this->strength / a->get_str());
    
    if(population < 0) population = 0;
    return;
  }
};


int main()
{
  // population(P),reproduction(R),strength(S)
  //              P     R       S  
  predator cats ( 10,  -0.1,   0.1  );
  prey mice     (1000,  0.068,   0.12);

  cerr << setw(10) << left << "mice" << "cats" << endl; 
  for(int i=0; i<500; i++){
    cout << setw(10) << left <<  i << mice.get_pop() << " " << cats.get_pop() << endl;
    cats.season(&mice);
    mice.season(&cats);
  }

  return 0;
}
   


     
