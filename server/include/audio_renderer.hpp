#ifndef AUDIO_RENDERER_HPP
#define AUDIO_RENDERER_HPP

#include <vector>
#include <string>

struct SpatialVector3D {
    float x;
    float y;
    float z;
};

class AudioRenderer {
private:
    float mastering_gain_db;
    unsigned int active_output_channels;

public:
    AudioRenderer();
    ~AudioRenderer() = default;

    void ProcessAudioObjectPosition(const SpatialVector3D& source_pos, const SpatialVector3D& camera_pos);
    std::vector<uint8_t> SynthesizeAudioFrameBlock();
};

#endif // AUDIO_RENDERER_HPP
