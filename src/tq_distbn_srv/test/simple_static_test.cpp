#include <iostream>

#include "tq_distbn_srv.hpp"

int main()
{
    // positive
    float powertrain_tq_tar_total_Nm = 150.0;
    float powertrain_tq_recuperation_capacity_actual_Nm = -25.0;

    Torque_Distribution_Service tq_distbn_srv(
        powertrain_tq_recuperation_capacity_actual_Nm, powertrain_tq_tar_total_Nm);

    tq_distbn_srv.update();

    std::cout << "positive total_tar value: " << std::endl
              << "tq_tar_pt: " << tq_distbn_srv.get_tq_tar_pt() << std::endl
              << "tq_tar_brk: " << tq_distbn_srv.get_tq_tar_brk() << std::endl;

    // negative but greater as cap
    powertrain_tq_tar_total_Nm = -15.0;
    powertrain_tq_recuperation_capacity_actual_Nm = -25.0;

    tq_distbn_srv.update();

    std::cout << "negative total_tar value but greater cap: " << std::endl
              << "tq_tar_pt: " << tq_distbn_srv.get_tq_tar_pt() << std::endl
              << "tq_tar_brk: " << tq_distbn_srv.get_tq_tar_brk() << std::endl;

    // negative and smaller as cap
    powertrain_tq_tar_total_Nm = -45.0;
    powertrain_tq_recuperation_capacity_actual_Nm = -25.0;

    tq_distbn_srv.update();

    std::cout << "negative total_tar value and smaller cap: " << std::endl
              << "tq_tar_pt: " << tq_distbn_srv.get_tq_tar_pt() << std::endl
              << "tq_tar_brk: " << tq_distbn_srv.get_tq_tar_brk() << std::endl;

    return 0;
}