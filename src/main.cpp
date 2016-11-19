//
// Created by raz on 14/11/16.
//
#include <iostream>
#include <stack>
#include "BFS.h"
#include "Grid.h"

using namespace std;

char* parser(string s, int &a, int &c);
void printRoute(stack<Node*> route);

int main() {
    stack<Node*> route;
    BFS bfs;
    Grid *grid;
    int x,y;
    int cols;
    int rows;
    Point start;
    Point end;

    string s;
    cin >> s;

    getline(cin, s, ',');
    parser(s, cols, rows);

    getline(cin, s, ',');
    parser(s, x, y);
    start.setX(x);
    start.setY(y);

    getline(cin, s, '\n');
    parser(s, x, y);
    end.setX(x);
    end.setY(y);

    grid = new Grid(rows,cols);

    printRoute(bfs.run(grid->get(start), grid->get(end)));
// get information from user, parse it and create grid. get shortest lane.

    delete grid;
}

char* parser(string s, int &a, int &b){
    a = stoi(s.substr(0,'_'));
    b = stoi(s.substr('_', s.size()));
}

void printRoute(stack<Node*> route){
    while (!route.empty()){
        cout << route.top();
        route.pop();
    }
}