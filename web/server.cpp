#include "../httplib.h"

int main()
{
    using namespace httplib;

    Server svr;

    svr.Get("/", [](const Request& req, Response& res) {
        res.set_content("main.html", "text/html");
    });



    svr.Get("/stop", [&](const Request& req, Response& res) {
        svr.stop();
    });

    svr.listen("localhost", 8080);
}