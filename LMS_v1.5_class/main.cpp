#include <iostream>
#include <fstream>
#include <sstream>

class LibrarySystem {
public:
    void run() {
        int option = 0;
        
        while (option == 0) {
            // Seçenekleri göster
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Library Managment System v1.5" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << "1. REGISTER" << std::endl;
            std::cout << "2. LOGIN" << std::endl;
            std::cout << "3. EXIT" << std::endl;
            std::cout << "---------" << std::endl;
            std::cout << "==> ";

            std::cin >> option;
            if (option == 1) {
                register_user();
                option = 0;
            } else if (option == 2) {
                login();
                break;
            } else if (option == 3) {
                std::cout << "Exited The Program" << std::endl;
                break;
            } else if (option <= 0 && option > 3) {
                std::cout << "Wrong choice!" << std::endl;
                option = 0;
            }
        }
    }

private:
    void register_user() {
        std::string username, password;

        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        std::ofstream file("users.txt", std::ios_base::app);
        file << username << " " << password << std::endl;
        file.close();
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Registration Successful!" << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    int library_menu() {
        int menu = 0;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "Library Managment System v1.5" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "1. ADD BOOK" << std::endl;
        std::cout << "2. DISPLAY BOOKS" << std::endl;
        std::cout << "3. CHECK PARTICULAR BOOK" << std::endl;
        std::cout << "4. UPDATE BOOK" << std::endl;
        std::cout << "5. DELETE BOOK" << std::endl;
        std::cout << "6. EXIT" << std::endl;
        std::cout << "---------" << std::endl;
        std::cout << "==> ";
        std::cin >> menu;
        return (menu);
        
        

    }

    void login() {
        bool login_successful = false;
        bool menu_open = false;
        int menu_status = 0;
        std::string username, password;

        std::cout << "----Login----" << std::endl;
        std::cout << "Username: ";
        std::cin >> username;

        std::cout << "Password: ";
        std::cin >> password;

        std::ifstream file("users.txt");
        std::string line;

        while (std::getline(file, line)) {
            std::string stored_username, stored_password;
            std::istringstream iss(line);
            iss >> stored_username >> stored_password;

            if (stored_username == username && stored_password == password) {
                login_successful = true;
                break;
            }
        }

        file.close();

        if (login_successful) {
            std::cout << "-----------------------------" << std::endl;
            std::cout << "Login Successful!" << std::endl;
            std::cout << "-----------------------------" << std::endl;
            menu_open = true;
            if (menu_open)
            {
                    menu_status = library_menu();
                    if (menu_status == 1){
                        //Add book
                        std::cout << "Add Book" << std::endl;
                        
                    }
                    else if (menu_status == 2){
                        //Display books
                        std::cout << "Display Books" << std::endl;
                        
                    }
                    else if (menu_status == 3){
                        //Check Particular Bookk
                        std::cout << "Check Particular Book" << std::endl;
                        
                    }
                    else if (menu_status == 4){
                        //Update Book
                        std::cout << "Update Book" << std::endl;
                        
                    }
                    else if (menu_status == 5){
                        //Delete Book
                        std::cout << "Delete Book" << std::endl;
                        
                    }
                    else if (menu_status == 6){
                        //Exit
                        std::cout << "Exit Program" << std::endl;
                        
                    }
                    
            }
            

        } else {
            std::cout << "Incorrect username or password!" << std::endl;
        }
    }
};

int main() {
    LibrarySystem system;
    system.run();

    return 0;
}
