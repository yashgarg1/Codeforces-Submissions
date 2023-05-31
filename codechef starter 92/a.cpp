#include <iostream>
#include <set>
using namespace std;
int main() {
   int arr[] = {10, 15, 26, 30, 35, 40, 48, 87, 98};
   set<int> my_set(arr, arr + sizeof(arr) / sizeof(arr[0]));
   set<int>::iterator it;
   cout << "Elements of Set in forward order: ";
   for (it = my_set.begin(); it != my_set.end(); it++)
      cout << *it << " ";
   set<int>::reverse_iterator rev_it;
   cout << "\nElements of Set in reverse order: ";
   for (rev_it = my_set.rbegin(); rev_it != my_set.rend(); rev_it++)
      cout << *rev_it << " ";
}