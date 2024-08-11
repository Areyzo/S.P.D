#include"playbutton.hpp"
#include<raylib.h> 
using namespace std;

playbutton::playbutton()
{
    image =LoadTexture("Graphics/start1.png");
    InitialRectangle={0.0f,0.0f,(float)image.width/noofframes,(float)image.height};
    FinalRectangle ={0.0f,300,((float)image.width/noofframes)*4.0f,(float)image.height*4.0f};
}
playbutton::~playbutton()
{
    UnloadTexture(image);
}

void playbutton::draw()
{
    InitialRectangle.x=currentframe*image.width/noofframes;
    DrawTexturePro(image,InitialRectangle,FinalRectangle,Vector2{0,0},0,WHITE);
}



// void playbutton::done()
// {
//     std::string targetString = "true";
//     std::string fileString;

//     // Open the file for reading
//     std::ifstream inFile("T.txt");

//     // Check if the file opened successfully
//     if (!inFile) 
//     {
//         std::cerr << "Error opening file for reading." << std::endl;
//         std::cout << "Unable to open the file for reading.\n";
//         // Print a basic error message
//         // Exit the function if the file cannot be opened
//     }

//     // Read the content of the file
//     inFile >> fileString;

//     // Close the file after reading
//     inFile.close();

//     // Compare the string from the file with the target string
//     if (fileString == targetString) 
//     {
//         std::cout << "Strings are equal. Updating the file..." << std::endl;

//         // Open the file in write mode to update its content
//         std::ofstream outFile("T.txt");

//         // Check if the file opened successfully
//         if (!outFile) 
//         {
//             std::cerr << "Error opening file for writing." << std::endl;
//             std::cout << "Unable to open the file for writing.\n";
//             return; // Exit the function if the file cannot be opened
//         }

//         // Write "true" to the file
//         outFile << "false";

//         // Close the file after writing
//         outFile.close();


        
//     } 
//     else 
//     {
//         std::cout << "Strings are not equal. No changes made." << std::endl;
//         skip_tutoial = true;
//     }
// }

void playbutton::done()
{
    string filestring;
    string targetstring="true";
    ifstream Infile("T.txt");

    if(!Infile)
    {
        cout<<"Unable to open the file\n";
    }

    Infile>>filestring;
    Infile.close();

    if(filestring==targetstring)
    {
        cout<<"The strings are matched\n";

        ofstream OutFile("T.txt");

        if(!OutFile)
        {
            cout<<"Error loading the file\n";
        }

        OutFile<<false;

        cout<<"The value is changed to false meaning no more tutorial screen\n";

        OutFile.close();
    } 
    else
    {
        cout<<"Tutorial Screen is Skipped\n";
        skip_tutoial=true;
    }

}




