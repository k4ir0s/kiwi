/*
 *  Copyright (c) 2009 Novell, Inc.
 *  All Rights Reserved.
 *  
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, contact Novell, Inc.
 *  
 *  To contact Novell about this file by physical or electronic mail,
 *  you may find current contact information at www.novell.com
 *  
 *  Author: Matt Barringer <mbarringer@suse.de>
 *  
 */

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <QtCore>
#include <QtDBus>

#include "DeviceItem.h"

class Platform
{

public:
    Platform(bool kioskMode = false);
    bool removeDeviceFromList(const QString &displayName);
    DeviceItem *findDeviceInList(const QString &displayName);
    void writeData(QString path, QString fileName, qint64 deviceSize);
    QLinkedList<DeviceItem *> getDeviceList() { return itemList; }

    virtual void findDevices(bool unsafe = false) {}
    virtual bool isMounted(QString path) { return false; }
    virtual bool unmountDevice(QString path) { return false; }
    virtual DeviceItem *getNewDevice(QString devicePath) { return(NULL); }

protected:
    bool performUnmount(QString udi);
    bool mKioskMode;
    DeviceItem *pDevice;
    QLinkedList<DeviceItem *> itemList;
};

#endif
