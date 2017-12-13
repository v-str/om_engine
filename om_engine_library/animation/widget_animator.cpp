#include <widget_animator.h>

#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QTimer>
#include <QWidget>

om_animation::WidgetAnimator::WidgetAnimator(QWidget* widget) {}

om_animation::WidgetAnimator::~WidgetAnimator() {}

void om_animation::WidgetAnimator::SetAnimation(
    unsigned int animation_duration_msec,
    WidgetAnimationType widget_animation_type,
    const QEasingCurve& curve,
    unsigned int animation_direction) {}
