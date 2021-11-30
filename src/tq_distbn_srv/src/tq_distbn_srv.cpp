#include "tq_distbn_srv.hpp"

#include <algorithm>

Torque_Distribution_Service::Torque_Distribution_Service(
    float &ext_powertrain_tq_recuperation_capacity_actual_Nm,
    float &ext_powertrain_tq_tar_total_Nm)

    :

      powertrain_tq_recuperation_capacity_actual_Nm(
          ext_powertrain_tq_recuperation_capacity_actual_Nm),
      powertrain_tq_tar_total_Nm(ext_powertrain_tq_tar_total_Nm),
      tq_distbn_srv_tq_tar_pt_Nm(0.0),
      tq_distbn_srv_tq_tar_brk_Nm(0.0)

{
}

void Torque_Distribution_Service::update()
{
    if (is_greater_equal_tq_recu_capacity())
    {
        tq_distbn_srv_tq_tar_pt_Nm = powertrain_tq_tar_total_Nm;
        tq_distbn_srv_tq_tar_brk_Nm = 0.0;
    }
    else  // tq split path
    {
        tq_distbn_srv_tq_tar_pt_Nm = limit_tq_recu_capacity();
        tq_distbn_srv_tq_tar_brk_Nm =
            powertrain_tq_tar_total_Nm - limit_tq_recu_capacity();
    }
}

bool Torque_Distribution_Service::is_greater_equal_tq_recu_capacity()
{
    return (powertrain_tq_tar_total_Nm >= limit_tq_recu_capacity());
}

float Torque_Distribution_Service::limit_tq_recu_capacity()
{
    return (std::min(powertrain_tq_recuperation_capacity_actual_Nm, 0.0F));
}