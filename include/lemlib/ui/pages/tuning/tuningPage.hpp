#pragma once

#include "lemlib/ui/page.hpp"

namespace lemlib {
namespace ui {
namespace pages {
class TuningPage : public Page {
    public:
        TuningPage();

        void destroy();

        void initialize();

        void render();

        std::string getName() { return this->name; }
    private:
        lv_obj_t* screen;

        lv_obj_t* header;

        std::string name = "Tuning";
};
} // namespace pages
} // namespace ui
} // namespace lemlib