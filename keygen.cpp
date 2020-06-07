//Written the key generator using pasted asm code

#include<iostream>
#include<istream>
#define _CRT_SECURE_NO_WARNINGS

char name[1024], key[1024];
int razmer = 0;
void keygenerator();

int main()
{
	std::cout << "Enter your name: ";
	std::cin >> name;
	razmer = strlen(name);
	keygenerator();
	std::cout << "\nKey is " << key << "\n";
	system("pause");
	return 0;
}

void keygenerator()
{
	__asm
	{
		pushad
		xor eax, eax 
		xor edx,edx
		xor ecx,ecx
		xor ebx,ebx
		lea edx, name
		mov ecx, 0xFACC0FFF
		check1:
		mov bl, byte ptr [edx+eax]
		xor cl, bl
		rol ecx, 0x8
		inc eax
		cmp eax, razmer
		jne check1
		xor eax, eax
		xor edi, edi
		xor esi,esi
		mov edi, ecx
		check2:
		mov eax, edi
		and eax, 0xF
		shr edi, 0x4
		cmp eax, 0x9
		jbe jump
		mov eax, 0x9
		jump:
		add eax, 0x30
		mov byte ptr[edx+esi], al
		inc esi
		cmp esi, 0x8
		jne check2
		xor eax,eax
		mov eax, dword ptr [edx]
		mov dword ptr [key], eax
		mov eax, dword ptr[edx+4]
		mov dword ptr[key+4], eax
		popad
	}
}