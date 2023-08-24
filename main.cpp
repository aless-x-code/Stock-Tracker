
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *const argv[])
{
  float stock, second_entry, last = 0;        // stock variables
  float fw, fm, avg, sum;                     // fluctuation width, fluctuation mean, average, sum
  float min, max;                             // min and max
  float change, change1, change2, sum_change; // price change variables
  float count = 1;
  string buying_d;                            // buying descision

  // Retrieve first and second stock prices
  cout << "Enter stock price (enter -1 when finished): ";
  cin >> stock;
  cout << "Enter stock price (enter -1 when finished): ";
  cin >> second_entry;

  // initialize second entry as the price to be compared for min and max
  min = second_entry;
  max = second_entry;

  // initialize sum as second entry
  sum = second_entry;

  // initialize change1 and change2 to first and second entries for change comparasion
  change1 = stock;
  change2 = second_entry;
  sum_change = 0;

  // while stock is not -1 (sentinel)
  while (stock != -1)
  {
    // This will hold the last stock price before - 1 is inputed
    last = stock;
    // if entry is higher than max, then assign it as max
    if (stock > max)
      max = stock;
    // if entry is not higher than max, then is it lower than min
    else if (stock < min)
      min = stock;
    // Cummulative sum of stock prices
    sum += stock;

    // price change is equal to change1, minus change2 
    change = change1 - change2;
    // cummulative sum of price change squared
    sum_change += change * change;
    // shift change2 to change1 position, for next price change calculation
    change1 = change2;

    // enter new stock entry
    cout << "Enter stock price (enter -1 when finished): ";
    cin >> stock;
    // copy new entry to change2 for next price change calculation
    change2 = stock;

    // increase count by 1
    count++;
  }

  // fluctuation and average calculations
  fw = max - min;
  fm = sqrt(sum_change / (count - 1));
  avg = sum / count;

  // Buy stock if last entry is lower than avg price AND (either FW is lower than 1/3 of avg OR FM is lower than 1/3 of avg)
  if (last < avg && ((fw < avg / 3) || (fm < avg / 3)))
    buying_d = "Stock price pattern meets buying criteria";
  // If not, don't buy
  else
    buying_d = "Stock price pattern doesn't meet buying criteria";

  // Output
  cout << endl;
  cout << "Average price           : " << avg << endl;
  cout << "Fluctuation Width       : " << fw << endl;
  cout << "Fluctuation Mean        : " << fm << endl;
  cout << "Buying decision         : " << buying_d << endl;
  cout << endl;
}
