#include <iostream>
#include <windows.h>
#include <iomanip>
#include <time.h>

struct Node{
	std::string Nama;
	int Harga;
	Node* Next; 
    Node* Prev;
};

class LinkedList{
	Node* Head;

public:
	LinkedList() : Head(NULL) {}

	// getter since Head is private
	Node* getHead() {
		return Head;
	}

	void insertAtFirst(std::string nama, int harga) {
		Node* newNode = new Node();

		newNode->Nama = nama;
		newNode->Harga = harga;

        // kalo gada head, tunjuk sendiri
        if(!Head) {
            newNode->Next = newNode;
            newNode->Prev = newNode;
            Head = newNode;
            return;
        }

        // kalo ada head

        // node baru nunjuk head
		newNode->Next = Head;

        Node* temp = Head;
        Node* last = Head->Prev; // ambil node last
        last->Next = newNode; // biar next ke node baru (tail ke head)
        newNode->Prev = last; // biar prev node baru itu last (head ke tail)

        Head->Prev = newNode; // prev head ke node baru, nunjuk belakang

		Head = newNode;
	};

	void insertAtLast(std::string nama, int harga) {
		Node* newNode = new Node();

		newNode->Nama = nama;
		newNode->Harga = harga;

        if(!Head) {
            newNode->Next = newNode;
            newNode->Prev = newNode;
            Head = newNode;
            return;
        }

        Node* last = Head->Prev;

        // new node
        newNode->Next = Head;
        newNode->Prev = last;

        // last
        last->Next = newNode;

        // head
        Head->Prev = newNode;
	}

	void insertAtPosition(int position, std::string nama, int harga) {
		if(!Head) {
			std::cout << "data kosan kosong, silahkan input data terlebih dahulu..." << std::endl;
			return;
		}

		Node* newNode = new Node();
		newNode->Nama = nama;
		newNode->Harga = harga;

		Node* temp = Head;
		for(int i = 1; i < position-1 && temp; i++) {
			temp = temp->Next;
		}

		newNode->Next = temp->Next;
        newNode->Prev = temp;
        temp->Next->Prev = newNode;
		temp->Next = newNode;
	}

    void insertSorted(std::string nama, int harga) {
        Node* newNode = new Node();

        newNode->Nama = nama;
        newNode->Harga = harga;

        // kalo kosong
        if(!Head) {
            Head = newNode;
           newNode->Next = newNode;
           newNode->Prev = newNode;
           return;
        }

        Node* temp = Head;
        do {
            if(newNode->Harga <= temp->Harga) {
                break;
            }

            temp = temp->Next;
        }while(temp != Head);

        newNode->Next = temp;
        newNode->Prev = temp->Prev;
        temp->Prev->Next = newNode;
        temp->Prev = newNode;
    }


	int len() {
		if(!Head){
			return 0;
		}

		Node* temp = Head;

		int len = 0;
		while(temp) {
			len++;
			temp = temp->Next;
		}

		return len;
	}


    void deleteByValue(std::string nama) {
        if (!Head) {
            std::cout << "data kosong, input data terlebih dahulu..." << std::endl;
            return;
        }

        Node* current = Head;
        do {
            if (current->Nama == nama) {
                if (current->Next == current) {
                    delete current;
                    Head = nullptr;
                } else {
                    current->Prev->Next = current->Next;
                    current->Next->Prev = current->Prev;

                    if (current == Head) {
                        Head = current->Next;
                    }

                    delete current;
                }
                std::cout << "kosan berhasil dihapus..." << std::endl;
                return;
            }
            current = current->Next;
        } while (current != Head);

        std::cout << "kosan dengan nama tersebut tidak ditemukan..." << std::endl;
    }

	void print() {
		if(!Head) {
			std::cout << "tidak ada data kosan...";
			return;
		}

		Node* temp = Head;

        do{
			std::cout << "Nama Kosan\t: " << temp->Nama << std::endl;
			std::cout << "Harga / bulan\t: " << temp->Harga << std::endl;
			std::cout << std::endl;
			temp = temp->Next;
        }while(temp != Head);

	}

	void printBackward() {
		if(!Head) {
			std::cout << "tidak ada data kosan...";
			return;
		}

		Node* temp = Head->Prev;;

        do{
			std::cout << "Nama Kosan\t: " << temp->Nama << std::endl;
			std::cout << "Harga / bulan\t: " << temp->Harga << std::endl;
			std::cout << std::endl;
			temp = temp->Prev;
        }while(temp != Head->Prev);

	}

	void infinitePrint() {
		if(!Head) {
			std::cout << "tidak ada data kosan...";
			return;
		}

		Node* temp = Head;
        
        int index = 0;
        do{
            if(index == 100) {
                Sleep(99999);
            }
            std::cout << "Print ke " << index << std::endl;
			std::cout << "Nama Kosan\t: " << temp->Nama << std::endl;
			std::cout << "Harga / bulan\t: " << temp->Harga << std::endl;
			std::cout << std::endl;
			temp = temp->Next;
            index++; 
        }while(temp);
	}


};

