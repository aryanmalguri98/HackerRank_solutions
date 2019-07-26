#include<bits/stdc++.h>
using namespace std;
vector<vector<char> >grid;
//vector<int> size;
vector<vector<int> >visited;
vector<vector<int> > getunvisitedpairs(vector<vector<char> > grid,int i,int j, vector<vector<int> > visited);
vector<int> solution(vector<vector<char> >grid, vector<vector<int> >* visited);
void traverseNode(vector<vector<char> > grid, vector<vector<int> >* visited, int i, int j, vector<int>* sizes);

vector<int> solution(vector<vector<char> >grid, vector<vector<int> >* visited)
{
    vector<int> sizes{};
    vector<vector<int> > visited(grid.size(), vector<int>(grid[0].size(), false));
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(visited[i][j])
                continue;
            traverseNode(grid, &visited, i, j, &sizes);    
        }
    }
    return sizes;
}
void traverseNode(vector<vector<char> >grid, vector<vector<int> >* visited, int i, int j, vector<int>* sizes){
    int current_size = 0;
    vector<vector<int> >nodesToExplore{{i,j}};
    while(nodesToExplore.size()!=0){
        vector<int> currentNode = nodesToExplore.back();
        nodesToExplore.pop_back();
        i = currentNode[0];
        j = currentNode[1];
        if(visited[i][j])
            continue;
        if(grid[i][j] == 'B')
            continue;
        current_size++;    
        vector<vector<int> >unvisitedpair = getunvisitedpairs(grid, i, j, *visited);
        for(vector<int> neighbor:unvisitedpair)
            nodesToExplore.push_back(neighbor);
    }
    if((current_size % 2) != 0){
        sizes->push_back(current_size);
    }

}


vector<vector<int> > getunvisitedpairs(vector<vector<char> > grid,int i,int j, vector<vector<int> > visited){
    vector<vector<int> >unvisitedpair{};
    if(i > 0 && !visited[i-1][j])
        unvisitedpair.push_back({i-1, j});
    if(i < grid.size() && !visited[i+1][j])
        unvisitedpair.push_back({i+1, j});
    if(j > 0 && !visited[i][j-1])
        unvisitedpair.push_back({i, j-1});
    if(i < grid[0].size() && !visited[i][j+1])
        unvisitedpair.push_back({i, j+1});
    return unvisitedpair;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int row, column, answer = 1;
    cin >> row >> column;
    for(int i = 0; i < row; i++){
        
        for(int j = 0; j < column; j++){
            cin >> grid[i][j];
        }
    }
    vector<int> final_solution_pair = solution(grid, &visited);
    for(int i = 0; i < final_solution_pair.size(); i++)
    {
        answer = answer*final_solution_pair[i];
    }
    cout << answer << endl;
    return 0;
}