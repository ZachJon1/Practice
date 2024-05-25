#include "html_writer.hpp"
#include <fstream>
#include <streambuf>
#include <iostream>

int main(){
    std::ofstream html_file("test.html");

    std::streambuf* stream_buffer_cout = std::cout.rdbuf();
    std::cout.rdbuf(html_file.rdbuf());

    html_writer::OpenDocument();
    html_writer::AddTitle("CV Web App");
    html_writer::AddCSSStyle("style.css");
    html_writer::OpenBody();
    html_writer::OpenRow();
    html_writer::AddImage("../web_app/data/000000.png", 0.9f, true);
    html_writer::AddImage("../web_app/data/000100.png", 0.60f, false);
    html_writer::CloseRow();
    html_writer::OpenRow();
    html_writer::AddImage("../web_app/data/000200.png", 0.60f, false);
    html_writer::AddImage("../web_app/data/000300.png", 0.60f, false);
    html_writer::CloseRow();
    html_writer::CloseBody();
    html_writer::CloseDocument();

    std::cout.rdbuf(stream_buffer_cout);

    return 0;

}