void Menu() {
    const int width = 30;
    const char fillChar = '-';
    
    std::cout << std::setfill(fillChar);
    
    std::cout << std::setw(width) << "" << std::endl;
    std::cout << "| MENU" << std::setw(width - 6) << std::setfill(' ') << "|" << std::endl;
    std::cout << std::setfill(fillChar) << std::setw(width) << "" << std::endl;
    
    std::cout << "|" << std::setw(3) << std::setfill(' ') << "1." 
              << std::setw(25) << std::left << " Input" << "|" << std::endl;
    
    std::cout << "|" << std::setw(3) << std::setfill(' ') << "2." 
              << std::setw(25) << std::left << " Lihat" << "|" << std::endl;

    std::cout << "|" << std::setw(3) << std::setfill(' ') << "3." 
              << std::setw(25) << std::left << " Lihat Mundur" << "|" << std::endl;
    
    std::cout << "|" << std::setw(3) << std::setfill(' ') << "4." 
              << std::setw(25) << std::left << " Hapus" << "|" << std::endl;
    
    std::cout << "|" << std::setw(3) << std::setfill(' ') << "5." 
              << std::setw(25) << std::left << " Exit" << "|" << std::endl;
    
    std::cout << std::setfill(fillChar) << std::setw(width) << "" << std::endl;
}

void MenuInput() {
	std::cout << "1. Sisip depan" << std::endl;
	std::cout << "2. Sisip tengah" << std::endl;
	std::cout << "3. Sisip belakang" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

void Lihat(LinkedList* l) {
	std::cout << "data kosan" << std::endl;
	l->print();
}

void LihatMundur(LinkedList* l) {
	std::cout << "data kosan" << std::endl;
	l->printBackward();
}

void Hapus(LinkedList* l) {
	std::string nama;
	std::system("cls");
	std::cout << "Nama kosan yang ingin dihapus : ";
	std::cin.ignore();

	getline(std::cin, nama);
	l->deleteByValue(nama);
}


void Balik() {
}

int PilihMenu;
int PilihMenuInput;
char balik;
std::string namaKosan;
int hargaKosan;
int posisi;

/*
int main() {
    LinkedList l;
    l.insertAtFirst("ronaldo", 7);
    l.insertAtFirst("messi", 10);
    l.insertAtFirst("anto", 99);

    l.infinitePrint();

    return 0;
}
*/


/*
int main() {
	LinkedList l;	
	do{
		std::system("cls");
		std::cout << "PROGRAM KELOLA DATA KOSAN" << std::endl;
		Menu();

		std::cout << "Pilih : ";
		std::cin >> PilihMenu;
		switch(PilihMenu) {
			case 1:
				std::system("cls");
				std::cout << "Data yang ingin disisipkan" << std::endl;

				std::cout << "Nama kosan\t: ";
				std::cin.ignore();
				getline(std::cin, namaKosan);

				std::cout << "Harga kosan\t: ";
				std::cin >> hargaKosan;
                
                std::cout << std::endl;

				std::cout << "Menu sisip" << std::endl;

				MenuInput();
				std::cout << std::endl << "Pilih : ";
				std::cin >> PilihMenuInput;
				switch(PilihMenuInput){
					case 1:
						l.insertAtFirst(namaKosan, hargaKosan);
						break;
					case 2:
						std::cout << "Posisi yang ingin di sisip : ";
						std::cin >> posisi;

						l.insertAtPosition(posisi, namaKosan, hargaKosan);

						break;
					case 3:
						l.insertAtLast(namaKosan, hargaKosan);
						break;
					case 4:
						std::system("cls");
						std::cout << "mengembalikan ke menu utama...";
						Sleep(500);
						break;
					default:
						std::cout << "input tidak valid...";
						return 0;
				}

                std::system("cls");
				std::cout << "berhasil melakukan input data kosan, mengembalikan ke menu utama..." << std::endl;
                Sleep(500);
					
				break;
			case 2:
				Lihat(&l);
				std::cout << "kembali ke menu utama? (y/n) ";
				std::cin >> balik;
				switch(balik) {
					case 'y':
					case 'Y':
						std::system("cls");
						std::cout << "mengembalikan ke menu utama..." << std::endl;
						Sleep(500);
						std::system("cls");
						break;	
					case 'n':
					case 'N':
						std::system("cls");
						std::cout << "mengeliminasi program..." << std::endl;
						Sleep(500);
						return 0;
					default:
						std::cout << "input tidak valid..." << std::endl;
						return 0;
				}
				break;
            case 3:
				LihatMundur(&l);
				std::cout << "kembali ke menu utama? (y/n) ";
				std::cin >> balik;
				switch(balik) {
					case 'y':
					case 'Y':
						std::system("cls");
						std::cout << "mengembalikan ke menu utama..." << std::endl;
						Sleep(500);
						std::system("cls");
						break;	
					case 'n':
					case 'N':
						std::system("cls");
						std::cout << "mengeliminasi program..." << std::endl;
						Sleep(500);
						return 0;
					default:
						std::cout << "input tidak valid..." << std::endl;
						return 0;
				}
				break;
			case 4:
				Hapus(&l);
				std::cout << "kembali ke menu utama? (y/n) ";
				std::cin >> balik;
				switch(balik) {
					case 'y':
					case 'Y':
						std::system("cls");
						std::cout << "mengembalikan ke menu utama..." << std::endl;
						Sleep(500);
						std::system("cls");
						break;	
					case 'n':
					case 'N':
						std::system("cls");
						std::cout << "mengeliminasi program..." << std::endl;
						Sleep(500);
						return 0;
					default:
						std::cout << "input tidak valid..." << std::endl;
						return 0;
				}
				break;
			case 5:
                std::cout << "mengeliminasi program...";
                return 0;
			default: 
				std::cout << "input tidak valid...";
				return 0;
		}
	}while(true);

	return 0;
}
*/

int main () {
    LinkedList l;
    l.insertSorted("martinez", 23);
    l.insertSorted("phil folden", 47);
    l.insertSorted("nkunku", 15);
    l.insertSorted("coutinho", 23);
    l.insertSorted("garnacho", 13);

    l.print();

    return 0;
}

