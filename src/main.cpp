#include "crow_all.h"         // Crow framework
#include "campus_connect.h"
#include "messaging.h"
#include "group_management.h"

int main() {
    CampusConnect cc;         // Our in-memory users
    Messaging msg;            // Our messages
    Group devs("Developers"); // Example group

    crow::SimpleApp app;      // Create the server

    // ===== ROUTE: create user =====
    CROW_ROUTE(app, "/create_user").methods("POST"_method)
    ([&cc](const crow::request& req){
        auto body = crow::json::load(req.body);
        if(!body) return crow::response(400, "Invalid JSON");

        std::string name = body["name"].s();
        std::string email = body["email"].s();
        bool ok = cc.createUser(name, email);

        crow::json::wvalue res;
        res["success"] = ok;
        return crow::response{res};
    });

    // ===== ROUTE: add skill =====
    CROW_ROUTE(app, "/add_skill").methods("POST"_method)
    ([&cc](const crow::request& req){
        auto body = crow::json::load(req.body);
        std::string email = body["email"].s();
        std::string skill = body["skill"].s();
        bool ok = cc.addSkill(email, skill);

        crow::json::wvalue res;
        res["success"] = ok;
        return crow::response{res};
    });

    // ===== ROUTE: list users =====
    CROW_ROUTE(app, "/list_users")
    ([&cc](){
        crow::json::wvalue res;
        res["users"] = cc.listUsers();
        return crow::response{res};
    });

    // Start server on localhost:18080
    app.port(18080).multithreaded().run();
}
