#include <iostream>
#include <fstream>
using namespace std;
// APA Reference maker, helpful for papers -- ThatMatthewFellow
// If anything cannot be found on the website, leave it blank, and it won't be added to the reference

// Function to take an author name and format it according to APA style
string authorFormat(string name){
    // Find the length of the first name
    int fnLength = 0;
    for(char letter : name){
        if(letter != ' '){
            fnLength++;
        }
        else{
            break;
        }
    }
    // Get the first name from the name string
    string firstName = name.substr(0, fnLength);
    // Get the last name from the string
    string lastName = name.substr(fnLength+1, name.length());
    // Return the formatted name
    return lastName + ", " + firstName.substr(0,1);
}

// Function to handle all of the string input, AND the output formatting
string information(){
    // The output string where all text for the reference is compiled
    string output = "";
    // Name
    int numAuthors = 0;                                 // How many authors are there?
    cout << "How many authors? ";
    cin >> numAuthors;
    cin.ignore();
    for(int i = 0; i < numAuthors; i++){                // For all the authors, list them
        string authorName = "";
        cout << "Enter author's name (No special formatting): ";
        getline(cin,authorName);
        if(authorName.length() != 0){                   // If the author's name is greater than nothing, add it to the output
            output += authorFormat(authorName) + ". ";
        }
    }
    // Year
    string year = "";                               // What year is the article published?
    cout << "Enter year the article was published (year, month day): ";
    getline(cin,year);
    if(year.length() != 0){                             // If the year is greater than nothing, add it to the output
        output += "(" + year + "). ";
    }
    // Title
    string articleTitle = "";   // What's the title of the article?
    cout << "Enter article's title: ";
    getline(cin,articleTitle);
    if(articleTitle.length() != 0){                     // If the title is greater than nothing, add it to the output
        output += articleTitle + ". ";
    }
    // Publisher
    string publisher = "";                // Who's the publisher of the article?
    cout << "Enter article's publisher: ";
    getline(cin,publisher);
    if(publisher.length() != 0){                        // If the publisher name is greater than nothing, add it to the output
        output += publisher + ". ";
    }
    // Issue
    string issue = "";                              // What's the issue of the article?
    cout << "Enter article's issue/page numbers (issue, page-page): ";
    getline(cin, issue);
    if(issue.length() != 0){                            // If the issue number is greater than nothing, add it to the output
        output += issue + ". ";
    }
    // Url
    string url = "";                 // What's the url of the article?
    cout << "Enter article's url: ";
    getline(cin,url);
    if(url.length() != 0){                              // If the url is greater than nothing, add it to the output
        output += url;
    }
    // Output the info
    cout << "\nHere's the reference:\n";
    cout << output;
    return output;
}

// Function to add the references to a file if the user so desires
void files(){
    // Name of file
    string filename = "references.txt";
    // Make a new file with that name, if one does not already exist
    ofstream ReferenceFile(filename, ios::app);
    // Ensure the file is open
    if (!ReferenceFile.is_open()) {
        cerr << "Error opening file.\n";
        return;
    }
    // How many things to reference?
    int howMany = 0;
    cout << "How many references do you need? ";
    cin >> howMany;
    for(int i = 0; i < howMany; i++){
        // Write the reference on it
        ReferenceFile << information() << endl;
    }
    // Close the file
    ReferenceFile.close();
    cout << "\nReferences have been added to " << filename << "\n";
}

// The main program where everything is put together
int main(){
    // Choice of writing it to file or not
    char choice;
    cout << "Would you like to add the references to a file? (y/n) ";
    cin >> choice;
    // If yes, run files function
    if(choice == 'y')
        files();
    // If no, just write the references, and print them on screen
    else{
        // How many things to reference?
        int howMany = 0;
        cout << "How many references do you need? ";
        cin >> howMany;
        for(int i = 0; i < howMany; i++){
            // Write the reference on screen
            cout << information() << endl;
        }
    }
    // A faux "Press anything to continue" screen
    int done = 0;
    cout << "Type something, and hit enter, when finished: ";
    cin >> done;
    return 0;
}