#include <iostream>
#include <cinderbox/cinderbox.hh>
#include <librapid/librapid.hpp>

namespace lrc = librapid;

class MyApp : public ci::app::App {
public:
    MyApp() = default;

    void setup() override {
        setFrameRate(120);				  // Max 120fps
        ci::gl::enableVerticalSync(true); // VSync if possible
    }

    void draw() override {
        ci::gl::clear(ci::ColorA(0.1, 0.1, 0.1));
    }
};

CINDER_APP(MyApp, ci::app::RendererGl(ci::app::RendererGl::Options().msaa(4)))
