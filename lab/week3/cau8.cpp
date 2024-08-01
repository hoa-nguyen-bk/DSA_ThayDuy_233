#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());

    int i = 0; // Pointer for rooms
    int j = 0; // Pointer for people
    int count = 0;

    while (i < rooms.size() && j < people.size()) {
        if (rooms[i] >= people[j] - k && rooms[i] <= people[j] + k) {
            // Room i fits for person j
            count++;
            i++;
            j++;
        } else if (rooms[i] < people[j] - k) {
            // Room i is too small for person j
            i++;
        } else {
            // Room i is too big for person j
            j++;
        }
    }

    return count;
}

int main() {
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;
    
    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for(int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for(int i = 0; i < roomCount; i++)
        cin >> rooms[i];

    cout << maxNumberOfPeople(rooms, people, k) << '\n'; 

    return 0;
}

/*

To solve the problem of matching as many people as possible to rooms with their desired room sizes within a given tolerance k, we can use a greedy algorithm. The steps are as follows:

Sort the Rooms and People's Desired Room Sizes: Sorting will allow us to efficiently match the smallest available room that meets the person's requirement.
Two-pointer Technique: Use two pointers to iterate through the sorted rooms and people. This technique helps in efficiently finding the best match for each person without rechecking already checked rooms.
Explanation:
Sorting:
Both rooms and people arrays are sorted to facilitate the matching process.
Two-pointer Technique:
Two pointers i and j are used to traverse the rooms and people arrays, respectively.
If the current room size (rooms[i]) is within the acceptable range of the current person's desired room size (people[j] ± k), both pointers are incremented, and the count of matched pairs is increased.
If the current room size is smaller than the acceptable range, the room pointer i is incremented to check the next larger room.
If the current room size is larger than the acceptable range, the person pointer j is incremented to check the next person with a higher desired room size.
Edge Cases:
The algorithm efficiently handles cases with very large or very small values of k, as well as arrays with different lengths and contents.
Sorting ensures that the solution works within the provided constraints efficiently.
This solution ensures that we find the maximum number of people who can get rooms within their acceptable size range in an efficient manner.
*/