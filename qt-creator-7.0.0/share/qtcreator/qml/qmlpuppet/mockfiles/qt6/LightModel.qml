/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
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

import QtQuick 6.0
import QtQuick3D 6.0
import LightUtils 1.0

Model {
    id: lightModel

    property alias geometryName: lightGeometry.name // Name must be unique for each geometry
    property alias geometryType: lightGeometry.lightType
    property Material material
    readonly property bool _edit3dLocked: true // Make this non-pickable

    function updateGeometry()
    {
        lightGeometry.update();
    }

    scale: Qt.vector3d(50, 50, 50)

    geometry: lightGeometry
    materials: [ material ]

    LightGeometry {
        id: lightGeometry
    }
}
