#include <string>
#include <vector>
#include "image_browser.hpp"
#include <fmt/core.h>
#include "html_writer.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace image_browser{

    void AddFullRow(const ImageRow &row, bool first_row){
        std::cout << "Adding row: ";
        html_writer::OpenRow();
        for (int i = 0; i< 3; ++i){
            const auto& [image_path, score] = row[i];
            html_writer::AddImage(image_path, score, first_row && i == 0);
        }
        html_writer::CloseRow();
    }

    void CreateImageBrowser(const std::string &title, const std::string &stylesheet, const std::vector<ImageRow> &rows){
        std::cout << "Entering CreateImageBrowser function" << std::endl;
        html_writer::OpenDocument();
        html_writer::AddTitle(title);
        html_writer::AddCSSStyle(stylesheet);
        html_writer::OpenBody();

        bool first_row = true;
        for(const auto& row: rows){
            AddFullRow(row, first_row);
            first_row = false;
        
        }

        //sample rows

        html_writer::CloseBody();
        html_writer::CloseDocument();

    }

}


int main() {
    std::vector<image_browser::ImageRow> rows = {
        {
            image_browser::ScoredImage{"../web_app/data/000000.png", 0.92},
            image_browser::ScoredImage{"../web_app/data/000200.png", 0.85},
            image_browser::ScoredImage{"../web_app/data/000300.png", 0.78}
        },
        {
            image_browser::ScoredImage{"../web_app/data/000400.png", 0.71},
            image_browser::ScoredImage{"../web_app/data/000500.png", 0.63},
            image_browser::ScoredImage{"../web_app/data/000600.png", 0.57}
        }
    };

    std::ofstream html_file("image_browser.html");
    if (html_file.is_open()) {
        std::streambuf* cout_buffer = std::cout.rdbuf(html_file.rdbuf());
        html_file << "<!-- Start of HTML content -->\n";
        image_browser::CreateImageBrowser("Computer Vision Model Inferences", "styles.css", rows);
        html_file << "<!-- End of HTML content -->\n";
        std::cout.flush();
        std::cout.rdbuf(cout_buffer);
        html_file.close();
    } else {
        std::cerr << "Failed to open file 'image_browser.html'" << std::endl;
    }

    return 0;
}