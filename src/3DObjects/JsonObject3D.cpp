#include "JsonObject3D.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>

JsonObject3D::JsonObject3D(const std::string &filename) {
    try {
        std::ifstream ifs("resources/objects/" + filename + ".json");
        nlohmann::json data = nlohmann::json::parse(ifs);

        int points_used = 0;

        for (auto &row : data) {
            for (auto &vert : row["verts"]) {
                points.push_back(new Vector3D{vert[0], vert[1], vert[2]});
                points_used++;
            }

            for (int i = 1; i < row["verts"].size(); ++i) {
                lines.push_back(new Line{points[points_used - i], points[points_used - i - 1]});
            }

            lines.push_back(new Line{points[points_used - 1], points[points_used - row["verts"].size()]});
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}