/**
 * @licence app begin@
 * Copyright (C) 2011-2012  BMW AG
 *
 * This file is part of GENIVI Project Dlt Viewer.
 *
 * Contributions are licensed to the GENIVI Alliance under one or more
 * Contribution License Agreements.
 *
 * \copyright
 * This Source Code Form is subject to the terms of the
 * Mozilla Public License, v. 2.0. If a  copy of the MPL was not distributed with
 * this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \file dltviewerplugin.h
 * For further information see http://www.genivi.org/.
 * @licence end@
 */

#ifndef DLTVIEWERPLUGIN_H
#define DLTVIEWERPLUGIN_H

#include <QObject>
#include "plugininterface.h"
#include "form.h"

#define DLT_VIEWER_PLUGIN_VERSION "1.0.0"

class DltViewerPlugin : public QObject, QDLTPluginInterface, QDltPluginViewerInterface
{
    Q_OBJECT
    Q_INTERFACES(QDLTPluginInterface)
    Q_INTERFACES(QDltPluginViewerInterface)
    Q_PLUGIN_METADATA(IID "org.genivi.DLT.Plugin.DLTPluginInterface.DltViewerPlugin");

public:
    DltViewerPlugin();
    ~DltViewerPlugin();

    /* QDLTPluginInterface interface */
    QString name();
    QString pluginVersion();
    QString pluginInterfaceVersion();
    QString description();
    QString error();
    bool loadConfig(QString filename);
    bool saveConfig(QString filename);
    QStringList infoConfig();

    /* QDltPluginViewerInterface */
    QWidget* initViewer();
    void initFileStart(QDltFile *file);
    void initFileFinish();
    void initMsg(int index, QDltMsg &msg);
    void initMsgDecoded(int index, QDltMsg &msg);
    void updateFileStart();
    void updateMsg(int index, QDltMsg &msg);
    void updateMsgDecoded(int index, QDltMsg &msg);
    void updateFileFinish();
    void selectedIdxMsg(int index, QDltMsg &msg);
    void selectedIdxMsgDecoded(int index, QDltMsg &msg);

    /* internal variables */
    Form *form;

    /* statistics functions */
    void resetStatistics();
    void updateStatistics(int index, QDltMsg &msg);
    void printStatistics();

private:

    QDltFile *dltFile;
    QString errorText;

    int counterMessages;

    int counterVerboseLogs;
    int counterVerboseTraces;
    int countersVerboseLogs[QDltMsg::DltLogVerbose+1];
    int countersVerboseTraces[QDltMsg::DltNetworkTraceMost+1];


    int counterNonVerboseControl;
    int countersNonVerboseControl[QDltMsg::DltControlTime+1];

};

#endif // DLTVIEWERPLUGIN_H
