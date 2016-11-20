//
// Created by raz on 14/11/16.
//
#include <iostream>
#include <stack>
#include "BFS.h"
#include "Grid.h"

using namespace std;

void parser(string s, int &a, int &c);

void printRoute(stack<Node *> route);

/**
 * entry point.
 *
 * @return 0.
 */
int main() {
    stack<Node *> route;
    BFS bfs;
    Grid *grid;
    int x, y;
    int cols;
    int rows;
    Point start;
    Point end;
    string s;

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

    grid = new Grid(rows, cols);

    printRoute(bfs.run(grid->get(start), grid->get(end)));
// get information from user, parse it and create grid. get shortest lane.

    delete grid;
    return 0;
}

/**
 * parsing a string into two integers.
 *
 * @param s a string.
 * @param a first integer.
 * @param b second integer.
 */
void parser(string s, int &a, int &b) {
    unsigned long i = s.find('_');

    a = stoi(s.substr(0, i));
    b = stoi(s.substr(i + 1, s.size() - i - 1));
}

/**
 * printing a route.
 *
 * @param route a stuck of nodes.
 */
void printRoute(stack<Node *> route) {
    while (!route.empty()) {
        cout << route.top() << endl;
        route.pop();
    }
}