#ifndef ASSET_CURATOR_HPP
#define ASSET_CURATOR_HPP

#include <string>
#include <vector>
#include <unordered_map>

struct EngineeringConstraints {
    float physical_mass_kg;
    float thermal_conductivity;
    bool rigid_body_dynamics;
};

struct ScientificAssetMetadata {
    std::string asset_id;
    std::string gltf_binary_path;
    EngineeringConstraints physics_track;
};

class AssetCurator {
private:
    std::unordered_map<std::string, ScientificAssetMetadata> scientific_catalog;
    std::vector<std::string> active_scene_manifest;

public:
    AssetCurator();
    ~AssetCurator() = default;

    // Registers structural assets into the scientific inventory
    void RegisterCatalogAsset(const std::string& id, const std::string& path, const EngineeringConstraints& constraints);
    
    // Extracts and loads made-to-measure assets on-the-fly based on 3SAT solver mapping variables
    bool ExtractTargetAssets(const std::vector<int>& verified_variables);
    
    // Compiles the current active scene parameters into a unified frame manifest
    std::vector<std::string> CompileSceneManifest();
};

#endif // ASSET_CURATOR_HPP
