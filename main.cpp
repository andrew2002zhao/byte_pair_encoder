#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <iostream>

//characters -> token
std::map<std::string, std::string> vocabulary_map;
int vocabulary_count = 0;

std::string build_vocabulary_1_gram(std::string input) {
  std::string return_string = "";
  for(int i = 0 ; i < input.size(); i++) {
    //check if the character is in the vocab map
    if(vocabulary_map.find(std::string{input[i]}) != vocabulary_map.end()) {
      //if it is then add the token into return string
      return_string += vocabulary_map[std::string{input[i]}];
    }
    else{
      //otherwise add it to the vocab and return
      vocabulary_map.insert({std::string{input[i]}, std::to_string(vocabulary_count)});
      vocabulary_count++;
      return_string += vocabulary_map[std::string{input[i]}];
    }
  }
  return return_string;
}

// std::string build_vocabulary_2_gram(std::string input) {
//   /*
//   require a recursive function that will backtrack through every input and then update the vocabulary_map with new vocab that it generates 
//   */
//   //gets a hashmap back with the new vocabulary
//   2_gram_builder_recursive_function(input);
//   //for every 2-gram in hashmap
//   for(auto value : recursive_function_return) {
//     //add a new vocab into the global dictionary with a new number to represent the vocab
//     vocabulary_map.insert(value, std::to_string(vocabulary_count));
//     vocabulary_count++;
//   }
    
//   // take the input string match it with the new vocab
//   std::string matched_string = match_input_string_to_vocab(input, vocabulary_map);
//   return matched_string;
// }

using gram_dict = std::unordered_map<std::string, int>;
/**
 * 2_gram_builder_recursive_function
 * assumption : assume 2 grams for now so make window sized fix and dont require a parameter
 * fold_dictiontary and unique_folds are empty before being used for the first time 
 */
// 2_gram_builder_recursive_function(const std::string & input, int pointer, gram_dict & current_dictionary, gram_dict & best_dictionary) {
//   //pseudocode
  
//   //if pointer + n has reached the end of the string

//   if(pointer + 1 >= input.size()) {
//     compare_dictionaries(current_dictionary, best_dictionary);
//     return;
//   }
  
//   // return the amount of duplicated n-grams

//   //take a substring from pointer with size of n
//   std::string substring = input.substr(pointer, 2);
//   //increment the amount of times seeing this pattern
//   fold_dictionary[substring]++;
//   //call the recursive function
//   //if this iteration had more folds then store the map and token string
//   //decrement the amount of occurences of seeing this pattern
//   //or increment the pointer by 1 and then repeat the same decision making process


//   //determine the maximum folds between these two iterations and return the dictionary and new token string
//   /*
//   lets say theres a global best dictionary
//   everytime we reach the end, we check if our current dictionary is better than the global best, if it is we set a new global best
//   we don't really need to use the return state
//   there is a local dictionary we pass
//   the best dictionary will be returned
//   */
  
//   return best_dictionary;
// }

bool operator < (const gram_dict & l, const gram_dict & r) {
  //count the total number of folds and return true if left has more and return r is 
  int l_count = 0;
  for(auto element : l) {
    if(element.second > 1) {
      l_count += element.second - 1;
    }
  }
  int r_count = 0;
  for(auto element : r) {
    if(element.second > 1) {
      r_count += element.second - 1;
    }
  }
  return l_count < r_count;
}
//reuse the previously defined operator, just switch sides of the opreator since its commutative??? is that the word idk
bool operator > (const gram_dict & l, const gram_dict & r) {
  //count the total number of folds and return true if left has more and return r is 
  return r < l;
}

/*
ok so lets say this token folding method works
it should be able to return the updated token dictionary
it should also return the lengh of the longest string
but one problem is like what if the t /// im thinking of about how to make it faster
this is premature optimization
ok i believe this token folding method works. We dont need to think about faster yet.
*/

/*
this function feels complicated to immplement
is this really good enough?
theres required function paramters to make this code work that i dont know if i want to work
but how else am i going to be able to evaluate multiple different problems
i think this is good enough
we do need to specify certain parameters
and we do need to wrangle with recursion to make this work
but this will givem e a solution first
*/


int main(int argc, char ** argv) {
  
  //1) given an input of aaabdaaabac
  //2) return a compressed string with the dictionary

  std::string s = "aaabdaaabac";
  // std::string return_string = "";
  int counter = 0;



  //build a vocabulary
  //
  // std::string vocab_string = build_vocabulary(s);

  //count 1-gram frequency 
  // std::string return_string = build_vocabulary_1_gram("aaabcaa");
  //count duplicated grams to build 2 grams

  //take new token dictionary and build 2 grams for duplicates
  //shrink and add a new token value


  //gram_dict < operator overload


  gram_dict a;
  //a should have a count of 4
  a.insert({"a", 2});
  a.insert({"b", 4});

  //b should have a count of 3
  gram_dict b;
  b.insert({"a", 1});
  b.insert({"b", 4});
  //this should be false since b has less than a
  std::cout << (a < b) << std::endl;



  //b should have a count of 8 now
  b.insert({"c", 6});
  //this should be true since b has more than a now
  std::cout << (a < b) << std::endl;
  //this should be false since its just the "inverse" of the previous true statement
  std::cout << (a > b) << std::endl;
  
  
  // std::cout << return_string << std::endl;


  return 0;
}

