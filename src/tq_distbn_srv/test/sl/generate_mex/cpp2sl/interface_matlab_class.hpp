#pragma once

#include "tq_distbn_srv.hpp"

class Matlab_Testing
{
public:
    Matlab_Testing();

    void update_input_signals_tq_distbn_srv(
        float in_powertrain_tq_recuperation_capacity_actual_Nm,
        float in_powertrain_tq_tar_total_Nm);

    Torque_Distribution_Service tq_distbn_srv;

private:
    // data members
    float input_powertrain_tq_recuperation_capacity_actual_Nm;
    float input_powertrain_tq_tar_total_Nm;
};