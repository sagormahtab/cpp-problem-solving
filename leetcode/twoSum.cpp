#include <iostream>
#include <iterator>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
  vector<int> ar = {2, 7, 11, 15};
  int target = 9;
  vector<int>::iterator ptr, ptr2;
  // char openingThirdBracket[50] = "[";
  // char closingThirdBracket[50] = "]";
  // char comma[50] = ",";

  for (ptr = ar.begin(); ptr < ar.end(); ptr++)
  {
    bool isFound = false;
    for (ptr2 = ar.begin(); ptr2 < ar.end(); ptr2++)
    {
      int index1 = ptr - ar.begin();
      int index2 = ptr2 - ar.begin();
      int addition = ar[index1] + ar[index2];

      // string indexStr1 = to_string(index1);
      // string indexStr2 = to_string(index2);

      if (addition == target)
      {
        isFound = true;
        // strcat(openingThirdBracket, indexStr1, comma, indexStr2, closingThirdBracket);
        // string result = openingThirdBracket + index1 + comma + index2 + closingThirdBracket;
        // string result = "[" + index1 + index2 + "]";
        cout << result;
        break;
      }
    }

    if (isFound == true)
    {
      break;
    }
  }
  return 0;
}