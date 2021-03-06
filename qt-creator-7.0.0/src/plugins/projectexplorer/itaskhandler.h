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

#include "projectexplorer_export.h"
#include "task.h"

#include <utils/id.h>

#include <QObject>
#include <QString>

QT_BEGIN_NAMESPACE
class QAction;
QT_END_NAMESPACE

namespace ProjectExplorer {

class PROJECTEXPLORER_EXPORT ITaskHandler : public QObject
{
    Q_OBJECT

public:
    explicit ITaskHandler(bool isMultiHandler = false);
    ~ITaskHandler() override;

    virtual bool isDefaultHandler() const { return false; }
    virtual bool canHandle(const Task &) const { return m_isMultiHandler; }
    virtual void handle(const Task &);       // Non-multi-handlers should implement this.
    virtual void handle(const Tasks &tasks); // Multi-handlers should implement this.
    virtual Utils::Id actionManagerId() const { return Utils::Id(); }
    virtual QAction *createAction(QObject *parent) const = 0;

    bool canHandle(const Tasks &tasks) const;

private:
    const bool m_isMultiHandler;
};

} // namespace ProjectExplorer
