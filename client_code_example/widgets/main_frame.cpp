#include <main_frame.h>

#include <QString>
#include <QVector>

#include <main_frame_geometries.h>
#include <widget_customizer.h>
#include <writable_matcher.h>

using namespace client_code;
using namespace om_animation;
using namespace scaling;
using namespace om_widgets;

MainFrame::MainFrame(QWidget *parent, bool is_widget_open)
    : OmFrame(parent, is_widget_open),
      title_frame_(new TitleButtonFrame(this)),
      work_frame_(new WorkButtonFrame(this)),
      main_label_(new MainLabel(this)),
      main_label_text_setter_(new MainLabelTextSetter(main_label_, this)) {
  SetWidgets();
  SetConnections();
}

MainFrame::~MainFrame() {}

void MainFrame::ModifyGeometry(const QRect &initial_geometry,
                               const DeltaSize &delta_size) {
  OmFrame::ModifyGeometry(initial_geometry, delta_size);
  title_frame_->ScaleButtonFrame(delta_size);
  work_frame_->ScaleWorkFrame(delta_size);
  main_label_->ScaleMainLabel(delta_size);
}

void MainFrame::SetWidgets() {
  QVector<QString> text_animation_list = {"QLabel", "QPushButton", "QLineEdit",
                                          "om_widgets::OmButton",
                                          "client_code::MainLabel"};

  WritableMatcher::SetWritableWidgets(text_animation_list);

  resize(500, 300);
}

void MainFrame::SetConnections() {
  connect(title_frame_->OpenButton(), SIGNAL(clicked(bool)), main_label_,
          SLOT(Open()));
  connect(title_frame_->CloseButton(), SIGNAL(clicked(bool)), main_label_,
          SLOT(Close()));
  connect(title_frame_->OpenButton(), SIGNAL(clicked(bool)), work_frame_,
          SLOT(Open()));
  connect(title_frame_->CloseButton(), SIGNAL(clicked(bool)), work_frame_,
          SLOT(Close()));
  connect(title_frame_->AboutButton(), SIGNAL(clicked(bool)),
          main_label_text_setter_, SLOT(SetAbout()));
  connect(title_frame_->ClearButton(), SIGNAL(clicked(bool)), main_label_,
          SLOT(Clear()));
}
