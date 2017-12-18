#ifndef TEXT_ANIMATOR_H
#define TEXT_ANIMATOR_H

#include <QLabel>
#include <QObject>
#include <QString>
#include <QTimer>

class TextAnimator : public QObject {
  Q_OBJECT
 public:
  explicit TextAnimator(QObject* parent = nullptr,
                        unsigned int animation_delay = 10);
  ~TextAnimator();

  void RunTextAnimation(QLabel* animation_widget);
  void SetAnimationDelay(unsigned int animation_delay);
  void SetAnimationText(const QString& animation_text);

 private slots:
  void AnimateText();

 private:
  void Reset();
  bool IsStringEnd() const;

  QTimer* timer_ = nullptr;
  QLabel* animation_widget_ = nullptr;
  QString animation_text_;
  QString current_text_;
  unsigned int animation_delay_;
  unsigned int symbol_count_ = 0;
};

#endif  // TEXT_ANIMATOR_H
