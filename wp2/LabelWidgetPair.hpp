#ifndef WP2_LABELWIBDGETPAIR_HPP
#define WP2_LABELWIDGETPAIR_HPP

#include <Wt/WString>
#include <Wt/WCompositeWidget>

namespace Wt {
    class WFormWidget;
    class WLabel;
    class WContainerWidget;
}

namespace wp2 {

/** A label and a widget paired together automatically **/
class LabelWidgetPair : public Wt::WCompositeWidget {
private:
    Wt::WLabel* _label;
    Wt::WFormWidget* _widget;
    Wt::WContainerWidget* _root;
public:
    /// We take ownership of @param widget
    LabelWidgetPair(Wt::WContainerWidget* parent, const Wt::WString& labelName, Wt::WFormWidget* widget);
    Wt::WLabel* label() { return _label; }
    template<class WidgetClass=Wt::WFormWidget>
    WidgetClass* widget() { return dynamic_cast<WidgetClass*>(_widget); }
};

} // namespace wp2

#endif // WP2_LABELWIDGETPAIR_HPP
