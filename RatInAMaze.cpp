/*
  You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). 
  The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. 
  The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. 
  The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).
*/

// BACKTRACKING

#include <bits/stdc++.h> 
#include <vector>
#include <string>

bool isSafe(
        int new_x, 
        int new_y, 
        vector<vector<bool>> &visited, 
        vector < vector < int >> & arr, 
        int n
    ){
    // check if the new_x and new_y both are in the maze
    if((new_x >= 0 && new_x < n) && (new_y >= 0 && new_y < n) && visited[new_x][new_y] == 0 && arr[new_x][new_y] == 1){
        return true;
    }
    return false;
}

void sol(
        int x, 
        int y, 
        vector < vector < int >> & arr, 
        int n, 
        vector<string> &result,  
        vector<vector<bool>> &visited, 
        string path
    ){

    // base case
    // maze k end me pahuch gye
    if(x == n-1 && y == n-1){
        result.push_back(path);
        return;
    }
        visited[x][y] = 1;

    // down
    if(isSafe(x+1, y, visited, arr, n)){
        sol(x+1, y, arr, n, result, visited, path + 'D');
    }
     // left
    if(isSafe(x, y-1, visited, arr, n)){
        sol(x, y-1, arr, n, result, visited, path + 'L');
    }
    // right
    if(isSafe(x, y+1, visited, arr, n)){
        sol(x, y+1, arr, n, result, visited, path + 'R');
    }
    // up
    if(isSafe(x-1, y, visited, arr, n)){
        sol(x-1, y, arr, n, result, visited, path + 'U');
    }
    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> result;
    vector<vector<bool>> visited (n, vector<bool> (n,0));
    string path;

    if (arr[0][0] == 0) return result;

    sol(0,0, arr, n, result, visited, path);
    return result;
}
