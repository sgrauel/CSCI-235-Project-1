#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm> /* for shuffling an array */
#include <iostream>
#include <random> /* C++11 random number generator */
#include "./Inventory.h"
using namespace std;


// non-static methods
/*
int Inventory::randomize(int upperBound, int lowerBound, int seed) {
  srand(seed);
  return rand() % upperBound + lowerBound;
}
*/


int Inventory::randomize(int upperBound, int lowerBound) {
    // create a random device used to seed the random number generator mt 
    random_device rd;
    mt19937 mt(rd());
    // create uniform distribution of reals
    uniform_real_distribution<double> dist(lowerBound, upperBound);
    // return 1 value at random from that uniform distribution
    return dist(mt);
}


Inventory::Inventory() {

  // generate random number of models from 5 to 20
  models = randomize(20,5);
  cout << "there are " << models << " models" << endl;

  // preinitialize stock array to -1 => NOT carrying a model
  fill_n(stock,20,-1);
  
  // initialize stock and shuffle
  for (int i = 0; i < models; i++) {
    // set stock entries to random numbers between 1 and 75  
    int initStock = randomize(75,1);
    stock[i] = initStock;  
  } 
  

  // shuffle the entries of the stock array
  random_shuffle(begin(stock),end(stock));

  cout << "the shuffled stock array (after random shuffle): " << endl;
  for (int i = 0; i < 20; i++) {
    cout << stock[i] << endl;
  } 
  
}

// static behavior and state
// NOTE: all static state is initialized before instantiation

// static data
int Inventory::corpInventory[20] = {0};

// static methods

// static version; NOTE: no need for second 'static' keyword
/*
int Inventory::randomizeStatic(int upperBound, int lowerBound, int seed) {
  srand(seed);
  return rand() % upperBound + lowerBound;
}
*/

int Inventory::randomizeStatic(int upperBound, int lowerBound) {
    // create a random device used to seed the random number generator mt 
    random_device rd;
    mt19937 mt(rd());
    // create uniform distribution of reals
    uniform_real_distribution<double> dist(lowerBound, upperBound);
    // return 1 value at random from that uniform distribution
    return dist(mt);
}



void Inventory::setCorpInventory() {
  
  cout << "set the corporation's inventory" << endl;
  for (int i = 0; i < 20; i++) {
    corpInventory[i] = randomizeStatic(2000,600);    
    cout << (to_string(i) + ": ")  << to_string(corpInventory[i]) << endl;
  }
  
}
