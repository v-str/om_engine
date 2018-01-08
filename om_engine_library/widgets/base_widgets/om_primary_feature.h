#ifndef OM_PRIMARY_FEATURE_H
#define OM_PRIMARY_FEATURE_H

#include <memory>

class WidgetAnimator;

namespace om_widgets {

class OmPrimaryFeature {
 public:

private:
    std::unique_ptr<WidgetAnimator> animator_;
};
}

#endif  // OM_PRIMARY_FEATURE_H
