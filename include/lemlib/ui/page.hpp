#include "lemlib/chassis/chassis.hpp"
#include "liblvgl/lvgl.h"
#include <string>

namespace lemlib {
namespace ui {
class Page {
    public:
        Page(lemlib::Chassis* chassis, std::string name) {
            this->chassis = chassis;
            this->name = name;
        }

        virtual void render() = 0;
        virtual void initialize() = 0;
        virtual void destroy() = 0;

        virtual std::string getName() = 0;
    protected:
        lemlib::Chassis* chassis;
        std::string name;
};
} // namespace ui
} // namespace lemlib