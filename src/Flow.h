//
// Created by raz on 06/12/16.
//

#ifndef A_P1_FLOW_H
#define A_P1_FLOW_H

/**
 * this is the flow class.
 * here everything operate.
 */
enum class Operation {
    NEW_DRIVER = 1, NEW_RIDE, NEW_VEHICLE, DRIVER_LOCATION, START = 6, EXIT
};

class Flow {
public:
    int run();
};


#endif //A_P1_FLOW_H
