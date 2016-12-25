//
// Created by raz on 14/11/16.
//

#include <iostream>
#include <stack>
#include "navigation/Node.h"
#include "Driver.h"
#include "sockets/Udp.h"

using namespace std;

void parser(string s, int &a, int &c);

void printRoute(stack<Node *> route);

/**
 * entry point.
 *
 * @return 0.
 */
int main(int argc, char *argv[]) {
    std::cout << "Hello, from server" << std::endl;

    while (1) {
        Udp udp(1, atoi(argv[1]));
        udp.initialize();

        char buffer[1024];
        udp.reciveData(buffer, sizeof(buffer));
        cout << buffer << endl;
        udp.sendData("sup?");
    }


    return 0;


    //Flow flow = Flow();
//
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