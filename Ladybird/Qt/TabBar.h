/*
 * Copyright (c) 2024, Tim Flynn <trflynn89@serenityos.org>
 * Copyright (c) 2024, Jamie Mansfield <jmansfield@cadixdev.org>
 * Copyright (c) 2024, Sam Atkins <sam@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <QProxyStyle>
#include <QPushButton>
#include <QTabBar>
#include <QTabWidget>

class QContextMenuEvent;
class QEvent;
class QIcon;
class QWidget;

namespace Ladybird {

class TabBar : public QTabBar {
    Q_OBJECT

public:
    explicit TabBar(QWidget* parent = nullptr);

    virtual QSize tabSizeHint(int index) const override;
    virtual void contextMenuEvent(QContextMenuEvent* event) override;
};

class TabWidget : public QTabWidget {
    Q_OBJECT

public:
    explicit TabWidget(QWidget* parent = nullptr);
};

class TabBarButton : public QPushButton {
    Q_OBJECT

public:
    explicit TabBarButton(QIcon const& icon, QWidget* parent = nullptr);

protected:
    bool event(QEvent* event);
};

class TabStyle : public QProxyStyle {
    Q_OBJECT

public:
    explicit TabStyle(QObject* parent = nullptr);

    virtual QRect subElementRect(QStyle::SubElement, QStyleOption const*, QWidget const*) const override;
};

}
