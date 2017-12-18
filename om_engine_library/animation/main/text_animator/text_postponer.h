#ifndef TEXT_POSTPONER_H
#define TEXT_POSTPONER_H

#include <QLabel>
#include <QObject>
#include <QString>
#include <QTimer>

class TextPostponer : public QObject {
  Q_OBJECT
 public:
  explicit TextPostponer(QObject* parent = nullptr,
                         unsigned int interval_postpone_msec = 10);
  ~TextPostponer();

  void RunTextPosponing(QLabel* postpone_label);
  void ResetIntervalPostpone(unsigned int interval_postpone_msec);
  void SetPostponeText(const QString& postpone_text);

 private slots:
  void Run();

 private:
  void Reset();
  bool IsStringEnd() const;

  QTimer* timer_ = nullptr;
  QLabel* postpone_label_ = nullptr;
  QString postpone_text_;
  QString current_text_;
  unsigned int interval_postpone_msec_;
  unsigned int symbol_count_ = 0;
};

#endif  // TEXT_POSTPONER_H
