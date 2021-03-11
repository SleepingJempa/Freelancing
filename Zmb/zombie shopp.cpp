#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <ctime>
using namespace std;

void EditCategories();
void ShowCart();
void Loading();
void Redirecting();

void EditProduct();
void MainMenu();
void CustomerMenu();
void Cart();
void Exit();
void ShopkeeperMenu(); 
void AddCategory();
void AddCategoriedProduct();
void EditCart();
void Checkout();
void SearchProduct();
void Login();
void ShowAllCategories();
void ShowAllProdut();
void ShowAllProdutCustomer();
void DeleteCategories();
void DeleteProduct();


#define RedColor SetConsoleTextAttribute(h, 0xfc)
#define PurpleColor SetConsoleTextAttribute(h, 0xfd)
#define BlackColor SetConsoleTextAttribute(h, 0xf0)

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); 

bool Successfull = false;
string category;
string product;
int HowMany;
struct Product{
  int id;
  string name;
  float amount;
  float price;
};

int main(){
  Loading();
  system ("color f0");
  MainMenu();
}

void Loading(){
  
}

void Redirecting(){
  string text = "Redirecting...";
  int countingletter = 0;
  while (text[countingletter] != 0)
  {
    RedColor;
    cout << text[countingletter];
    BlackColor;
    Sleep(75);
    countingletter++;
  }
  Sleep(1000);
}

void MainMenu(){
  system ("cls");
  cout << " Main Menu\t\t";
  cout << "Date: ";
      time_t t = time(0);   
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
  cout << "---------------" <<endl;
  cout << " 1.Sign in as Customer" << endl;
  cout << " 2.Sign in as Employee" << endl;
  cout << " 3.Credit" << endl;
  RedColor;
  cout << " 4.Exit" <<endl;
  BlackColor;
  char choice;
  choice = getch();
  switch (choice) {
    case '1':
      CustomerMenu();
      break;
    case '2':
      if (Successfull == false){
        Login();
      }
      else {
        ShopkeeperMenu();
      }
      break;
    case '4':
      Exit();
      break;
  }
}

void CustomerMenu(){
  system ("cls");
  cout << "Customer Menu\t\t";
  cout << "Date: ";
      time_t t = time(0);   
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
  cout << "---------------" <<endl;
  cout << " 1.Add Product to Cart" << endl;
  cout << " 2.View Cart" <<endl;
  cout << " 3.Edit Cart" << endl;
  cout << " 4.Search for Products" << endl;
  cout << " 5.Show all Products" << endl;
  PurpleColor;
  cout << " 6.Checkout" << endl;
  RedColor;
  cout << " 9.Return to Main Menu" <<endl;
  BlackColor;
  char choice;
  choice = getch();
  switch (choice) {
    case '1':
      Cart();
      break;
    case '2':
      ShowCart();
      break;
    case '3':
      EditCart();
      break;
    case '4':
      SearchProduct();
      break;
    case '5':
      ShowAllProdutCustomer();
      break;
    case '6':
      Checkout();
      break;
    case '9':
      MainMenu();
      break;
  }
}

