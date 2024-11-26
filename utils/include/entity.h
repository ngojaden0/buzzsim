#pragma once

#include <Eigen/Dense>
#include <iostream>

struct States
{
        Eigen::Vector3d pos;
        Eigen::Vector3d vel;
        Eigen::Vector3d acc;
        Eigen::Vector3d rpy;
        Eigen::Vector3d rates;

        void reset()
        {
            pos   = Eigen::Vector3d::Zero();
            vel   = Eigen::Vector3d::Zero();
            acc   = Eigen::Vector3d::Zero();
            rpy   = Eigen::Vector3d::Zero();
            rates = Eigen::Vector3d::Zero();
        }
};

struct Entity
{
    States states;
    double refArea;
    double refLength;

    void reset()
    {
        refArea = 0.0;
        refLength = 0.0;
    }
};