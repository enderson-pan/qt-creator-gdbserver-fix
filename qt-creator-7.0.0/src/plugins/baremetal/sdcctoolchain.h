/****************************************************************************
**
** Copyright (C) 2019 Denis Shienkov <denis.shienkov@gmail.com>
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

#include <projectexplorer/abi.h>
#include <projectexplorer/toolchain.h>
#include <projectexplorer/toolchainconfigwidget.h>

QT_BEGIN_NAMESPACE
class QPlainTextEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

namespace Utils {
class FilePath;
class PathChooser;
}

namespace ProjectExplorer { class AbiWidget; }

namespace BareMetal {
namespace Internal {

// SdccToolChain

class SdccToolChain final : public ProjectExplorer::ToolChain
{
    Q_DECLARE_TR_FUNCTIONS(SdccToolChain)

public:
    MacroInspectionRunner createMacroInspectionRunner() const final;

    Utils::LanguageExtensions languageExtensions(const QStringList &cxxflags) const final;
    Utils::WarningFlags warningFlags(const QStringList &cxxflags) const final;

    BuiltInHeaderPathsRunner createBuiltInHeaderPathsRunner(
            const Utils::Environment &) const final;
    void addToEnvironment(Utils::Environment &env) const final;
    QList<Utils::OutputLineParser *> createOutputParsers() const final;

    std::unique_ptr<ProjectExplorer::ToolChainConfigWidget> createConfigurationWidget() final;

    bool operator ==(const ToolChain &other) const final;

    Utils::FilePath makeCommand(const Utils::Environment &env) const final;

private:
    SdccToolChain();

    friend class SdccToolChainFactory;
    friend class SdccToolChainConfigWidget;
};

// SdccToolChainFactory

class SdccToolChainFactory final : public ProjectExplorer::ToolChainFactory
{
public:
    SdccToolChainFactory();

    ProjectExplorer::Toolchains autoDetect(
            const ProjectExplorer::ToolchainDetector &detector) const final;

private:
    ProjectExplorer::Toolchains autoDetectToolchains(const Candidates &candidates,
            const ProjectExplorer::Toolchains &alreadyKnown) const;
    ProjectExplorer::Toolchains autoDetectToolchain(
            const Candidate &candidate, Utils::Id language) const;
};

// SdccToolChainConfigWidget

class SdccToolChainConfigWidget final : public ProjectExplorer::ToolChainConfigWidget
{
    Q_OBJECT

public:
    explicit SdccToolChainConfigWidget(SdccToolChain *tc);

private:
    void applyImpl() final;
    void discardImpl() final { setFromToolchain(); }
    bool isDirtyImpl() const final;
    void makeReadOnlyImpl() final;

    void setFromToolchain();
    void handleCompilerCommandChange();

    Utils::PathChooser *m_compilerCommand = nullptr;
    ProjectExplorer::AbiWidget *m_abiWidget = nullptr;
    ProjectExplorer::Macros m_macros;
};

} // namespace Internal
} // namespace BareMetal
