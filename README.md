# CinderBox

CinderBox provides a simple, lightweight set of helper functions and classes
over [Cinder](https://github.com/cinder/Cinder), creating a more friendly experience with a faster setup-time, so you
can spend more time coding and less time preparing.

### Packages contained in CinderBox
1. ``Cinder``
2. ``librapid``
    - ``{fmt}``
    - ``scnlib``
    - ``MPIR``
    - ``MPFR``

# Usage

Just `add_subdirectory(cinderbox)` and `target_link_libraries(MyProject PUBLIC cinderbox)` in your `CMakeLists.txt`

## Linux usage

On Linux, you'll need to install the following packages for Cinder to work

```
sudo apt-get install libxcursor-dev \
libxrandr-dev \
libxinerama-dev \
libxi-dev \
libgl1-mesa-dev \
libglu1-mesa-dev \
zlib1g-dev \
libfontconfig1-dev \
libmpg123-dev \
libsndfile1 \
libsndfile1-dev \
libpulse-dev \
libasound2-dev \
libcurl4-gnutls-dev \
libgstreamer1.0-dev \
libgstreamer-plugins-bad1.0-dev \
libgstreamer-plugins-base1.0-dev \
gstreamer1.0-libav \
gstreamer1.0-alsa \
gstreamer1.0-pulseaudio \
gstreamer1.0-plugins-bad \
libboost-filesystem-dev
```
