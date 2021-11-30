#include "interface_matlab_class.hpp"

Matlab_Testing::Matlab_Testing()

    :

      tq_distbn_srv(input_powertrain_tq_recuperation_capacity_actual_Nm,
                    input_powertrain_tq_tar_total_Nm),

      input_powertrain_tq_recuperation_capacity_actual_Nm(0.0),
      input_powertrain_tq_tar_total_Nm(0.0)

{
}

void Matlab_Testing::update_input_signals_tq_distbn_srv(
    float in_powertrain_tq_recuperation_capacity_actual_Nm, float in_powertrain_tq_tar_total_Nm)
{
    input_powertrain_tq_recuperation_capacity_actual_Nm =
        in_powertrain_tq_recuperation_capacity_actual_Nm;
    input_powertrain_tq_tar_total_Nm = in_powertrain_tq_tar_total_Nm;
}