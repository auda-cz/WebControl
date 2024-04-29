#include "./crow_all.h"
#include <cstdlib>

int main() {
    crow::SimpleApp app;

    std::unordered_set<std::string> validActions{"P1_on", "P1_off", "P2_on", "P2_off", "P3_on", "P3_off", "All_on", "All_off"};
    CROW_ROUTE(app, "/run/<string>")
    ([&validActions](const std::string& deviceAction) -> crow::response {
        if (validActions.find(deviceAction) == validActions.end()) {
            return crow::response(400, "Invalid device action specified.");
        }

        std::ostringstream cmdStream;
        // Construct the command safely
        cmdStream << "sudo RemoteControl /RCSeq/" << deviceAction << " " << 4;
        std::string command = cmdStream.str();

        // Execute the command
        int result = system(command.c_str());
        if (result == 0) {
            return crow::response("Command executed successfully");
        } else {
            return crow::response(500, "Command execution failed");
        }
    });

    app.port(1919).run();
}