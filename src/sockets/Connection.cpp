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
 * accept connection.
 *
 * @return a descriptor.
 */
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

int Connection::receiveJava(char *buffer) {
    socket->setDescriptorCommunicateClient(client);
    int size = 0;
    char pbuffer[20000];

    socket->reciveData(pbuffer, sizeof(pbuffer));

    while(pbuffer[size] != '\0') {
        buffer[size] = pbuffer[size];
        size++;
    }

    buffer[size - 1] = '\0';

    return size - 1;
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

/**
 * returns connection's client.
 *
 * @return connection's client.
 */
int Connection::getClient() const {
    return client;
}

/**
 * setting connection's client.
 *
 * @param client a descriptor.
 */
void Connection::setDescriptor(int client) {
    Connection::client = client;
}
