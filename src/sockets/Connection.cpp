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

int Connection::accept() {
    client = socket->initialRecieve();
    return client;
}

/**
 * recieve a string from connection.
 *
 * @param buffer a buffer.
 * @return number of bytes it gets.
 */
int Connection::receiveString(char *buffer) {
    socket->setDescriptorCommunicateClient(client);
    return socket->reciveData(buffer, sizeof(buffer));
}

/**
 * send a string.
 *
 * @param s a string.
 * @return 0 if correct. other numbers otherwise.
 */
int Connection::sendString(string s) {
    socket->setDescriptorCommunicateClient(client);
    return socket->sendData(s);
}

int Connection::getClient() const {
    return client;
}

void Connection::setDescriptor(int client) {
    Connection::client = client;
}
