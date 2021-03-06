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

#include <clangsupport_global.h>

#include "processhandle.h"

#include <utils/environment.h>
#include <utils/temporarydirectory.h>

#include <QStringList>

#include <future>
#include <memory>

QT_BEGIN_NAMESPACE
class QTemporaryDir;
QT_END_NAMESPACE

namespace Utils {
class Environment;
class QtcProcess;
}

namespace ClangBackEnd {

class CLANGSUPPORT_EXPORT ProcessCreator
{
public:
    ProcessCreator();

    void setTemporaryDirectoryPattern(const QString &temporaryDirectoryPattern);
    void setProcessPath(const QString &m_processPath);
    void setArguments(const QStringList &m_arguments);
    void setEnvironment(const Utils::Environment &environment);
    void setObserver(QObject *m_observer);

    std::future<QProcessUniquePointer> createProcess() const;

    const QTemporaryDir &temporaryDirectory() const;
    void resetTemporaryDirectory();

private:
    void checkIfProcessPathExists() const;
    void checkIfProcessWasStartingSuccessful(Utils::QtcProcess *process) const;
    [[noreturn]] void dispatchProcessError(Utils::QtcProcess *process) const;
    void postProcessStartedEvent() const;
    [[noreturn]] void throwProcessException(const QString &message) const;

    Utils::Environment processEnvironment() const;

private:
    std::unique_ptr<Utils::TemporaryDirectory> m_temporaryDirectory;
    QString m_processPath;
    QString m_temporaryDirectoryPattern;
    QStringList m_arguments;
    Utils::Environment m_environment;
    QObject *m_observer = nullptr;
};

} // namespace ClangBackEnd
