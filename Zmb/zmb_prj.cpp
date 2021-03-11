#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;


void edit_categories();
void show_cart();
void  edit_item();
void AddCategory();
void AddCategoriedProduct();
void EditCart();
void Search();
void Login();
void ShowAllCategories();
void home_menu();
void c_menu();
void Cart();
void Checkout();
void Exit();
void EmployeeMenu(); 
void ShowAllProdut();
void ShowAllProdutCustomer();
void DeleteCategories();
void Delete();


bool flag_success = false;
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
  
  home_menu();
}

void home_menu(){
  system ("cls");
  cout << "Home Menu\t\t"<<endl;
  
  cout << "-=-=-=-=-=-=-=-" <<endl;
  cout << " 1.You're a Customer" << endl;
  cout << " 2.You're Staff" << endl;
  cout << " 3.Exit" <<endl;


  char slct;
  slct = getch();
  switch (slct) {
    case '2':
      if (flag_success == false){
    
        Login();
      }
      else {
        EmployeeMenu();
      }
      break;
    case '1':
      c_menu();
      break;
    case '3':
      	
      Exit();
      break;
  }
}

void c_menu(){
  system("cls");
  cout << "The Menu of Customer\t\t";
  cout<<endl;
  cout << "---------------" <<endl;
  cout << " 1.Add Items to Cart" << endl;
  cout << " 2.My Cart" <<endl;
  cout << " 3.Edit my Cart" << endl;
  cout << " 4.Search" << endl;
  cout << " 5.Show all Items" << endl;

  cout << " 6.Checkout" << endl;

  cout << " 9.Exit" <<endl;

  char slct;
  slct = getch();
  switch (slct) {
    case '1':
      Cart();
      return;
    case '2':
      show_cart();
      return;
    case '3':
      EditCart();
      return;
    case '4':
      Search();
      return;
    case '5':
      ShowAllProdutCustomer();
      return;
    case '6':
      Checkout();
      return;
    case '9':
      home_menu();
      return;
  }
}

void Cart(){
	system("cls");	
   
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
  char slct;
  int intchoice;
  slct = getch();
  intchoice = slct - '0';
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
   
  c_menu();
}


void Checkout(){
	system("cls");	
   
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
  c_menu();
}

void Login(){

  EmployeeMenu();
}

void EmployeeMenu(){
	system("cls");	
   
  system ("cls");
  cout << "EmployeeMenu\t\t";
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

  cout << "9.Back to Main Menu" <<endl;

  char slct;
  slct = getch();
  switch (slct) {
    case '1':
      AddCategory();
      break;
    case '2':
      AddCategoriedProduct();
      break;
    case '3':
      edit_categories();
      break;
    case '4':
       edit_item();
      break;
    case '5':
      DeleteCategories();
      break;
    case '6':
      Delete();
      break;
    case '7':
      ShowAllCategories();
      break;
    case '8':
      ShowAllProdut();
      break;
    case '9':
      home_menu();
      break;
  }
}

void AddCategory(){
	system("cls");	
   
  system ("cls");
  cout << "Adding Category" << endl;
  cout << "---------------" <<endl;
  cout << "Please Enter a name for Category:" << endl;
  cin >> category;
  string copyofCategory = category;
  system ("cls");
  char decision;
  cout << "Creating new Category with name of ";

  cout << copyofCategory;

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
     
  }
  else {
    cout << "Creating Category Canceled!\n" <<endl;
     
  }
  EmployeeMenu();
}
void Exit(){
	system("cls");	
   
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
    home_menu();
  }
}
void AddCategoriedProduct(){
	system("cls");	
   
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
  int slct;
  cin >> slct;
  system ("cls");

  cout << "Adding Product to " << category  << endl;
  cout << "---------------" <<endl;

  i=1;
  ifstream iCategory("CategoryList.txt");
  while (iCategory >> category){
    if (slct == i) break;
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
     
  }
  else {
    system ("cls");
    cout << "Adding Product to category Canceled!\n" <<endl;
     
  }
  system ("cls");
  EmployeeMenu();
}

void edit_categories(){
	system("cls");	
   
  system ("cls");
  cout << "Which Category do you wish to Edit ?" << endl;
  ifstream show("CategoryList.txt");
  int i = 1;
  while (!show.eof()){
    while (show >> category) cout << i++ << '.' << category <<endl;
  }
  show.close();
  char slct;
  int intchoice;
  slct = getch();
  intchoice = slct - '0';
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
  EmployeeMenu();
}

void ShowAllProdut(){
	system("cls");	
   
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

      cout << category_copy <<endl;
      cout << endl;

      while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
      }
      openCategory.close();
      cout << "_________________\n" << endl;
    }
    show.close();
  }
  cout << endl;

  cout << "Press any key to back . . ." << endl;

  cin.ignore();
  EmployeeMenu();
}

void Search(){
	system("cls");	
   
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
  char slct;
  int intchoice;
  slct = getch();
  intchoice = slct - '0';
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
  c_menu();
}


void  edit_item(){
	system("cls");	
   
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
  char slct;
  int intchoice;
  slct = getch();
  intchoice = slct - '0';
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
  slct;
  intchoice;
  slct = getch();
  intchoice = slct - '0';
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
    const char * old = category.c_str();
    const char * newcategory = copyofCategory.c_str();
    remove (old);
    rename (newcategory, old);
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
    const char * old = category.c_str();
    const char * newcategory = copyofCategory.c_str();
    remove (old);
    rename (newcategory, old);
  }
  system ("pause");
  EmployeeMenu();
}

void DeleteCategories(){
	system("cls");	
   
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
  char slct;
  int intchoice;
  slct = getch();
  intchoice = slct - '0';
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
  const char * old = copyofCategory.c_str(); 
  remove (old);
  remove ("CategoryList.txt");
  rename ("CategoryList_temp.txt", "CategoryList.txt");

  EmployeeMenu();
}

void Delete(){
	system("cls");	
   
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
  char slct;
  int intchoice;
  slct = getch();
  intchoice = slct - '0';
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
  const char * old = category.c_str();
  const char * newcategory = copyofCategory.c_str();
  remove (old);
  rename (newcategory, old);
  system ("pause");
  EmployeeMenu();
}

void ShowAllCategories(){
	system("cls");	
   
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

  cout << "Press any key to back . . ." << endl;

  cin.ignore();
  EmployeeMenu();
}



void Credits(){
	system("cls");	
   
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
  home_menu();
}

void show_cart(){
	system("cls");	
   
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

  cout << "Press any key to back . . ." << endl;


  char decision;
  decision = getch();
  c_menu();
}

void EditCart(){
	system("cls");	
   
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
  int slct;
  cin >> slct;
  system ("cls");
  if (slct == 1){
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
  if (slct == 2){
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

  cout << "Press any key to back . . ." << endl;

  cin.ignore();
  c_menu();
}

void ShowAllProdutCustomer(){
	system("cls");	
   
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

      cout << category_copy <<endl;
      cout << endl;

      while (openCategory >> myProduct.id >> myProduct.name >> myProduct.amount >> myProduct.price){
        cout << myProduct.id << "." << ' ' << myProduct.name << ' ' << "#" << myProduct.amount << ' ' << myProduct.price << "$" << endl;
      }
      openCategory.close();
      cout << "_________________\n" << endl;
    }
    show.close();
  }
  cout << endl;

  cout << "Press any key to back . . ." << endl;

  cin.ignore();
  c_menu();
}

