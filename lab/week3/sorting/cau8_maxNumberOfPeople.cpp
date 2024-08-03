#include <iostream>
#include <vector>
#include <algorithm> // Include the <algorithm> header for the sort function
using namespace std;
//---START---
int maxNumberOfPeople(vector<int> &rooms, vector<int> &people, int k)
{

  sort(rooms.begin(), rooms.end());
  sort(people.begin(), people.end());

  int i = 0; // Pointer for rooms
  int j = 0; // Pointer for people
  int count = 0;

  while (i < rooms.size() && j < people.size())
  {
    if (rooms[i] >= people[j] - k && rooms[i] <= people[j] + k)
    {
      // Room i fits for person j
      count++;
      i++;
      j++;
    }
    else if (rooms[i] < people[j] - k)
    {
      // Room i is too small for person j
      i++;
    }
    else
    {
      // Room i is too big for person j
      j++;
    }
  }

  return count;
}
//---END---
int main()
{
  int peopleCount, roomCount, k;
  cin >> peopleCount >> roomCount >> k;

  vector<int> people(peopleCount);
  vector<int> rooms(roomCount);

  for (int i = 0; i < peopleCount; i++)
    cin >> people[i];
  for (int i = 0; i < roomCount; i++)
    cin >> rooms[i];
  cout << maxNumberOfPeople(rooms, people, k) << '\n';
  // 3 4 5
  // 30 60 75
  // 57 45 80 65
  // 2
  return 0;
}
