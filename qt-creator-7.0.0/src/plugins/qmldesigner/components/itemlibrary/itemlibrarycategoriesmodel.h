/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
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

#include "itemlibrarymodel.h"

#include <QObject>
#include <QPointer>

namespace QmlDesigner {

class ItemLibraryCategory;

class ItemLibraryCategoriesModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ItemLibraryCategoriesModel(QObject *parent = nullptr);
    ~ItemLibraryCategoriesModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QHash<int, QByteArray> roleNames() const override;

    void addCategory(ItemLibraryCategory *category);
    void expandCategories(bool expand = true);

    const QList<QPointer<ItemLibraryCategory>> &categorySections() const;

    bool isAllCategoriesHidden() const;
    void sortCategorySections();
    void resetModel();
    void showAllCategories();
    void hideCategory(const QString &categoryName);
    void clearSelectedCategory(int categoryIndex);
    int selectFirstVisibleCategory();
    QPointer<ItemLibraryCategory> selectCategory(int categoryIndex);

private:
    void addRoleNames();

    QList<QPointer<ItemLibraryCategory>> m_categoryList;
    QHash<int, QByteArray> m_roleNames;
};

} // namespace QmlDesigner
