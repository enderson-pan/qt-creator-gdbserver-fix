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

#include <QObject>
#include <QString>
#include <QSize>
#include <QVariant>

#include "itemlibraryinfo.h"

namespace QmlDesigner {

class ItemLibraryItem: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariant itemLibraryEntry READ itemLibraryEntry FINAL)
    Q_PROPERTY(QString itemName READ itemName FINAL)
    Q_PROPERTY(QString itemLibraryIconPath READ itemLibraryIconPath FINAL)
    Q_PROPERTY(bool itemVisible READ isVisible NOTIFY visibilityChanged FINAL)
    Q_PROPERTY(QString componentPath READ componentPath FINAL)
    Q_PROPERTY(bool itemUsable READ isUsable FINAL)
    Q_PROPERTY(QString itemRequiredImport READ requiredImport FINAL)
    Q_PROPERTY(QString itemComponentSource READ componentSource FINAL)

public:
    ItemLibraryItem(const ItemLibraryEntry &itemLibraryEntry, bool isImported, QObject *parent);
    ~ItemLibraryItem() override;

    QString itemName() const;
    QString typeName() const;
    QString itemLibraryIconPath() const;
    QString componentPath() const;
    QString requiredImport() const;
    QString componentSource() const;

    bool setVisible(bool isVisible);
    bool isVisible() const;
    bool isUsable() const;

    QVariant itemLibraryEntry() const;

signals:
    void visibilityChanged();

private:
    ItemLibraryEntry m_itemLibraryEntry;
    bool m_isVisible = true;
    bool m_isUsable = false;
};

} // namespace QmlDesigner
