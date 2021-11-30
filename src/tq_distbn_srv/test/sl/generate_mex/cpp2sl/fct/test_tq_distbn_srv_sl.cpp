#include "test_tq_distbn_srv_sl.hpp"

/***************************************/
/**** Class instance global storage ****/
/***************************************/
Matlab_Testing *matlab_testing_sl;

//*************************************************
//**** Wrappers for methods called in Simulink ****
//*************************************************
void create_tq_distbn_srv() { matlab_testing_sl = new Matlab_Testing(); }

void delete_tq_distbn_srv() { delete matlab_testing_sl; }

void tq_distbn_srv_output(float in_powertrain_tq_recuperation_capacity_actual_Nm,
                          float in_powertrain_tq_tar_total_Nm,
                          float *out_tq_distbn_srv_tq_tar_pt_Nm,
                          float *out_tq_distbn_srv_tq_tar_brk_Nm)
{
    matlab_testing_sl->update_input_signals_tq_distbn_srv(
        in_powertrain_tq_recuperation_capacity_actual_Nm, in_powertrain_tq_tar_total_Nm);

    matlab_testing_sl->tq_distbn_srv.update();

    *out_tq_distbn_srv_tq_tar_pt_Nm = matlab_testing_sl->tq_distbn_srv.get_tq_tar_pt();
    *out_tq_distbn_srv_tq_tar_brk_Nm = matlab_testing_sl->tq_distbn_srv.get_tq_tar_brk();
}