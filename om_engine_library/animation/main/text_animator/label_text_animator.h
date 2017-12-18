#ifndef LABEL_TEXT_ANIMATOR_H
#define LABEL_TEXT_ANIMATOR_H

#include <QLabel>
#include <QObject>
#include <QString>

class LabelTextAnimator : public QObject {
  Q_OBJECT
 public:
  explicit LabelTextAnimator(QObject* parent = nullptr);
  LabelTextAnimator(const QString& text, bool is_running, QObject* parent);
  ~LabelTextAnimator();

  void SetAnimationText(const QString& text);

 public slots:

 private:
  QString animation_text_buffer_;
  bool is_running_ = false;
};

#endif  // LABEL_TEXT_ANIMATOR_H
