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

struct BuzzMemory
{
    Atmosphere Atmos;
};
