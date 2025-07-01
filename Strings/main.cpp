
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

bool canBeSegmented(std::unordered_set<std::string> dictionnary, std::string words) {
  for (int i = 1; i <= words.length(); ++i) {
    std::string firstWord = words.substr(0,i);
    if (dictionnary.find(firstWord) != dictionnary.end())
    {
      std::string nextWord = words.substr(i);
      if (nextWord.empty() || canBeSegmented(dictionnary, nextWord))
        return true;
    }
  }
  return false;
}

std::vector<std::string> listPalindromes(std::string inputString) {
  std::vector<std::string> result;
  if (inputString.length() > 1) {
    for (int i = 1; i < inputString.length(); ++i) {
      int indexLeft = i;
      int indexRight = i;
      while ((indexLeft >= 0 && indexRight < inputString.length()) &&
        inputString[indexLeft] == inputString[indexRight])
      {
        indexLeft--;
        indexRight++;
      }
      if (indexRight - indexLeft > 2)
        result.push_back(inputString.substr(indexLeft+1, indexRight - indexLeft - 1));
    }
  }
  return result;
}

void printBrackets(int n) {
  std::cout << n << " bracket combination: ";
  if (n == 1)
    std::cout << "{}";

  std::cout << std::endl;
}

int main() {

  std::unordered_set<std::string> dictionnary = {"NULL", "This", "not", "is", "maybe", "a", "win"};
  std::string wordsWin = "Thiswin";
  std::string wordsFail = "Thisfail";

  std::cout << "Result win: " << canBeSegmented(dictionnary, wordsWin) << std::endl;
  std::cout << "Result fail: " << canBeSegmented(dictionnary, wordsFail) << std::endl;

  std::string stringWin = "bfbqyevey";
  std::string stringFail = "thisfail";

  std::cout << "Palindrome win: ";
  for (std::string palin : listPalindromes(stringWin))
    std::cout << palin << ", ";
  std::cout << std::endl;
  std::cout << "Palindrome fail: ";
  for (std::string palin : listPalindromes(stringFail))
    std::cout << palin << ", ";
  std::cout << std::endl;

  return 1;
}
