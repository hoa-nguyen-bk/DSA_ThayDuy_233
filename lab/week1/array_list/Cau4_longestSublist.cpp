/*Given an array of strings.
Your task is to implement a function with following prototype:
int longestSublist(vector<string>& words);
The function returns the length of the longest subarray where all words share the same first letter.*/
#include <iostream>
#include <vector>
using namespace std;
//---START---
int longestSublist(vector<string> &words)
{
  // STUDENT ANSWER
  int length = words.size();
  int result = 0;
  for (int i = 0; i < length; i++)
  {
    int c = 0;
    for (int k = i; k < length; k++)
    {
      if (words[k][0] == words[i][0])
        c++;
      else
        break;
    }
    result = max(result, c);
  }
  return result;
}
//---END----
int main()
{
  vector<string> words{"faction", "fight", "and", "are", "attitude"};
  cout << longestSublist(words);
  // 3
  return 0;
}
