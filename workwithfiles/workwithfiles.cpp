#include <fstream>
#include <iostream>
#include <vector>

#pragma pack(push, 1)
struct BFI{
    //Header
    uint16_t Signature;
    uint32_t fs;
    uint32_t Reserved;
    uint32_t DataOffset;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BII{
    //InfoHeader
    uint32_t Size;
    uint32_t Width;
    uint32_t Height;
    uint16_t Planes;
    uint16_t BitCount;
    uint32_t Compression;
    uint32_t ImageSize;
    uint32_t XpixelsPerM;
    uint32_t YpixelsPerm;
    uint32_t ColorsUsed;
    uint32_t ColorsImportant;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BMP{
    BFI bmpfileinfo;
    BII bmpimginfo;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct BMPImage{
    BMP bmp;
    std::vector<uint8_t> dib;
    void read(std::ifstream& file){
        file.read(reinterpret_cast<char*>(&bmp), sizeof(BMP));
        dib.resize(bmp.bmpimginfo.ImageSize);
        file.read(reinterpret_cast<char*>(dib.data()), dib.size());
    }
};
#pragma pack(pop)

int main(){
    std::ifstream f("kkk.bmp",std::ios::binary);
    char c1, c2;
    uint32_t fs;
    f.read(&c1, 1);
    f.read(&c2, 1);
    f.read(reinterpret_cast<char*>(&fs), 4);
   // f.read((char*) &fs, 4);
    
    std::cout  << c1 << " " << c2 << std::endl;
    std::cout << "BMP File Size: " << fs << std::endl;
    std::cout << "Size of structs: " 
    << sizeof(BII) + sizeof(BFI) 
    << std::endl;
    
    BFI bmpinfo;
    BII bmpimginfo;

    BMP bmp;

    f.read(reinterpret_cast<char*>(&bmpinfo), sizeof(BFI));
    f.read(reinterpret_cast<char*>(&bmpimginfo), sizeof(BII));
    f.read(reinterpret_cast<char*>(&bmp), sizeof(BMP));

    std::cout << bmp.bmpimginfo.ImageSize << std::endl;
    return 0;
}