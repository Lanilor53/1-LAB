#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

/**
 * @brief Given a sequence of 20 elements returns minimum element in the sequence
 * @tparam sequenceType
 * @param seq
 * @return Minimum element in the sequence
 */
template <typename sequenceType>
auto min_seq(sequenceType seq[20])
{
  sequenceType minN;
  minN = seq[0];
  for (int i=0; i < 20; i++){
    if (minN>seq[i]){
      minN = seq[i];
    }
  }
  return minN;
}

/**
 * @brief Given a sequence of 20 elements returns maximum element in the sequence
 * @tparam sequenceType
 * @param seq
 * @return Maximum element in the sequence
 */
template <typename sequenceType>
auto max_seq(sequenceType seq[20])
{
  sequenceType maxN;
  maxN = seq[0];
  for (int i=0; i < 20; i++){
    if (maxN<seq[i]){
      maxN = seq[i];
    }
  }
  return maxN;
}

/**
 * @brief Given a sequence of 20 elements returns average value in the sequence
 * @tparam sequenceType
 * @param seq
 * @return Average value in the sequence
 */
template <typename sequenceType>
auto avg_seq(sequenceType seq[20])
{
  float avgN = 0;
  for (int i=0; i < 20; i++){
    avgN += seq[i];
  }
  avgN = avgN/20;
  return avgN;
}

/**
 * @brief Given a sequence of 20 elements returns the sum of its elements
 * @tparam sequenceType
 * @param seq
 * @return Sum of elements
 */
template <typename sequenceType>
auto sum_seq(sequenceType seq[20])
{
  sequenceType sumN = 0;
  for (int i=0; i < 20; i++){
    sumN += seq[i];
  }
  return sumN;
}

/**
 * @brief Generates a random float from min to max. Use srand() before generating.
 * @param min
 * @param max
 * @return
 * @related https://stackoverflow.com/a/686373
 */
float genRandomFloat(float min, float max){
  return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

/**
 * @brief Handles the sequence using type of the provided argument
 * @tparam sequenceType
 * @param t
 */
template <typename sequenceType>
void handleSequence(sequenceType t) {
  sequenceType sequence[20];

  srand(time(nullptr));
  for (auto & i : sequence){
    i = genRandomFloat(0,100);
  }
  cout << "Generated sequence: [";
  for (auto & j : sequence) {
    cout << j << ", ";
  }
  cout << "\b\b]" << endl; // \b\b is used to overwrite the last ", " written to cout

  cout << "Minimal value in the sequence is " << min_seq(sequence) << endl;
  cout << "Maximum value in the sequence is " << max_seq(sequence) << endl;
  cout << "Average value in the sequence is " << avg_seq(sequence) << endl;
  cout << "Sum of values in the sequence is " << sum_seq(sequence) << endl;

  exit(0);
}

int main() {
  char buff[256];

  int flagInt = 0;
  double flagDouble = 0;
  float flagFloat = 0;

  // Wait for user input
  while (!(flagInt || flagDouble || flagFloat)) {
    cout << "Sequence type:";
    cin >> buff;
    strcmp(buff, "float") == 0 ? handleSequence(flagFloat++) : (strcmp(buff, "int") == 0 ? handleSequence(flagInt++) : (strcmp(buff, "double") == 0 ? handleSequence(flagDouble++) : (void)flagInt));
    cout << "Incorrect type." << endl;
  }

  return 0;
}
