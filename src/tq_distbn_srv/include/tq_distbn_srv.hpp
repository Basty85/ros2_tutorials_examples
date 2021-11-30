#pragma once

class Torque_Distribution_Service
{
public:
    Torque_Distribution_Service(float &ext_powertrain_tq_recuperation_capacity_actual_Nm,
                                float &ext_powertrain_tq_tar_total_Nm);

    float get_tq_tar_pt() const { return tq_distbn_srv_tq_tar_pt_Nm; }
    float get_tq_tar_brk() const { return tq_distbn_srv_tq_tar_brk_Nm; }

    void update();

private:
    float limit_tq_recu_capacity();
    bool is_greater_equal_tq_recu_capacity();

    float tq_distbn_srv_tq_tar_pt_Nm;
    float tq_distbn_srv_tq_tar_brk_Nm;

    float &powertrain_tq_recuperation_capacity_actual_Nm;
    float &powertrain_tq_tar_total_Nm;
};