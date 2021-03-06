/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <coreplugin/dialogs/ioptionspage.h>

#include <utils/aspects.h>

namespace Autotest {
namespace Internal {

enum MetricsType
{
    Walltime,
    TickCounter,
    EventCounter,
    CallGrind,
    Perf
};

class QtTestSettings : public Utils::AspectContainer
{
    Q_DECLARE_TR_FUNCTIONS(Autotest::Internal::QtTestSettings)
public:
    QtTestSettings();

    static QString metricsTypeToOption(const MetricsType type);

    Utils::SelectionAspect metrics;
    Utils::BoolAspect noCrashHandler;
    Utils::BoolAspect useXMLOutput;
    Utils::BoolAspect verboseBench;
    Utils::BoolAspect logSignalsSlots;
    Utils::BoolAspect limitWarnings;
    Utils::IntegerAspect maxWarnings;
};

class QtTestSettingsPage final : public Core::IOptionsPage
{
public:
    QtTestSettingsPage(QtTestSettings *settings, Utils::Id settingsId);
};

} // namespace Internal
} // namespace Autotest
