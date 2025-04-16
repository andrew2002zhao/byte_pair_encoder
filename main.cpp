#include <string>
#include <map>
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
  std::string return_string = build_vocabulary_1_gram("aaabcaa");
  //count duplicated 1 grams
  //shrink and add a new token value


  //upon parsing through a string
  //increase the gram size and look for more shrinking
  

  
  
  std::cout << return_string << std::endl;


  return 0;
}

