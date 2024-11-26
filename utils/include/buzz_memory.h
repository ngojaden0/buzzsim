#pragma once

#include <Eigen/Dense>
struct Atmosphere
{
    double temp;
    double pressure;
    double density;
    double sonic_speed;
    double dyn_pressure;
    double mach;

    void reset()
    {
        temp = 0.0;
        pressure = 0.0;
        density = 0.0;
        sonic_speed = 0.0;
        dyn_pressure = 0.0;
        mach = 0.0;
    };
};

struct Aerodynamics
{
    double Cl;
    double Cd;
    double alpha;
    double bank;

    void reset()
    {
        Cl = 0.0;
        Cd = 0.0;
        alpha = 0.0;
        bank = 0.0;
    };
};

struct Propulsion
{
    double mass;
    double mdot;
    double specific_impulse;
    double thrust;
    double xcg;

    void reset()
    {
        mass = 0.0;
        mdot = 0.0;
        specific_impulse = 0.0;
        thrust = 0.0;
        xcg = 0.0;
    };
};

struct Newton
{
    Eigen::Vector3d forces;

    void reset()
    {
        forces.setZero();
    }  
};

struct BuzzMemory
{
    Atmosphere atmos;
    Aerodynamics aero;
    Propulsion prop;
    Newton eom;

    double dt;
    double totalTime;

    void reset()
    {
        dt = 0.0;
        totalTime = 0.0;
    }
};
