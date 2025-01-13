#include <iostream>
#include <string>
using namespace std;

class Book{

    string title;
    string author; 
    int publicationYear; 
    int id;

    public:
    Book(string title , string author  ,int publicationYear  ,int id ){

        this-> title = title;
        this-> author = author;
        this-> publicationYear = publicationYear;
        this-> id = id;


    }

    Book(const Book& obj){

        title = obj.title;
        author = obj.author;
        publicationYear = obj.publicationYear;
        id = obj.id;

    }
    void setTitle(string titleName){
        if(titleName != " "){
            title = titleName;
        }else{
            cout<<"Title Not Found"<<endl;
        }

        
    }
    void setAuthor(string AuthorName){
        if(AuthorName !=" "){
             author = AuthorName;
        }else{
            cout<<"Author Not Found"<<endl;
        }
        
       
    }
//function

    void setPublicationYear(int PublicationYearDate ){
        if(PublicationYearDate > 0){
            publicationYear = PublicationYearDate;
        }else{
            cout<<"PublicationYear Not Found"<<endl;

        }
        
    }
    void setId(int idData){
        if(idData>0){
             id = idData;
        }else{
            cout<<"ID Not Found"<<endl;
        }
       
    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    int getPublicationYear(){
        return publicationYear;
    }
    int getID(){
        return id;
    }

    void displayFunction() const {
        cout<<"Title "<<title<<endl;
        cout<<"Author "<<author<<endl;
        cout<<"PublicationYear "<<publicationYear<<endl;
        cout<<"Id "<<id<<endl;

    }





};

class Libarary{

string name;
string location;
Book featuredBook; 

   
public:



    Libarary(string name, string location, Book featuredBook): featuredBook(featuredBook) {

        this-> name =this-> name;
        this-> location = this->location;
        
        
    }

    void setName(string name){
        
            this->name = name;
        

        
    }
    void setLocation(string location){
        
             this->location = location;
       
        
       
    }
    void setFeaturedBook(Book featuredBook ){
        
             this->featuredBook = featuredBook;
       
        
    }

    string getName(){
        return name;
    }
    string getLocation(){
        return location;
    }
    Book getfeaturedBook(){
        return featuredBook;
    }

    void displayLibraryInfo() const {
        cout << "Library Name: " << name << endl;
        cout << "Location: " << location << endl;
        featuredBook.displayFunction();
    }
    
};


class Librarian{

    string name;
	int employeeId;

    public:

    Librarian(string name, int employeeId){

        this-> name = name;
        this-> employeeId = employeeId;
    }

     void setname(string name){
        
             this->name = this->name;
       
        
       
    }
    void setemployeeId(int employeeId ){
        
             this->employeeId = this->employeeId;
       
        
    }

    string getName(){
        return name;
    }
    int getemployeeId(){
        return employeeId;
    }


};



int main(){
    
    Book book1("Harry Potter", "Ali", 1999, 101);

    
    Libarary library("Lahore Library", "MM Alam Road", book1);


    cout << "Library Information: " << endl;
    library.displayLibraryInfo();

    Book book2("Atomic Habbit", " ALi Raza", 1997, 109);
    library.setFeaturedBook(book2);

    
    cout << "Updated Library Information: " << endl;
    library.displayLibraryInfo();

    
    library.setName("");
    if (library.getName() == "") {
        cout << "Invalid Library Name!" << endl;
    }

   
    library.setName("Lahore Library");
    cout << "Final Library Information: " << endl;
    library.displayLibraryInfo();



}
