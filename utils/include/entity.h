#include <Eigen/Dense>
#include <iostream>

class Entity
{
    public:
        class States
        {
            public:
                Eigen::Vector3d pos;
                Eigen::Vector3d vel;
                Eigen::Vector3d acc;
                Eigen::Vector3d rpy;
                Eigen::Vector3d rates;

                States()
                {
                    pos   = Eigen::Vector3d::Zero();
                    vel   = Eigen::Vector3d::Zero();
                    acc   = Eigen::Vector3d::Zero();
                    rpy   = Eigen::Vector3d::Zero();
                    rates = Eigen::Vector3d::Zero();
                }
        };
};