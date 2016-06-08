#include "gatoconnectionparameters.h"
#include <QSharedData>

struct GatoConnectionParametersPrivate : public QSharedData
{
	int scanInterval;
	int scanWindow;
	int connIntervalMin;
	int connIntervalMax;
	int slaveLatency;
	int supervisionTimeout;
	int connectionTimeout;
};

GatoConnectionParameters::GatoConnectionParameters()
	: d(new GatoConnectionParametersPrivate)
{
	d->scanInterval = 10000; // 10 ms
	d->scanWindow = 10000; // 10 ms
	// Set a connection scan interval between 10 and 320 ms.
	d->connIntervalMin = 10000;
	d->connIntervalMax = 320000;
	d->slaveLatency = 0;
	d->supervisionTimeout = 10000; // 10 seconds
}

GatoConnectionParameters::GatoConnectionParameters(const GatoConnectionParameters &o)
	: d(o.d)
{
}

GatoConnectionParameters::~GatoConnectionParameters()
{
}

int GatoConnectionParameters::scanInterval() const
{
	return d->scanInterval;
}

void GatoConnectionParameters::setScanInterval(int interval)
{
	d->scanInterval = interval;
}

int GatoConnectionParameters::scanWindow() const
{
	return d->scanWindow;
}

void GatoConnectionParameters::setScanWindow(int interval)
{
	d->scanWindow = interval;
}

int GatoConnectionParameters::connectionIntervalMin() const
{
	return d->connIntervalMin;
}

void GatoConnectionParameters::setConnectionIntervalMin(int interval)
{
	d->connIntervalMin = interval;
}

int GatoConnectionParameters::connectionIntervalMax() const
{
	return d->connIntervalMax;
}

void GatoConnectionParameters::setConnectionIntervalMax(int interval)
{
	d->connIntervalMax = interval;
}

void GatoConnectionParameters::setConnectionInterval(int min, int max)
{
	d->connIntervalMin = min;
	d->connIntervalMax = max;
}

int GatoConnectionParameters::slaveLatency() const
{
	return d->slaveLatency;
}

void GatoConnectionParameters::setSlaveLatency(int latency)
{
	d->slaveLatency = latency;
}

int GatoConnectionParameters::supervisionTimeout() const
{
	return d->supervisionTimeout;
}

void GatoConnectionParameters::setSupervisionTimeout(int timeout)
{
	d->supervisionTimeout = timeout;
}

int GatoConnectionParameters::connectionTimeout() const
{
	return d->connectionTimeout;
}

void GatoConnectionParameters::setConnectionTimeout(int timeout)
{
	d->connectionTimeout = timeout;
}

GatoConnectionParameters &GatoConnectionParameters::operator=(const GatoConnectionParameters &o)
{
	if (this != &o)
		d.operator=(o.d);
	return *this;
}
