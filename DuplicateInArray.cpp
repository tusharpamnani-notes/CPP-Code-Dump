/*
  You are given an array 'ARR' of size 'N' containing each number between 1 and 'N' - 1 at least once. 
  There is a single integer value that is present in the array twice. 
  Your task is to find the duplicate integer value present in the array
*/

/* 
  Link to the question
  https://www.codingninjas.com/studio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
*/

int findDuplicate(vector<int> &arr) 
{
    int result = 0;
    for( int i=0; i<arr.size(); i++){
        result ^= arr[i];
    }
    for(int i = 0; i<arr.size(); i++){
        result ^= i;
    }
    return result;
}

/*
  XOR ing the elements to remove the duplicate elements.
  XOR ing the elements of given array with an array of elements [1, (N-1)]
  This way, Every element will be removed leaving the duplicate one.
  Consider this as: 
  n -> 7
  given array -> [1, 2, 3, 4, 5, 6, 2] -> array1
  given array after XOR ing -> [1, 3, 4, 5, 6] -> array2
  new array with elements [1, (N-1)] -> [1, 2, 3, 4, 5, 6]
  XOR ing array1 and array2 -> 2
  result -> duplicate number was 2
*/
