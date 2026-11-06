#include "../include/asset_curator.hpp"
#include <iostream>

AssetCurator::AssetCurator() {
    // Initialize the catalog with a default engineering baseline
    EngineeringConstraints horizon_specs = {5000.0f, 0.05f, false};
    RegisterCatalogAsset("horizon_mesh_01", "Assets/Models/infinite_horizon.glb", horizon_specs);
}

void AssetCurator::RegisterCatalogAsset(const std::string& id, const std::string& path, const EngineeringConstraints& constraints) {
    ScientificAssetMetadata metadata = {id, path, constraints};
    scientific_catalog[id] = metadata;
    std::cout << "[Asset Curator] Registered asset '" << id << "' with physics and structural tracks.\n";
}

bool AssetCurator::ExtractTargetAssets(const std::vector<int>& verified_variables) {
    if (verified_variables.empty()) {
        std::cerr << "[Curator Warning] Empty solver variable matrix passed to asset layer.\n";
        return false;
    }

    std::cout << "[Asset Curator] Extracting and verifying assets against " << verified_variables.size() << " logical clauses...\n";
    
    // Simulate mapping your 3SAT variable output directly to physical asset properties
    for (int var : verified_variables) {
        if (var == 101) { // Example variable index mapping to environment geometry
            active_scene_manifest.push_back("horizon_mesh_01");
            std::cout << "[Asset Curator] Variable 101 True -> Hot-swapping 'horizon_mesh_01' into rendering pipeline.\n";
        }
    }
    
    return !active_scene_manifest.empty();
}

std::vector<std::string> AssetCurator::CompileSceneManifest() {
    std::cout << "[Asset Curator] Compiling master scene manifest for the neural rendering engine.\n";
    return active_scene_manifest;
}
