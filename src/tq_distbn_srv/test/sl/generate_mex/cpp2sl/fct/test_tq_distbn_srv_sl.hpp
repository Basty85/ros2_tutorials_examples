#pragma once

#include "interface_matlab_class.hpp"

extern Matlab_Testing *matlab_testing_sl;

// Method wrappers
extern void create_tq_distbn_srv();
extern void delete_tq_distbn_srv();
extern void tq_distbn_srv_output(float in_powertrain_tq_recuperation_capacity_actual_Nm,
                                 float in_powertrain_tq_tar_total_Nm,
                                 float *out_tq_distbn_srv_tq_tar_pt_Nm,
                                 float *out_tq_distbn_srv_tq_tar_brk_Nm);