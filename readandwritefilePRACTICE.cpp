#include <iostream>
#include <vector>
#include <fstream>

/*
write a c++ program that:
reads a text file containing log entries
categorized messages by log level
reports useful statistics*/

//-- Grab the text! ---
class LogEntry {
private: 
    std::string text;

public:
    void setText (const std::string& t) {
        text = t;
    }

    std::string getText() const{
        return text;
    }

};

//---collect all that shit! ----
class logBook {
private:
    std::vector<LogEntry> entries; // the "private gears" storing logs
        //this is like a bunch of boxes that you put your stuff in. nothing has to change in the code, as long as youre trying to make boxes to store your stuff

public:
    void addEntry (const std::string& str){
        LogEntry entry;
        entry.setText(str);
        entries.push_back(entry);
    }

    const std::vector<LogEntry>& getEntries() const{
        return entries;
    }

    //not necessary but allows you to see the entries are working
    //this same format will work on other entry type projcts
    void printEntries() const {
        for (const auto& entry : entries) {       // loop over all LogEntry objects in the vector
            std::cout << entry.getText() << "\n"; // use LogEntry’s getter to access the text safely
        }
    }
};


class FileReader {
public:
    //open a file with fstream
    //to store many things inside the vector use std::vector<T>
    // exp: std::vector<int> std::vector<std::string> std::<LogEntry>
    static std::vector<std::string> ReadLines (const std::string& filename){
        std::ifstream infile(filename);
        
        if (!infile) {
            throw std::runtime_error ("Invalid file selected\n");
        } // to make sure file exists

        
        std::vector<std::string> getLine; //read each line
        std::string PlaceHolderString; //temp holder

        while( std::getline( infile, PlaceHolderString)){
            getLine.push_back(PlaceHolderString); //store each line
        }
                
        //not getLine. function return type must exactly match what you return
        //so its actually ReadTheFile
        return getLine;
    }

};


int main() {
    try {
        logBook book;
        auto lines = FileReader::ReadLines("stuff.txt");

        
        for (const std::string& LINE : lines){
            book.addEntry(LINE);
        }

        for (const LogEntry& entry : book.getEntries())
        {
            std:: cout<< entry.getText() << "\n";
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    
    return 0;
}