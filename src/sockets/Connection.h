//
// Created by raz on 27/12/16.
//

#ifndef A_P1_CONNECTION_H
#define A_P1_CONNECTION_H


#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include "Socket.h"

using namespace std;

/**
 * connection representing class.
 */
class Connection {
private:
    Socket *socket;
    int client;
public:
    Connection(Socket *socket);

    virtual ~Connection();

    int getClient() const;

    void setDescriptor(int client);

    /**
     * initialize socket
     * @return event code
     */
    int initialize();

    int accept();

    /**
     * receive text from socket
     * @param buffer buffer to save text
     * @return event code
     */
    int receiveString(char *buffer);

    int receiveJava(char *buffer);

    /**
     * receive and deserialize object
     * @tparam T object type
     * @return pointer to object
     */
    template<class T>
    T *receive() {
        T *ob;
        char buffer[130000];
        memset(buffer, 0, sizeof(buffer));

        socket->setDescriptorCommunicateClient(client);
        socket->reciveData(buffer, sizeof(buffer));

        std::string serial_str;
        boost::iostreams::basic_array_source<char> device(buffer, sizeof(buffer));
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        ia >> ob;

        return ob;
    }

    /**
     * send string to socket
     * @param s string
     * @return event code
     */
    int sendString(string s);

    /**
     * serialize and send object
     * @tparam T type
     * @param ob object
     * @return event code
     */
    template<class T>
    int send(T *ob) {
        std::string serial_str;
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(
                inserter);
        boost::archive::binary_oarchive oa(s);
        oa << ob;
        s.flush();

        socket->setDescriptorCommunicateClient(client);

        return socket->sendData(serial_str, (int) serial_str.size());
    }
};


#endif //A_P1_SENDER_H