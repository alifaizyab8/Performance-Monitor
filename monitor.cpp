#include "monitor.h"


PerformanceMonitor::PerformanceMonitor()
    : query(NULL), cpuCounter(NULL), ramCounter(NULL),
    diskCounter(NULL), networkCounter(NULL), initialized(false) {}

PerformanceMonitor::~PerformanceMonitor()
{
    if (query != NULL)
        PdhCloseQuery(query);
}

double PerformanceMonitor::GetCounterValue(PDH_HCOUNTER counter)
{
    PDH_FMT_COUNTERVALUE counterValue;
    PDH_STATUS status = PdhGetFormattedCounterValue(counter, PDH_FMT_DOUBLE, NULL, &counterValue);
    if (status == ERROR_SUCCESS)
        return counterValue.doubleValue;
    else
        return -1.0; // Error
}

bool PerformanceMonitor::starter()
{
    PDH_STATUS status;

    status = PdhOpenQuery(NULL, 0, &query);
    if (status != ERROR_SUCCESS)
        return false;

    status = PdhAddCounterW(query, L"\\Processor(_Total)\\% Processor Time", 0, &cpuCounter);
    if (status != ERROR_SUCCESS)
        return false;

    status = PdhAddCounterW(query, L"\\Memory\\Available MBytes", 0, &ramCounter);
    if (status != ERROR_SUCCESS)
        return false;

    status = PdhAddCounterW(query, L"\\PhysicalDisk(_Total)\\% Disk Time", 0, &diskCounter);
    if (status != ERROR_SUCCESS)
        return false;

    status = PdhAddCounterW(query, L"\\Network Interface(*)\\Bytes Total/sec", 0, &networkCounter);
    if (status != ERROR_SUCCESS)
        return false;

    status = PdhCollectQueryData(query);
    if (status != ERROR_SUCCESS)
        return false;

    initialized = true;
    return true;
}

bool PerformanceMonitor::collector()
{
    if (!initialized)
        return false;
    PDH_STATUS status = PdhCollectQueryData(query);
    return status == ERROR_SUCCESS;
}

double PerformanceMonitor::getCPU() { return GetCounterValue(cpuCounter); }
double PerformanceMonitor::getRAM() { return GetCounterValue(ramCounter); }
double PerformanceMonitor::getDisk() { return GetCounterValue(diskCounter); }
double PerformanceMonitor::getNetworkUsage() { return GetCounterValue(networkCounter); }
