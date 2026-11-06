#ifndef SOLVER_BRIDGE_HPP
#define SOLVER_BRIDGE_HPP

#include <vector>
#include <string>
#include <memory>

struct NarrativeState {
    std::string active_genre;
    unsigned int current_act;       // 1, 2, or 3
    bool logical_contradiction;
};

class SolverBridge {
private:
    NarrativeState current_context;
    std::vector<std::vector<int>> clause_matrix;

public:
    SolverBridge();
    ~SolverBridge() = default;

    bool ParseThematicConstraints(const std::string& custom_taste_profile);
    void MapStateToVariables(int variable_id, bool active_state);
    bool AssertPlotConsistency();
};

#endif // SOLVER_BRIDGE_HPP
