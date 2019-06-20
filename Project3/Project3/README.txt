This is Nathan Pierson's submission for Project 3, the appliance manager client.

There are three header files and four source code files:

Appliance.h
AppliancePtr.h
PtrList.h

Appliance.cpp
AppliancePtr.cpp
PtrList.cpp
ShopClient.cpp

Running the main() method in ShopClient.cpp should create the command-line interface as specified in the homework. The user should be advised that the commands are case-sensitive, so that "l" will list all the appliances but "L" will not.

The appliance files are stored in the \appliances\ folder. Each file is named <ID>.txt, and has a body consisting of the type (an integer 0, 1, or 2), the manufacturer, the price in cents, and strings corresponding to picture filepaths (if any). These values are newline separated. The file parser assumes that if the file exists and is nonempty, then it is complete. Of the sample files included, there are a variety. Some IDs have no file at all. Some have an empty file. Some have a file with no pictures, and some have a file with pictures.

The AppliancePtr is slightly overzealous about keeping memory use down: It only allows *one* instance of Appliance in memory at a time, not three. You could create a version that allows up three by, instead of having a single inMemory pointer, maintaining a dynamic array of which AppliancePtrs currently are in memory and choosing which one to deallocate whenever a new one needs space. However, the simpler version I implemented does conform to the requirement that no more than three instances are ever in memory at once.

If the AppliancePtr corresponds to an ID that has no associated .txt file, operator* will throw a null pointer error. The client is careful not to let this occur, but AppliancePtr itself does not protect against this possibility.

This project was created using Visual Studio Community on Windows 10, using the default C++ project settings. To my knowledge, it doesn't use any C++14 or C++17 features.