void Cart(){
  system ("cls");
  cout << " Add Product to Cart" << endl;
  cout << "---------------" <<endl;
  Product myProduct;
  cout << " from Which Category do you wish to Edit Product ?" << endl;
  ifstream ShowAllCategories("CategoryList.txt");
  int i = 1;
  while (!ShowAllCategories.eof()){
    while (ShowAllCategories >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  ShowAllCategories.close();
  char choice;
  int intchoice;
  choice = getch();
  intchoice = choice - '0';
  system ("cls");
  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (intchoice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  string copyofCategory = category;
  category += ".txt";
  ifstream openCategory(category.c_str());
  while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
    cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
  }
  openCategory.close();
  int decision;
  ofstream cart("Cart.txt", ios::app);
  cout << "\n\nPlease Enter the ID : " << endl;
  cin >> decision;
  cout << "Please Enter the quantity : " <<endl;
  cin >> HowMany;
  system ("cls");
  ifstream openCategoryAgain(category.c_str());
  while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
    if (decision == myProduct.id){
      cart << myProduct.id << ' ' << myProduct.name << ' ' << HowMany << ' ' << myProduct.price * HowMany << ' ' << copyofCategory << endl;
    }
  }
  openCategoryAgain.close();
  cart.close();
  system ("cls");
  cout << "Product Added to your Cart\n" << endl;
  Redirecting();
  CustomerMenu();
}


void Checkout(){
  system ("cls");
  string name, dummy;
  Product myProduct;
  int id; double amount, price;
  ifstream checkout("Cart.txt");
  while (checkout >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price >> dummy) {
      dummy += ".txt";
      ifstream openACategory(dummy.c_str());
      ofstream resultAfterChanging("temp.txt", ios::app);
      while (openACategory >> id >> name >> amount >> price) {
        if (id == myProduct.id && name == myProduct.name) {
          resultAfterChanging << id << ' ' << name << ' ' << amount-myProduct.amount << ' ' << myProduct.price << endl;
          continue;
        }
        resultAfterChanging << id << ' ' << name << ' ' << amount << ' ' << price << endl;
      }
      openACategory.close();
      resultAfterChanging.close();
      const char * oldName = dummy.c_str();
      remove(oldName);
      rename("temp.txt", oldName);
  }
  checkout.close();
  remove("Cart.txt");

  system ("pause");
  CustomerMenu();
}

void Login(){

  ShopkeeperMenu();
}

void ShopkeeperMenu(){
  system ("cls");
  cout << "ShopkeeperMenu\t\t";
  cout << "Date: ";
      time_t t = time(0);   
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
  cout << "---------------" <<endl;
  cout << "1.Add Category" << endl;
  cout << "2.Adding Products to Categories" << endl;
  cout << "3.Edit Categories" << endl;
  cout << "4.Edit Products" << endl;
  cout << "5.Delete Categories" << endl;
  cout << "6.Delete Product" << endl;
  cout << "7.Show all Categories" << endl;
  cout << "8.Show all Products" <<endl;
  RedColor;
  cout << "9.Back to Main Menu" <<endl;
  BlackColor;
  char choice;
  choice = getch();
  switch (choice) {
    case '1':
      AddCategory();
      break;
    case '2':
      AddCategoriedProduct();
      break;
    case '3':
      EditCategories();
      break;
    case '4':
      EditProduct();
      break;
    case '5':
      DeleteCategories();
      break;
    case '6':
      DeleteProduct();
      break;
    case '7':
      ShowAllCategories();
      break;
    case '8':
      ShowAllProdut();
      break;
    case '9':
      MainMenu();
      break;
  }
}

void AddCategory(){
  system ("cls");
  cout << "Adding Category" << endl;
  cout << "---------------" <<endl;
  cout << "Please Enter a name for Category:" << endl;
  cin >> category;
  string copyofCategory = category;
  system ("cls");
  char decision;
  cout << "Creating new Category with name of ";
  RedColor;
  cout << copyofCategory;
  BlackColor;
  cout << " ? [y][n]" << endl;
  decision = getch();
  if (decision == 'y'){
    system ("cls");
    ofstream CategoryList("CategoryList.txt", ios::app);

    CategoryList << category << endl;
    CategoryList.close();
    category += ".txt";
    ofstream NewCategory(category.c_str());
    NewCategory.close();
    cout << "Category successfully created!\n" <<endl;
    Redirecting();
  }
  else {
    cout << "Creating Category Canceled!\n" <<endl;
    Redirecting();
  }
  ShopkeeperMenu();
}
void Exit(){
  system ("cls");
  char decision;
  cout << "Are you sure you want to exit ? [y][n]";
  decision = getch();
  if (decision == 'y'){
    system ("cls");
    cout << "Farewell. Hope you have a good time <3";
    exit (1);
  }
  else {
    MainMenu();
  }
}
void AddCategoriedProduct(){
  system ("cls");
  cout << "Adding Categoried Product" << endl;
  cout << "---------------" <<endl;
  cout << "Which Category do you wish to add a Product to ?" << endl;
  ifstream ShowAllCategories("CategoryList.txt");
  int i = 1;
  while (!ShowAllCategories.eof()){
    while (ShowAllCategories >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  ShowAllCategories.close();
  int choice;
  cin >> choice;
  system ("cls");

  cout << "Adding Product to " << category  << endl;
  cout << "---------------" <<endl;

  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (choice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  Product myProduct;
  cout << "Id: ";
  cin >> myProduct.id;
  cin.ignore();
  cout << "Name: ";
  getline(cin, myProduct.name);
  cout << "Amount or Number: ";
  cin >> myProduct.amount;
  cout << "Price: ";
  cin >> myProduct.price;
  system ("cls");
  cout << "is this correct? [y][n]" << endl;
  cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$";
  char decision;
  decision = getch();
  if (decision == 'y'){
    system ("cls");
    category += ".txt";
    ofstream CategoriedProduct(category.c_str(), ios::app | ios::out);
    CategoriedProduct << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
    CategoriedProduct.close();
    cout << "Product successfully added!\n" <<endl;
    Redirecting();
  }
  else {
    system ("cls");
    cout << "Adding Product to category Canceled!\n" <<endl;
    Redirecting();
  }
  system ("cls");
  ShopkeeperMenu();
}

void EditCategories(){
  system ("cls");
  cout << "Which Category do you wish to Edit ?" << endl;
  ifstream show("CategoryList.txt");
  int i = 1;
  while (!show.eof()){
    while (show >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  show.close();
  char choice;
  int intchoice;
  choice = getch();
  intchoice = choice - '0';
  system ("cls");
  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (intchoice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  string copyofCategory = category;
  string NewCategoryName;
  cout << "Please select a new name." << endl;
  cin >> NewCategoryName;
  ifstream editFile("CategoryList.txt");
  ofstream tempCategorylist("CategoryList_temp.txt");
  while (!editFile.eof()){
    while (editFile >> category){
      if (category == copyofCategory){
        tempCategorylist << NewCategoryName << endl;
      }
      else {
        tempCategorylist << category << endl;
      }
    }
  }
  editFile.close();
  tempCategorylist.close();
  remove ("CategoryList.txt");
  rename ("CategoryList_temp.txt", "CategoryList.txt");
  copyofCategory += ".txt";
  NewCategoryName += ".txt";
  const char * oldcategory = copyofCategory.c_str();
  const char * newcategory = NewCategoryName.c_str(); 
  rename (oldcategory, newcategory);
  ShopkeeperMenu();
}

void ShowAllProdut(){
  system ("cls");
  cout << "All Products" << endl;
  cout << "---------------" <<endl;
  Product myProduct;
  ifstream show("CategoryList.txt");
  while (!show.eof()){
    while (show >> category){
      string category_copy = category;
      category += ".txt";
      ifstream openCategory(category.c_str());
      RedColor;
      cout << category_copy <<endl;
      cout << endl;
      BlackColor;
      while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
      }
      openCategory.close();
      cout << "_________________\n" << endl;
    }
    show.close();
  }
  cout << endl;
  PurpleColor;
  cout << "Press any key to back . . ." << endl;
  BlackColor;
  cin.ignore();
  ShopkeeperMenu();
}

void SearchProduct(){
  system ("cls");
  cout << "Search Product" << endl;
  cout << "---------------" <<endl;
  Product myProduct;
  cout << "from Which Category do you wish to Edit Product ?" << endl;
  ifstream ShowAllCategories("CategoryList.txt");
  int i = 1;
  while (!ShowAllCategories.eof()){
    while (ShowAllCategories >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  ShowAllCategories.close();
  char choice;
  int intchoice;
  choice = getch();
  intchoice = choice - '0';
  system ("cls");
  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (intchoice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  string copyofCategory = category;
  category += ".txt";
  ifstream openCategory(category.c_str());
  while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
    cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
  }
  openCategory.close();
  system ("cls");
  bool isFound = false;
  string Search;
  cout << "Please enter word to search: ";
  cin >> Search;
  system ("cls");
  ifstream openCategoryAgain(category.c_str());
  while (!openCategoryAgain.eof()){
    cout << "Products founded :" << endl;
    while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
      if (myProduct.name.find(Search) != string::npos){
        isFound = true;
        cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
      }
    }
    if (isFound != true) {
      system ("cls");
      cout << "N0thing founded !" << endl;
      break;
    }
  }
  openCategoryAgain.close();
  system ("pause");
  CustomerMenu();
}


void EditProduct(){
  system ("cls");
  Product myProduct;
  cout << "from Which Category do you wish to Edit Product ?" << endl;
  ifstream ShowAllCategories("CategoryList.txt");
  int i = 1;
  while (!ShowAllCategories.eof()){
    while (ShowAllCategories >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  ShowAllCategories.close();
  char choice;
  int intchoice;
  choice = getch();
  intchoice = choice - '0';
  system ("cls");
  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (intchoice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  string copyofCategory = category;
  category += ".txt";
  ifstream openCategory(category.c_str());
  while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
    cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
  }
  openCategory.close();
  int decision;
  cin >> decision;
  system ("cls");
  cout << "Which part you wish to edit ?" << endl;
  cout << "1.ID" << endl << "2.Name" << endl << "3.amount" << endl << "4.price" <<endl;
  choice;
  intchoice;
  choice = getch();
  intchoice = choice - '0';
  if (intchoice == 1){
    system ("cls");
    int NewID;
    cout << "Please enter new ID: ";
    cin >> NewID;
    ifstream openCategoryAgain(category.c_str());
    copyofCategory += "_temp.txt";
    ofstream tempCategory(copyofCategory.c_str());
    while (!openCategoryAgain.eof()){
      while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        if (decision == myProduct.id){
          tempCategory << NewID << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
        }
        else {
          tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
        }
      }
    }
    openCategoryAgain.close();
    tempCategory.close();
    const char * oldcategory = category.c_str();
    const char * newcategory = copyofCategory.c_str();
    remove (oldcategory);
    rename (newcategory, oldcategory);
  }
    if (intchoice == 2){
    system ("cls");
    string NewName;
    cout << "Please enter new Name: ";
    cin >> NewName;
    ifstream openCategoryAgain(category.c_str());
    copyofCategory += "_temp.txt";
    ofstream tempCategory(copyofCategory.c_str());
    while (!openCategoryAgain.eof()){
      while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        if (decision == myProduct.id){
          tempCategory << myProduct.id << ' ' << NewName << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
        }
        else {
          tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
        }
      }
    }
    openCategoryAgain.close();
    tempCategory.close();
    const char * oldcategory = category.c_str();
    const char * newcategory = copyofCategory.c_str();
    remove (oldcategory);
    rename (newcategory, oldcategory);
  }
  if (intchoice == 3){
    system ("cls");
    int NewAmount;
    cout << "Please enter new Amount: ";
    cin >> NewAmount;
    ifstream openCategoryAgain(category.c_str());
    copyofCategory += "_temp.txt";
    ofstream tempCategory(copyofCategory.c_str());
    while (!openCategoryAgain.eof()){
      while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        if (decision == myProduct.id){
          tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << NewAmount << ' ' << myProduct.price << endl;
        }
        else {
          tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
        }
      }
    }
    openCategoryAgain.close();
    tempCategory.close();
    const char * oldcategory = category.c_str();
    const char * newcategory = copyofCategory.c_str();
    remove (oldcategory);
    rename (newcategory, oldcategory);
  }
  if (intchoice == 4){
    system ("cls");
    int NewPrice;
    cout << "Please enter new Price: ";
    cin >> NewPrice;
    ifstream openCategoryAgain(category.c_str());
    copyofCategory += "_temp.txt";
    ofstream tempCategory(copyofCategory.c_str());
    while (!openCategoryAgain.eof()){
      while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        if (decision == myProduct.id){
          tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << NewPrice << endl;
        }
        else {
          tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
        }
      }
    }
    openCategoryAgain.close();
    tempCategory.close();
    const char * oldcategory = category.c_str();
    const char * newcategory = copyofCategory.c_str();
    remove (oldcategory);
    rename (newcategory, oldcategory);
  }
  system ("pause");
  ShopkeeperMenu();
}

void DeleteCategories(){
  system ("cls");
  cout << "Which Category do you wish to Delete ?" << endl;
  ifstream ShowAllCategories("CategoryList.txt");
  int i = 1;
  while (!ShowAllCategories.eof()){
    while (ShowAllCategories >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  ShowAllCategories.close();
  char choice;
  int intchoice;
  choice = getch();
  intchoice = choice - '0';
  system ("cls");
  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (intchoice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  string copyofCategory2 = category;
  string copyofCategory = category;

  ifstream editFile("CategoryList.txt");
  ofstream tempCategorylist("CategoryList_temp.txt");
  while (!editFile.eof()){
    while (editFile >> category){
      if (category == copyofCategory2){

      }
      else {
        tempCategorylist << category << endl;
      }
    }
  }
  tempCategorylist.close();
  editFile.close();
  copyofCategory += ".txt";
  const char * oldcategory = copyofCategory.c_str(); 
  remove (oldcategory);
  remove ("CategoryList.txt");
  rename ("CategoryList_temp.txt", "CategoryList.txt");

  ShopkeeperMenu();
}

void DeleteProduct(){
  system ("cls");
  Product myProduct;
  cout << "Which Category do you wish to Delete ?" << endl;
  ifstream ShowAllCategories("CategoryList.txt");
  int i = 1;
  while (!ShowAllCategories.eof()){
    while (ShowAllCategories >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  ShowAllCategories.close();
  char choice;
  int intchoice;
  choice = getch();
  intchoice = choice - '0';
  system ("cls");
  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (intchoice == i) {
      break;
    }
    i++;
  }
  iCategory.close();
  string copyofCategory = category;
  category += ".txt";
  ifstream openCategory(category.c_str());
  while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
    cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
  }
  openCategory.close();
  int decision;
  cin >> decision;
  system ("cls");
  ifstream openCategoryAgain(category.c_str());
  copyofCategory += "_temp.txt";
  ofstream tempCategory(copyofCategory.c_str());
  while (!openCategoryAgain.eof()){
    while (openCategoryAgain >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
      if (decision == myProduct.id){

      }
      else {
        tempCategory << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price << endl;
      }
    }
  }
  openCategoryAgain.close();
  tempCategory.close();
  const char * oldcategory = category.c_str();
  const char * newcategory = copyofCategory.c_str();
  remove (oldcategory);
  rename (newcategory, oldcategory);
  system ("pause");
  ShopkeeperMenu();
}

void ShowAllCategories(){
  system ("cls");
  cout << "All Categories" << endl;
  cout << "---------------\n" <<endl;
  ifstream show("CategoryList.txt");
  int i = 1;
  while (!show.eof()){
    while (show >> category){
      cout << i << '.' << category <<endl;
      i++;
    }
  }
  show.close();
  PurpleColor;
  cout << "Press any key to back . . ." << endl;
  BlackColor;
  cin.ignore();
  ShopkeeperMenu();
}



void Credits(){
  system ("cls");
  string credit = "Supervisor : \nDr.x\n\nThis program brought you by :\nAlireza\n\nSpecial thanks to\nA\nB\n";
  int countingletter = 0;
  while (credit[countingletter] != 0)
  {
    cout << credit[countingletter];
    Sleep(75);
    countingletter++;
  }
  Sleep(2000);
  MainMenu();
}

void ShowCart(){
  system ("cls");
  cout << "Your Cart" << endl;
  cout << "---------------" <<endl;
  Product myProduct;
  string dummy;
  ifstream cart("Cart.txt");
  while (cart >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price >> dummy){
    cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
  }
  cart.close();
  PurpleColor;
  cout << "Press any key to back . . ." << endl;
  BlackColor;

  char decision;
  decision = getch();
  CustomerMenu();
}

void EditCart(){
  system ("cls");
  Product myProduct;
  string dummy;
  cout << "Edit Cart" << endl;
  cout << "---------------" <<endl;
  ifstream cart("Cart.txt");
  while (cart >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price >> dummy){
    cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
  }
  cart.close();
  int decition;
  cout << "Please Enter ID to edit Cart :";
  cin >> decition;
  system ("cls");
  cout << "Select an operation :" << endl;
  cout << "1.Edit the quantity" << endl;
  cout << "2.Delete Product from Cart" << endl;
  int choice;
  cin >> choice;
  system ("cls");
  if (choice == 1){
    ofstream cart_temp("Cart_temp.txt");
    cout << "Enter New quantity :" << endl;
    int NewHowMany;
    cin >> NewHowMany;
    ifstream openCart("Cart.txt");
    while (openCart >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price >> dummy){
      if (decition == myProduct.id){
        cart_temp << myProduct.id << ' ' << myProduct.name << ' ' << NewHowMany << ' ' << myProduct.price * NewHowMany << ' ' << dummy << endl;
      }
      else{
        cart_temp << myProduct.id << ' ' << myProduct.name << ' ' << HowMany << ' ' << myProduct.price * HowMany << ' ' << dummy << endl;
      }
    }
    openCart.close();
    cart_temp.close();
    remove ("Cart.txt");
    rename ("Cart_temp.txt" , "Cart.txt");
  }
  if (choice == 2){
    ofstream cart_tempAgian("Cart_temp.txt");
    ifstream openCartAgian("Cart.txt");
    while (openCartAgian >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price >> dummy){
      if (decition == myProduct.id){

      }
      else{
        cart_tempAgian << myProduct.id << ' ' << myProduct.name << ' ' << myProduct.amount << ' ' << myProduct.price * HowMany << ' ' << dummy << endl;
      }
    }
    openCartAgian.close();
    cart_tempAgian.close();
    remove ("Cart.txt");
    rename ("Cart_temp.txt" , "Cart.txt");
  }
  PurpleColor;
  cout << "Press any key to back . . ." << endl;
  BlackColor;
  cin.ignore();
  CustomerMenu();
}

void ShowAllProdutCustomer(){
  system ("cls");
  cout << "All Products" << endl;
  cout << "---------------" <<endl;
  Product myProduct;
  ifstream show("CategoryList.txt");
  while (!show.eof()){
    while (show >> category){
      string category_copy = category;
      category += ".txt";
      ifstream openCategory(category.c_str());
      RedColor;
      cout << category_copy <<endl;
      cout << endl;
      BlackColor;
      while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
      }
      openCategory.close();
      cout << "_________________\n" << endl;
    }
    show.close();
  }
  cout << endl;
  PurpleColor;
  cout << "Press any key to back . . ." << endl;
  BlackColor;
  cin.ignore();
  CustomerMenu();
}

