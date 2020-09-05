#include<iostream>
#include<string> 
#include<algorithm>
#include<fstream>


int hash;
void FNV(int i, std::string z);

int main()
{
	std::string extension;
	int size;
	std::ifstream in("input.txt");
	std::ofstream out("hashes.txt");
	while (std::getline(in, extension))
	{
		reverse(begin(extension), end(extension));
		size = extension.length();
		FNV(size, extension);
		out << std::hex << std::uppercase << hash << "\n";
	}
	in.close();
	out.close();
	system("pause");
	return 0;
}


void FNV(int i, std::string extension) {

	_asm
	{
		pushad
		lea ecx, extension
		mov edx, 0x811C9DC5
		imul edx, 0x1000193
		xor ebx,ebx
		is_end2 :
			movzx eax, byte ptr ds : [ecx+ebx+4]
			xor eax, edx
			imul edx, eax, 0x1000193
			inc ebx
			cmp ebx, i
		jne is_end2
		mov hash, edx
		popad
	}
}