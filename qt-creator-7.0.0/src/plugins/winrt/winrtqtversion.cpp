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

#include "winrtqtversion.h"

#include "winrtconstants.h"

#include <coreplugin/featureprovider.h>
#include <qtsupport/qtsupportconstants.h>

namespace WinRt {
namespace Internal {

QString WinRtQtVersion::description() const
{
    return tr("Windows Runtime");
}

QSet<Utils::Id> WinRtQtVersion::availableFeatures() const
{
    QSet<Utils::Id> features = QtSupport::QtVersion::availableFeatures();
    features.insert(QtSupport::Constants::FEATURE_MOBILE);
    features.remove(QtSupport::Constants::FEATURE_QT_CONSOLE);
    features.remove(Utils::Id::versionedId(QtSupport::Constants::FEATURE_QT_QUICK_CONTROLS_PREFIX, 1));
    features.remove(QtSupport::Constants::FEATURE_QT_WEBKIT);
    return features;
}

QSet<Utils::Id> WinRtQtVersion::targetDeviceTypes() const
{
    return {Constants::WINRT_DEVICE_TYPE_LOCAL, Constants::WINRT_DEVICE_TYPE_EMULATOR};
}


// Factory

WinRtQtVersionFactory::WinRtQtVersionFactory()
{
    setQtVersionCreator([] { return new WinRtQtVersion; });
    setSupportedType(Constants::WINRT_WINRTQT);
    setRestrictionChecker([](const SetupData &setup) { return setup.platforms.contains("winrt"); });
    setPriority(10);
}

} // Internal
} // WinRt
