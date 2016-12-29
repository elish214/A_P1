//
// Created by raz on 14/11/16.
//

#include <iostream>
#include <stack>
#include "navigation/Node.h"
#include "Driver.h"
#include "sockets/Udp.h"
#include "sockets/Connection.h"

using namespace std;
//using namespace boost::archive;
//std::stringstream ss;

void parser(string s, int &a, int &c);

void printRoute(stack<Node *> route);

/**
 * entry point.
 *
 * @return 0.
 */
int main(int argc, char *argv[]) {
    Point *p = new Point(4, 5);
    Driver *d = new Driver(1,23,MaritalStatus::DIVORCED,123);

    cout << "Hello, from server" << endl;

    Connection con(new Udp(1, atoi(argv[1])));
    con.initialize();

    while (1) {
        char buffer[1024];

        con.receiveString(buffer);
        cout << buffer << endl;

        con.send(d);
    }


    //return 0;


    //Flow flow = Flow();

    //return flow.run();
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

    a = atoi(s.substr(0, i).c_str());
    b = atoi(s.substr(i + 1, s.size() - i - 1).c_str());
}

/**
 * printing a route.
 *
 * @param route a stuck of nodes.
 */
void printRoute(stack<Node *> route) {
    while (!route.empty()) {
        cout << *(route.top()) << endl;
        route.pop();
    }
}