#include "tq_distbn_pubsub/tq_distbn_srv.hpp"

#include <algorithm>

using namespace std::chrono_literals;

Torque_Distribution_Service::Torque_Distribution_Service(
    const float &ext_powertrain_tq_tar_total_Nm,
    const float &ext_powertrain_tq_recuperation_capacity_actual_Nm)

    :

      Node("tq_distbn_business_logic"),
      powertrain_tq_tar_total_Nm(ext_powertrain_tq_tar_total_Nm),
      powertrain_tq_recuperation_capacity_actual_Nm(ext_powertrain_tq_recuperation_capacity_actual_Nm),

      tq_distbn_srv_tq_tar_pt_Nm(0.0),
      tq_distbn_srv_tq_tar_brk_Nm(0.0)
{
    auto exec_business_logic = [this]() -> void
    {
        this->update();
    };

    timer_ = this->create_wall_timer(10ms, exec_business_logic);
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
        tq_distbn_srv_tq_tar_brk_Nm = powertrain_tq_tar_total_Nm - limit_tq_recu_capacity();
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