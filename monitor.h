#ifndef MONITOR_H
#define MONITOR_H
#include <windows.h>
#include <pdh.h>

class PerformanceMonitor
{
private:
    PDH_HQUERY query;
    PDH_HCOUNTER cpuCounter;
    PDH_HCOUNTER ramCounter;
    PDH_HCOUNTER diskCounter;
    PDH_HCOUNTER networkCounter;
    bool initialized;

    double GetCounterValue(PDH_HCOUNTER counter);

public:
    PerformanceMonitor();
    ~PerformanceMonitor();

    // Initialize PDH counters
    bool starter();

    // Collect data
    bool collector();

    // Get counter values
    double getCPU();
    double getRAM();
    double getDisk();
    double getNetworkUsage();
};

#endif // MONITOR_H
