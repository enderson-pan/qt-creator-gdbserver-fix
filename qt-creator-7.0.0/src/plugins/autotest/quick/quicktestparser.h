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

#include "../itestparser.h"

#include <qmljs/qmljsdocument.h>

#include <QFileSystemWatcher>

namespace Autotest {
namespace Internal {

class QuickTestParseResult : public TestParseResult
{
public:
    explicit QuickTestParseResult(ITestFramework *framework) : TestParseResult(framework) {}
    TestTreeItem *createTestTreeItem() const override;
};

class QuickTestParser : public QObject, public CppParser
{
    Q_OBJECT
public:
    explicit QuickTestParser(ITestFramework *framework);
    void init(const Utils::FilePaths &filesToParse, bool fullParse) override;
    void release() override;
    bool processDocument(QFutureInterface<TestParseResultPtr> &futureInterface,
                         const Utils::FilePath &fileName) override;
    Utils::FilePath projectFileForMainCppFile(const Utils::FilePath &fileName) const;
private:
    bool handleQtQuickTest(QFutureInterface<TestParseResultPtr> &futureInterface,
                           CPlusPlus::Document::Ptr document, ITestFramework *framework);
    void handleDirectoryChanged(const QString &directory);
    void doUpdateWatchPaths(const QStringList &directories);
    QString quickTestName(const CPlusPlus::Document::Ptr &doc) const;
    QList<QmlJS::Document::Ptr> scanDirectoryForQuickTestQmlFiles(const QString &srcDir);
    QmlJS::Snapshot m_qmlSnapshot;
    QHash<Utils::FilePath, Utils::FilePath> m_proFilesForQmlFiles;
    QFileSystemWatcher m_directoryWatcher;
    QMap<QString, QMap<QString, QDateTime> > m_watchedFiles;
    QMap<Utils::FilePath, Utils::FilePath> m_mainCppFiles;
};

} // namespace Internal
} // namespace Autotest
