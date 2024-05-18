#include <fmt/core.h>
#include <string>
#include <filesystem>
#include <iostream>
#include "../api/html_writer.hpp"


namespace html_writer {

    void OpenDocument(){
        fmt::print("<!DOCTYPE html>\n"
                "<html>\n"
                "<head>\n"
                "<title>Computer Vision Model Inferences</title>\n"
                "</head>\n"
                "<body>\n");
    }

    void CloseDocument(){
        fmt::print("</body>\n"
                "</html>\n");
    }

    void AddCSSStyle(const std::string & stylesheet){
        fmt::print("<link rel=\"stylesheet\" type=\"text/css\" href=\"{}\">\n", stylesheet);
    }

    void AddTitle(const std::string & title){
        fmt::print("<title>{}</title>\n", title);
    }

    void OpenBody(){
        fmt::print("<body>\n");
    }

    void CloseBody(){
        fmt::print("</body>\n");
    }

    void OpenRow(){
        fmt::print("<div class=\"row\">\n");
    }

    void CloseRow(){
        fmt::print("</div>\n");
    }

    void AddImage(const std::string& img_path, float score, bool highlight){
        //check file type is png or jpg
        std::filesystem::path path(img_path);
        std::string extension = path.extension();
        if(extension != ".png" && extension != ".jpg"){
            std::cerr << "Error: JPG or PNG file types are required" << img_path << " not supported \n";
            return;
        }

        std::string filename = path.filename();

        std::string format_score = fmt::format("{:.2f}", score);


        std::string highlightClass = highlight ? "highlight" : "";
        fmt::print("<div class=\"image {}\">\n", highlightClass);
        fmt::print("<h2>{}</h2>\n", filename);
        fmt::print("<img src=\"{}\" alt=\"{}\">\n", img_path, filename);
        fmt::print("<p>Score: {}</p>\n", format_score);
        fmt::print("</div>\n");
    }

}