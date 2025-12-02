#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using State = unsigned int; // bitmask representing facts

// --------------------
// priority queue (kept sorted by f)
// --------------------

struct Node {
    State state;
    int f; // g + h
};

std::vector<Node> open_list;

// inserts while keeping vector sorted by f
void enqueue(const Node& node) {
    open_list.push_back(node);
    int i = (int)open_list.size() - 2;
    // shift items until we find the right spot
    while (i >= 0 && open_list[i].f > node.f) {
        open_list[i + 1] = open_list[i];
        i--;
    }
    open_list[i + 1] = node;
}

// removes the lowest-f node
Node pop_front() {
    Node best = open_list.front();
    open_list.erase(open_list.begin());
    return best;
}

// --------------------
// actions
// --------------------

struct Action {
    std::string name;
    State precond; // bits that need to be set
    State add_eff; // bits to turn on
    State del_eff; // bits to clear
    int cost;
};

// checks if action can run in the given state
bool is_applicable(const Action& a, State state) {
    return (state & a.precond) == a.precond;
}

// applies add/delete effects and returns updated state
State apply_action(const Action& a, State state) {
    State s = state;
    s &= ~a.del_eff;
    s |= a.add_eff;
    return s;
}

// --------------------
// heuristic: count missing goal bits
// --------------------

int heuristic(State state, State goal_mask) {
    State missing = goal_mask & ~state;
    int h = 0;
    while (missing) {
        missing &= (missing - 1);
        h++;
    }
    return h;
}

// --------------------
// A* over logical bitmask states
// --------------------

bool astar_plan(State start,
                State goal_mask,
                const std::vector<Action>& actions,
                std::vector<int>& out_plan,
                int& out_cost) {
    
    std::map<State, int> g;            // best known g for each state
    std::map<State, State> parent;     // backpointers for reconstruction
    std::map<State, int> parent_action;

    open_list.clear();

    g[start] = 0;
    enqueue({start, heuristic(start, goal_mask)});

    while (!open_list.empty()) {
        Node current = pop_front();
        State s = current.state;

        auto itg = g.find(s);
        if (itg == g.end()) continue;

        int g_here = itg->second;
        int best_f = g_here + heuristic(s, goal_mask);

        // discard outdated queue entries
        if (current.f != best_f) continue;

        // check goal condition
        if ((s & goal_mask) == goal_mask) {
            out_plan.clear();
            out_cost = g_here;

            // rebuild action path
            State t = s;
            while (parent.find(t) != parent.end()) {
                int act_id = parent_action[t];
                out_plan.push_back(act_id);
                t = parent[t];
            }
            std::reverse(out_plan.begin(), out_plan.end());
            return true;
        }

        // expand neighbors
        for (int i = 0; i < (int)actions.size(); ++i) {
            const Action& a = actions[i];
            if (!is_applicable(a, s)) continue;

            State ns = apply_action(a, s);
            int tentative_g = g_here + a.cost;

            auto it_ng = g.find(ns);
            if (it_ng == g.end() || tentative_g < it_ng->second) {
                g[ns] = tentative_g;
                parent[ns] = s;
                parent_action[ns] = i;

                enqueue({ns, tentative_g + heuristic(ns, goal_mask)});
            }
        }
    }

    return false;
}

// test example

void print_state(State state) {
    std::cout << "State facts:\n";
    if (state & (1u << 0)) std::cout << "- robot in room A\n";
    if (state & (1u << 1)) std::cout << "- robot in room B\n";
    if (state & (1u << 2)) std::cout << "- box in room A\n";
    if (state & (1u << 3)) std::cout << "- box in room B\n";
}

int main() {
    // bit assignments for readabilty
    const State ROBOT_IN_A = 1u << 0;
    const State ROBOT_IN_B = 1u << 1;
    const State BOX_IN_A   = 1u << 2;
    const State BOX_IN_B   = 1u << 3;

    State start = ROBOT_IN_A | BOX_IN_A;
    State goal_mask = BOX_IN_B;

    std::vector<Action> actions;

    actions.push_back({
        "Move robot from A to B",
        ROBOT_IN_A,
        ROBOT_IN_B,
        ROBOT_IN_A,
        1
    });

    actions.push_back({
        "Move robot from B to A",
        ROBOT_IN_B,
        ROBOT_IN_A,
        ROBOT_IN_B,
        1
    });

    actions.push_back({
        "Push box from A to B",
        ROBOT_IN_A | BOX_IN_A,
        ROBOT_IN_B | BOX_IN_B,
        ROBOT_IN_A | BOX_IN_A,
        1
    });

    actions.push_back({
        "Push box from B to A",
        ROBOT_IN_B | BOX_IN_B,
        ROBOT_IN_A | BOX_IN_A,
        ROBOT_IN_B | BOX_IN_B,
        1
    });

    std::cout << "Start:\n";
    print_state(start);
    std::cout << "\nGoal: box should be in room B\n\n";

    std::vector<int> plan;
    int total_cost = 0;

    bool ok = astar_plan(start, goal_mask, actions, plan, total_cost);

    if (!ok) {
        std::cout << "No plan found\n";
        return 0;
    }

    std::cout << "Plan found (cost = " << total_cost << "):\n";
    State current = start;
    for (int i = 0; i < (int)plan.size(); ++i) {
        const Action& a = actions[plan[i]];
        std::cout << i + 1 << ". " << a.name << "\n";
        current = apply_action(a, current);
    }

    std::cout << "\nFinal state after plan:\n";
    print_state(current);

    return 0;
}