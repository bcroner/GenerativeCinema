# GenerativeCinema

Generative Cinema (GC) - Automatic and custom generation of unique, novel streaming movies based on direct user taste profiling. By utilizing a high-performance bare-metal execution architecture, GC shifts the financial burden of streaming entirely to a one-time upfront hardware layer, making continuous media consumption dramatically more affordable.

Licensed under the permissive **MIT License**.

## System Architecture Overview

Traditional streaming networks rely on static, cloud-hosted content delivery infrastructure that incurs massive licensing overhead and scaling costs. Generative Cinema replaces pre-rendered media catalogs with a real-time, logic-driven production engine. 

The framework is divided into two primary environments:

### 1. The Server Pipeline (The Brains Tier)
The server operates on bare-metal hardware clusters running automated R&D tasks 24/7. It is composed of three interconnected open-source engine components:
*   **The Narrative Consistency Bridge (`server/src/solver_bridge.cpp`):** Translates dynamic plot lines, character properties, and dramatic milestones into standard propositional logic variables. It maps these inputs straight to your core parallelized **3SAT solver** loop to verify that branching paths retain 100% world-state consistency without logical contradictions.
*   **The Asset Curator (`server/src/asset_curator.cpp`):** Functions as the automated director. It maps the verified variable arrays from the logic solver to a scientific inventory, dynamically extracting, hot-swapping, and loading made-to-measure 3D environment components, asset meshes, and physics profiles on the fly.
*   **The Geometry Audio Renderer (`server/src/audio_renderer.cpp`):** Calculates delta distances and vector coordinates across virtual 3D spaces to procedurally synthesize native, immersive **9.1 channel spatial audio** bitstreams.

### 2. The Client Player (The Endpoint Tier)
**File:** `client/android/app/src/main/java/com/gc/player/PlaybackEngine.java`

The consumer-facing application is engineered to be exceptionally lightweight, optimized for consumer sticks and platforms like the **Amazon Fire TV Cube (3rd Gen)** and **vSeeBox v6 Max**. The client contains zero heavy rendering logic; it connects to your server's custom streaming manifests and enforces strict, raw HDMI bitstream passthrough to pass spatial audio objects directly to home theater AV receivers.

## Repository Layout

*   `server/include/`: Header definitions for the narrative bridge, curator, and spatial audio layers.
*   `server/src/`: Core C++ pipeline files, including the main HLS stream segment compiler.
*   `client/android/`: Native Android project configurations and Java playback engines.
*   `templates/cinematic_profile.json`: The AGI manifest schema for custom genre, mood, and asset generation.

## Compiling the Server Backend

The server environment uses CMake for fast, dependency-free optimization compilation:

```bash
mkdir build && cd build
cmake ..
make
./generative_cinema_server
```

## Compiling the Client Player

To build the client player path on your local development machine:

```bash
# Force the creation of nested package structures cleanly
mkdir -p client/android/app/src/main/java/com/gc/player

# Execute native Android Gradle tasks to generate the client APK
cd client/android/
./gradlew assembleDebug
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.
