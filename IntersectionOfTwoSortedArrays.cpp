/*
  You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. 
  Both these arrays are sorted in non-decreasing order. 
  You have to find the intersection of these two arrays. 
  Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.
*/

/*
  link to the question
  https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
*/

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i =0, j=0;
	vector<int> ans;

	while(i<n && j<m){

		if(arr1[i] == arr2[j]){
			ans.push_back(arr1[i]);
			i++;
			j++;
		}

		else if(arr1[i] < arr2[j]){
			i++;
		}

		else {
			j++;
		}
	}
	return ans;
}

/*
  // NOT AN OPTIMIZED SOLUTION
#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;

	for(int i = 0; i< n; i++){
		int element = arr1[i];

		for(int j=0; j<m; j++){

			if(element < arr2[j]){
				break;
			}

			if(element == arr2[j]){
				ans.push_back(element);
				arr2[j] = -1;
				break;
			}
		} 
	}
	return ans;
}
*/
