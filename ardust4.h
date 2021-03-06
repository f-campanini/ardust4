/*******************************************************************************
  Copyright(c) 2012 Jasem Mutlaq. All rights reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.

  The full GNU General Public License is included in this distribution in the
  file called LICENSE.
*******************************************************************************/

#ifndef ARDUST4_H
#define ARDUST4_H

#include <defaultdevice.h>
#include <indiguiderinterface.h>


/* Standard headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>

#include <sys/time.h>
#include <time.h>

class ARDUST4Driver;

class ARDUST4 : public INDI::GuiderInterface, public INDI::DefaultDevice
{
    public:
    ARDUST4();
    virtual ~ARDUST4();

    virtual bool initProperties();
    virtual bool updateProperties();
    virtual void ISGetProperties (const char *dev);
    virtual bool ISNewNumber (const char *dev, const char *name, double values[], char *names[], int n);
    virtual bool ISNewSwitch (const char *dev, const char *name, ISState *states, char *names[], int n);
    virtual bool ISNewText (const char *dev, const char *name, char *texts[], char *names[], int n);
    virtual bool ISSnoopDevice (XMLEle *root);

    protected:

    //  Generic indi device entries
    bool Connect();
    bool Disconnect();
    const char *getDefaultName();
    void debugTriggered(bool enable);

    void TimerHit();

    virtual IPState GuideNorth(float ms);
    virtual IPState GuideSouth(float ms);
    virtual IPState GuideEast(float ms);
    virtual IPState GuideWest(float ms);

    private:

    float CalcWEPulseTimeLeft();
    float CalcNSPulseTimeLeft();


    bool InWEPulse;
    float WEPulseRequest;
    struct timeval WEPulseStart;
    int WEtimerID;


    bool InNSPulse;
    float NSPulseRequest;
    struct timeval NSPulseStart;
    int NStimerID;

    int WEDir;
    int NSDir;

    ARDUST4Driver *driver;


};

#endif // ARDUST4_H
