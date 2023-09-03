/*
  You have been given an integer array/list(ARR) of size N. 
  Where N is equal to [2M + 1]. 
  Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
  You need to find and return that number which is unique in the array/list.
*/

/* Link to the question
  https://www.codingninjas.com/studio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
*/  

int findUnique(int *arr, int size)
{
    int result = 0;
    for(int i = 0; i< size; i++){
        result ^= arr[i];
    }
    return result;
}

/*
  Using XOR logic. 
  a^a = 0
  0^a = a
  All the duplicate numbers when XORed with each other will  be removed and only the unique ones will remain.
  When theses reamining elements are XORed with 0, won't have a change, leaving the unique ones in the array
*/
