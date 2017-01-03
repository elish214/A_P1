//
// Created by raz on 27/12/16.
//

#include "Connection.h"

/**
 * constructor.
 *
 * @param socket a socket.
 */
Connection::Connection(Socket *socket) : socket(socket) {}

/**
 * destructor.
 */
Connection::~Connection() {
    delete socket;
}

/**
 * initializng connection.
 *
 * @return 0 if correct. other numbers otherwise.
 */
int Connection::initialize() {
    return socket->initialize();
}

/**
 * recieve a string from connection.
 *
 * @param buffer a buffer.
 * @return number of bytes it gets.
 */
int Connection::receiveString(char *buffer) {
    return socket->reciveData(buffer, sizeof(buffer));
}

/**
 * send a string.
 *
 * @param s a string.
 * @return 0 if correct. other numbers otherwise.
 */
int Connection::sendString(string s) {
    return socket->sendData(s);
}
